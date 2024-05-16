#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <string>
#include <QChar>
#include <cmath>
#include <vector>

using namespace std;

namespace Ui {
class CalcWindow;
}

class CalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalcWindow(QWidget *parent = nullptr);
    ~CalcWindow();
    
private slots:
    
    void on_sin_clicked();
    
    void on_cos_clicked();
    
    void on_tg_clicked();
    
    void on_ctg_clicked();
    
    void on_asin_clicked();
    
    void on_acos_clicked();
    
    void on_atg_clicked();
    
    void on_actg_clicked();
    
    pair <long double, QString> get_parsed();
    
    void on_lim_clicked();
    
    void on_exp_clicked();
    
    void on_abs_clicked();
    
    void on_pushButton_clicked();
    
    void on_fact_clicked();
    
private:
    Ui::CalcWindow *ui;
};

#endif // CALCWINDOW_H
