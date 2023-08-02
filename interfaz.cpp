#include <iostream>
#include <time.h>
#include "rlutil.h"

#include "prototipos.h"

/// ------------ CARGAR CADENA ------------ ///

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);

    for (i=0; i<tamano; i++){
        palabra[i]=std::cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}


/// ------------ MOSTRAR TEXTO------------ ///
void escribir( int x , int y, std::string texto ){
    rlutil::locate(x, y);
    std::cout<< texto << std::endl;
}

/// ------------ MOSTRAR VARIABLE CHAR CONSTANTE ----------- ///
void mostrarNombre( int x , int y, char nombrePlayer[][21] ,int p ){
    rlutil::locate(x, y);
    std::cout<< nombrePlayer[p] << std::endl;
}

void escribir( int x , int y, std::string texto, char nombre[][21] ,int p ){
    rlutil::locate(x, y);
    std::cout<< texto << nombre[p] << std::endl;
}

/// ------------ MOSTRAR VARIABLE INT ------------ ///
void mostrarInt( int x , int y, int variable ){
    rlutil::locate(x, y);
    std::cout<< variable << std::endl;
}

/// ------------ MOSTRAR TEXTO Y VARIABLE INT ------------ ///
void escribir( int x , int y , std::string texto , int numero ){
    rlutil::locate( x, y );
    std::cout<< texto << numero << std::endl;
}


/// ------------ MOSTRAR TEXTO 1, VARIABLE INT, TEXTO 2 ------------ ///
void escribir( int x , int y , std::string texto1 , int num , std::string texto2 ){
    rlutil::locate( x , y );
    std::cout<< texto1 << num << texto2 << std::endl;
}


/// ------------ BICHITO ------------ ///
void monstruo( int x, int y ){
    rlutil::hidecursor();
    rlutil::locate(x,y);
    std::cout<< (char)223 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)223 << std::endl;
    rlutil::locate(++x,++y);
    std::cout<< (char)219 << (char)248 << " " << (char)248 << (char)219 << std::endl;
    rlutil::locate(x,++y);
    std::cout<< (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << std::endl;

}

/// ------------ COPA RANKING ------------ ///
void copaRanking(int x , int y ){
    rlutil::hidecursor();
    rlutil::setColor(rlutil::BROWN);
    rlutil::locate(x,y);
    std::cout<< "("<< (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << ")" << std::endl;
    rlutil::locate(x,++y);
    std::cout<< " " << (char)223 << (char)219 << (char)219 << (char)219 << (char)223 << std::endl;
    rlutil::locate(x,++y);
    std::cout<< " " << (char)220 << (char)220 << (char)219 << (char)220 << (char)220 << std::endl;

}


/// ------------ SALIR  ------------ ///

void salir( int x, int y ){
    rlutil::hidecursor();
    rlutil::setColor(rlutil::RED);
    rlutil::locate(x,y);
    std::cout<< (char)220<< (char)220 << (char)220 << (char)220 << (char)220 << std::endl;
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::GREY);
    rlutil::locate(x,++y);
    std::cout<<"  X  " << std::endl;
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::setColor(rlutil::RED);
    rlutil::locate(x,++y);
    std::cout<< (char)223<< (char)223 << (char)223 << (char)223 << (char)223 << std::endl;

}

/// ------------ TITULO DEL JUEGO  ------------ ///
void quinientos (){
    rlutil::setColor(rlutil::RED);
    escribir( 51 , 2 , "  E S C A L E R A  " );

    int x=47 , y=4;

    // ---------- CINCO ---------- //

    rlutil::setColor(rlutil::LIGHTBLUE);
    rlutil::locate( x , y );
    std::cout<< (char)219 << (char)219 << (char)223 << (char)223 << (char)223 << (char)223 << std::endl;
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate( x , ++y );
    std::cout<< (char)223 << (char)223 << (char)223 << (char)223 << (char)223 << (char)219 << (char)220 << std::endl;
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate( x , ++y );
    std::cout<< (char)220 << (char)220 << "   " << (char)219 << (char)219 << std::endl;;
    rlutil::locate( x , ++y );
    std::cout<< " " << (char)223 << (char)223 << (char)223 << (char)223 << (char)223 << std::endl;

    // ---------- CERO 1 ---------- //

    for (int i=1 ; i<=2 ; i++){
        x+=10;
        y-=3;
        rlutil::setColor(rlutil::LIGHTBLUE);
        rlutil::locate( x , y );
        std::cout<< (char)220 << (char)219 << (char)223 << (char)223 << (char)223 << (char)219 << (char)220 << std::endl;
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate( x , ++y );
        std::cout<< (char)219 << (char)219 << "   " << (char)219 << (char)219 << std::endl;
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate( x , ++y );
        std::cout<< (char)219 << (char)219 << "   " << (char)219 << (char)219 << std::endl;
        rlutil::locate( x , ++y );
        std::cout<< " " << (char)223 << (char)223 << (char)223 << (char)223 << (char)223 << std::endl;
    }

    rlutil::setColor(rlutil::MAGENTA);
    escribir( 54 , 8 , "<< G A M E >>" );
}


/// ------------ MARCO SIMPLE ------------ ///
void marco(){
    rlutil::setColor(rlutil::BLACK);

    rlutil::locate( 2 , 2 );
    std::cout << (char)201 << std::endl;
    rlutil::locate( 119 , 2 );
    std::cout << (char)187 << std::endl;
    rlutil::locate( 2 , 29 );
    std::cout << (char)200 << std::endl;
    rlutil::locate( 119 , 29 );
    std::cout << (char)188 << std::endl;

    for ( int x=3; x<=118 ; x++){
        rlutil::locate( x , 2 );
        std::cout << (char)205 << std::endl;
    }
    for ( int x=3; x<=118 ; x++){
        rlutil::locate( x , 29 );
        std::cout << (char)205 << std::endl;
    }
    for ( int y=3; y<=28 ; y++){
        rlutil::locate( 2 , y );
        std::cout << (char)186 << std::endl;
    }
    for ( int y=3; y<=28 ; y++){
        rlutil::locate( 119 , y );
        std::cout << (char)186 << std::endl;
    }
}

/// ------------ MARCO DE PARTIDA ------------ ///
void marcoPartida1(){
    marco();
    rlutil::locate( 2 , 4 );
    std::cout<< (char)204 << std::endl;
    rlutil::locate( 119 , 4 );
    std::cout<< (char)185 << std::endl;
    for ( int i=3 ; i<119 ; i++ ){
        rlutil::locate( i , 4 );
        std::cout<< (char)205 << std::endl;
    }
    rlutil::locate( 38 , 4 );
    std::cout<< (char)202 << std::endl;
    rlutil::locate( 76 , 4 );
    std::cout<< (char)202 << std::endl;

    rlutil::locate( 38 , 2 );
    std::cout<< (char)203 << std::endl;
    rlutil::locate( 76 , 2 );
    std::cout<< (char)203 << std::endl;

    rlutil::locate( 38 , 3 );
    std::cout<< (char)186 << std::endl;
    rlutil::locate( 76 , 3 );
    std::cout<< (char)186 << std::endl;

}

/// ------------ SALIR DEL JUEGO ------------ ///
int salirDelJuego(){

    system("title Escalera500: GRACIAS");
    rlutil::setColor(rlutil::MAGENTA);
    escribir( 50 , 9, "GRACIAS POR JUGAR!");
    rlutil::setColor(rlutil::LIGHTRED);
    monstruo( 55 , 11 );
    rlutil::setColor(rlutil::GREY);
    return 0;
}

/// ------------ CUADRO INGRESAR NOMBRE  ------------ ///
void cuadro(){
    for( int y=5 ; y<16 ; y++ ){
        rlutil::setBackgroundColor(9);
        for( int x=46 ; x<74 ; x++ ){
            rlutil::locate( x , y );
            std::cout<< " ";
        }

    }

    rlutil::setColor(1);
    for( int y=5 ; y<16 ; y++ ){
        for( int x=45 ; x<75 ; x++ ){
            if( y==5 ){
                rlutil::locate( x , y );
                std::cout<<(char)223;
            }

            if( y==15 ){
                rlutil::locate( x , y );
                std::cout<<(char)220;
            }
            if( x==45 || x==74 ){
                rlutil::locate( x , y );
                std::cout<<(char)219;
            }
        }
    }
    rlutil::setBackgroundColor(7);
    rlutil::setColor(0);
}

/// ------------ ELEGIR RONDAS ------------ ///
void cuadro2(){
    for( int y=7 ; y<18 ; y++ ){
        rlutil::setBackgroundColor(9);
        for( int x=40 ; x<81 ; x++ ){
            rlutil::locate( x , y );
            std::cout<< " ";
        }

    }

    rlutil::setColor(1);
    for( int y=7 ; y<18 ; y++ ){
        for( int x=40 ; x<81 ; x++ ){
            if( y==7 ){
                rlutil::locate( x , y );
                std::cout<<(char)223;
            }

            if( y==17 ){
                rlutil::locate( x , y );
                std::cout<<(char)220;
            }
            if( x==40 || x==80 ){
                rlutil::locate( x , y );
                std::cout<<(char)219;
            }
        }
    }
    rlutil::setBackgroundColor(7);
    rlutil::setColor(0);
}

/// ------------ FIN DE RONDAS ------------ ///
void cuadro3(){
    for( int y=7 ; y<18 ; y++ ){
        rlutil::setBackgroundColor(9);
        for( int x=40 ; x<77 ; x++ ){
            rlutil::locate( x , y );
            std::cout<< " ";
        }
        if( y==9 ){
            for( int x=40 ; x<77 ; x++ ){
            rlutil::locate( x , y );
            rlutil::setBackgroundColor(11);
            std::cout<< " ";
            }
            rlutil::setBackgroundColor(9);
        }

    }

    rlutil::setColor(1);
    for( int y=7 ; y<18 ; y++ ){
        for( int x=40 ; x<77 ; x++ ){
            if( y==7 ){
                rlutil::locate( x , y );
                std::cout<<(char)223;
            }

            if( y==17 ){
                rlutil::locate( x , y );
                std::cout<<(char)220;
            }
            if( x==40 || x==76 ){
                rlutil::locate( x , y );
                std::cout<<(char)219;
            }
        }
    }
    rlutil::setBackgroundColor(7);
    rlutil::setColor(0);
}
