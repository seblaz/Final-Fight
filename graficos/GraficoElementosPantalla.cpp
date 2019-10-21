#include "GraficoDeElementosPantalla.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"

#include <utility>
#include <cmath>

GraficoDeElementosPantalla::GraficoDeElementosPantalla(SDL_Texture* sprite,
                                       SDL_Rect posicionPantalla,
                                        float escalaHorizontal) :
        sprite(sprite),
        escalaHorizontal(escalaHorizontal),
        posicionPantalla(posicionPantalla) {}

void GraficoDeElementosPantalla::actualizar(Entidad *entidad) {
    SDL_Renderer* renderer = Locator::renderer();
    //int alto = Locator::configuracion()->getIntValue("/resolucion/alto");
    //int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    //int posicionX = entidad->getEstado<Posicion>("posicion")->getX();
    //int posicionY = entidad->getEstado<Posicion>("posicion")->getY();

    //SDL_Rect posicionSprite = posicionesSprite[i];
    //posicionSprite.w = int(round((float)ancho / escalaHorizontal));
    //posicionSprite.x = int(round((float)100/*posicionX*/ / escalaHorizontal));
    //SDL_Rect posicionPantalla = {100, , ancho, alto};

    SDL_RenderCopy(renderer, sprite, NULL/*&posicionSprite*/, &posicionPantalla);
}