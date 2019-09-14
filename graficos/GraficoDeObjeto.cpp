//
// Created by felipe on 14/9/19.
//


#include "GraficoDeObjeto.h"
#include "../modelo/mapeables/Objeto.h"

GraficoDeObjeto::GraficoDeObjeto(SDL_Renderer *renderer, SDL_Texture *texturaSprite) :
        renderer(renderer) {
        texture = texturaSprite;
}

void GraficoDeObjeto::actualizar(Mapeable &mapeable) {
    auto &objeto = dynamic_cast<Objeto &>(mapeable);

//    Posicion &posicion = escenario.posicion(); // Se obtiene la posicion del jugador y en base a eso se construye el hitbox del jugador.
//    SDL_Rect posicionJugador = {posicion.getX(), posicion.getY(), 200, 400};
    //Se setea la posicion de la plantilla de sprites (La posicion y dimension que se va a renderizar LA PLANTILLA DE SPRITES, no el hitbox)
//    TODO: poner estas coordenadas para cada sprite aca es turbio, hace falta sacarlo de aca (idea: tener una clase sprite).
    SDL_Rect posicionSprite = {0, 0, 150, 150};
    SDL_Rect posicionObjeto = {800, 500, 250, 400};

    //Se renderiza en la ventana la imagen, la posicion del sprite, y la posicion del jugador
    SDL_RenderCopy(renderer, texture, &posicionSprite, &posicionObjeto);

}