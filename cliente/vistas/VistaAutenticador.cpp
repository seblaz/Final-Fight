//
// Created by sebas on 30/10/19.
//

#include <SDL_events.h>
#include "VistaAutenticador.h"
#include "../../servicios/Locator.h"

VistaAutenticador::VistaAutenticador(Autenticador *autenticador) :
        fuente(Locator::fuente()),
        autenticador(autenticador) {}

void VistaAutenticador::generarFondo(SDL_Renderer *renderer) {
    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");

    auto *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/fondo/src");

    SDL_Rect posicionEnPantallaCompleta = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, &posicionEnPantallaCompleta);
}

void VistaAutenticador::generarFormulario(SDL_Renderer *renderer, const string &usuario, const string &password) {

    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");

    auto *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/formulario/fondo/src");
    auto *user = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/formulario/usuario/src");
    auto *pass = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/formulario/password/src");
    auto *enter = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/formulario/enter/src");

    SDL_Rect cajaFondo = {int(ancho / 3), int(alto / 1.7), int(ancho / 3), int(alto / 2.45)};
    SDL_Rect cajaUser = {int(ancho / 2.8), int(alto / 1.45), int(ancho / 3.5), int(alto / 13)};
    SDL_Rect cajaPass = {int(ancho / 2.8), int(alto / 1.29), int(ancho / 3.5), int(alto / 13)};
    SDL_Rect cajaEnter = {int(ancho / 2.5), int(alto / 1.15), int(ancho / 5), int(alto / 14)};

    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, &cajaFondo);
    SDL_RenderCopy(renderer, user->getTexture(), nullptr, &cajaUser);
    SDL_RenderCopy(renderer, pass->getTexture(), nullptr, &cajaPass);
    SDL_RenderCopy(renderer, enter->getTexture(), nullptr, &cajaEnter);

    // llenar usuario y pass
    generarTexto(renderer, usuario, cajaUser);
    generarTexto(renderer, password, cajaPass);
}

void VistaAutenticador::generarTexto(SDL_Renderer *renderer, const string &texto, SDL_Rect posicion) {
    SDL_Color white = {255, 255, 255};
    SDL_Surface *surfaceTexto = TTF_RenderText_Solid(fuente, texto.c_str(), white);
    SDL_Texture *texturaTexto = SDL_CreateTextureFromSurface(renderer, surfaceTexto);
    SDL_FreeSurface(surfaceTexto);

    posicion.x += 160;
    posicion.y += 10;
    posicion.h = 45;
    posicion.w = (int) texto.size() * 21;
    SDL_RenderCopy(renderer, texturaTexto, nullptr, &posicion);
    SDL_DestroyTexture(texturaTexto);
}

void VistaAutenticador::generarMensajePasswordIncorrecta(SDL_Renderer *renderer) {
    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");

    auto *sprite = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/rechazado/src");
    SDL_Rect cajaRechazado = {(int) (ancho / 2.45), (int) (alto / 3), (int) (ancho / 6), (int) (alto / 4.5)};
    SDL_RenderCopy(renderer, sprite->getTexture(), nullptr, &cajaRechazado);
}

void VistaAutenticador::graficar(SDL_Renderer *renderer) {
    generarFondo(renderer);
    generarFormulario(renderer, autenticador->getUsuario(), autenticador->getPassword());
    if (autenticador->passwordIncorrecta()) generarMensajePasswordIncorrecta(renderer);
}


void VistaAutenticador::reproducir() {

    if(Mix_PlayingMusic() == 0 )
    {
        Mix_PlayMusic( musica, -1);
    }
}

