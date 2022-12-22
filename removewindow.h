#ifndef REMOVEWINDOW_H
#define REMOVEWINDOW_H

#include <QDialog>

namespace Ui {
class removewindow;
}

class removewindow : public QDialog
{
    Q_OBJECT

public:
    explicit removewindow(QWidget *parent = nullptr);
    ~removewindow();

private:
    Ui::removewindow *ui;
};

#endif // REMOVEWINDOW_H
