#include <stdio.h>
#include <stdlib.h>
#include "libr_media_valutazioni.h"

void richiesta_ritorno_menu( ) {
  
  
  enum utente { si = 1, no } risposta;
  int flag_risposta = 0;
  
  puts( " " );
  puts( "Selezionare una delle seguenti operazioni:" );
  puts( "1 - Ritorno al menù principale." );
  puts( "2 - Terminazione del programma.");
  printf( "Inserisca il numero dell'operazione che intende effettuare---> " );
  scanf( "%d", &risposta );

 while( flag_risposta != 1 ) { // finchè l'utente non sceglie correttamente l'operazione da effettuare
    switch( risposta ) {
      case si : // se sceglie si 
       flag_risposta = 1;
       system( "clear" );
       main();
       break;
      
      case no : // se sceglie no 
       flag_risposta = 1;
       puts( "exit" );       
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



