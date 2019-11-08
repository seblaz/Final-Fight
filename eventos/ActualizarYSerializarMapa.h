//
// Created by sebas on 7/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZARYSERIALIZARMAPA_H
#define FINAL_FIGHT_ACTUALIZARYSERIALIZARMAPA_H


#include "Eventos.h"

class ActualizarYSerializarMapa : public EventoAProcesar {

private:
    Mapa *mapa;
    void serializar();
    void actualizar();

public:
    explicit ActualizarYSerializarMapa(Mapa *mapa);
    void resolver() override;
};


#endif //FINAL_FIGHT_ACTUALIZARYSERIALIZARMAPA_H
