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
    Juego juego(&mapa);
    SDL_Renderer* renderer = juego.renderer();

    GraficosDePersonaje graficoDePersonaje(renderer, "assets/personajes/coddy.png");
    ComportamientoDeJugador comportamientoDeJugador;
    FisicaDePersonaje fisicaDePersonaje;
    Personaje personaje(1, 1, 0, "sebas", &mapa, &comportamientoDeJugador, &fisicaDePersonaje, &graficoDePersonaje);

    mapa.agregar(&personaje);

    juego.loop();
}
