#ifndef CONSOLE_ENHANCE_H
#define CONSOLE_ENHANCE_H

#include <QDialog>
#include "QDebug"
#include "QString"
#include <QCloseEvent>

namespace Ui {
class Console_Enhance;
}

class Console_Enhance : public QDialog
{
    Q_OBJECT

public:
    explicit Console_Enhance(QWidget *parent = nullptr);
    ~Console_Enhance();
    void process_data(void);
signals:
    void get_data(void);
    void turn_off_config_enhance(void);
void into_enhance(void);

private slots:
    void on_btnOk_clicked();

private:
    Ui::Console_Enhance *ui;
public:
    quint8 From, To ,offset;
private slots:
    void closeEvent (QCloseEvent *event);
};

#endif // CONSOLE_ENHANCE_H
