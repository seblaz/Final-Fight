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

void Locator::clean() {
    delete configuracion_;
    delete logger_;
}