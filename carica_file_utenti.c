#include <stdio.h>
#include "libr_caricamento_files.h"

int carica_file_utenti( utente utenti[] ) {
  FILE *fPtr;
  int n_utenti; // variabile che contiene il numero di utenti memorizzati nel file 

  fPtr = fopen( "utenti.dat", "rb" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  /* Lettura del file */
  else { // altrimenti
   n_utenti = 0;
   while( fread( &utenti[n_utenti], sizeof( utente ), 1, fPtr ) == 1 ) {
     n_utenti++;     
   } // fine di while

   
  } // fine di else

  fclose( fPtr ); // chiusura del file
  
   
  //printf( "%d\n", n_utenti ); 
 
 return n_utenti;

} // termina la funzione
