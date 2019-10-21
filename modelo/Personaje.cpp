//
// Created by sebas on 8/10/19.
//

#include "Personaje.h"

Personaje::Personaje() : personaje(CODY){}

Personaje::Personaje(enum PERSONAJE personaje) : personaje(personaje){}

enum PERSONAJE Personaje::getPersonaje() {
    return personaje;
}

void Personaje::setPersonaje(enum PERSONAJE personaje_) {
    personaje = personaje_;
}

void Personaje::serializar(ostream &stream) {
    serializarEntero(stream, personaje);
}

void Personaje::deserializar(istream &stream) {
    personaje = static_cast<enum PERSONAJE>(deserializarEntero(stream));
}

string Personaje::PersonajeACadena(enum PERSONAJE personaje) {
    switch(personaje){
        case CODY:
            return "cody";
        case HAGGAR:
            return "haggar";
        case GUY:
            return "guy";
        case MAKI:
            return "maki";
    }
}
