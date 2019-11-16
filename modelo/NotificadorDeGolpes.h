//
// Created by leo on 15/11/19.
//

#ifndef FINAL_FIGHT_NOTIFICADORDEGOLPES_H
#define FINAL_FIGHT_NOTIFICADORDEGOLPES_H


#include "Entidad.h"

class NotificadorDeGolpes : public Comportamiento {
    public:
        explicit NotificadorDeGolpes(Entidad *entidad);
        void notificarGolpeAPersonaje(Entidad* personajeGolpeado);
        void notificarGolpeAElemento(Entidad* elementoGolpeado);
};


#endif //FINAL_FIGHT_NOTIFICADORDEGOLPES_H
