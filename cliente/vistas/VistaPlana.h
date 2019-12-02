//
// Created by sebas on 18/11/19.
//

#ifndef FINAL_FIGHT_VISTAPLANA_H
#define FINAL_FIGHT_VISTAPLANA_H


#include "Vista.h"

class VistaPlana : public Vista {

private:
    string configFondo;
    string configMusica;

public:
    VistaPlana(string configFondo, string configMusica);
    void graficar(SDL_Renderer *renderer) override;
    string getConfigPathMusica() override;

};


#endif //FINAL_FIGHT_VISTAPLANA_H
