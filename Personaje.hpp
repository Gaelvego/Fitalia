#pragma once    
#include <iostream>
#include "Mundos.hpp"
using namespace std;

class Personaje{
    private:
        string nombre;
        string descripcion;
        Mundo* mundo;
    public:
        Personaje();
        Personaje(string, string, Mundo*);
        string getNombre() const;
        void setNombre(string);
        string getDescripcion();
        void setDescripcion(string);
        Mundo* getMundo();
        void setMundo(Mundo*);
        virtual string imprime() ;
        virtual int juega()=0;
        virtual void recibeInteraccion(int, string, bool)=0;
        friend std::ostream& operator<< (std::ostream &, Personaje*);

     
};