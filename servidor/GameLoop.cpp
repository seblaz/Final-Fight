//
// Created by sebas on 7/10/19.
//

#include <SDL_timer.h>
#include "GameLoop.h"
#include "../servicios/Locator.h"
#include <unistd.h>

GameLoop::GameLoop(EventosAProcesar *eventos, EventoAProcesar *eventoAProcesar) :
        eventos(eventos),
        eventoAProcesar(eventoAProcesar) {}

void GameLoop::loop() {
    const size_t MS_PER_FRAME = 1.0 / Locator::configuracion()->getIntValue("/fps") * 1000 * 1000; // Microsegundos.

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
//        size_t start = SDL_GetTicks();
//
//        size_t end = SDL_GetTicks();
//        int sleepTime = MS_PER_FRAME + start - end;
        eventos->push(eventoAProcesar);
//        if (sleepTime > 0) {
//            SDL_Delay(sleepTime);
//        }
//        SDL_Delay(MS_PER_FRAME);
        usleep(MS_PER_FRAME);
    }
#pragma clang diagnostic pop

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
