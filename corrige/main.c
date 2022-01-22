#include <stdio.h>
#include "math.h"

// on passe le pointer vers le tableau où on garde les nombre premiers et le nombre jusqu'à lequel on fait le recherche
int search_firsts(unsigned int* tab, int n) { 
    if(n == 0) { 
        tab = NULL;
        return 0;
    }
    if(n == 1) {
        tab[0] = 1;
        return 1;
    } else if(n == 2) {
        tab[0] = 1;
        tab[1] = 2;
        return 2;
    }
    tab[0] = 1;
    tab[1] = 2;
    int pointer = 2;
    for(int i=3; i<=n; i++) { // pour chaque nombre entre 3 et n
        int is_first = 1;
        for (int j=1; j< pointer; j++) {
            if (i % tab[j] == 0) { // si un des nombres premiers qu'on a trouvé divise le i, i n'est pas premier
                is_first = 0;
                break;
            }
        }
        if(is_first == 1) { // si après le parcours i est premier
            tab[pointer] = i;
            pointer++;
        }
    }
    return pointer;
}

// On suppose que le centre de cercle est à l'origine, r son rayon, a b et c sont les coeeficients de l'équation de la droite.
void intersection_circle_line(double r, double a, double b, double c) {
    
    double eps = 0.0001; // précision

    double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b); // point le plus proche au centre

    if (c*c > r*r*(a*a+b*b)+eps) 
        printf("pas de points\n");
    else if (fabs (c*c - r*r*(a*a+b*b)) < eps) {
        printf("un point:\n");
        printf("Coordonnees: %lf, %lf", x0, y0);
    }
    else {
        double d = r*r - c*c/(a*a+b*b); // distance à l'intersection
        double mult = sqrt (d / (a*a+b*b));
        double ax,ay,bx,by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;
        printf("deux points:\n");
        printf("premier: %lf, %lf\n", ax, ay);
        printf("deuxieme: %lf, %lf\n", bx, by);
    }
}


int main() {
    unsigned int firsts[100];
    int n = search_firsts(firsts, 100);
    for(int i=0; i<n; i++) {
        printf("%u ", firsts[i]);
    }
    printf("\n");
    intersection_circle_line(50.0, 10.0, -5.0, 8.0);
    return 0;
}