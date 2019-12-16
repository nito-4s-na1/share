#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <packetmachine.hpp>
#include <string>
//#include "listmodel.h"
#include "packetlistmodel.h"
#include<pcap.h>
namespace Ui {
class Widget;
}
class Widget : public QWidget
{
  Q_OBJECT
public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();
  pm::Machine m;
private:
  Ui::Widget *ui;
  ListModel *model;
public slots:
private slots:
  void on_pushButton_clicked(bool checked);
  void on_pushButton_clicked();
};
#endif // WIDGET_H
