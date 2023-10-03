#include "Personaje.hpp"

class Amigo: public Personaje{
    private:
        bool estatus;
        string historia;
    public:
        Amigo();
        Amigo(string, string, Mundo*, bool, string);
        bool getEstatus();
        void setEstatus(bool);
        string getHistoria();
        void setHistoria(string);
        string imprime() override;
        int juega();
        void recibeInteraccion(int, string, bool);
};