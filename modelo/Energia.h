//
// Created by franco on 29/10/19.
//

#ifndef FINAL_FIGHT_ENERGIA_H
#define FINAL_FIGHT_ENERGIA_H


#include "../serializar/Serializable.h"
#include "Entidad.h"

class Energia : public Estado, Serializable{

private:
    int puntosDeEnergia;
    int vidas;
    bool vivo;

public:
    Energia() = default;
    explicit Energia(int puntosDeEnergia, int vidas);
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

    void restarEnergia(int energiaRestada);
    bool personajeVive();
    int getEnergia();
    int getVidas();


};


#endif //FINAL_FIGHT_ENERGIA_H
