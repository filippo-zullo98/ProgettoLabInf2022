#include <stdio.h>
#include "libr_caricamento_files.h"

void crea_file_visite( medico medici[], int n_medici ) {
  FILE *fPtr;

  // ricevi in input dal file di testo visite i dati delle visite da inserire nella struct medici
  fPtr = fopen( "visite.txt", "r" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  /* Lettura del file */ 
 else { // altrimenti
   for( int i = 0; i < n_medici; i++ ) {
     fgets( medici[i].Id_medico, 20, fPtr  );
     fgets( medici[i].nome_medico, 20, fPtr );
     fgets( medici[i].cognome_medico, 20, fPtr );
     fscanf( fPtr, "%s\n", medici[i].tipo_visita );
     fgets( medici[i].descrizione, 500, fPtr );
     fscanf( fPtr, "%f", &medici[i].prezzo );
     fscanf( fPtr, "%f\n", &medici[i].val_utenza );
    }
   puts( "caricamento completato!" );
  } // fine di else

 fclose(fPtr); // chiusura del file

 fPtr = fopen( "visite.dat", "wb" ); // Apertura del file binario in scrittura

  if( !fPtr ) { // se il file non viene aperto
    puts( "Errore durante la creazione del file!" ); // comunica all'utente un messaggio di errore
  } // fine di if

  /* Scrittura in file binario di tutti i record */
  else { // altrimenti
    fwrite( medici, sizeof( medico ), n_medici, fPtr );
  } // fine di else


  fclose(fPtr); // chiusura del file


} // termina la funzione
