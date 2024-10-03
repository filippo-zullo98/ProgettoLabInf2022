#include <stdio.h>
#include <string.h>
#include "libr_ordinamento_medici.h"

int ordina_tipi_visite( medico medici[], int n_medici, char *lista_visite[], char tipo_visita[] ) {

  int n_visite = 0;
  

  /* finchè il valore di i è minore del numero di visite memorizzate nel file binario "VISITE" */
  for( int i = 0; i < n_medici; i++ ) { 
   /* copia ogni tipo di visita memorizzata nella struct dei medici nella lista delle visite */
    lista_visite[i] = medici[i].tipo_visita; 
  } // fine di for 

  
  puts( " " );
  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    for( int j = i + 1; j < n_medici; j++ ) { // finchè il valore di j è minore del numero di medici 
      if( strncmp( lista_visite[i], lista_visite[j], 30 ) == 0 ) { // se il prezzo i-esimo è uguale al prezzo j-esimo 
        lista_visite[j] = tipo_visita;
      } // fine di if
    } // fine di for interno 
  } // fine di for   


  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    if( tipo_visita != lista_visite[i] ) { // se il prezzo i-esimo è diverso da zero 
      n_visite++; // incrementa il numero di visite
    } // fine di if 
    
  } // fine di for  

    

  return n_visite; // restituisci il numero di visite alla funzione chiamante 
  
} // termina la funzione 