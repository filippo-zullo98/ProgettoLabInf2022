#include <stdio.h>
#include "libr_ordinamento_medici.h"

int ordina_prezzi_medici( medico medici[], int n_medici, float prezzi[] ) {

  int max_prezzo = 0;
  int tmp = 0; // variabile che conterrà il valore maggiore temporaneo 
  int n_prezzi = 0; 

  // finchè il valore di i è minore del numero di medici presenti nel file binario "VISITE"
  for( int i = 0; i < n_medici; i++ ) { 
    prezzi[i] = medici[i].prezzo; // copia ogni prezzo memorizzato nella stuct dei medici all'interno dell'array prezzi
  } // fine di for 

  // applica l'algoritmo di ordinamento bubble sort
  for( int i = 0; i < n_medici - 1; i++ ) { // finchè il valore di i è minore del numero di medici - 1
    for( int j = 0; j < n_medici - 1; j++ ) {  // finchè il valore di j è minore del numero di medici - 1
      if( prezzi[j] > prezzi[j + 1] ) { // se il prezzo j-esimo è maggiore del suo successore 
        tmp = prezzi[j]; // poni la variabile temporanea uguale al prezzo j-esimo 
        prezzi[j] = prezzi[j + 1]; // poni il valore j-esimo uguale al suo successore
        prezzi[j + 1] = tmp; // poni il successore del valore j-esimo uguale al valore temporaneo 
      } // fine di if 
    } // fine di for 
  } // fine di for 
  

  puts( " " );
  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    for( int j = i + 1; j < n_medici; j++ ) { // finchè il valore di j è minore del numero di medici 
      if( prezzi[i] == prezzi[j] ) { // se il prezzo i-esimo è uguale al prezzo j-esimo 
        prezzi[j] = 0; // poni il valore duplicato uguale a zero 
      } // fine di if
    } // fine di for interno 
  } // fine di for 

 
  
  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    if( prezzi[i] != 0 ) { // se il prezzo i-esimo è diverso da zero 
      n_prezzi++; // incrementa il numero di prezzi 
    } // fine di if 
  } // fine di for 

  return n_prezzi; // restituisci il numero di prezzi alla funzione chiamante 
  
} // termina la funzione 