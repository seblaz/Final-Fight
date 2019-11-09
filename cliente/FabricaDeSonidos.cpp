//
// Created by sebas on 22/10/19.
//

#include "FabricaDeSonidos.h"
#include "../servicios/Locator.h"
#include "../sonidos/Sonido.h"

Sonido* FabricaDeSonidos::getSoundBySrc(const string& src) {
    if(sonidos.find(src) == sonidos.end()){
        sonidos[src] = new Sonido(src);
    }
    return sonidos[src];
}

Sonido* FabricaDeSonidos::getSoundConfigPath(const string& path){
    string src = Locator::configuracion()->getValue(path);
    return getSoundBySrc(src);
}
