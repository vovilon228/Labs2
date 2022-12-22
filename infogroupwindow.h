#ifndef INFOGROUPWINDOW_H
#define INFOGROUPWINDOW_H

#include <QDialog>

namespace Ui {
class infogroupwindow;
}

class infogroupwindow : public QDialog
{
    Q_OBJECT

public:
    explicit infogroupwindow(QWidget *parent = nullptr);
    ~infogroupwindow();

private:
    Ui::infogroupwindow *ui;
};

#endif // INFOGROUPWINDOW_H
