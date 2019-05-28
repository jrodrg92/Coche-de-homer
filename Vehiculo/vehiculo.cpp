#include "vehiculo.h"
#include "time.h"

/*Constructor de la clase*/

Vehiculo::Vehiculo(){

}

/*Destructor de la clase*/

Vehiculo::~Vehiculo(){

}

/*Metodo getters y setters para acceder a las variables privadas de la clase Vehiculo*/
void Vehiculo::setNom(QString value){
    this->nombre=value;
}

QString Vehiculo::getNom(){
    return nombre;
}

void Vehiculo::setMatricula(QString value){
    this->matricula=value;
}

QString Vehiculo::getMatricul(){
    return matricula;
}

void Vehiculo::setPotencia(QString value){
    this->potencia_Motor=value;
}

QString Vehiculo::getPotencia(){
    return potencia_Motor;
}

void Vehiculo::setNumRuedas(QString value){
    this->numRuedas=value;
}

QString Vehiculo::getNumRuedas(){
    return numRuedas;
}

void Vehiculo::setCombustible(QString value){
    this->tipo_combustible=value;
}

QString Vehiculo::getCombustible(){
    return tipo_combustible;
}

void Vehiculo::setColor(QString value){
    this->tipo_color=value;
}

QString Vehiculo::getColor(){
    return tipo_color;
}

void Vehiculo::setBocinas(bool value){
    this->mas_Bocinas=value;
}

bool Vehiculo::getBocinas(){
    return mas_Bocinas;
}

void Vehiculo::setBurbuja(bool value){
    this->burbuja=value;
}

bool Vehiculo::getBurbuja(){
    return burbuja;
}

void Vehiculo::setPortavasos(bool value){
    this->portavasos=value;
}

bool Vehiculo::getPortavasos(){
    return portavasos;
}

void Vehiculo::setKit(bool value){
    this->kit_Pinchazos=value;
}

bool Vehiculo::getKit(){
    return kit_Pinchazos;
}

void Vehiculo::setRueda(bool value){
    this->rueda_Repuesto=value;
}

bool Vehiculo::getRueda(){
    return rueda_Repuesto;
}

void Vehiculo::setTipo(QString value){
    this->tipo=value;
}

QString Vehiculo::getTipo(){
    return tipo;
}

int Vehiculo::getCont(){
    return contVehiculo;
}

/*Metodo que genera la matricula de forma aleatoria*/

QString Vehiculo::nuevaMatricula()
{

    QString matricula;
       matricula.resize(8);
       for (int i = 0; i < matricula.size() ; i++)
           if (i<4) {
               matricula[i] = QChar(ASCII_LETRA_0 + char(qrand() % (ASCII_LETRA_9 - ASCII_LETRA_0)));

           } else if (i==4) {
               matricula[i]=QChar(ASCII_LETRA_GUION);

           }else {
               matricula[i] = QChar(ASCII_LETRA_B + char(qrand() % (ASCII_LETRA_Z - ASCII_LETRA_B)));
               if (matricula[i]==QChar(ASCII_LETRA_E|ASCII_LETRA_I|ASCII_LETRA_O|ASCII_LETRA_U)) {
                   i--;
               }
               if (matricula[i]==QChar(ASCII_LETRA_E)) {
                   i--;
               }
               if (matricula[i]==QChar(ASCII_LETRA_I)) {
                   i--;
               }
               if (matricula[i]==QChar(ASCII_LETRA_O)) {
                   i--;
               }
               if (matricula[i]==QChar(ASCII_LETRA_U)) {
                   i--;
               }
           }



    return matricula;
}
