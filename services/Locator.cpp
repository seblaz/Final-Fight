//
// Created by sebas on 8/9/19.
//

#include "Locator.h"

Logger *Locator::logger_;

Logger *Locator::logger() {
    return logger_;
}

void Locator::provide(Logger *logger) {
    logger_ = logger;
}
