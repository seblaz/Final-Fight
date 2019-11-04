//
// Created by poncio on 23/9/19.
//

#ifndef FINAL_FIGHT_REPRODUCTOREFECTOSDENIVEL_H
#define FINAL_FIGHT_REPRODUCTOREFECTOSDENIVEL_H

#include "../modelo/Entidad.h"

class ReproductorEfectosDeNivel : public Comportamiento{


private:
    char *rutaMusica;

public:
    explicit ReproductorEfectosDeNivel(char * rutaMusica);
    void actualizar(Entidad *) override ;

    static void reproducirMusica(char *basicString);
};

#endif //FINAL_FIGHT_REPRODUCTOREFECTOSDENIVEL_H
