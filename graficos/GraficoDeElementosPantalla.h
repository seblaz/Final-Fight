#ifndef FINAL_FIGHT_GRAFICODEELEMENTOSPANTALLA_H
#define FINAL_FIGHT_GRAFICODEELEMENTOSPANTALLA_H

#include <SDL_system.h>
#include <string>
#include "../modelo/Entidad.h"

using namespace std;

class GraficoDeElementosPantalla : public Comportamiento {

private:
    float escalaHorizontal;
    SDL_Texture* sprite;
    SDL_Rect posicionPantalla;
    
public:
    /**
     *
     * @param sprites
     * @param posicionesSprite
     * @param distanciasAlFondo: float entre 0 y 1 que indica la distancia desde
     * la capa i hasta el fondo (capa que no se mueve). 0 = primera capa, 1 = fondo inamovible.
     */
    explicit GraficoDeElementosPantalla(SDL_Texture * sprite,
                                       SDL_Rect posicionPantalla,
                                        float escalaHorizontal);
    ~GraficoDeElementosPantalla() = default;

    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_GRAFICODEELEMENTOSPANTALLA_H