#include <iostream>
#include "Guerrero.hpp"
#include "Amigo.hpp"
#include "Mundos.hpp"
#include<cstdlib>

#include <vector>

string nombresGuerreros[20] = {
  "Gormak, el Devorador de Almas",
  "Lysandra, la Bruja Sanguinaria",
  "Dracar, el Señor de las Sombras",
  "Morgath, el Caminante del Abismo",
  "Zephyr, el Espectro de la Tormenta",
  "Sylthar, el Vengador Oscuro",
  "Elara, la Serpiente de Hielo",
  "Morghul, el Despiadado Carnicero",
  "Valkyr, el Caballero del Inframundo",
  "Zarael, el Archimago de los Horrores",
  "Gorganna, la Bestia Despiadada",
  "Ragnok, el Gigante de las Montañas",
  "Isolde, la Hechicera de los Bosques Malditos",
  "Varax, el Nigromante de los Lamentos",
  "Nyx, el Maestro de los Engaños",
  "Skarn, el Guardián de la Tumba Eterna",
  "Vespera, la Reina de las Pesadillas",
  "Thulgrim, el Guerrero Inmortal",
  "Arachne, la Tejedora de Veneno",
  "Malachi, el Jinete de las Tinieblas"
};

string descripcionesGuerreros[20] = {
  "Demonio ancestral que acecha desde las profundidades infernales.",
  "Feroz guerrero orco que lidera hordas sedientas de sangre.",
  "Araña gigante con veneno letal que teje sus redes en las sombras.",
  "Hombre lobo maldito por la luna llena y hambriento de carne humana.",
  "Espíritu vengativo atrapado en el plano etéreo, deseoso de cobrar su deuda.",
  "Caballero oscuro que busca reclamar almas para su siniestro señor.",
  "Elemental de fuego imbuido de ira ardiente y destructiva.",
  "Gárgola de piedra viva, vigilante de antiguas ruinas encantadas.",
  "Sirena seductora que atrae a los navegantes hacia su trágico destino.",
  "Guerrero esquelético armado con una espada maldita de poder ancestral.",
  "Hada engañosa que usa su magia para confundir y controlar a los viajeros.",
  "Minotauro gigante que habita en un laberinto mortal, esperando desafiantes.",
  "Banshee con un grito que perfora el alma, anunciando la muerte inminente.",
  "Trol de piedra con fuerza descomunal y resistencia implacable.",
  "Espectro vengativo de un antiguo rey, buscando venganza contra los vivos.",
  "Elemental de agua que emerge de los mares para arrastrar a los navegantes hacia las profundidades.",
  "Nigromante maestro en el arte oscuro de la necromancia y control de muertos vivientes.",
  "Vampiro elegante y seductor que se alimenta de la vida de los mortales.",
  "Dragón de escamas negras que aterroriza los cielos con su aliento de fuego.",
  "Guardián ancestral de una reliquia sagrada, dispuesto a matar para protegerla."
};

string atributos[3] = {"agua", "fuego", "planta"};



int generateRandomNum(int range) {
  return rand() % (range);
}

int ProcesaCantidadItem(string nombre){
  if(nombre=="Escudo"){
    return 0;
  }
  else if(nombre=="Mini escudo"){
    return 1;
  }
  else if(nombre=="Vendas"){
    return 2;
  }
  else if(nombre=="Resurección"){
    return 0;
  }
  else if(nombre=="Bidon"){
    return 0;
  }else{
  return -1;
  }
}


Guerrero createCharacter () {
  string nombre, descripcion, atributo;
  int opcionClase = 0;
  int opcionClase2 = 0;
  bool loop = true;
  cout << "-----Bienvenido a JUEGO-----" << endl;
  cout << "Como quiere que se llame su personaje: ";
  cin >> nombre;
  while (loop) {
    cout << "Elija una clase para su personaje: " << endl;
    cout << "1)Orco" << endl;
    cout << "2)Elfo" << endl;
    cout << "3)Humano" << endl;
    cout << "4)Duende" << endl;
    cout << "5)Enano" << endl;
    cout << "Ingrese el numero deseado: ";
    cin >> opcionClase;
    try {
      if (cin.fail()){
        cin.clear(); cin.ignore(512, '\n');
        throw "Opción Invalida. Escoge un número!";
      };
      switch (opcionClase) {
        case 1:
          descripcion = "Orco de fuerza increible";
          loop = false;
          break;
        case 2:
          descripcion = "Elfo agil con punteria impecable";
          loop = false;
          break;
        case 3:
          descripcion = "Humano común y corriente";
          loop = false;
          break;
        case 4:
          descripcion = "Duende capaz de robar todo";
          loop = false;
          break;
        case 5:
          descripcion = "Enano de las minas de Moria";
          loop = false;
          break;
        default:
          throw "Opción Invalida. Escoge una de las opciones disponibles!";
      } 
    }catch (const char* msg) {
            cout << msg << endl;
    }
  }
  loop = true;
  cout << "Sabia eleccion! Ahora elija un atributo elemental para su personaje: " << endl;
  while (loop) {
    cout << "Recuerde que el elemento de su personaje determina sus debilidades y fortalezas" << endl;
    cout << "1)Fuego" << endl;
    cout << "2)Agua" << endl;
    cout << "3)Planta" << endl;
    cout << "Ingrese el numero deseado: ";
    cin >> opcionClase;
    try {
      if (cin.fail()){
        cin.clear(); cin.ignore(512, '\n');
        throw "Opción Invalida. Escoge un número!";
      };
      switch (opcionClase) {
        case 1:
          atributo = "fuego";
          loop = false;
          break;
        case 2:
          atributo = "agua";
          loop = false;
          break;
        case 3:
          atributo = "planta";
          loop = false;
          break;
        default:
          throw "Opción Invalida. Escoge una de las opciones disponibles!";
      } 
    }catch (const char* msg) {
      cout << msg << endl;
    }
  }
   return Guerrero(nombre, descripcion, NULL, 100, 100, 300, atributo);
}

int main() {

  //Creación de mundos
  vector<Mundo*> mundos;
  mundos.push_back(new Mundo("Alderaan", NULL, NULL, "Planeta desertico"));
  mundos.push_back(new Mundo("Chicago", NULL, NULL, "Planeta nevado"));
  mundos.push_back(new Mundo("Coruscant", NULL, NULL, "Planeta lleno de lava"));
  mundos.push_back(new Mundo("Tlaxcala", NULL, NULL, "Planeta de los asteroides"));
  mundos.push_back(new Mundo("Hoth", NULL, NULL, "Planeta del destino"));
  mundos.push_back(new Mundo("xxxxxxx", NULL, NULL, "xxxxxxxx"));


  //Creación de Items
 vector<Item*> items;
  items.push_back(new Item("Escudo", 50, "Otorga un escudo de 50 de vida"));
  items.push_back(new Item("Mini escudo", 25, "Otorga un escudo de 25 de vida"));
  items.push_back(new Item("Vendas", 15, "Otorga 15 de vida"));
  items.push_back(new Item("Bidon", 100, "Recupera 100 puntos de vida"));
  items.push_back(new Item("xxxx", 100, "xxxxx"));


  for(int i=0;i<mundos.size();i++){
    mundos[i]->setSiguiente(mundos[i+1]);
    mundos[i]->setItem(items[i]);
  }

  vector<Personaje*> personajes;
  // Personajes mundo 1
  personajes.push_back(new Guerrero(nombresGuerreros[generateRandomNum(19)], descripcionesGuerreros[generateRandomNum(19)], mundos[2], 100, 100, 30, atributos[generateRandomNum(2)]));
  personajes.push_back(new Amigo ("Moi","Mago",mundos[1], true, "Soy un viajero en busqueda de mi hija"));
 // Personajes mundo 2
  personajes.push_back(new Guerrero(nombresGuerreros[generateRandomNum(19)], descripcionesGuerreros[generateRandomNum(19)], mundos[2], 100, 100, 40, atributos[generateRandomNum(2)]));
  personajes.push_back(new Amigo ("Fher","Curandero",mundos[2], true, "Viajo por campos de batalla ayudando a heridos"));
   // Personajes mundo 3
  personajes.push_back(new Guerrero(nombresGuerreros[generateRandomNum(19)], descripcionesGuerreros[generateRandomNum(19)], mundos[3], 100, 100, 50, atributos[generateRandomNum(2)]));
  personajes.push_back(new Amigo ("Carlos","Hechizero",mundos[3], true, "Estoy en busqueda de compañeros"));
   // Personajes mundo 4
  personajes.push_back(new Guerrero(nombresGuerreros[generateRandomNum(19)], descripcionesGuerreros[generateRandomNum(19)], mundos[4], 100, 100, 55, atributos[generateRandomNum(2)]));
  personajes.push_back(new Amigo ("Santos","Cazador",mundos[4], true, "Quiero vencer a las bestias más fuertes del reino"));
   // Personajes mundo 5
  personajes.push_back(new Guerrero(nombresGuerreros[generateRandomNum(19)], descripcionesGuerreros[generateRandomNum(19)], mundos[5], 150, 150, 60, atributos[generateRandomNum(2)]));
  personajes.push_back(new Amigo ("Gael","Científico",mundos[5], true, "Muchas felicidades! Has liberado al reino del mal!"));

  Guerrero jugador = createCharacter();
  for(int m=0;m<mundos.size();m++){
    int usos=ProcesaCantidadItem(mundos[m]->getItem()->getNombre());
    jugador.setMundo(mundos[m]);
  cout<<"Te encuentras en " <<jugador.getMundo()->getNombre() << endl;
  cout << jugador.getMundo()->getDescripcion() << endl;
  for(int i=0;i<2;i++){
    cout<<"--------------------------------------------------------------------------------"<<endl;
    if (Guerrero* ptrG = dynamic_cast<Guerrero*>(personajes[i])){
      cout << personajes[i] << endl;
      while(jugador.getptSaludActual()>0){
      jugador.recibeInteraccion(personajes[i]->juega(), ptrG->getAtributo(),true);
      if(jugador.getptSaludActual()==0){
          cout<<"Game over"<<endl;
          exit(0);
      }
      if(m>=1 && usos>0){
        string d;
        cout<<"Preciona 'u' para usar "<<mundos[m-1]->getItem()->getNombre()<<endl;
        cin>>d;
        if(d=="u"){
          jugador.recibeInteraccion(mundos[m-1]->getItem()->getPuntosSalud(),"null",true);
          usos=usos-1;
        }
      }
      cout<<"--------------------------------------------------------------------------------"<<endl;
      cout<<"Es tu turno de atacar, presiona cualquier tecla... ";
      cin.ignore();
      cin.get();
      ptrG->recibeInteraccion(jugador.juega(),jugador.getAtributo(),false);
          if(ptrG->getptSaludActual()==0 && m < 4){
            cout<<"¡Bien hecho!, eliminaste a "<<ptrG->getNombre()<<endl;
            cout<<"Avanzas al siguiente mundo..."<<endl;
            cout<<"Pero antes una recompensa"<<endl;
            jugador.recibeInteraccion(personajes[i+1]->juega(), "null",true);
            cout<<"Desbloqueaste el item perdido de "<<mundos[m]->getNombre()<<", "<<mundos[m]->getItem()->getDescripcion()<<", usalo cuando lo consideres necesario"<<endl;
            personajes.erase(personajes.begin());
            personajes.erase(personajes.begin());
          break;
        } else {
          jugador.recibeInteraccion(personajes[i+1]->juega(), "null",true);
          cout << "Felicidades has terminado el juego!" << endl;
          exit(0);
        }
      }
    }
    cout<<"--------------------------------------------------------------------------------"<<endl;
    }  
  }
}
