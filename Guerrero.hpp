#include "Personaje.hpp"

class Guerrero: public Personaje{
    private:
        int ptSaludTotal;
        int ptSaludActual;
        int ataqueMax;
        string atributo;
    public:
        Guerrero();
        Guerrero(string, string, Mundo*, int, int, int, string);
        int getptSaludTotal();
        void setptSaludTotal(int);
        int getptSaludActual();
        void setptSaludActual(int);
        int getataqueMax();
        void setataqueMax(int);
        string getAtributo();
        void setAtributo(string);
        bool vivo();
        int porcentajeSalud();
        string imprimeBarraSalud();
        string imprime() override;
        int juega();
        void recibeInteraccion(int,string,bool);
};