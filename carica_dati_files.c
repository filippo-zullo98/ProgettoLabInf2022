#include <stdio.h>
#include <string.h>
#include "libr_caricamento_files.h"

void carica_dati_files( int n_medici, int *n_utenti, int *n_prenotazioni, int *n_valutazioni ) {

  medico medici[n_medici]; 
  utente utenti[*n_utenti];
  prenotazione prenotazioni[*n_prenotazioni];
  valutazione valutazioni[*n_valutazioni];
  int scelta_operazione;
  int risultato_controllo_visite = 0;
  int risultato_controllo_utenti = 0;
  int risultato_controllo_prenotazioni = 0;
  int risultato_controllo_valutazioni = 0;
  int n_medici_memorizzati; // variabile utile per contare il numero di record presenti nel file visite
  int n_utenti_memorizzati; // variabile utile per contare il numero di record presenti nel file utenti
  int n_prenotazioni_memorizzate; // variabile utile per contare il numero di record presenti nel file prenotazioni
  int n_valutazioni_memorizzate; // variabile utile per contare il numero di record presenti nel file valutazioni


 /* CARICAMENTO FILE VISITE */
 /* effettua un controllo per verificare se il file esiste oppure no */
  n_medici_memorizzati = carica_file_visite( medici ); 
  if( n_medici_memorizzati == 0 ) { // se il numero di medici trovati nel file binario visite è uguale a zero 
   while( risultato_controllo_visite != 1 ) { // finchè l'utente non sceglie correttamente una delle due operazioni disponibili
     puts( "Il file VISITE non esiste" ); // comunica all'utente che il file non esiste
     puts( "Intende procedere con la creazione del file visite ?" ); // chiedi all'utente se intende creare il file
     puts( "-> Inserisca 1 per continuare." );
     puts( "-> Inserisca 2 per terminare." );
     scanf( "%d", &scelta_operazione ); // ricevi dall'utente in input una scelta
     /* chiamata alla funzione per il controllo della scelta immessa dall'utente */
     risultato_controllo_visite = controllo_scelta( scelta_operazione ); 
    } // fine di while
   
   if( scelta_operazione == 1 ) { // se l'utente ha scelto di registrare i medici 
    /* chiamata alla funzione che acquisisce i dati da file di testo per poi memorizzarli in un file binario */
     crea_file_visite( medici, n_medici ); 
     //stampa_dati_medici( medici, n_medici );
     puts( " " );
    } // fine di if interno 

  } // fine di if

  else { // altrimenti 
    puts( "Caricamento del file VISITE completato." ); 
    puts( "ci sono dei medici nel file." );
    /* chiamata alla funzione per il caricamento della informazioni presenti nel file binario delle visite */
    carica_file_visite( medici ); 
    /* chiamata alla funzione per la stampa a video dei record memorizzati nella struct medici */
    //stampa_dati_medici( medici, n_medici ); 
    puts( "file correttamente caricato!" );
    puts( " " );
  } // fine di else
  

  /* CARICAMENTO FILE UTENTI */
  /* effettua un controllo per verificare se il file esiste oppure no */
  n_utenti_memorizzati = carica_file_utenti( utenti ); 
  if( n_utenti_memorizzati == 0 ) {  // se il numero di utenti trovati nel file binario visite è uguale a zero
   while( risultato_controllo_utenti != 1 ) { // finchè l'utente non sceglie correttamente una delle due operazioni disponibili
     puts( "Il file UTENTI non esiste" ); // comunica all'utente che il file non esiste
     puts( "Intende procedere con la creazione del file utenti ?" ); // chiedi all'utente se intende creare il file
     puts( "-> Inserisca 1 per continuare." );
     puts( "-> Inserisca 2 per terminare." );
     scanf( "%d", &scelta_operazione ); // ricevi dall'utente in input una scelta 
     /* chiamata alla funzione per il controllo della scelta immessa dall'utente */
     risultato_controllo_utenti = controllo_scelta( scelta_operazione ); 
    } // fine di while 
   
   if( scelta_operazione == 1 ) { // se l'utente ha scelto di registrare i pazienti 
     /* chiamata alla funzione che acquisisce i dati da file di testo per poi memorizzarli in un file binario */
     crea_file_utenti( utenti, *n_utenti ); 
     //carica_file_utenti( utenti );  
     //stampa_dati_utenti( utenti, *n_utenti );
     puts( " " );
    } // fine di if interno 
   
  } // fine di if 

  else { // altrimenti 
    puts( "Caricamento del file UTENTI completato." );
    puts( "ci sono dei pazienti nel file." );
    /* chiamata alla funzione per il caricamento della informazioni presenti nel file binario degli utenti */
    *n_utenti = carica_file_utenti( utenti ); 
    /* chiamata alla funzione per la stampa a video dei record memorizzati nella struct utenti */
    //stampa_dati_utenti( utenti, *n_utenti );    
    puts( "file correttamente caricato!" ); 
    puts( " " );
  } // fine di else


 /* CARICAMENTO FILE PRENOTAZIONI */
 /* effettua un controllo per verificare se il file esiste oppure no */
 n_prenotazioni_memorizzate = carica_file_prenotazioni( prenotazioni );
 if( n_prenotazioni_memorizzate == 0 ) { // se il numero di utenti trovati nel file binario delle prenotazioni è uguale a zero
   while( risultato_controllo_prenotazioni != 1 ) { // finchè l'utente non sceglie correttamente una delle due operazioni disponibili
     puts( "Il file PRENOTAZIONI non esiste" ); // comunica all'utente che il file non esiste
     puts( "Intende procedere con la creazione del file prenotazioni ?" ); // chiedi all'utente se intende creare il file
     puts( "-> Inserisca 1 per continuare." );
     puts( "-> Inserisca 2 per terminare." );
     scanf( "%d", &scelta_operazione ); // ricevi dall'utente in input una scelta 
     /* chiamata alla funzione per il controllo della scelta immessa dall'utente */
     risultato_controllo_prenotazioni = controllo_scelta( scelta_operazione );
    } // fine di while 
   
   if( scelta_operazione == 1 ) { // se l'utente ha scelto di registrare le prenotazioni
     /* chiamata alla funzione che acquisisce i dati da file di testo per poi memorizzarli in un file binario */
     crea_file_prenotazioni( prenotazioni, *n_prenotazioni ); 
     //stampa_dati_prenotazioni( prenotazioni, *n_prenotazioni );
     puts( " " );
    } // fine di if interno 
  
  } // fine di if 

 else { // altrimenti 
    puts( "Caricamento del file PRENOTAZIONI completato." );
    puts( "ci sono delle prenotazioni nel file." );
    /* chiamata alla funzione per il caricamento della informazioni presenti nel file binario delle prenotazioni */
    *n_prenotazioni = carica_file_prenotazioni( prenotazioni );
    //printf( "%d", *n_prenotazioni );
    /* chiamata alla funzione per la stampa a video dei record memorizzati nella struct prenotazioni */
    //stampa_dati_prenotazioni( prenotazioni, *n_prenotazioni );   
    puts( "file correttamente caricato!" ); 
    puts( " " );
  } // fine di else if



 /* CARICAMENTO FILE VALUTAZIONI */
 /* effettua un controllo per verificare se il file esiste oppure no */
 n_valutazioni_memorizzate = carica_file_valutazioni( valutazioni );
 if( n_valutazioni_memorizzate == 0 ) { // se il numero di utenti trovati nel file binario delle prenotazioni è uguale a zero
    while( risultato_controllo_valutazioni != 1 ) { // finchè l'utente non sceglie correttamente una delle due operazioni disponibili
     puts( "Il file VALUTAZIONI non esiste" ); // comunica all'utente che il file non esiste
     puts( "Intende procedere con la creazione del file valutazioni ?" ); // chiedi all'utente se intende creare il file
     puts( "-> Inserisca 1 per continuare." );
     puts( "-> Inserisca 2 per terminare." );
     scanf( "%d", &scelta_operazione ); // ricevi dall'utente in input una scelta
     /* chiamata alla funzione per il controllo della scelta immessa dall'utente */
     risultato_controllo_valutazioni = controllo_scelta( scelta_operazione );
    } // fine di while 

   if( scelta_operazione == 1 ) { // se l'utente ha scelto di registrare le valutazioni
     /* chiamata alla funzione che acquisisce i dati da file di testo per poi memorizzarli in un file binario */
     crea_file_valutazioni( valutazioni, *n_valutazioni ); // funzione che crea e memorizza i dati presenti nella struct in un file binario
     //stampa_dati_valutazioni( valutazioni, *n_valutazioni );
     /* chiamata alla funzione per l'aggiornamento delle valutazioni presenti nel file visite */
     aggiorna_valutazioni_medici( medici, valutazioni, *n_valutazioni );
     /* chiamata alla funzione per la stampa a video dei record memorizzati nella struct valutazioni */
     //stampa_dati_valutazioni( valutazioni, *n_valutazioni );
     puts( " " );
    } // fine di if interno  
  
  } // fine di if

 else { // altrimenti
    puts( "Caricamento del file VALUTAZIONI completato." );
    puts( "ci sono delle valutazioni nel file." );
    /* chiamata alla funzione per il caricamento della informazioni presenti nel file binario delle valutazioni */
    *n_valutazioni = carica_file_valutazioni( valutazioni );
   /* chiamata alla funzione per il caricamento della informazioni presenti nel file binario delle visite */
    carica_file_visite( medici );
    /* chiamata alla funzione per l'aggiornamento delle valutazioni presenti nel file visite */
    aggiorna_valutazioni_medici( medici, valutazioni, *n_valutazioni ); 
    //printf( "%d", *n_valutazioni );
    /* chiamata alla funzione per la stampa a video dei record memorizzati nella struct valutazioni */
    //stampa_dati_valutazioni( valutazioni, *n_valutazioni );
    puts( "file correttamente caricato!" ); 
    puts( " " );  
    
   
   
  } // fine di else if
  

 


}
