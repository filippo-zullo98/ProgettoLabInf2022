#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <string.h>

void registra_nuova_valutazione( valutazione valutazioni[], int *n_valutazioni, char CodFiscale[], char Id_medico[],
                                  char nome_visita[], int valutazione_utenza, int giorno_prenotazione, int mese_prenotazione,
                                  int anno_prenotazione, int ora_prenotazione, int minuti_prenotazione )
{

  FILE *fPtr; // variabile puntatore ad una struct di tipo file 

  /* memorizza tutti i dati immessi dal paziente che interessano la valutazione che intende registrare */
  strncpy( valutazioni[*n_valutazioni - 1].CodFiscale, CodFiscale, 17 );
  strncpy( valutazioni[*n_valutazioni - 1].Id_medico, Id_medico, 20 );
  strncpy( valutazioni[*n_valutazioni - 1].tipo_visita, nome_visita, 30 );
  valutazioni[*n_valutazioni - 1].valutazione = valutazione_utenza;
  valutazioni[*n_valutazioni - 1].giorno_prenotazione = giorno_prenotazione;
  valutazioni[*n_valutazioni - 1].mese_prenotazione = mese_prenotazione;
  valutazioni[*n_valutazioni - 1].anno_prenotazione = anno_prenotazione;
  valutazioni[*n_valutazioni - 1].ora_prenotazione = ora_prenotazione;
  valutazioni[*n_valutazioni - 1].minuti_prenotazione = minuti_prenotazione;     

  fPtr = fopen( "valutazioni.dat", "ab" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  // Lettura del file 
  else { // altrimenti
  fwrite( valutazioni[*n_valutazioni - 1].CodFiscale, sizeof( valutazione ), 1, fPtr );
  } // fine di else

  

  fclose( fPtr ); // chiusura del file */ 

  
} // termina la funzione 