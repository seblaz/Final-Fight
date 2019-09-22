//
// Created by sebas on 10/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEESCENARIO_H
#define FINAL_FIGHT_GRAFICODEESCENARIO_H


#include <SDL_system.h>
#include <string>
#include "../modelo/Entidad.h"

using namespace std;

class GraficoDeEscenario : public Comportamiento {

private:
    int longitudDeSprite;
    vector<SDL_Texture *> sprites;
    vector<SDL_Rect> posicionesSprite;
    vector<float> distanciasAlFondo;

public:
    /**
     *
     * @param sprites
     * @param posicionesSprite
     * @param distanciasAlFondo: float entre 0 y 1 que indica la distancia desde
     * la capa i hasta el fondo (capa que no se mueve). 0 = primera capa, 1 = fondo inamovible.
     */
    explicit GraficoDeEscenario(vector<SDL_Texture *> sprites,
                                vector<SDL_Rect> posicionesSprite,
                                vector<float> distanciasAlFondo, int longitudDeSprite);

    ~GraficoDeEscenario() = default;

    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_GRAFICODEESCENARIO_H
