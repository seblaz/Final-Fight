//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_ENTRADA_H
#define FINAL_FIGHT_ENTRADA_H

using namespace std;

class Entrada {

private:
    int socket;
    void procesarEntrada();

public:
    explicit Entrada(int socket);
    pthread_t procesarEntradaEnHilo();

};


#endif //FINAL_FIGHT_ENTRADA_H
