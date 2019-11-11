//
// Created by franco on 31/10/19.
//

#ifndef FINAL_FIGHT_ENVOLVENTEVOLUMEN_H
#define FINAL_FIGHT_ENVOLVENTEVOLUMEN_H


#include "../Entidad.h"
#include "../serializables/Posicion.h"
#include "Envolvente.h"

class EnvolventeVolumen : public Envolvente {

public:
    using Envolvente::Envolvente;
    bool colisionaPorIzquierdaCon(EnvolventeVolumen * envolvente);
    bool colisionaPorDerechaCon(EnvolventeVolumen * envolvente);
    bool colisionaAbajoCon(EnvolventeVolumen * envolvente);
    bool colisionaArribaCon(EnvolventeVolumen * envolvente);

};


#endif //FINAL_FIGHT_ENVOLVENTEVOLUMEN_H
