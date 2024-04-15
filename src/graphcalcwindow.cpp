#include "graphcalcwindow.h"
#include "ui_graphcalcwindow.h"
#include <iostream>
#include <QStatusBar>
#include <QApplication>
#include <QScreen>
#include <qDebug>

using namespace std;

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

int global_x = 200, global_y = 150, global_l = 300, global_w = 400;

//переписать на кастом сетку

void GraphCalcWindow::paintEvent(QPaintEvent *)
{
    int length = global_l, width = global_w, start_x = global_x, start_y = global_y;
    
    QPainter painter;

    painter.begin(this);

    QPen pen;

    pen.setColor(Qt::lightGray);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);

    painter.setPen(pen);

    QPolygon pol;
    pol << QPoint(start_x, start_y) << QPoint(start_x, start_y + length) <<
        QPoint(start_x + width, start_y + length) << QPoint(start_x + width, start_y);

    painter.drawPolygon(pol);
    
    int h = 25;
    for (int i = start_x; i <= start_x + width; i += h) {
        
        int j = start_y, j1 = start_y + length;
        
        QPoint p1(i, j);
        QPoint p2(i, j1);
        QLine l(p1, p2);
        
        if (i == start_x + width / 2) {
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawLine(l);
            pen.setColor(Qt::lightGray);
            painter.setPen(pen);
            continue;
        }
        painter.drawLine(l);
        
    }
    
    int h1 = h;
    for (int j = start_y; j <= start_y + length; j += h1) {
        int i = start_x, i1 = start_x + width;
        QPoint p1(i, j), p2(i1, j);
        QLine l(p1, p2);
        if (j == start_y + length / 2) {
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawLine(l);
            pen.setColor(Qt::lightGray);
            painter.setPen(pen);
            continue;
        }
        
        painter.drawLine(l);
    }



    painter.end();
}


void GraphCalcWindow::on_expandWin_clicked()
{
    
    int add_l = 50;
    int add_w = 100;
    int decrease_l = add_l / 2;
    int decrease_w = add_w / 2;
    
    if (global_x - decrease_l < 0 || global_y - decrease_w < 0) {
        statusBar() -> showMessage(tr("Can't expand window"), 2000);
        return;
    }
    
    /*int h = GraphCalcWindow.geometry().height();
    qDebug() << h << ' ';*/
        
    int width = 800;
    int length = 600;
    
    if (global_w + add_w > width - 25 || global_l + add_l > length - 25) {
        statusBar() -> showMessage(tr("Can't expand window"), 2000);
        return;
    }
        
    global_x -= decrease_w;
    global_y -= decrease_l;
    global_l += add_l;
    global_w += add_w;
    
    repaint();
}


void GraphCalcWindow::on_decraseWin_clicked()
{
    int dec_l = 50;
    int dec_w = 100;
    int add_l = dec_l / 2;
    int add_w = dec_w / 2;
    
    int width = 800;
    int length = 600;
    
    if (global_x + add_l > length - 25 || global_y + add_w > width - 25) {
        statusBar() -> showMessage(tr("Can't decrease window"), 2000);
        return;
    }
    
    if (global_w - dec_w < 25 || global_l - dec_l < 25) {
        statusBar() -> showMessage(tr("Can't decrease window"), 2000);
        return;
    }
    
    global_x += add_l * 2;
    global_y += add_w / 2;
    global_l -= dec_l;
    global_w -= dec_w;
    
    repaint();
}

