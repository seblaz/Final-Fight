//
// Created by franco on 13/10/19.
//

#include "Elemento.h"
#include "Puntaje.h"

Elemento::Elemento() :
        golpes(0),
        elemento(static_cast<ELEMENTO>(0)) {}

Elemento::Elemento(ELEMENTO elemento, int golpes, int puntosParaJugadorPorRomper) :
        golpes(golpes),
        elemento(elemento),
        puntosParaJugadorPorRomper(puntosParaJugadorPorRomper) {}

ELEMENTO Elemento::getElemento() {
    return elemento;
}

void Elemento::recibirGolpeDe(Entidad* golpeador) {
    golpes--;
    if(golpes == 0){
        golpeador->getEstado<Puntaje>("puntaje")->agregarPuntos(this->puntosParaJugadorPorRomper);
    }
}

bool Elemento::estaRoto() {
    return golpes < 1;
}

void Elemento::serializar(ostream &stream) {
    serializarEntero(stream, static_cast<int>(elemento));
    serializarEntero(stream, golpes);
}

void Elemento::deserializar(istream &stream) {
    elemento = static_cast<ELEMENTO>(deserializarEntero(stream));
    golpes = Serializable::deserializarEntero(stream);
}

string Elemento::ElementoACadena(ELEMENTO elemento) {
    switch (elemento){
        case ELEMENTO::CAJA:
            return "caja";
        case ELEMENTO::BARRIL:
            return "barril";
    };
}
