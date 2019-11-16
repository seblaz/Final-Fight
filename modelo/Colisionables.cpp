//
// Created by franco on 31/10/19.
//

#include "Colisionables.h"
#include "envolventes/EnvolventeVolumen.h"
#include "../estados/personajes/EstadoDePersonajeServidor.h"
#include "../estados/elementos/EstadoDeElemento.h"
#include "envolventes/EnvolventeAtaque.h"
#include "serializables/Arma.h"

void Colisionables::calcularInteracciones() {
    auto *mapa = Locator::mapa();
    calcularPosiblesColisiones();
    calcularArmasAlcanzables();

    calcularAtaquesEntre(mapa->getPersonajes(), mapa->getElementos()); // Romper elementos.
    calcularAtaquesEntre(mapa->getPersonajes(), mapa->getEnemigos()); // Jugadores atacan enemigos.
    calcularAtaquesEntre(mapa->getEnemigos(), mapa->getPersonajes()); // Enemigos atacan jugadores.
}

void Colisionables::calcularPosiblesColisiones() {

    auto *mapa = Locator::mapa();
    for (auto itEntidadCentral = mapa->getColisionables().begin();
         itEntidadCentral != mapa->getColisionables().end(); itEntidadCentral++) {
        auto *entidadCentral = *itEntidadCentral;

        auto *envolvente = entidadCentral->getEstado<EnvolventeVolumen>("envolvente");
        auto *posicion = entidadCentral->getEstado<Posicion>("posicion");
        auto *velocidad = entidadCentral->getEstado<Velocidad>("velocidad");

        for (auto itEntidad_colisionable = itEntidadCentral + 1;
             itEntidad_colisionable != mapa->getColisionables().end(); itEntidad_colisionable++) {

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

void Colisionables::calcularArmasAlcanzables() {
    auto *mapa = Locator::mapa();
    for (auto *jugador : mapa->getPersonajes()) {
        auto *estado = jugador->getEstado<EstadoDePersonaje>("estado de personaje");

        if (estado->getEstado() == AGACHADO) {
            auto *envolvente = jugador->getEstado<EnvolventeVolumen>("envolvente");
            for (auto *arma : mapa->getArmas()) {
                auto *envolvente_arma = arma->getEstado<EnvolventeVolumen>("envolvente");

                if (envolvente->colisionaCon(envolvente_arma)) {
                    auto *armaSuelo = arma->getEstado<Arma>("arma");
                    auto *armaJugador = jugador->getEstado<Arma>("arma");
                    if (armaJugador->getArma() == ARMA::PUNIOS) {
                        armaSuelo->tomar();
                        Locator::mapa()->quitarArma(arma);
                        armaJugador->cambiarPor(armaSuelo->getArma());
                    }
                }
            }
        }
    }
}

void Colisionables::calcularAtaquesEntre(vector<Entidad *> &atacantes, vector<Entidad *> &defensores) {
    for (auto *atacante : atacantes) {
        auto *estado = atacante->getEstado<EstadoDePersonaje>("estado de personaje");

        if (estado->getEstado() == DANDO_GOLPE || estado->getEstado() == PATEANDO) {

            auto *envolventeAtaque = atacante->getEstado<EnvolventeAtaque>("envolvente ataque");
            for (auto *defensor : defensores) {
                auto *envolvente_defensor = defensor->getEstado<EnvolventeVolumen>("envolvente");

                if (envolventeAtaque->colisionaCon(envolvente_defensor, atacante->getEstado<Arma>("arma"))) {
                    Locator::logger()->log(DEBUG, "golpeado!");

                    defensor->getComportamiento<EstadoDeColisionable>("estado")->recibirGolpeDe(atacante);
                }
            }
        }
    }
}
