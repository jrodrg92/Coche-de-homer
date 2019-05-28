#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QGroupBox>
#include "vehiculo.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void almacenarInformacion(Vehiculo *nuevo);
    void limpiar();
    void crearVehiculo(int pos);
    Vehiculo* getLista(int i) const;
    void setLista(Vehiculo *vehiculo);
    int numeroDeCoches();

private slots:

     void on_pushGenerar_clicked();
     void on_pushGuardar_clicked();
     void on_pushAnterior_clicked();
     void on_pushSig_clicked();
     void on_pushFoto_clicked();


private:
    Ui::MainWindow *ui;
    Vehiculo *vehiculo1;
    vector<Vehiculo*> vehiculos;
    int pos=0;
    int pos2=pos;

};

#endif // MAINWINDOW_H
