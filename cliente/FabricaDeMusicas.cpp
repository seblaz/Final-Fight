#include "FabricaDeMusicas.h"
#include "../servicios/Locator.h"

Musica* FabricaDeMusicas::getMusicBySrc(const string& src) {
    if(musicas.find(src) == musicas.end()){
        musicas[src] = new Musica(src);
    }
    return musicas[src];
}

Musica* FabricaDeMusicas::getMusicByConfigPath(const string& path){
    string src = Locator::configuracion()->getValue(path);
    return getMusicBySrc(src);
}
