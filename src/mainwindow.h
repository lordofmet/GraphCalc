#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphcalcwindow.h>
#include <calcwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_MainButtonGraphCalc_clicked();
    
    void on_MainButtonOther_clicked();
    
private:
    Ui::MainWindow *ui;
    GraphCalcWindow graphCalc;
    CalcWindow calc;

};
#endif // MAINWINDOW_H
