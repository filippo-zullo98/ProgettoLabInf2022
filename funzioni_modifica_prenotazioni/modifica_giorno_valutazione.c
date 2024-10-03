#include <stdio.h>
#include <string.h>
#include "libr_modifica_prenotazioni.h"

void modifica_giorno_valutazione( valutazione valutazioni[], int *n_valutazioni, char Id_medico[], char CodFiscale[], 
                                   int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione, 
                                   int ora_prenotazione, int minuti_prenotazione, int giorno_sostitutivo, 
                                   int mese_sostitutivo, int anno_sostitutivo, int ora_sostitutiva, 
                                   int minuti_sostitutivi, char nome_visita[] )
{

  FILE *fPtr;
  
  /* finchè il valore di i è minore del numero delle prenotazioni presenti nel file binario "VALUTAZIONI" */  
  for( int i = 0; i < *n_valutazioni; i++ ) {
    /* se il codice fiscale presente nel file delle valutazioni coincide con il codice fiscale inserito dall'utente */
    if( strncmp( CodFiscale, valutazioni[i].CodFiscale, 17 ) == 0 ) {
      /* se l'id del medico presente nel file delle valutazioni coincide con l'id del medico inserito dall'utente */
      if( strncmp( Id_medico, valutazioni[i].Id_medico, 20 ) == 0 ) {
        /* se il nome della visita coincide con quello presente nel file delle valutazioni */
        if( strncmp( nome_visita, valutazioni[i].tipo_visita, 30 ) == 0 ) {
          /* se il giorno della prenotazione presente nel file delle valutazioni coincide con il giorno della 
          prenotazione inserita dall'utente */ 
          if( giorno_prenotazione == valutazioni[i].giorno_prenotazione ) {
            /* se il mese della prenotazione presente nel file delle valutazioni coincide con il mese della 
             prenotazione inserita dall'utente */
            if( mese_prenotazione == valutazioni[i].mese_prenotazione ) {
              /* se l'anno della prenotazione presente nel file delle valutazioni coincide con l'anno della 
              prenotazione inserito dall'utente */
              if( anno_prenotazione == valutazioni[i].anno_prenotazione ) {
                /* se l'ora della prenotazione presente nel file delle valutazioni coincide con l'ora della 
                 prenotazione inserita dall'utente */
                if( ora_prenotazione == valutazioni[i].ora_prenotazione ) {
                  /* se i minuti della prenotazione presenti nel file delle valutazioni coincidono con i minuti 
                    della prenotazione inseriti dall'utente */
                  if( minuti_prenotazione == valutazioni[i].minuti_prenotazione ) {
                    valutazioni[i].giorno_prenotazione = giorno_sostitutivo;
                    valutazioni[i].mese_prenotazione = mese_sostitutivo;
                    valutazioni[i].anno_prenotazione = anno_sostitutivo;
                    valutazioni[i].ora_prenotazione = ora_sostitutiva;
                    valutazioni[i].minuti_prenotazione = minuti_sostitutivi;                    
                  }
                }
              }
            }
          }
        }
      }
    }      
  } // fine di for 

  fPtr = fopen( "valutazioni.dat", "wb" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  // Lettura del file 
  else { // altrimenti
   fwrite( valutazioni, sizeof( valutazione ), *n_valutazioni, fPtr );  
  } // fine di else

  

  fclose( fPtr ); // chiusura del file 

  
  
  
  
} // termina la funzione 