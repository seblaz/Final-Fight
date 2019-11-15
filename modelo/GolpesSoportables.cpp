//
// Created by franco on 11/11/19.
//

#include "GolpesSoportables.h"
#include "../servicios/Locator.h"

void GolpesSoportables::restarGolpe() {
    this -> maximoDeGolpes--;
    Locator::logger()->log(DEBUG, to_string(maximoDeGolpes));
    if ( seRompio() ){
        Locator::logger()->log(DEBUG, "Elemento ROTO!");
        
    }
}

bool GolpesSoportables::seRompio() {
    return ( maximoDeGolpes <= 0 );
}

GolpesSoportables::GolpesSoportables(int golpesMaximos) {
    this->maximoDeGolpes = golpesMaximos;
}
