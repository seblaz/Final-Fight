//
// Created by sebas on 8/9/19.
// Simple implementacion de https://gameprogrammingpatterns.com/service-locator.html.
//

#ifndef MYAPP_LOCATOR_H
#define MYAPP_LOCATOR_H

#include "./Logger.h"

class Locator {

public:
    static Logger *logger();

    static void provide(Logger *logger);

private:
    static Logger *logger_;

};


#endif //MYAPP_LOCATOR_H
