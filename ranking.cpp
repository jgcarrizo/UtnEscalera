#include <iostream>
#include <string.h>
#include "rlutil.h"

#include "prototipos.h"

void ranking( int vPuntajesRanking[] , char mNombresRanking[][21] ){
    system("title Escalera500: RANKING");

    do {
        marco();
        rlutil::setBackgroundColor(15);
        rlutil::setColor(1);
        escribir( 51 , 8, " R A N K I N G " );
        rlutil::setBackgroundColor(7);
        rlutil::setColor(0);
        if( vPuntajesRanking[0] > 0 ){
            escribir( 39 , 10 , "PUESTO          PUNTOS           NOMBRE" );
            escribirRanking( 41 , 12, 1 , vPuntajesRanking , mNombresRanking , 0 );
            escribirRanking( 41 , 14, 2 , vPuntajesRanking , mNombresRanking , 1 );
            escribirRanking( 41 , 16, 3 , vPuntajesRanking , mNombresRanking , 2 );
        } else {
            rlutil::setColor(4);
            escribir( 49 , 12 , " AUN NO HAS JUGADO? ");
            escribir( 38 , 13 , " PRUEBA TU SUERTE PARA ENTRAR AL RANKING! ");
        }
        copaRanking(55 , 4);
        rlutil::setBackgroundColor(10);
        rlutil::setColor(15);
        escribir( 51 , 25, " VOLVER AL MENU " );
        rlutil::setBackgroundColor(7);

    } while ( rlutil::getkey()!= 1 );

}


void escribirRanking( int x , int y , int num , int vPuntajesRanking[] , char mNombresRanking[][21] , int p ){
    rlutil::locate( x , y );
    std::cout<< "#"<< num <<"             "<< vPuntajesRanking[p] << "              " << mNombresRanking[p] << std::endl;
}

void actualizarRanking( int vMayorPuntaje[] , char mNombres[][21] , int vPuntajesRanking[] , char mNombresRanking[][21] ){
    char mVacio[2][21]={};

    for( int i=0 ; i<2 ; i++ ){
        if( vMayorPuntaje[i] > 0 ){
            if ( vMayorPuntaje[i] > vPuntajesRanking[0] ){
                vPuntajesRanking[2] = vPuntajesRanking[1];
                strcpy( mNombresRanking[2] , mNombresRanking[1] );
                vPuntajesRanking[1] = vPuntajesRanking[0];
                strcpy( mNombresRanking[1] , mNombresRanking[0] );
                vPuntajesRanking[0] = vMayorPuntaje[i];
                strcpy( mNombresRanking[0] , mNombres[i] );

            } else if ( vMayorPuntaje[i] > vPuntajesRanking[1] ){
                vPuntajesRanking[2] = vPuntajesRanking[1];
                strcpy( mNombresRanking[2] , mNombresRanking[1]);
                vPuntajesRanking[1] = vMayorPuntaje[i];
                strcpy( mNombresRanking[1] , mNombres[i] );

            } else if ( vMayorPuntaje[i] > vPuntajesRanking[2] ){
                vPuntajesRanking[2] = vMayorPuntaje[i];
                strcpy( mNombresRanking[2] , mNombres[i] );
            }
        }
    }
    strcpy( mNombres[0] , mVacio[0] );
    strcpy( mNombres[1] , mVacio[1] );

    vectorCero( vMayorPuntaje , 2 );
}

