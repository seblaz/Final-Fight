#include "Game.h"
#include "../graphics/BoxGraphics.h"

int main(int argc, char *args[]) {
    Mapa mapa(300, 1000, 500);
    BoxGraphics boxGraphics;
    Mapeable mapeable(1, 1, 0, &boxGraphics);

    mapa.agregar(&mapeable);
    Game game(mapa);
}
