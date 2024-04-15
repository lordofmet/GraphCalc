#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MainButtonGraphCalc_clicked()
{
    graphCalc.show();
}



void MainWindow::on_MainButtonOther_clicked()
{
    calc.show();
}

