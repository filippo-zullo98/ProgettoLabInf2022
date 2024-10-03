#include <stdio.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void output_prezzi_MedDecr( int n_prezzi, medico medici[], float new_lista_prezzi[], int n_medici, float prezzi[] ) {
  
  int j = 0; 
  
  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    if( prezzi[i] != 0 ) { // se il prezzo i-esimo è diverso da zero 
      new_lista_prezzi[j] = prezzi[i]; // poni il valore j-esimo della nuova lista dei prezzi uguale al prezzo i-esimo
      j++; // incrementa il valore di j
    } // fine di if 
  } // fine di for 

  system( "clear" ); 
  puts( "LISTA PREZZI MEDICI IN ORDINE DECRESCENTE" );
  puts( " " );
  // finchè il valore di i è maggiore di zero 
  for( int i = n_prezzi; i > 0; i-- ) {
    /* finchè il valore di j è minore del numero di medici memorizzati nel 
       file binario "VISITE" */
    for( int j = 0; j < n_medici; j++ ) {
      /* se il prezzo i-esimo della nuova lista dei prezzi coincide con l'elemento j-esimo dei 
         prezzi della struct medici */
      if( new_lista_prezzi[i] == medici[j].prezzo ) {
        printf( "-> Prezzo visita medica: %.2f\n", medici[j].prezzo );
        printf( "-> Id medico: %s", medici[j].Id_medico );
        printf( "-> Nome medico: %s", medici[j].nome_medico );
        printf( "-> Cognome medico: %s", medici[j].cognome_medico );
        printf( "-> Tipo di visita medica: %s\n", medici[j].tipo_visita );
        puts( " " );
      } // fine di if 
    } // fine di for interno
  } // fine di for 

} // termina la funzione 