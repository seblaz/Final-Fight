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
Socket Locator::socket_(0);

Socket Locator::socket() {
    return socket_;
}

void Locator::provide(Socket socket) {
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

void Locator::clean() {
    logger_->log(DEBUG, "Se limpian configuracion y logger");

    delete configuracion_;
    delete logger_;
}