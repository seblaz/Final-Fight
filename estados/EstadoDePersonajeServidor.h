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
    static void agregarEstado(Entidad *entidad, ESTADO_DE_PERSONAJE estado);
    static void cambiarAnimacion(Entidad *entidad, const string& estado);
    static map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)()> mapa;

public:
    virtual void saltar(Entidad *);
    virtual void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg);
    virtual void reposar(Entidad *);
    virtual void agachar(Entidad *);
    virtual void golpear(Entidad *);
    virtual void golpeado(Entidad *);

    void actualizar(Entidad * entidad) override;
};


#endif //FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H
