//
// Created by sebas on 7/11/19.
//

#include "PuntuacionJugadores.h"

void PuntuacionJugadores::setPuntuacion(string jugador, int puntuacion) {
    puntuaciones[jugador] = puntuacion;
}

unordered_map<string, int> PuntuacionJugadores::getPuntuaciones() {
    return puntuaciones;
}
