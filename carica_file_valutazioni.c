#include <stdio.h>
#include "libr_caricamento_files.h"

int carica_file_valutazioni( valutazione valutazioni[] ) {
  FILE *fPtr;
  int n_valutazioni;

  fPtr = fopen( "valutazioni.dat", "rb" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  /* Lettura del file */
  else { // altrimenti
   n_valutazioni = 0;
   while( fread( &valutazioni[n_valutazioni], sizeof( valutazione ), 1, fPtr ) == 1 ) {
     n_valutazioni++;
   } // fine di while

  } // fine di else

  fclose( fPtr ); // chiusura del file



 return n_valutazioni;

} // termina la funzione
