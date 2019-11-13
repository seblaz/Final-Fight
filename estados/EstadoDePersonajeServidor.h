//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H
#define FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H


#include "../modelo/Entidad.h"
#include "../servicios/Locator.h"
#include "../modelo/serializables/EstadoDePersonaje.h"

//class EstadoDePersonajeServidor;
//typedef map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)()> mapaEstados;

class EstadoDePersonajeServidor : public Comportamiento {

private:
    static map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)(Entidad *entidad)> mapa;
    void cambiarEstado(ESTADO_DE_PERSONAJE estado);
    int frames = 0;

public:
    explicit EstadoDePersonajeServidor(Entidad *entidad);

    virtual void saltar();
    virtual void caminar(bool X_pos, bool X_neg, bool Y_pos, bool Y_neg);
    virtual void reposar();
    virtual void agachar();
    virtual void darGolpe();
    virtual void recibirGolpe();

    void actualizar() override;
};


#endif //FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H
