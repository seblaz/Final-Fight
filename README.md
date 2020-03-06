# Final Fight

Juego multijugador similar a [Final Fight](https://es.wikipedia.org/wiki/Final_Fight) creado por [Capcom](http://www.capcom.com/). El mismo fue desarrollado como una aplicación de tipo cliente-servidor para funcionar sobre Linux.

Tested on Ubuntu 20.04 with gcc 9.2.1

<p align="center">
    <img alt="caminando" src="assets/screenshots/caminando.png"/>
</p>

## Capturas de pantalla

<p align="center">
    <img alt="usuario" src="assets/screenshots/usuario.png"/>
</p>

<p align="center">
    <img alt="personajes" src="assets/screenshots/personajes.png"/>
</p>

<p align="center">
    <img alt="efectua golpe poison" src="assets/screenshots/efectua golpe poison.png"/>
</p>

<p align="center">
    <img alt="recibe golpe boss" src="assets/screenshots/recibe golpe boss.png"/>
</p>

## Prerequisitos:

 - SDL2:
 - Valgrind:
 - SLD2-Image (Carga archivos PNG)
 - SDL True Type Font
 - Xerces:
 - SDL2 Mixer:
 - Debug librería estándar (opcional):

       $ make dep

# Build

       mkdir build
       cd build
       cmake ..
       make

# Server

       ./server

# Client

       ./client 127.0.0.1  5000

# Format

       sudo apt install indent
       make format

# User/Pass

[Configuracion.xml](Configuracion.xml)

