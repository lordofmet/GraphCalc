#ifndef GRAPHCALCWINDOW_H
#define GRAPHCALCWINDOW_H

#include <QMainWindow>

namespace Ui {
class GraphCalcWindow;
}

class GraphCalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphCalcWindow(QWidget *parent = nullptr);
    ~GraphCalcWindow();

private slots:

private:
    Ui::GraphCalcWindow *ui;
};

#endif // GRAPHCALCWINDOW_H
