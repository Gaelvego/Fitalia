#pragma once
#include <iostream>
using namespace std;

class Item {
    private:
        string nombre;
        int puntosSalud;
        string descripcion;
    public:
        Item();
        Item(string, int, string);
        string getNombre();
        void setNombre(string);
        int getPuntosSalud();
        void setPuntosSalud(int);
        string getDescripcion();
        void setDescripcion(string);
        void imprime();
};