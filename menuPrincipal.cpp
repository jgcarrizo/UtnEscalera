#include <iostream>
#include <time.h>
#include "rlutil.h"

#include "prototipos.h"

int menuPrincipal(){
    int opcion = 1;
    bool pulsoEnter = false;

    system("title Escalera500: Menu Principal");
    system("color 70");

    rlutil::hidecursor();
    marco();
    quinientos();

    opcionUnPlayer();
    opcionDosPlayers();
    opcionRanking();
    opcionSalir();

    int x=0;

    while( !pulsoEnter ){
        rlutil::setBackgroundColor(10);
        rlutil::setColor(15);
        escribir( 15+x , 19, " <<|       |>> " );

        switch( rlutil::getkey() ){
            case 16:
            moverIzquierda(x);
            break;
            case 17:
                moverDerecha(x);
            break;
            case 1:
                pulsoEnter = true;
                switch (x) {
                    case 0:
                       opcion = 1;
                    break;
                    case 25:
                       opcion = 2;
                    break;
                    case 50:
                       opcion = 3;
                    break;
                    case 75:
                       opcion = 0;
                    break;
                }
            break;
        }
    }
    system("color 70");
    return opcion;
}


void opcionUnPlayer(){
    rlutil::setColor(0);
    escribir( 18 , 13, "1  PLAYER" );
    rlutil::setColor(rlutil::BLUE);
    monstruo(19, 15);
}

void opcionDosPlayers(){
    rlutil::setColor(0);
    escribir( 43 , 13, "2  PLAYERS" );
    rlutil::setColor(0);
    monstruo(40, 15);
    rlutil::setColor(1);
    monstruo(48, 15);
}

void opcionRanking(){
    rlutil::setColor(0);
    escribir( 69 , 13, "RANKING" );
    copaRanking(69, 15);
}

void opcionSalir(){
    rlutil::setColor(0);
    escribir( 95 , 13, "SALIR" );
    salir(95, 15);
}

void moverIzquierda( int &x ){
    rlutil::setBackgroundColor(7);
    escribir( 15+x , 19, "               " );
    x-=25;

    if ( x < 0 ) {
        x = 0;
    }
}

void moverDerecha( int &x ){
    rlutil::setBackgroundColor(7);
    escribir( 15+x , 19, "               " );
    x+=25;

    if ( x > 75 ) {
        x = 75;
    }
}
