//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_PERSONAJE_H
#define FINAL_FIGHT_PERSONAJE_H


#include <string>
#include "Mapeable.h"
#include "../../comportamiento/Comportamiento.h"
#include "../../fisica/Fisica.h"

using namespace std;

class Personaje : public Mapeable {

private:
    std::string nombre;
    Velocidad _velocidad;
    Comportamiento *comportamiento;
    int posX, posY, posZ;
    bool saltando;
    //bool agachado; //Solo Dug golpea agachado

public:
    Personaje(int x, int y, int z, string nombre, bool saltando ,Mapa *mapa, Comportamiento *comportamiento, Fisica *fisica, Grafico *grafico);
    ~Personaje() = default;
    Velocidad &velocidad();
    void actualizar(SDL_Renderer *renderer) override;
};

#endif //FINAL_FIGHT_PERSONAJE_H