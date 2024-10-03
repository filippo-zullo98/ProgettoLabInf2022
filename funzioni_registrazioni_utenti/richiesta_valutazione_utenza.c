#include "libr_registrazioni_utenti.h"
#include <stdio.h>


void richiesta_valutazione_utenza( int *valutazione_utenza ) {
  
  
  puts( "La preghiamo di rilasciare una valutazione da 0 a 5 inerente al nostro sistema di prenotazione:" );
  scanf( "%d", valutazione_utenza );
  
  while( *valutazione_utenza < 0 || *valutazione_utenza > 5 ) { // finchè l'utente non inserisce un valore corretto
   puts( "Errore!" );
   puts( "La preghiamo di rilasciare una valutazione da 0 a 5 inerente al nostro sistema di prenotazione:" );
   scanf( "%d", valutazione_utenza );
  } // fine di while
  
} // termina la funzione 