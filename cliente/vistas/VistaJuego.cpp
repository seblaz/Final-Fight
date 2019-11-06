//
// Created by sebas on 6/11/19.
//

#include <algorithm>
#include "VistaJuego.h"
#include "../../servicios/Locator.h"

void VistaJuego::graficar(SDL_Renderer *renderer) {

    auto entidades = Locator::mapa()->devolverEntidades();

    sort(entidades.begin(), entidades.end(), [](Entidad *a, Entidad *b) {
        return a->getEstado<Posicion>("posicion")->getY() > b->getEstado<Posicion>("posicion")->getY();
    });

    for (auto entidad : entidades) {
        for (auto *comportamiento : entidad->getComportamientos()) {
            comportamiento->actualizar(entidad);
        }
    }
}
