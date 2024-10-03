#include "libr_registrazioni_utenti.h"
#include <stdio.h>

void richiesta_orario_prenotazione( int *ora_prenotazione, int *minuti_prenotazione ) {
  /* la variabile flag contiene un valore binario che se va a 0 da valore vero e se va a 1 da valore falso */
  int flag_minuti = 0; 
  int flag_ora = 0;
  
  
  while( flag_ora != 1 ) { // finchè il paziente immette un'ora errata
    puts( "Inserisci l'ora della prenotazione:" );
    scanf( "%d", ora_prenotazione );
    /* se l'ora è compresa tra 8 e 12 o tra 15 e 18 */
    if( *ora_prenotazione >= 8 && *ora_prenotazione <= 12 || *ora_prenotazione >= 15 && *ora_prenotazione <= 18 ) {
     flag_ora = 1; // imposta il valore del flag a 1 ed esci dal ciclo while 
    } // fine di if 
    
    else { // altrimenti 
      flag_ora = 0; // imposta il valore del flag a zero 
      puts( "Errore! il medico non è disponibile per questa ora." );
    } // fine di else 
  
  } // fine di while 
  

  while( flag_minuti != 1 ) { // finchè il paziente immette i minuti in maniera errata 
    puts( "Inserisci i minuti della prenotazione:" ); 
    scanf( "%d", minuti_prenotazione );
    /* se i minuti sono equivalenti a zero o a trenta */
    if( *minuti_prenotazione == 0 || *minuti_prenotazione == 30 ) { // le visite possono essere effettuate solo ogni 30 minuti 
     flag_minuti = 1; // imposta il valore del flag a 1 ed esci dal ciclo while  
    } // fine di if 
    
    else { // altrimenti 
      flag_minuti = 0; // imposta il valore del flag a zero 
      puts( "Errore! è possibile effettuare una prenotazione per ogni 30 minuti" );
    } // fine di else  
  
  } // fine di while 



} // termina la funzione 