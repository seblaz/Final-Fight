//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_PANTALLAJUEGO_H
#define FINAL_FIGHT_PANTALLAJUEGO_H


#include "Pantalla.h"
#include "../ReceptorCliente.h"

class PantallaJuego : public Pantalla {

private:
    ReceptorCliente receptor;

public:
    using Pantalla::Pantalla;
    void iniciar() override;
    void recibir(stringstream &s) override;

};


#endif //FINAL_FIGHT_PANTALLAJUEGO_H
