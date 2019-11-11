//
// Created by franco on 31/10/19.
//

#include "Colisionables.h"
#include "envolventes/EnvolventeVolumen.h"
#include "../estados/EstadoDePersonajeServidor.h"
#include "envolventes/EnvolventeAtaque.h"
#include <utility>


void Colisionables::calcularPosiblesColisiones() {

    for (auto *entidadCentral : colisionables) {
        auto *envolvente = entidadCentral->getEstado<EnvolventeVolumen>("envolvente");
        auto *posicion = entidadCentral->getEstado<Posicion>("posicion");
        auto *velocidad = entidadCentral->getEstado<Velocidad>("velocidad");
        for (auto *entidad_colisionable : colisionables) {

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

void Colisionables::add(Entidad *entidad) {
    colisionables.insert(colisionables.begin(), entidad);

    auto *tipo = entidad->getEstado<Tipo>("tipo");
    if (tipo->tipo() == ENEMIGO) {
        enemigos.insert(enemigos.begin(), entidad);
    } else if (tipo->tipo() == JUGADOR) {
        jugadores.insert(jugadores.begin(), entidad);
    }
}

void Colisionables::addLimitesDeEscenario(int profundidad, int frente) {
    this->limiteEnProfundidad = profundidad;
    this->limiteFrontal = frente;
}

void Colisionables::calcularAtaques() {
    for (auto *jugador : jugadores) {
        auto *estado = jugador->getEstado<EstadoDePersonaje>("estado de personaje");

        if (estado->getEstado() == DANDO_GOLPE || estado->getEstado() == PATEANDO) {
            Locator::logger()->log(DEBUG, "Busco golpes");

            auto *envolventeAtaque = jugador->getEstado<EnvolventeAtaque>("envolvente ataque");
            for (auto *enemigo : enemigos) {
                auto *envolvente_enemigo = enemigo->getEstado<EnvolventeVolumen>("envolvente");

                if (envolventeAtaque->colisionaCon(envolvente_enemigo)) {
                    Locator::logger()->log(DEBUG, "golpeado!");
                    enemigo->getComportamiento<EstadoDePersonajeServidor>("estado")->recibirGolpe();
                }
            }
        }
    }
}

