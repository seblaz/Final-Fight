//
// Created by franco on 20/10/19.
//

#ifndef FINAL_FIGHT_ANIMACIONSERVIDOR_H
#define FINAL_FIGHT_ANIMACIONSERVIDOR_H

#include "../modelo/Entidad.h"
#include "../servicios/Locator.h"

class AnimacionServidor : public Comportamiento {

private:
    vector<int> duracionesPorSprite;
    int duracionTotal;

    int framesFaltantes;
    int spriteActual;
    float sumaDeDuracionesRelativas;

    int calcularFramesFaltantes();
    
public:
    AnimacionServidor(Entidad *entidad, vector<int> duracionesPorSprite, int duracionTotal);
    void actualizar() override;

};


#endif //FINAL_FIGHT_ANIMACIONSERVIDOR_H
