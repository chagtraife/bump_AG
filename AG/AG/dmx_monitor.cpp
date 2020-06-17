#include "dmx_monitor.h"
#include "ui_dmx_monitor.h"
#include <QStandardItemModel>
#include "qtbaselib.h"
#include "QDebug"
#include <QFile>
#include <QTextStream>

DMX_Monitor::DMX_Monitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMX_Monitor)
{
    model = new QStandardItemModel(0,0,this);
    ui->setupUi(this);
    for(int i = 0; i < 16; i++)
    {
        model->setHorizontalHeaderItem(i, new QStandardItem(QString::number(i+1)));
    }
    ui->tableView_DMXval->setModel(model);
    memset(_DMX_buffer, 0, sizeof(_DMX_buffer));

    _frameCnt = _frameRate = _frameLength = _frameByteCnt = _frameERRcnt = _frameVerifyCnt = 0;
    _frameRateDisp = _frameLengthDisp = _frameERRpercentDisp = 0;
    _error = _lst_error = NO_ERROR;

    this->refreshDMXDisplay();
    TimerTick = new QTimer(this);
    connect(TimerTick, SIGNAL(timeout()), this, SLOT(_1sTick()));
    TimerTick->start(1000);

    RecordTimer = new QElapsedTimer();
    _sampleRate = _samplePeriod = 0;
    _beginChannel = _endChannel = 0;
    _isRecording = false;
    on_txt_SampleRate_textChanged(ui->txt_SampleRate->text());
    on_txt_RecordedChannel_textChanged(ui->txt_RecordedChannel->text());

    outputFile.setFileName(outputFilename);
    outStream.setDevice(&outputFile);
}

DMX_Monitor::~DMX_Monitor()
{
    delete ui;
}

void DMX_Monitor::ShowDMXmonitor(void)
{
    if(!dmxrdm->isAdministratorUser())
    {
        ui->DMX_Recorder->hide();
    }
    else
    {
        ui->DMX_Recorder->show();
    }
    this->show();
}

void DMX_Monitor::SetCell(quint16 x, quint16 y, QString data, uint8_t color)
{
    QColor _color = QColor::fromRgb(color, 0, 0);
    QStandardItem *row = new QStandardItem(data);
    row->setForeground(_color);
    model->setItem(y,x,row);
}

void DMX_Monitor::SetCell(quint16 x, quint16 y, uint32_t data, uint8_t color)
{

}

#define ERROR_UPDATE_INTERVAL 3 //3s
void DMX_Monitor::_1sTick(void)
{
    QString str;
    static QString strERR = "";
    static uint8_t _errDel = 0;
    _frameRateDisp = _frameRate = _frameCnt;
    _frameCnt = 0;
    if(_errDel++ % ERROR_UPDATE_INTERVAL == 0)
    {
        if(_frameVerifyCnt > 0)
        {
            _frameERRpercentDisp = _frameERRcnt*100/_frameVerifyCnt;
            _error = NO_ERROR;
        }
        if(_lst_error!=NO_ERROR)
        {
            strERR = " - " + DMX_ERROR_TYPE_str[_lst_error];
            _lst_error = NO_ERROR;
        }
        else
        {
            strERR = "";
        }
        _frameERRcnt = 0;
        _frameVerifyCnt = 0;
    }

    str = "Error: " + QString::number(_frameERRpercentDisp) + "% " + strERR + "\r\n" +
            "Frame Rate: " + QString::number(_frameRateDisp) + "fps" + "\r\n" +
            "Frame Length: " + QString::number(_frameLengthDisp) + "bytes";

    ui->txt_DMXinfo->setText(str);
}

void DMX_Monitor::ReadBreak()
{
    _frameCnt++;
    if(_frameByteCnt > 1)
    {
        _frameLengthDisp = _frameByteCnt - 1;
    }
    else
    {
        _frameLengthDisp = 0;
    }
    _frameByteCnt = 0;
    if(_error != NO_ERROR)
    {
        _lst_error = _error;
        _frameERRcnt++;
        _error = NO_ERROR;
    }
    else
    {
        if(refreshDMXDisplay_request)
        {
            refreshDMXDisplay();
        }
    }
    _frameVerifyCnt++;
}

void DMX_Monitor::ReadData(QByteArray dat)
{
    for(int i = 0; i < dat.size(); i++)
    {
        if(_frameByteCnt == 0 && i > 0)
        {
            _error = FRAME_LENGTH;
            break;
        }

        if(_frameByteCnt < sizeof(_DMX_buffer))
        {
            if(_frameByteCnt == 0)
            {
                if(dat[i] == 1)
                {
                    _error = FRAME_RDM;
                }
                else if(dat[i] != 0)
                {
                    _error = FRAME_SYNTAX;
                }
            }
            if(_DMX_buffer[_frameByteCnt] != dat[i])
            {
                refreshDMXDisplay_request = true;
            }
            _DMX_buffer[_frameByteCnt] = dat[i];
        }
        else if(_frameByteCnt > sizeof(_DMX_buffer))
        {
            _error = FRAME_LENGTH;
            break;
        }
        _frameByteCnt++;
    }
}

void DMX_Monitor::refreshDMXDisplay(void)
{
    int cellCnt = 1;
    for(int y = 0; y < 32; y++)
    {
        for( int x = 0; x < 16; x++)
        {
            SetCell(x, y, QString::number(_DMX_buffer[cellCnt]), _DMX_buffer[cellCnt]);
            cellCnt++;
            if(cellCnt >= sizeof(_DMX_buffer)) break;
        }
    }
    refreshDMXDisplay_request = false;
}

void DMX_Monitor::on_txt_SampleRate_textChanged(const QString &arg1)
{
    bool ok;
    int num = arg1.toInt(&ok, 10);
    if(num <= 0 || num > 25 || !ok)
    {
        ui->txt_SampleRate->setStyleSheet("color: red;");
        _sampleRate = 0;
        _samplePeriod = 0;
    }
    else
    {
        ui->txt_SampleRate->setStyleSheet("color: black;");
        _sampleRate = num;
        _samplePeriod = 1000/_sampleRate;
    }
}

void DMX_Monitor::on_txt_RecordedChannel_textChanged(const QString &arg1)
{
    //1-12
    QString _strChann = arg1.trimmed();
    QStringList _strChannLst = _strChann.split("-");
    bool ok;
    int _beginChann, _endChann;

    if(_strChannLst.size() != 2)
    {
        ui->txt_RecordedChannel->setStyleSheet("color: red;");
        _beginChannel = 0;
        _endChannel = 0;
        return;
    }

    _beginChann = ((QString)(_strChannLst[0])).toInt(&ok);
    if(_beginChann <= 0 || !ok || _beginChann > 511)
    {
        ui->txt_RecordedChannel->setStyleSheet("color: red;");
        _beginChannel = 0;
        _endChannel = 0;
        return;
    }

    _endChann = ((QString)(_strChannLst[1])).toInt(&ok);
    if(_endChann <= 0 || !ok || _endChann <= _beginChann || _endChann > 512)
    {
        ui->txt_RecordedChannel->setStyleSheet("color: red;");
        _beginChannel = 0;
        _endChannel = 0;
        return;
    }
    _beginChannel = _beginChann;
    _endChannel = _endChann;
    ui->txt_RecordedChannel->setStyleSheet("color: black;");
}

void DMX_Monitor::on_btn_Rec_clicked()
{
    if(!_isRecording)
    {
        if(_sampleRate > 0 &&
                _beginChannel > 0 && _beginChannel < 512 &&
                _endChannel > _beginChannel && _endChannel <= 512)
        {
            qDebug()<<"_sampleRate"<<_sampleRate<<"_samplePeriod"<<_samplePeriod<<"_beginChannel"<<_beginChannel<<"_endChannel"<<_endChannel;

            ui->btn_Rec->setText("Stop");

            outputFile.open(QIODevice::WriteOnly);

            /* Check it opened OK */
            if(!outputFile.isOpen())
            {
                qDebug() << "- Error, unable to open" << outputFilename << "for output";
                return;
            }

            /* Point a QTextStream object at the file */
            outStream << str_Recording_Header;
            _isRecording = true;
            _recordedFileSize = 0;
            RecordTimer->restart();
            while(_isRecording)
            {
                RecordTimer->restart();
                QString _stream = "";
                for(int i = _beginChannel; i <= _endChannel; i++)
                {
                    _stream += "\t" + QString::number(_DMX_buffer[i]) + ",\t";
                    _recordedFileSize++;
                }
                _stream+="\r\n";
                outStream<<_stream;
                qDebug()<<"Recording"<<_stream;
                while(RecordTimer->elapsed() < _samplePeriod)
                {
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                }
            }

        }
    }
    else
    {
        _isRecording = false;
        ui->btn_Rec->setText("Record");
        qDebug()<<"File is opened:"<<outputFile.isOpen();
        if(outputFile.isOpen())
        {
            outStream<<"};\r\n\r\n";

            QString _headerStream = "";
            _headerStream = tr("const PRG_HEADER prg1 __attribute__((at(0x08010000))) =\r\n{\r\n") +
                    tr("\"#001\",\r\n") +
                    tr("0x08010400,\r\n") +
                    tr("0x0") + QString::number(0x08010400+_recordedFileSize-1, 16) + tr(",\r\n") +
                    QString::number(_recordedFileSize) + tr(",\r\n") +
                    QString::number(_sampleRate) + tr(",\r\n") +
                    QString::number(_endChannel - _beginChannel + 1) + tr(",\r\n") +
                    tr("};\r\n");

            outStream<<_headerStream;
            outputFile.close();
            qDebug()<<"recorded file size:"<<_recordedFileSize<<"bytes";
            qDebug()<<"File closed!";
        }
    }
}
