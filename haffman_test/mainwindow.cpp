#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QtCore/QCoreApplication>
#include <QtCore>
#include <QDebug>


void write()
{
    QString generatepath("C:/Users/GIGABYTE/Documents/haffman_test/Original file");
    QDir dir1 = QDir::root();
    dir1.mkpath(generatepath);

    QString originalpath("C:/Users/GIGABYTE/Documents/haffman_test/Original file/original.pgm");
    QFile filewrite(originalpath);
    if (filewrite.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&filewrite);
        out << "hello\r\n";
        out << "sad\r\n";
        out << "people\r\n";
        out << "check\r\n";
        out << "if this GUI works\r\n";



        filewrite.flush();
        filewrite.close();

    }

}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QPixmap pix2(":/img/images/MR_Thorax.jpg");
    int w2 = ui->label_4->width();
    int h2 = ui->label_4->height();
    ui->label_4->setPixmap(pix2.scaled(20*w2,10*h2,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(this, "User Manual", "(1)Press compress button to add a pmg photo for compression this will provide a frequency table file(.frq) and encoded file(.huf) in encoded file with overwrite1 \n "
                                                  "(2)Press decompress button to add both frequency table and encoded file to restore the original file this will be in original directory (.pgm)\n (3)All files will be over written when compressed or decompressed to save space on the device  ");
}

void MainWindow::on_pushButton_clicked()
{
    QString filter = "All File (*.*) ;; text file (*.txt) ;; pgm file (*.pgm) ;; frequency file (*.frq) ;; encoded file (*.enc) ;; document (*.docx)";
    QString fileName = QFileDialog::getOpenFileName(this, "choose a pgm file", "C:/Users/GIGABYTE/Documents/haffman_test/images", filter);
    QFile file(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "","You Havn`t Choose Any File please try again or exit");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();

    QDir dir("fileName/encoded file with overwrite1");
     if(dir.exists())
     {
         QMessageBox::information(this, "", "This file already exist");

     }
     else
     {

         QString path("C:/Users/GIGABYTE/Documents/haffman_test/encoded file with overwrite1");
         QDir dir = QDir::root();
         dir.mkpath(path);

         QString frqpath("C:/Users/GIGABYTE/Documents/haffman_test/encoded file with overwrite1/frequency tabel.frq");
         QFile filewrite(frqpath);
         if (!filewrite.open(QFile::WriteOnly | QFile::Text))
         {
         QMessageBox::warning(this, ""," frequency tabel File Not Open please try again or exit");
         }
         QTextStream out(&filewrite);
         QString text2 = ui->plainTextEdit->toPlainText();
         out << text2;
         filewrite.flush();
         filewrite.close();


         QString hufpath("C:/Users/GIGABYTE/Documents/haffman_test/encoded file with overwrite1/encoded file.huf");
         QFile filewrite2(hufpath);
         if (!filewrite2.open(QFile::WriteOnly | QFile::Text))
         {
         QMessageBox::warning(this, ""," huffman File Not Open please try again or exit");
         }
         QTextStream out1(&filewrite2);
         QString text3 = ui->plainTextEdit->toPlainText();
         out1 << text3;
         filewrite2.flush();
         filewrite2.close();
     }
/*
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    QString text = stream.readAll();
    QMessageBox box;
    box.setText(text);
    box.exec();
    file.close();
*/
 // QMessageBox::information(this, "",fileName); // for showing the path
}

void MainWindow::on_pushButton_2_clicked()
{
        QString filter2 = "All File (*.*) ;; text file (*.txt) ;; pgm file (*.pgm) ;; frequency file (*.frq) ;; encoded file (*.enc) ;; document (*.docx)";
        QMessageBox::critical(this, "", "please choose a frequency tabel file");
        QString fileName1 = QFileDialog::getOpenFileName(this, "choose a frequency tabel file", "C:/Users/GIGABYTE/Documents/haffman_test/encoded file with overwrite1", filter2);

        QFile file1(fileName1);
        if (!file1.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "","You Havn`t Choose frequency tabel to decompress");
        }

        QTextStream in1(&file1);
        QString text1 = in1.readAll();
        file1.close();



        QString filter3 = "All File (*.*) ;; text file (*.txt) ;; pgm file (*.pgm) ;; frequency file (*.frq) ;; encoded file (*.enc) ;; document (*.docx)";
        QMessageBox::critical(this, "", "please choose an encoded file");
        QString fileName2 = QFileDialog::getOpenFileName(this, "choose an encoded file", "C:/Users/GIGABYTE/Documents/haffman_test/encoded file with overwrite1", filter3);

        QFile file2(fileName2);

        if (!file2.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "","You Havn`t Choose encoded file to decompress");
        }

        QTextStream in2(&file2);
        QString text2 = in2.readAll();
        file1.close();


        QDir dir1("fileName1/Original file");
         if(dir1.exists())
         {
             QMessageBox::information(this, "", "This file already exist");

         }
         else
         {
             write();
          }


}
