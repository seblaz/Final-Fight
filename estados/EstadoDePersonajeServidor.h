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
    static map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)()> mapa;
    static void cambiarEstado(Entidad *entidad, ESTADO_DE_PERSONAJE estado);
    int frames = 0;

public:
    virtual void saltar(Entidad *);
    virtual void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg);
    virtual void reposar(Entidad *);
    virtual void agachar(Entidad *);
    virtual void darGolpe(Entidad *entidad);
    virtual void recibirGolpe(Entidad *entidad);

    void actualizar(Entidad * entidad) override;
};


#endif //FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H
