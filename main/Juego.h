//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_JUEGO_H
#define FINAL_FIGHT_JUEGO_H

#include "../modelo/Mapa.h"
#include <SDL2/SDL.h>
#include "../tipos/tipos.h"
#include "../cliente/EntradaUsuario.h"
#include "../usuario/Usuario.h"

#define CANTIDAD_JUGADORES 4
#define CANT_MAX_CARACTERES_USUARIO 15
#define CANT_MAX_CARACTERES_CONTRASENIA 15

#define MAX_LENGTH 100

typedef struct seleccionarBox_t {
    SDL_Rect rect;
    string text;
    SDL_Color textcolor;
    //TTF_Font font;
} seleccionar_box_t;

bool _boxSeleccionadaRect(int x, int y, SDL_Rect *rect);
bool boxSeleccionada(seleccionar_box_t *boxSeleccionada, SDL_Event *e);

class Juego {

private:

    void inicializarGraficos();

    SDL_Event processInput();
    void actualizar();
    void graficar();
    void clearScene();
    void validarUserPass();
    Usuario& generarPantallaDeIngreso(bool &contraseniaIncorrecta);

    SDL_Renderer *renderer_ = nullptr;
    SDL_Window *window = nullptr;
    bool exit = false;
    Mapa mapa_;

public:
    Juego();

    void loop();
    Mapa &mapa();
//    nombreJugador generarMenuPrincipal();
    SDL_Renderer* renderer();
    void terminar();

};

#endif //FINAL_FIGHT_JUEGO_H