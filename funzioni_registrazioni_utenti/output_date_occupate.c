#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <string.h>

void output_date_occupate( char nome_visita[], prenotazione prenotazioni[], int counter_prenotazioni, char Id_medico[] ){
  int count = 0;
  
 
  puts( "\n\nDate prenotate per il medico selezionato:" ); 
  count = 0; // reinizializza il valore del contatore a zero 
  for( int i = 0; i < counter_prenotazioni; i++ ) { // cicla sulla struct delle prenotazioni
    /* effettua dei confronti sulla struct prenotazioni tra l'id inserito dall'utente e quelli presenti nella struct prenotazioni */
    if( strncmp( Id_medico, prenotazioni[i].Id_medico, 20 ) == 0 ) { 
    /* effettua dei confronti sulla struct prenotazioni tra il tipo di visita inserita dall'utente e quelle presenti nella struct prenotazioni */
     if( strncmp( nome_visita, prenotazioni[i].tipo_visita, 30 ) == 0 ) {
       printf( "-> %d/%d/%d\n", prenotazioni[i].giorno_prenotazione, prenotazioni[i].mese_prenotazione, prenotazioni[i].anno_prenotazione );
       if( prenotazioni[i].minuti_prenotazione == 0 ) { 
         printf( "ORARI OCCUPATI:\n%d:%d0\n\n", prenotazioni[i].ora_prenotazione, prenotazioni[i].minuti_prenotazione );
        } // fine di if interno
        else { // altrimenti 
         printf( "ORARI OCCUPATI:\n%d:%d\n\n", prenotazioni[i].ora_prenotazione, prenotazioni[i].minuti_prenotazione );
        } // fine di else 
       count++; // incrementa il valore del contatore        
      } // fine di if interno
    } // fine di if  
   
  } // fine di for 

  if( count == 0 ) { // se il contatore è uguale a zero
    puts( "-> non ci sono date prenotate." );
  } // fine di if  
  




  
} // termina la funzione 