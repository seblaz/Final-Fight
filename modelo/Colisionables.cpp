//
// Created by franco on 31/10/19.
//

#include "Colisionables.h"
#include "envolventes/EnvolventeVolumen.h"
#include "../estados/EstadoDePersonajeServidor.h"
#include "envolventes/EnvolventeAtaque.h"
#include "serializables/Energia.h"
#include "serializables/Puntaje.h"
#include "serializables/Arma.h"
#include "serializables/Elemento.h"
#include <utility>


void Colisionables::calcularPosiblesColisiones() {

    auto* mapa = Locator::mapa();
    for (auto *entidadCentral : mapa->getColisionables()) {
        auto *envolvente = entidadCentral->getEstado<EnvolventeVolumen>("envolvente");
        auto *posicion = entidadCentral->getEstado<Posicion>("posicion");
        auto *velocidad = entidadCentral->getEstado<Velocidad>("velocidad");
        for (auto *entidad_colisionable : mapa->getColisionables()) {

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

                if (envolventeAtaque->colisionaCon(envolvente_enemigo)) {
                    Locator::logger()->log(DEBUG, "golpeado!");

                    auto arma = jugador->getEstado<Arma>("arma");
                    auto energiaEnemigo = enemigo->getEstado<Energia>("energia");
                    auto puntajeJugador = jugador->getEstado<Puntaje>("puntaje");

                    int puntosDeDanio =  estado->getEstado() == PATEANDO ? 75 : arma->getPuntosDeDanio();
                    int puntosParaJugador = estado->getEstado() == PATEANDO ? 400 : arma->getPuntosParaPersonaje();

                    energiaEnemigo->restarEnergia(puntosDeDanio);
                    puntajeJugador->agregarPuntos(puntosParaJugador);
                    arma->usar();

                    enemigo->getComportamiento<EstadoDePersonajeServidor>("estado")->recibirGolpe();

                    if(!energiaEnemigo->personajeVive()){
                        puntajeJugador->agregarPuntos(500);
                    }
                }
            }
        }
    }
}

void Colisionables::calcularAtaquesAelementos() {
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
                    elemento->getEstado<Elemento>("elemento")->golpear();
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
//                auto *arma_eliminada = arma->getEstado<GolpesSoportables>("eliminado");

                if (envolvente->colisionaCon(envolvente_arma)) {
                    Locator::logger()->log(DEBUG, "toma el arma!");
                    arma->getEstado<Arma>("arma")->tomar();
                }
            }
        }
    }
}

