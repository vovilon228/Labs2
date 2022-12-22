#include "infoclockwindow.h"
#include "ui_infoclockwindow.h"

infoclockwindow::infoclockwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoclockwindow)
{
    ui->setupUi(this);
}

infoclockwindow::~infoclockwindow()
{
    delete ui;
}
