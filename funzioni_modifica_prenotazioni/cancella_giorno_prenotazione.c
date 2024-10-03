#include <stdio.h>
#include <string.h>
#include "libr_modifica_prenotazioni.h"

void cancella_giorno_prenotazione( prenotazione prenotazioni[], int *n_prenotazioni, char Id_medico[], 
                                   char CodFiscale[], int giorno_prenotazione, int mese_prenotazione, 
                                   int anno_prenotazione, int ora_prenotazione, int minuti_prenotazione,
                                   char tipo_visita[] ) 
{
  /* chiamata alla funzione per il caricamento delle informazioni presenti nel file delle prenotazioni */
  carica_file_prenotazioni( prenotazioni );
  int indice_data = 0; // variabile che conterrà l'indice degli elementi da cancellare all'interno della struct  

  // finchè il valore di i è minore del numero delle prenotazioni presenti nel file binario "PRENOTAZIONI"
  for( int i = 0; i < *n_prenotazioni; i++ ) { 
   /* se il codice fiscale presente nel file delle prenotazioni coincide con il codice fiscale inserito dall'utente */
   if( strncmp( CodFiscale, prenotazioni[i].CodFiscale, 17 ) == 0 ) {
    /* se l'id del medico presente nel file delle prenotazioni coincide con l'id del medico inserito dall'utente */
     if( strncmp( Id_medico, prenotazioni[i].Id_medico, 20 ) == 0 ) {
      /* se il nome della visita coincide con quello presente nel file delle prenotazioni */
       if( strncmp( tipo_visita, prenotazioni[i].tipo_visita, 30 ) == 0 ) {
        /* se il giorno della prenotazione presente nel file delle prenotazioni coincide con il giorno della 
          prenotazione inserita dall'utente */ 
         if( giorno_prenotazione == prenotazioni[i].giorno_prenotazione ) {
           /* se il mese della prenotazione presente nel file delle prenotazioni coincide con il mese della 
             prenotazione inserita dall'utente */
           if( mese_prenotazione == prenotazioni[i].mese_prenotazione ) {
              /* se l'anno della prenotazione presente nel file delle prenotazioni coincide con l'anno della 
              prenotazione inserito dall'utente */
             if( anno_prenotazione == prenotazioni[i].anno_prenotazione ) {
               /* se l'ora della prenotazione presente nel file delle prenotazioni coincide con l'ora della 
                 prenotazione inserita dall'utente */
               if( ora_prenotazione == prenotazioni[i].ora_prenotazione ) {
                 /* se i minuti della prenotazione presenti nel file delle prenotazioni coincidono con i minuti 
                    della prenotazione inseriti dall'utente */
                 if( minuti_prenotazione == prenotazioni[i].minuti_prenotazione ) {
                   indice_data = i; // poni il valore dell'indice uguale al valore di i 
                  } 
                }              
              }
            }
          }
        }
      }
    }
  } // fine di for 

  
  /* finchè il valore di i è minore del numero delle prenotazioni presenti nel file binario "PRENOTAZIONI" */
  for( int i = indice_data; i < *n_prenotazioni; i++ ) {
   if( i < *n_prenotazioni ) { // se l'indice il valore di i è minore del numero delle prenotazioni
     // sposta ogni elemento spostandolo di una posizione 
     strncpy( prenotazioni[i].CodFiscale, prenotazioni[i + 1].CodFiscale, 17 );
     strncpy( prenotazioni[i].Id_medico, prenotazioni[i + 1].Id_medico, 20 );
     strncpy( prenotazioni[i].tipo_visita, prenotazioni[i + 1].tipo_visita, 30 );
     prenotazioni[i].giorno_prenotazione = prenotazioni[i + 1].giorno_prenotazione;
     prenotazioni[i].mese_prenotazione = prenotazioni[i + 1].mese_prenotazione;
     prenotazioni[i].anno_prenotazione = prenotazioni[i + 1].anno_prenotazione;
     prenotazioni[i].ora_prenotazione = prenotazioni[i + 1].ora_prenotazione;
     prenotazioni[i].minuti_prenotazione = prenotazioni[i + 1].minuti_prenotazione;
    } // fine di if 
    
  }  // fine di for 
 
  *n_prenotazioni = *n_prenotazioni - 1; // decrementa il numero di prenotazioni memorizzate nel file binario "PRENOTAZIONI"

  /* chiamata alla funzione per la cancellazione dal file binario della prenotazione scelta dall'utente */
  registra_data_cancellata( prenotazioni, *n_prenotazioni );
  
    
  
  
  
} // termina la funzione 