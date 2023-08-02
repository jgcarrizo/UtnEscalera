#include <iostream>
#include <cstdlib>
#include <time.h>
#include "rlutil.h"

#include "prototipos.h"


void unPlayer( char mNombres[][21] , int vMayorPuntaje[] ){
    int jugada = 0, puntajeTotal=0, ronda=1 , totalRondas=0;
    int puntoParcial=0;
    bool esGanador = false;

    rlutil::hidecursor();
    system("title Escalera500: 1 PLAYER");
    marco();

    ingreseNombre( mNombres , 0 );
    system("cls");
    elegirRondas( totalRondas );
    system("cls");

    while ( !esGanador && (ronda<=totalRondas) ) {
        int lanzamientos=1;
        int puntajeRonda = 0 , maxRonda = 0;

        interfazUnPlayer( mNombres, ronda, puntajeTotal, lanzamientos, maxRonda , totalRondas );
        escribir( 40 , 15 , "PRESIONE ENTER PARA LOS LANZAR DADOS...");
        do {
            jugada=0;
            if (rlutil::getkey()==1){
                int vCant[6];

                escribir( 40 , 15 , "                                       ");
                lanzarDados( vCant , 6 );
                determinarJugada( vCant , 6 , jugada , puntoParcial );
                mostrarJugada( vCant , 6 , jugada , puntoParcial );
                maxPuntajeRonda( maxRonda , puntajeRonda , puntoParcial , jugada );

                interfazUnPlayer( mNombres, ronda, puntajeTotal, lanzamientos, maxRonda , totalRondas );

                ++lanzamientos;
                avisoDeFin( lanzamientos , jugada );
            }
        } while ( (lanzamientos<4) && (jugada!=4 && jugada!=1) );

        pausaJugadaClave( jugada );
        sumaPuntos( puntajeTotal , puntajeRonda , jugada );
        system("cls");
        finDeRonda( mNombres , puntajeTotal, ronda , jugada);

        ronda++;
        system("cls");
        determinarEsGanador( esGanador, jugada , puntajeTotal );
    }
    finDePartida( esGanador, jugada , mNombres , ronda, puntajeTotal );
    vMayorPuntaje[0] = puntajeTotal;
}



/// -  INTERFAZ  - ///
void interfazUnPlayer( char mNombres[][21], int ronda, int puntajeTotal, int lanzamientos, int puntajeRonda , int totalRondas ){

    rlutil::hidecursor();
    marcoPartida1();
    escribir( 4 , 3 , "TURNO DE: " , mNombres , 0 );
    rlutil::locate( 54 , 3 );
    std::cout<< "RONDA " << ronda << "/" << totalRondas << std::endl;
    escribir( 86 , 3 , "PUNTAJE TOTAL: " , puntajeTotal , " PUNTOS" );
    escribir( 3 , 5 , "MAXIMO PUNTAJE DE LA RONDA: " , puntajeRonda );
    escribir( 3 , 6 , "LANZAMIENTOS " , lanzamientos , "/3" );
}


/// -  CARTEL DE FIN DE RONDA  - ///
void finDeRonda( char mNombres[][21], int puntos, int ronda , int jugada ){
    rlutil::hidecursor();
    if( jugada != 4 ){
        marco();
        do{
            cuadro2();
            rlutil::setBackgroundColor(9);
            rlutil::setColor(15);
            escribir( 57 , 10 , "RONDA " , ronda );
            rlutil::locate( 43 , 13 );
            std::cout<< "PUNTAJE DE "<< mNombres[0] << ": "<< puntos << std::endl;
            rlutil::setBackgroundColor(7);
            rlutil::setColor(0);
            escribir( 44 , 20 , "PRESIONE ENTER PARA CONTINUAR..." );

        } while ( rlutil::getkey() != 1 );
        system("cls");
    }

}

/// -  DETERMINAR SI HAY GANADOR  - ///
void determinarEsGanador( bool &esGanador, int j, int p ){
    if ( j== 4 || p >= 500 ){
        esGanador = true;
    }
}

/// -  CARTEL DE FIN DE PARTIDA  - ///
void finDePartida( bool esGanador, int jugada, char mNombres[][21] , int ronda , int puntos ){
    system("cls");
    rlutil::hidecursor();
    marco();
    cuadro3();
    if (esGanador){
        if( jugada == 4 ){
            do{
                rlutil::setBackgroundColor(11);
                rlutil::setColor(0);
                mostrarNombre( 47 , 9 , mNombres , 0 );
                rlutil::setBackgroundColor(9);
                rlutil::setColor(15);
                escribir( 47 , 11 , "FELICIDADES!!" );
                escribir( 47 , 13 , "GANASTE CON ESCALERA!!! " );
                escribir(47 , 15 , "EN " , ronda-1 , " RONDAS" );
                rlutil::setBackgroundColor(7);
                rlutil::setColor(0);
                escribir( 42 , 20 , "PRESIONE ENTER PARA CONTINUAR..." );
                festejo( 55 , 4 );

            } while ( rlutil::getkey() != 1 );
        }
        if( puntos >= 500 ){
            do{
                rlutil::setBackgroundColor(11);
                rlutil::setColor(0);
                mostrarNombre( 47 , 9 , mNombres , 0 );
                rlutil::setBackgroundColor(9);
                rlutil::setColor(15);
                escribir( 47 , 11 , "GANASTE LA PARTIDA!" );
                escribir( 47 , 13 , "CON ", puntos , " PUNTOS" );
                escribir(47 , 15 , "EN " , ronda-1 , " RONDAS" );
                rlutil::setBackgroundColor(7);
                rlutil::setColor(0);
                escribir( 42 , 20 , "PRESIONE ENTER PARA CONTINUAR..." );
                festejo( 55 , 4 );

            } while ( rlutil::getkey() != 1 );
        }
    } else {
        do{
            rlutil::setBackgroundColor(11);
            rlutil::setColor(0);
            mostrarNombre( 47 , 9 , mNombres , 0 );
            rlutil::setBackgroundColor(9);
            rlutil::setColor(15);
            escribir( 47 , 11 , "SUERTE PARA LA PROXIMA!" );
            escribir(47 , 13 , "PUNTOS ALCANZADOS " , puntos );
            rlutil::setBackgroundColor(7);
            rlutil::setColor(0);
            escribir( 42 , 20 , "PRESIONE ENTER PARA CONTINUAR..." );
            triste( 55 , 4 );
        } while ( rlutil::getkey() != 1 );
    }

    system("cls");
}


void avisoDeFin( int lanzamientos , int jugada ){
    if ( lanzamientos==4 && jugada!=4){
        do{
           escribir( 50, 6, "FIN DE LA RONDA");
            rlutil::setColor(5);
            monstruo( 54 , 8 );
        } while ( rlutil::getkey() != 1 );
    }
}


void pausaJugadaClave( int jugada ){
    if( jugada == 4){
        festejo( 55 , 8 );
        do{}while(rlutil::getkey()!=1);
    }
    if(jugada == 1){
        triste( 55 , 8 );
       do{}while(rlutil::getkey()!=1);
    }
}
