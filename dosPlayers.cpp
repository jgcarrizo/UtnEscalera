#include <iostream>
#include <cstdlib>
#include <time.h>
#include "rlutil.h"

#include "prototipos.h"

void dosPlayers( char mNombres[][21] , int vMayorPuntaje[] ){
    int jugada = 0, vEstadoJuego[2]{} , ronda = 1 , totalRondas=0;
    int vPuntoParcial[2]{} , vPuntajeTotal[2]{} , ganador = 0;
    bool hayGanador = false;

    rlutil::hidecursor();
    system("title Escalera500: 2 PLAYERS");

    ingreseNombre(mNombres, 0 );
    ingreseNombre(mNombres, 1 );
    elegirRondas( totalRondas );
    system("cls");

    while ( !hayGanador && (ronda<=totalRondas) ){ /// PARTIDA
        int vLanzamientos[2]{1,1} , vPuntajeRonda[2]{} , vMaxRonda[2]{};
        int p = 0 , anterior;
        vectorCero( vEstadoJuego , 2 );

        comienzoDeRonda( ronda );
        system("cls");
        interfaz2Players( mNombres, ronda, vPuntajeTotal, vLanzamientos, vMaxRonda, p , totalRondas );

        while( vLanzamientos[1]<4 && ( !hayGanador && vEstadoJuego[1]!=1) ){ /// RONDAS

            escribir( 40 , 15 , "PRESIONE ENTER PARA LOS LANZAR DADOS...");
            interfaz2Players( mNombres, ronda, vPuntajeTotal, vLanzamientos, vMaxRonda, p , totalRondas );

            while ( vLanzamientos[p]<4 && vEstadoJuego[p]==0 ){ /// LANZAMIENTOS
                if (rlutil::getkey()==1){
                    int vCant[6]{};

                    escribir( 40 , 15 , "                                       ");
                    lanzarDados( vCant , 6 );
                    determinarJugada( vCant , 6 , jugada , vPuntoParcial[p] );
                    mostrarJugada( vCant , 6 , jugada , vPuntoParcial[p] );
                    estadoDelJuego( jugada , vEstadoJuego , ganador , hayGanador , p );
                    maxPuntajeRonda( vMaxRonda , vPuntajeRonda , vPuntoParcial , p , jugada );
                    interfaz2Players( mNombres, ronda, vPuntajeTotal, vLanzamientos, vMaxRonda, p , totalRondas );

                    ++vLanzamientos[p];
                    pausaDeFinRonda( vLanzamientos , p , vEstadoJuego );
                }
            }
            sumaPuntos( vPuntajeTotal , vPuntajeRonda , p , jugada );

            system("cls");
            proximoTurno( p , vLanzamientos , vEstadoJuego, anterior );
            cambioDeTurno( ronda , p , mNombres , vLanzamientos , vPuntajeTotal , vEstadoJuego , anterior , hayGanador , totalRondas );
        }
        estadoFinJuego( hayGanador , ganador , vPuntajeTotal , vEstadoJuego );
        ronda++;
    }
    finDePartida( vEstadoJuego , mNombres , ronda, vPuntajeTotal , hayGanador , ganador );
    determinarMayorPuntaje( vPuntajeTotal , vMayorPuntaje , mNombres );
}



void pausaDeFinRonda( int vLanzamientos[] , int p , int vEstadoJuego[] ){
    if( vLanzamientos[p] == 4 && vEstadoJuego[p]!=4 ){
        do{}while(rlutil::getkey()!=1);
    }
}


void estadoDelJuego( int jugada , int vEstadoJuego[] , int &ganador , bool &hayGanador , int p ){
    if( jugada == 4 ){
        vEstadoJuego[p] = 4;
        hayGanador = true;
        ganador = p;

        festejo( 55 , 8 );
        do{}while(rlutil::getkey()!=1);
    }
    if (jugada == 1 ){
        vEstadoJuego[p] = 1;
        triste( 55 , 8 );
        do{}while(rlutil::getkey()!=1);
    }
}


void comienzoDeRonda( int ronda ){
    rlutil::hidecursor();
    marco();
    cuadro2();

    do{
        rlutil::setBackgroundColor(9);
        rlutil::setColor(15);
        escribir( 52 , 10 , "COMIENZA LA RONDA");
        mostrarInt( 60 , 11 , ronda );
        feliz( 57 , 13 );
        rlutil::setBackgroundColor(7);
        rlutil::setColor(0);
        escribir( 45 , 20 ,"PRESIONE ENTER PARA CONTINUAR...");

    } while ( rlutil::getkey()!= 1 );
    system("cls");
    rlutil::setBackgroundColor(7);
    rlutil::setColor(0);
}

void determinarMayorPuntaje( int vPuntajeTotal[] , int vMayorPuntaje[] , char mNombres[][21] ){
    if( (vPuntajeTotal[0] == vPuntajeTotal[1]) || (vPuntajeTotal[0] >= 500 && vPuntajeTotal[1] >= 500) ){
        vMayorPuntaje[0] = vPuntajeTotal[0];
        vMayorPuntaje[1] = vPuntajeTotal[1];
    }  else {

        if( vPuntajeTotal[0] > vPuntajeTotal[1] ){
            vMayorPuntaje[0] = vPuntajeTotal[0];
            vMayorPuntaje[1] = vPuntajeTotal[1];
        } else if( vPuntajeTotal[1] > vPuntajeTotal[0] ){
            char vNombre[12];
            vMayorPuntaje[0] = vPuntajeTotal[1];
            strcpy( vNombre , mNombres[0] );
            strcpy( mNombres[0] , mNombres[1] );
            vMayorPuntaje[1] = vPuntajeTotal[0];
            strcpy( mNombres[1] , vNombre );
        }
    }
}


void finDePartida( int vEstadoJuego[] , char mNombres[][21] , int ronda , int vPuntajeTotal[] , bool hayGanador , int &ganador ){
    rlutil::hidecursor();
    marco();
    cuadro3();

    switch( vEstadoJuego[ganador] ){
        case 4:
            do {
                rlutil::setBackgroundColor(11);
                rlutil::setColor(0);
                escribir( 45 , 9 , mNombres[ganador] );
                rlutil::setBackgroundColor(9);
                rlutil::setColor(15);
                escribir( 45 , 11 , "FELICIDADES!!");
                escribir( 45 , 12 , "GANASTE CON ESCALERA!");
                escribir( 45 , 15 , "CANTIDAD DE RONDAS: " , ronda-1 );
                rlutil::setBackgroundColor(7);
                rlutil::setColor(0);
                escribir( 42 , 20 ,"PRESIONE ENTER PARA CONTINUAR...");
                festejo( 55 , 4 );
            } while ( rlutil::getkey()!=1 );
        break;
        case 10:
            do {
                rlutil::setBackgroundColor(11);
                rlutil::setColor(0);
                escribir( 45 , 9 , mNombres[ganador] );
                rlutil::setBackgroundColor(9);
                rlutil::setColor(15);
                escribir( 45 , 11 , "FELICIDADES!!");
                escribir( 45 , 12 , "GANASTE LA PARTIDA!");
                escribir( 45 , 13 , "PUNTOS: " , vPuntajeTotal[ganador] );
                escribir( 45 , 15 , "CANTIDAD DE RONDAS: " , ronda-1 );
                rlutil::setBackgroundColor(7);
                rlutil::setColor(0);
                escribir( 42 , 20 ,"PRESIONE ENTER PARA CONTINUAR...");
                festejo( 55 , 4 );
            } while ( rlutil::getkey()!=1 );
        break;
        case 11:
            do{
                rlutil::setBackgroundColor(11);
                rlutil::setColor(0);
                escribir( 54 , 9 , "EMPATE!");
                rlutil::setBackgroundColor(9);
                rlutil::setColor(15);
                escribir( 45 , 13 , "CANTIDAD DE RONDAS: " , ronda-1 );
                rlutil::setBackgroundColor(7);
                rlutil::setColor(0);
                escribir( 42 , 20 ,"PRESIONE ENTER PARA CONTINUAR...");
            } while ( rlutil::getkey()!=1 );

        break;
        case 12:
            do {
                rlutil::setBackgroundColor(11);
                rlutil::setColor(0);
                escribir( 45 , 9 , mNombres[ganador] );
                rlutil::setBackgroundColor(9);
                rlutil::setColor(15);
                escribir( 45 , 12 , "GANA POR MAYOR PUNTAJE!");
                escribir( 45 , 15 , "CANTIDAD DE RONDAS: " , ronda-1 );
                rlutil::setBackgroundColor(7);
                rlutil::setColor(0);
                escribir( 42 , 20 ,"PRESIONE ENTER PARA CONTINUAR...");
            } while ( rlutil::getkey()!=1 );
        break;
    }
    system("cls");
}


void ingreseNombre(char m[][21], int p ){

    rlutil::hidecursor();
    marco();
    cuadro();
    rlutil::setBackgroundColor(9);
    rlutil::setColor(15);
    escribir(56 , 7 , "PLAYER ", p+1 );
    escribir(51 , 9 , "INGRESE SU NOMBRE: " );
    rlutil::setBackgroundColor(9);
    escribir(50 , 12 , "--------------------" );
    rlutil::locate(50,11);
    cargarCadena( m[p], 21 );
    rlutil::setBackgroundColor(7);
    system("cls");
}


void elegirRondas( int &totalRondas ){
    int v[10]{ 06 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 };
    int i=0;
    bool enter = false;

    cuadro2();
    rlutil::setBackgroundColor(9);
    rlutil::setColor(15);
    escribir( 44 , 10 , "SELECCIONE LA CANTIDAD DE RONDAS:" );
    rlutil::setBackgroundColor(1);
    rlutil::setColor(15);
    rlutil::locate(56 , 14 );
    std::cout<< " "<< (char)174 << " ";
    rlutil::locate(61 , 14 );
    std::cout<< " " << (char)175 << " " ;
    rlutil::setBackgroundColor(7);
    rlutil::setColor(0);
    escribir( 45 , 20 ,"PRESIONE ENTER PARA CONTINUAR...");

    do{
        rlutil::setBackgroundColor(15);
        rlutil::setColor(1);
        escribir(59 , 14 , "  ");
        mostrarInt(59 , 14 , v[i]);
        switch(rlutil::getkey()){
            case 17:
                rlutil::setBackgroundColor(15);
                rlutil::setColor(1);
                escribir(59 , 14 , "  ");
                if(  (i+1)<=9 ){
                    i++;
                }
                else{
                    i=0;
                }

            break;
            case 16:
                rlutil::setBackgroundColor(15);
                rlutil::setColor(1);
                escribir(59 , 14 , "  ");
                if( (i-1) >= 0 ){
                   i--;
                } else {
                    i=9;
                }

            break;
            case 1:
                enter = true;
                totalRondas = v[i];
            break;
        }
    } while( !enter );
    system("cls");
    rlutil::setBackgroundColor(7);
    rlutil::setColor(0);
}


void interfaz2Players( char mNombres[][21], int ronda, int vPuntajeTotal[], int vLanzamientos[], int vMaxParcial[], int p , int totalRondas){
    marcoPartida1();
    rlutil::hidecursor();
    escribir( 4 , 3 , "TURNO DE: " , mNombres , p );
    rlutil::locate( 54 , 3 );
    std::cout<< "RONDA: " << ronda << "/" << totalRondas <<std::endl;
    escribir( 86 , 3 , "PUNTAJE TOTAL: " , vPuntajeTotal[p] , " PUNTOS" );
    escribir( 3 , 5 , "MAXIMO PUNTAJE DE LA RONDA: " , vMaxParcial[p] );
    escribir( 3 , 6 , "LANZAMIENTO " , vLanzamientos[p] , "/3" );
}



void estadoFinJuego( bool &hayGanador , int &ganador, int vPuntajeTotal[] , int vEstadoJuego[] ){
    int cantGanadores = 0;

    if( (vEstadoJuego[0]!=4) && (vEstadoJuego[1]!=4)){

        for ( int i=0 ; i<2 ; i++ ){
            if ( vPuntajeTotal[i] >= 500 ){
                cantGanadores++;
                hayGanador = true;
                ganador = i;
            }
        }

        if( vPuntajeTotal[0] == vPuntajeTotal[1] ){
            cantGanadores = 2;
        }

        if( cantGanadores == 0 ){
            if( vPuntajeTotal[0]>vPuntajeTotal[1] ){
                ganador = 0;
            } else if( vPuntajeTotal[1]>vPuntajeTotal[0] ){
                ganador = 1;
            }
        }

        switch ( cantGanadores ){
            case 0:
                vEstadoJuego[ganador] = 12;
            break;
            case 1:
                vEstadoJuego[ganador] = 10;
            break;
            case 2:
                vEstadoJuego[0] = 11;
                vEstadoJuego[1] = 11;
            break;

        }
    }
}

void proximoTurno( int &p , int vLanzamientos[] , int vEstadoJuego[], int &anterior ){
    if( vLanzamientos[0]==4 || vEstadoJuego[0]==1 ){
        p = 1;
        anterior=0;
    }
    if( vLanzamientos[1]==4 || vEstadoJuego[1]==1 ){
        p = 0;
        anterior=1;
    }
}

void cambioDeTurno( int ronda , int p , char mNombres[][21] , int vLanzamientos[], int vPuntajeTotal[], int vEstadoJuego[] , int anterior , bool hayGanador , int totalRondas ){

    if ( ((vLanzamientos[0] == 4 || vLanzamientos[1] == 4) || ( vEstadoJuego[anterior]==1 ) )&& !hayGanador ){

        system("cls");
        rlutil::hidecursor();
        marco();
        do{
            cuadro2();
            rlutil::setBackgroundColor(9);
            rlutil::setColor(15);
            escribir( 57 , 9 , "RONDA " , ronda );
            if( (ronda != totalRondas) || (p == 1) ){
                rlutil::setColor(11);
                escribir( 43 , 11 , "PROXIMO TURNO: ", mNombres , p );
            } else {
                escribir( 45 , 11 , "FIN DEL JUEGO");
            }
            rlutil::setColor(15);
            rlutil::locate( 43 , 14 );
            std::cout<< "PUNTAJE DE "<< mNombres[0] << ": "<< vPuntajeTotal[0] << std::endl;
            rlutil::locate( 43 , 15 );
            std::cout<< "PUNTAJE DE "<< mNombres[1] << ": "<< vPuntajeTotal[1] << std::endl;
            rlutil::setBackgroundColor(7);
            rlutil::setColor(0);
            escribir( 45 , 20 , "PRESIONE ENTER PARA CONTINUAR...");
        } while ( rlutil::getkey() != 1 );

        vLanzamientos[0]=1;
        system("cls");
    }

}


