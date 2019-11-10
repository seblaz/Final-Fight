//
// Created by sebas on 20/10/19.
//

#include "FabricaDeAnimacionesServidor.h"

vector<int> split(string str, const string &token) {
    vector<int> result;
    while (!str.empty()) {
        int index = str.find(token);
        if (index != string::npos) {
            result.push_back(stoi(str.substr(0, index)));
            str = str.substr(index + token.size());
            if (str.empty()) result.push_back(stoi(str));
        } else {
            result.push_back(stoi(str));
            str = "";
        }
    }
    return result;
}

AnimacionServidor *FabricaDeAnimacionesServidor::getAnimacion(const string &ruta) {
    Configuracion *config = Locator::configuracion();
    vector<int> duraciones = split(config->getValue("/animaciones" + ruta + "/duraciones"), ",");
    return new AnimacionServidor(duraciones, config->getIntValue("/animaciones" + ruta + "/total"));
}

AnimacionServidor *
FabricaDeAnimacionesServidor::getAnimacion(enum PERSONAJE personajeSeleccionado, const string &estado) {
    string personaje = Personaje::PersonajeACadena(personajeSeleccionado);
    return getAnimacion("/" + personaje + "/" + estado);
}

AnimacionServidor *
FabricaDeAnimacionesServidor::getAnimacion(enum PERSONAJE personajeSeleccionado, enum ESTADO_DE_PERSONAJE estado) {
    return getAnimacion(personajeSeleccionado, EstadoDePersonaje::estadoACadena(estado));
}
