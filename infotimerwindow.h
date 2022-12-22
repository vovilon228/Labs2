#ifndef INFOTIMERWINDOW_H
#define INFOTIMERWINDOW_H

#include <QDialog>

namespace Ui {
class infotimerwindow;
}

class infotimerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit infotimerwindow(QWidget *parent = nullptr);
    ~infotimerwindow();

private:
    Ui::infotimerwindow *ui;
};

#endif // INFOTIMERWINDOW_H
