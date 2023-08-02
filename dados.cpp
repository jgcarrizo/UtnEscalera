#include <iostream>
#include <time.h>
#include "rlutil.h"

#include "prototipos.h"

void sombra1( int &x , int &y ){
    rlutil::setColor(rlutil::DARKGREY);
    rlutil::locate( x , y );
    std::cout<<(char)220 << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)219 << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)219 << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)219 << std::endl;
    x++;
    y-=3;
}
void sombra2( int &x , int &y ){
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::setColor(rlutil::DARKGREY);
    rlutil::locate( --x , ++y );
    std::cout<< (char)223<< (char)223<< (char)223<< (char)223<< (char)223<< (char)223<< (char)223<< std::endl;
}



void seis( int x , int y ){
    sombra1( x , y );
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate( x , y );
    std::cout<< (char)177<< " "<<(char)254<<"   "<<(char)254<<" " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< " "<<(char)254<<"   "<<(char)254<<" " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< " "<<(char)254<<"   "<<(char)254<<" " << std::endl;
    sombra2( x , y );
}

void uno ( int x , int y ){
    sombra1( x , y );
    rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate( x , y );
    std::cout<< (char)177<< "       " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< "   "<<(char)254<<"   " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< "       " << std::endl;
    sombra2( x , y );
}

void dos( int x , int y ){
    sombra1( x , y );
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate( x , y );
    std::cout<< (char)177<< " "<<(char)254<<"     " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< "       " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< "     "<<(char)254<<" " << std::endl;
    sombra2( x , y );
}

void tres( int x , int y ){
    sombra1( x , y );
    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate( x , y );
    std::cout<< (char)177<< "     " <<(char)254 << " " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< "   "<<(char)254 <<"   " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< " " <<(char)254 << "     " << std::endl;
    sombra2( x , y );
}

void cuatro( int x , int y ){
    sombra1( x , y );
    rlutil::setBackgroundColor(rlutil::LIGHTRED);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate( x , y );
    std::cout<< (char)177<< " "<<(char)254<<"   "<<(char)254<<" " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< "       " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< " "<<(char)254<<"   "<<(char)254<<" " << std::endl;
    sombra2( x , y );
}


void cinco( int x , int y ){
    sombra1( x , y );
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate( x , y );
    std::cout<< (char)177<< " "<<(char)254<<"   "<<(char)254<<" " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< "   " <<(char)254<< "   " << std::endl;
    rlutil::locate( x , ++y );
    std::cout<< (char)177<< " "<<(char)254<<"   "<<(char)254<<" " << std::endl;
    sombra2( x , y );
}

void borrarDados(){
    int posX=7;
    for( int i=0 ; i<7 ; i++){
        rlutil::setColor(8);
        for( int y=14 ; y<28 ; y++ ){
            escribir( posX , y , "                 ");
        }
        posX+=16;
    }
}

void dibujarDado( int vDados[] ){
    int x , y;
    srand(time(NULL));
    x=7;
    borrarDados();

    for( int i=0 ; i<6 ; i++ ){
        switch ( vDados[i] ){
            case 1:
                y= 15 + rand()% 8;
                uno( x , y );
            break;
             case 2:
                y= 15 + rand()% 8;
                dos( x , y );
            break;
             case 3:
                y= 15 + rand()% 8;
                tres( x , y );
            break;
             case 4:
                y= 15 + rand()% 8;
                cuatro( x , y );
            break;
             case 5:
                y= 15 + rand()% 8;
                cinco( x , y );
            break;
             case 6:
                y= 15 + rand()% 8;
                seis( x , y );
            break;
        }
        x+=14 + rand()% 6;
    }
}

