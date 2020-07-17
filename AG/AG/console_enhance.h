#ifndef CONSOLE_ENHANCE_H
#define CONSOLE_ENHANCE_H

#include <QDialog>

namespace Ui {
class Console_Enhance;
}

class Console_Enhance : public QDialog
{
    Q_OBJECT

public:
    explicit Console_Enhance(QWidget *parent = nullptr);
    ~Console_Enhance();

private:
    Ui::Console_Enhance *ui;
};

#endif // CONSOLE_ENHANCE_H
