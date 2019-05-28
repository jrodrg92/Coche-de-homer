#ifndef VEHICULO_H
#define VEHICULO_H

#define  ASCII_LETRA_B 66
#define  ASCII_LETRA_Z 90
#define ASCII_LETRA_E 69
#define ASCII_LETRA_I 73
#define ASCII_LETRA_O 79
#define ASCII_LETRA_U 85
#define ASCII_LETRA_0 48
#define ASCII_LETRA_9 57
#define ASCII_LETRA_GUION 45


#include <iostream>
#include <QMainWindow>
#include <QString>
#include <QGroupBox>
#include <vector>
#include <string>

using namespace std;

class Vehiculo{

public:

    Vehiculo();
    ~Vehiculo();


   void setNom(QString value);
   QString getNom();

   void setMatricula(QString value);

   QString getMatricul();

   void setNumRuedas(QString value);
   QString getNumRuedas();

   void setPotencia(QString value);
   QString getPotencia();

   void setCombustible(QString value);
   QString getCombustible();

   void setColor(QString value);
   QString getColor();

   void setTipo(QString value);
   QString getTipo();

   void setBurbuja(bool value);
   bool getBurbuja();

   void setBocinas(bool value);
   bool getBocinas();

   void setRueda(bool value);
   bool getRueda();

   void setKit(bool value);
   bool getKit();

   void setPortavasos(bool value);
   bool getPortavasos();

   int getCont();

   QString nuevaMatricula();


private:

    QString nombre;
    QString matricula;
    QString numRuedas;
    QString potencia_Motor;
    QString tipo_combustible;
    QString tipo_color;
    bool burbuja;
    bool mas_Bocinas;
    bool rueda_Repuesto;
    bool kit_Pinchazos;
    bool portavasos;

    QString tipo;

    int contVehiculo=0;

};

#endif // VEHICULO_H
