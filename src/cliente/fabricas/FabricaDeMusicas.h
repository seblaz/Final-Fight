#ifndef FINAL_FIGHT_FABRICADEMUSICAS_H
#define FINAL_FIGHT_FABRICADEMUSICAS_H

#include <unordered_map>
#include "../../graficos/Sprite.h"
#include "../../sonidos/Musica.h"

using namespace std;

class FabricaDeMusicas
{

private:
  unordered_map < string, Musica * >musicas;

public:
  Musica * getMusicBySrc (const string & src);
  Musica *getMusicByConfigPath (const string & path);
};


#endif //FINAL_FIGHT_FABRICADEMUSICAS_H
