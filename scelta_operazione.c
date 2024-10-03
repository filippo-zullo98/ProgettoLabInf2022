#include "libr_menu_utente.h"
#include <stdio.h>

void scelta_operazione( int n_medici, int *n_utenti, int *n_prenotazioni, int *n_valutazioni ) {

 int scelta_utente; 
 int flag = 0; 

 while( flag != 1 ) { // finchè il paziente non inserisce correttamente il numero dell'operazione da svolgere 
   puts( "Scegliere un operazione:" );
   puts( "1 - Richiesta di prenotazione;" );
   puts( "2 - Richiesta di modifica di una prenotazione;" );
   puts( "3 - Richiesta di visualizzazione delle statistiche;" );
   puts( "4 - Richiesta output medici ordinati." );
   printf( "Inserisci il numero di una delle 4 operazioni---> " );
   scanf( "%d", &scelta_utente ); 
   switch( scelta_utente ) {
     case 1 : // se l'operazione scelta dal paziente è numero 1
      /* chiamata alla funzione per la richiesta di nuove prenotazioni */
      richiesta_prenotazione( n_prenotazioni, n_utenti, n_valutazioni );
      flag = 1; // imposta ad 1 il valore del flag ed esci dal ciclo while 
      break;

     case 2 : // se l'operazione scelta dal paziente è la numero 3
      /* chiamata alla funzione per la richiesta di modifica della visita da parte del paziente */
      richiesta_modifica_prenotazione( n_prenotazioni, n_valutazioni );
      flag = 1; // imposta ad 1 il valore del flag ed esci dal ciclo while 
      break;

     case 3 : // se l'operazione scelta dal paziente è la numero 4
      /* chiamata alla funzione per l'output della media delle valutazioni per un medico specifico */
      richiesta_output_valutazioni( n_valutazioni, &n_medici );
      flag = 1; // imposta ad 1 il valore del flag ed esci dal ciclo while 
      break;

     case 4 : // se l'operazione scelta dal paziente è la numero 5
      richiesta_medici_ordinati( n_medici, *n_prenotazioni );
      flag = 1;// imposta ad 1 il valore del flag ed esci dal ciclo while 
      break;

     default:
      puts( "Il numero dell'operazione da lei selezionata è inesistente!\n\n\n" );
    
    } // termina switch
  } // fine di while 
  
  
} // termina la funzione 