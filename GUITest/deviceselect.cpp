#include "deviceselect.h"
#include "ui_deviceselect.h"
#include<pcap.h>

DeviceSelect::DeviceSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceSelect)
{
    ui->setupUi(this);
    cb = new QComboBox(this);
    pcap_if_t *ii;
        std::string dev;
        std::vector<std::string> devlist;
        int count=1;
        int devnum;
        char *err;
    if(pcap_findalldevs(&ii,err)!=0) printf("error\n");//デバイス名の取得


        for(pcap_if_t *de=ii;de;de=de->next){//デバイス名の一覧表示とvectorへの格納

            std::string device=std::string(de->name);
            cb->addItem(device.c_str());
            //devlist.emplace_back(device);
            count++;
        }
    cb->setGeometry(30,30,180,30);
    //wi=dynamic_cast<Widget*>(parent);
        connect(ui->buttonBox,SIGNAL(accepted()),parent,SLOT(capture(QString)));

}
DeviceSelect::~DeviceSelect(){
    delete ui;
};
/*void DeviceSelect::emitdevSignal(QString name){

    emit devSignal(ui->comboBox->currentText());
}
DeviceSelect::~DeviceSelect()
{
    delete ui;
}*/

