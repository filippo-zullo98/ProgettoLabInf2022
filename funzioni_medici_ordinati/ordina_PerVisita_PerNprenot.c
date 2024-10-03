#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void ordina_PerVisita_PerNprenot( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni )
{
  int lista_prenotazioni[n_medici]; 
  int lista_prenotazioni_SenzaDuplicati[n_medici];
  int scelta = 0;
  int counter_somma_prenotazioni = 0;
  int n_visite = 0;
  char *lista_visite[n_medici];
  char tipo_visita[30] = "null";
 
  /* chiamata alla funzione per il caricamento delle informazioni memorizzate nel file binario "VISITE" */
  carica_file_visite( medici );
  /* chiamata alla funzione per il caricamento delle informazioni memorizzate nel file binario "PRENOTAZIONI" */
  carica_file_prenotazioni( prenotazioni );
  /* chiamata alla funzione per la creazione della lista del numero di prenotazioni per ogni medico */
  counter_somma_prenotazioni = crea_lista_prenotazioni( medici, n_medici, prenotazioni, n_prenotazioni, lista_prenotazioni, lista_prenotazioni_SenzaDuplicati  ); 

  int new_lista_prenotazioni[counter_somma_prenotazioni]; 

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

 /* se l'utente sceglie di visualizzare l'elenco in ordine decrescente */
 if( scelta == 1 ) { 
   /* chiamata alla funzione per visualizzare i medici elencati per tipo di visita e numero di prenotazioni 
      in ordine decrescente */
   outputMedDec_PerVis_PerNpren( medici, n_medici, prenotazioni, n_prenotazioni, lista_prenotazioni, lista_prenotazioni_SenzaDuplicati,
                              counter_somma_prenotazioni, new_lista_prenotazioni, n_visite, new_lista_visite, lista_visite, tipo_visita );
  } // fine di if 
 
  /* se l'utente sceglie di visualizzare l'elenco in ordine crescente */
 else {
   /* chiamata alla funzione per visualizzare i medici elencati per tipo di visita e numero di prenotazioni 
      in ordine crescente */
   outputMedCresc_PerVis_PerNpren( medici, n_medici, prenotazioni, n_prenotazioni, lista_prenotazioni, lista_prenotazioni_SenzaDuplicati,
                                   counter_somma_prenotazioni, new_lista_prenotazioni, n_visite, new_lista_visite, lista_visite, tipo_visita );
   
  } // fine di else   
  
  
} // termina la funzione 