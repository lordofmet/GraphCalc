#include "graphcalcwindow.h"
#include "ui_graphcalcwindow.h"


GraphCalcWindow::GraphCalcWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphCalcWindow)
{
    ui->setupUi(this);

}

GraphCalcWindow::~GraphCalcWindow()
{
    delete ui;
}

