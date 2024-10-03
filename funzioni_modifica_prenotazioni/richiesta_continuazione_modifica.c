#include <stdio.h>
#include <stdlib.h>
#include "libr_modifica_prenotazioni.h"

void richiesta_continuazione_modifica() {

  int risposta = 0;
  int flag_risposta = 0;
  
  puts( " " );
  puts( "Selezionare una delle seguenti operazioni:" );
  puts( "1 - Continua l'operazione di modifica della prenotazione." );
  puts( "2 - Ritorno al menù principale." );
  puts( "3 - Terminazione del programma." );
  printf( "Inserisca il numero dell'operazione che intende effettuare---> " );
  scanf( "%d", &risposta );

 while( flag_risposta != 1 ) { // finchè l'utente non sceglie correttamente l'operazione da effettuare
    switch( risposta ) {
      case 1 : // se sceglie di continuare con l'operazione di modifica
      flag_risposta = 1;
      break;      
      
      case 2 : // se sceglie di ritornare al menù principale
       flag_risposta = 1;
       system( "clear" );
        /* chiamata alla funzione per il ritorno al menù principale */
       main();
       break;
      
      case 3 : // se sceglie di terminare l'esecuzione del programma
       flag_risposta = 1;
        /* chiamata alla funzione per la terminazione del programma */
       exit(EXIT_SUCCESS);
       break; 

      default : // se la risposta è errata 
       puts( " " );
       puts( "Selezionare una delle seguenti operazioni:" );
       puts( "1 - Ritorno al menù principale." );
       puts( "2 - Terminazione del programma.");
       printf( "Inserisca il numero dell'operazione che intende effettuare---> " );
       scanf( "%d", &risposta );
    } // termina switch 
  } // fine di while 
  
} // termina la funzione 