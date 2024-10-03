#include <stdio.h>
#include <string.h>
#include "libr_caricamento_files.h"

void crea_file_prenotazioni( prenotazione prenotazioni[], int n_prenotazioni ) {
  FILE *fPtr;
  
  // ricevi in input dal file di testo visite i dati delle visite da inserire nella struct utenti
  fPtr = fopen( "prenotazioni.txt", "r" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  /* Lettura del file */ 
 else { // altrimenti
   for( int i = 0; i < n_prenotazioni; i++ ) {
     fscanf( fPtr, "%s\n", prenotazioni[i].CodFiscale );
     fgets( prenotazioni[i].Id_medico, 20, fPtr  );
     fscanf( fPtr, "%s\n", prenotazioni[i].tipo_visita );
     fscanf( fPtr, "%d", &prenotazioni[i].giorno_prenotazione );
     fscanf( fPtr, "%d", &prenotazioni[i].mese_prenotazione );
     fscanf( fPtr, "%d", &prenotazioni[i].anno_prenotazione );
     fscanf( fPtr, "%d", &prenotazioni[i].ora_prenotazione );
     fscanf( fPtr, "%d", &prenotazioni[i].minuti_prenotazione );
    } 
   puts( "caricamento completato!" );
  } // fine di else
 
 fclose(fPtr); // chiusura del file

 
 fPtr = fopen( "prenotazioni.dat", "wb" ); // Apertura del file binario in scrittura

 if( !fPtr ) { // se il file non viene aperto
    puts( "Errore durante la creazione del file!" ); // comunica all'utente un messaggio di errore
  } // fine di if

  /* Scrittura in file binario di tutti i record */
 else { // altrimenti
    fwrite( prenotazioni, sizeof( prenotazione ), n_prenotazioni, fPtr );
  } // fine di else


  fclose(fPtr); // chiusura del file


} // termina la funzione

