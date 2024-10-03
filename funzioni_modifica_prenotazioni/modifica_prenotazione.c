#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libr_modifica_prenotazioni.h"

void modifica_prenotazione( prenotazione prenotazioni[], char CodFiscale[], medico medici[], int *n_prenotazioni, valutazione valutazioni[],
                            int *n_valutazioni ) 
{
  
  char Id_medico[20];
  char tipo_visita[30];
  int giorno_prenotazione;
  int mese_prenotazione;
  int anno_prenotazione;
  int ora_prenotazione;
  int minuti_prenotazione;
  int counter_prenotazioni;
  int counter_medici;
  int n_visite_registrate = 0;
  char *lista_visite[n_visite_registrate];
  int flag = 0;
  int scelta_visita;
  int n_visite_offerte = 0;
  int result_contr_InsVisita = 0;
  int result_contr_InsMedico = 0;
  int result_contr_InsData = 0;
  int result_contr_InsScelta = 0;
  
   
  /* chiamata alla funzione per il caricamento delle informazioni memorizzate nel file binario "prenotazioni" */
  counter_prenotazioni = carica_file_prenotazioni( prenotazioni );
  /* chiamata alla funzione per il caricamento delle informazioni memorizzate nel file binario "medici" */
  counter_medici = carica_file_visite( medici );
  printf( "\nInserisca l'Id del medico per cui intende spostare la visita---> " ); 
  while( getchar() != '\n' );  
  fgets( Id_medico, 20, stdin );  
  // finchè l'utente non ha scelto correttamente un medico per il quale abbia effettuato una prenotazione 
  while( result_contr_InsMedico < 1 ) { 
   /* chiamata alla funzione per verificare se l'utente abbia scelto un medico per il quale abbia registrato una prenotazione */
   result_contr_InsMedico = controllo_scelta_medico(  prenotazioni, counter_prenotazioni, 
                             CodFiscale, Id_medico, tipo_visita );  
  } // fine di while 
  
  /* chiamata alla funzione che mostra all'utente la lista delle visite disponibili per quel medico */
  n_visite_offerte = output_visite_MedSpecifico( Id_medico, counter_medici, medici, lista_visite );
  while( result_contr_InsVisita != 1 ) { // finchè l'utente seleziona correttamente una delle visite elencate
    printf( "\nSelezionare il numero di una visita presente nell'elenco---> " );
    scanf( "%d", &scelta_visita ); // ricevi in input dall'utente l'id del medico 
   /* chiamata alla funzione per verificare se l'utente abbia scelto correttamente una fra le visite elencate */
   result_contr_InsVisita = controllo_inserimento_visita( n_visite_offerte, scelta_visita, lista_visite ); 
  } // fine di while 

  // finchè l'utente non inserisce correttamente una delle date mostrate nell'elenco
  while( result_contr_InsData != 1 ) { 
    /* chiamata alla funzione per l'input e il controllo della data da modificare */
    result_contr_InsData = richiesta_data( prenotazioni, &giorno_prenotazione, &mese_prenotazione, &anno_prenotazione, &ora_prenotazione, 
                  &minuti_prenotazione, counter_prenotazioni, Id_medico, CodFiscale );
  } // fine di while  

  system( "clear" );  
  /* chiamata alla funzione per l'output delle operazioni di modifica della data selezionata */
  result_contr_InsScelta = scelta_OpModifica();
  puts( " " );
  if( result_contr_InsScelta == 1  ) { // se il paziente decide di spostare la data della prenotazione
    /* chiamata alla funzione per lo spostamento della prenotazione */
    sposta_giorno_prenotazione( prenotazioni, counter_prenotazioni, Id_medico, CodFiscale, 
                                giorno_prenotazione, mese_prenotazione, anno_prenotazione,
                                ora_prenotazione, minuti_prenotazione, medici, 
                                counter_medici, tipo_visita, valutazioni, n_valutazioni );
    
  } // fine di if 

  else { // altrimenti 
    /* chiamata alla funzione per la cancellazione della prenotazione */
    cancella_giorno_prenotazione( prenotazioni, n_prenotazioni, Id_medico, CodFiscale, 
                                  giorno_prenotazione, mese_prenotazione, anno_prenotazione, 
                                  ora_prenotazione, minuti_prenotazione, tipo_visita );
  } // fine di else 
  
  
  
  
  
} // termina la funzione 