//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ENTIDAD_H
#define FINAL_FIGHT_ENTIDAD_H

#include <cstddef>
#include <map>
#include <unordered_map>

using namespace std;

class Componente {

};

using IdEntidad = size_t;

class Entidad {

private:
    static IdEntidad ultimoId;
    IdEntidad idEntidad;
    unordered_map<size_t, Componente*> componentes;

public:
    Entidad();

    template<typename T>
    void agregarComponente(T *t) {
        int hash = typeid(T).hash_code();
        componentes[hash] = t;
    };

    template<typename T>
    T* getComponente() {
        int hash = typeid(T).hash_code();
        return (T*)componentes[hash];
    };

    IdEntidad getId();
};


#endif //FINAL_FIGHT_ENTIDAD_H
