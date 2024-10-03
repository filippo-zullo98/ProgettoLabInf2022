#include <stdio.h>
#include "libr_caricamento_files.h"

void crea_file_valutazioni( valutazione valutazioni[], int n_valutazioni ) {
  FILE *fPtr;

  // ricevi in input dal file di testo visite i dati delle visite da inserire nella struct medici
  fPtr = fopen( "valutazioni.txt", "r" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  /* Lettura del file */ 
 else { // altrimenti
   for( int i = 0; i < n_valutazioni; i++ ) {
     fscanf( fPtr, "%s\n", valutazioni[i].CodFiscale );
     fgets( valutazioni[i].Id_medico, 20, fPtr  );
     fscanf( fPtr, "%s\n", valutazioni[i].tipo_visita );
     fscanf( fPtr, "%d", &valutazioni[i].valutazione );
     fscanf( fPtr, "%d", &valutazioni[i].giorno_prenotazione );
     fscanf( fPtr, "%d", &valutazioni[i].mese_prenotazione );
     fscanf( fPtr, "%d", &valutazioni[i].anno_prenotazione );
     fscanf( fPtr, "%d", &valutazioni[i].ora_prenotazione );
     fscanf( fPtr, "%d\n", &valutazioni[i].minuti_prenotazione );
    }
   puts( "caricamento completato!" );
  } // fine di else

 fclose(fPtr); // chiusura del file

 fPtr = fopen( "valutazioni.dat", "wb" ); // Apertura del file binario in scrittura

  if( !fPtr ) { // se il file non viene aperto
    puts( "Errore durante la creazione del file!" ); // comunica all'utente un messaggio di errore
  } // fine di if

  /* Scrittura in file binario di tutti i record */
  else { // altrimenti
    fwrite( valutazioni, sizeof( valutazione ), n_valutazioni, fPtr );
  } // fine di else


  fclose(fPtr); // chiusura del file


} // termina la funzione
