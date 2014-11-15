#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QToolTip>
#include <QObject>
#include <QEvent>
#include <QtGui>


//Open/save
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVector>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

// global double vector to store GPS data and time
QVector<double> time_GPS_var, time_GPS_CORR_var, time_ALT_var, time_BAR_var;
QVector<double> GPS_var, GPS_CORR_var, ALT_var, BAR_var;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->customPlot->replot();

    //enable tracking of the mouse to request mouse position
    ui->customPlot->setMouseTracking(true);

    //setting up axis types
    ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->customPlot->xAxis->setDateTimeFormat("yyyy.MMM.dd\nhh:mm:ss");

    //setting up axis labels
    ui->customPlot->xAxis->setLabel("time");
    ui->customPlot->yAxis->setLabel("altitude(m)");

    //adding graphs to the plot
    //graph(0) is for marker point
    //graph(1) is for GPS data
    //graph(2) is for Altimeter data
    //graph(3) is for Barometer data
    //graph(4) is for corrected GPS data

    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();



    //connect SIGNALS to SLOTS
    connect(ui->actionContact,
            SIGNAL(triggered()), this, SLOT(actionContact()));
    //connect(ui->actionContent,
    //        SIGNAL(triggered()), this, SLOT(actionContent()));
    //connect(ui->actionDocumentation,
    //        SIGNAL(triggered()), this, SLOT(actionDocumentation()));
    connect(ui->actionExit,
            SIGNAL(triggered()), this, SLOT(actionExit()));
    connect(ui->actionImport_data_files,
            SIGNAL(triggered()), this, SLOT(actionImport()));
    connect(ui->actionSave_chart,
            SIGNAL(triggered()), this, SLOT(actionSave()));
    connect(ui->customPlot,
            SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));

    ui->actionSave_chart->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//every time the mouse position changes
void MainWindow::mouseMove(QMouseEvent * event)
{
    int marginx = ui->customPlot->xAxis->calculateMargin();
    int paddingx = ui->customPlot->xAxis->padding() + ui->customPlot->yAxis->labelPadding();

    QCPRange xrange = ui->customPlot->xAxis->range();

    //calculate pointed time from the position of the mouse
    double GPStime = xrange.lower + xrange.size() / (ui->customPlot->width() - marginx -  paddingx) * ( event->x() - marginx - ui->customPlot->xAxis->offset());

    //setData function accepts only QVector type as parameter, but only one pair of data/graph is to be displayed
    QVector<double> PointTime, PointData;
    PointTime.append(0);
    PointData.append(0);

    PointTime.append(0);
    PointData.append(0);

    PointTime.append(0);
    PointData.append(0);

    PointTime.append(0);
    PointData.append(0);


    //Mouse pointed time value is set. Search for the closest time value in the GPS time vector. Assign this time and the related altitude to PointTime[0], PointData[0] variables
    for(int i=0;  (i < time_GPS_var.size()) & (i < GPS_var.size()); ++i)
    {
        if(time_GPS_var[i] <= GPStime)
        {
            PointTime[0] = time_GPS_var[i];
            PointData[0] = GPS_var[i];
        }
    }

    for(int i=0;  (i < time_ALT_var.size()) & (i < ALT_var.size()); ++i)
    {
        if(time_ALT_var[i] <= GPStime)
        {
            PointTime[1] = time_ALT_var[i];
            PointData[1] = ALT_var[i];
        }
    }

    for(int i=0;  (i < time_GPS_CORR_var.size()) & (i < GPS_CORR_var.size()); ++i)
    {
        if(time_GPS_CORR_var[i] <= GPStime)
        {
            PointTime[2] = time_GPS_CORR_var[i];
            PointData[2] = GPS_CORR_var[i];
        }
    }

    for(int i=0;  (i < time_BAR_var.size()) & (i < BAR_var.size()); ++i)
    {
        if(time_BAR_var[i] <= GPStime)
        {
            PointTime[3] = time_BAR_var[i];
            PointData[3] = BAR_var[i];
        }
    }
    ui->customPlot->graph(0)->setData(PointTime, PointData);
    ui->customPlot->replot();

    QDateTime timestamp;
    timestamp.setTime_t(PointTime[0]);

    ui->lineEdit_Time->setText(timestamp.toString("hh:mm:ss:zzz"));
    ui->lineEdit_Date->setText(timestamp.toString("yyyy.MMMdd"));

    //write pointed GPS data
    ui->lineEdit_GPS->setText(QString::number(PointData[0]));
    ui->lineEdit_Altimeter->setText(QString::number(PointData[1]));
    ui->lineEdit_GPS_CORR->setText(QString::number(PointData[2]));
    ui->lineEdit_Barometer->setText(QString::number(PointData[3]));

}

void MainWindow::actionImport()
{

    //list of the opened file names
    QStringList filenames = QFileDialog::getOpenFileNames(this,
                                                        tr("Import files"), "/home", tr("Text files(*.txt)"));
    if (filenames.isEmpty()) return;

    //set export chart active
    ui->actionSave_chart->setEnabled(true);

    //sensor filenames
    QString filenameGPS;
    QString filenameALT;
    QString filenameBAR;
    QString filenameGPS_CORR;

    //sort filenames into the specified categories
    for (int i=0; i<filenames.length(); i++)
    {
        if(filenames[i].contains("GPS_CORR"))
            filenameGPS_CORR = filenames[i];
        else if(filenames[i].contains("GPS"))
            filenameGPS = filenames[i];
        else if(filenames[i].contains("ALT"))
            filenameALT = filenames[i];
        else if(filenames[i].contains("BAR"))
            filenameBAR = filenames[i];
    }

    //sensor files
    QFile fileGPS(filenameGPS);
    QFile fileALT(filenameALT);
    QFile fileBAR(filenameBAR);
    QFile fileGPS_CORR(filenameGPS_CORR);

    //open files
    fileGPS.open(QFile::ReadOnly);
    fileALT.open(QFile::ReadOnly);
    fileBAR.open(QFile::ReadOnly);
    fileGPS_CORR.open(QFile::ReadOnly);

    //open streams
    QTextStream inGPS(&fileGPS);
    QTextStream inALT(&fileALT);
    QTextStream inBAR(&fileBAR);
    QTextStream inGPS_CORR(&fileGPS_CORR);

    //strings for every read line
    QString GPSdata;
    QString ALTdata;
    QString BARdata;
    QString GPS_CORRdata;

    //until we get to the end of the file
    while( !inGPS.atEnd())
    {
        GPSdata = inGPS.readLine();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////// GPS data processing ///////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        QString GPS_date;
        QString GPS_time;
        QString GPS_altitude;

        int hour;
        int minute;
        int second;
        int msecond;

        //RMC messages contain date and time data
        if( GPSdata.contains("$GPRMC"))
        {
            QStringList GPSdata_split = GPSdata.split(',');
            if(GPSdata_split.length()>=10)
            {
                GPS_date = GPSdata_split[9];
                GPS_time = GPSdata_split[1];

                hour = GPS_time.mid(0, 2).toInt();
                minute = GPS_time.mid(2, 2).toInt();
                second = GPS_time.mid(4, 2).toInt();
                msecond = GPS_time.mid(7, 2).toInt()*10;

                QTime time(hour, minute, second, msecond);
                QDate date( 2000 + GPS_date.mid(4,2).toInt(), GPS_date.mid(2,2).toInt(), GPS_date.mid(0,2).toInt() );

                QDateTime datetime(date, time);

                time_GPS_var.push_back(datetime.toTime_t());
            }
        }

        //GGA messages contain altitude data
        if( GPSdata.contains("$GPGGA"))
        {
            QStringList GPSdata_split = GPSdata.split(',');
            if(GPSdata_split.length()>=10)
            {
                GPS_altitude = GPSdata_split[9];

                GPS_var.push_back(GPS_altitude.toDouble());
            }
        }

        //the program ignores every other GPS message

    }


    while( !inGPS_CORR.atEnd())
    {
        GPS_CORRdata = inGPS_CORR.readLine();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////// Corrected GPS data processing /////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        QString GPS_date;
        QString GPS_time;
        QString GPS_altitude;

        int hour;
        int minute;
        int second;
        int msecond;

        double GPS_altitude_rounded;

        QStringList GPS_CORRdata_split = GPS_CORRdata.split(',');

        if(GPS_CORRdata_split.length() >= 3)
        {
            GPS_date = GPS_CORRdata_split[0];
            GPS_time = GPS_CORRdata_split[1];
            GPS_altitude = GPS_CORRdata_split[2];

            hour = GPS_time.mid(0, 2).toInt();
            minute = GPS_time.mid(2, 2).toInt();
            second = GPS_time.mid(4, 2).toInt();
            msecond = GPS_time.mid(6, 2).toInt()*10;

            QTime time(hour, minute, second, msecond);
            QDate date( 2000 + GPS_date.mid(4,2).toInt(), GPS_date.mid(2,2).toInt(), GPS_date.mid(0,2).toInt() );

            QDateTime datetime(date, time);

            if(GPS_altitude != "NaN")
            {
                GPS_altitude_rounded = (int(10*GPS_altitude.toDouble()))/10;

                time_GPS_CORR_var.push_back(datetime.toTime_t());

                GPS_CORR_var.push_back(GPS_altitude_rounded);
            }
        }

    }

    //until we get to the end of the file
    while( !inALT.atEnd())
    {
        ALTdata = inALT.readLine();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////// ALT data processing ///////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        QString ALT_date;
        QString ALT_time;

        int hour;
        int minute;
        int second;
        int msecond;

        QString ALT_altitude;

        //#ALT messages contain altitude data and error code
        if( ALTdata.contains("#ALT"))
        {

            QStringList ALTdata_split = ALTdata.split(' ');
            if(ALTdata_split.length()>=4)
            {
                ALT_altitude = ALTdata_split[1];

                //if( ALTdata_split[3] == "00")

                if( time_ALT_var.size() == (ALT_var.size() + 1))
                {
                    ALT_var.push_back(ALT_date.toDouble());
                }

            }
        }

        //timestamp
        if( ALTdata.contains("#TIME"))
        {
            QStringList ALTdata_split = ALTdata.split(' ');
            if(ALTdata_split.length()>=3)
            {
                ALT_date = ALTdata_split[1];
                ALT_time = ALTdata_split[2];

                hour = ALT_time.mid(0, 2).toInt();
                minute = ALT_time.mid(3, 2).toInt();
                second = ALT_time.mid(6, 2).toInt();
                msecond = ALT_time.mid(9, 3).toInt();


                QTime time(hour, minute, second, msecond);
                QDate date( ALT_date.mid(0,4).toInt(), ALT_date.mid(5,2).toInt(), ALT_date.mid(8,2).toInt() );

                QDateTime datetime(date, time);

                time_ALT_var.push_back(datetime.toTime_t());

            }
        }

        //the program ignores every other ALT message

    }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////// BAR data processing ///////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   while( !inBAR.atEnd())
   {
        BARdata = inBAR.readLine();

        QString BAR_date_time;
        QString BAR_altitude;

        int hour;
        int minute;
        int second;
        int msecond;

        QStringList BARdata_split = BARdata.split(",");

        if(BARdata_split.length()>=4)
        {

                BAR_date_time = BARdata_split[0];

                hour = BAR_date_time.mid(11, 2).toInt();
                minute = BAR_date_time.mid(14, 2).toInt();
                second = BAR_date_time.mid(17, 2).toInt();
                msecond = BAR_date_time.mid(20, 3).toInt();


                QTime time(hour, minute, second, msecond);
                QDate date( BAR_date_time.mid(0,4).toInt(), BAR_date_time.mid(5,2).toInt(), BAR_date_time.mid(8,2).toInt() );

                QDateTime datetime(date, time);

                time_BAR_var.push_back(datetime.toTime_t());

                BAR_altitude = BARdata_split[3];

                time_BAR_var.push_back(datetime.toTime_t());
                BAR_var.push_back(BAR_altitude.toDouble());
         }



   }

    ui->customPlot->setLocale(QLocale (QLocale::English, QLocale::UnitedKingdom));

    //setting up graph look: colour, line style
    //graph(1) is the GPS graph
    ui->customPlot->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    //graph(2) is the ALT graph
    ui->customPlot->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(2)->setPen(QPen(Qt::blue));
    //graph(3) is the BAR graph
    ui->customPlot->graph(3)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(3)->setPen(QPen(Qt::green));
    //graph(4) is the corrected GPS graph
    ui->customPlot->graph(4)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(4)->setPen(QPen(Qt::black));

    //set marker point to a black point
    ui->customPlot->graph(0)->setPen(QPen(Qt::black));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);

    //setting data of the graphs
    ui->customPlot->graph(1)->setData(time_GPS_var, GPS_var);
    ui->customPlot->graph(2)->setData(time_ALT_var, ALT_var);
    ui->customPlot->graph(3)->setData(time_BAR_var, BAR_var);
    ui->customPlot->graph(4)->setData(time_GPS_CORR_var, GPS_CORR_var);



    //error handling
    if( GPS_var.isEmpty() | time_GPS_var.isEmpty() )
    {
        QMessageBox::critical(this, "Error", "Could not read time or altitude data");
        return;
    }

    /*setting range and margin depending on the data read: must fit into the window, and the window should show that no data is missing, hence
      the 5% of the data range is left for the margin. The axis ranges are set when the data is read in. Enabling the rangeDrag and rangeZoom options we can easily
      zoom into and move the graph
    */
    double min, max;
    double margin;

    min = max = GPS_var[0];

    for(int i=0; i<GPS_var.size(); ++i)
    {
        if( GPS_var[i] > max)
        { max = GPS_var[i]; }
        if( GPS_var[i] < min)
        { min = GPS_var[i]; }
    }

    for(int i=0; i<ALT_var.size(); ++i)
    {
        if( ALT_var[i] > max)
        { max = ALT_var[i]; }
        if( ALT_var[i] < min)
        { min = ALT_var[i]; }
    }
    for(int i=0; i<BAR_var.size(); ++i)
    {
        if( BAR_var[i] > max)
        { max = BAR_var[i]; }
        if( BAR_var[i] < min)
        { min = BAR_var[i]; }
    }
    for(int i=0; i<GPS_CORR_var.size(); ++i)
    {
        if( GPS_CORR_var[i] > max)
        { max = GPS_CORR_var[i]; }
        if( GPS_CORR_var[i] < min)
        { min = GPS_CORR_var[i]; }
    }

    margin = (max-min) / 20;

    ui->customPlot->xAxis->setRange(time_GPS_var[0], time_GPS_var.back());
    ui->customPlot->yAxis->setRange(min - margin, max + margin);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    //when everything is set, customPlot must be replotted
    ui->customPlot->replot();

    //closing the files
    fileGPS.close();
    fileALT.close();

}

void MainWindow::actionExit()
{
    close();
}

void MainWindow::actionContact()
{
    Dialog about;
    if(!about.exec()) {return;}
}


void MainWindow::actionSave()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save image", qApp->applicationDirPath(), ".png");
    ui->customPlot->savePng(fileName);
}