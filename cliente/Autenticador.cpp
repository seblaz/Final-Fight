//
// Created by sebas on 30/10/19.
//

#include <SDL_events.h>
#include "Autenticador.h"
#include "../servicios/Locator.h"

void Autenticador::generarFormulario(SDL_Renderer *renderer) {

    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");

    auto *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/formulario/fondo/src");
    auto *user = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/formulario/usuario/src");
    auto *pass = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/formulario/password/src");
    auto *enter = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/formulario/enter/src");

    SDL_Rect posicionFondo = {int(ancho / 3), int(alto / 1.7), int(ancho / 3), int(alto / 2.45)};
    SDL_Rect posicionUser = {int(ancho / 2.8), int(alto / 1.45), int(ancho / 3.5), int(alto / 13)};
    SDL_Rect posicionPass = {int(ancho / 2.8), int(alto / 1.29), int(ancho / 3.5), int(alto / 13)};
    SDL_Rect posicionEnter = {int(ancho / 2.5), int(alto / 1.15), int(ancho / 5), int(alto / 14)};

    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, &posicionFondo);
    SDL_RenderCopy(renderer, user->getTexture(), nullptr, &posicionUser);
    SDL_RenderCopy(renderer, pass->getTexture(), nullptr, &posicionPass);
    SDL_RenderCopy(renderer, enter->getTexture(), nullptr, &posicionEnter);
}

Usuario *Autenticador::getUsuario(SDL_Event *e) {
    SDL_Renderer *renderer = Locator::renderer();

    if(e->type == SDL_KEYDOWN && e->key.keysym.scancode == SDL_SCANCODE_RETURN)
        return new Usuario("seba", "b");

    generarFondo(renderer);
    generarFormulario(renderer);
    SDL_RenderPresent(renderer); // Update screen

    return nullptr;
}

void Autenticador::generarFondo(SDL_Renderer *renderer) {
    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");

    auto *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/fondo/src");

    SDL_Rect posicionEnPantallaCompleta = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, &posicionEnPantallaCompleta);
}

//Usuario *Juego::generarPantallaDeIngreso(bool &contraseniaIncorrecta) {
//    Configuracion *config = Locator::configuracion();
//
//    string srcSpritePantallaIngreso = config->getValue("/pantallaDeIngreso/sprite/src");
//    string srcSpriteBotonEntrar = config->getValue("/pantallaDeIngreso/botonDeEntrar/sprite/src");
//    string srcSpriteBoxIdentificacion = config->getValue("/pantallaDeIngreso/identificacionUsuario/sprite/src");
//    string srcSpriteBoxUsr = config->getValue("/pantallaDeIngreso/boxUsuario/sprite/src");
//    string srcSpriteBoxContrasenia = config->getValue("/pantallaDeIngreso/boxContrasenia/sprite/src");
//    string srcSpriteUsuarioRechazado = config->getValue("/pantallaDeIngreso/usuarioRechazado/sprite/src");
//    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
//    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");
//    SDL_Color color = {238, 238, 238, 0};
//
//    bool usuarioSeleccionado = false;
//    bool contraseniaSeleccionada = false;
//    seleccionar_box_t boxSeleccionadaRectOk;
//    seleccionar_box_t boxSeleccionadaRectUsuario;
//    seleccionar_box_t boxSeleccionadaRectContrasenia;
//    boxSeleccionadaRectUsuario.textcolor = color;
//    boxSeleccionadaRectContrasenia.textcolor = color;
//    boxSeleccionadaRectUsuario.text = "";
//    boxSeleccionadaRectContrasenia.text = "";
//
//    Locator::logger()->log(DEBUG, "Se genera pantalla de ingreso");
//
//    auto *pantalla = new Entidad();
//
//    //Boton entrar grafico
//    auto *spriteBotonDeEntrar = Locator::fabricaDeSprites()->getSpriteBySrc(srcSpriteBotonEntrar);
//    SDL_Rect posicionEnPantallaIngresoBoton = {(int) (ancho / 2.15), (int) (alto / 1.15), (int) (ancho / 16),
//                                               (int) (alto / 14)};
//    auto *graficoBotonDeEntrar = new GraficoDeElementosPantalla(spriteBotonDeEntrar->getTexture(),
//                                                                posicionEnPantallaIngresoBoton, 1);
//
//    pantalla->agregarEstado("spriteBotonDeEntrar", spriteBotonDeEntrar);
//    pantalla->agregarComportamiento("graficoBotonDeEntrar", graficoBotonDeEntrar);
//
//    //Box usuario grafico
//    auto *spriteBoxUsuario = Locator::fabricaDeSprites()->getSpriteBySrc(srcSpriteBoxUsr);
//    SDL_Rect posicionEnPantallaIngresoUsuario = {(int) (ancho / 2.8), (int) (alto / 1.45), (int) (ancho / 3.5),
//                                                 (int) (alto / 13)};
//    auto *graficoBoxUsuario = new GraficoDeElementosPantalla(spriteBoxUsuario->getTexture(),
//                                                             posicionEnPantallaIngresoUsuario, 1);
//
//    pantalla->agregarEstado("spriteBoxUsuario", spriteBoxUsuario);
//    pantalla->agregarComportamiento("graficoBoxUsuario", graficoBoxUsuario);
//
//    auto *spriteBoxContrasenia = Locator::fabricaDeSprites()->getSpriteBySrc(srcSpriteBoxContrasenia);
//    SDL_Rect posicionEnPantallaIngresoContrasenia = {(int) (ancho / 2.8), (int) (alto / 1.3), (int) (ancho / 3.5),
//                                                     (int) (alto / 13)};
//    auto *graficoBoxContrasenia = new GraficoDeElementosPantalla(spriteBoxContrasenia->getTexture(),
//                                                                 posicionEnPantallaIngresoContrasenia, 1);
//
//    //Box Contrasenia
//
//    pantalla->agregarEstado("spriteBoxContrasenia", spriteBoxContrasenia);
//    pantalla->agregarComportamiento("graficoBoxContrasenia", graficoBoxContrasenia);
//
//    //Box identificacion grafico
//    auto *spriteBoxIdentificacion = Locator::fabricaDeSprites()->getSpriteBySrc(srcSpriteBoxIdentificacion);
//    SDL_Rect posicionEnPantallaIngresoBoxIdentificacion = {(int) (ancho / 3), (int) (alto / 1.7), (int) (ancho / 3),
//                                                           (int) (alto / 2.45)};
//    auto *graficoBoxIdentificacion = new GraficoDeElementosPantalla(spriteBoxIdentificacion->getTexture(),
//                                                                    posicionEnPantallaIngresoBoxIdentificacion, 1);
//
//    pantalla->agregarEstado("spriteBoxIdentificacion", spriteBoxIdentificacion);
//    pantalla->agregarComportamiento("graficoBoxIdentificacion", graficoBoxIdentificacion);
//
//    //Grafico usuario rechazado
//    auto *spriteUsuarioRechazado = Locator::fabricaDeSprites()->getSpriteBySrc(srcSpriteUsuarioRechazado);
//    SDL_Rect posicionEnPantallaIngresoUsuarioRechazado = {(int) (ancho / 2.45), (int) (alto / 3), (int) (ancho / 6),
//                                                          (int) (alto / 4.5)};
//    auto *graficoUsuarioRechazado = new GraficoDeElementosPantalla(spriteUsuarioRechazado->getTexture(),
//                                                                   posicionEnPantallaIngresoUsuarioRechazado, 1);
//
//    //Pantalla grafico
//    auto *spritePantallaIngreso = Locator::fabricaDeSprites()->getSpriteBySrc(srcSpritePantallaIngreso);
//    SDL_Rect posicionEnPantallaIngreso = {0, 0, ancho, alto};
//    auto *graficoPantalla = new GraficoDeElementosPantalla(spritePantallaIngreso->getTexture(),
//                                                           posicionEnPantallaIngreso, 1);
//
//    pantalla->agregarEstado("spritePantallaIngreso", spritePantallaIngreso);
//    pantalla->agregarComportamiento("graficoPantalla", graficoPantalla);
//
//    bool usuarioExit = false;
//    while (!usuarioExit) {
//        SDL_Event sdlEvento;
//        SDL_WaitEvent(&sdlEvento);
//        if (sdlEvento.type == SDL_QUIT) {
//            stringstream s;
//            Accion(FIN).serializar(s);
//            Locator::socket()->enviar(s);
//            Locator::logger()->log(INFO, "Se cierra la aplicación voluntariamente.");
//            exit = true;
//            break;
//        }
//
//        SDL_Surface *surfaceTextoUsuario;
//        SDL_Surface *surfaceTextoContrasenia;
//        SDL_Texture *textureTextoUsuario = nullptr;
//        SDL_Texture *textureTextoContrasenia = nullptr;
//        SDL_Rect posicionEnPantallaIngresoUsuarioTexto;
//        SDL_Rect posicionEnPantallaIngresoContraseniaTexto;
//        int text_height;
//        int text_width;
//
//        //Limpieza pantalla
//        clearScene();
//
//
//        //Grafico caracteres usuario
//        if (boxSeleccionadaRectUsuario.text.length()) {
//            //cout << "Se puede" << endl;
//            surfaceTextoUsuario = TTF_RenderText_Solid(font, boxSeleccionadaRectUsuario.text.c_str(),
//                                                       boxSeleccionadaRectUsuario.textcolor);
//            textureTextoUsuario = SDL_CreateTextureFromSurface(renderer_, surfaceTextoUsuario);
//            text_width = surfaceTextoUsuario->w;
//            text_height = surfaceTextoUsuario->h;
//            posicionEnPantallaIngresoUsuarioTexto = posicionEnPantallaIngresoUsuario;
//            posicionEnPantallaIngresoUsuarioTexto.w = text_width;
//            posicionEnPantallaIngresoUsuarioTexto.h = text_height;
//            posicionEnPantallaIngresoUsuarioTexto.x += (int) ancho / 14;
//            posicionEnPantallaIngresoUsuarioTexto.y += (int) alto / 72;
//            SDL_FreeSurface(surfaceTextoUsuario);
//        }
//
//
//
//        //Grafico caracteres contraseña
//        if (boxSeleccionadaRectContrasenia.text.length()) {
//            surfaceTextoContrasenia = TTF_RenderText_Solid(font, boxSeleccionadaRectContrasenia.text.c_str(),
//                                                           boxSeleccionadaRectContrasenia.textcolor);
//            textureTextoContrasenia = SDL_CreateTextureFromSurface(renderer_, surfaceTextoContrasenia);
//            text_width = surfaceTextoContrasenia->w;
//            text_height = surfaceTextoContrasenia->h;
//            posicionEnPantallaIngresoContraseniaTexto = posicionEnPantallaIngresoContrasenia;
//            posicionEnPantallaIngresoContraseniaTexto.w = text_width;
//            posicionEnPantallaIngresoContraseniaTexto.h = text_height;
//            posicionEnPantallaIngresoContraseniaTexto.x += (int) ancho / 11;
//            posicionEnPantallaIngresoContraseniaTexto.y += (int) alto / 72;
//            SDL_FreeSurface(surfaceTextoContrasenia);
//        }
//
//
//        if (contraseniaIncorrecta) {
//            pantalla->agregarEstado("spriteUsuarioRechazado", spriteUsuarioRechazado);
//            pantalla->agregarComportamiento("graficoUsuarioRechazado", graficoUsuarioRechazado);
//        } else {
//            pantalla->quitarComportamiento("graficoUsuarioRechazado");
//        }
//
//
//        //Inicializacion Boxes
//        boxSeleccionadaRectOk.rect = posicionEnPantallaIngresoBoton;
//        boxSeleccionadaRectUsuario.rect = posicionEnPantallaIngresoUsuario;
//        boxSeleccionadaRectContrasenia.rect = posicionEnPantallaIngresoContrasenia;
//
//        //Eventos
//        switch (sdlEvento.type) {
//            //case SDL_QUIT:
//            //exit = true;
//            //break;
//            case SDL_MOUSEBUTTONDOWN:
//                //Pantalla Ok seleccionada
//                if (boxSeleccionada(&boxSeleccionadaRectOk, &sdlEvento))
//                    usuarioExit = true;
//
//                //Ingreso de caracteres pantalla usuario
//                if (boxSeleccionada(&boxSeleccionadaRectUsuario, &sdlEvento)) {
//                    usuarioSeleccionado = true;
//                    contraseniaSeleccionada = false;
//                }
//
//                //Ingreso de caracteres pantalla contraseña
//                if (boxSeleccionada(&boxSeleccionadaRectContrasenia, &sdlEvento)) {
//                    contraseniaSeleccionada = true;
//                    usuarioSeleccionado = false;
//                }
//                break;
//            case SDL_TEXTINPUT:
//                //Acoplo caracteres usuario
//                if (usuarioSeleccionado && boxSeleccionadaRectUsuario.text.length() <= CANT_MAX_CARACTERES_USUARIO)
//                    boxSeleccionadaRectUsuario.text.append(sdlEvento.text.text);
//
//                //Acoplo caracteres contraseña
//                if (contraseniaSeleccionada &&
//                    boxSeleccionadaRectContrasenia.text.length() <= CANT_MAX_CARACTERES_CONTRASENIA)
//                    boxSeleccionadaRectContrasenia.text.append(sdlEvento.text.text);
//
//                break;
//            case SDL_KEYDOWN:
//
//                //Retroceso usuario
//                if (usuarioSeleccionado && sdlEvento.key.keysym.sym == SDLK_BACKSPACE &&
//                    !boxSeleccionadaRectUsuario.text.empty())
//                    boxSeleccionadaRectUsuario.text.pop_back();
//
//                    //Cambio usuario -> contraseña
//                else if (usuarioSeleccionado && sdlEvento.key.keysym.sym == SDLK_TAB) {
//                    usuarioSeleccionado = false;
//                    contraseniaSeleccionada = true;
//                }
//
//                    //Retroceso contraseña
//                else if (contraseniaSeleccionada && sdlEvento.key.keysym.sym == SDLK_BACKSPACE &&
//                         !boxSeleccionadaRectContrasenia.text.empty())
//                    boxSeleccionadaRectContrasenia.text.pop_back();
//                break;
//        }
//
//        if (!usuarioExit) {
//            //Actualizar
//            auto comportamientos = pantalla->getComportamientos();
//            for (auto *comportamiento : comportamientos) {
//                comportamiento->actualizar(pantalla);
//            }
//
//            //Graficar
//            if (textureTextoUsuario)
//                SDL_RenderCopy(renderer_, textureTextoUsuario, nullptr, &posicionEnPantallaIngresoUsuarioTexto);
//            if (textureTextoContrasenia)
//                SDL_RenderCopy(renderer_, textureTextoContrasenia, nullptr, &posicionEnPantallaIngresoContraseniaTexto);
//            SDL_RenderPresent(renderer_); // Update screen
//
//            if (contraseniaIncorrecta) {
//                SDL_Delay(1000);
//                contraseniaIncorrecta = false;
//            }
//
//            //Deletes
//            SDL_DestroyTexture(textureTextoUsuario);
//            SDL_DestroyTexture(textureTextoContrasenia);
//        }
//
//    }
//    static Usuario usr;
//    usr.setUsuario(boxSeleccionadaRectUsuario.text);
//    usr.setContrasenia(boxSeleccionadaRectContrasenia.text); //"p"
//
//    return usr;
//}
