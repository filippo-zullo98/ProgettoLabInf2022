#include <stdio.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void output_listCresc_prenotazioni( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni, int lista_prenotazioni[], 
                                  int lista_prenotazioni_SenzaDuplicati[], int counter_somma_prenotazioni, int new_lista_prenotazioni[] ) 
{

  int j = 0;
  
  /* chiamata alla funzione per il caricamento delle informazioni memorizzate nel file binario "PRENOTAZIONI" */
  carica_file_prenotazioni( prenotazioni );

  for( int i = 0; i < n_medici; i++ ) { // finchè il valore di i è minore del numero dei medici
    if( lista_prenotazioni_SenzaDuplicati[i] != -1 ) { // se il valore i-esimo è diverso da -1
      /* poni l'elemento j-esimo della nuova lista delle prenotazioni uguale all'elemento i-esimo della 
         lista delle prenotazioni senza duplicati */
      new_lista_prenotazioni[j] = lista_prenotazioni_SenzaDuplicati[i];
      j++; // incrementa il valore di j
    } // fine di if 
  } // fine di for 

  system( "clear" );
  
  puts( " " );
  puts( "LISTA MEDICI IN ORDINE CRESCENTE PER NUMERO DI PRENOTAZIONI" );
  // finchè il valore di i è minore del contatore delle somme delle prenotazioni
  for( int i = 0; i < counter_somma_prenotazioni; i++ ) { 
    // finchè il valore di j è minore del numero di medici memorizzati nel file binario "VISITE"
    for( int j = 0; j < n_medici; j++  ) { 
      // se l'elemento i-esimo della nuova lista delle prenotazioni è uguale all'elemento j-esimo della lista delle prenotazioni 
      if( new_lista_prenotazioni[i] == lista_prenotazioni[j] ) { 
        printf( "-> Id medico: %s", medici[j].Id_medico );
        printf( "-> Nome medico: %s", medici[j].nome_medico );
        printf( "-> Cognome medico: %s", medici[j].cognome_medico );
        printf( "-> Tipo di visita medica: %s\n", medici[j].tipo_visita );
        printf( "-> num pazienti prenotati: %d\n", new_lista_prenotazioni[i] );
        printf( "-> Prezzo visita medica:  %.2f\n", medici[j].prezzo );       
        puts( " " );        
      } // fine di if 
    } // fine di for interno 
  } // fine di for 
  
  
} // termina la funzione 