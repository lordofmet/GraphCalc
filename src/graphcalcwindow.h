#ifndef GRAPHCALCWINDOW_H
#define GRAPHCALCWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QLine>

namespace Ui {
class GraphCalcWindow;
}

class GraphCalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphCalcWindow(QWidget *parent = nullptr);
    ~GraphCalcWindow();

protected:
    void paintEvent(QPaintEvent *);
    
private slots:
    void on_expandWin_clicked();
    
    void on_decraseWin_clicked();
    
private:
    Ui::GraphCalcWindow *ui;
};

#endif // GRAPHCALCWINDOW_H
