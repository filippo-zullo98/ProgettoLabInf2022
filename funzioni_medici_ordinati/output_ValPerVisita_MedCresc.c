#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void output_ValPerVisita_MedCresc( int n_valutazioni, medico medici[], float new_lista_valutazioni[], int n_medici, float valutazioni[],
                                  int n_visite, char *new_lista_visite[], char *lista_visite[], char tipo_visita[] ) 
{

  int j = 0;
  int risposta = 0; 
  int flag = 0;
  char visita_inserita[30]; 

  system( "clear" ); 
  
  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    if( valutazioni[i] != -1 ) { // se la valutazione i-esima è diversa da zero 
      new_lista_valutazioni[j] = valutazioni[i]; // poni il valore j-esimo della nuova lista dei prezzi uguale al valutazione i-esima
      j++; // incrementa il valore di j
    } // fine di if 
  } // fine di for  

  j = 0; // imposta il valore di j uguale a zero 

  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici
    if( lista_visite[i] != tipo_visita ) { // se il l'elemento i-esimo della lista delle visite è diverso da "null"
      new_lista_visite[j] = lista_visite[i]; // copia l'elemento nella lista nuova
      j++; // incrementa il valore di j
    } // fine di if 
  } // fine di for

  puts( "ELENCO VISITE DISPONIBILI:" ); 
  /* finchè il valore di i è minore del numero di visite */
  for( int i = 0; i < n_visite; i++ ) {
    // stampa tutti i tipi di visite memorizzate nel sistema 
    printf( "%d - %s\n", i + 1, new_lista_visite[i] );
  } // fine di for 


  /* finchè l'utente non seleziona correttamente una delle visite elencate */
  while( risposta < 1 || risposta > n_visite ) { 
    printf( "\nSelezionare una delle seguenti visite elencate per visualizzarne i prezzi---> " );
    scanf( "%d", &risposta );
    if( risposta < 1 || risposta > n_visite ) { // se l'utente seleziona scorrettamente una delle visite elencate 
      puts( "Errore!" ); 
    } // fine di if 
  } // fine di for 

 // copia il tipo di visita selezionata dall'utente nella variabile visita_inserita  
 strncpy( visita_inserita, new_lista_visite[risposta - 1], 30 ); 

  puts( " " );
  puts( "LISTA VALUTAZIONI MEDICI IN ORDINE CRESCENTE" );
  // finchè il valore di i è minore del numero di valutazioni
  for( int i = 0; i < n_valutazioni; i++ ) {
    /* finchè il valore di j è minore del numero di medici memorizzati nel 
       file binario "VISITE" */
    for( int j = 0; j < n_medici; j++ ) {
      /* se la valutazione i-esima della nuova lista delle valutazioni coincide con l'elemento j-esimo delle
         valutazioni della struct medici */
      if( new_lista_valutazioni[i] == medici[j].val_utenza ) {  
        /* se la visita inserita dall'utente coincide con l'elemento j-esimo dei 
         prezzi della struct medici */
        if( strncmp(visita_inserita, medici[j].tipo_visita, 30 ) == 0 ) {
         printf( "-> Media Valutazioni Utenti: %.2f\n", medici[j].val_utenza );
         printf( "-> Id medico: %s", medici[j].Id_medico );
         printf( "-> Nome medico: %s", medici[j].nome_medico );
         printf( "-> Cognome medico: %s", medici[j].cognome_medico );
         printf( "-> Tipo di visita medica: %s\n", medici[j].tipo_visita );
         printf( "-> Prezzo visita medica: %.2f\n", medici[j].prezzo );
         puts( " " );
        } // fine di if interno 
      } // fine di if 
    } // fine di for interno 
  } // fine di for   

  
  
  
} // termina la funzione 