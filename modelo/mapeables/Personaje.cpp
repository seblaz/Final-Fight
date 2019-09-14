// Created by sebas on 30/8/19.
//

#include <utility>
#include "Mapeable.h"
#include "Personaje.h"
#include "../../comportamiento/Comportamiento.h"

Personaje::Personaje(int x, int y, int z, string nombre, bool saltando, Mapa *mapa, Comportamiento *comportamiento, Fisica *fisica, Grafico *grafico):
        Mapeable(x, y, z, mapa, fisica, grafico),
        comportamiento(comportamiento),
        _velocidad(0, 0, 0),
        nombre(move(nombre)),
        posX(x),
        posY(y),
        posZ(z),
        saltando(false) {}

Velocidad &Personaje::velocidad() {
    return _velocidad;
}

void Personaje::actualizar(SDL_Renderer *renderer) {
    comportamiento->actualizar(*this);
    Mapeable::actualizar(renderer);
}