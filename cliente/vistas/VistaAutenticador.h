//
// Created by sebas on 30/10/19.
//

#ifndef FINAL_FIGHT_VISTAAUTENTICADOR_H
#define FINAL_FIGHT_VISTAAUTENTICADOR_H


#include <SDL_system.h>
#include <SDL_ttf.h>
#include "../../usuario/Usuario.h"
#include "Vista.h"
#include "../modelos/Autenticador.h"

class VistaAutenticador : public Vista {

private:
    TTF_Font *fuente;
    Autenticador *autenticador;
    int framesFaltantesPasswordIncorrecta = 0;

    void generarTexto(SDL_Renderer *renderer, const string& texto, SDL_Rect posicion);
    void generarFormulario(SDL_Renderer *renderer, const string& usuario, const string& password);
    static void generarFondo(SDL_Renderer *renderer);
    static void generarMensajePasswordIncorrecta(SDL_Renderer *renderer);

public:
    explicit VistaAutenticador(Autenticador *autenticador);
    void passwordIncorrecta();
    void graficar(SDL_Renderer *renderer) override;
//    void actualizar(const string &usuario, const string &password, bool passIncorrecta);
};


#endif //FINAL_FIGHT_VISTAAUTENTICADOR_H
