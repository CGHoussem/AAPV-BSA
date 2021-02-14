# AAPV-BSA
Algorithm Analysis &amp; Program Validation | Binary Search Algorithm

Pour compiler le programme, il suffit de taper les commandes suivantes:
```bash
# Naviguer à la repertoire du programme
$ cd AAPV-BSA/

# Créer une répertoire nommé 'build'
$ mkdir build

# Compiler le code source en utilsant CMAKE
$ cmake ..

# Construire le fichier binaire
$ build
```

Après avoir compilé le code source avec succès, vous pouvez l'exécuter, en tapant cette commande:
```bash
# Il faut saisir le nombre d'itérations voulu
$ ./AAPV-BSA [iterations]
```

Vous pouvez également et c'est plutôt recommandé de rediriger la sortie du programme vers un fichier et non pas la sortie standard (par défaut):
```bash
$ ./AAPV-BSA [iterations] > 'nom_du_fichier_de_sortie'
```

---

Tableau de correspondance entre le nombre d'itérations choisi et la mémoire qui sera utilisé par le programme.   
Types/Itérations|1|2|3|4|5|6|7|8|9|10
---|---|---|---|---|---|---|---|---|---|---
Entier|2 MB|4 MB|8 MB|16 MB|32 MB|64 MB|128 MB|256 MB|1 GB|2 GB
Double Flotttans|4 MB|8 MB|16 MB|32 MB|64 MB|128 MB|256 MB|1 GB|2 GB|4 GB
**Total**|6 MB|12 MB|24 MB|48 MB|96 MB|192 MB|374 MB|1.25 GB |3 GB|6 GB

---

Quelques exemples:
```bash
$ ./AAPV-BSA 2
Integers: 2097152 Bytes (2 MBytes)
Doubles: 4194304 Bytes (4 MBytes)
Total: 16777216 Bytes (6 MBytes)
iterative median (int): 0.00115933
recursive median (int): 0.000920333
iterative median (double): 0.000219333
recursive median (double): 0.000194667
---
Integers: 4194304 Bytes (4 MBytes)
Doubles: 8388608 Bytes (8 MBytes)
Total: 33554432 Bytes (12 MBytes)
iterative median (int): 0.00129633
recursive median (int): 0.001129
iterative median (double): 0.000286667
recursive median (double): 0.00023
---
```
```bash
$ ./AAPV-BSA 4 > 'benchmark_48MB.txt'
```