//
// Created by sebas on 21/9/19.
//

#include "Entidad.h"
#include "Posicion.h"
#include "Orientacion.h"
#include "Personaje.h"
#include "Nivel.h"
#include "EstadoDePersonaje.h"
#include "Opacidad.h"
#include "TipoElemento.h"
#include "Actividad.h"
#include "NumeroJugador.h"
#include "IndiceSprite.h"
#include <algorithm>
#include <iostream>


vector<Comportamiento *> Entidad::getComportamientos() {
    vector<Comportamiento *> values(comportamientos.size());
    auto value_selector = [](auto pair) { return pair.second; };
    transform(comportamientos.begin(), comportamientos.end(), values.begin(), value_selector);
    return values;
}

vector<Estado *> Entidad::getEstados() {
    vector<Estado *> values(estados.size());
    auto value_selector = [](auto pair) { return pair.second; };
    transform(estados.begin(), estados.end(), values.begin(), value_selector);
    return values;
}

void Entidad::serializar(ostream &stream) {
    getEstado<Tipo>("tipo")->serializar(stream);
    for (size_t i = 0; i < estadosSerializables.size(); i++) {
        string estado = estadosSerializables.at(i);
        if (!(estados.find(estado) == estados.end())) {
            serializarEntero(stream, i);
            estados[estado]->serializar(stream);
        }
    }
    serializarEntero(stream, fin);
}

void Entidad::deserializar(istream &stream) {
    auto *tipo = new Tipo();
    tipo->deserializar(stream);
    agregarEstado("tipo", tipo);

    int posicionEstado = deserializarEntero(stream);
    while (posicionEstado != fin) {
        string estado = estadosSerializables.at(posicionEstado);
        bool existe = contieneEstado(estado);
        if (estado == "posicion") {
            if (existe) {
                getEstado<Posicion>("posicion")->deserializar(stream);
            } else {
                auto *posicion = new Posicion();
                posicion->deserializar(stream);
                agregarEstado("posicion", posicion);
            }
        } else if (estado == "orientacion") {
            if (existe) {
                getEstado<Orientacion>("orientacion")->deserializar(stream);
            } else {
                auto *orientacion = new Orientacion();
                orientacion->deserializar(stream);
                agregarEstado("orientacion", orientacion);
            }
        } else if (estado == "nivel") {
            if (existe) {
                getEstado<Nivel>("nivel")->deserializar(stream);
            } else {
                auto *nivel = new Nivel();
                nivel->deserializar(stream);
                agregarEstado("nivel", nivel);
            }
        } else if (estado == "estado de personaje") {
            if (existe) {
                getEstado<EstadoDePersonaje>("estado de personaje")->deserializar(stream);
            } else {
                auto *estadoDePersonaje = new EstadoDePersonaje();
                estadoDePersonaje->deserializar(stream);
                agregarEstado("estado de personaje", estadoDePersonaje);
            }
        } else if (estado == "personaje") {
            if (existe) {
                getEstado<Personaje>("personaje")->deserializar(stream);
            } else {
                auto *personaje = new Personaje();
                personaje->deserializar(stream);
                agregarEstado("personaje", personaje);
            }
        } else if (estado == "opacidad") {
            if (existe) {
                getEstado<Opacidad>("opacidad")->deserializar(stream);
            } else {
                auto *opacidad = new Opacidad();
                opacidad->deserializar(stream);
                agregarEstado("opacidad", opacidad);
            }
        } else if (estado == "tipo elemento") {
            if (existe) {
                getEstado<TipoElemento>("tipo elemento")->deserializar(stream);
            } else {
                auto *tipoElemento = new TipoElemento();
                tipoElemento->deserializar(stream);
                agregarEstado("tipo elemento", tipoElemento);
            }
        } else if (estado == "actividad") {
            if (existe) {
                getEstado<Actividad>("actividad")->deserializar(stream);
            } else {
                auto *actividad = new Actividad();
                actividad->deserializar(stream);
                agregarEstado("actividad", actividad);
            }
        } else if (estado == "numeroJugador") {
            if (existe) {
                getEstado<NumeroJugador>("numeroJugador")->deserializar(stream);
            } else {
                auto *numeroJugador = new NumeroJugador();
                numeroJugador->deserializar(stream);
                agregarEstado("numeroJugador", numeroJugador);
            }
        } else if (estado == "indice sprite") {
            if (existe) {
                getEstado<IndiceSprite>("indice sprite")->deserializar(stream);
            } else {
                auto *indiceSprite = new IndiceSprite();
                indiceSprite->deserializar(stream);
                agregarEstado("indice sprite", indiceSprite);
            }
        }
        posicionEstado = deserializarEntero(stream);
    }
}

void Entidad::putIdInStream(ostream &in, IdEntidad idEntidad) {
    serializarEntero(in, idEntidad);
}

IdEntidad Entidad::getIdFromStream(istream &stream) {
    return deserializarEntero(stream);
}

Tipo::Tipo(TIPO tipo) : tipo_(tipo) {}

TIPO Tipo::tipo() {
    return tipo_;
}

void Tipo::serializar(ostream &stream) {
    serializarEntero(stream, tipo_);
}

void Tipo::deserializar(istream &stream) {
    tipo_ = static_cast<TIPO>(deserializarEntero(stream));
}

Tipo::Tipo() : tipo_(PANTALLA_SELECCION) {}

bool Tipo::operator==(const Tipo &otroTipo) {
    return tipo_ == otroTipo.tipo_;
}
