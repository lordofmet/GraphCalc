#include "calcwindow.h"
#include "ui_calcwindow.h"

CalcWindow::CalcWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalcWindow)
{
    ui->setupUi(this);
}

CalcWindow::~CalcWindow()
{
    delete ui;
}

QString parseInput (QString text)
{
    
    int n = text.size();
    QString warn1 = "Enter a valid number", warn2 = "Number is too large";
    
    for (int i = 0; i < n; i++) {
        QChar x = text[i];
        if (x == '.') {
            if (i != n - 1 && i != 0) {
                continue;
            }
            else
                return warn2;
        }
        if (!x.isDigit()) {
            return warn1;
        }
    }
    
    if (n > 18) {
        return warn2;
    }
    
    return text;
    
}

void CalcWindow::on_sin_clicked()
{
    QString text = ui -> input_str->text();
    text = parseInput(text);
    
    ui -> input_str->setText(text);
    
}


void CalcWindow::on_cos_clicked()
{
    
}

