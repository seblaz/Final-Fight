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
int Locator::socket_;

int Locator::socket() {
    return socket_;
}

void Locator::provide(int socket) {
    socket_ = socket;
}

void Locator::clean() {
    logger_->log(DEBUG, "Se limpian configuracion y logger");

    delete configuracion_;
    delete logger_;
}
