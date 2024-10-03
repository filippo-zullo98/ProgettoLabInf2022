#include <stdio.h>
#include "libr_modifica_prenotazioni.h"

int scelta_OpModifica( ) {

  int scelta = 0;

  // finchè l'utente non seleziona correttamente una delle due opzioni mostrate 
  while( scelta != 1 && scelta != 2 ) { 
   puts( "Scegliere una delle seguenti operazioni:" );
   puts( "1 - Effettua uno spostamento della prenotazione selezionata;" );
   puts( "2 - Effettua una cancellazione della prenotazione selezionata." );
   printf( "Selezionare un numero fra quelli elencati---> " );
   scanf( "%d", &scelta );
   // se l'utente sbaglia nella scelta dell'operazione da effettuare
   if( scelta != 1 && scelta != 2 ) { 
     puts( "\nErrore nella selezione!" );
     puts( "La preghiamo di selezionare una delle operazioni mostrate nell'elenco." );
    } // fine di if 
 
  } // fine di while 
  
  return scelta; // restituisci il valore della scelta alla funzione chiamante 
  
} // termina la funzione 