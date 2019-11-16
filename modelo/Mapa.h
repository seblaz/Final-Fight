//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPA_H
#define FINAL_FIGHT_MAPA_H

#include "Entidad.h"
#include "Jugadores.h"
#include "Colisionables.h"
#include <vector>
#include <mutex>

using namespace std;

/**
 * IdEntidad. Id de la entidad de tipo numérico y estático.
 */
using IdEntidad = size_t;
using IdColisionable = size_t;


class Mapa {

private:
    static IdEntidad ultimoId;
    unordered_map<IdEntidad, Entidad*> entidades;
    Jugadores jugadores;
    stringstream serializadoMasReciente;
    mutex m;
    vector<Entidad *> colisionables;
    vector<Entidad *> personajes;
    vector<Entidad *> enemigos;
    vector<Entidad *> elementos;
    vector<Entidad *> armas;
    Entidad *crearEntidad();

public:
    Entidad *crearEntidadConId(IdEntidad idEntidad);
    void agregarJugadorConId(IdEntidad idEntidad, Entidad *jugador);
    vector<Entidad *> devolverEntidades();
    unordered_map<IdEntidad, Entidad *> devolverEntidadesConId();
    void vaciarMapa();
    Jugadores* getJugadores();
    Entidad *getEntidad(IdEntidad idEntidad);
    bool contiene(IdEntidad idEntidad);
    void guardarSerializado(stringstream &s);
    void serializar(ostream& stream);

    Entidad *crearJugador();
    Entidad *crearEnemigo();
    Entidad *crearElemento();
    Entidad *crearArma();
    Entidad *crearEscenario();

    vector<Entidad *> &getColisionables();
    vector<Entidad *> &getPersonajes();
    vector<Entidad *> &getEnemigos();
    vector<Entidad *> &getElementos();
    vector<Entidad *> &getArmas();

    Entidad *crearPantalla();

    Entidad *crearTransicion();

    bool bloqueoEscenarioPorEnemigos();
};

#endif //FINAL_FIGHT_MAPA_H
