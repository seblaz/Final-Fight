//
// Created by sebas on 7/10/19.
//

#include <SDL_timer.h>
#include "GameLoop.h"
#include "../servicios/Locator.h"
#include <unistd.h>

GameLoop::GameLoop(EventosAProcesar *eventos, EventoAProcesar *eventoAProcesar, ManagerUsuarios *managerUsuarios) :
        eventos(eventos),
        eventoAProcesar(eventoAProcesar),
        managerUsuarios(managerUsuarios) {}

void GameLoop::loop() {
    const size_t MS_PER_FRAME = 1.0 / Locator::configuracion()->getIntValue("/fps") * 1000 * 1000; // Microsegundos.

    while (managerUsuarios->hayJugadoresConectados()) {
        eventos->push(eventoAProcesar);
        usleep(MS_PER_FRAME);
    }
    Locator::logger()->log(INFO, "Todos los usuarios se desconectaron voluntariamente.");
}

pthread_t GameLoop::loopEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *conexiones = (GameLoop *) arg;
        conexiones->loop();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de loop del juego.");
    return hilo;

}
