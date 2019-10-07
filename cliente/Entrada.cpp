//
// Created by sebas on 5/10/19.
//

#include <SDL_quit.h>
#include <SDL_system.h>
#include <sys/socket.h>
#include <pthread.h>
#include <string>
#include <SDL_timer.h>
#include "Entrada.h"
#include "../eventos/data.h"

Entrada::Entrada(int socket) : socket(socket){}

void Entrada::procesarEntrada() {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    string msg;
    miData var = {1, 2};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true){
        if (entrada[SDL_SCANCODE_A])  {
            msg = "Golpear";
        } else if (entrada[SDL_SCANCODE_S]) {
            msg = "Saltar";
        } else if (entrada[SDL_SCANCODE_D]) {
            msg = "Agachar";
        } else {
            msg = "Reposar";
        }
        send(socket, &var, sizeof(var), 0);
        SDL_Delay(1000);
    }
#pragma clang diagnostic pop
}

pthread_t Entrada::procesarEntradaEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void* arg)->void *{
            auto *conexiones = (Entrada *)arg;
            conexiones->procesarEntrada();
            return nullptr;
        }, (void *) this);
    return hilo;
}