#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <string.h>

void aggiungi_paziente( char Id_medico[], int flag_sesso, prenotazione prenotazioni[], utente utenti[],
                        valutazione valutazioni[], char nome_visita[], int *n_utenti, int *n_valutazioni, int *n_prenotazioni ) 
{
  
  char CodFiscale[17]; 
  int risultato_ricerca_paziente = 0;
  char nome_paziente[20];
  char cognome_paziente[20];
  char sesso;
  int giorno_nascita;
  int mese_nascita;
  int anno_nascita;
  int controllo_compatibilità_sesso = 0;
  int flag = 0;
  int giorno_prenotazione;
  int mese_prenotazione;
  int anno_prenotazione;
  int ora_prenotazione;
  int minuti_prenotazione;
  int risultato_controllo_prenotazione = 0;
  int valutazione_utenza;
  int n_record_valutazioni;
   
 
  /* chiamata alla funzione per l'input e la verifica della correttezza del codice fiscale */
  controllo_cod_fiscale( CodFiscale ); 
  /* chiamta alla funzione per verificare se il paziente è già registrato o meno nel sistema */
  /* questa funzione effettua anche un controllo sulla visita scelta dall'utente */
  risultato_ricerca_paziente = cerca_paziente( utenti, CodFiscale, nome_paziente, cognome_paziente, &sesso, &giorno_nascita, 
                                           &mese_nascita, &anno_nascita, flag_sesso, &controllo_compatibilità_sesso );

  
  if( risultato_ricerca_paziente == 1 && controllo_compatibilità_sesso == 0 ) { // se il paziente è già memorizzato nel sistema 
    while( flag != 1 ) { // finchè il paziente non trova una data disponibile per la sua visita
      /* chiamata alla funzione per la richiesta di input della data della prenotazione da parte del paziente */
      richiesta_data_prenotazione( &giorno_prenotazione, &mese_prenotazione, &anno_prenotazione );
      /* chiamata alla funzione per la richiesta di input dell'orario della prenotazione da parte del paziente */
      richiesta_orario_prenotazione( &ora_prenotazione, &minuti_prenotazione );
      /* chiamata alla funzione per il controllo della data e dell'orario richiesti dall'utente per la visita */
      risultato_controllo_prenotazione = controllo_prenotazione_inserita( Id_medico, giorno_prenotazione, mese_prenotazione, anno_prenotazione, 
                                         ora_prenotazione, minuti_prenotazione, prenotazioni );
      if( risultato_controllo_prenotazione == 1 ) { // se la data è occupata
       flag = 0; // imposta il valore del flag a zero 
       /* chiamata alla funzione per l'ouput delle prenotazioni già occupate per quel medico richiesto dall'utente */
       output_prenotazioni_occupate( prenotazioni, Id_medico );
      } // fine di if 
     
     else { // altrimenti 
       flag = 1; // imposta il valore del flag a uno     
       puts( "Data confermata!" ); // comunica all'utente che la data richiesta non è occupata 
       /* chiamata alla funzione per la richiesta di input di una valutazione da parte del paziente */
       richiesta_valutazione_utenza( &valutazione_utenza ); 
       /* chiamta alla funzione per il caricamento delle informazioni presenti nel file delle valutazioni */
       carica_file_valutazioni( valutazioni );
       *n_valutazioni = *n_valutazioni + 1; // incrementa il numero di valutazioni memorizzate nel file binario "valutazioni"
       /* chiamata alla funzione per la registrazione della nuova valutazione all'interno del file binario "valutazioni" */
       registra_nuova_valutazione( valutazioni, n_valutazioni, CodFiscale, Id_medico, nome_visita, 
                                valutazione_utenza, giorno_prenotazione, mese_prenotazione, anno_prenotazione,
                                ora_prenotazione, minuti_prenotazione );
       /* chiamta alla funzione per il caricamento delle informazioni presenti nel file delle prenotazioni */
       carica_file_prenotazioni( prenotazioni );
       *n_prenotazioni = *n_prenotazioni + 1; // incrementa il numero di preotazioni memorizzate nel fila binario "prenotazioni"
       /* chiamata alla funzione per la registrazione della nuova valutazione all'interno del file binario "prenotazioni" */
       registra_nuova_prenotazione( prenotazioni, n_prenotazioni,CodFiscale, Id_medico, nome_visita,
                                 giorno_prenotazione, mese_prenotazione, anno_prenotazione, ora_prenotazione,
                                 minuti_prenotazione );
       
      } // fine di else 
      
    } // fine di while
    
   
  } // fine di if 
  

  else if( risultato_ricerca_paziente == 0 ) { // se il paziente non è già memorizzato nel sistema 
   /* chiamta alla funzione per la richiesta di input dell'anagrafica da parte del paziente */
   richiesta_anagrafica_paziente( nome_paziente, cognome_paziente, &sesso, flag_sesso, &anno_nascita, &mese_nascita, &giorno_nascita );
   while( flag != 1 ) { // finchè non il paziente non occupa un giorno libero del medico da lui scelto
     /* chiamata alla funzione per la richiesta di input della data della prenotazione da parte del paziente */
     richiesta_data_prenotazione( &giorno_prenotazione, &mese_prenotazione, &anno_prenotazione );
     /* chiamata alla funzione per la richiesta di input dell'orario della prenotazione da parte del paziente */
     richiesta_orario_prenotazione( &ora_prenotazione, &minuti_prenotazione );
     /* chiamata alla funzione per il controllo della data e dell'orario richiesti dall'utente per la visita */
     risultato_controllo_prenotazione = controllo_prenotazione_inserita( Id_medico, giorno_prenotazione, mese_prenotazione, anno_prenotazione,
                                     ora_prenotazione, minuti_prenotazione, prenotazioni );
     
     if( risultato_controllo_prenotazione == 1 ) { // se la data è occupata
       flag = 0; // imposta il valore del flag a zero
       puts( "Data non confermata" ); // comunica all'utente che la data richiesta non è occupata
       /* chiamata alla funzione per l'ouput delle prenotazioni già occupate per quel medico richiesto dall'utente */
       output_prenotazioni_occupate( prenotazioni, Id_medico );
      } // fine di if 

      else { // altrimenti 
       flag = 1; // imposta il valore del flag a uno
       puts( "Data confermata!" ); // comunica all'utente che la data richiesta non è occupata
       /* chiamata alla funzione per la richiesta di input di una valutazione da parte del paziente */
       richiesta_valutazione_utenza( &valutazione_utenza );       
       //carica_file_utenti( utenti );
       *n_utenti = *n_utenti + 1;    
       /* chiamata alla funzione per la registrazione della nuova valutazione all'interno del file binario "utenti" */
       registra_nuovo_paziente( utenti, n_utenti, CodFiscale, nome_paziente, cognome_paziente, 
                               sesso, giorno_nascita, mese_nascita, anno_nascita, Id_medico,
                               nome_visita, giorno_prenotazione, mese_prenotazione, anno_prenotazione,
                               ora_prenotazione, minuti_prenotazione );
      /* chiamta alla funzione per il caricamento delle informazioni presenti nel file delle valutazioni */
       carica_file_valutazioni( valutazioni );
       *n_valutazioni = *n_valutazioni + 1; // incrementa il numero di valutazioni memorizzate nel file delle valutazioni
       /* chiamata alla funzione per la registrazione della nuova valutazione all'interno del file binario "valutazioni" */
       registra_nuova_valutazione( valutazioni, n_valutazioni, CodFiscale, Id_medico, nome_visita, 
                                valutazione_utenza, giorno_prenotazione, mese_prenotazione, anno_prenotazione,
                                ora_prenotazione, minuti_prenotazione );
      /* chiamta alla funzione per il caricamento delle informazioni presenti nel file delle prenotazioni */
       carica_file_prenotazioni( prenotazioni );
       *n_prenotazioni = *n_prenotazioni + 1; // incrementa il numero di valutazioni memorizzate nel file delle valutazioni
      /* chiamata alla funzione per la registrazione della nuova valutazione all'interno del file binario "prenotazioni" */
       registra_nuova_prenotazione( prenotazioni, n_prenotazioni,CodFiscale, Id_medico, nome_visita,
                                 giorno_prenotazione, mese_prenotazione, anno_prenotazione, ora_prenotazione,
                                 minuti_prenotazione );
      } // fine di else 
    } // fine di while 
         
  } // fine di else if 
    
  
    
  
  
} // termina la funzione 