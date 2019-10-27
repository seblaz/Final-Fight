//
// Created by sebas on 13/10/19.
//

#include "SelectorPersonajes.h"

SelectorPersonajes::SelectorPersonajes(int jugadores) :
        jugadoresMax(jugadores){}

void SelectorPersonajes::confirmar(Usuario *usuario) {
    unique_lock<mutex> lock(m_mutex);
    usuarios[usuario->getUsuario()] = usuario;
}

bool SelectorPersonajes::puedoComenzar() {
    unique_lock<mutex> lock(m_mutex);
    return jugadoresMax == usuarios.size();
}

void SelectorPersonajes::quitar(Usuario *usuario) {
    unique_lock<mutex> lock(m_mutex);
    if(!(usuarios.find(usuario->getUsuario()) == usuarios.end())){
        usuarios.erase(usuario->getUsuario());
    }
}
