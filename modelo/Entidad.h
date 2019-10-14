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
    unordered_map<string, Estado *> estados;
    unordered_map<string, Comportamiento *> comportamientos;
    vector<string> estadosSerializables = { "posicion", "orientacion", "nivel", "estado" ,"personaje", "opacidad", "tipo elemento"};
     const int fin = 999999999;

public:
    static void putIdInStream(ostream &in, IdEntidad idEntidad);
    static IdEntidad getIdFromStream(istream &stream);

    template<typename T>
    void agregarEstado(const string &s, T *t) {
//        if (estados.find(s) != estados.end())
//            delete estados[s];
        estados[s] = t;
    };

    template<typename T>
    T *getEstado(const string &s) {
        return (T *) estados[s];
    };

    bool contieneEstado(const string &s){
        return estados.find(s) != estados.end();
    }

    template<typename T>
    void agregarComportamiento(const string &s, T *t) {
//        if (comportamientos.find(s) != comportamientos.end())
//            delete comportamientos[s];
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
    PERSONAJE_SELECCION,
    PERSONAJE,
    ESCENARIO,
    JUGADOR,
    TRANSICION,
    ENEMIGO,
    USUARIO,
    ELEMENTO
};

class Tipo : public Estado, Serializable {

private:
    TIPO tipo_;

public:
    explicit Tipo(TIPO tipo);
    Tipo();
    TIPO tipo();

    /**
     * Serializar.
     * Formato: Tipo, idEstado1, estado1, idEstado2, estado2, ...
     * @param stream
     */
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

    bool operator==(const Tipo &otroTipo);

};

#endif //FINAL_FIGHT_ENTIDAD_H
