#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <packetmachine.hpp>
#include <string>
//#include "listmodel.h"
#include "packetlistmodel.h"
#include "deviceselect.h"
#include<pcap.h>
#include <sstream>
#include <QElapsedTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    pm::Machine m;
    bool zikkoutyu;
    void select();
  private:
    Ui::MainWindow *ui;
    DeviceSelect *ds;
    ListModel *model;
  public slots:
  private slots:
    //void on_pushButton_clicked(bool checked);
    void on_pushButton_clicked();
    //void capture(QString);

};

#endif // MAINWINDOW_H
