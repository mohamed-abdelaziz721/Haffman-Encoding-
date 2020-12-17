#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <huffman.hpp>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/bdoaboubkr/Pictures/1.png");
    ui->label_pic->setPixmap(pix.scaled(500,500,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_compress_clicked()
{

}

void MainWindow::on_pushButton_DE_clicked()
{

}

void MainWindow::on_pushButton_close_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                     "My App", "Are You sure you want to exit?",
                            QMessageBox::Yes | QMessageBox::No);
      if(reply == QMessageBox::Yes) {
          QApplication::quit();
      } else {
          qDebug() << "No is clicked";
      }
}
