# Des prérequis et des rappels 

## Déclarer une varible et l'initialiser

``` C
    int x; // declaration
    x = 0; // attribution de valeur
    float y = 0; // declaration et initialisation
```

## Les conditions avec if/else

```C
    int x = calculate_something(...);
    if(x == 0) {
        /* Do something here */
    } else if( x == 2) {
        /* Do something here */
    } else {
        /* Else do something here */
    }
```

## Les boucles

```C
    int n = 5;
    for(int i  = 0; i < n; i++) {
        /* Do something here */
    }

    int i = 0;
    
    while(i < 5) {
        /* Do something here */
        i++;
    }
```

## Des fonctions

Fonctions doit avoir le type de retour ou void, le nom, les paramètres et le corps(le code de la fonction). Vous pouvez définir une fonction et l'appeler dans le même fichier comme ça:

```C
    // You can declare a function simply
    double func1(double a, double b, ...) {
        /* Do something here */
        return ...; // double value there
    }

    void func2(...) {
        /* Do something here */
    }
```

Sinon vous devez créer un header et déclarer votre fonction à l'intérieur pour pouvoir l'importer:


```
your_project
|   main.c
|   your_file.h
|   your_file.c
```

```C
    // your_file.h
    #ifndef YOUR_FILE_H
    #define YOUR_FILE_H
    
    int func(int , int );

    #endif
```

```C
    // your_file.c
    #include "your_file.h"

    int func(int a, int b) {
        /* Do something here */
        return ...; // int value here
    }
```

```C
    // main.c
    #include "your_file.h"

    int main() {
        func(1, 2);
        /* Do something here */
        return 0;
    }
```

## Compilation

Normalement pour les 2 exos ça doit suffir, mais vous pouvez aller plus loin et compiler plusieurs fichier sources.

```bash
    gcc -Wall -Werror -o exec main.c
    ./exec
```

## Aller plus loin

[Réference du language C](https://en.cppreference.com/w/)
[Compilation basique](http://perso.univ-lyon1.fr/jean-claude.iehl/Public/educ/gcc.html)

---

# Les exos

## Les nombres premiers

Il s'agit d'écrire et tester une fonction qui vous retourne tout les nombres premiers entre 1 et n, où n est donné. Vous aurez besoin des listes(je vous laisse débrouiller) et probablement d'un algorithme (je vous donne pas le nom, je dis juste que c'est le grec qui l'a inventé).

## L'intersection 

Etant donné la droite(a, b et c de l'équation de la droite ax + by +c = 0) et le cercle( le centre et le rayon), trouver leur point(s) d'intersection s'il existe.
