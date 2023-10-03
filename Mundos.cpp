#include "Mundos.hpp"

Mundo::Mundo(){

}

Mundo::Mundo(string nombre_, Mundo* siguiente_, Item* item_, string descripcion_){
    nombre = nombre_;
    siguiente = siguiente_;
    item = item_;
    descripcion = descripcion_;
}

string Mundo::getNombre(){
    return nombre;
}

void Mundo::setNombre(string nombre_){
    nombre = nombre_;
}

string Mundo::getDescripcion() {
    return descripcion;
}

void Mundo::setDescripcion(string descripcion_){
    descripcion = descripcion_;
}

void Mundo::setSiguiente(Mundo* mundo_){
    siguiente = mundo_;
}

Mundo* Mundo::getSiguiente(){
    return siguiente;
}

Item* Mundo::getItem(){
    return item;
}

void Mundo::setItem(Item* item_){
    item = item_;
}


