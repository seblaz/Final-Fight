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
#include "Energia.h"
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

template<typename T>
Estado *createInstance() { return new T; }

typedef map<string, Estado *(*)()> estadosMapType;
estadosMapType mapaEstados = {
        {"posicion",    &createInstance<Posicion>},
        {"orientacion", &createInstance<Orientacion>},
        {"nivel", &createInstance<Nivel>},
        {"estado de personaje", &createInstance<EstadoDePersonaje>},
        {"personaje", &createInstance<Personaje>},
        {"opacidad", &createInstance<Opacidad>},
        {"tipo elemento", &createInstance<TipoElemento>},
        {"actividad", &createInstance<Actividad>},
        {"numeroJugador", &createInstance<NumeroJugador>},
        {"indice sprite", &createInstance<IndiceSprite>},
        {"energia", &createInstance<Energia>},
};

void Entidad::deserializar(istream &stream) {
    auto *tipo = new Tipo();
    tipo->deserializar(stream);
    agregarEstado("tipo", tipo);

    int posicionEstado = deserializarEntero(stream);
    while (posicionEstado != fin) {
        string estado = estadosSerializables.at(posicionEstado);
        bool existe = contieneEstado(estado);
        if(existe){
            getEstado<Estado>(estado)->deserializar(stream);
        } else {
            auto *estadoObjeto = mapaEstados[estado]();
            estadoObjeto->deserializar(stream);
            agregarEstado(estado, estadoObjeto);
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
