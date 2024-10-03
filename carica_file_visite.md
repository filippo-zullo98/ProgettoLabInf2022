# CARICA FILE VISITE

### DESCRIZIONE DELLA FUNZIONE
Questa funzione ha come scopo principale quello di copiare tutte le informazioni presenti nel
file binario delle visite all'interno di una struct, che in questo caso è la struct
chiamata "medici". 

Questa funzione presenta un unico argomento, dove all'interno di esso c'è una copia
della struct "medici" ( passaggio per valore ), la funzione presenta nel suo
corpo due variabili: la variabile di tipo FILE "fPtr" e la variabile intera "n_medici".

La variabile "fPtr" in questo caso è un puntatore ad una struct di tipo file, cioè, attraverso
questa variabile abbiamo la possibilità di poter accedere al contenuto del file di nostro 
interesse, che in questo caso è il file binario delle "visite", dove potremo accedervi 
assegnando a "fPtr" il valore restituito dalla funzione "fopen".
La variabile "n_medici" rappresenta, invece, all'interno della funzione, il valore di ritorno restituito 
alla funzione chiamante "carica_dati_files", dove sostanzialmente avremo che all'interno di 
"n_medici" sarà contenuto il numero di medici memorizzati all'interno del file binario "visite".

###  FUNZIONAMENTO
Prima di poter effettuare la copia, la funzione accede prima di tutto al file "visite", nel quale
sono contenute le informazioni di interesse, in questo caso l'accesso che viene fatto sarà un accesso
fatto in lettura, poichè in questo caso l'intenzione è solo quella di visionare il contenuto del file.
Una volta effettuato l'accesso in lettura, attraverso un ciclo while in cui è presente una chiamata
alla funzione fread, avremo che finchè la funzione fread restituisce il valore 1, verrà incremntato il 
valore di n_medici e il record letto verrà memorizzato all'interno della struct "medici".
Una volta terminato il ciclo, viene effettuata una chiamata alla funzione fclose, che andrà in questo
caso a chiudere il file che era stato aperto in precedenza. 
