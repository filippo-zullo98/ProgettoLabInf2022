#include <stdio.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void output_valutazioni_MedCresc( int n_valutazioni, medico medici[], float new_lista_valutazioni[], int n_medici, float valutazioni[] ) {

  int j = 0;

  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    if( valutazioni[i] != -1 ) { // se il prezzo i-esimo è diverso da -1
      new_lista_valutazioni[j] = valutazioni[i]; // poni il valore j-esimo della nuova lista delle valutazioni uguale alla valutazione i-esima
      j++; // incrementa il valore di j
    } // fine di if 
  } // fine di for 

  
  system( "clear" );
  puts( "LISTA VALUTAZIONI MEDICI IN ORDINE CRESCENTE" );
  puts( " " );
  // finchè il valore di i è minore del numero di valutazioni
  for( int i = 0; i < n_valutazioni; i++ ) {
    /* finchè il valore di j è minore del numero di valutazioni memorizzate nel 
       file binario "VISITE" */
    for( int j = 0; j < n_medici; j++ ) {
      /* se la valutazione i-esima della nuova lista delle valutazioni coincide con l'elemento j-esimo delle
         valutazioni della struct medici */
      if( new_lista_valutazioni[i] == medici[j].val_utenza ) {
        printf( "-> Media Valutazioni Utenti: %.2f\n", medici[j].val_utenza );
        printf( "-> Id medico: %s", medici[j].Id_medico );
        printf( "-> Nome medico: %s", medici[j].nome_medico );
        printf( "-> Cognome medico: %s", medici[j].cognome_medico );
        printf( "-> Tipo di visita medica: %s\n", medici[j].tipo_visita );
        printf( "-> Prezzo visita medica: %.2f\n", medici[j].prezzo );
        puts( " " );
      } // fine di if 
    } // fine di for interno
  } // fine di for 
  

  
 
} // termina la funzione 