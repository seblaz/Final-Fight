//
// Created by sebas on 6/10/19.
//

#include "MostrarMenuSeleccion.h"

MostrarMenuSeleccion::MostrarMenuSeleccion(Mapa *mapa) : mapa(mapa) {}

void MostrarMenuSeleccion::resolver() {
    NivelServidor::generarMenuSeleccion(mapa);
   // NivelServidor::generarPersonajesSeleccion(mapa);
}
