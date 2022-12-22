#ifndef INFOCLOCKWINDOW_H
#define INFOCLOCKWINDOW_H

#include <QDialog>

namespace Ui {
class infoclockwindow;
}

class infoclockwindow : public QDialog
{
    Q_OBJECT

public:
    explicit infoclockwindow(QWidget *parent = nullptr);
    ~infoclockwindow();

private:
    Ui::infoclockwindow *ui;
};

#endif // INFOCLOCKWINDOW_H
