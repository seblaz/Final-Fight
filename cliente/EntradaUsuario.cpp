//
// Created by sebas on 9/10/19.
//

#include <SDL_quit.h>
#include <SDL_system.h>
#include "EntradaUsuario.h"
#include "../servicios/Locator.h"
#include <unistd.h>
#include <sys/socket.h>
#include <SDL_timer.h>

Accion *EntradaNula::getAccion() {
    return nullptr;
}

Accion *EntradaMenuSeleccion::getAccion() {
    if (activo) {
        const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
        if (entrada[SDL_SCANCODE_RETURN]) {
            activo = false;
            return new Accion(CONFIRMAR);
        } else if (entrada[SDL_SCANCODE_LEFT]) {
            return new Accion(SELECCIONAR_ANTERIOR);
        } else if (entrada[SDL_SCANCODE_RIGHT]) {
            return new Accion(SELECCIONAR_SIGUIENTE);
        }
    }
    return nullptr;
}

Accion *EntradaJuego::getAccion() {
    // TODO: completar con acciones de usuario.
    return nullptr;
}

TrasmisionCliente::TrasmisionCliente(Socket socket, EntradaUsuario *entradaUsuario) :
        entradaUsuario(entradaUsuario),
        socket(socket) {}

EntradaUsuario *TrasmisionCliente::getEntradaUsuario() {
    std::lock_guard<std::mutex> lock(m);
    return entradaUsuario;
}

void TrasmisionCliente::setEntradaUsuario(EntradaUsuario *entradaUsuario_) {
    std::lock_guard<std::mutex> lock(m);
    entradaUsuario = entradaUsuario_;
}

void TrasmisionCliente::transmitir() {

    const size_t MS_PER_FRAME = 1.0 / Locator::configuracion()->getIntValue("/fps") * 1000; // Milisegundos.

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        size_t start = SDL_GetTicks();

        Accion *accion = getEntradaUsuario()->getAccion();
        if (accion) {
            stringstream s;
            accion->serializar(s);
            socket.enviar(s);
        }

        size_t end = SDL_GetTicks();
        int sleepTime = MS_PER_FRAME + start - end;
        if (sleepTime > 0) {
            SDL_Delay(sleepTime);
        }
    }
#pragma clang diagnostic pop
}

pthread_t TrasmisionCliente::transmitirEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *transmision = (TrasmisionCliente *) arg;
        transmision->transmitir();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de transmisión.");
    return hilo;
}
