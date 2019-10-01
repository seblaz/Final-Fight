
#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEHAGGAR_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEHAGGAR_H


#include "Animacion.h"
#include "FabricaDeAnimacionesDePersonaje.h"

class FabricaDeAnimacionesDeHaggar : public FabricaDeAnimacionesDePersonaje {

public:
    Animacion* caminando() override;
    Animacion* saltando() override;
    Animacion* reposando() override;
    Animacion* agachado() override;
    Animacion* golpear() override;
    Animacion* saltandoAdelante() override;
    Animacion* patadaBasica() override;
};

#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEHAGGAR_H