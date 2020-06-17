#include "inputbox.h"
#include "ui_inputbox.h"

InputBox::InputBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputBox)
{
    ui->setupUi(this);
}

InputBox::~InputBox()
{
    delete ui;
}


