#include <stdio.h>
#include "libr_modifica_prenotazioni.h"

void registra_data_cancellata( prenotazione prenotazioni[], int n_prenotazioni ) {
  
  FILE *fPtr;
  
  fPtr = fopen( "prenotazioni.dat", "wb" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  // Lettura del file 
  else { // altrimenti
   fwrite( prenotazioni, sizeof( prenotazione ), n_prenotazioni, fPtr );  
  } // fine di else

  

  fclose( fPtr ); // chiusura del file 
  
} // termina la funzione 