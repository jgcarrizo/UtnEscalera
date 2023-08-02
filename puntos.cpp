#include <iostream>
#include <cstdlib>
#include <time.h>
#include "rlutil.h"

#include "prototipos.h"


void generarDados( int v[], int t ){

    srand(time(NULL));
    for ( int i=0 ; i<t ; i++ ){

        v[i] = 1 + rand()% t;
    }

/*
    int x = 1 + rand()% 10;
    if( x == 4 ){
        for ( int i=0 ; i<t ; i++ ){
            v[i] = 6;
        }
    } else {
        srand(time(NULL));
        for ( int i=0 ; i<t ; i++ ){

            v[i] = 1 + rand()% t;
        }
    }
*/
}

void vectorCero( int v[], int t ){
    for( int i=0 ; i<t ; i++ ){
        v[i]=0;
    }
}

void contarRep(int v[], int c[], int t){
    vectorCero( c , t );

    for ( int i=0 ; i<t ; i++ ){
        c[v[i]-1]++;
    }
}

void lanzarDados( int vCant[] , int t ){
    int vDados[6];
    vectorCero( vDados , 6 );
    generarDados(vDados, 6);
    dibujarDado( vDados);
    contarRep(vDados, vCant, 6);
}

////////////////// COMBINACIONES GANADORAS  ///////////////////////
void sexteto6( int vCant[] , int &jugada ){ /// 1 - SEXTETO 6
    if ( vCant[5] == 6 ) {
        jugada=1;
        return;
    }
}

int sumaDados( int vCant[] , int t  ){ /// 2 - SUMA DE DADOS
    int i=0;
    int condicion2=0;
    bool suma=true;

    while( suma && i<6 ){
        if ( vCant[i]>=3 ){
            suma=false;
        }
        i++;
    }

    if (suma){
        for( int i=0 ; i<t ; i++ ){
            condicion2+= vCant[i]*(i+1);
        }
    }
    return condicion2;
}


int trioX( int vCant[] , int t ){ /// 3 - TRIO X
    bool trio=false;
    int x=0 , condicion3=0;

    for ( int i=0 ; i<t ; i++ ){
        if ( vCant[i]>=3 && vCant[i]<t){
            trio=true;
            x=i+1;
        }
    }
    if ( trio ){
        condicion3= x*10;
    }
    return condicion3;
}

void escalera ( int vCant[] , int t , int &jugada ){ /// 4 - ESCALERA
    bool escalera=true;
    int i=0;
    while( escalera && i<t ){
        if ( vCant[i]!=1 ){
            escalera=false;
        }
        i++;
    }
    if (escalera){
        jugada=4;
        return;
    }
}

int sexteto( int vCant[] ){ /// 5 - SEXTETO X
    int i=0 , x=0 , condicion5=0;
    bool sexteto=false;
    while( !sexteto && i<5 ){
        if ( vCant[i]==6 ){
            sexteto=true;
            x=i+1;
        }
        i++;
    }
    if (sexteto){
        condicion5 = 50* x;
    }
    return condicion5;
}



//// ------------ DETERMINAR JUGADA -------------- ///
void determinarJugada( int vCant[], int t, int &jugada , int &puntos ){
    int mejorPunto = 0 , mejorJugada = 0;
    jugada = 0;
    sexteto6( vCant , jugada );
    escalera( vCant , t , jugada );

    if ( sexteto( vCant ) > mejorPunto ){
        mejorJugada = 5;
        mejorPunto = sexteto( vCant );
    }

    if ( sumaDados( vCant , t ) > mejorPunto ){
        mejorJugada = 2;
        mejorPunto = sumaDados( vCant , t );
    }

    if ( trioX( vCant , t ) > mejorPunto ) {
        mejorJugada = 3;
        mejorPunto = trioX( vCant , t );
    }

    if ( jugada != 4 && jugada != 1 ){
        puntos = mejorPunto;
        jugada = mejorJugada;
    }

}

/// --------- MOSTRAR POR PANTALLA JUGADA Y PUNTOS ------- ///
void mostrarJugada( int vCant[] , int t , int jugada , int puntos ){
    escribir( 4 , 11 , "                                    " );
    switch(jugada){

        case 1:
            rlutil::setBackgroundColor(1);
            rlutil::setColor(15);
            escribir( 4 , 11 , "SEXTETO6! PIERDE LOS PUNTOS DE LA RONDA :C " );
            rlutil::setBackgroundColor(7);
        break;
        case 2:
            rlutil::setBackgroundColor(1);
            rlutil::setColor(15);
            rlutil::locate( 4, 11 );
            std::cout<< "SUMA DE DADOS: "<< puntos << " PUNTOS"<< std::endl;
            rlutil::setBackgroundColor(7);
        break;
        case 3:
            int x;
            for ( int i=0 ; i<t ; i++ ){
                if ( vCant[i]>=3 && vCant[i]<t){
                    x=i+1;
                }
            }
            rlutil::setBackgroundColor(1);
            rlutil::setColor(15);
            rlutil::locate( 4, 11 );
            std::cout<< "TRIO"<< x <<": "<< puntos << " PUNTOS        "<< std::endl;
            rlutil::setBackgroundColor(7);
        break;
        case 4:
            rlutil::setBackgroundColor(1);
            rlutil::setColor(15);
            escribir( 4 , 11 , "ESCALERA! GANA LA PARTIDA" );
            rlutil::setBackgroundColor(7);
        break;
        case 5:
            int s;
            for ( int i=0 ; i<t ; i++ ){
                if ( vCant[i]== 6 ){
                    s=i;
                }
            }
            rlutil::setBackgroundColor(1);
            rlutil::setColor(15);
            rlutil::locate( 4, 11 );
            std::cout<< "SEXTETO"<< s+1 <<": "<< puntos << " PUNTOS"<< std::endl;
            rlutil::setBackgroundColor(7);
        break;

    }

}


/// ------ SUMA DE PUNTOS --- ///

// -- 1 PLAYER -- //

void maxPuntajeRonda( int &maxRonda , int &puntajeRonda , int parciales , int jugada  ){

    if ( jugada!= 4 ){
        if( jugada != 1 ){
            if( parciales > puntajeRonda ){
                maxRonda = parciales;
            }
            puntajeRonda = maxRonda;
        } else {
            puntajeRonda = 0;
        }
    }

}

void sumaPuntos(int &total, int &puntajeRonda , int jugada ){

    if ( jugada!= 4 ){
        total+=puntajeRonda;
    }
}


// -- 2 PLAYERS -- //

void maxPuntajeRonda( int maxRonda[] , int puntajeRonda[] , int parciales[] , int p , int jugada ){

    if ( jugada!= 4 ){
        if( jugada != 1 ){
            if( parciales[p] > puntajeRonda[p] ){
                maxRonda[p] = parciales[p];
            }
            puntajeRonda[p] = maxRonda[p];
        } else {
            puntajeRonda[p] = 0;
        }
    }

}

void sumaPuntos(int total[] , int puntajeRonda[] , int p  , int jugada ){

    if ( jugada!= 4 ){
        total[p]+=puntajeRonda[p];
    }
}


