#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output_prenotazioni_occupate( prenotazione prenotazioni[], char Id_medico [] ) {
 
  int counter_prenotazioni; // variabile contatore che conterrà il numero di elementi memorizzati nel file delle prenotazioni 

  /* chiamta alla funzione per il caricamento delle informazioni presenti nel file delle prenotazioni */ 
  counter_prenotazioni = carica_file_prenotazioni( prenotazioni );  
  
  system( "clear" );
  puts( "La data da lei scelta è stata già assegnata ad un altro paziente!" );
  puts( "La preghiamo di scegliere un'altra data o un altro orario." );
  puts( "Ecco l'elenco delle prenotazioni già occupate per il medico selezionato:" );
  for( int i = 0; i < counter_prenotazioni; i++ ) { // finchè i è minore del numero di prenotazioni memorizzate nel file 
    /* se l'Id del medico inserito dall'utente è uguale all'id del medico memorizzato nel file */
    if( strncmp( Id_medico, prenotazioni[i].Id_medico, 20 ) == 0 ) { 
      printf( "-> %d/%d/%d\t", prenotazioni[i].giorno_prenotazione, prenotazioni[i].mese_prenotazione, prenotazioni[i].anno_prenotazione );
      /* se i minuti della prenotazione memorizzati nel file sono uguali a zero */
      if( prenotazioni[i].minuti_prenotazione == 0 ) {
       printf( "%d:%d0\n", prenotazioni[i].ora_prenotazione, prenotazioni[i].minuti_prenotazione );
      }  // fine di if     
      else { // altrimenti 
        printf( "%d:%d\n", prenotazioni[i].ora_prenotazione, prenotazioni[i].minuti_prenotazione );
      } // fine di else 

    } // fine di if 
  } // fine di for 

} // termina la funzione 