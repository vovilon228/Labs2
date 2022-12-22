#include "infotimerwindow.h"
#include "ui_infotimerwindow.h"

infotimerwindow::infotimerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infotimerwindow)
{
    ui->setupUi(this);
}

infotimerwindow::~infotimerwindow()
{
    delete ui;
}
