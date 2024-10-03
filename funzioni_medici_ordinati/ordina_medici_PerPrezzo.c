#include <stdio.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void ordina_medici_PerPrezzo( medico medici[], int n_medici ) {
  
  float prezzi[n_medici];
  int n_prezzi = 0; 
  int scelta = 0;
   
  
  /* chiamata alla funzione per il caricamento delle informazioni presenti nel file binario "VISITE" */
  carica_file_visite( medici );
  /* chiamata alla funzione per l'ordinamento dei prezzi presenti nel file binario "VISITE" */
  n_prezzi = ordina_prezzi_medici( medici, n_medici, prezzi );
  system( "clear" );
  
  
  float new_lista_prezzi[n_prezzi]; // array che conterrà i prezzi di tutti i medici senza duplicati

  /* finchè l'utente non sceglie correttamente una fra le due opzioni elencate */
  while( scelta != 1 && scelta != 2 ) {
   puts( "Selezionare uno dei seguenti ordini: " );
   puts( "1 - Decrescente" );
   puts( "2 - Crescente" );
   printf( "Insersca un numero---> " );
   scanf( "%d", &scelta );
   if( scelta != 1 && scelta != 2 ) { // se la scelta è diversa da una delle due elencate 
     puts( "\nErrore! Selezionare una delle due opzioni mostrate nell'elenco." ); 
    } // fine di if
  } // fine di for 

 /* se l'utente sceglie di visualizzare i medici dai prezzi più costosi ai meno costosi */
 if( scelta == 1 ) { 
   /* chiamata alla funzione per l'output dei prezzi elencati in ordine decrescente */
   output_prezzi_MedDecr( n_prezzi, medici, new_lista_prezzi, n_medici, prezzi );
  } // fine di if 
 
  /* se l'utente sceglie di visualizzare i medici dai prezzi meno costosi ai più costosi */
  else {
    /* chiamata alla funzione per l'output dei prezzi elencati in ordine crescente */
   output_prezzi_MedCresc( n_prezzi, medici, new_lista_prezzi, n_medici, prezzi );
  } // fine di else 

} // termina la funzione 