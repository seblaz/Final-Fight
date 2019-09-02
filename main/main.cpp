#include "Game.h"

int main(int argc, char *args[]) {
    Mapa mapa(300, 1000, 500);
    Graphics graphics;
    Mapeable mapeable(1, 1, 0, graphics);

    mapa.agregar(&mapeable);
    Game game(mapa);
}
