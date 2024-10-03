#include "libr_registrazioni_utenti.h"
#include <stdio.h>

int richiesta_avvio_operazione() {
  int flag = 0;
  char response;
  
  puts( "Intende proseguire nella registrazione della prenotazione ? Y|N " );
  while( getchar() != '\n' );
  scanf( "%c", &response );
  if( response == 'Y' || response == 'y' ) {  // se la risposta immessa dall'utente è si 
    flag = 1; // imposta il valore del flag a 1
  } // fine di if 

  else if( response == 'N' || response == 'n' ) { // se la risposta immessa dall'utente è no 
    flag = 2; // imposta il valore del flag a 2
  } // fine di else if 

  else if( flag == 0 ) { // se l'utente non ha risposto in maniera errata  
   puts( "Errore nella digitazione!" ); 
  } // fine di else if 

  return flag; // restituisci il valore di ritorno alla funzione chiamante 
  
} // termina la funzione 