#include "Items.hpp"
#include <stdlib.h>

Item::Item(){

}

Item::Item(string nombre_, int puntosSalud_, string descripcion_){
    nombre = nombre_;
    puntosSalud = puntosSalud_;
    descripcion = descripcion_;
}



string Item::getNombre(){
    return nombre;
}

void Item::setNombre(string nombre_){
    nombre = nombre_;
}

int Item::getPuntosSalud(){
    return puntosSalud;
}

void Item::setPuntosSalud(int puntosSalud_){
    puntosSalud = puntosSalud_;
}

string Item::getDescripcion() {
    return descripcion;
}

void Item::setDescripcion(string descripcion_){
    descripcion = descripcion_;
}

void Item::imprime(){
    cout << getDescripcion() << "otorga " << getPuntosSalud() << "puntos de salud" << endl;
}