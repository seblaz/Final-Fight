//
// Created by franco on 20/10/19.
//

#ifndef FINAL_FIGHT_ANIMACIONSERVIDOR_H
#define FINAL_FIGHT_ANIMACIONSERVIDOR_H

#include "../modelo/Entidad.h"
#include "../servicios/Locator.h"

class AnimacionServidor : public  Comportamiento {

private:
    int posicion;
    vector<float> duracionesPorSprite;
    int duracionTotal;

    int framesFaltantes;
    int spriteActual;
    float sumaDeDuracionesRelativas;

    int calcularFramesFaltantes();
public:
    AnimacionServidor(vector<float> duracionesPorSprite, int duracionTotal);
    void actualizar(Entidad* entidad) override;

};


#endif //FINAL_FIGHT_ANIMACIONSERVIDOR_H
