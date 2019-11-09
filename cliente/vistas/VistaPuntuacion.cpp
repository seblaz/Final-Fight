//
// Created by sebas on 7/11/19.
//

#include <set>
#include <algorithm>
#include "VistaPuntuacion.h"
#include "../../servicios/Locator.h"

VistaPuntuacion::VistaPuntuacion(PuntuacionJugadores *puntuaciones) :
        puntuaciones(puntuaciones) {}

void VistaPuntuacion::generarFondo(SDL_Renderer *renderer) {
    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");
    auto *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/puntuacion/fondo/src");

    SDL_Rect posicionEnPantallaCompleta = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, &posicionEnPantallaCompleta);
}

void VistaPuntuacion::generarTitulo(SDL_Renderer *renderer) {
    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");

    SDL_Color white = {255, 255, 255};
    string titulo = "puntos";
    SDL_Surface *surfaceTexto = TTF_RenderText_Solid(Locator::fuente(), titulo.c_str(), white);
    SDL_Texture *texturaTexto = SDL_CreateTextureFromSurface(renderer, surfaceTexto);
    SDL_FreeSurface(surfaceTexto);

    int tamanioLetra = 40;
    int anchoTitulo = titulo.size() * tamanioLetra;
    int x = ancho / 2 - titulo.size() * tamanioLetra / 2;
    SDL_Rect posicion = {x, 400, anchoTitulo, 100};

    SDL_RenderCopy(renderer, texturaTexto, nullptr, &posicion);
    SDL_DestroyTexture(texturaTexto);
}

void VistaPuntuacion::generarPuntuaciones(SDL_Renderer *renderer) {

    // Ordenar por puntuación más alta.
    auto puntos = puntuaciones->getPuntuaciones();
    std::vector<std::pair<std::string, int>> puntosOrdenados{std::make_move_iterator(begin(puntos)),
                                                             std::make_move_iterator(end(puntos))};
    sort(begin(puntosOrdenados), end(puntosOrdenados),
         [](auto p1, auto p2) { return p1.second > p2.second; });

    int y = 400;
    int offset = 20;
    int tamanioLetra = 30;
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    int xUsuario = ancho / 2 - 13 * tamanioLetra - offset;
    int xPuntos = ancho / 2 + offset;
    SDL_Color white = {255, 255, 255};

    for (const auto& tupla : puntosOrdenados) {
        SDL_Surface *surfaceUsuario = TTF_RenderText_Solid(Locator::fuente(), tupla.first.c_str(), white);
        SDL_Surface *surfacePuntos = TTF_RenderText_Solid(Locator::fuente(), to_string(tupla.second).c_str(), white);

        SDL_Texture *texturaUsuario = SDL_CreateTextureFromSurface(renderer, surfaceUsuario);
        SDL_Texture *texturaPuntos = SDL_CreateTextureFromSurface(renderer, surfacePuntos);

        SDL_FreeSurface(surfaceUsuario);
        SDL_FreeSurface(surfacePuntos);

        y += 100;
        int anchoUsuario = tupla.first.size() * tamanioLetra;
        SDL_Rect posicionUsuario = {xUsuario, y, anchoUsuario, 70};

        int anchoPuntos = to_string(tupla.second).size() * tamanioLetra;
        SDL_Rect posicionPuntos = {xPuntos, y, anchoPuntos, 70};

        SDL_RenderCopy(renderer, texturaUsuario, nullptr, &posicionUsuario);
        SDL_RenderCopy(renderer, texturaPuntos, nullptr, &posicionPuntos);

        SDL_DestroyTexture(texturaUsuario);
        SDL_DestroyTexture(texturaPuntos);
    }
}


void VistaPuntuacion::graficar(SDL_Renderer *renderer) {
    generarFondo(renderer);
    generarTitulo(renderer);
    generarPuntuaciones(renderer);
}


void VistaPuntuacion::reproducir() {
    if(Mix_PlayingMusic() == 0 )
    {
        Mix_PlayMusic( musica, 0);
    }
}

