#include "calcwindow.h"
#include "bigint.h"
#include "math.h"
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
    
    bool flag = false;
    int i_start = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '.') {
            flag = true;
            i_start = i;
            break;
        }
        ld cur = str[i] - 48;
        x *= 10;
        x += cur;
    }
    
    if (flag) {
        
        for (int i = i_start + 1; i < n; i++) {
            ld cur = str[i] - 48;
            cur /= pow(10, i - i_start);
            x += cur;
        }
        
    }
    
    return x;
}

QString ldToQstr (ld x) {
    
    string s = to_string(x);
    
    QString qs = QString::fromStdString(s);
    
    return qs;
    
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
    QString warn1 = "Enter a valid number", warn2 = "Number is too large";
    
    if (text == warn1) {
        ui ->ans_str->setText(warn1);
    }
    
    if (text == warn2) {
        ui ->ans_str->setText(warn2);
    }
    
    ld text_ld = qStrToLd(text);
    
    text_ld = sinl(text_ld);
    
    QString t = ldToQstr(text_ld);
    qDebug() << t << "\n";
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "sin(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
    
}
    
void CalcWindow::on_cos_clicked()
{
    
}

