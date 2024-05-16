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
        
        if (text[i] == ' ')
            continue;
        
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

string format_str (string s) {
    
    int n = s.size();
    
    string s1 = "";
    
    for (int i = 0; i < n; i++) {
        
        if (s[i] == ' ') {
            continue;
        }
        
        if (i + 1 < n) {
            
            if (s[i] == '.' && s[i + 1] == '.') {
                i += 1;
                continue;
            }
            
            if (isalpha(s[i]) && isalpha(s[i + 1])) {
                i += 1;
                continue;
            }
            
        }
        
        /*if (!isdigit(s[i]) && !isalpha(s[i]) && s[i] != '.' && s[i] != ',' &&
            s[i] != '('    && s[i] != ')'    && s[i] != '^' && s[i] != '+')
        {
            continue;
        }*/
        
        s1 += s[i];
        
    }
    
    return s1;
    
}

template <typename T> void print_vec (vector <T> &v) {
    
    int n = v.size();
    
    for (int i = 0; i < n; i++) {
        
        cout << "vec[" << i << "] = " << v[i] << "\n";
        
    }
    
    cout << "\n";
    
}

template <typename T> void print_vec_n (vector <T> &v, int n) {
    
    for (int i = 0; i < n; i++) {
        
        cout << "vec[" << i << "] = " << v[i] << "\n";
        
    }
    
    cout << "\n";
    
}

ld limParser(QString text) { //x^3 + 3x^5,  x,  5 => lim (x^3 + 3x^5)
                                                                       //                      x->5
    
    
    string s = text.toStdString();
    
    s = format_str(s);
    string s0 = s;
    int n = s.size();
    
    string s1 = "";
    
    int z1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ',') {
            z1 = i + 1;
            break;
        }
        s1 += s[i];
    }
    
    string s2 = "";
    int z2 = 0;
    for (int i = z1; i < n; i++) {
        if (s[i] == ',') {
            z2 = i + 1;
            break;
        }
        s2 += s[i];
    }
    
    string s3 = "";
    for (int i = z2; i < n; i++) {
        s3 += s[i];
    }
    
    s = s1;
    n = s.size();
    
    cout << "s1 " << s1 << endl;
    cout << "s " << s << endl;
    cout << "s2 " << s2 << endl;
    cout << "s3 " << s3 << endl;
    
    vector<long double> coef(n, 0); //4 * (var)
    vector<char> params(n, 0); // x, y, ...
    vector<char> opers(n, 0); //+, -
    vector<long double> pows(n, 0); //^5, ...
    
    int cur = 0;
    
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        
        if (s[i] == ',') {
            break;
        }
        
        if (i == 0 && s[i] != '-') {
            opers[cur] = '+';
        }
        
        else if (s[i] == '+') {
            opers[cur] = '+';
            i++;
        }
        
        else if (s[i] == '-') {
            opers[cur] = '-';
            i++;
            //cout << opers[cur] << ' ' << i << "\n";
        }
        
        string cur_num = "";
        
        while ((isdigit(s[i]) || s[i] == '.') && i < n) {
            
            cur_num += s[i];
            i++;
        }
        
        if (cur_num != "") {
            QString t = QString::fromStdString(cur_num);
            ld t1 = qStrToLd(t);
            coef[cur] = t1;
        }
        
        else {
            coef[cur] = 1;
        }
        
        if (i == n) {
            params[cur] = 1;
            pows[cur] = 1;
            break;
        }
        
        while (isalpha(s[i]) && i < n) {
            
            params[cur] = s[i];
            pows[cur] = 1;
            
            //if (i + 3 < n && s[i + 1] == '^' && s[i + 2] == '(') {
            if (s[i + 1] == '^') {
                //i += 3;
                i += 2;
                string cur_pow = "";
                while ((isdigit(s[i]) || s[i] == '.') && i < n) {
                    cur_pow += s[i];
                    if (!isdigit(s[i+1]) && i + 1 < n)
                        break;
                    i++;
                }
                
                if (cur_pow != "") {
                    QString t = QString::fromStdString(cur_pow);
                    ld t1 = qStrToLd(t);
                    pows[cur] = t1;
                }
                
                else{
                    pows[cur] = 1;
                }
                
            }
            
            if (i >= n - 1) {
                flag = true;
                break;
            }
            
            if (!isalpha(s[i+1]) && i + 1 < n){
                break;
            }
            
            i++;
        }
        
        if (flag)
            break;
        
        if (params[cur] == 0) {
            params[cur] = 1;
        }
        
        cur++;   
        
    }
    
    pair < vector<ld>, vector<char> > res;
    
    res.first = coef;
    res.second = params;
    
    pair < vector<ld>, vector<char> > res1;
    
    res1.first = pows;
    res1.second = opers;
    
    vector < pair < vector<ld>, vector<char> > > res_fin;
    
    res_fin.push_back(res);
    res_fin.push_back(res1);
    
    cout << "res\n";
    for (int i = 0; i <= cur; i++) {
        cout << (char)opers[i];
        cout << coef[i];
        cout << (char)params[i];
        cout << "^" << pows[i] << "\n";
    }
    
    char var = s2[0];
    ld var_val = stold(s3);

    ld ans = 0;
    for (int i = 0; i <= cur; i++) {
        if (opers[i] == '+') {
            if (params[i] == var)
                ans += coef[i] * powl(var_val, pows[i]);
            else ans += coef[i];
        }
        else {
            if (params[i] == var)
                ans -= coef[i] * powl(var_val, pows[i]);
            else ans -= coef[i];
        }
    }
    
    
    
    return ans;
}


void CalcWindow::on_lim_clicked()
{
    
    QString text = ui->input_str->text();
    
    ld k = limParser(text);
    QString kstr = ldToQstr(k);
    ui->ans_str->setText(kstr);
    
    
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

void CalcWindow::on_fact_clicked()
{
    
    pair <long double, QString> p = get_parsed();
    ld text_ld = p.first;
    int text_int = (int) text_ld;
    QString text = p.second;
    
    bigint res(1);
    
}

