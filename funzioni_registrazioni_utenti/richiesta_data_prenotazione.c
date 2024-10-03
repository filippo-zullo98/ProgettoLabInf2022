#include <stdio.h>
#include <string.h>
#include "libr_registrazioni_utenti.h"

void richiesta_data_prenotazione( int *giorno_prenotazione, int *mese_prenotazione, int *anno_prenotazione ) {
  int flag_anno = 0;
  int flag_mese = 0;
  int flag_giorno = 0;
  int flag_bisestile = 0;
  int flag_ricerca = 0;

  enum anno { Gennaio = 1, Febbraio, Marzo, Aprile, Maggio,
             Giugno, Luglio, Agosto, Settembre, Ottobre, Novembre,
             Dicembre } mese;
  
  puts( " " );
  while( flag_anno != 1 ) { // finchè l'utente inserisce l'anno in maniera errata
    puts( "Inserisci l'anno della prenotazione:" );
    scanf( "%d", anno_prenotazione ); 
    if( *anno_prenotazione >= 2022 && *anno_prenotazione <= 2025 ) { // se l'anno della prenotazione è compreso tra 2022 e 2025 
      flag_anno = 1; // poni il valore del flag uguale ad 1 ed esci dal ciclo 
      if( *anno_prenotazione % 4 == 0 ) { // se l'anno è bisestile
       flag_bisestile = 1; // imposta il flag bisestile a 1
      } // fine di if 
    } // fine di if 
    else { // altrimenti 
      flag_anno = 0; // poni il valore del flag uguale a zero 
      puts( "Errore!" );
    } // fine di else 
  } // fine di while 
  
    
  
  while( flag_mese != 1 ) { // finchè l'utente inserisce il mese in maniera errata  
   puts( "Inserisci il mese della prenotazione:" );
   scanf( "%d", &mese );
   if( mese >= 1 && mese <= 12 ) { // se il mese inserito è compreso tra 1 e 12
     *mese_prenotazione = mese; // poni il mese di nascita uguale al mese inserito 
     flag_mese = 1; // poni il valore del flag a 1 ed esci dal ciclo 
    } // fine di if 
   else { // altrimenti 
     flag_mese = 0; // poni il valore del flag uguale a zero 
     puts( "Errore!" );
    } // fine di else 
  } // fine di while 

  
    
  switch( mese ) {
    
    case Gennaio : // se il mese è GENNAIO i giorni sono 31 
    {      
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       if( *giorno_prenotazione > 1 && *giorno_prenotazione <= 31 && *giorno_prenotazione != 6  ) { // se il giorno è compreso tra 2 e 31 e diverso da 6
         flag_giorno = 1; // poni il valore del flag uguale ad 1 ed esci dal ciclo
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    }  // termina 
    
    case Febbraio : // se il mese è FEBBRAIO i giorni sono 28 o 29
    {
      puts( "Inserisci il giorno della prenotazione:" );
      scanf( "%d", giorno_prenotazione );
      if( flag_bisestile == 1 ) { // se l'anno è di 29 giorni
       if( *giorno_prenotazione < 1 || *giorno_prenotazione > 29 ) { // se il giorno inserito è compreso tra 1 e 29
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
         while( flag_giorno != 1 ) { // finchè il giorno inserito è errato  
           puts( "Inserisci il giorno della prenotazione:" );
           scanf( "%d", giorno_prenotazione );
           if( *giorno_prenotazione < 1 || *giorno_prenotazione > 29 ) { // se il giorno inserito è compreso tra 1 e 29
             puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
             flag_giorno = 0; // poni il valore del flag uguale a zero 
            } // fine di if 
           else { // altrimenti 
             flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
            } // fine di else 
          } // fine di while 
        } // fine di if interno 
      }  // fine di if 

      else { // altrimenti 
        if( *giorno_prenotazione < 1 || *giorno_prenotazione > 28 ) { // se il giorno inserito è compreso tra 1 e 28
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
         while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
           puts( "Inserisci il giorno della prenotazione:" );
           scanf( "%d", giorno_prenotazione );
           if( *giorno_prenotazione < 1 || *giorno_prenotazione > 28 ) { // se il giorno inserito è compreso tra 1 e 28
             puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
             flag_giorno = 0; // poni il valore del flag uguale a uno 
            } // fine di if
           else { // altrimenti 
             flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
            } // fine di else 
          } // fine di while  
        } // fine di if 
      } // fine di else    
      break;
    } // termina  

    case Marzo : // se il mese è MARZO i giorni sono 31
    {
     while( flag_giorno != 1 ) {
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       if( *giorno_prenotazione >= 1 && *giorno_prenotazione <= 31  ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Aprile : // se il mese è APRILE i giorni sono 30
    {
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       /* se il giorno inserito è compreso tra 1 e 30 ed è diverso da 25 */
       if( *giorno_prenotazione >= 1 && *giorno_prenotazione <= 30 && *giorno_prenotazione != 25  ) { 
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if   
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero ed esci dal ciclo while 
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina

    case Maggio : // se il mese è MAGGIO i giorni sono 31
    {
      while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       if( *giorno_prenotazione >= 2 && *giorno_prenotazione <= 31 ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if   
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 
    

    case Giugno : // se il mese è GIUGNO i giorni sono 30
    {
     while( flag_giorno != 1 ) {
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       if( *giorno_prenotazione >= 1 && *giorno_prenotazione <= 30 && *giorno_prenotazione != 2  ) {
         flag_giorno = 1;
        }        
        else {
         flag_giorno = 0;
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        }
      } // fine di while    
     break;
    } // termina il caso 6

    case Luglio : // se il mese è LUGLIO i giorni sono 31
    {
      while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       if( *giorno_prenotazione >= 1 && *giorno_prenotazione <= 31  ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if        
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Agosto : // se il mese è AGOSTO i giorni sono 31
    {
      while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
      /* se il giorno inserito è compreso tra 1 e 9 o tra 16 e 31 */
       if( *giorno_prenotazione >= 1 && *giorno_prenotazione <= 9 || *giorno_prenotazione >= 16 && *giorno_prenotazione <= 31  ) {
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if       
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Settembre : // se il mese è SETTEMBRE i giorni sono 30
    {
    while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       if( *giorno_prenotazione >= 1 && *giorno_prenotazione <= 30  ) { // se il giorno inserito è compreso tra 1 e 30
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Ottobre : // se il mese è OTTOBRE i giorni sono 31
    {
     while( flag_giorno != 1 ) {
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       if( *giorno_prenotazione >= 1 && *giorno_prenotazione <= 31 ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while
        } // fine di if        
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Novembre : // se il mese è NOVEMBRE i giorni sono 30
    {
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
       /* se il giorno inserito è compreso tra 1 e 30 ed è diverso da 1 */
       if( *giorno_prenotazione >= 1 && *giorno_prenotazione <= 30 && *giorno_prenotazione != 1  ) {
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Dicembre : // se il mese è DICEMBRE i giorni sono 31
    {
      while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno della prenotazione:" );
       scanf( "%d", giorno_prenotazione );
        /* se il giorno inserito è compreso tra 1 e 24 o tra 28 e 31 ed è diverso da 8 */
       if( *giorno_prenotazione != 8 && *giorno_prenotazione >= 1 && *giorno_prenotazione <= 24 || *giorno_prenotazione >= 28 && *giorno_prenotazione <= 31  ) {
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while
        } // fine di if       
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero
         puts( "Errore! Non è possibile effettuare una visita per questo giorno." );
        } // fine di else 
      } // fine di while    
     break;
    } // termina

  } // termina switch


} // termina la funzione 