#include <iostream>
#include "rlutil.h"

#include "prototipos.h"

void ojitos( int x , int y );
void orejitas( int x , int y );
void sonrisa( int x , int y );
void pos1( int x , int y);
void pos2( int x , int y);
void confeti( int x , int y );
void borrarConfeti( int x , int y );
void llanto1( int x , int y );
void llanto2( int x , int y );


void feliz( int x , int y ){
    for( int j=0 ; j<4 ; j++ ){
        switch(j){
            case 0:
                rlutil::setColor(5);
                orejitas( x , y );
            break;
            case 1:
                rlutil::setColor(5);
                ojitos( x , y );
            break;
            case 2:
                rlutil::setColor(5);
                orejitas( x , y );
            break;
            case 3:
                rlutil::setColor(5);
                sonrisa( x , y );
            break;
        }
        rlutil::msleep(120);
    }


    rlutil::setColor(0);
}

void festejo( int x , int y ){

    for( int i=0 ; i<3 ; i++ ){
        for( int j=0 ; j<4 ; j++ ){
            switch(j){
                case 0:
                    rlutil::setColor(5);
                    pos1( x , y );

                break;
                case 1:
                    rlutil::setColor(5);
                    pos2( x , y );
                break;
                case 2:
                    rlutil::setColor(5);
                    confeti( x , y );
                break;
                case 3:
                    rlutil::setColor(5);
                    borrarConfeti( x , y );
                break;
            }
            rlutil::msleep(160);
        }
        rlutil::msleep(160);
    }
    rlutil::setColor(0);
}

void triste( int x , int y ){
    for( int i=0 ; i<2 ; i++ ){
        for( int j=0 ; j<3 ; j++ ){
            rlutil::setBackgroundColor(7);
            switch(j){
                case 0:
                    rlutil::setColor(5);
                    llanto1( x , y );

                break;
                case 1:
                    rlutil::setColor(5);
                    llanto2( x , y );
                break;
            }
            rlutil::msleep(160);
        }
       rlutil::msleep(160);
    }
    rlutil::setColor(0);
}

void ojitos( int x , int y ){
    rlutil::setBackgroundColor(9);
    rlutil::hidecursor();
    rlutil::locate(x,y);
    std::cout<< (char)223 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)223 << std::endl;
    rlutil::locate(++x,++y);
    rlutil::setBackgroundColor(7);
    std::cout<< (char)219 << "^-^" << (char)219 << std::endl;
    rlutil::locate(x,++y);
    std::cout<< (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << std::endl;
    rlutil::setBackgroundColor(9);
}

void orejitas( int x , int y ){
    rlutil::setBackgroundColor(9);
    rlutil::saveDefaultColor();
    rlutil::hidecursor();
    rlutil::locate(x,y);
    std::cout<< (char)254 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)254 << std::endl;
    rlutil::locate(++x,++y);
    rlutil::setBackgroundColor(7);
    std::cout<< (char)219 << (char)248 << "-" << (char)248 << (char)219 << std::endl;
    rlutil::locate(x,++y);
    std::cout<< (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << std::endl;
    rlutil::locate(x-2,++y);
    rlutil::setBackgroundColor(10);
    rlutil::setColor(2);
    std::cout<<",//,//,//"<< std::endl;
    rlutil::resetColor();
    rlutil::setBackgroundColor(9);
}

void sonrisa( int x , int y ){
    rlutil::setBackgroundColor(9);
    rlutil::hidecursor();
    rlutil::locate(x,y);
    std::cout<< (char)223<< (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)223 << std::endl;
    rlutil::locate(++x,++y);
    rlutil::setBackgroundColor(7);
    std::cout<< (char)219 << "^-^" << (char)219 << std::endl;
    rlutil::locate(x,++y);
    std::cout<< (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << std::endl;
}

void pos1( int x , int y ){
    rlutil::hidecursor();
    rlutil::locate(x,y);
    std::cout<< (char)223 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)223 << std::endl;
    rlutil::locate(x,++y);
    std::cout<< (char)'(' << (char)219 << "^ ^" << (char)219 << (char)')' << std::endl;
    rlutil::locate(++x,++y);
    std::cout<<(char)219 << (char)219 << (char)219 << (char)219 << (char)219 << std::endl;
}

void pos2( int x , int y ){
    rlutil::hidecursor();
    rlutil::locate(x,y);
    std::cout<< (char)223 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)223 << std::endl;
    rlutil::locate(x,++y);
    std::cout<< (char)'\\' << (char)219 << "^ ^" << (char)219 << (char)'/' << std::endl;
    rlutil::locate(++x,++y);
    std::cout<<(char)219 << (char)219 << (char)219 << (char)219 << (char)219 << std::endl;
}

void confeti( int x , int y ){
    rlutil::hidecursor();
    rlutil::locate(x-3,--y);
    rlutil::setColor(1);
    std::cout<< (char)254;

    rlutil::locate(x-5,++y);
    rlutil::setColor(4);
    std::cout<< (char)254;

    rlutil::locate(x-3,++y);
    rlutil::setColor(3);
    std::cout<< (char)254;

    rlutil::locate(x+10,y);
    rlutil::setColor(10);
    std::cout<< (char)254;

    rlutil::locate(x+11,--y);
    rlutil::setColor(9);
    std::cout<< (char)254;

    rlutil::locate(x+10,--y);
    rlutil::setColor(4);
    std::cout<< (char)254;
}

void borrarConfeti( int x , int y ){
    rlutil::hidecursor();
    rlutil::locate(x-3,--y);
    rlutil::setColor(7);
    std::cout<< (char)254;

    rlutil::locate(x-5,++y);
    rlutil::setColor(7);
    std::cout<< (char)254;

    rlutil::locate(x-3,++y);
    rlutil::setColor(7);
    std::cout<< (char)254;

    rlutil::locate(x+10,y);
    rlutil::setColor(7);
    std::cout<< (char)254;

    rlutil::locate(x+11,--y);
    rlutil::setColor(7);
    std::cout<< (char)254;

    rlutil::locate(x+10,--y);
    rlutil::setColor(7);
    std::cout<< (char)254;
}

void llanto1( int x , int y ){
    rlutil::hidecursor();
    rlutil::locate(x,y);
    std::cout<< (char)223 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)223 << std::endl;
    rlutil::locate(++x,++y);
    std::cout<< (char)219 << "- -" << (char)219 << std::endl;
    rlutil::locate(x,++y);
    std::cout<< (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << std::endl;
}

void llanto2( int x , int y ){
    rlutil::hidecursor();
    rlutil::saveDefaultColor();
    rlutil::locate(x,y);
    std::cout<< (char)223 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)223 << std::endl;
    rlutil::locate(++x,++y);
    std::cout<< (char)219 << "   " << (char)219 << std::endl;
    rlutil::locate(++x,y);
    rlutil::setColor(3);
    std::cout<< (char)210 <<" "<<(char)210<< std::endl;
    rlutil::resetColor();
    rlutil::locate(--x,++y);
    std::cout<< (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << std::endl;
}
