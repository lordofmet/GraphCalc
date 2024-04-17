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
    
    bool neg = false;
    bool flag = false;
    
    int i_start = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 && str[i] == '-') {
            neg = true;
            continue;
        }
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
    
    if (neg)
        x *= -1;
    
    return x;

}

QString ldToQstr (ld x) {
    
    string s = to_string(x);
    
    QString qs = QString::fromStdString(s);
    
    return qs;
    
}

QString parseNumberInput (QString text)
{
    
    bool neg = false;
    int n = text.size();
    QString warn1 = "Enter a valid number", warn2 = "Number is too large";
    
    for (int i = 0; i < n; i++) {
        QChar x = text[i];
        if (i == 0 && x == '-') {
            neg = true;
            continue;
        }
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
    
    QString text1 = "";
    
    int allowed_prec = 12;
    int border = min(allowed_prec, n);
    
    for (int i = 0; i < border; i++) {
        
        text1 += text[i];
        
    }
    
    text = text1;
    
    
    return text;
    
}

pair <long double, QString> CalcWindow::get_parsed() {
    
    QString text = ui -> input_str->text();
    text = parseNumberInput(text);
    QString warn1 = "Enter a valid number", warn2 = "Number is too large";
    
    if (text == warn1) {
        ui ->ans_str->setText(warn1);
    }
    
    if (text == warn2) {
        ui ->ans_str->setText(warn2);
    }
    
    ld text_ld = qStrToLd(text);
    
    pair <long double, QString> p;
    p.first = text_ld;
    p.second = text;
    
    return p;
    
}

void CalcWindow::on_sin_clicked()
{
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    text_ld = sinl(text_ld);
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "sin(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
    
}
    
void CalcWindow::on_cos_clicked()
{
    
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    text_ld = cosl(text_ld);
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "cos(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
    
}


void CalcWindow::on_tg_clicked()
{
    
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    text_ld = tanl(text_ld);
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "tg(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
    
}


void CalcWindow::on_ctg_clicked()
{
    
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    ld sine = sinl(text_ld);
    ld cosine = cosl(text_ld);
    ld cotangent = cosine / sine;
    
    text_ld = cotangent;
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "ctg(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
    
}


void CalcWindow::on_asin_clicked()
{
    
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    text_ld = asinl(text_ld);
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "arcsin(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
    
}


void CalcWindow::on_acos_clicked()
{
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    text_ld = acosl(text_ld);
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "arccos(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
}


void CalcWindow::on_atg_clicked()
{
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    text_ld = atanl(text_ld);
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "arctg(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
}


void CalcWindow::on_actg_clicked()
{
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    text_ld = atanl(text_ld);
    text_ld = M_PI / 2 - text_ld;
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "arcctg(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
}

/*void limParser(QString text) { //x^3 + 3x^5,  x,  5 => lim (x^3 + 3x^5)
                               //                      x->5
    
    
    string s = text.toStdString();
    
    int n = s.size();
    
    vector<double> coef;
    
    for (int i = 0; i < n; i++) {
        
        if (s[i] == ',') {
            break;
        }
        
        if (isdigit(s[i])) {
            
            
            
        }
        
    }
    
}
*/

void CalcWindow::on_lim_clicked()
{
    
    QString text = ui->input_str->text();
    
    //limParser(text);
    
}


void CalcWindow::on_exp_clicked()
{
    
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    text_ld = exp(text_ld);
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "e^(" + text + ") = " + text_qStr;
    
    ui->ans_str->setText(output);
    
}


void CalcWindow::on_abs_clicked()
{
    
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    QString text = p.second;
    
    if (text_ld < 1e-18) {
        text_ld *= -1;
    }
    
    QString text_qStr = ldToQstr(text_ld);
    QString output = "| " + text + " | = " + text_qStr;
    
    ui->ans_str->setText(output);
    
}

