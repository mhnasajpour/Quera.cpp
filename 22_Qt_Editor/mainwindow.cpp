#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dir = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSave_triggered()
{
    if(dir == "")
        dir = QFileDialog::getSaveFileName(this, "Save");
    QFile file(dir);
    file.open(QFile::WriteOnly | QFile::Truncate);
    file.write(ui->textEdit->toPlainText().toUtf8());
    file.close();
}


void MainWindow::on_actionOpen_triggered()
{
    dir = QFileDialog::getOpenFileName(this, "Open");
    QFile file(dir);
    file.open(QFile::ReadOnly);
    ui->textEdit->setText(file.readAll());
    file.close();
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}

