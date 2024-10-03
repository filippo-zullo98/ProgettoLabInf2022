#include <stdio.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void richiesta_continuazione_OpOrdinamento( int n_medici, int n_prenotazioni )
{
  int scelta = 0; 

  // finchè l'utente non sceglie correttamente una fra le tre operazioni elencate
  while( scelta < 1 || scelta > 3 ) { 
    puts( "Selezionare una delle seguenti opzioni elencate: " );
    puts( "1 - Continua nell'operazione di ordinamento dei medici;" );
    puts( "2 - Ritorna al menù principale;" );
    puts( "3 - Termina il programma." );
    printf( "Inserisca uno dei numeri elencati---> " );
    scanf( "%d", &scelta );
    if( scelta < 1 || scelta > 3 ) { // se l'utente sbaglia nella scelta
      puts( "ERRORE!" );
    } // fine di if 
  } // fine di while 

  switch( scelta ) {
    case 1 : // se la scelta è quella di continuare la visualizzazione
    system( "clear" );
    break;

    case 2 : // se la scelta è quella di tornare al menù principale 
    system( "clear" );
    main(); // effettua una chiamata a main 
    break;

    case 3 : // se la scelta è quella di terminare il programma
    puts( "exit" );
    exit(EXIT_SUCCESS); // termina il programma 
    break;
    
  } // termina switch
  
} // termina la funzione 