# AGGIORNA VALUTAZIONI MEDICI 
### DESCRIZIONE DELLA PROCEDURA
La procedura si occupa di aggiornare il file binario delle visite, a seguito della scrittura
del file binario delle valutazioni. 
La procedura presenta 4 argomenti:
- La copia della struct dei medici;
- La copia della struct delle valutazioni;
- La copia del numero dei medici memorizzati nel file binario delle visite;
- La copia del numero di valutazioni memorizzate nel file binario delle valutazioni.


# FUNZIONAMENTO
La prima operazione che svolge la procedura è quella di confronto, dove l'obiettivo principale è quello
di verificare se per ogni medico presente nel file delle visite, esiste una valutazione ad esso associata
all'interno del file delle valutazioni. Per poter rilevare il medico senza eventuali ambiguità, il confronto
che verrà fatto, sarà fatto confrontando l'Id del medico memorizzato nel file delle visite, con l'Id del 
medico memorizzato nel file delle valutazioni. Per poter tener traccia delle valutazioni associate per ogni
medico e per poter svolgere successivamente altre operazioni, come il calcolo della media, sono stati creati
degli array, dove in uno sarà contenuta la somma dei voti di ogni medico e in un altro sarà contenuto il numero 
di valutazioni registrate per ogni medico.
Quindi, ogni volta che verrà rilevato un medico all'interno del file delle valutazioni che abbia lo stesso Id 
del medico presente nel file delle visite, verrà sommata la valutazione attualmente memorizzata con quella appena
rilevata, e successivamente verrà incrementato il numero di valutazioni registrate per quel medico specifico.
A seguito del termine dell'operazione di confronto, verrà effettuato un ciclo dove all'interno di esso verrà 
effettuato il calcolo della media delle valutazioni di ogni medico, dove, per ogni medico verrà effettuata 
l'operazione di divisione tra la somma delle valutazioni registrate e il numero di valutazioni registrate, per 
quel medico specifico.
Dopo aver eseguito il calcolo della media, il file delle visite viene aperto in scrittura, dove quello che
avviene è niente meno che una sovrascrittura del file, dove quindi le valutazioni per ogni medico vengono aggiornate. 


