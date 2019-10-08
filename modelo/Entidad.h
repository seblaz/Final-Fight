//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ENTIDAD_H
#define FINAL_FIGHT_ENTIDAD_H

#include <unordered_map>
#include "Iterator.cpp"
#include "../serializar/Serializable.h"
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

public:
    virtual void serializar(ostream& stream) {};
    virtual void deserializar(istream& stream) {};
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

class Entidad : public Serializable {

private:
    static IdEntidad ultimoId;
    IdEntidad idEntidad;
    unordered_map<string, Estado *> estados;
    unordered_map<string, Comportamiento *> comportamientos;
    vector<string> estadosSerializables = {"posicion", "orientacion"};

public:
    Entidad();
    explicit Entidad(IdEntidad idEntidad);

    IdEntidad getId();
    void putIdInStream(ostream &in);
    static IdEntidad getIdFromStream(istream &stream);

    template<typename T>
    void agregarEstado(const string &s, T *t) {
        if (estados.find(s) != estados.end())
            delete estados[s];
        estados[s] = t;
    };

    template<typename T>
    T *getEstado(const string &s) {
        return (T *) estados[s];
    };

    template<typename T>
    void agregarComportamiento(const string &s, T *t) {
        if (comportamientos.find(s) != comportamientos.end())
            delete comportamientos[s];
        comportamientos[s] = t;
    };

    template<typename T>
    T *getComportamiento(const string &s) {
        return (T *) comportamientos[s];
    };

    vector<Comportamiento *> getComportamientos();

    vector<Estado *> getEstados();

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
};


/**
 * Tipo de entidad.
 */
enum TIPO {
    PANTALLA_SELECCION,
    PERSONAJE,
    ESCENARIO
};

class Tipo : public Estado, Serializable {

private:
    TIPO tipo_;

public:
    explicit Tipo(TIPO tipo);
    Tipo();
    TIPO tipo();

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

    bool operator==(const Tipo &otroTipo);

};

#endif //FINAL_FIGHT_ENTIDAD_H
