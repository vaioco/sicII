# primo esercizio

sfruttare lo stack overflow presente nei programmi stack{1,2,3,4,5}.c per ottenere in output la stringa "you win!"

per i primi tre programmi e' disponibile il codice sorgente. 

```
r0x@ubuntu:~/lezioni/sicII/esercizi/stack$ python -c 'VOSTRA SOLUZIONE' | ./stack1
buf: ffffd05c cookie: ffffd0ac
you win!
```

il codice precedente mostra un esempio dell'output che indica la corretta soluzione dell'esercizio.

nell'esempio viene utilizzata la redirezione dell'output sfruttando il comando pipe "|", il comando python serve, invece, per produrre l'input che verra' passato al programma che segue il comando di pipe "|" (nell'esempio: stack1). Potete utilizzare qualsiasi altro metodo per risolvere gli esercizi.

La soluzione da consegnare e' l'input utilizzato per sfruttare lo stack overflow e completare l'esercizio.

happy hacking!!
