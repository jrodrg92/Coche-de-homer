#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include "vehiculo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vehiculo1=new Vehiculo();



    QObject::connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

Vehiculo *MainWindow::getLista(int i) const
{
    return vehiculos[i];
}

void MainWindow::setLista(Vehiculo *vehiculo)
{
    vehiculos.push_back(vehiculo);
}

int MainWindow::numeroDeCoches(){
    return vehiculos.size();
}

void MainWindow::on_pushGenerar_clicked(){

    ui->mat_Et->setText(vehiculo1->nuevaMatricula());

}

void MainWindow::on_pushGuardar_clicked(){

    Vehiculo *nuevo=new Vehiculo();

    setLista(nuevo);

    almacenarInformacion(nuevo);

    limpiar();

    crearVehiculo(pos);

    pos++;

    pos2=pos-1;
}

void MainWindow::almacenarInformacion(Vehiculo *nuevo){

    nuevo->setNom(ui->nom_Et->text());
    nuevo->setMatricula(ui->mat_Et->text());
    nuevo->setPotencia((QString) ui->spinBox->text());
    nuevo->setColor(ui->comboBox->currentText());

    if(ui->radioButton->isChecked()){
        nuevo->setCombustible("Diesel");
    }
    else if(ui->radioButton_2->isChecked()){
        nuevo->setCombustible("Gasolina");
    }
    else if(ui->radioButton_3->isChecked()){
        nuevo->setCombustible("Electrico");
    }

    if(ui->radioButton_4->isChecked()){
        nuevo->setNumRuedas((QString)"1");
    }
    else if(ui->radioButton_5->isChecked()){
        nuevo->setNumRuedas((QString)"2");
    }
    else if(ui->radioButton_6->isChecked()){
        nuevo->setNumRuedas((QString)"3");
    }
    else if(ui->radioButton_7->isChecked()){
        nuevo->setNumRuedas((QString)"4");
    }

    if(ui->checkBox_5->isChecked()){
        nuevo->setRueda(true);
    }
    else{
        nuevo->setRueda(false);
    }

    if(ui->checkBox_8->isChecked()){
        nuevo->setBocinas(true);
    }
    else{
        nuevo->setBocinas(false);
    }

    if(ui->checkBox_6->isChecked()){
        nuevo->setKit(true);
    }
    else{
        nuevo->setKit(false);
    }

    if(ui->checkBox_7->isChecked()){
        nuevo->setBurbuja(true);
    }
    else{
        nuevo->setBurbuja(false);
    }

    if(ui->checkBox_9->isChecked()){
        nuevo->setPortavasos(true);
    }
    else{
        nuevo->setPortavasos(false);
    }

    if(nuevo->getNumRuedas()=="4"){
        if(nuevo->getColor()=="VERDE"&&nuevo->getBocinas()==true&&nuevo->getBurbuja()==true){
            nuevo->setTipo((QString)"Coche de Homer");
        }
        else{
            nuevo->setTipo((QString)"Coche");
        }
    }
    else if(nuevo->getNumRuedas()=="1"){
        nuevo->setTipo((QString)"Monociclo");
    }
    else if(nuevo->getNumRuedas()=="2"){
        nuevo->setTipo((QString)"Moto");
    }
    else if(nuevo->getNumRuedas()=="3"){
        nuevo->setTipo((QString)"Triciclo");
    }



}

void MainWindow::limpiar(){

    ui->nom_Et->clear();
    ui->mat_Et->clear();
    ui->horizontalSlider->setValue(90);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);

}

void MainWindow::on_pushFoto_clicked(){

    /*QString tipo=ui->lineEdit_Tipo->text();

    if(tipo.toStdString()=="Coche de Homer"){
        imprimir_Imagen(tipo.toStdString());
    }
    else if(tipo.toStdString()=="Coche"){
        imprimir_Imagen(tipo.toStdString());
    }
    else if(tipo.toStdString()=="Monociclo"){
        imprimir_Imagen(tipo.toStdString());
    }
    else if(tipo.toStdString()=="Moto"){
        imprimir_Imagen(tipo.toStdString());
    }
    else if(tipo.toStdString()=="Triciclo"){
        imprimir_Imagen(tipo.toStdString());
    }*/

}

void MainWindow::crearVehiculo(int loc){

        if(loc>=0&&loc<=pos){


            Vehiculo *imp=new Vehiculo();
            imp=getLista(loc);

            ui->lineEdit->setText(imp->getNom());
            ui->lineEdit->setReadOnly(true);
            ui->lineEdit_1->setText(imp->getMatricul());
            ui->lineEdit_1->setReadOnly(true);
            ui->lineEdit_2->setText(imp->getNumRuedas());
            ui->lineEdit_2->setReadOnly(true);
            ui->lineEdit_3->setText(imp->getCombustible());
            ui->lineEdit_3->setReadOnly(true);
            ui->lineEdit_Color->setText(imp->getColor());
            ui->lineEdit_Color->setReadOnly(true);
            ui->lineEdit_Pot->setText(imp->getPotencia());
            ui->lineEdit_Pot->setReadOnly(true);

            if(imp->getRueda()==true){
                ui->checkBox_Rep->setChecked(true);

            }
            ui->checkBox_Rep->setEnabled(false);
            if(imp->getKit()==true){
                ui->checkBox_Kit->setChecked(true);

            }
            ui->checkBox_Kit->setEnabled(false);
            if(imp->getBurbuja()==true){
                ui->checkBox_Bu->setChecked(true);

            }
             ui->checkBox_Bu->setEnabled(false);
            if(imp->getPortavasos()==true){
                ui->checkBox_Por->setChecked(true);

            }
            ui->checkBox_Por->setEnabled(false);
            if(imp->getBocinas()==true){
                ui->checkBox_Boc->setChecked(true);

            }
             ui->checkBox_Boc->setEnabled(false);

             ui->lineEdit_Tipo->setText(imp->getTipo());
             ui->lineEdit_Tipo->setReadOnly(true);

        }



}

void MainWindow::on_pushAnterior_clicked(){

    crearVehiculo(pos2-=1);
}

void MainWindow::on_pushSig_clicked(){


    crearVehiculo(pos2+=1);
}
