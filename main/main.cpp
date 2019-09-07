#include "Juego.h"
#include "../graficos/GraficoDeCaja.h"
#include "../graficos/GraficoDePersonaje.h"
#include "../modelo/mapeables/Personaje.h"
#include "../comportamiento/ComportamientoDeJugador.h"
#include "../fisica/FisicaDePersonaje.h"

int main(int argc, char *args[]) {
    Mapa mapa(300, 1000, 500);
//    GraficoDeCaja boxGraphics;
//    Mapeable mapeable(1, 1, 0, &boxGraphics);
//    mapa.agregar(&mapeable);
//
    GraficosDePersonaje graficoDePersonaje;
    ComportamientoDeJugador comportamientoDeJugador;
    FisicaDePersonaje fisicaDePersonaje;
    Personaje personaje(1, 1, 0, "sebas","assets/personajes/coddy.png", &mapa, &comportamientoDeJugador, &fisicaDePersonaje, &graficoDePersonaje);
    mapa.agregar(&personaje);

    Juego game(mapa);
    game.initialize();
    game.loop();
    game.finish();
}
