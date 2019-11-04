//
// Created by sebas on 2/11/19.
//

#ifndef FINAL_FIGHT_PANTALLAERROR_H
#define FINAL_FIGHT_PANTALLAERROR_H


#include "../Pantalla.h"

using namespace std;

class PantallaError : public Pantalla {

private:
    string configPath;

public:
    explicit PantallaError(IdPantalla id, string  configPath);
    void actualizar(SDL_Event *e) override;
};


#endif //FINAL_FIGHT_PANTALLAERROR_H
