#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QChar>

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
    
private:
    Ui::CalcWindow *ui;
};

#endif // CALCWINDOW_H
