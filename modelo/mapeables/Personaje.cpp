//
// Created by sebas on 30/8/19.
//

#include "Personaje.h"
#include "../../comportamiento/Comportamiento.h"

#include <utility>

Personaje::Personaje(int x, int y, int z, string nombre, Mapa *mapa, Comportamiento *comportamiento, Fisica *fisica, Grafico *grafico):
        Mapeable(x, y, z, mapa, fisica, grafico),
        _velocidad(0, 0, 0),
        comportamiento(comportamiento),
        nombre(move(nombre)) {}

Velocidad &Personaje::velocidad() {
    return _velocidad;
}

void Personaje::actualizar(SDL_Renderer *renderer) {
    comportamiento->actualizar(*this);
    Mapeable::actualizar(renderer);
}
