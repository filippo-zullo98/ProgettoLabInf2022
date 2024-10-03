#include <stdio.h>
#include <string.h>
#include "libr_caricamento_files.h"

void crea_file_utenti( utente utenti[], int n_utenti ) {
  FILE *fPtr;
  
  // ricevi in input dal file di testo visite i dati delle visite da inserire nella struct utenti
  fPtr = fopen( "utenti.txt", "r" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  /* Lettura del file */ 
 else { // altrimenti
   for( int i = 0; i < n_utenti; i++ ) {
     fscanf( fPtr, "%s\n", utenti[i].CodFiscale );
     fgets( utenti[i].nome_paziente, 20, fPtr );
     fgets( utenti[i].cognome_paziente, 20, fPtr );
     fscanf( fPtr, "%c", &utenti[i].sesso );
     fscanf( fPtr, "%d", &utenti[i].giorno_nascita );
     fscanf( fPtr, "%d", &utenti[i].mese_nascita );
     fscanf( fPtr, "%d\n", &utenti[i].anno_nascita );
    }
   puts( "caricamento completato!" );
  } // fine di else

 fclose(fPtr); // chiusura del file

 
 fPtr = fopen( "utenti.dat", "wb" ); // Apertura del file binario in scrittura

 if( !fPtr ) { // se il file non viene aperto
    puts( "Errore durante la creazione del file!" ); // comunica all'utente un messaggio di errore
  } // fine di if*/

  /* Scrittura in file binario di tutti i record */
 else { // altrimenti
    fwrite( utenti, sizeof( utente ), n_utenti, fPtr );
  } // fine di else


  fclose(fPtr); // chiusura del file


} // termina la funzione

