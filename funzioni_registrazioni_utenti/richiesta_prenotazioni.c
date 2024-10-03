#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libr_registrazioni_utenti.h"

void richiesta_prenotazione( int *n_prenotazioni, int *n_utenti, int *n_valutazioni ) {
   
  medico medici[N_RECORD_INIZIALI];
  prenotazione prenotazioni[*n_prenotazioni];
  utente utenti[*n_utenti];
  valutazione valutazioni[*n_valutazioni];
  char Id_medico[20];
  int counter_medici;
  int counter_prenotazioni;
  int result_contr_InsMedico = 0;
  int tipo_visita;
  int result_contr_InsVisita = 0;
  char *lista_visite[N_TIPI_VISITE];
  int n_visite_offerte;
  char nome_visita[30];
  /* in questa variabile verrà inserito un valore binario che determinerà per 
     quale sesso è possibile una determinata visita */
  int flag_sesso; 
  /* in questa variabile verrà inserito un valore binario che determinerà se 
     l'utente intende continuare l'operazione di registrazione o se vuole tornare 
     alla schermata principale */
  int flag_richiesta;
  
   
  system( "clear" );
  /* chiamata alla funzione per il caricamento del file delle visite */
  counter_medici = carica_file_visite( medici ); 
  /* chiamata alla funzione per la stampa dei medici presenti nel file visite */
  stampa_dati_medici( medici, counter_medici ); 
 
  

  /* chiamata alla funzione per il controllo dell'esistenza del medico inserito dall'utente */
  while(getchar() != '\n'); 
  while( result_contr_InsMedico != 1 ) { // finchè non viene trovato un medico memorizzato nel file delle visite
   printf( "Selezionare l'id del medico del quale intende effettuare la prenotazione----> " );
   fgets( Id_medico, 20, stdin ); // ricevi in input dall'utente l'id del medico 
   /* chiamata alla funzione per il controllo dell'esistenza del medico inserito dall'utente nel file visite */
   result_contr_InsMedico = controllo_inserimento_medico( Id_medico, counter_medici, medici ); 
  } // fine di while   

  system( "clear" ); // pulizia console 

  /* chiamata alla funzione per l'output delle visite offerte per un medico specificato dall'utente */
  n_visite_offerte = output_visite_MedSpecifico( Id_medico, counter_medici, medici, lista_visite );
    
  while( result_contr_InsVisita != 1 ) { // finchè non viene trovato un medico memorizzato nel file delle visite
   printf( "Selezionare il numero di una visita presente nell'elenco---> " );
   scanf( "%d", &tipo_visita ); // ricevi in input dall'utente l'id del medico 
   /* chiamata alla funzione per verificare se l'utente abbia scelto correttamente una fra le visite elencate */
   result_contr_InsVisita = controllo_inserimento_visita( n_visite_offerte, tipo_visita, lista_visite );  
  } // fine di while   

  /* chiama la funzione strncpy per copiare il contenuto dell'elemento pari al numero del 
   tipo della visita selezionato e copialo in una variabile di tipo stringa */  
  strncpy( nome_visita, lista_visite[tipo_visita], 30 ); 
  /* chiamata alla funzione per il caricamento del file delle prenotazioni */
  counter_prenotazioni = carica_file_prenotazioni( prenotazioni ); 
  /* chiamata alla funzione per l'output delle visite già prenotate 
  da altri utenti per quel medico e per quel tipo di visita */
  output_date_occupate( nome_visita, prenotazioni, counter_prenotazioni, Id_medico  ); 

  /* chiamata alla funzione per determinare che tipo di sesso può prenotare un determinato tipo di visita */
  flag_sesso = Determina_Accesso_visita( medici, counter_medici, nome_visita ); 

  /* chiama la funzione per chiedere all'utente se intende continuare con l'operazione di registrazione */
  while( flag_richiesta != 1 || flag_richiesta != 2 ) { // fincè il valore del flag è diverso da 1 o da 2
    flag_richiesta = richiesta_avvio_operazione(); // effettua la chiamata alla funzione 
    if( flag_richiesta == 1 ) { // se il valore del flag è uguale ad 1
      /* chiama la funzione per l'aggiunta delle informazioni nei files che interessano la nuova prenotazione */
      aggiungi_paziente( Id_medico, flag_sesso, prenotazioni, utenti, valutazioni, nome_visita, n_utenti, n_valutazioni, n_prenotazioni );       
      break; // esci dal ciclo while 
    } // fine di if 

    else if( flag_richiesta == 2 ) {
      break; // esci dal ciclo while
    } // fine di else if      
      
  } // fine di while 

  
  system( "clear" );
  /* chiamata alla funzione per tornare al menù principale */
  main();
  

  
} // termina la funzione 
