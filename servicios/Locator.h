//
// Created by sebas on 8/9/19.
// Simple implementacion de https://gameprogrammingpatterns.com/service-locator.html.
//

#ifndef FINAL_FIGHT_LOCATOR_H
#define FINAL_FIGHT_LOCATOR_H

#include "./Logger.h"
#include "Configuracion.h"

class Locator {

public:
    static Logger *logger();
    static void provide(Logger *logger);

    static Configuracion *configuracion();
    static void provide(Configuracion *configuracion);

    static void clean();

private:
    static Logger *logger_;
    static Configuracion *configuracion_;

};


#endif //FINAL_FIGHT_LOCATOR_H
