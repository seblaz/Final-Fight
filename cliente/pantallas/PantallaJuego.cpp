//
// Created by sebas on 6/11/19.
//

#include "PantallaJuego.h"

void PantallaJuego::recibir(stringstream &s) {
    receptor.devolverStreamMasReciente(s);
}

void PantallaJuego::iniciar() {
    receptor.recibirEnHilo();
}
