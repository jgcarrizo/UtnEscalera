#include <iostream>
#include <time.h>
#include "rlutil.h"

#include "prototipos.h"

int main(){
    int opcion, vMayorPuntaje[2]{} , vPuntajesRanking[3]{};
    char mNombres[2][21]{} , mNombresRanking[3][21]{};

    do {
        opcion = menuPrincipal();
        rlutil::cls();

        switch ( opcion ){

            case 1:
                unPlayer( mNombres , vMayorPuntaje );
                rlutil::cls();
                actualizarRanking( vMayorPuntaje , mNombres , vPuntajesRanking , mNombresRanking );

            break;
            case 2:
                dosPlayers( mNombres, vMayorPuntaje );
                rlutil::cls();
                actualizarRanking( vMayorPuntaje , mNombres , vPuntajesRanking , mNombresRanking );

            break;
            case 3:
                ranking( vPuntajesRanking , mNombresRanking );
                rlutil::cls();

            break;
            case 0:
                salirDelJuego();
            break;
        }
    } while ( opcion != 0 );

	return 0;
}
