
#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEHAGGAR_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEHAGGAR_H


#include "AnimacionCliente.h"
#include "FabricaDeAnimacionesDePersonaje.h"

class FabricaDeAnimacionesDeHaggar : public FabricaDeAnimacionesDePersonaje {

public:
    AnimacionCliente* caminando() override;
    AnimacionCliente* saltando() override;
    AnimacionCliente* reposando() override;
    AnimacionCliente* agachado() override;
    AnimacionCliente* golpear() override;
    AnimacionCliente* saltandoAdelante() override;
    AnimacionCliente* patadaBasica() override;
};

#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEHAGGAR_H