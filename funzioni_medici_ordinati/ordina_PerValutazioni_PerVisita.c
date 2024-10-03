#include <stdio.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void ordina_PerValutazioni_PerVisita( medico medici[], int n_medici ) {
  
  float valutazioni[n_medici];
  int n_valutazioni = 0;
  int scelta = 0;
  int n_visite = 0;
  char *lista_visite[n_medici];
  char tipo_visita[30] = "null";

  /* chiamata alla funzione per il caricamento delle informazioni presenti nel file binario "VISITE" */
  carica_file_visite( medici );
  /* chiamata alla funzione per l'ordinamento delle valutazioni presenti nel file binario "VISITE" */
  n_valutazioni = ordina_valutazioni_medici( medici, n_medici, valutazioni );
  system( "clear" ); 

  float new_lista_valutazioni[n_valutazioni]; // array che conterrà le valutazioni di tutti i medici senza duplicati 

  /* chiamat alla funzione per l'ordinamento delle visite presenti nel file binario "VISITE" */
  n_visite = ordina_tipi_visite( medici, n_medici, lista_visite, tipo_visita );

  char *new_lista_visite[n_visite]; 

  system( "clear" );

  
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

 /* se l'utente sceglie di visualizzare i medici per tipo di visita e per le valutazioni dalle più alte alle più basse */
 if( scelta == 1 ) { 
   /* chiamata alla funzione per l'output delle valutazioni elencate per tipo di visita e in ordine decrescente */
   output_ValPerVisita_MedDecr( n_valutazioni, medici, new_lista_valutazioni, n_medici, valutazioni, n_visite, new_lista_visite, lista_visite, tipo_visita );
  } // fine di if 
 
  /* se l'utente sceglie di visualizzare i medici per tipo di visita e per le valutazioni dalle più base alle più alte */
  else {
    /* chiamata alla funzione per l'output delle valutazioni elencate per tipo di visita e in ordine crescente */
    output_ValPerVisita_MedCresc( n_valutazioni, medici, new_lista_valutazioni, n_medici, valutazioni, n_visite, new_lista_visite, lista_visite, tipo_visita );
  } // fine di else 

} // termina la funzione