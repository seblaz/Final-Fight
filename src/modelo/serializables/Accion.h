//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_ACCION_H
#define FINAL_FIGHT_ACCION_H

#include "Serializable.h"
#include "../../usuario/Usuario.h"

enum ACCION
{
  CONFIRMAR,
  GOLPEAR,
  SALTAR,
  REPOSAR,
  AGACHAR,
  CAM_IZQUIERDA,
  CAM_DERECHA,
  CAM_ARRIBA,
  CAM_ABAJO,
  CAM_IZQUIERDA_ARRIBA,
  CAM_IZQUIERDA_ABAJO,
  CAM_DERECHA_ARRIBA,
  CAM_DERECHA_ABAJO,
  SELECCIONAR_GUY,
  SELECCIONAR_CODY,
  SELECCIONAR_HAGGAR,
  SELECCIONAR_MAKI,
  ENVIAR_USUARIO,
  FIN,
  NULA,
  MODOTEST
};

class Accion:public Serializable
{

private:
  ACCION accion_;

public:
  Accion ();
  explicit Accion (ACCION accion);
  ACCION accion ();
  void serializar (ostream & stream) override;
  void deserializar (istream & stream) override;

};

class AccionEnviarUsuario:public Accion
{

private:
  Usuario * usuario;

public:
  explicit AccionEnviarUsuario (Usuario * usuario);
  void serializar (ostream & stream) override;
};

#endif //FINAL_FIGHT_ACCION_H
