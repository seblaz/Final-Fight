//
// Created by sebas on 2/11/19.
//

#ifndef FINAL_FIGHT_PANTALLAJUEGO_H
#define FINAL_FIGHT_PANTALLAJUEGO_H


#include "../../../modelo/Mapa.h"
#include "../../ActualizadorCliente.h"
#include "../../ReceptorCliente.h"
#include "../Pantalla.h"

using namespace std;

class PantallaJuego : public Pantalla {

private:
    Mapa *mapa;
    EntradaNula entrada;
    ReceptorCliente receptor;
    TrasmisionCliente trasmision;
    ActualizadorCliente actualizador;
    pthread_t hiloRecepcion = 0;
    pthread_t hiloTransmision = 0;
    void actualizarEntidades();

public:
    explicit PantallaJuego(IdPantalla id, Mapa *mapa);
    void iniciar() override;
    void actualizar(SDL_Event *evento) override;
};


#endif //FINAL_FIGHT_PANTALLAJUEGO_H
