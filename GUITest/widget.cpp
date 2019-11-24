/*#include "widget.h"
//画面表示や操作を管理しているクラスです。
#include "ui_widget.h"
#include <QElapsedTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new ListModel();
    ui->tableView->setModel(model);

    //model->add(new Parson(tr("Taro Yamada"), 21));
    //model->add(new Parson(tr("Hanako Yamada"), 22));

    //connect(ui->pushButton, &QPushButton::clicked, this, &Widget::on_pushButton_clicked);
}

Widget::~Widget()
{
    delete model;
    delete ui;
}

void Widget::on_pushButton_clicked(bool checked)
{
    QElapsedTimer timer;
    timer.start();
    double time=timer.elapsed();
    static int counter = 0;
    model->add(new Packet(counter,time,tr("aaa"),tr("bbb"),tr("ccc"),13));
    //model->add(new Parson(tr("hoge%1").arg(counter), counter));
    counter++;

    ui->tableView->scrollToBottom();
}*/

#include "widget.h"
#include <sstream>
//画面表示や操作を管理しているクラスです。
#include "ui_widget.h"
#include <QElapsedTimer>
Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
  model = new ListModel();
  ui->tableView->setModel(model);
  //model->add(new Parson(tr("Taro Yamada"), 21));
  //model->add(new Parson(tr("Hanako Yamada"), 22));
  //connect(ui->pushButton, &QPushButton::clicked, this, &Widget::on_pushButton_clicked);


  m.on("UDP", [&](const pm::Property& p) {    //イベント "UDP"のコールバック関数
      //const auto& s1=p.value("IPv4.src");
      //const auto& s2=p.value("IPv4.dst");
      const auto& s3=p.pkt_size();
      std::ostringstream s1;
      std::ostringstream s2;

      QElapsedTimer timer;
      timer.start();
      double time=timer.elapsed();
      static int counter = 0;
      const std::string ss3=std::to_string(s3);
          //ストリームにパケットの情報を書きこむ
      s1<<p["IPv4.src"];
      s2<<p["IPv4.dst"];
      const std::string ss1=s1.str();
      const std::string ss2=s2.str();
      model->add(new Packet(counter,time,tr(ss1.c_str()),tr(ss2.c_str()),
              tr("UDP"),tr(ss3.c_str())));
      ui->tableView->scrollToBottom();
      //model->add(new Parson(tr("hoge%1").arg(counter), counter))
          //パケットクラス配列への格納
          //pvec.emplace_back(packet("UDP",p.value("IPv4.src"),p.value("IPv4.dst"),p.pkt_size()));
          //ストリームのクリア
          //s1.str("");s2.str("");s3.str("");
   });

  m.on("TCP", [&](const pm::Property& p) {    //イベント "UDP"のコールバック関数
      //const auto& s1=p.value("IPv4.src");
      //const auto& s2=p.value("IPv4.dst");
      const auto& s3=p.pkt_size();
      std::ostringstream s1;
      std::ostringstream s2;

      QElapsedTimer timer;
      timer.start();
      double time=timer.elapsed();
      static int counter = 0;
      const std::string ss3=std::to_string(s3);
          //ストリームにパケットの情報を書きこむ
      s1<<p["IPv4.src"];
      s2<<p["IPv4.dst"];
      const std::string ss1=s1.str();
      const std::string ss2=s2.str();
      model->add(new Packet(counter,time,tr(ss1.c_str()),tr(ss2.c_str()),
              tr("TCP"),tr(ss3.c_str())));
      ui->tableView->scrollToBottom();
      //model->add(new Parson(tr("hoge%1").arg(counter), counter))
          //パケットクラス配列への格納
          //pvec.emplace_back(packet("UDP",p.value("IPv4.src"),p.value("IPv4.dst"),p.pkt_size()));
          //ストリームのクリア
          //s1.str("");s2.str("");s3.str("");
   });

  m.on("DNS", [&](const pm::Property& p) {    //イベント "UDP"のコールバック関数
      //const auto& s1=p.value("IPv4.src");
      //const auto& s2=p.value("IPv4.dst");
      const auto& s3=p.pkt_size();
      std::ostringstream s1;
      std::ostringstream s2;

      QElapsedTimer timer;
      timer.start();
      double time=timer.elapsed();
      static int counter = 0;
      const std::string ss3=std::to_string(s3);
          //ストリームにパケットの情報を書きこむ
      s1<<p["IPv4.src"];
      s2<<p["IPv4.dst"];
      const std::string ss1=s1.str();
      const std::string ss2=s2.str();
      model->add(new Packet(counter,time,tr(ss1.c_str()),tr(ss2.c_str()),
              tr("DNS"),tr(ss3.c_str())));
      ui->tableView->scrollToBottom();
      //model->add(new Parson(tr("hoge%1").arg(counter), counter))
          //パケットクラス配列への格納
          //pvec.emplace_back(packet("UDP",p.value("IPv4.src"),p.value("IPv4.dst"),p.pkt_size()));
          //ストリームのクリア
          //s1.str("");s2.str("");s3.str("");
   });

  m.add_pcapdev("enp1s0");
  m.start();
}
Widget::~Widget()
{
  delete model;
  delete ui;
}
void Widget::on_pushButton_clicked(bool checked)
{
  QElapsedTimer timer;
  timer.start();
  double time=timer.elapsed();
  static int counter = 0;
  //model->add(new Packet(counter,time,tr("aaa"),tr("bbb"),tr("ccc"),13));
  //model->add(new Parson(tr("hoge%1").arg(counter), counter));
  counter++;
  //ui->tableView->scrollToBottom();
}
