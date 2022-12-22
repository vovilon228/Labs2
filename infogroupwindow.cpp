#include "infogroupwindow.h"
#include "ui_infogroupwindow.h"

infogroupwindow::infogroupwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infogroupwindow)
{
    ui->setupUi(this);
}

infogroupwindow::~infogroupwindow()
{
    delete ui;
}
