#include "console_enhance.h"
#include "ui_console_enhance.h"

Console_Enhance::Console_Enhance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Console_Enhance)
{
    ui->setupUi(this);
}

Console_Enhance::~Console_Enhance()
{
    delete ui;
}
