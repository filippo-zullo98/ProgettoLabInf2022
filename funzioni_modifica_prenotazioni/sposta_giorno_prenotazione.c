#include <stdio.h>
#include "libr_modifica_prenotazioni.h"

void sposta_giorno_prenotazione( prenotazione prenotazioni[], int counter_prenotazioni, char Id_medico[], char CodFiscale[],
                                 int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione, int ora_prenotazione,
                                 int minuti_prenotazione, medico medici[], int counter_medici, char nome_visita[], valutazione valutazioni[],
                                 int *n_valutazioni )
{ 
  
  int giorno_sostitutivo = 0;
  int mese_sostitutivo = 0;
  int anno_sostitutivo = 0;
  int ora_sostitutiva = 0;
  int minuti_sostitutivi = 0;
  int n_visite_registrate = 0;
  char *lista_visite[n_visite_registrate];
  int n_visite_offerte = 0;
  int result_contr_InsVisita = 0;
  int scelta_visita = 0;
  int flag = 0;
  int risultato_controllo_prenotazione = 0;
  
  puts( "RIEPILOGO PRENOTAZIONE SELEZIONATA: " );
  printf( "Data scelta -> %d/%d/%d\n", giorno_prenotazione, mese_prenotazione, anno_prenotazione );
  if( minuti_prenotazione == 0 ) { // se i minuti della prenotazione sono uguali a zero 
   printf( "Orario -> %d:%d0\n", ora_prenotazione, minuti_prenotazione );  
  } // fine di if 
  
  else { // altrimenti 
   printf( "Orario -> %d:%d\n", ora_prenotazione, minuti_prenotazione );
  } // fine di else 
  

  
  puts( " " );
  /* chiamata alla funzione che mostra all'utente la lista delle visite offerte per il medico da lui specificato */
  n_visite_offerte = output_visite_MedSpecifico( Id_medico, counter_medici, medici, lista_visite );
   while( result_contr_InsVisita != 1 ) { // finchè l'utente seleziona correttamente una delle visite elencate
    printf( "Selezionare il numero di una visita presente nell'elenco---> " );
    scanf( "%d", &scelta_visita ); // ricevi in input dall'utente l'id del medico 
   /* chiamata alla funzione per verificare se l'utente abbia scelto correttamente una fra le visite elencate */
   result_contr_InsVisita = controllo_inserimento_visita( n_visite_offerte, scelta_visita, lista_visite ); 
  } // fine di while  

  /* chiamata alla funzione che mostra all'utente la lista delle date già occupate per un medico da lui specificato */
  output_date_occupate( nome_visita, prenotazioni, counter_prenotazioni, Id_medico  ); 
  fflush( stdin );
  
 while( flag != 1 ) { // finchè il paziente non trova una data disponibile per la sua visita
    /* chiamata alla funzione per la richiesta di input della data della prenotazione da parte del paziente */
    richiesta_data_prenotazione( &giorno_sostitutivo, &mese_sostitutivo, &anno_sostitutivo );
    /* chiamata alla funzione per la richiesta di input dell'orario della prenotazione da parte del paziente */
    richiesta_orario_prenotazione( &ora_sostitutiva, &minuti_sostitutivi );
    /* chiamata alla funzione per il controllo della data e dell'orario richiesti dall'utente per la visita */
    risultato_controllo_prenotazione = controllo_prenotazione_inserita( Id_medico, giorno_sostitutivo, mese_sostitutivo, anno_sostitutivo, 
                                       ora_sostitutiva, minuti_sostitutivi, prenotazioni );
    if( risultato_controllo_prenotazione == 1 ) { // se la data è occupata
     flag = 0; // imposta il valore del flag a zero 
     /* chiamata alla funzione per l'ouput delle prenotazioni già occupate per quel medico richiesto dall'utente */
     output_prenotazioni_occupate( prenotazioni, Id_medico );
    } // fine di if 
     
    else { // altrimenti 
     flag = 1; // imposta il valore del flag a uno     
     puts( "Data confermata!" ); // comunica all'utente che la data richiesta non è occupata        
     /* chiamata alla funzione per la registrazione della nuova data */
     registra_data_spostata( prenotazioni, Id_medico, CodFiscale, giorno_prenotazione, mese_prenotazione,
                             anno_prenotazione, ora_prenotazione, minuti_prenotazione, giorno_sostitutivo, mese_sostitutivo,
                             anno_sostitutivo, ora_sostitutiva, minuti_sostitutivi, nome_visita );  
      carica_file_valutazioni( valutazioni );
      /* chiamata alla funzione per l'aggiornamento della prenotazione registrata nel file delle valutazioni */
      modifica_giorno_valutazione( valutazioni, n_valutazioni, Id_medico, CodFiscale, giorno_prenotazione, 
                                   mese_prenotazione, anno_prenotazione, ora_prenotazione, minuti_prenotazione, 
                                   giorno_sostitutivo, mese_sostitutivo, anno_sostitutivo, ora_sostitutiva, 
                                   minuti_sostitutivi, nome_visita );  
    
    } // fine di else 
      
  } // fine di while


  
    
  
  
} // termina la funzione 