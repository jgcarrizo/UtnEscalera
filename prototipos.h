#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

/// PROTOTIPOS

/// INTERFAZ.CPP
void cargarCadena(char *palabra, int tamano );
void escribir( int  , int , std::string  ); // MUESTRA TEXTOS
void escribir( int , int , std::string , char [][21] , int );
void mostrarNombre( int , int , char [][21] , int p ); // MUESTRA MATRIZ CHAR
void mostrarInt( int , int , int  ); // MUESTRA UNA VARIABLE ENTERA
void escribir( int , int , std::string , int ); // MUESTRA TEXTO MAS VARIABLE ENTERA
void escribir( int , int , std::string , int , std::string ); // MUESTRA UN TEXTO, UNA VARIABLE ENTERA Y OTRO TEXTO
void monstruo( int , int ); // DIBUJA UN MONSTRUO
void copaRanking(int  , int ); // DIBUJA UNA COPA
void salir( int , int ); // DIBUJA SALIR
void quinientos (); // DIBUJA EL TITULO
void marco(); // DIBUJA UN MARCO SIMPLE
void marcoPartida1(); // DIBUJA EL MARCO DE PARTIDA
int salirDelJuego(); // PANTALLA SALIR DEL JUEGO
void cuadro();
void cuadro2();
void cuadro3();


/// MENUPRINCIPAL.CPP
int menuPrincipal();
void opcionUnPlayer();
void opcionDosPlayers();
void opcionRanking();
void opcionSalir();
void moverIzquierda( int &x );
void moverDerecha( int &x );


/// RANKING.CPP
void ranking( int vPuntajesRanking[] , char mNombresRanking[][21] );
void escribirRanking( int x , int y , int num , int vPuntajesRanking[] , char mNombresRanking[][21] , int p );
void actualizarRanking( int vMayorPuntaje[] , char mNombres[][21] , int vPuntajesRanking[] , char mNombresRanking[][21] );


/// DADOS.CPP
void sombra1( int &x , int &y );
void sombra2( int &x , int &y );
void seis( int x , int y ); // DIBUJA DADO SEIS
void uno ( int x , int y ); // DIBUJA EL DADO UNO
void dos( int x , int y ); // DIBUJA EL DADO DOS
void tres( int x , int y ); // DIBUJA EL DADO TRES
void cuatro( int x , int y ); // DIBUJA EL DADO CUATRO
void cinco( int x , int y ); // DIBUJA EL DADO DE CINCO
void dibujarDado( int [] ); // DIBUJA LOS SEIS DADOS LANZADOS
void borrarDados();


/// PUNTOS.CPP
void generarDados( int v[],int t); // CARGA VECTOR CON NUMEROS RANDOM  ( ENTRE 1 Y t )
void vectorCero( int v[], int t ); // VECTOR EN CERO
void contarRep( int v[], int c[], int t ); // CUENTA CUANTAS VECES SE REPITE CADA NUMERO ( ENTRE 1 Y t )
void lanzarDados( int vCant[] , int t ); // LANZA LOS DADOS Y CUENTA LA CANTIDAD DE CADA VALOR

// JUGADAS/COMBINACIONES GANADORAS //
int sexteto( int vCant[] );
int sumaDados( int vCant[] , int t );
int trioX( int vCant[] , int t );
void escalera ( int vCant[] , int t , int &jugada );
int sexteto( int vCant[] );
//------------------------//

void determinarJugada( int vCant[], int t, int &jugada , int &puntos ); // DETERMINAR JUGADA GANADORA
void mostrarJugada( int vCant[] , int t , int jugada , int puntos ); // MOSTRAR JUGADA Y PUNTAJE
void maxPuntajeRonda( int &maxRonda , int &puntajeRonda , int parciales , int jugada  ); // GUARDA EL MAXIMO DE TRES LANZAMIENTOS ( 1 PLAYER )
void sumaPuntos( int &total, int &puntajeRonda , int jugada ); // ACUMULA EL MAXIMO EN EL PUNTAJE TOTAL ( 1 PLAYER )
void maxPuntajeRonda( int maxRonda[] , int puntajeRonda[] , int parciales[] , int p , int jugada ); // GUARDA EL MAXIMO DE TRES LANZAMIENTOS ( 2 PLAYER )
void sumaPuntos( int total[] , int puntajeRonda[] , int p  , int jugada ); // ACUMULA EL MAXIMO EN EL PUNTAJE TOTAL ( 2PLAYER )

/// DOSPLAYERS.CPP
void dosPlayers( char [][21] , int [] );
void interfaz2Players( char [][21], int , int [], int [], int [], int  , int ); // DIBUJA LA INTERFAZ PARA DOS PLAYERS
void ingreseNombre(char [][21], int); // INGRESA EL NOMBRE DE LOS JUGADORES
void elegirRondas( int & ); // ELEGIR LA CANTIDAD DE RONDAS
void proximoTurno(int & , int [], int [] , int & );
void cambioDeTurno( int ronda , int p , char mNombres[][21] , int vLanzamientos[], int vPuntajeTotal[], int vEstadoJuego[] , int anterior , bool hayGanador , int totalRondas );
void comienzoDeRonda( int ronda );
void estadoDelJuego( int jugada , int vEstadoJuego[] , int &ganador , bool &hayGanador , int p );
void pausaDeFinRonda( int vLanzamientos[] , int p , int vEstadoJuego[] );
void estadoFinJuego( bool &hayGanador , int &ganador, int vPuntajeTotal[] , int vEstadoJuego[] );
void finDePartida( int vEstadoJuego[] , char mNombres[][21] , int ronda , int vPuntajeTotal[] , bool hayGanador , int &ganador );
void determinarMayorPuntaje( int vPuntajeTotal[] , int vMayorPuntaje[] , char mNombres[][21] );


/// UNPLAYER.CPP
void unPlayer( char mNombres[][21] , int vMayorPuntaje[] );
void finDeRonda( char mNombres[][21], int puntos, int ronda , int jugada );
void determinarEsGanador( bool &esGanador, int j, int p );
void finDePartida( bool esGanador, int jugada, char mNombres[][21] , int ronda , int puntos );
void interfazUnPlayer( char mNombres[][21], int ronda, int puntajeTotal, int lanzamientos, int puntajeRonda , int rondaFinal );
void avisoDeFin( int lanzamientos , int jugada );
void pausaJugadaClave( int jugada );

/// ANIMACIONES.CPP
void feliz( int x , int y );
void festejo( int x , int y);
void triste( int x , int y );



#endif // PROTOTIPOS_H_INCLUDED
