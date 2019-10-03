//
// Created by sebas on 3/10/19.
//

#include "GraficoDePantallaCompleta.h"
#include "Sprite.h"
#include "../servicios/Locator.h"

void GraficoDePantallaCompleta::actualizar(Entidad *entidad) {
    auto *sprite = entidad->getEstado<Sprite>("sprite");
    auto *renderer = Locator::renderer();
    SDL_RenderCopy(renderer, sprite->getTexture(), nullptr, nullptr);
}
