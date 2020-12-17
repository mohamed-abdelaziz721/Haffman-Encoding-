#include "pgmdisplay.h"
#include "ui_pgmdisplay.h"

pgmdisplay::pgmdisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pgmdisplay)
{
    ui->setupUi(this);
}

pgmdisplay::~pgmdisplay()
{
    delete ui;
}
