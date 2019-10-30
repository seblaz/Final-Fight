//
// Created by felipe on 22/9/19.
//

#include "Patrullar.h"
#include "../../servicios/Locator.h"
#include "../../graficos/animaciones/FabricaDeAnimacionesDePoison.h"
#include "../../modelo/Velocidad.h"

Patrullar::Patrullar() {
    srand(time(nullptr));
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se instancio un objeto de clase Patrullar");
}

Patrullar::~Patrullar() {
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se elimino un objeto de clase Patrullar");
}

#define RAPIDEZ 4

void Patrullar::actualizar(Entidad *entidad) {

    auto *estado = entidad->getComportamiento<EstadoDePersonajeServidor>("estado");

    int num = 1 + rand() % (101 - 1);

    estado->caminar(entidad, adelante, !adelante, 0, 0);

    if (pasosTotales < contadorDePasos && num > 95) {
        adelante = !adelante;
        contadorDePasos = 0;
        estado->saltar(entidad);
    }
    contadorDePasos++;
}