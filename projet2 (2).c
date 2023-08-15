#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LC {
    char nom[30];
    char prenoms[50];
    float noteMaths;
    float notePysc;
    float moyenne;
    struct LC* suivant;
} LC;

LC* init_liste() {
    return NULL;
}

void ajouter_element_fin(LC** l, char NOM[30], char PRENOM[50], float n, float m) {
    LC* end = (LC*)malloc(sizeof(LC));

    strcpy(end->nom, NOM);
    strcpy(end->prenoms, PRENOM);
    end->noteMaths = n;
    end->notePysc = m;
    end->moyenne = ((n * 5) + (m * 4)) / 9;
    end->suivant = NULL;

    if (*l == NULL) {
        *l = end;
    } else {
        LC* compteur = *l;
        while (compteur->suivant != NULL) {
            compteur = compteur->suivant;
        }
        compteur->suivant = end;
    }
}

void afficherListeChainee(LC* liste) {
    LC* courant = liste;
    while (courant != NULL) {
        printf("Nom : %s\n", courant->nom);
        printf("Prénoms : %s\n", courant->prenoms);
        printf("Note en Mathématiques : %.2f\n", courant->noteMaths);
        printf("Note en Physique : %.2f\n", courant->notePysc);
        printf("Moyenne : %.2f\n\n", courant->moyenne);
        courant = courant->suivant;
    }
}

float moy_forte(LC* l) {
    if (l == NULL) {
        return 0.0;
    }

    float maxi = l->moyenne;
    LC* m = l->suivant;

    while (m != NULL) {
        if (m->moyenne > maxi) {
            maxi = m->moyenne;
        }
        m = m->suivant;
    }

    return maxi;
}

float moy_gene(LC* l) {
    float moy = 0;
    int n = 0;
    
    LC* m = l;
    while (m != NULL) {
        moy += m->moyenne;
        n++;
        m = m->suivant;
    }
    
    if (n == 0) {
        return 0;
    }
    
    return moy / n;
}

void rang_eleve(LC* l) {
    if (l == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    LC* courant = l;
    int rang = 1;

    while (courant != NULL) {
        LC* comparer = l;
        int rang_actuel = 1;

        while (comparer != NULL) {
            if (comparer->moyenne > courant->moyenne) {
                rang_actuel++;
            }
            comparer = comparer->suivant;
        }

        printf("L'élève %s %s a le rang : %d\n", courant->nom, courant->prenoms, rang_actuel);
        courant = courant->suivant;
        rang++;
    }
}

int main() {
    char sname[30], fname[50];
    float n1, n2;
    int i, i1 = 0, choix;
    LC* k = init_liste();
    
    printf(" ----------------------------------------------------------------------------------- \n");
    printf("donnees concernant des eleves \n");
    printf("veuillez saisir le nombre d'eleve : ");
    scanf("%d", &i);
    
    printf(" ----------------------------------------------------------------------------------- \n\nvous allez commencer la saisie\n");
    
    while (i1 < i) {
        printf(" ----------------------------------------------------------------------------------- \n");
        printf("Entrer le nom de l'eleve: ");
        scanf("%s", sname);
        printf("\nEntrer le(s) prenom(s) de l'eleve: ");
        scanf("%s", fname);
        printf("\nEntrer sa note en Maths: ");
        scanf("%f", &n1);
        printf("\nEntrer sa note en Science-Physique: ");
        scanf("%f", &n2);
        ajouter_element_fin(&k, sname, fname, n1, n2);
        i1++;
    }

    printf("\nVous avez terminé la saisie.\n");
    afficherListeChainee(k);
    
    printf("Veuillez faire un choix :\n");
    do {
        printf("1 : afficher la moyenne la plus élevée\n2 : afficher la moyenne générale\n3 : afficher le rang de chaque élève\n4 : fin des opérations\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("La moyenne la plus élevée est : %.2f\n", moy_forte(k));
                printf("***************************\n");
                break;
            case 2:
                printf("La moyenne générale est : %.2f\n", moy_gene(k));
                printf("***************************\n");
                break;
            case 3:
                rang_eleve(k);
                printf("***************************\n");
                break;
            case 4:
                printf("Fin des opérations.\n");
                break;
            default:
                printf("Veuillez entrer une option valide.\n");
        }
    } while (choix != 4);

    // Libérer la mémoire allouée pour la liste
    LC* temp;
    while (k != NULL) {
        temp = k;
        k = k->suivant;
        free(temp);
    }

    return 0;
}
