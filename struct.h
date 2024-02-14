#include<stdio.h>
#include<stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
//Dimensions de la fenetre : 
#define HAUTEUR 1000
#define LONGUEUR 1000

// Dimensions de la grille en nombre de cases (origine en haut a gauche) :
#define COLONNES 12
#define LIGNES 18

// Les deux camps :
#define ABEILLE 'A'
#define FRELON 'F'

// Les types d'unites :
#define REINE 'r'
#define OUVRIERE 'o'
#define ESCADRON 'e'
#define GUERRIERE 'g'
#define RUCHE 'R'
#define NID 'N'

// Pour la recolte de pollen
#define RECOLTE 'p'
#define PASRECOLTE 'N'

// Les temps necessaires a la production :
#define TREINEA 8
#define TOUVRIERE 2
#define TGUERRIERE 4
#define TESCADRON 6


#define TREINEF 8
#define TFRELON 5
#define TRECOLTE 4

// Les couts necessaires a la production :


#define COUVRIERE 3
#define CGUERRIERE 5
#define CESCADRON 6
#define CREINEA 7
#define CRUCHE 10

#define CFRELON 3
#define CREINEF 8
#define CNID 10


// La force des unites
#define FREINE 6
#define FOUVRIERE 1
#define FGUERRIERE 5
#define FESCADRON 12
#define FFRELON 8



/*
    @struct Unite
    @brief Structure représentant une unité du jeu.

    @param camp: ABEILLE ou FRELON (char)
    @param type: RUCHE, NID, REINE, OUVRIERE, GUERRIERE, ESCADRON ou FRELON (char)
    @param force: la force de l'unité (int)
    @param posx, posy: position actuelle sur la grille (int)
    @param destx, desty: destination (négatif si immobile) (int)
    @param production: production d'une ruche ou d'un nid et RECOLTE pour la récolte de pollen (char)
    @param temps: nombre de tours total pour cette production (int)
    @param toursrestant: tours restant pour cette production (int)
    @prod_en_cours: nombre de tours de récolte restants à une ouvrière (int)
    @point_de_vie: nombre de point_de_vie d'une unité (int)
    @peut_jouer: indique si une unnité peut jouer ou si elle est encore en cours de fabrication (int)
    @couleur: couleur du texte représentnant l'unité sur l'interface graphique (dépend de sa colonie affiliée) (MLV_Color)
    @param usuiv, uprec: liste des unités affiliées à une ruche ou un nid (struct unite*)
    @param colsuiv, colprec: liste des autres ruches ou nids (colonies) du même camp (struct unite*)
    @param vsuiv, vprec: liste des autres unités sur la même case (struct unite*)
*/
typedef struct unite { 
    char camp; 
    char type; 
    int force; 
    int posx, posy; 
    char production; 
    int cree_ruche;
    int temps; 
    int toursrestant; 
    int prod_en_cours;
    int point_de_vie;
    int peut_jouer;
    MLV_Color couleur ;
    struct unite *usuiv, *uprec; 
    struct unite *colsuiv, *colprec; 
    struct unite *vsuiv, *vprec; 
} Unite, *UListe;


/*
    @struct Case
    @brief Structure représentant une case du jeu.

    @param colonie: Pointeur vers une ruche ou un nid sur la case (struct unite*)
    @param occupant: Liste des autres occupants de la case (struct UListe*)
*/
typedef struct {
    Unite *colonie; 
    UListe occupant; 
} Case;


/*
    @struct Grille
    @brief Structure représentant la grille du jeu.

    @param plateau: Tableau 2D de cases représentant la grille (struct Case[COLONNES][LIGNES])
    @param abeille : Listes d'unités abeille (struct UListe*)
    @param frelon : Listes d'unités  frelon (struct UListe*)
    @param tour: Numéro du tour actuel (int)
    @param ressourcesAbeille : Ressources des abeilles (int)
    @param ressourcesFrelon : Ressources des frelons (int)
*/
typedef struct {
    Case plateau[LIGNES][COLONNES];
    UListe abeille, frelon;
    int tour; 
    int ressourcesAbeille, ressourcesFrelon;
} Grille;


/*
    @struct Point
    @brief Structure représentant un point avec des coordonnées x et y.

    @param x: Coordonnée x du point (float)
    @param y: Coordonnée y du point (float)
*/
typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    int x;
    int y;
} Pointint;


/*
    @struct Cell
    @brief Structure représentant une cellule avec des coordonnées x et y, 
    ainsi que des points haut_gauche, haut_droite, bas_gauche, bas_droite définissant les coins de la cellule.

    @param x: Coordonnée x de la cellule (int)
    @param y: Coordonnée y de la cellule (int)
    @param haut_gauche: Point en haut à gauche de la cellule (struct Point)
    @param haut_droite: Point en haut à droite de la cellule (struct Point)
    @param bas_gauche: Point en bas à gauche de la cellule (struct Point)
    @param bas_droite: Point en bas à droite de la cellule (struct Point)
    @param suivant: Pointeur vers la cellule suivante (struct cell*)
*/
typedef struct cell {
    int x;
    int y;
    Point haut_gauche;
    Point haut_droite;
    Point bas_gauche;
    Point bas_droite;


    Point case_haut_droite_haut_gauche;
    Point case_haut_droite_haut_droite;
    Point case_haut_droite_bas_gauche;
    Point case_haut_droite_bas_droite;

    Point case_haut_gauche_haut_gauche;
    Point case_haut_gauche_haut_droite;
    Point case_haut_gauche_bas_gauche;
    Point case_haut_gauche_bas_droite;

    Point case_milieu_gauche_haut_gauche;
    Point case_milieu_gauche_haut_droite;
    Point case_milieu_gauche_bas_gauche;
    Point case_milieu_gauche_bas_droite;

    Point case_milieu_milieu_haut_gauche;
    Point case_milieu_milieu_haut_droite;
    Point case_milieu_milieu_bas_gauche;
    Point case_milieu_milieu_bas_droite;

    Point case_milieu_droite_haut_gauche;
    Point case_milieu_droite_haut_droite;
    Point case_milieu_droite_bas_gauche;
    Point case_milieu_droite_bas_droite;


    Point case_bas_droite_haut_gauche;
    Point case_bas_droite_haut_droite;
    Point case_bas_droite_bas_gauche;
    Point case_bas_droite_bas_droite;

    Point case_bas_gauche_haut_gauche;
    Point case_bas_gauche_haut_droite;
    Point case_bas_gauche_bas_gauche;
    Point case_bas_gauche_bas_droite;


    struct cell *suivant;
} Cell, *Liste_coord;
