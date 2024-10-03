#include <stdio.h>
#include "libr_ordinamento_medici.h"

int ordina_valutazioni_medici( medico medici[], int n_medici, float valutazioni[] ) {
  
  int max_valutazione = 0;
  int tmp = 0; // variabile che conterrà il valore maggiore temporaneo 
  int n_valutazioni = 0;

  // finchè il valore di i è minore del numero di medici presenti nel file binario "VISITE"
  for( int i = 0; i < n_medici; i++ ) {
    valutazioni[i] = medici[i].val_utenza; // copia ogni valutazione memorizzata nella stuct dei medici all'interno dell'array valutazioni
  } // fine di for 

  // applica l'algoritmo di ordinamento bubble sort
  for( int i = 0; i < n_medici - 1; i++ ) { // finchè il valore di i è minore del numero di medici - 1
    for( int j = 0; j < n_medici - 1; j++ ) {  // finchè il valore di j è minore del numero di medici - 1
      if( valutazioni[j] > valutazioni[j + 1] ) { // se la valutazione j-esima è maggiore del sua successiva 
        tmp = valutazioni[j]; // poni la variabile temporanea uguale alla valutazione j-esima 
        valutazioni[j] = valutazioni[j + 1]; // poni il valore j-esimo uguale al suo successore
        valutazioni[j + 1] = tmp; // poni il successore del valore j-esimo uguale al valore temporaneo 
      } // fine di if 
    } // fine di for 
  } // fine di for 

  puts( " " );
  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    for( int j = i + 1; j < n_medici; j++ ) { // finchè il valore di j è minore del numero di medici 
      if( valutazioni[i] == valutazioni[j] ) { // se la valutazione i-esima è uguale alla valutazione j-esima 
        valutazioni[j] = -1; // poni il valore duplicato uguale a zero 
      } // fine di if
    } // fine di for interno 
  } // fine di for 

  

  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    if( valutazioni[i] != -1 ) { // se la valutazione i-esima è diversa da -1 
      n_valutazioni++; // incrementa il numero delle valutazioni 
    } // fine di if 
  } // fine di for 

  
  

  return n_valutazioni; // restituisci il numero delle valutazioni alla funzione chiamante

} // fine di for 