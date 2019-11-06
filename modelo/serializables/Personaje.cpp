//
// Created by sebas on 8/10/19.
//

#include "Personaje.h"

Personaje::Personaje() : personaje(PERSONAJE::CODY){}

Personaje::Personaje(enum PERSONAJE personaje) : personaje(personaje){}

enum PERSONAJE Personaje::getPersonaje() {
    return personaje;
}

void Personaje::setPersonaje(enum PERSONAJE personaje_) {
    personaje = personaje_;
}

void Personaje::serializar(ostream &stream) {
    serializarEntero(stream, static_cast<int>(personaje));
}

void Personaje::deserializar(istream &stream) {
    personaje = static_cast<enum PERSONAJE>(deserializarEntero(stream));
}

string Personaje::PersonajeACadena(enum PERSONAJE personaje) {
    switch(personaje){
        case PERSONAJE::CODY:
            return "cody";
        case PERSONAJE::HAGGAR:
            return "haggar";
        case PERSONAJE::GUY:
            return "guy";
        case PERSONAJE::MAKI:
            return "maki";
        case PERSONAJE::POISSON:
            return "poisson";
    }
}
