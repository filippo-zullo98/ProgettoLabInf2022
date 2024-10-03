#include <stdio.h>
#include "libr_caricamento_files.h"

void stampa_dati_valutazioni( valutazione valutazioni[], int n_valutazioni ) {

  for( int i = 0; i < n_valutazioni; i++ ) {
    printf( "CodFiscale Paziente: %s\n", valutazioni[i].CodFiscale );
    printf( "Identificativo Medico: %s", valutazioni[i].Id_medico );
    printf( "Tipo di visita: %s\n", valutazioni[i].tipo_visita );
    printf( "Valutazione: %d\n", valutazioni[i].valutazione );
    printf( "Giorno della prenotazione: %d\n", valutazioni[i].giorno_prenotazione );
    printf( "Mese della prenotazione: %d\n", valutazioni[i].mese_prenotazione );
    printf( "Anno della prenotazione: %d\n", valutazioni[i].anno_prenotazione ); 
    printf( "Ora della prenotazione: %d\n", valutazioni[i].ora_prenotazione );
    if( valutazioni[i].minuti_prenotazione == 0 ) {
      printf( "Minuti prenotazione: %d0\n\n", valutazioni[i].minuti_prenotazione );
    }
    
    else {
     printf( "Minuti prenotazione: %d\n\n", valutazioni[i].minuti_prenotazione );
    }
  }

  
  
  
} // termina la funzione
