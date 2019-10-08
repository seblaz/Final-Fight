//
// Created by sebas on 8/10/19.
//

#include "Actualizador.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../graficos/GraficoDePantallaCompleta.h"

Actualizador::Actualizador(Mapa *mapa) : mapa(mapa) {}

void Actualizador::actualizarEntidades(stringstream &s) {
    if (!inicio) {
        inicio = true;
        mapa->vaciarMapa();
    }

    IdEntidad idEntidad = Entidad::getIdFromStream(s);
    if (!mapa->contiene(idEntidad)) {
        Locator::logger()->log(DEBUG,
                               "El cliente no contiene la entidad: " + to_string(idEntidad) + ". Se va a crear.");
        Entidad *entidad = mapa->crearEntidadConId(idEntidad);
        entidad->deserializar(s);

        auto *tipo = entidad->getEstado<Tipo>("tipo");
        switch (tipo->tipo()) {
            case PANTALLA_SELECCION:
                Locator::logger()->log(INFO, "Se genera el menu de seleccion.");
                Configuracion *config = Locator::configuracion();
                string srcSprite = config->getValue("/pantallaDeSeleccion/jugador1/seleccion/src");
                auto *renderer = Locator::renderer();
                auto *sprite = new Sprite(renderer, srcSprite);
                auto *grafico = new GraficoDePantallaCompleta();
//                auto *entrada = new EntradaPantallaDeSeleccion();

                entidad->agregarEstado("sprite", sprite);
                entidad->agregarEstado("mapa", mapa);
                entidad->agregarComportamiento("grafico", grafico);
//                pantalla->agregarComportamiento("entrada", entrada);
                break;
//            case PERSONAJE:
//                break;
//            case ESCENARIO:
//                break;
        }
    }
}
