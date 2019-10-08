//
// Created by sebas on 8/10/19.
//

#include <SDL_quit.h>
#include <SDL_system.h>
#include <sys/socket.h>
#include "EntradaPantallaDeSeleccionNuevo.h"
#include "../servicios/Locator.h"
#include "../modelo/Accion.h"

void EntradaPantallaDeSeleccionNuevo::actualizar(Entidad *entidad) {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    if (entrada[SDL_SCANCODE_RETURN]) {
        Locator::logger()->log(DEBUG, "Se selecciona a cody.");
        Accion accion(SELECCIONAR_CODY);
        stringstream s;
        accion.serializar(s);        
        string msg = s.str();
        int result = send(Locator::socket(), msg.c_str(), msg.length(), 0);
        if (result == -1) {
            Locator::logger()->log(ERROR, "Error al transmitir.");
        } else if (result == 0) {
            Locator::logger()->log(INFO, "Cliente desconectado.");
        } else {
            Locator::logger()->log(DEBUG, "Transmisión correcta de: " + msg);
        }
    }
}
