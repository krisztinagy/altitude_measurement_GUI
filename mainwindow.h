#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "sensordata.h"
//#include <QListWidgetItem>
#include <QString>
#include "qcustomplot.h"
#include <stdio.h>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void actionContact();
    //void actionContent();
    //void actionDocumentation();
    void actionExit();
    void actionImport();
    void actionSave();

    void mouseMove(QMouseEvent * event);

protected:
    QVector<SensorData> sensor_data_vector;


private:
    Ui::MainWindow *ui;
    QCustomPlot* customPlot;
};

#endif // MAINWINDOW_H
