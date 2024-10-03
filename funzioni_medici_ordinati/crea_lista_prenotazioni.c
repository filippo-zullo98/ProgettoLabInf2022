#include <stdio.h>
#include <string.h>
#include "libr_ordinamento_medici.h"

int crea_lista_prenotazioni( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni, int lista_prenotazioni[], int lista_prenotazioni_SenzaDuplicati[] ) 
{ 
  int counter_somma_prenotazioni = 0;
  int tmp;
  
  // finchè il valore di i è minore del numero di medici memorizzati nel file binario "VISITE"
  for( int i = 0; i < n_medici; i++ ) {
    lista_prenotazioni_SenzaDuplicati[i] = 0; // poni il valore i-esimo della lista delle prenotazioni uguali a zero 
  } // fine di for 

  // finchè il valore di i è minore del numero di medici memorizzati nel file binario "VISITE"
  for( int i = 0; i < n_medici; i++ ) {
    // finchè il valore di j è minore del numero di prenotazioni memorizzate nel file binario "PRENOTAZIONI"
    for( int j = 0; j < n_prenotazioni; j++ ) { 
      // se il medico i-esimo memorizzato nella struct medici ha lo stesso id del medico j-esimo memorizzato nella struct prenotazioni
      if( strncmp( medici[i].Id_medico, prenotazioni[j].Id_medico, 20 ) == 0 ) {
        lista_prenotazioni_SenzaDuplicati[i]++; // incrementa il numero delle prenotazioni
      } // fine di if 
    } // fine di for interno 
  } // fine di for  

  for( int i = 0; i < n_medici; i++ ) {
    lista_prenotazioni[i] = lista_prenotazioni_SenzaDuplicati[i]; 
  } 

  // applica l'algoritmo di ordinamento bubble sort
  for( int i = 0; i < n_medici - 1; i++ ) { // finchè il valore di i è minore del numero di medici - 1
    for( int j = 0; j < n_medici - 1; j++ ) {  // finchè il valore di j è minore del numero di medici - 1
      if( lista_prenotazioni_SenzaDuplicati[j] > lista_prenotazioni_SenzaDuplicati[j + 1] ) { // se il prezzo j-esimo è maggiore del suo successore 
        tmp = lista_prenotazioni_SenzaDuplicati[j]; // poni la variabile temporanea uguale al prezzo j-esimo 
        lista_prenotazioni_SenzaDuplicati[j] = lista_prenotazioni_SenzaDuplicati[j + 1]; // poni il valore j-esimo uguale al suo successore
        lista_prenotazioni_SenzaDuplicati[j + 1] = tmp; // poni il successore del valore j-esimo uguale al valore temporaneo 
      } // fine di if 
    } // fine di for 
  } // fine di for 

   puts( " " );
  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    for( int j = i + 1; j < n_medici; j++ ) { // finchè il valore di j è minore del numero di medici 
      if( lista_prenotazioni_SenzaDuplicati[i] == lista_prenotazioni_SenzaDuplicati[j] ) { // se il prezzo i-esimo è uguale al prezzo j-esimo 
        lista_prenotazioni_SenzaDuplicati[j] = -1; // poni il valore duplicato uguale a zero 
      } // fine di if
    } // fine di for interno 
  } // fine di for  

   for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici 
    if( lista_prenotazioni_SenzaDuplicati[i] != -1 ) { // se il prezzo i-esimo è diverso da zero 
      counter_somma_prenotazioni++; // incrementa il numero di prezzi 
    } // fine di if 
  } // fine di for 


  return counter_somma_prenotazioni; // restituisci il valore del contatore alla funzione chiamante

} // termina la funzione 