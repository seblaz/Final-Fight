//
// Created by sebas on 21/9/19.
//

#include "Entidad.h"
#include "Posicion.h"
#include <algorithm>

IdEntidad Entidad::ultimoId = 0;

Entidad::Entidad() {
    idEntidad = ultimoId++;
}

IdEntidad Entidad::getId() {
    return idEntidad;
}

vector<Comportamiento *> Entidad::getComportamientos() {
    vector<Comportamiento *> values(comportamientos.size());
    auto value_selector = [](auto pair){return pair.second;};
    transform(comportamientos.begin(), comportamientos.end(), values.begin(), value_selector);
    return values;
}

vector<Estado *> Entidad::getEstados() {
    vector<Estado *> values(estados.size());
    auto value_selector = [](auto pair){return pair.second;};
    transform(estados.begin(), estados.end(), values.begin(), value_selector);
    return values;
}

void Entidad::serializar(ostream &stream) {
    serializarEntero(stream, idEntidad);
    getEstado<Tipo>("tipo")->serializar(stream);

    for (Estado * estado : getEstados()){
        if(find(estadosSerializables.begin(), estadosSerializables.end(), estado) != estadosSerializables.end()){
            estado->serializar(stream);
        }
    }
}

void Entidad::deserializar(istream &stream) {
    idEntidad = deserializarEntero(stream);
    auto * tipo = new Tipo();
    tipo->deserializar(stream);
    agregarEstado("tipo", tipo);

    switch (tipo->tipo()){
        case PANTALLA_SELECCION:
            auto* posicion = new Posicion();
            posicion->deserializar(stream);
            agregarEstado("posicion", posicion);
            break;
    }
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

Tipo::Tipo() : tipo_(PANTALLA_SELECCION){}

bool Tipo::operator==(const Tipo &otroTipo) {
    return tipo_ == otroTipo.tipo_;
}
