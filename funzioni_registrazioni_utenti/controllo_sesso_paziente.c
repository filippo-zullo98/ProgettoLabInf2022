#include "libr_registrazioni_utenti.h"
#include <stdio.h>

void controllo_sesso_paziente( char *sesso, int flag_sesso ) {
 
  int flag = 0;
 
  if( flag_sesso == 1 ) { // se la visita è ginecologica
   if( *sesso != 'f' && *sesso != 'F' ) { // se il sesso è diverso da quello femminile 
     puts( "Errore nella digitazione!" );
     puts( "Solo le persone di sesso femminile possono prenotarsi per questo tipo di visita." );
     while( flag != 1  ) { // finchè il paziente inserisce un sesso diverso da quello femminile
       puts( "Inserisca il sesso: " );
       while( getchar() != '\n' );
       scanf( "%c", sesso );
       if( *sesso != 'f' && *sesso != 'F' ) { // se il sesso è diverso da quello femminile 
         flag = 0; // imposta il valore del flag a zero 
         puts( "Errore nella digitazione!" );
         puts( "Solo le persone di sesso femminile possono prenotarsi per questo tipo di visita." );
        } // fine di if 
        else { // altrimenti  
          flag = 1; // imposta il valore del flag a 1 ed esci dal ciclo while 
        } // fine di else
      } // fine di while
    } 
  } 

  else if( flag_sesso == 2 ) { // se la visita è urologica
   if( *sesso != 'm' && *sesso != 'M' ) { // se il sesso è diverso da quello maschile 
     puts( "Errore nella digitazione!" );
     puts( "Solo le persone di sesso maschile possono prenotarsi per questo tipo di visita." );
     while( flag != 1  ) { // finchè il paziente inserisce un sesso diverso da quello maschile 
       puts( "Inserisca il sesso: " ); 
       while( getchar() != '\n' );
       scanf( "%c", sesso );
       if( *sesso != 'm' && *sesso != 'M' ) { // se il sesso è diverso da quello maschile  
         flag = 0; // imposta il valore del flag a zero 
         puts( "Errore nella digitazione!" );
         puts( "Solo le persone di sesso maschile possono prenotarsi per questo tipo di visita." );
        } // fine di if 
        else { // altrimenti 
          flag = 1; // imposta il valore del flag a 1 ed esci dal ciclo while 
        } // fine di else 
      } // fine di while
    }
  }
  
  
 
  else if( *sesso != 'm' && *sesso != 'f' && *sesso != 'M' && *sesso != 'F' ) { // se l'utente sbaglia l'inserimento
    puts( "Errore nella digitazione!" );
    while ( flag != 1 ) { // finchè l'inserimento è errato 
      while( getchar() != '\n' );
      puts( "Inseirsca il sesso: " );
      scanf( "%c", sesso );
      if( *sesso != 'm' && *sesso != 'f' && *sesso != 'M' && *sesso != 'F' ) { // se l'utente sbaglia l'inserimento 
        flag = 0; // imposta il valore del flag a 0
        puts( "Errore nella digitazione!" );
      } // fine di if 
      else { // altrimenti esci dal ciclo while 
       flag = 1; // imposta ad 1 il valore del flag ed esci dal ciclo 
      } // fine di else

    }  // fine di while
  
  } // fine di else if 
 

} // termina la funzione