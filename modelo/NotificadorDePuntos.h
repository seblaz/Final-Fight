//
// Created by leo on 15/11/19.
//

#ifndef FINAL_FIGHT_NOTIFICADORDEPUNTOS_H
#define FINAL_FIGHT_NOTIFICADORDEPUNTOS_H


#include "Entidad.h"

class NotificadorDePuntos : public Comportamiento {
    public:
        explicit NotificadorDePuntos(Entidad *entidad);
        void notificarGolpeAPersonaje(Entidad* personajeGolpeado);
        void notificarGolpeAElemento(Entidad* elementoGolpeado);
};


#endif //FINAL_FIGHT_NOTIFICADORDEPUNTOS_H
