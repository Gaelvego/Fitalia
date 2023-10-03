#include "Personaje.hpp"

Personaje::Personaje(){

}

Personaje::Personaje(string nombre_, string descripcion_, Mundo* mundo_){
    nombre = nombre_;
    descripcion = descripcion_;
    mundo = mundo_;
}

string Personaje::getNombre() const{
    return nombre;
}

void Personaje::setNombre(string nombre_){
    nombre = nombre_;
}
string Personaje::getDescripcion(){
    return descripcion;
}

void Personaje::setDescripcion(string descripcion_){
    descripcion = descripcion_;
}

Mundo* Personaje::getMundo(){
    return mundo;
}

void Personaje::setMundo(Mundo* mundo_){
    mundo = mundo_;
}

string Personaje::imprime() {
    return "Te encuentras con " + nombre + "\n" + descripcion ;
}

std::ostream& operator << (std::ostream& salida, Personaje* p1) {
    salida << p1->imprime();
    return salida;
}
