#include <stdio.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void ordina_medici_PerValutazioni( medico medici[], int n_medici ) {

  float valutazioni[n_medici];
  int n_valutazioni = 0;
  int scelta = 0;

  /* chiamata alla funzione per il caricamento delle informazioni presenti nel file binario "VISITE" */
  carica_file_visite( medici );
  /* chiamata alla funzione per l'ordinamento delle valutazioni presenti nel file binario "VISITE" */
  n_valutazioni = ordina_valutazioni_medici( medici, n_medici, valutazioni );
  system( "clear" ); 

  float new_lista_valutazioni[n_valutazioni]; // array che conterrà le valutazioni di tutti i medici senza duplicati

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

 /* se l'utente sceglie di visualizzare i medici dalle valutazioni più alte alle più basse */
 if( scelta == 1 ) { 
   /* chiamata alla funzione per l'output delle valutazioni elencate in ordine decrescente */
   output_valutazioni_MedDecr( n_valutazioni, medici, new_lista_valutazioni, n_medici, valutazioni );
  } // fine di if 
 
  /* se l'utente sceglie di visualizzare i medici dalle valutazioni più basse alle più alte */
  else {
    /* chiamata alla funzione per l'output delle valutazioni elencate in ordine crescente */
    output_valutazioni_MedCresc( n_valutazioni, medici, new_lista_valutazioni, n_medici, valutazioni );
  } // fine di else 


  

  
} // termina la funzione 