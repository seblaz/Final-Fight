//
// Created by sebas on 5/11/19.
//

#include "Cliente.h"
#include "../../servicios/Locator.h"
#include "../etapas/Etapa.h"
#include "../modelo/ModeloAutenticacion.h"
#include "../interpretes/InterpreteAutenticacion.h"
#include "../modelo/ModeloMenuSeleccion.h"
#include "../interpretes/InterpreteMenuSeleccion.h"
#include "../modelo/ModeloJuego.h"
#include "../interpretes/InterpreteJuego.h"
#include <unistd.h>
#include <functional>


Cliente::Cliente(Socket *socket) :
        socket(socket) {
    auto *modeloAutenticacion = new ModeloAutenticacion();
    auto *interpreteAutenticacion = new InterpreteAutenticacion(usuario, modeloAutenticacion, &etapas);
    etapas.agregar(new Etapa("autenticacion", modeloAutenticacion, interpreteAutenticacion));
    etapas.agregar(new Etapa("menu de seleccion", new ModeloMenuSeleccion(), new InterpreteMenuSeleccion(usuario)));
    etapas.agregar(new Etapa("juego", new ModeloJuego(), new InterpreteJuego(usuario)));

    lanzarHilo(bind(&Cliente::transmitirEnHilo, this));
    lanzarHilo(bind(&Cliente::recibirEnHilo, this));
}

void Cliente::cambiarA(const IdEtapa &etapa) {
    etapas.cambiarA(etapa);
}

void Cliente::recibirEnHilo() {
    stringstream s;
    while (!fin) {
        if (socket->estaDesconectado() || !socket->recibir(s)) {
            Locator::logger()->log(ERROR, "Se detecta socket invalido y se cierra.");
            break;
        };
        etapas.getActual()->getInterprete()->interpretarStream(s);
    }
    etapas.getActual()->getInterprete()->finalizar();
    Locator::logger()->log(DEBUG, "Se termina el hilo de recepción.");
}

void Cliente::transmitirEnHilo() {
    const size_t MS_PER_FRAME = 1.0 / Locator::configuracion()->getIntValue("/fps") * 1000 * 1000; // Microsegundos.
    stringstream s;
    while (!fin) {
        etapas.getActual()->getModelo()->serializar(s);
        if (socket->estaDesconectado() || !socket->enviar(s)) {
            Locator::logger()->log(ERROR, "Se detecta socket invalido y se cierra.");
            break;
        }
        usleep(MS_PER_FRAME);
    }
    Locator::logger()->log(DEBUG, "Se termina el hilo de transmisión.");
}
