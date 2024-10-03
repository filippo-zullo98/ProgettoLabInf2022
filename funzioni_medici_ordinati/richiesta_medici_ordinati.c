#include <stdio.h>
#include <stdlib.h>
#include "libr_ordinamento_medici.h"

void richiesta_medici_ordinati( int n_medici, int n_prenotazioni ) {

  medico medici[n_medici];
  prenotazione prenotazioni[n_prenotazioni]; 
  int risposta = 0; 
  
  system( "clear" );

  /* finchè l'utente non sceglie correttamente l'operazione da svolgere */
  while( risposta < 1 || risposta > 6 ) {
   puts( "SELEZIONARE UNA DELLE SEGUENTI OPERAZIONI DI ORDINAMENTO" );
   puts( "1 - Elenco dei medici ordinati in base al prezzo;" );
   puts( "2 - Elenco dei medici ordinati in base al tipo di visita e al prezzo;" );
   puts( "3 - Elenco dei medici ordinati in base alle valutazioni;" );
   puts( "4 - Elenco dei medici ordinati in base al tipo di visita e alle valutazioni;" );
   puts( "5 - Elenco dei medici ordinati in base al numero di prenotazioni;" );
   puts( "6 - Elenco dei medici ordinati in base al tipo di visita e al numero di prenotazioni." );
   printf( "\nInserire il numero corrispondente di una delle seguenti operazioni elencate---> " );
   scanf( "%d", &risposta );
   if( risposta < 1 || risposta > 6 ) { // se l'utente seleziona scorrettamente l'operazione da svolgere
     puts( "Errore!\n" );
    } // fine di if 
  } // fine di while 

  switch( risposta ) {
    case 1 : // se l'operazione scelta è la 1
      /* chiamata alla funzione per l'ordinamento dei medici in base al prezzo */
     ordina_medici_PerPrezzo( medici, n_medici ); 
    break;
    
    case 2 :
      /* chiamata alla funzione per l'ordinamento dei medici in base al tipo di visita e al prezzo */
     ordina_PerPrezzo_PerVisita( medici, n_medici ); 
    break;

    case 3 :
      /* chiamata alla funzione per l'ordinamento dei medici in base alle valutazioni */
     ordina_medici_PerValutazioni( medici, n_medici );
    break;

    case 4 :
      /* chiamata alla funzione per l'ordinamento dei medici in base alle valutazioni e al tipo di visita */
     ordina_PerValutazioni_PerVisita( medici, n_medici ); 
    break;

    case 5 :
     /* chiamata alla funizone per l'output dei medici in base al numero di prenotazioni */
     ordina_PerNum_Prenotazioni( medici, n_medici, prenotazioni, n_prenotazioni );
    break;

    case 6 :
     puts( "Elenco dei medici ordinati in base al tipo di visita e al numero di prenotazioni" );
      ordina_PerVisita_PerNprenot( medici, n_medici, prenotazioni, n_prenotazioni );
    break;
    
  } // fine di switch  

  /* chiamata alla funzione per la richiesta di continuazione dell'operazione di ordinamento*/
  richiesta_continuazione_OpOrdinamento( n_medici, n_prenotazioni );
  /* effettua una chiamata alla stessa funzione in caso l'utente scelga di continuare 
     nell'operazione di ordinamento */
  richiesta_medici_ordinati( n_medici, n_prenotazioni );
  
   
  

} // termina la funzione 