# CREA FILE VALUTAZIONI 
### DESCRIZIONE DELLA PROCEDURA 

Questa procedura ha come scopo principale quello di acquisire da un file di testo tutte le informazioni che interessano
le valutazioni effettuate da 20 utenti, e di memorizzarle all'interno di un file binario. 
Questa procedura presenta due argomenti, dove in uno c'è una copia
della struct "valutazioni" ( passaggio per valore ), e in un altro c'è la copia del numero 
degli utenti da memorizzare nel file.
La funzione presenta nel suo corpo la variabile di tipo FILE "fPtr", la variabile "fPtr" in questo 
caso è un puntatore ad una struct di tipo file, cioè, attraverso questa variabile abbiamo la possibilità 
di poter accedere al contenuto del file di nostro interesse, che in questo caso sono sia il file binario  
"valutazioni" e sia il file di testo "valutazioni" , dove potremo accedervi assegnando a "fPtr" il valore restituito 
dalla funzione "fopen".

###  FUNZIONAMENTO
Prima di poter effettuare la scrittura, la funzione accede prima di tutto al file di testo "valutazioni", nel quale
sono contenute le informazioni di interesse, in questo caso l'accesso che viene fatto sarà un accesso
fatto in lettura, poichè in questo caso l'intenzione è solo quella di visionare il contenuto del file.
Una volta effettuato l'accesso in lettura al file di testo "valutazioni", tutte le informazioni presenti verranno memorizzate 
all'interno della struct "valutazioni" attraverso un ciclo for, che prevede un numero di ripetizioni pari al valore di 
"n_valutazioni".
Una volta terminato il ciclo, il file di testo viene chiuso attraverso una chiamata alla funzione fclose, e invece
il file binario "valutazioni" viene aperto in modalità di scrittura, mediante la funzione fopen.
Dopo che viene effettuata l'apertura del file binario, tutti i record della struct valutazioni, verranno ricopiati e 
memorizzati in maniera permanente all'interno del file binario "valutazioni", mediante una chiamata alla funzione fwrite.
Una volta terminata l'operazione di scrittura, il file binario viene chiuso, e la procedura viene terminata.