//
// Created by sebas on 7/11/19.
//

#ifndef FINAL_FIGHT_VISTAPUNTUACION_H
#define FINAL_FIGHT_VISTAPUNTUACION_H


#include <SDL_render.h>
#include <SDL_mixer.h>
#include "Vista.h"
#include "../modelos/PuntuacionJugadores.h"
#include "../../servicios/Locator.h"

class VistaPuntuacion : public Vista {

private:
    PuntuacionJugadores *puntuaciones;
    static void generarFondo(SDL_Renderer *renderer);
    static void generarTitulo(SDL_Renderer *renderer);
    void generarPuntuaciones(SDL_Renderer *renderer);
    Mix_Music* musica = Locator::fabricaDeMusicas()->getMusicBySrc("assets/musicas/puntaje.wav")->getMusic();


public:
    explicit VistaPuntuacion(PuntuacionJugadores *puntuaciones);
    void graficar(SDL_Renderer *renderer) override;
    void reproducir() override;
};


#endif //FINAL_FIGHT_VISTAPUNTUACION_H
