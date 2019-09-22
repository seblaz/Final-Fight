#include "Juego.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../modelo/Posicion.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "../graficos/Grafico.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../estados/Parado.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../modelo/Orientacion.h"
#include "../niveles/Nivel.h"

//DECLARACION CONSTANTES
static const char *const PATH_SPRITE_CAJA = "assets/escenarios/caja.png";
static const char *const PATH_SPRITE_CUCHILLO = "assets/objetos/cuchillo.png";

static const char *const PATH_XML_CANTIDAD_CAJA = "/escenario/objetos/caja/cantidad";
static const char *const PATH_XML_CANTIDAD_CUCHILLO = "/escenario/objetos/cuchillo/cantidad";



int generarPosicionX(int limiteDeFrontera){
    return rand() % limiteDeFrontera;
}

int generarPosicionY(){
    return rand() % 400;
}

int main(int argc, char *args[]) {
    /**
     * Iniciar.
     */
    Logger* logger;
    Configuracion *config;

    if (argc == 1){
        logger = new Logger();
        Locator::provide(logger);
        config = new Configuracion();
    } else{
        if (argc == 2){
            string param = args[1];
            size_t found = param.find(".xml");

            if (found!=std::string::npos){
                logger = new Logger();
                Locator::provide(logger);
                config = new Configuracion(args[1]);
            } else{
                logger = new Logger(args[1]);
                Locator::provide(logger);
                config = new Configuracion();
            }

        }else{
            logger = new Logger(args[1]);
            Locator::provide(logger);
            config = new Configuracion(args[2]);
        }
    }
    Locator::provide(config);


    Juego juego;
    SDL_Renderer *renderer = juego.renderer();
    Locator::provide(renderer);

    Mapa &mapa = juego.mapa();

    Nivel::generarNivel(renderer,&mapa);


    juego.loop();

    delete logger;
    delete config;
}
