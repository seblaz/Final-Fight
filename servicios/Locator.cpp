//
// Created by sebas on 8/9/19.
//

#include "Locator.h"

/**
 * Logger.
 */
Logger *Locator::logger_;

Logger *Locator::logger() {
    return logger_;
}

void Locator::provide(Logger *logger) {
    logger_ = logger;
}

/**
 * Configuracion.
 */
Configuracion *Locator::configuracion_;

Configuracion *Locator::configuracion() {
    return configuracion_;
}

void Locator::provide(Configuracion *configuracion) {
    configuracion_ = configuracion;
}

/**
 * Renderer.
 */
SDL_Renderer *Locator::renderer_;

SDL_Renderer *Locator::renderer() {
    return renderer_;
}

void Locator::provide(SDL_Renderer *renderer) {
    renderer_ = renderer;
}

/**
 * Socket.
 */
Socket *Locator::socket_;

Socket *Locator::socket() {
    return socket_;
}

void Locator::provide(Socket *socket) {
    socket_ = socket;
}


/**
 * Posicion.
 */
Posicion *Locator::posicion;

Posicion *Locator::posicionEscenario() {
    return posicion;
}

void Locator::provide(Posicion *posicion_) {
    posicion = posicion_;
}

/**
 * Fabrica de sprites.
 */
FabricaDeSprites *Locator::fabrica;

FabricaDeSprites *Locator::fabricaDeSprites() {
    return fabrica;
}

void Locator::provide(FabricaDeSprites *fabricaDeSprites) {
    fabrica = fabricaDeSprites;
}

/**
 * Fuente.
 */
TTF_Font *Locator::fuente_;

TTF_Font *Locator::fuente() {
    return fuente_;
}

void Locator::provide(TTF_Font *fuente) {
    fuente_ = fuente;
}

/**
 * Eventos a procesar.
 */
EventosAProcesar *Locator::eventos_;

EventosAProcesar *Locator::eventos() {
    return eventos_;
}

void Locator::provide(EventosAProcesar *eventos) {
    eventos_ = eventos;
}

/**
 * Manager de usuarios.
 */
ManagerUsuarios *Locator::usuarios_;

ManagerUsuarios *Locator::usuarios() {
    return usuarios_;
}

void Locator::provide(ManagerUsuarios *usuarios) {
    usuarios_ = usuarios;
}

/**
 * Mapa.
 */
Mapa *Locator::mapa_;

Mapa *Locator::mapa() {
    return mapa_;
}

void Locator::provide(Mapa *mapa) {
    mapa_ = mapa;
}

void Locator::clean() {
    logger_->log(DEBUG, "Se limpian configuracion y logger");

    delete configuracion_;
    delete logger_;
}