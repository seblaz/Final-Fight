//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H
#define FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H


#include "../EstadoDeColisionable.h"
#include "../../servicios/Locator.h"
#include "../../modelo/serializables/EstadoDePersonaje.h"

//class EstadoDePersonajeServidor;
//typedef map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)()> mapaEstados;

class EstadoDePersonajeServidor : public EstadoDeColisionable {

private:
    static map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)(Entidad *entidad)> mapa;
    void cambiarEstado(ESTADO_DE_PERSONAJE estado);
    int frames = 0;

protected:
    int framesFaltantes;

public:
    explicit EstadoDePersonajeServidor(Entidad *entidad);
    virtual void saltar();
    virtual void caminar(bool X_pos, bool X_neg, bool Y_pos, bool Y_neg);
    virtual void reposar();
    virtual void agachar();
    virtual void darGolpe();
    void recibirGolpeDe(Entidad* golpeador) override;
    virtual void morir();

    void actualizar() override;
};


#endif //FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H
