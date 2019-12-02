//
// Created by sebas on 2/11/19.
//

#include "FabricaDeAnimacionesCliente.h"
#include "../servicios/Locator.h"

#include <utility>

FabricaDeAnimacionesCliente::FabricaDeAnimacionesCliente(string rutaBase) : rutaBase(std::move(rutaBase)) {}

AnimacionCliente *FabricaDeAnimacionesCliente::getAnimacion(const string &rutaFinal) {
    if (animaciones.find(rutaFinal) == animaciones.end()) {

        auto *posiciones = new vector<SDL_Rect>;
        Configuracion *config = Locator::configuracion();
        int cantidad = config->getIntValue(rutaBase + rutaFinal + "/cantidad");
        for (int i = 0; i < cantidad; i++) {
            string rutaAux = rutaBase + rutaFinal + "/posiciones/posicion" + to_string(i);
            SDL_Rect posicion;
            posicion.x = config->getIntValue(rutaAux + "/x");
            posicion.y = config->getIntValue(rutaAux + "/y");
            posicion.w = config->getIntValue(rutaAux + "/w");
            posicion.h = config->getIntValue(rutaAux + "/h");
            posiciones->push_back(posicion);
        }

        float escala = config->getFloatValue(rutaBase + rutaFinal + "/escala");
        animaciones[rutaFinal] = make_tuple(posiciones, escala);
    }

    return new AnimacionCliente(get<0>(animaciones[rutaFinal]), get<1>(animaciones[rutaFinal]));
}

AnimacionCliente *FabricaDeAnimacionesCliente::getAnimacion(ESTADO_DE_PERSONAJE estado) {
    return getAnimacion("/" + EstadoDePersonaje::estadoACadena(estado));
}
