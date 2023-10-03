#include "Guerrero.hpp"
#include <time.h>
#include <stdlib.h>

Guerrero::Guerrero(){

}

Guerrero::Guerrero(string nombre_, string descripcion_, Mundo* mundo_, int ptSaludTotal_, int ptSaludActual_, int ataqueMax_, string atributo_):Personaje(nombre_, descripcion_, mundo_){
    ptSaludTotal = ptSaludTotal_;
    ptSaludActual = ptSaludActual_;
    ataqueMax  = ataqueMax_;
    atributo = atributo_;
}

int Guerrero::getptSaludTotal(){
    return ptSaludTotal; 
}

void Guerrero::setptSaludTotal(int ptSaludTotal_){
    ptSaludTotal = ptSaludTotal_;
}
int Guerrero::getptSaludActual(){
    return ptSaludActual;
}

void Guerrero::setptSaludActual(int ptSaludActual_){
    if(ptSaludActual_<0){
        ptSaludActual = 0;
    }else if(ptSaludActual_>ptSaludTotal){
    ptSaludActual = ptSaludTotal;
    }else{
         ptSaludActual = ptSaludActual_;
    }
}

int Guerrero::getataqueMax(){
    return ataqueMax;
}

void Guerrero::setataqueMax(int ataqueMax_){
    ataqueMax = ataqueMax_;
}

string Guerrero::getAtributo(){
    return atributo;
}

void Guerrero::setAtributo(string atributo_){
    atributo = atributo_;
}

bool Guerrero::vivo(){
    return ptSaludActual>0;
}
int Guerrero::porcentajeSalud(){
    return (ptSaludActual*100)/ptSaludTotal;
}
string Guerrero::imprimeBarraSalud(){
    string caracteres_vida = "||||||||||||||||||||";
    if ((porcentajeSalud()/5)!=20){
    for(int i=20;(i>=(porcentajeSalud()/5));i--){
        caracteres_vida[i]='.';
    }
    }
    return caracteres_vida;
}
string Guerrero::imprime(){
    return Personaje::imprime() + " ¡preparate para pelear!";
}
int Guerrero::juega(){
    Guerrero *clase;
    srand(time(NULL));
    int ataque;
    ataque=rand()%ataqueMax;
    cout<<getNombre()<<" ataca con "<<ataque<<endl;
    return -ataque;
}

void Guerrero::recibeInteraccion(int interaccion, string atributo_, bool tipo){
    float multiplicadorDmg=1;
    if(interaccion<0){
        if (atributo_ == "fuego" && atributo == "planta"){
            cout << "Ataque critico!" << endl;
            multiplicadorDmg = 2;
        } else if (atributo_ == "planta" && atributo == "fuego") {
            cout << "Ataque no efectivo!" << endl;
            multiplicadorDmg = .5;
        }  else if (atributo_ == "agua" && atributo == "planta") {
            cout << "Ataque no efectivo!" << endl;
            multiplicadorDmg = .5;
        }  else if (atributo_ == "agua" && atributo == "fuego") {
            cout << "Ataque critico!" << endl;
            multiplicadorDmg = 2;
        }  else if (atributo_ == "planta" && atributo == "agua") {
            cout << "Ataque critico!" << endl;
            multiplicadorDmg = 2;
        }  else if (atributo_ == "fuego" && atributo == "agua") {
            cout << "Ataque no efectivo!" << endl;
            multiplicadorDmg = .5;
        } 
        if (tipo == 1){
            cout << "Recibiste " << -interaccion*multiplicadorDmg << " de daño" << endl;
        }else{
            cout <<getNombre()<<" recibe " << -interaccion*multiplicadorDmg << " de daño" << endl;
        }
        //cout << "ataque normal: " << interaccion << endl;
        setptSaludActual(ptSaludActual+(interaccion*multiplicadorDmg));
        if(getptSaludActual()==0){
            if(tipo==1){
                cout<<"Estás muerto"<<endl;
            }else{
            cout << getNombre() << " está muert@" <<endl;
            }
        }else{
            cout << imprimeBarraSalud() <<" Salud: "<<getptSaludActual()<<endl;
        }
    }
    else if(interaccion>0){
        cout << "Recibiste " << interaccion << " de salud" << endl;
        setptSaludActual(ptSaludActual+(interaccion));
        cout << imprimeBarraSalud() <<" Salud: "<<getptSaludActual()<<endl;
    }
}