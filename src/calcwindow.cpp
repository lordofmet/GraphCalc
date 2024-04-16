#include "calcwindow.h"
#include "bigint.h"
#include "ui_calcwindow.h"

#define ld long double

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

ld qStrToLd (QString s)
{
    string str = s.toStdString();
    
    int n = s.size();
    ld x = 0;
    
    for (int i = 0; i < n; i++) {
        ld cur = str[i] - 48;
        if (i > 0 && s[i - 1] == '.') {
            cur /= 10;
            x += cur;
            continue;
        }
        x *= 10;
        x += cur;
    }
    
    return x;
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
    
    //ld text_ld = qStrToLd(text);
    
    return text;
    
}

void CalcWindow::on_sin_clicked()
{
    QString text = ui -> input_str->text();
    text = parseInput(text);
    
    
    
    
}


void CalcWindow::on_cos_clicked()
{
    
}

