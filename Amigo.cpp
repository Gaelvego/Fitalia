#include "Amigo.hpp"
#include <stdlib.h>

Amigo::Amigo(){
    
}

Amigo::Amigo(string nombre_, string descripcion_, Mundo* mundo_,bool estatus_, string historia_):Personaje(nombre_, descripcion_, mundo_){
    estatus = estatus_;
    historia = historia_;
}

bool Amigo::getEstatus(){
    return estatus;
}

void Amigo::setEstatus(bool estatus_){
    estatus = estatus_;
}

string Amigo::getHistoria(){
    return historia;
}

void Amigo::setHistoria(string historia_){
    historia = historia_;
}

string Amigo::imprime(){
    return Personaje::imprime() + "\n" + getHistoria() + "\n" + "Te das cuenta que es un@ aliad@" "\n";
}

int Amigo::juega(){
    if(estatus==1){
        cout << this;
        return 20;
    }else{
        cout <<getNombre()<< " No está dispuest@ a hablar" << endl;
        return 0;
    }
}

void Amigo::recibeInteraccion(int interaccion, string null, bool nada){
    if (interaccion < 3) {
        cout << getNombre() << " dormido" << endl;
    }else {
        juega();
    }    
}