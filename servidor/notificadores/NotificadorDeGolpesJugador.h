//
// Created by leo on 15/11/19.
//

#ifndef FINAL_FIGHT_NOTIFICADORDEGOLPESJUGADOR_H
#define FINAL_FIGHT_NOTIFICADORDEGOLPESJUGADOR_H


#include "../../modelo/Entidad.h"
#include "NotificadorDeGolpes.h"

class NotificadorDeGolpesJugador : public NotificadorDeGolpes {

private:
    Entidad *jugador;

public:
    explicit NotificadorDeGolpesJugador(Entidad *entidad);

    void notificarGolpeAPersonaje(Entidad *personajeGolpeado) override;
    void notificarGolpeAElemento(Elemento *elementoGolpeado) override;

};


#endif //FINAL_FIGHT_NOTIFICADORDEGOLPESJUGADOR_H
