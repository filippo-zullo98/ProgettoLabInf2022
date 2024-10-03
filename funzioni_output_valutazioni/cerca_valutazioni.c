#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libr_media_valutazioni.h"

int cerca_valutazioni( char Id_medico[], int n_valutazioni, valutazione valutazioni[] ) {
  
  int value = 0;
  int frequency = 0; // variabile che contiene il numero di voti memorizzati per un medico specifico  
  float valutazione = 0; 
  float stars = 0; // variabile che contiene il numero di stelle che rappresentano la media delle valutazioni 
  
  /* chiamata alla funzione per il caricamento delle informazioni memorizzate nel file binario "valutazioni" */
  carica_file_valutazioni( valutazioni ); 
  
  
  for( int i = 0; i < n_valutazioni; i++ ) { // finchè il valore di i è minore del numero delle valutazioni presenti nel file 
    /* se l'Id del medico inserito dal paziente coincide con quello memorizzato nel file delle valutazioni */
    if( strncmp( Id_medico, valutazioni[i].Id_medico, 20 ) == 0 ) { 
      value = 1; // poni il valore di value uguale a 1
      valutazione = valutazioni[i].valutazione + valutazione; // somma a valutazione il valore della valutazione trovata nel file 
      frequency++; // incrementa il numero di valutazioni trovate per quel medico       
    } // fine di if 
    
  } // fine di for 

  
  if( value == 1 ) { // se il valore di value è 1
   system( "clear" );
   puts( "medico trovato!!" ); 
   printf( "Average %s", Id_medico  );
   printf( "-> %.2f",valutazione / frequency ); // mostra la media
   stars = valutazione / frequency; // poni il valore di stars uguale alla media delle valutazioni
   printf( "\nValutazione: " );
   /* finchè il valore di i è minore di stars */
   for( int i = 0; i < (int)stars; i++ ) {
     printf( "*" ); // stampa una stella
    } // fine di for 
  
  } // fine di if 

  puts( " " );
  return value; // restituisci il valore di value alla funzione chiamante 
  
} // termina la funzione 