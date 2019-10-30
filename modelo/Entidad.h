//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ENTIDAD_H
#define FINAL_FIGHT_ENTIDAD_H

#include <unordered_map>
#include "Iterator.cpp"
#include "serializables/Serializable.h"
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
class Estado : protected Serializable {

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

typedef map<string, Estado *(*)()> estadosMapType;

class Entidad : public Serializable {

private:
    unordered_map<string, Estado *> estados;
    unordered_map<string, Comportamiento *> comportamientos;
    static vector<string> estadosSerializables;
    static estadosMapType mapaEstados;
    const int fin = -1;

public:
    Entidad();
    static void putIdInStream(ostream &in, IdEntidad idEntidad);
    static IdEntidad getIdFromStream(istream &stream);

    void agregarEstado(const string &s, Estado *t) {
        if (estados.find(s) != estados.end())
            delete estados[s];
        estados[s] = t;
    };

    template<typename T>
    T *getEstado(const string &s) {
        return (T *) estados[s];
    };

    bool contieneEstado(const string &s){
        return estados.find(s) != estados.end();
    }

    void agregarComportamiento(const string &s, Comportamiento *t) {
//        if (comportamientos.find(s) != comportamientos.end())
//            delete comportamientos[s];
        comportamientos[s] = t;
    };

    template<typename T>
    T *getComportamiento(const string &s) {
        return (T *) comportamientos[s];
    };

    void quitarComportamiento(const string &s) {
        comportamientos.erase(s);
    };

    vector<Comportamiento *> getComportamientos();
    
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
};


/**
 * Tipo de entidad.
 */
enum TIPO {
    PANTALLA_SELECCION,
    PERSONAJE,
    ESCENARIO,
    JUGADOR,
    TRANSICION,
    ENEMIGO,
    USUARIO,
    ELEMENTO
};

class Tipo : public Estado {

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
