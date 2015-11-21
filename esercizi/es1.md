# primo esercizio

provare a sfruttare lo stack overflow presente nei programmi stack{1,2,3,4,5}.c

per i primi tre programmi e' disponibile il codice sorgente. 

Il goal e' stampare la stringa "you win!"

```
r0x@ubuntu:~/lezioni/sicII/esercizi/stack$ python -c 'VOSTRA SOLUZIONE' | ./stack1
buf: ffffd05c cookie: ffffd0ac
you win!
```

il codice precedente mostra un esempio dell'output che indica la corretta soluzione dell'esercizio.

nell'esempio viene utilizzata la redirezione dell'output sfruttando il comando pipe "|", il comando python serve, invece, per produrre l'input che verra' passato al programma che segue il comando di pipe "|" (nell'esempio: stack1)

La soluzione da consegnare e' il comando che avete costruito per "exploitare" lo stack overflow degli esercizi.

happy hacking!!
