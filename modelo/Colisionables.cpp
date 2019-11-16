//
// Created by franco on 31/10/19.
//

#include "Colisionables.h"
#include "envolventes/EnvolventeVolumen.h"
#include "../estados/EstadoDePersonajeServidor.h"
#include "envolventes/EnvolventeAtaque.h"
#include "serializables/Arma.h"
#include "serializables/Elemento.h"
#include "../servidor/notificadores/NotificadorDeGolpesJugador.h"
#include <utility>

void Colisionables::calcularInteracciones() {
    calcularPosiblesColisiones();
    calcularAtaquesDeJugadoresAEnemigos();
    calcularAtaquesAElementos();
    calcularArmasAlcanzables();
    calcularAtaquesDeEnemigosAJugadores();
}

void Colisionables::calcularPosiblesColisiones() {

    auto* mapa = Locator::mapa();
    for(auto itEntidadCentral = mapa->getColisionables().begin(); itEntidadCentral!=mapa->getColisionables().end(); itEntidadCentral++){
    auto* entidadCentral = *itEntidadCentral;
//    for (auto *entidadCentral : mapa->getColisionables()) {
        auto *envolvente = entidadCentral->getEstado<EnvolventeVolumen>("envolvente");
        auto *posicion = entidadCentral->getEstado<Posicion>("posicion");
        auto *velocidad = entidadCentral->getEstado<Velocidad>("velocidad");

        for(auto itEntidad_colisionable = itEntidadCentral + 1; itEntidad_colisionable!=mapa->getColisionables().end(); itEntidad_colisionable++){
//        for (auto *entidad_colisionable : mapa->getColisionables()) {
            auto *entidad_colisionable = *itEntidad_colisionable;
            auto *envolventeContrario = entidad_colisionable->getEstado<EnvolventeVolumen>("envolvente");
            auto *posicionContrario = entidad_colisionable->getEstado<Posicion>("posicion");
            if (entidad_colisionable != entidadCentral) {

                auto *velocidadContrario = entidad_colisionable->getEstado<Velocidad>("velocidad");

                if (velocidadContrario->y == 0 && velocidad->y != 0) {
                    if (envolvente->colisionaAbajoCon(envolventeContrario)) {
                        posicion->y = envolventeContrario->posicion->y + envolventeContrario->profundidad +
                                      envolvente->profundidad;
                    } else if (envolvente->colisionaArribaCon(envolventeContrario)) {
                        posicion->y = envolventeContrario->posicion->y - envolventeContrario->profundidad -
                                      envolvente->profundidad;
                    }
                } else if (velocidadContrario->y != 0 && velocidad->y != 0) {
                    if (envolvente->colisionaAbajoCon(envolventeContrario) ||
                        envolvente->colisionaArribaCon(envolventeContrario)) {
                        posicion->y -= int(velocidad->y);
                        posicionContrario->y -= int(velocidadContrario->y);
                    }
                }
                if (velocidadContrario->x == 0 && velocidad->x != 0) {
                    if (envolvente->colisionaPorIzquierdaCon(envolventeContrario)) {
                        posicion->x = envolventeContrario->posicion->x - envolventeContrario->ancho - envolvente->ancho;
                    } else if (envolvente->colisionaPorDerechaCon(envolventeContrario)) {
                        posicion->x = envolventeContrario->posicion->x + envolventeContrario->ancho + envolvente->ancho;
                    }
                } else if (velocidadContrario->x != 0 && velocidad->x != 0) {
                    if (envolvente->colisionaPorIzquierdaCon(envolventeContrario) ||
                        envolvente->colisionaPorDerechaCon(envolventeContrario)) {
                        posicion->x -= int(velocidad->x);
                        posicionContrario->x -= int(velocidadContrario->x);
                    }
                }
            }
        }

        if (posicion->y >= limiteEnProfundidad) {
            posicion->y = limiteEnProfundidad - 1;
        } else if (posicion->y <= limiteFrontal) {
            posicion->y = limiteFrontal;
        }
    }
}

void Colisionables::addLimitesDeEscenario(int profundidad, int frente) {
    this->limiteEnProfundidad = profundidad;
    this->limiteFrontal = frente;
}

void Colisionables::calcularAtaquesDeJugadoresAEnemigos() {
    auto* mapa = Locator::mapa();
    for (auto *jugador : mapa->getPersonajes()) {
        auto *estado = jugador->getEstado<EstadoDePersonaje>("estado de personaje");

        if (estado->getEstado() == DANDO_GOLPE || estado->getEstado() == PATEANDO) {
            Locator::logger()->log(DEBUG, "Busco golpes");

            auto *envolventeAtaque = jugador->getEstado<EnvolventeAtaque>("envolvente ataque");
            for (auto *enemigo : mapa->getEnemigos()) {
                auto *envolvente_enemigo = enemigo->getEstado<EnvolventeVolumen>("envolvente");
                auto *estadoEnemigo = enemigo->getEstado<EstadoDePersonaje>("estado de personaje");

                if (envolventeAtaque->colisionaCon(envolvente_enemigo) && estadoEnemigo->getEstado() != MUERTO) {
                    Locator::logger()->log(DEBUG, "golpeado!");

                    enemigo->getComportamiento<EstadoDePersonajeServidor>("estado")->recibirGolpeDe(jugador);
                }
            }
        }
    }
}

void Colisionables::calcularAtaquesAElementos() {
    auto* mapa = Locator::mapa();
    for (auto *jugador : mapa->getPersonajes()) {
        auto *estado = jugador->getEstado<EstadoDePersonaje>("estado de personaje");

        if (estado->getEstado() == DANDO_GOLPE || estado->getEstado() == PATEANDO) {
            Locator::logger()->log(DEBUG, "Busco golpes");

            auto *envolventeAtaque = jugador->getEstado<EnvolventeAtaque>("envolvente ataque");
            for (auto *elemento : mapa->getElementos()) {
                auto *envolvente_elemento = elemento->getEstado<EnvolventeVolumen>("envolvente");

                if (envolventeAtaque->colisionaCon(envolvente_elemento)) {
                    Locator::logger()->log(DEBUG, "golpeado!");
                    elemento->getEstado<Elemento>("elemento")->recibirGolpeDe(jugador);
                }
            }
        }
    }
}

void Colisionables::calcularArmasAlcanzables() {
    auto* mapa = Locator::mapa();
    for (auto *jugador : mapa->getPersonajes()) {
        auto *estado = jugador->getEstado<EstadoDePersonaje>("estado de personaje");

        if (estado->getEstado() == AGACHADO ) {
            Locator::logger()->log(DEBUG, "Busco armas en el suelo");

            auto *envolvente = jugador->getEstado<EnvolventeVolumen>("envolvente");
            for (auto *arma : mapa->getArmas()) {
                auto *envolvente_arma = arma->getEstado<EnvolventeVolumen>("envolvente");

                if (envolvente->colisionaCon(envolvente_arma)) {
                    Locator::logger()->log(DEBUG, "toma el arma!");
                    if(jugador->getEstado<Arma>("arma")->getArma() == ARMA::PUNIOS){
                        auto armaEstado = arma->getEstado<Arma>("arma");
                        armaEstado->tomar();
                        jugador->agregarEstado("arma", new Arma(armaEstado->getArma()));
                    }
                }
            }
        }
    }
}

void Colisionables::calcularAtaquesDeEnemigosAJugadores() {
    auto* mapa = Locator::mapa();
    for (auto *enemigo : mapa->getEnemigos()) {
        auto *estado = enemigo->getEstado<EstadoDePersonaje>("estado de personaje");

        if (estado->getEstado() == DANDO_GOLPE || estado->getEstado() == PATEANDO) {
            Locator::logger()->log(DEBUG, "Busco golpes");

            auto *envolventeAtaque = enemigo->getEstado<EnvolventeAtaque>("envolvente ataque");
            for (auto *jugador : mapa->getPersonajes()) {
                auto *envolvente_jugador = jugador->getEstado<EnvolventeVolumen>("envolvente");
                auto *estadoJugador = jugador->getEstado<EstadoDePersonaje>("estado de personaje");

                if (envolventeAtaque->colisionaCon(envolvente_jugador) && estadoJugador->getEstado() != MUERTO) {
                    Locator::logger()->log(DEBUG, "golpeado!");

                    jugador->getComportamiento<EstadoDePersonajeServidor>("estado")->recibirGolpeDe(enemigo);
                }
            }
        }
    }
}
