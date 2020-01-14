# Final Fight - Taller I

Juego multijugador similar a [Final Fight](https://es.wikipedia.org/wiki/Final_Fight) creado por [Capcom](http://www.capcom.com/). El mismo fue desarrollado como una aplicación de tipo cliente-servidor para funcionar sobre Linux.

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
    
        $ apt-get install libsdl2-dev
    
 - Valgrind:
 
        $ apt-get install valgrind

 - SLD2-Image (Carga archivos PNG)

        $ apt-get install libsdl2-image-dev
 
 - SDL True Type Font
    
        $ apt-get install libsdl2-ttf-dev
    
 - Xerces:
    
    Descargar los archivos desde [http://xerces.apache.org/xerces-c/download.cgi](http://xerces.apache.org/xerces-c/download.cgi), descomprimir y ejecutar:
    
        $ ./configure
        $ make
        $ sudo make install

 - SDL2 Mixer:

        $ apt-get install libsdl2-mixer-dev
    
 - Debug librería estándar (opcional):
 
        $ apt-get install libstdc++6-8-dbg

