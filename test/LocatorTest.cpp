//
// Created by sebas on 11/9/19.
//

#include "gtest/gtest.h"
#include "../servicios/Logger.h"
#include "../servicios/Locator.h"

TEST(Locator, DespuesDeAgregarElServicioPuedoUsarloEnLocator){
    auto *logger = new Logger("INFO");
    Locator::provide(logger);

    Locator::logger()->log(DEBUG, "Soy un mensaje de debug que no se va a ver");
    delete logger;
}