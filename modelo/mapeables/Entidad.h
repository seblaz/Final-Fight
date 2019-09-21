//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ENTIDAD_H
#define FINAL_FIGHT_ENTIDAD_H

#include <unordered_map>
#include "../Iterator.cpp"
#include <cstddef>
#include <vector>
#include <map>

using namespace std;

/**
 * Entidad. Representa una entidad del juego.
 */
class Entidad;

/**
 * Estado. Representa un estado de una entidad (solo datos sin comportamiento).
 */
class Estado {
};

/**
 * Comportamiento. Representa una parte del comportamiento de una entidad del juego.
 * Puede mantener estado propio, pero hace uso del estado de la entidad.
 */
class Comportamiento {

public:
    virtual void actualizar(Entidad *) {};

};

/**
 * IdEntidad. Id de la entidad de tipo numérico y estático.
 */
using IdEntidad = size_t;

class Entidad {

private:
    static IdEntidad ultimoId;
    IdEntidad idEntidad;
    unordered_map<size_t, Estado *> estados;
    unordered_map<size_t, Comportamiento *> comportamientos;

public:
    Entidad();

    IdEntidad getId();

    template<typename T>
    void agregarEstado(T *t) {
        int hash = typeid(T).hash_code();
        estados[hash] = t;
    };

    template<typename T>
    T *getEstado() {
        int hash = typeid(T).hash_code();
        return (T *) estados[hash];
    };

    template<typename T>
    void agregarComportamiento(T *t) {
        int hash = typeid(T).hash_code();
        comportamientos[hash] = t;
    };

    template<typename T>
    T *getComportamiento() {
        int hash = typeid(T).hash_code();
        return (T *) comportamientos[hash];
    };

    vector<Comportamiento *> getComportamientos();

    vector<Estado *> getEstados();
};


#endif //FINAL_FIGHT_ENTIDAD_H
