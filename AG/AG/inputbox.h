#ifndef INPUTBOX_H
#define INPUTBOX_H

#include <QDialog>

namespace Ui {
class InputBox;
}

class InputBox : public QDialog
{
    Q_OBJECT

public:
    explicit InputBox(QWidget *parent = 0);
    ~InputBox();

private:
    Ui::InputBox *ui;
};

#endif // INPUTBOX_H
