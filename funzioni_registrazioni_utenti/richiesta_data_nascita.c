#include "libr_registrazioni_utenti.h"
#include <stdio.h>

void richiesta_data_nascita( int *anno_nascita, int *mese_nascita, int *giorno_nascita ) {
  int flag_anno = 0;
  int flag_mese = 0;
  int flag_giorno = 0;
  int flag_bisestile = 0;
  int value = 1; 

  enum anno { Gennaio = 1, Febbraio, Marzo, Aprile, Maggio,
             Giugno, Luglio, Agosto, Settembre, Ottobre, Novembre,
             Dicembre } mese;
  
  
  while( flag_anno != 1 ) { // finchè l'utente inserisce l'anno in maniera errata
    puts( "Inserisci l'anno di nascita:" );
    scanf( "%d", anno_nascita ); 
    if( *anno_nascita >= 1928 && *anno_nascita <= 2021 ) { // se l'anno di nascita inserito è compreso tra il 1928 e il 2021
      flag_anno = 1; // poni il valore del flag uguale ad 1 ed esci dal ciclo 
      if( *anno_nascita % 4 == 0 ) { // se l'anno è bisestile
       flag_bisestile = 1; // imposta il flag bisestile a 1
      } // fine di if 
    } // fine di if 
    else { // altrimenti 
      flag_anno = 0; // poni il valore del flag uguale a zero 
      puts( "Errore!" );
    } // fine di else 
  } // fine di while 
  
  
 while( flag_mese != 1 ) { // finchè l'utente inserisce il mese in maniera errata  
   puts( "Inserisci il mese di nascita:" );
   scanf( "%d", &mese );
   if( mese >= 1 && mese <= 12 ) { // se il mese inserito è compreso tra 1 e 12
     *mese_nascita = mese; // poni il mese di nascita uguale al mese inserito 
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
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 31 ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale ad 1 ed esci dal ciclo
        } // fine di if       
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break; 
    }  // termina 
    
    case Febbraio : // se il mese è FEBBRAIO i giorni sono 28 o 29
    {
      puts( "inserisci giorno di nascita: " );
      scanf( "%d", giorno_nascita );
      if( flag_bisestile == 1 ) { // se l'anno è di 29 giorni
       if( *giorno_nascita < 1 || *giorno_nascita > 29 ) { // se il giorno inserito è compreso tra 1 e 29
         puts( "Il giorno inserito è errato!" );
         while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
           puts( "inserisci giorno di nascita: " );
           scanf( "%d", giorno_nascita );
           if( *giorno_nascita < 1 || *giorno_nascita > 29 ) { // se il giorno inserito è compreso tra 1 e 29
             puts( "Il giorno inserito è errato!" );
             flag_giorno = 0; // poni il valore del flag uguale a zero 
            } // fine di if 
           else { // altrimenti 
             flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
            } // fine di else 
          } // fine di while 
        }  // fine di if interno 
      }  // fine di if 

      else { // altrimenti 
        if( *giorno_nascita < 1 || *giorno_nascita > 28 ) { // se il giorno inserito è compreso tra 1 e 28
         puts( "Il giorno inserito è errato!" );
         while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
           puts( "inserisci giorno di nascita: " );
           scanf( "%d", giorno_nascita );
           if( *giorno_nascita < 1 || *giorno_nascita > 28 ) { // se il giorno inserito è compreso tra 1 e 28
             puts( "Il giorno inserito è errato!" );
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
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 31  ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Aprile : // se il mese è APRILE i giorni sono 30
    {
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 30 ) { // se il giorno inserito è compreso tra 1 e 30
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina

    case Maggio : // se il mese è MAGGIO i giorni sono 31
    {
      while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 31 ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if       
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 
    

    case Giugno : // se il mese è GIUGNO i giorni sono 30
    {
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 30  ) { // se il giorno inserito è compreso tra 1 e 30
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina

    case Luglio : // se il mese è LUGLIO i giorni sono 31
    {
      while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 31  ) { // se il giorno inserito è compreso tra 1 e 31 
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina

    case Agosto : // se il mese è AGOSTO i giorni sono 31
    {
      while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 31  ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina   

    case Settembre : // se il mese è SETTEMBRE i giorni sono 30
    {
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 30 ) { // se il giorno inserito è compreso tra 1 e 30
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Ottobre : // se il mese è OTTOBRE i giorni sono 31
    {
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 31 ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina  

    case Novembre : // se il mese è NOVEMBRE i giorni sono 30
    {
     while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 30 ) { // se il giorno inserito è compreso tra 1 e 30
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

    case Dicembre : // se il mese è DICEMBRE i giorni sono 31
    {
      while( flag_giorno != 1 ) { // finchè il giorno inserito è errato 
       puts( "Inserisci il giorno di nascita:" );
       scanf( "%d", giorno_nascita );
       if( *giorno_nascita >= 1 && *giorno_nascita <= 31 ) { // se il giorno inserito è compreso tra 1 e 31
         flag_giorno = 1; // poni il valore del flag uguale a uno ed esci dal ciclo while 
        } // fine di if 
        else { // altrimenti 
         flag_giorno = 0; // poni il valore del flag uguale a zero 
         puts( "Il giorno inserito è errato!" );
        } // fine di else 
      } // fine di while    
     break;
    } // termina 

  } // termina switch
  
} // termina la funzione 