# CONTROLLO SCELTA 
### DESCRIZIONE DELLA FUNZIONE 

La funzione in questione ha due scopi: 

1 - Comunicare un errore nel caso in cui l'utente abbia inserito un numero, per il quale non vi è associata alcuna operazione;

2 - Determinare se l'utente abbia scelto l'operazione di creazione di un file binario o la terminazione del programma.

La funzione presenta un unico argomento( "scelta" ), dove all'interno di esso vi è contenuta una copia del valore del numero
dell'operazione inserita dall'utente, al momento della scelta dell'operazione da effettuare all'interno della funzione chiamante. 
Nel del corpo della funzione viene inizializzata a zero una variabile "value", questa variabile rappresenta il valore di ritorno 
che verrà restituito alla funzione chiamante.

### FUNZIONAMENTO

La funzione effettua i controlli sulla scelta dell'operazione nel seguente modo:

1 - Se il valore della scelta è pari a 1, all'utente viene comunicato che il file binario sta per essere creato, e "value", che è
    il valore restituto alla funzione chiamante, assumerà il valore di 1, terminando così la richiesta di input della scelta dell'operazione
    da effettuare;

2 - Se il valore della scelta è pari a 2, all'utente viene comunicato che il programma sta per essere terminato, e "value", che è
    il valore restituto alla funzione chiamante, assumerà il valore di 1, terminando così la richiesta di input della scelta dell'operazione
    da effettuare;

3 - Se il valore della scelta è diverso da 1 o da 2, all'utente verrà comunicato l'errore nella scelta dell'operazione da effettuare, e "value", che 
    è il valore restituto alla funzione chiamante, rimarrà con il suo valore impostato a zero, e il che si traduce nel fatto che all'utente
    verrà richiesto nuovamente di scegliere fra una delle due operazioni offerte.