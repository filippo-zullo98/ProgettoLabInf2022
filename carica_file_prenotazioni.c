#include <stdio.h>
#include "libr_caricamento_files.h"

int carica_file_prenotazioni( prenotazione prenotazioni[] ) {
  FILE *fPtr;
  int n_prenotazioni; // variabile che contiene il numero di utenti memorizzati nel file 
 
  fPtr = fopen( "prenotazioni.dat", "rb" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!\n" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  /* Lettura del file */
  else { // altrimenti
   n_prenotazioni = 0;
   while( fread( &prenotazioni[n_prenotazioni], sizeof( prenotazione ), 1, fPtr ) == 1 ) {
     n_prenotazioni++;
   } // fine di while

   
  } // fine di else

  fclose( fPtr ); // chiusura del file
  
   
  //printf( "%d\n", n_utenti ); 
 
 return n_prenotazioni;

} // termina la funzione
