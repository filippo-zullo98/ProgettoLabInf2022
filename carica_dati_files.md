# CARICA DATI FILES 
### DESCRIZIONE DELLA PROCEDURA
La procedura si occupa del caricamento dei dati sulla quale è basato il funzionamento dell'intero sistema.
I dati che vengono caricati sono dati che interessano le visite, gli utenti, le prenotazioni e le valutazioni.   
Gli utenti, le visite, le prenotazioni e le valutazioni vengono definiti nel seguente modo:

1. UTENTI ( Verranno definiti i seguenti dati anagrafici ) :
- Codice fiscale;
- Nome;
- Cognome;
- Sesso;
- Giorno di nascita;
- Mese di nascita;
- Anno di nascita; 

2. VISITE : 
-  Codice identificativo del medico;
-  Nome del medico;
-  Cognome del medico;
-  Tipo di visita;
-  Descrizione;
-  Prezzo;
-  Valutazione delle utenze; 

3. PRENOTAZIONI :
- Codice fiscale del paziente;
- Codice identificativo del medico;
- Tipo di visita;
- Giorno della prenotazione;
- Mese della prenotazione;
- Anno della prenotazione;
- Ora della prenotazione;
- Minuti della prenotazione.

4. VALUTAZIONI :
- Codice fiscale del paziente;
- Codice identificativo del medico;
- Tipo di visita;
- Valutazione immessa dall'utente;
- Giorno della prenotazione;
- Mese della prenotazione;
- Anno della prenotazione;
- Ora della prenotazione;
- Minuti della prenotazione.


Questa procedura incorpa al suo interno delle funzioni( o delle procedure ), che vengono amministrate da essa non 
solo per svolgere operazioni come il caricamento, ma anche per svolgere compiti differenti, ma molto fondamentali
ai fini del funzionamento del sistema. 

La procedura presenta delle funzioni che si occupano anche della verifica dell'esistenza dei dati, perchè qualora 
essi non ci fossero, nessun utente potrebbe effettuare una prenotazione, in quanto non ci sarebbero medici
memorizzati all'interno del programma. 
Quindi, a tale scopo, sono state create delle funzioni dedicate all'acquisizione dei dati, queste funzioni( o procedure )
non fanno altro che ricevere da dei file di testo tutte le informazioni che interessano utenti e medici.
Oltre all'acquisizione di dati che interessanno medici e utenti, c'è anche l'acquisizone di dati che riguarda
le valutazioni e le prenotazioni effettuate da ogni paziente. 

### FUNZIONAMENTO 

Possiamo suddividere il funzionamento di questa procedura in 5 punti fondamentali:

1. CARICAMENTO DEL FILE DELLE VISITE;
2. CARICAMENTO DEL FILE DEGLI UTENTI;
3. CARICAMENTO DEL FILE DELLE PRENOTAZIONI;
4. CARICAMENTO DEL FILE DELLE VALUTAZIONI.
5. AGGIORNAMENTO DEL FILE DEI MEDICI A SEGUITO DELL'ACQUISIZIONE DEL FILE DELLE PRENOTAZIONI.

In tutti i punti elencati vengono eseguite delle operazioni quasi equivalenti, poichè, in tutte e 4 avviene 
una chiamata ad una funzione dedicata al conteggio degli elementi presenti nel file binario di interesse, dove
in base alla quantità restituita dalla funzione chiamata, verrà determinato se l'operazione successiva sarà un 
operazione di scrittura o di semplice lettura nel file binario. 
Il quinto punto, invece, viene preso in considerazione solo se siamo nella situazione nella quale, sia il file delle
visite e sia il file delle valutazioni vengono scritti per la prima volta. 
Il motivo per cui il quinto punto viene preso in considerazione solo nella situazione descritta in precedenza, è che 
quando viene acquisito il file di testo dei medici per la prima volta, le valutazioni che riguardano ogni medico presente
nel file non esistono, in quanto fino a quel momento non è stata ancora registrata alcuna valutazione da nessun utente. 
Solo a seguito dell'acquisizione del file di testo delle valutazioni possiamo disporre di valutazioni associate a dei medici 
specifici, motivo per il quale a seguito di ciò possiamo aggiornare il file binario delle visite con nuove valutazioni.
Se, invece, il file binario delle visite dovesse essere solo caricato e non scritto per la prima volta, allora vuol dire
che il file delle visite è già aggiornato con le nuove valutazioni, perciò non c'è bisogno di effettuare una chiamata
alla funzione che lo aggiorni.


