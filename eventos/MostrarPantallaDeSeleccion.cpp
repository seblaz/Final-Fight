//
// Created by sebas on 6/10/19.
//

#include "MostrarPantallaDeSeleccion.h"

void MostrarPantallaDeSeleccion::resolver() {
    NivelServidor::generarMenuSeleccion(mapa);
}

MostrarPantallaDeSeleccion::MostrarPantallaDeSeleccion(Mapa *mapa) : mapa(mapa) {}
