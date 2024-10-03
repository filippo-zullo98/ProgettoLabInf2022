#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libr_modifica_prenotazioni.h"

void registra_data_spostata( prenotazione prenotazioni[], char Id_medico[], char CodFiscale[], int giorno_prenotazione, 
                             int mese_prenotazione, int anno_prenotazione, int ora_prenotazione, int minuti_prenotazione, 
                             int giorno_sostitutivo, int mese_sostitutivo, int anno_sostitutivo, int ora_sostitutiva, 
                             int minuti_sostitutivi, char nome_visita[] )
{
  
  int counter_prenotazioni;
  FILE *fPtr;
  int n_prenotazione;
  
  /* chiamata alla funzione per il caricamento delle informazioni memorizzate nel file delle prenotazioni*/
  counter_prenotazioni = carica_file_prenotazioni( prenotazioni ); 
  
  /* finchè il valore di i è minore del numero delle prenotazioni presenti nel file binario "PRENOTAZIONI" */  
  for( int i = 0; i < counter_prenotazioni; i++ ) {
    /* se il codice fiscale presente nel file delle prenotazioni coincide con il codice fiscale inserito dall'utente */
    if( strncmp( CodFiscale, prenotazioni[i].CodFiscale, 17 ) == 0 ) {
     /* se l'id del medico presente nel file delle prenotazioni coincide con l'id del medico inserito dall'utente */
     if( strncmp( Id_medico, prenotazioni[i].Id_medico, 20 ) == 0 ) {
      /* se il nome della visita coincide con quello presente nel file delle prenotazioni */
       if( strncmp( nome_visita, prenotazioni[i].tipo_visita, 30 ) == 0   ) {
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
                   prenotazioni[i].giorno_prenotazione = giorno_sostitutivo;
                   prenotazioni[i].mese_prenotazione = mese_sostitutivo;
                   prenotazioni[i].anno_prenotazione = anno_sostitutivo;
                   prenotazioni[i].ora_prenotazione = ora_sostitutiva;
                   prenotazioni[i].minuti_prenotazione = minuti_sostitutivi;
                   n_prenotazione = i;
                  }
                }
              }
            }
          }
        }
      }
    }      
  } // fine di for  

  
  fPtr = fopen( "prenotazioni.dat", "wb" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  // Lettura del file 
  else { // altrimenti
   fwrite( prenotazioni, sizeof( prenotazione ), counter_prenotazioni, fPtr );  
  } // fine di else

  

  fclose( fPtr ); // chiusura del file 
  
} // termina la funzione