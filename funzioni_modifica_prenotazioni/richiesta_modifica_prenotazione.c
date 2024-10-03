#include <stdio.h>
#include <stdlib.h>
#include "libr_modifica_prenotazioni.h"

void richiesta_modifica_prenotazione( int *n_prenotazioni, int *n_valutazioni ) {
  prenotazione prenotazioni[*n_prenotazioni];
  valutazione valutazioni[*n_valutazioni];
  medico medici[N_MEDICI];
  char CodFiscale[17];
  int risultato_ricerca_prenotazione;
  
  
  system( "clear" ); 
  /* chiamata alla funzione per il controllo del codice fiscale */
  controllo_cod_fiscale( CodFiscale );

  /* chiamata alla funzione per la verifica dell'esistenza della prenotazione all'interno del programma */
  risultato_ricerca_prenotazione = cerca_prenotazione( prenotazioni, CodFiscale );
  if( risultato_ricerca_prenotazione == 1  ) { // se la prenotazione viene rilevata all'interno del programma
    /* effettua una chiamata alla funzione che richiede all'utente se intende continuare nella modifica */
    richiesta_continuazione_modifica();
    /* chiamat alla funzione per la modifica della prenotazione */
    modifica_prenotazione( prenotazioni, CodFiscale, medici, n_prenotazioni, valutazioni, n_valutazioni );    
  } // fine di if 
  else { // altrimenti  
    puts( "non è stato trovato nulla" );
  } // fine di else

} // termina la funzione 