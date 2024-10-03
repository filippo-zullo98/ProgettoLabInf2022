#include <stdio.h>
#include "libr_caricamento_files.h"

void stampa_dati_utenti( utente utenti[], int n_utenti ) {
  
  for( int i = 0; i < n_utenti; i++ ) {
    printf( "CodFiscale Paziente: %s\n", utenti[i].CodFiscale );
    printf( "Nome Paziente: %s", utenti[i].nome_paziente );
    printf( "Cognome Paziente: %s", utenti[i].cognome_paziente );
    printf( "Sesso Paziente: %c\n", utenti[i].sesso );
    printf( "Giorno di nascita Paziente: %d\n", utenti[i].giorno_nascita );
    printf( "Mese di nascita Paziente: %d\n", utenti[i].mese_nascita );
    printf( "Anno di nascita Paziente: %d\n\n", utenti[i].anno_nascita );
  }

  
  
  
} // termina la funzione
