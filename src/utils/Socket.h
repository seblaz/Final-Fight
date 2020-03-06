//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_SOCKET_H
#define FINAL_FIGHT_SOCKET_H


#include <sstream>
#include <chrono>

using namespace std;

class Socket
{

private:
  int socket;
  int tamanoDigitos = 5;
  bool enviarSinChequeo (stringstream & s);
  bool recibirConCantidad (stringstream & s, size_t cantidad);
    chrono::time_point <chrono::system_clock> ultimaRecepcion =
    chrono::system_clock::now ();
  const int milisegundosDesconexion = 1000;

public:
    explicit Socket (int socket);
  int getIntSocket ();
  bool enviar (stringstream & s);
  bool recibir (stringstream & s);
  bool estaDesconectado ();
  void finalizarConexion ();

};


#endif //FINAL_FIGHT_SOCKET_H
