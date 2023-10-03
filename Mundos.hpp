#pragma once
#include "Items.hpp"
#include <iostream>
using namespace std;

class Mundo{
    private:
        string nombre;
        Mundo* siguiente;
        Item* item;
        string descripcion;
    public:
        Mundo();
        Mundo(string, Mundo*, Item*, string);
        string getNombre();
        void setNombre(string);
        string getDescripcion();
        void setDescripcion(string);
        void setSiguiente(Mundo*);
        Mundo* getSiguiente();
        Item* getItem();
        void setItem(Item*);
};