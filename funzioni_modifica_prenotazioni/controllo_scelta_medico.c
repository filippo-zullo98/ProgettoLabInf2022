#include <stdio.h>
#include <string.h>
#include "libr_modifica_prenotazioni.h"

int controllo_scelta_medico( prenotazione prenotazioni[], int counter_prenotazioni, 
                             char CodFiscale[], char Id_medico[], char tipo_visita[] )
{

  int n_visite_prenotate = 0;
  
  // finchè il valore di i è minore del numero di prenotazioni memorizzate nel file delle prenotazioni
  for( int i = 0; i < counter_prenotazioni; i++ ) { 
    // se il codice fiscale immesso dall'utente è uguale a quello memorizzato nel file delle prenotazioni
    if( strncmp( CodFiscale, prenotazioni[i].CodFiscale, 17 ) == 0 ) { 
      // se l'id del medico immesso dall'utente è uguale a quello memorizzato nel file delle prenotazioni
      if( strncmp( Id_medico, prenotazioni[i].Id_medico, 20 ) == 0 ) {
        // copia il tipo di visita presente nel file prenotazioni nella variabile tipo_visita
        strncpy( tipo_visita, prenotazioni[i].tipo_visita, 30 );         
        // incrementa il numero di visite prenotate
        n_visite_prenotate = n_visite_prenotate + 1;  
        break;
      } // fine di if interno     
    } // fine di if 
  } // fine di for 

  // se l'utente ha inserito un medico per il quale non ha effettuato alcuna prenotazione
  if( n_visite_prenotate == 0 ) { 
   puts( "Errore! nessuna visita prenotata per questo medico!" );
   printf( "\nInserisca l'Id del medico per cui intende spostare la visita---> " ); 
   fgets( Id_medico, 20, stdin ); 
  } // fine di if 

  return n_visite_prenotate; // restituisci il numero di visite prenotate alla funzione chiamante
  
} // termina la funzione 