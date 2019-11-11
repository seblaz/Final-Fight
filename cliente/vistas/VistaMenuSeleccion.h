//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_VISTAMENUSELECCION_H
#define FINAL_FIGHT_VISTAMENUSELECCION_H


#include <SDL_system.h>
#include "Vista.h"
#include "../../graficos/Sprite.h"
#include "../../servicios/Locator.h"
#include "../modelos/MenuSeleccion.h"


class VistaMenuSeleccion : public Vista {

private:
    Sprite *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/seleccion/fondo/src");
    Sprite *selector = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/seleccion/selector/src");
    Sprite *confirmacion = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/seleccion/listo/src");
    MenuSeleccion *menu;

public:
    explicit VistaMenuSeleccion(MenuSeleccion *menu);
    void graficar(SDL_Renderer *renderer) override;
    string getConfigPathMusica() override;

};


#endif //FINAL_FIGHT_VISTAMENUSELECCION_H
