#include <stdio.h>
#include "libr_caricamento_files.h"

int carica_file_visite( medico medici[] ) {
  FILE *fPtr;
  int n_medici;

  fPtr = fopen( "visite.dat", "rb" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  /* Lettura del file */
  else { // altrimenti
   n_medici = 0;
   while( fread( &medici[n_medici], sizeof( medico ), 1, fPtr ) == 1 ) {
     n_medici++;
   } // fine di while

  } // fine di else

  fclose( fPtr ); // chiusura del file



 return n_medici;

} // termina la funzione
