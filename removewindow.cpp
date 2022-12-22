#include "removewindow.h"
#include "ui_removewindow.h"

removewindow::removewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removewindow)
{
    ui->setupUi(this);
}

removewindow::~removewindow()
{
    delete ui;
}
