#include <stdio.h>
#include "libr_caricamento_files.h"

void stampa_dati_medici( medico medici[], int n_medici ) {
  /* in questa variabile verrà inserito il numero di stelle da stampare per la media delle valutazioni del medico */
  int stars = 0; // inizializza la variabile stars a zero 

  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero di medici 
    printf( "-> Id medico: %s", medici[i].Id_medico ); 
    printf( "-> Nome medico: %s", medici[i].nome_medico );
    printf( "-> Cognome medico: %s", medici[i].cognome_medico );
    printf( "-> Tipo di visita medica: %s\n", medici[i].tipo_visita );
    printf( "-> Descrizione visita: %s", medici[i].descrizione );
    printf( "-> Prezzo visita medica: %.2f€\n", medici[i].prezzo );
    if( medici[i].val_utenza > 0 ) { // se la valutazione è maggiore di zero 
      stars = medici[i].val_utenza; // imposta il valore di stars uguale al valore dell'utenza per un medico specifico 
      printf( "-> Media valutazioni utenti: " ); 
      for( int j = 0; j < (int)stars; j++ ) { // finchè il valore il valore di j è minore del valore intero di stars
        printf( "*" ); // stampa una stella 
      } // fine di for 
      printf( "\n\n" );  
    } // fine di if 

    else { // altrimenti 
      printf( "Media valutazioni utenze---> %.2f\n\n", medici[i].val_utenza ); // stampa la media delle valutazioni in virgola mobile 
    } // fine di else 
  } // fine di for 

} // termina la funzione
