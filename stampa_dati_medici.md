# STAMPA DATI MEDICI
### DESCRIZIONE DELLA PROCEDURA 
Questa procedura ha come unico scopo quello di mostrare a video tutti i record presenti all'interno della 
struct "medici".
La procedura presenta due argomenti passati per valore, che contengono rispettivamente la copia della struct
medici e il numero di medici memorizzati nel file.

###  FUNZIONAMENTO
La procedura presenta all'interno del suo corpo un ciclo for, che eseguira un numero di ripetizioni nella stampa 
a video pari al numero dei medici memorizzati nel file.
Per quanto riguarda i record della struct che interessano le valutazioni dei medici, abbiamo che esse verranno
rappresentate mediante delle "stelle", dove qualora la valutazione sia un numero maggiore di zero.
Se il numero fosse minore o uguale a zero, avremo che la rappresentazione sarà numerica e non simbolica( quindi 
non rappresentata da delle stelle ).