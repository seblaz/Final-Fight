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

Entrada::Entrada(int socket) : socket(socket){}

void Entrada::procesarEntrada() {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    string msg;
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
        send(socket, msg.c_str(), msg.length(), 0);
        SDL_Delay(1000);
    }
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