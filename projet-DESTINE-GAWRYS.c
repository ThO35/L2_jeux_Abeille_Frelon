
#include "struct.h"

/**
 * Alloue dynamiquement de la mémoire pour une nouvelle unité dans une liste.
 *
 * @return Un pointeur vers la nouvelle unité allouée (UListe), ou NULL en cas d'échec.
 *
 * Cette fonction alloue dynamiquement de la mémoire pour une nouvelle unité
 * (de type Unite) dans une liste et renvoie un pointeur vers cette unité.
 * En cas d'échec de l'allocation mémoire, la fonction renvoie NULL.
 */
UListe allouerUListe() {
    UListe p;
    p = (Unite*)malloc(sizeof(Unite));
    if (p) return p;
    return NULL;
}


/**
 * Crée une couleur aléatoire en utilisant les composantes rouge, vert et bleu.
 *
 * @param i Un entier utilisé pour générer une couleur unique (peut être ignoré).
 * @return La couleur générée au format MLV_Color (MLV_rgba).
 *
 * Cette fonction utilise la fonction rand() pour générer des valeurs aléatoires
 * pour les composantes rouge, vert et bleu, et renvoie une couleur opaque avec
 * une composante alpha de 255.
 */
MLV_Color fabriqueCouleur(int i) {
    int rouge = rand() % 256;
    int vert = rand() % 256;
    int bleu = rand() % 256;
    return MLV_rgba(rouge, vert, bleu, 255);
}


/**
 * Affiche un texte sur une case spécifique de la grille en fonction des coordonnées et du type d'unité.
 *
 * @param p La liste de coordonnées représentant la grille.
 * @param x La coordonnée x de la case où afficher le texte.
 * @param y La coordonnée y de la case où afficher le texte.
 * @param coul La couleur du texte à afficher.
 * @param lst La liste d'unités contenant le type d'unité à afficher.
 * @return 1 si le texte a été affiché avec succès, 0 sinon.
 *
 * Cette fonction parcourt la liste de coordonnées pour trouver la case spécifiée par les coordonnées (x, y).
 * Elle utilise le type d'unité (lst->type) pour déterminer quel texte afficher sur la case.
 * La fonction utilise la bibliothèque MLV pour dessiner un texte box avec le texte approprié sur la case.
 * Elle renvoie 1 si le texte a été affiché avec succès, et 0 sinon.
 */
int afiche_texte(Liste_coord p, int x, int y, MLV_Color coul ,UListe lst) {
    while (p != NULL) {
        if (p->x == x && p->y == y) {
            if (lst->type == FRELON)MLV_draw_text_box(p->case_milieu_droite_haut_gauche.x, p->case_milieu_droite_haut_gauche.y,p->case_milieu_droite_haut_droite.x-p->case_milieu_droite_haut_gauche.x,p->case_milieu_droite_bas_gauche.y-p->case_milieu_droite_haut_gauche.y,"f",0,MLV_COLOR_WHITE,coul, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst->type == OUVRIERE)MLV_draw_text_box(p->case_milieu_gauche_haut_gauche.x,p->case_milieu_gauche_haut_gauche.y,p->case_milieu_gauche_haut_droite.x-p->case_milieu_gauche_haut_gauche.x,p->case_milieu_gauche_bas_gauche.y-p->case_milieu_gauche_haut_gauche.y,"o",0,MLV_COLOR_WHITE,coul, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst->type == GUERRIERE)MLV_draw_text_box(p->case_bas_gauche_haut_gauche.x,p->case_bas_gauche_haut_gauche.y,  p->case_bas_gauche_haut_droite.x-p->case_bas_gauche_haut_gauche.x, p->case_bas_gauche_bas_gauche.y-p->case_bas_gauche_haut_gauche.y,"g",0,MLV_COLOR_WHITE,coul, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst->type == ESCADRON)MLV_draw_text_box(p->case_bas_droite_haut_gauche.x,p->case_bas_droite_haut_gauche.y,p->case_bas_droite_haut_droite.x-p->case_bas_droite_haut_gauche.x, p->case_bas_droite_bas_gauche.y-p->case_bas_droite_haut_gauche.y,"e",0,MLV_COLOR_WHITE,coul, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst->type == RUCHE)MLV_draw_text_box(p->case_milieu_milieu_haut_gauche.x,p->case_milieu_milieu_haut_gauche.y,p->case_milieu_milieu_haut_droite.x-p->case_milieu_milieu_haut_gauche.x,p->case_milieu_milieu_bas_gauche.y-p->case_milieu_milieu_haut_gauche.y,"R",0,MLV_COLOR_WHITE,coul, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst->type== NID)MLV_draw_text_box(p->case_milieu_milieu_haut_gauche.x,p->case_milieu_milieu_haut_gauche.y, p->case_milieu_milieu_haut_droite.x-p->case_milieu_milieu_haut_gauche.x,   p->case_milieu_milieu_bas_gauche.y-p->case_milieu_milieu_haut_gauche.y,"N",0,MLV_COLOR_WHITE,coul, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst->type== REINE && lst->camp == FRELON)MLV_draw_text_box(p->case_haut_droite_haut_gauche.x,p->case_haut_droite_haut_gauche.y,p->case_haut_droite_haut_droite.x-p->case_haut_droite_haut_gauche.x, p->case_haut_droite_bas_gauche.y-p->case_haut_droite_haut_gauche.y,"RF",0,MLV_COLOR_WHITE,coul, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst->type== REINE && lst->camp == ABEILLE)MLV_draw_text_box(p->case_haut_gauche_haut_gauche.x,p->case_haut_gauche_haut_gauche.y,p->case_haut_gauche_haut_droite.x-p->case_haut_gauche_haut_gauche.x, p->case_haut_gauche_bas_gauche.y-p->case_haut_gauche_haut_gauche.y,"RA",0,MLV_COLOR_WHITE,coul, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
           return 1;
        }   
        p = p->suivant;
    }
    return 0;
}


/**
 * Recherche les coordonnées correspondant à une position spécifique dans une liste de coordonnées.
 *
 * @param p La liste de coordonnées représentant la grille.
 * @param x La coordonnée x de la position à rechercher.
 * @param y La coordonnée y de la position à rechercher.
 * @return Une structure Pointint contenant les coordonnées correspondantes, ou {-1, -1} si non trouvées.
 *
 * Cette fonction parcourt la liste de coordonnées pour trouver les coordonnées correspondant à la position spécifiée.
 * Elle compare la position avec les coordonnées des coins supérieur gauche (haut_gauche) et inférieur droit (bas_droite)
 * de chaque case dans la liste. Si la position se trouve à l'intérieur d'une case, les coordonnées de cette case sont renvoyées.
 * Si aucune correspondance n'est trouvée, la fonction renvoie la structure Pointint {-1, -1}.
 */
Pointint recherche_coord(Liste_coord p, int x, int y) {
    Pointint point ={-1,-1};
    while (p != NULL) {
        if (p->haut_droite.x >= x && x >= p->haut_gauche.x) {
            if (p->haut_droite.y <= y && y <= p->bas_gauche.y) {
                point.x=p->x;
                point.y=p->y;
                return point;
            }
        }

        p = p->suivant;
    }
    return point;
}


/**
 * Vérifie si une position est voisine d'une autre position dans une grille rectangulaire.
 *
 * @param x La coordonnée x de la position initiale.
 * @param y La coordonnée y de la position initiale.
 * @param voisinx La coordonnée x de la position voisine à vérifier.
 * @param voisiny La coordonnée y de la position voisine à vérifier.
 * @return TRUE si la position voisine est valide, FALSE sinon.
 *
 * Cette fonction vérifie si la position (voisinx, voisiny) est une position voisine de la position (x, y)
 * dans une grille rectangulaire. Elle renvoie TRUE si les positions sont voisines et FALSE sinon.
 * Les positions sont considérées comme voisines si elles diffèrent d'au plus une unité horizontalement,
 * verticalement ou en diagonale. Les positions en dehors des limites de la grille sont considérées comme non valides.
 */
int est_voisin(int x,int y,int voisinx ,int voisiny){
    if (voisinx<0 || voisiny<0 || x>LONGUEUR || y>HAUTEUR)return 0;
    if (x+1==voisinx && y==voisiny)return 1;
    if (x-1==voisinx && y==voisiny)return 1;
    if (x==voisinx && y+1==voisiny)return 1;
    if (x==voisinx && y-1==voisiny)return 1;
    if (x+1==voisinx && y+1==voisiny)return 1;
    if (x-1==voisinx && y-1==voisiny)return 1;
    if (x-1==voisinx && y+1==voisiny)return 1;
    if (x+1==voisinx && y-1==voisiny)return 1;
return 0;
}


/**
 * Affiche une fenêtre de début avec une grille de cases dessinées et initialise une liste de coordonnées.
 *
 * @param x La largeur de la fenêtre.
 * @param y La hauteur de la fenêtre.
 * @param p Un pointeur vers la liste de coordonnées à initialiser.
 * @return 1 si l'affichage est réussi, -1 en cas d'échec d'allocation mémoire.
 *
 * Cette fonction affiche une fenêtre de début avec une grille de cases dessinées. Chaque case est délimitée par des lignes,
 * et des lignes supplémentaires divisent chaque case en parties. La fonction initialise également une liste de coordonnées
 * associées à chaque case de la grille. Les coordonnées de chaque coin et de certaines parties de la case sont stockées
 * dans la liste pour une utilisation ultérieure. En cas de réussite, la fonction renvoie 1, sinon elle renvoie -1 en cas
 * d'échec d'allocation mémoire.
 */
int affiche_fenetre_debut(int x, int y, Liste_coord *p) {

    float taille_colonnes = ((y)*8 / 10) / (COLONNES);
    float taille_lignes = (x) / (LIGNES);
    
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            Liste_coord c = (Liste_coord)malloc(sizeof(Cell));
            if (c == NULL) return -1;
            MLV_draw_line(taille_lignes * i, taille_colonnes * j, taille_lignes * (i + 1), taille_colonnes * j, MLV_COLOR_ALICE_BLUE);
            MLV_draw_line(taille_lignes * i, taille_colonnes * j, taille_lignes * i, taille_colonnes * (j + 1), MLV_COLOR_ALICE_BLUE);
            MLV_draw_line(taille_lignes * i, taille_colonnes * (j + 1), taille_lignes * (i + 1), taille_colonnes * (j + 1), MLV_COLOR_ALICE_BLUE);
            MLV_draw_line(taille_lignes * (i + 1), taille_colonnes * j, taille_lignes * (i + 1), taille_colonnes * (j + 1), MLV_COLOR_ALICE_BLUE);
            //haut
            MLV_draw_line((taille_lignes * i+taille_lignes * (i + 1))/2,taille_colonnes * j, (taille_lignes * i+taille_lignes * (i + 1))/2, (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2, MLV_COLOR_BLACK);
            MLV_draw_line(taille_lignes * (i+1), (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,(taille_lignes * i+taille_lignes * (i + 1))/2, (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,MLV_COLOR_BLACK);
            MLV_draw_line(taille_lignes * i, (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,(taille_lignes * i+taille_lignes * (i + 1))/2, (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,MLV_COLOR_BLACK);
            //milieu
            MLV_draw_line((taille_lignes * i+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, ((taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2),(taille_lignes * i+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,MLV_COLOR_BLACK);
            MLV_draw_line ((taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, ((taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2),(taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2,  (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,MLV_COLOR_BLACK); 
            MLV_draw_line(((taille_lignes * i+taille_lignes * (i + 1))/2), (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,(taille_lignes * i+taille_lignes * (i + 1))/2, taille_colonnes * (j+1),MLV_COLOR_BLACK);
            //milieu trait          
            MLV_draw_line((taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2,  (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,(taille_lignes * i+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,MLV_COLOR_BLACK);
            MLV_draw_line (taille_lignes * i, (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,(taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2,  (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,MLV_COLOR_BLACK);
            MLV_draw_line (taille_lignes * (i+1), (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,(taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2,  (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2,MLV_COLOR_BLACK);
            
            Point haut_gauche = {taille_lignes * i, taille_colonnes * j};
            c->haut_gauche=haut_gauche;
            Point haut_droite = {taille_lignes * (i + 1), taille_colonnes * j};
            Point bas_gauche = {taille_lignes * i, taille_colonnes * (j + 1)};
            Point bas_droite = {taille_lignes * (i + 1), taille_colonnes * (j + 1)};

            Point case_haut_droite_haut_gauche = {(taille_lignes * i+taille_lignes * (i + 1))/2,taille_colonnes * j};
            Point case_haut_droite_haut_droite = {(taille_lignes * (i+1)),taille_colonnes * j};
            Point case_haut_droite_bas_gauche = {(taille_lignes * i+taille_lignes * (i + 1))/2, (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_haut_droite_bas_droite = {taille_lignes * (i+1), (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};


            Point case_haut_gauche_haut_gauche = {(taille_lignes * i),taille_colonnes * j};
            Point case_haut_gauche_haut_droite = {(taille_lignes * i+taille_lignes * (i + 1))/2,taille_colonnes * j};
            Point case_haut_gauche_bas_gauche = {taille_lignes * i, (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_haut_gauche_bas_droite = {(taille_lignes * i+taille_lignes * (i + 1))/2, (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            
            Point case_milieu_gauche_haut_gauche = { taille_lignes * i, (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};;
            Point case_milieu_gauche_haut_droite = {(taille_lignes * i+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, ((taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2)};
            Point case_milieu_gauche_bas_gauche = {taille_lignes * i, (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2} ;
            Point case_milieu_gauche_bas_droite = {(taille_lignes * i+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            
            
            Point case_milieu_milieu_haut_gauche = {(taille_lignes * i+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, ((taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2)};
            Point case_milieu_milieu_haut_droite = {(taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, ((taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2)};
            Point case_milieu_milieu_bas_gauche = {(taille_lignes * i+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_milieu_milieu_bas_droite = {(taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2,  (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};

            
            Point case_milieu_droite_haut_gauche = {(taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2, ((taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2)};
            Point case_milieu_droite_haut_droite = {taille_lignes * (i+1), (taille_colonnes * j +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_milieu_droite_bas_gauche = {(taille_lignes * (i+1)+((taille_lignes * i+taille_lignes * (i + 1))/2))/2,  (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_milieu_droite_bas_droite = {taille_lignes * (i+1), (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            
           


            Point case_bas_gauche_haut_gauche ={taille_lignes * i, (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_bas_gauche_haut_droite ={((taille_lignes * i+taille_lignes * (i + 1))/2), (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_bas_gauche_bas_gauche ={taille_lignes * i, taille_colonnes * (j + 1)};
            Point case_bas_gauche_bas_droite ={(taille_lignes * i+taille_lignes * (i + 1))/2, taille_colonnes * (j+1)};
           
            Point case_bas_droite_haut_gauche ={((taille_lignes * i+taille_lignes * (i + 1))/2), (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_bas_droite_haut_droite ={taille_lignes * (i+1), (taille_colonnes * (j+1) +(taille_colonnes * j +taille_colonnes * (j + 1))/2)/2};
            Point case_bas_droite_bas_gauche ={(taille_lignes * i+taille_lignes * (i + 1))/2, taille_colonnes * (j+1)};
            Point case_bas_droite_bas_droite ={taille_lignes * (i + 1), taille_colonnes * (j + 1)};
            c->x =i;
            c->y = j;     
            c->haut_droite = haut_droite;
            c->bas_gauche = bas_gauche;
            c->bas_droite = bas_droite;
            c->case_haut_droite_haut_gauche = case_haut_droite_haut_gauche;
            c->case_haut_droite_haut_droite = case_haut_droite_haut_droite;
            c->case_haut_droite_bas_gauche = case_haut_droite_bas_gauche;
            c->case_haut_droite_bas_droite = case_haut_droite_bas_droite;
            c->case_haut_gauche_haut_gauche = case_haut_gauche_haut_gauche;
            c->case_haut_gauche_haut_droite = case_haut_gauche_haut_droite;
            c->case_haut_gauche_bas_gauche = case_haut_gauche_bas_gauche;
            c->case_haut_gauche_bas_droite = case_haut_gauche_bas_droite;
            c->case_milieu_gauche_haut_gauche = case_milieu_gauche_haut_gauche;
            c->case_milieu_gauche_haut_droite = case_milieu_gauche_haut_droite;
            c->case_milieu_gauche_bas_gauche = case_milieu_gauche_bas_gauche;
            c->case_milieu_gauche_bas_droite = case_milieu_gauche_bas_droite;
            c->case_milieu_milieu_haut_gauche = case_milieu_milieu_haut_gauche;
            c->case_milieu_milieu_haut_droite = case_milieu_milieu_haut_droite;
            c->case_milieu_milieu_bas_gauche = case_milieu_milieu_bas_gauche;
            c->case_milieu_milieu_bas_droite = case_milieu_milieu_bas_droite;
            c->case_milieu_droite_haut_gauche = case_milieu_droite_haut_gauche;
            c->case_milieu_droite_haut_droite = case_milieu_droite_haut_droite;
            c->case_milieu_droite_bas_gauche = case_milieu_droite_bas_gauche;
            c->case_milieu_droite_bas_droite = case_milieu_droite_bas_droite;
            c->case_bas_gauche_haut_gauche = case_bas_gauche_haut_gauche;
            c->case_bas_gauche_haut_droite = case_bas_gauche_haut_droite;
            c->case_bas_gauche_bas_gauche = case_bas_gauche_bas_gauche;
            c->case_bas_gauche_bas_droite = case_bas_gauche_bas_droite;
            c->case_bas_droite_haut_gauche = case_bas_droite_haut_gauche;
            c->case_bas_droite_haut_droite = case_bas_droite_haut_droite;
            c->case_bas_droite_bas_gauche = case_bas_droite_bas_gauche;
            c->case_bas_droite_bas_droite = case_bas_droite_bas_droite;
            c->suivant =NULL;
            if (*p == NULL) {
                *p = c;
            } else {
                while ((*p) != NULL) {
                    p = &(*p)->suivant;
                }
                *p = c;
            }  
            MLV_update_window();
        }
    }
    return 1;
}


/**
 * Ajoute une maison (NID ou RUCHE) à la liste des maisons.
 *
 * @param x La position x de la maison.
 * @param y La position y de la maison.
 * @param ruche Un pointeur vers la liste des maisons existantes.
 * @param type Le type de la maison (NID ou RUCHE).
 * @return Un pointeur vers la liste mise à jour des maisons.
 *
 * Cette fonction crée une nouvelle maison avec les propriétés spécifiées (position, type, etc.) et l'ajoute à la liste
 * existante des maisons. La fonction renvoie un pointeur vers la liste mise à jour. Si l'allocation mémoire pour la
 * nouvelle maison échoue, la fonction renvoie NULL.
 */
UListe Ajout_Maison(int x, int y, UListe *ruche, char type) {
    UListe lst = allouerUListe();
    if (lst) {
        if (type == NID) lst->camp = FRELON;
        if (type == RUCHE) lst->camp = ABEILLE;
        lst->type = type;
        lst->posx = x;
        lst->posy = y;
        lst->usuiv = NULL;
        lst->uprec = NULL;
        lst->colprec = NULL;
        lst->colsuiv = NULL;
        lst->couleur = fabriqueCouleur(10);
        lst->point_de_vie = 0;
        lst->peut_jouer = 0;
        lst->production = 'Z';
        lst->prod_en_cours = -1;
        lst->toursrestant = -1;

        if (*ruche) {
            UListe dernier = *ruche;
            while (dernier->colsuiv) {
                dernier = dernier->colsuiv;
            }
            dernier->colsuiv = lst;
            lst->colprec = dernier;
            return *ruche;
        } else {
            return *ruche = lst;
        }
    }
    return NULL;
}


/**
 * Crée une nouvelle unité et l'ajoute à la liste d'unités existante.
 *
 * @param x La position x initiale de l'unité.
 * @param y La position y initiale de l'unité.
 * @param unite Un pointeur vers la liste d'unités existante.
 * @param nom Le nom de l'unité (REINE, OUVRIERE, GUERRIERE, ESCADRON, FRELON).
 * @param camp Le camp de l'unité (ABEILLE ou FRELON).
 * @return Un pointeur vers la liste mise à jour d'unités.
 *
 * Cette fonction crée une nouvelle unité avec les propriétés spécifiées (position, nom, camp, etc.)
 * et l'ajoute à la liste existante d'unités. La fonction renvoie un pointeur vers la liste mise à jour.
 * Si l'allocation mémoire pour la nouvelle unité échoue, la fonction renvoie NULL.
 */
Unite *Creation_Unite(int x, int y, UListe *unite, char nom, char camp) {
    // Allouer une nouvelle structure pour représenter une unitéCreation
    UListe lst = allouerUListe();

    if (lst) {
        // Initialiser les propriétés de l'unité en fonction du nom et du camp

        // Si l'unité est une abeille ou un frelon, elle ne crée pas de ruche

        // Si l'unité est une reine, définir son camp
        if (camp == ABEILLE && nom == REINE)
            lst->camp = ABEILLE;
        if (camp == FRELON && nom == REINE)
            lst->camp = FRELON;

        // Définir le camp en fonction du type d'unité
        if (nom == OUVRIERE || nom == GUERRIERE || nom == ESCADRON)
            lst->camp = ABEILLE;
        if (nom == FRELON)
            lst->camp = FRELON;

        // Définir le type et la force de l'unité
        lst->type = nom;
        if (nom == REINE)
            lst->force = FREINE;
        if (nom == OUVRIERE)
            lst->force = FOUVRIERE;
        if (nom == GUERRIERE)
            lst->force = FGUERRIERE;
        if (nom == ESCADRON)
            lst->force = FESCADRON;
        if (nom == FRELON)
            lst->force = FFRELON;
        if (nom == OUVRIERE)
            lst->production =PASRECOLTE;
        else lst->production = 'Z';
        

        // Définir la position et la destination initiales de l'unité
        lst->posx = x;
        lst->posy = y;
        lst->point_de_vie = lst->force + 12;
        lst->prod_en_cours = -1;
        lst->peut_jouer = 0;

        // Définir le temps et les tours restants en fonction du type d'unité
        if (nom == REINE && camp ==ABEILLE) lst->temps =TREINEA;
        if (nom == REINE && camp ==ABEILLE) lst->temps =TREINEF; 
        if (nom == OUVRIERE) lst->temps =TOUVRIERE; 
        if (nom == GUERRIERE) lst->temps = TGUERRIERE;
        if (nom == ESCADRON)  lst->temps = TESCADRON;
        if (nom ==  FRELON)lst->temps =TFRELON;
        
        lst->toursrestant =lst->temps+1;
        lst->usuiv=NULL;
        lst->uprec=NULL;
        lst->vprec=NULL;
        lst->vsuiv=NULL;
    

        // Ajouter l'unité à la liste d'unités existante
        if (*unite) {
            (*unite)->uprec = lst;
            lst->usuiv = *unite;
            *unite = lst;
            
        } else {
            *unite = lst;
            
        }
    return *unite;
    }

    // Retourner NULL (possiblement pour indiquer une erreur ou une absence de résultat)
    return NULL;
}


/**
 * Crée une nouvelle unité au début de la liste d'unités existante.
 *
 * @param x La position x initiale de l'unité.
 * @param y La position y initiale de l'unité.
 * @param unite Un pointeur vers la liste d'unités existante.
 * @param nom Le nom de l'unité (REINE, OUVRIERE, GUERRIERE, ESCADRON, FRELON).
 * @param camp Le camp de l'unité (ABEILLE ou FRELON).
 * @return Un pointeur vers la liste mise à jour d'unités.
 *
 * Cette fonction crée une nouvelle unité avec les propriétés spécifiées (position, nom, camp, etc.)
 * et l'ajoute au début de la liste existante d'unités. La fonction renvoie un pointeur vers la liste mise à jour.
 * Si l'allocation mémoire pour la nouvelle unité échoue, la fonction renvoie NULL.
 */
Unite *Creation_Unite_debut(int x, int y, UListe *unite, char nom, char camp) {
    // Allouer une nouvelle structure pour représenter une unitéCreation
    UListe lst = allouerUListe();

    if (lst) {
        // Initialiser les propriétés de l'unité en fonction du nom et du camp

        // Si l'unité est une abeille ou un frelon, elle ne crée pas de ruche

        // Si l'unité est une reine, définir son camp
        if (camp == ABEILLE && nom == REINE)
            lst->camp = ABEILLE;
        if (camp == FRELON && nom == REINE)
            lst->camp = FRELON;

        // Définir le camp en fonction du type d'unité
        if (nom == OUVRIERE || nom == GUERRIERE || nom == ESCADRON)
            lst->camp = ABEILLE;
        if (nom == FRELON)
            lst->camp = FRELON;

        // Définir le type et la force de l'unité
        lst->type = nom;
        if (nom == REINE)
            lst->force = FREINE;
        if (nom == OUVRIERE)
            lst->force = FOUVRIERE;
        if (nom == GUERRIERE)
            lst->force = FGUERRIERE;
        if (nom == ESCADRON)
            lst->force = FESCADRON;
        if (nom == FRELON)
            lst->force = FFRELON;
        if (nom == OUVRIERE)
            lst->production =PASRECOLTE;
        else lst->production = 'Z';
        // Définir la position et la destination initiales de l'unité
        lst->posx = x;
        lst->posy = y;
        lst->point_de_vie = lst->force + 12;
        lst->prod_en_cours = -1;
        lst->peut_jouer = 0;
        lst->usuiv=NULL;
        lst->uprec=NULL;
        lst->vprec=NULL;
        lst->vsuiv=NULL;

        // Définir le temps et les tours restants en fonction du type d'unité
        
        lst->temps=0;
        lst->toursrestant=0;
    

        // Ajouter l'unité à la liste d'unités existante
        if (*unite) {
            (*unite)->uprec = lst;
            lst->usuiv = *unite;
            *unite = lst;
            
        } else {
            *unite = lst;
            
        }
    return *unite;
    }

    // Retourner NULL (possiblement pour indiquer une erreur ou une absence de résultat)
    return NULL;
}


/**
 * Initialise tous les éléments du tableau de la grille.
 *
 * @param tableau Un pointeur vers la grille à initialiser.
 *
 * Cette fonction parcourt tous les éléments du tableau de la grille
 * et initialise les champs 'occupant' et 'colonie' à NULL.
 */
void init_plateau(Grille *tableau) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES ;j++) {
            (*tableau).plateau[i][j].occupant = NULL;
            (*tableau).plateau[i][j].colonie=NULL;
        }
    }
}


/**
 * Ajoute une nouvelle unité à la fin de la liste chaînée.
 * 
 * @param mainListe Pointeur vers la tête de la liste.
 * @param unite_ajout Unité à ajouter à la liste.
 * @return 1 en cas de succès, 0 en cas d'échec de l'allocation mémoire.
 */
int ajoute_case(UListe* mainListe, UListe unite_ajout) {
    // Allouer une nouvelle unité
    UListe lst = (UListe)malloc(sizeof(struct unite));
    if (lst) {
        // Copier les données de unite_ajout dans la nouvelle allocation
        lst = unite_ajout;  // Copie la structure
        lst->vsuiv = NULL;
        lst->vprec = NULL;
        // Ajouter la nouvelle unité à la fin de la liste
        if (*mainListe) {
            UListe dernier = *mainListe;
            while (dernier->vsuiv) {
                dernier = dernier->vsuiv;
            }
            dernier->vsuiv = lst;
            lst->vprec = dernier;
        } else {
            // Si la liste est vide, la nouvelle unité devient la tête de liste
            *mainListe = lst;
        }
        return 1;  // Succès
    }
    return 0;  // Échec de l'allocation mémoire
}


/**
 * Supprime l'unité spécifiée de la liste chaînée.
 * 
 * @param lst_unite Pointeur vers la tête de la liste.
 * @param a_efface Unité à supprimer.
 * @return 1 en cas de succès, 0 si l'unité n'a pas été trouvée.
 */
int efface_unite(UListe *lst_unite, Unite *a_efface) {
    while (*lst_unite != NULL) {
        if (*lst_unite == a_efface) {
            // Cas où l'élément à supprimer est en fin de liste
            if ((*lst_unite)->usuiv == NULL) {
                UListe copie = (*lst_unite)->uprec;
                free(*lst_unite);
                *lst_unite = copie;
                if (copie != NULL) {
                    copie->usuiv = NULL;
                }
                return 1;
            }
            // Cas où l'élément à supprimer est en début de liste
            else if ((*lst_unite)->uprec == NULL) {
                UListe copie = (*lst_unite)->usuiv;
                free(*lst_unite);
                *lst_unite = copie;
                if (copie != NULL) {
                    copie->uprec = NULL;
                }
                return 1;
            }
            // Cas général (élément à supprimer est au milieu)
            else {
                UListe copie = *lst_unite;
                (*lst_unite)->usuiv->uprec = (*lst_unite)->uprec;
                (*lst_unite)->uprec->usuiv = (*lst_unite)->usuiv;
                free(copie);
                return 1;
            }
        }
        // Avance dans la liste
        lst_unite = &(*lst_unite)->usuiv;
    }
    // L'élément à supprimer n'a pas été trouvé
    return 0;
}



/**
 * Remplit le tableau avec les informations provenant de la liste chaînée.
 * 
 * @param lst_camp Liste chaînée d'éléments à ajouter au tableau.
 * @param tableau Pointeur vers la grille à remplir.
 * @param p Structure Liste_coord pour afficher les informations.
 * @return 1 en cas de succès, -1 en cas d'échec.
 */
int remplir_case_init(UListe lst_camp, Grille *tableau,Liste_coord p) { 
    while (lst_camp) {
        
        afiche_texte(p, lst_camp->posx, lst_camp->posy,lst_camp->couleur,lst_camp);
        int lst1 = ajoute_case(&(*tableau).plateau[lst_camp->posx][lst_camp->posy].colonie, lst_camp);
        if (lst1 == 0)return -1;
        if (lst_camp->usuiv) { 
            UListe suivant = lst_camp->usuiv;
            while (suivant) {
                if (ajoute_case(&(*tableau).plateau[suivant->posx][suivant->posy].occupant, suivant) == 0)
                    return -1;
                afiche_texte(p, suivant->posx,suivant->posy,lst_camp->couleur,suivant);
                suivant = suivant->usuiv;
            }
        }

        lst_camp = lst_camp->colsuiv;
    }
    MLV_update_window();
    return 1; // Succès
}


/**
 * Libère la mémoire allouée pour chaque élément de la liste chaînée.
 * 
 * @param p Pointeur vers la tête de la liste chaînée.
 */
void libere_unite_ruche(UListe*p) {
    UListe copie = *p;
    UListe suiv;
    while (copie != NULL) {
        suiv = copie->usuiv;
        free(copie);
        copie = suiv;
    }
    *p =NULL;
}


/**
 * Supprime l'unité spécifiée de la liste chaînée et libère la mémoire associée.
 * 
 * @param lst_unite Pointeur vers la tête de la liste chaînée.
 * @param a_efface Unité à supprimer.
 * @return 1 en cas de succès, 0 si l'unité n'a pas été trouvée.
 *
 * Cette fonction permet de supprimer une unité spécifique d'une liste chaînée. Elle gère également
 * la libération de la mémoire associée à cette unité ainsi qu'à la liste chaînée qui la suit (usuiv).
 * La fonction prend en compte différentes situations telles que la position de l'unité dans la liste
 * et ajuste les liens pour maintenir l'intégrité de la structure de la liste.
 */
int efface_Maison(UListe *lst_unite, Unite *a_efface) {
    while (*lst_unite != NULL) {
        if (*lst_unite == a_efface) {
            libere_unite_ruche(&(*lst_unite)->usuiv);
            if ((*lst_unite)->colsuiv == NULL) {
                UListe copie =(*lst_unite)->colprec;
                free (*lst_unite);
                (*lst_unite) = copie;
                (*lst_unite)=NULL;
                return 1;
            } 
            else if ((*lst_unite)->colprec == NULL){
                UListe copie =(*lst_unite)->colsuiv;
                free (*lst_unite);
                (*lst_unite) = copie;
                (*lst_unite)->colprec=NULL;
                return 1;
                }

            else{
                UListe copie= (*lst_unite);
                (*lst_unite)->colsuiv->colprec = (*lst_unite)->colprec;
                (*lst_unite)->colprec->colsuiv = (*lst_unite)->colsuiv;
                copie->colsuiv=NULL;
                copie->colprec=NULL;
                free(copie);
                return 1;
            }
        }
        lst_unite = &(*lst_unite)->colsuiv;

    }
    return 0;
}


/**
 * Initialise le plateau et remplit le tableau avec les informations des listes de camps.
 * 
 * @param lst_camp Liste chaînée d'éléments de camp à ajouter au tableau.
 * @param lst_camp_frelon Liste chaînée d'éléments de frelons à ajouter au tableau.
 * @param tableau Pointeur vers la grille à remplir.
 * @param p Structure Liste_coord pour afficher les informations.
 * @return 1 en cas de succès, -1 en cas d'échec lors du remplissage.
 *
 * Cette fonction initialise le plateau (tableau) en utilisant la fonction init_plateau.
 * Ensuite, elle tente de remplir le tableau avec les informations provenant de deux listes chaînées,
 * lst_camp et lst_camp_frelon, en utilisant la fonction remplir_case_init.
 * Si l'une des opérations de remplissage échoue, la fonction retourne -1.
 * Sinon, elle retourne 1 pour indiquer le succès de l'opération.
 */
int complete_case(UListe lst_camp, UListe lst_camp_frelon, Grille *tableau,Liste_coord p){ 
    init_plateau(tableau);
    int lst1 = remplir_case_init(lst_camp,tableau, p);
    if (lst1 == -1) return -1;
    int lst2 = remplir_case_init(lst_camp_frelon,tableau,p);
    if (lst2 == -1) return -1;
    return 1;
}


/**
 * Initialise le jeu en définissant les ressources, créant les maisons et les unités au début.
 * 
 * @param jeux Pointeur vers la grille représentant l'état du jeu.
 * @param p Structure Liste_coord pour afficher les informations.
 * @return 1 en cas de succès, -1 en cas d'échec lors de l'initialisation.
 *
 * Cette fonction initialise le jeu en définissant les ressources des abeilles et des frelons.
 * Elle crée une maison pour les abeilles et les frelons, puis ajoute des unités de différents types
 * à ces maisons. Enfin, elle appelle la fonction complete_case pour remplir le tableau avec ces informations.
 * La fonction retourne 1 en cas de succès et -1 en cas d'échec lors de l'initialisation.
 */
int debut_jeux(Grille *jeux,Liste_coord p) {
    jeux->ressourcesAbeille =50;
    jeux->ressourcesFrelon =10;
    UListe lst1 = Ajout_Maison(0, 0, &(jeux->abeille), RUCHE);
        if (lst1 == NULL) return -1;
    UListe lst2 = Creation_Unite_debut(0, 0, &(jeux->abeille->usuiv), OUVRIERE,ABEILLE);
        if (lst2 == NULL) return -1;
    UListe lst3 = Creation_Unite_debut(0, 0, &(jeux->abeille->usuiv), REINE,ABEILLE);
        if (lst3 == NULL) return -1;
    UListe lst5 = Creation_Unite_debut(0, 0, &(jeux->abeille->usuiv), GUERRIERE,ABEILLE);
        if (lst5 == NULL) return -1;
    UListe lst55 = Creation_Unite_debut(0, 0, &(jeux->abeille->usuiv), ESCADRON,ABEILLE);
        if (lst55 == NULL) return -1;


    UListe lst7 = Ajout_Maison(LIGNES-1, COLONNES-1, &(jeux->frelon), NID);
        if (lst7 == NULL) return -1;

    UListe lst8 = Creation_Unite_debut(LIGNES-1, COLONNES-1, &(jeux->frelon->usuiv), FRELON,FRELON);
    if (lst8 == NULL) return -1;

    UListe lst110 = Creation_Unite_debut(LIGNES-1, COLONNES-1, &(jeux->frelon->usuiv), FRELON,FRELON);
    if (lst110 == NULL) return -1;

    
    int lstcc = complete_case(jeux->abeille, jeux->frelon, jeux,p);
    if (lstcc == -1)return -1;
    return 1;
}


/**
 * Vérifie si une unité de type spécifié appartenant à un camp spécifié existe déjà dans la liste.
 * 
 * @param lst_camp Liste chaînée d'unités à vérifier.
 * @param type Type de l'unité à rechercher.
 * @param camp Camp de l'unité à rechercher.
 * @return 0 si l'unité existe déjà, 1 sinon.
 *
 * Cette fonction parcourt la liste chaînée d'unités et vérifie si une unité de type spécifié
 * appartenant à un camp spécifié existe déjà. Elle retourne 0 si une telle unité est trouvée,
 * indiquant qu'elle existe déjà. Sinon, elle retourne 1, indiquant qu'elle n'existe pas encore.
 */
int existe_deja(UListe lst_camp,char type,char camp){
    while (lst_camp){
        if (lst_camp->type == type && lst_camp->camp == camp) {
            return 0;
        }
        lst_camp = lst_camp->vsuiv;
    }
    return 1;
}


/**
 * Colorie les cases voisines possibles en rouge si elles peuvent être occupées par une unité.
 * 
 * @param p Liste des coordonnées des cases à vérifier.
 * @param x Coordonnée x de la case d'origine.
 * @param y Coordonnée y de la case d'origine.
 * @param tableau Grille du jeu contenant les informations sur l'occupation des cases.
 * @param lst_camp Liste des unités à vérifier.
 * @return TRUE si au moins une case voisine peut être occupée, FALSE sinon.
 *
 * Cette fonction vérifie les cases voisines de la position spécifiée et les colore en rouge si elles peuvent être occupées
 * par une unité. Elle prend en compte l'occupation actuelle des cases et la liste des unités à vérifier. La fonction retourne
 * TRUE s'il existe au moins une case voisine qui peut être occupée, sinon elle retourne FALSE.
 */
int colorie_case_possible (Liste_coord p,int x,int y,Grille tableau,UListe lst_camp){
    int n =0;
    if (x+1<LONGUEUR){
        Liste_coord copie= p;
        while (copie){
            if (copie->x == x+1 && copie->y == y)  {
                if (tableau.plateau[x+1][y].occupant){
                    int t = existe_deja (tableau.plateau[x+1][y].occupant,lst_camp->type,lst_camp->camp);
                    if (t== 1){
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 

                        MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                        MLV_update_window();
                        n++;
                        break;
                    }
                }
                else{
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 

                    MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                    MLV_update_window();
                    n++;
                    break;
                }
            }
            copie= copie->suivant;
        }
    }
    if (x-1>=0){
        Liste_coord copie= p;
        while (copie){
            if (copie->x == x-1 && copie->y == y)  {
                if (tableau.plateau[x-1][y].occupant){
                    int t = existe_deja (tableau.plateau[x-1][y].occupant,lst_camp->type,lst_camp->camp);
                    if (t== 1){
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 

                    MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                    MLV_update_window();
                    n++;
                    break;
                    }
                }
                else{
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 

                    MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                    MLV_update_window();
                    n++;
                    break;
                }
            }
            copie= copie->suivant;
        }    
    }
    if (y+1<HAUTEUR){
        Liste_coord copie= p;
        while (copie){
            if (copie->x == x && copie->y== y+1)  {
                if (tableau.plateau[x][y+1].occupant){
                    int t = existe_deja (tableau.plateau[x][y+1].occupant,lst_camp->type,lst_camp->camp);
                    if (t== 1){
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                      
                        MLV_update_window();
                        n++;
                        break;
                    }
                }
                else{
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 

                    MLV_update_window();
                    n++;
                    break;
                }
            }
        copie= copie->suivant;
        }
    }
    
    if (y-1>=0){
        Liste_coord copie= p;
        while (copie){
            if (copie->x == x && copie->y == y-1)  {
                if (tableau.plateau[x][y-1].occupant){
                    int t = existe_deja (tableau.plateau[x][y-1].occupant,lst_camp->type,lst_camp->camp);
                    if (t== 1){
                     
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                        MLV_update_window();
                        n++;
                        break;
                    }
                }
                else{

                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                    MLV_update_window();
                    n++;
                    break;
                }
            }
        copie= copie->suivant;
        }    
    }


    if (x+1<LONGUEUR && y+1<HAUTEUR){
        Liste_coord copie= p;
        while (copie){
            if (copie->x == x+1 && copie->y == y+1)  {
                if (tableau.plateau[x+1][y+1].occupant){
                    int t = existe_deja (tableau.plateau[x+1][y+1].occupant,lst_camp->type,lst_camp->camp);
                    if (t== 1){
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                        MLV_update_window();
                        n++;
                        break;
                    }
                }
                else{
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                    MLV_update_window();
                    n++;
                    break;
                }
            }
            copie= copie->suivant;
        }
    }

    if (x+1<LONGUEUR && y-1<HAUTEUR){
        Liste_coord copie= p;
        while (copie){
            if (copie->x == x+1 && copie->y == y-1)  {
                if (tableau.plateau[x+1][y-1].occupant){
                    int t = existe_deja (tableau.plateau[x+1][y-1].occupant,lst_camp->type,lst_camp->camp);
                    if (t== 1){
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                        MLV_update_window();
                        n++;
                        break;
                    }
                }
                else{
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                    MLV_update_window();
                    n++;
                    break;
                }
            }
            copie= copie->suivant;
        }
    }

    if (x-1<LONGUEUR && y+1<HAUTEUR){
        Liste_coord copie= p;
        while (copie){
            if (copie->x == x-1 && copie->y == y+1)  {
                if (tableau.plateau[x-1][y+1].occupant){
                    int t = existe_deja (tableau.plateau[x-1][y+1].occupant,lst_camp->type,lst_camp->camp);
                    if (t== 1){
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                        MLV_update_window();
                        n++;
                        break;
                    }
                }
                else{
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                    MLV_update_window();
                    n++;
                    break;
                }
            }
            copie= copie->suivant;
        }
    }

    if (x-1<LONGUEUR && y-1<HAUTEUR){
        Liste_coord copie= p;
        while (copie){
            if (copie->x == x-1 && copie->y == y-1)  {
                if (tableau.plateau[x-1][y-1].occupant){
                    int t = existe_deja (tableau.plateau[x-1][y-1].occupant,lst_camp->type,lst_camp->camp);
                    if (t== 1){
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                        MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                        MLV_update_window();
                       
                        n++;
                        break;
                    }
                }
                else{
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->bas_droite.x,copie->bas_droite.y,copie->haut_droite.x,copie->haut_droite.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_gauche.x,copie->haut_gauche.y,copie->bas_gauche.x,copie->bas_gauche.y,MLV_COLOR_RED); 
                    MLV_draw_line (copie->haut_droite.x,copie->haut_droite.y,copie->haut_gauche.x,copie->haut_gauche.y,MLV_COLOR_RED); 
                    MLV_update_window();
                    n++;
                    break;
                }
            }
            copie= copie->suivant;
        }
    }

    if (n>0)return 1;
    return 0;
}


/**
 * Modifie visuellement une case spécifiée pour indiquer la présence d'une unité.
 *
 * @param suivant Un pointeur vers la structure Unite représentant l'unité.
 * @param p Liste des coordonnées de la case à modifier.
 *
 * La fonction parcourt la liste de coordonnées p et vérifie si les coordonnées correspondent
 * à la position de l'unité. Si une correspondance est trouvée, la fonction dessine un texte
 * spécifique dans la case pour représenter le type d'unité.
 */
void case_rouge(Unite*suivant,Liste_coord p){ 
    int x,y;
    int t = 0;
    Unite lst = *suivant;
    Liste_coord p_copie= p;
    while (p_copie){
        if (p_copie->x == lst.posx && p_copie->y == lst.posy){
            if (lst.type == FRELON)MLV_draw_text_box(p_copie->case_milieu_droite_haut_gauche.x, p_copie->case_milieu_droite_haut_gauche.y,p_copie->case_milieu_droite_haut_droite.x-p_copie->case_milieu_droite_haut_gauche.x,p_copie->case_milieu_droite_bas_gauche.y-p_copie->case_milieu_droite_haut_gauche.y,"f",0,MLV_COLOR_WHITE, MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type == OUVRIERE)MLV_draw_text_box(p_copie->case_milieu_gauche_haut_gauche.x,p_copie->case_milieu_gauche_haut_gauche.y,p_copie->case_milieu_gauche_haut_droite.x-p_copie->case_milieu_gauche_haut_gauche.x,p_copie->case_milieu_gauche_bas_gauche.y-p_copie->case_milieu_gauche_haut_gauche.y,"o",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type == GUERRIERE)MLV_draw_text_box(p_copie->case_bas_gauche_haut_gauche.x,p_copie->case_bas_gauche_haut_gauche.y,  p_copie->case_bas_gauche_haut_droite.x-p_copie->case_bas_gauche_haut_gauche.x, p_copie->case_bas_gauche_bas_gauche.y-p_copie->case_bas_gauche_haut_gauche.y,"g",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type == ESCADRON)MLV_draw_text_box(p_copie->case_bas_droite_haut_gauche.x,p_copie->case_bas_droite_haut_gauche.y,p_copie->case_bas_droite_haut_droite.x-p_copie->case_bas_droite_haut_gauche.x, p_copie->case_bas_droite_bas_gauche.y-p_copie->case_bas_droite_haut_gauche.y,"e",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type == RUCHE)MLV_draw_text_box(p_copie->case_milieu_milieu_haut_gauche.x,p_copie->case_milieu_milieu_haut_gauche.y,p_copie->case_milieu_milieu_haut_droite.x-p_copie->case_milieu_milieu_haut_gauche.x,p_copie->case_milieu_milieu_bas_gauche.y-p_copie->case_milieu_milieu_haut_gauche.y,"R",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type== NID)MLV_draw_text_box(p_copie->case_milieu_milieu_haut_gauche.x,p_copie->case_milieu_milieu_haut_gauche.y, p_copie->case_milieu_milieu_haut_droite.x-p_copie->case_milieu_milieu_haut_gauche.x,   p_copie->case_milieu_milieu_bas_gauche.y-p_copie->case_milieu_milieu_haut_gauche.y,"N",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type== REINE && lst.camp == FRELON)MLV_draw_text_box(p_copie->case_haut_droite_haut_gauche.x,p_copie->case_haut_droite_haut_gauche.y,p_copie->case_haut_droite_haut_droite.x-p_copie->case_haut_droite_haut_gauche.x, p_copie->case_haut_droite_bas_gauche.y-p_copie->case_haut_droite_haut_gauche.y,"RF",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type== REINE && lst.camp == ABEILLE)MLV_draw_text_box(p_copie->case_haut_gauche_haut_gauche.x,p_copie->case_haut_gauche_haut_gauche.y,p_copie->case_haut_gauche_haut_droite.x-p_copie->case_haut_gauche_haut_gauche.x, p_copie->case_haut_gauche_bas_gauche.y-p_copie->case_haut_gauche_haut_gauche.y,"RA",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        break;
        }
        p_copie=p_copie->suivant;   
    } 
}


/**
 * Effectue le déplacement d'une unité sur le plateau.
 *
 * @param tableau Un pointeur vers la structure Grille représentant le plateau de jeu.
 * @param suivant Un pointeur vers la structure Unite représentant l'unité à déplacer.
 * @param p Liste des coordonnées possibles pour le déplacement.
 *
 * La fonction parcourt la liste de coordonnées p et vérifie si les coordonnées correspondent
 * à la position de l'unité. Si une correspondance est trouvée, la fonction dessine un texte
 * spécifique dans la case pour représenter le type d'unité.
 *
 * La fonction permet également à l'utilisateur de choisir la destination de l'unité en cliquant
 * sur une case possible, en vérifiant les règles du jeu et en effectuant le déplacement.
 */
void deplacement(Grille *tableau,Unite*suivant,Liste_coord p){ 
    int x,y;
    int t = 0;
    Unite lst = *suivant;
    Liste_coord p_copie= p;
    while (p_copie){
        if (p_copie->x == lst.posx && p_copie->y == lst.posy){
            if (lst.type == FRELON)MLV_draw_text_box(p_copie->case_milieu_droite_haut_gauche.x, p_copie->case_milieu_droite_haut_gauche.y,p_copie->case_milieu_droite_haut_droite.x-p_copie->case_milieu_droite_haut_gauche.x,p_copie->case_milieu_droite_bas_gauche.y-p_copie->case_milieu_droite_haut_gauche.y,"f",0,MLV_COLOR_WHITE, MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type == OUVRIERE)MLV_draw_text_box(p_copie->case_milieu_gauche_haut_gauche.x,p_copie->case_milieu_gauche_haut_gauche.y,p_copie->case_milieu_gauche_haut_droite.x-p_copie->case_milieu_gauche_haut_gauche.x,p_copie->case_milieu_gauche_bas_gauche.y-p_copie->case_milieu_gauche_haut_gauche.y,"o",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type == GUERRIERE)MLV_draw_text_box(p_copie->case_bas_gauche_haut_gauche.x,p_copie->case_bas_gauche_haut_gauche.y,  p_copie->case_bas_gauche_haut_droite.x-p_copie->case_bas_gauche_haut_gauche.x, p_copie->case_bas_gauche_bas_gauche.y-p_copie->case_bas_gauche_haut_gauche.y,"g",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type == ESCADRON)MLV_draw_text_box(p_copie->case_bas_droite_haut_gauche.x,p_copie->case_bas_droite_haut_gauche.y,p_copie->case_bas_droite_haut_droite.x-p_copie->case_bas_droite_haut_gauche.x, p_copie->case_bas_droite_bas_gauche.y-p_copie->case_bas_droite_haut_gauche.y,"e",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type == RUCHE)MLV_draw_text_box(p_copie->case_milieu_milieu_haut_gauche.x,p_copie->case_milieu_milieu_haut_gauche.y,p_copie->case_milieu_milieu_haut_droite.x-p_copie->case_milieu_milieu_haut_gauche.x,p_copie->case_milieu_milieu_bas_gauche.y-p_copie->case_milieu_milieu_haut_gauche.y,"R",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type== NID)MLV_draw_text_box(p_copie->case_milieu_milieu_haut_gauche.x,p_copie->case_milieu_milieu_haut_gauche.y, p_copie->case_milieu_milieu_haut_droite.x-p_copie->case_milieu_milieu_haut_gauche.x,   p_copie->case_milieu_milieu_bas_gauche.y-p_copie->case_milieu_milieu_haut_gauche.y,"N",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type== REINE && lst.camp == FRELON)MLV_draw_text_box(p_copie->case_haut_droite_haut_gauche.x,p_copie->case_haut_droite_haut_gauche.y,p_copie->case_haut_droite_haut_droite.x-p_copie->case_haut_droite_haut_gauche.x, p_copie->case_haut_droite_bas_gauche.y-p_copie->case_haut_droite_haut_gauche.y,"RF",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
            if (lst.type== REINE && lst.camp == ABEILLE)MLV_draw_text_box(p_copie->case_haut_gauche_haut_gauche.x,p_copie->case_haut_gauche_haut_gauche.y,p_copie->case_haut_gauche_haut_droite.x-p_copie->case_haut_gauche_haut_gauche.x, p_copie->case_haut_gauche_bas_gauche.y-p_copie->case_haut_gauche_haut_gauche.y,"RA",0,MLV_COLOR_WHITE,MLV_COLOR_BLACK , MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        break;
        }
        p_copie=p_copie->suivant;
        
    }       
    do {
    int n = colorie_case_possible (p,suivant->posx,suivant->posy,*tableau,suivant);
    MLV_wait_mouse(&x,&y);
    Pointint point= recherche_coord(p,x,y);
    t = est_voisin(suivant->posx,suivant->posy,point.x,point.y);
    if (n==0){
        t=1;
        printf ("Deplacement impossible car vous êtes bloques\n");
    }else if (t==1){
        if ((*tableau).plateau[point.x][point.y].occupant == NULL){
            suivant->posx =point.x;
            suivant->posy =point.y;
    }else{
            int m = existe_deja ((*tableau).plateau[point.x][point.y].occupant,suivant->type,suivant->camp);
            if (m==1){
                suivant->posx =point.x;
                suivant->posy =point.y;
            }

            else { 
                printf ("Il existe deja une unite du meme type dans la case. Choisissez une nouvelle\n");
                t= 0;
            }
        }
    }
    }while (t == 0);
}


/**
 * Vérifie si une unité peut effectuer une action de récolte sans rencontrer d'opposition.
 *
 * @param tableau Un pointeur vers la structure Grille représentant le plateau de jeu.
 * @param suivant Un pointeur vers la structure Unite représentant l'unité en question.
 *
 * @return Retourne TRUE si l'unité peut effectuer une action de récolte sans rencontrer
 * d'opposition (aucune unité ennemie présente), sinon retourne FALSE.
 *
 * La fonction parcourt la liste des occupants de la case actuelle de l'unité. Si une unité
 * ennemie est présente dans la même case, la fonction retourne FALSE. Sinon, elle retourne TRUE.
 */
int avent_recolt (Grille *tableau,Unite*suivant){ 
    UListe copie = tableau->plateau[suivant->posx][suivant->posy].occupant;
    if (copie){
        while (copie){
            if (copie->camp != suivant->camp) return 0;
        copie= copie->vsuiv;
        }
    }
    return 1;
}


/**
 * Effectue la récolte de pollen par une unité sur la case actuelle, sous certaines conditions.
 *
 * @param tableau Un pointeur vers la structure Grille représentant le plateau de jeu.
 * @param suivant Un pointeur vers la structure Unite représentant l'unité en question.
 *
 * @return Retourne 1 si l'unité peut effectuer la récolte de pollen avec succès, sinon retourne 0.
 *
 * La fonction vérifie d'abord s'il n'y a pas d'unité ennemie présente sur la même case que l'unité
 * actuelle. Si une unité ennemie est présente, la fonction retourne 0, indiquant l'échec de la récolte.
 * Sinon, la fonction met à jour les propriétés de l'unité pour indiquer qu'elle effectue une récolte de pollen,
 * et retourne 1 pour indiquer le succès de l'opération.
 */
int recolt_pollen(Grille *tableau,Unite*suivant){
    UListe copie = tableau->plateau[suivant->posx][suivant->posy].occupant;
    if (copie){
        while (copie){
            if (copie->camp != suivant->camp) return 0;
        copie= copie->vsuiv;
        }
    }
    suivant->production=RECOLTE;
    suivant->temps = 4;
    return 1;
}


/**
 * Vérifie si une ruche est déjà présente sur la même case que l'unité.
 *
 * @param tableau Un pointeur vers la structure Grille représentant le plateau de jeu.
 * @param suivant Un pointeur vers la structure Unite représentant l'unité en question.
 *
 * @return Retourne 1 si aucune ruche n'est présente sur la même case, sinon retourne 0.
 *
 * La fonction parcourt la liste des colonies de la case actuelle de l'unité. Si une ruche est déjà présente,
 * la fonction retourne 0, indiquant qu'il ne peut pas y avoir plus d'une ruche sur la même case. Sinon,
 * la fonction retourne 1, indiquant qu'aucune ruche n'est présente sur la même case.
 */
int deja_ruche_case(Grille *tableau,Unite*suivant){ 
    UListe copie = tableau->plateau[suivant->posx][suivant->posy].colonie;
    if (copie){
        while (copie){
            if (copie->type == RUCHE) return 0;
        copie= copie->vsuiv;
        }
    }
    return 1;
}


/**
 * Compte le nombre total d'abeilles dans une liste d'unités.
 *
 * @param p Un pointeur vers la liste d'unités à parcourir.
 *
 * @return Retourne le nombre total d'abeilles dans la liste.
 *
 * La fonction parcourt la liste d'unités et incrémente le compteur pour chaque unité qui est
 * d'un type associé aux abeilles (OUVRIERE, ESCADRON, GUERRIERE, REINE de camp ABEILLE).
 * Elle retourne ensuite le nombre total d'abeilles dans la liste.
 */
int compte_abeille(UListe p){
    int t =0;
    if (p){
        while (p) {
            if (p->type == OUVRIERE) t++;
            if (p->type == ESCADRON) t++;
            if (p->type == GUERRIERE) t++;
            if (p->type == REINE && p->camp == ABEILLE) t++;
        p=p->vsuiv;
        }
    }
    return t;
}


/**
 * Compte le nombre total de frelons dans une liste d'unités.
 *
 * @param p Un pointeur vers la liste d'unités à parcourir.
 *
 * @return Retourne le nombre total de frelons dans la liste.
 *
 * La fonction parcourt la liste d'unités et incrémente le compteur pour chaque unité qui est
 * de type FRELON ou de type REINE du camp FRELON. Elle retourne ensuite le nombre total de frelons dans la liste.
 */
int compte_frelon(UListe p){
    int t =0;
    if (p){
        while (p) {
            if (p->type == FRELON) t++;
            if (p->type == REINE && p->camp == FRELON) t++;
        p=p->vsuiv;
        }
    }
    return t;
}


/**
 * Vérifie si une case est disponible pour l'achat d'une unité de type spécifique.
 *
 * @param p Un pointeur vers la liste d'unités présentes sur la case.
 * @param camp Le camp de l'unité que l'on souhaite acheter.
 * @param type Le type d'unité que l'on souhaite acheter.
 * @param prix Le prix d'achat de l'unité.
 *
 * @return Retourne 1 si la case est disponible pour l'achat, -1 si une unité du même type est déjà présente,
 *         et 0 si les conditions d'achat ne sont pas remplies.
 *
 * La fonction parcourt la liste d'unités présentes sur la case. Si une unité du même type est déjà présente,
 * elle retourne -1, indiquant que l'achat n'est pas possible. Sinon, elle vérifie le type d'unité, le camp,
 * et le prix d'achat pour déterminer si l'achat est possible. Elle retourne 1 si les conditions sont remplies,
 * sinon elle retourne 0.
 */
int disponible_case_achat(UListe p, char camp ,char type, int prix){
    if (p){
        while (p) {
                if (p->type == type) return -1;
            p=p->vsuiv;
            }
    if(type == OUVRIERE && COUVRIERE <= prix) return 1;
    if(type == GUERRIERE && CGUERRIERE <= prix) return 1;
    if(type == ESCADRON && CESCADRON <= prix) return 1;
    if(type == FRELON && CFRELON <= prix) return 1;
    if(type == REINE && camp==ABEILLE && CREINEA  <= prix) return 1;
    

        }
    return 0;
}


/**
 * Détermine aléatoirement quelle équipe commence le jeu.
 *
 * @return Retourne 1 si les frelons commencent, 2 si les abeilles commencent.
 *
 * La fonction affiche un écran indiquant que les abeilles commencent d'un côté
 * et que les frelons commencent de l'autre côté. Elle attend ensuite le clic de
 * l'utilisateur pour effectuer le tirage aléatoire. Si le clic se trouve du côté
 * des abeilles, la fonction retourne 2, sinon elle retourne 1.
 */
int qui_commence(){
    int tirage = (rand() % 2) + 1;
    int x,y;
    if (tirage == 1) MLV_draw_text_box(0,0,HAUTEUR,LONGUEUR,"Les abeilles commencent",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    else MLV_draw_text_box(0,0,HAUTEUR,LONGUEUR,"Les frelons commencent ",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_BLUE1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_update_window();
    MLV_wait_mouse(&x,&y);

    MLV_clear_window(MLV_COLOR_BLACK);
    if (tirage == 1) return 1;
    else return 2;
}


/**
 * Affiche le nombre de ressources disponibles pour les abeilles et les frelons.
 *
 * @param ressourcesAbeille Le nombre de ressources disponibles pour les abeilles.
 * @param ressourcesFrelon Le nombre de ressources disponibles pour les frelons.
 * @param p La liste des coordonnées des cases pour afficher les informations.
 *
 * La fonction parcourt la liste des coordonnées pour trouver les emplacements spécifiques
 * destinés à afficher le nombre de ressources pour les abeilles et les frelons. Elle utilise
 * les paramètres `ressourcesAbeille` et `ressourcesFrelon` pour afficher les informations
 * sur la fenêtre graphique à ces emplacements.
 */
void affiche_ressource(int ressourcesAbeille,int ressourcesFrelon,Liste_coord p){
    Liste_coord copie = p;
    while (copie){
        if (copie->x == LIGNES-4 && copie->y ==COLONNES-1){
            MLV_draw_text(copie->bas_droite.x,copie->bas_droite.y,"Ressourece Frelon : %d ",MLV_COLOR_AZURE1,ressourcesFrelon);
        }
        if (copie->x == 0 && copie->y ==COLONNES-1){

            MLV_draw_text(copie->bas_gauche.x,copie->bas_gauche.y,"Ressourece abeille : %d ",MLV_COLOR_AZURE1,ressourcesAbeille);
        }
        copie=copie->suivant;
    } 
}


/**
 * Affiche des informations spécifiques de la partie sur la fenêtre graphique.
 *
 * @param texte Le texte à afficher sur la fenêtre graphique.
 * @param p La liste des coordonnées des cases pour déterminer l'emplacement d'affichage.
 *
 * La fonction parcourt la liste des coordonnées pour trouver les emplacements spécifiques
 * destinés à afficher des informations sur la fenêtre graphique. Elle utilise le paramètre
 * `texte` pour afficher le texte à l'emplacement déterminé par les coordonnées trouvées.
 */
void affiche_info_partie(char texte[100] ,Liste_coord p){
    Pointint haut_droit_box;
    Pointint haut_gauche_box;
    Pointint longeur;
    
    Liste_coord p_copie = p;
    while (p_copie){
        if (p_copie->x == 5 && p_copie->y == COLONNES-1){
            haut_gauche_box.x = p_copie->bas_gauche.x;
            haut_gauche_box.y = p_copie->bas_gauche.y;
            longeur.x= p_copie->haut_gauche.x;
            longeur.y= p_copie->haut_gauche.y;
        }
        if (p_copie->x == LIGNES-5 && p_copie->y == COLONNES-1){
             haut_droit_box.x=p_copie->bas_gauche.x;
             haut_droit_box.y=p_copie->bas_gauche.y;
        }
    p_copie=p_copie->suivant;
    }
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,texte,0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_update_window();
}


/**
 * Affiche des informations sur les points de vie des deux camps sur la fenêtre graphique.
 *
 * @param pva Les points de vie des abeilles à afficher.
 * @param pvf Les points de vie des frelons à afficher.
 * @param texte Le texte à afficher sur la fenêtre graphique.
 * @param p La liste des coordonnées des cases pour déterminer l'emplacement d'affichage.
 *
 * La fonction parcourt la liste des coordonnées pour trouver les emplacements spécifiques
 * destinés à afficher des informations sur les points de vie des deux camps sur la fenêtre graphique.
 * Elle utilise les paramètres `pva` et `pvf` pour afficher les points de vie à l'emplacement déterminé
 * par les coordonnées trouvées, avec le texte spécifié.
 */
void affiche_info_point_de_vie(int pva, int pvf, char texte[100] ,Liste_coord p){
    Pointint haut_droit_box;
    Pointint haut_gauche_box;
    Pointint longeur;
    
    Liste_coord p_copie = p;
    while (p_copie){
        if (p_copie->x == 5 && p_copie->y == COLONNES-1){
            haut_gauche_box.x = p_copie->bas_gauche.x;
            haut_gauche_box.y = p_copie->bas_gauche.y;
            longeur.x= p_copie->haut_gauche.x;
            longeur.y= p_copie->haut_gauche.y;
        }
        if (p_copie->x == LIGNES-5 && p_copie->y == COLONNES-1){
             haut_droit_box.x=p_copie->bas_gauche.x;
             haut_droit_box.y=p_copie->bas_gauche.y;
        }
    p_copie=p_copie->suivant;
    }
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,texte,0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER, pva, pvf);
    MLV_wait_seconds(1);
    MLV_update_window();
}


/**
 * Affiche des informations sur la partie en attente sur la fenêtre graphique.
 *
 * @param p La liste des coordonnées des cases pour déterminer l'emplacement d'affichage.
 * @param text Le texte à afficher sur la fenêtre graphique.
 * @param t La valeur associée à la partie en attente à afficher.
 *
 * La fonction parcourt la liste des coordonnées pour trouver les emplacements spécifiques
 * destinés à afficher des informations sur la partie en attente sur la fenêtre graphique.
 * Elle utilise le texte spécifié et la valeur `t` pour afficher ces informations à l'emplacement déterminé.
 */
void affiche_info_partie_attente(Liste_coord p,char text[100],int t){
    Pointint haut_droit_box;
    Pointint haut_gauche_box;
    Pointint longeur;
    
    Liste_coord p_copie = p;
    while (p_copie){
        if (p_copie->x == 5 && p_copie->y == COLONNES-1){
            haut_gauche_box.x = p_copie->bas_gauche.x;
            haut_gauche_box.y = p_copie->bas_gauche.y;
            longeur.x= p_copie->haut_gauche.x;
            longeur.y= p_copie->haut_gauche.y;
        }
        if (p_copie->x == LIGNES-5 && p_copie->y == COLONNES-1){
             haut_droit_box.x=p_copie->bas_gauche.x;
             haut_droit_box.y=p_copie->bas_gauche.y;
        }
    p_copie=p_copie->suivant;
    }
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,text,0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,t);
    MLV_update_window();
}


/**
 * Affiche des boutons "Oui" et "Non" sur la fenêtre graphique pour une interaction utilisateur.
 *
 * @param p La liste des coordonnées des cases pour déterminer l'emplacement d'affichage.
 * @return 1 si le bouton "Oui" est cliqué, 2 si le bouton "Non" est cliqué, -1 sinon.
 *
 * La fonction affiche deux boutons "Oui" et "Non" sur la fenêtre graphique à des emplacements spécifiques déterminés
 * par la liste des coordonnées `p`. Elle attend ensuite que l'utilisateur clique sur l'un des boutons et retourne
 * une valeur en fonction du bouton cliqué.
 */
int affiche_bouton_oui_non(Liste_coord p){

    Pointint haut_droit_box;
    Pointint haut_gauche_box;
    Pointint longeur;
    
    Liste_coord p_copie = p;
    while (p_copie){
        if (p_copie->x == 5 && p_copie->y == COLONNES-1){
            haut_gauche_box.x = p_copie->bas_gauche.x;
            haut_gauche_box.y = p_copie->bas_gauche.y;
            longeur.x= p_copie->haut_gauche.x;
            longeur.y= p_copie->haut_gauche.y;
        }
        if (p_copie->x == LIGNES-5 && p_copie->y == COLONNES-1){
             haut_droit_box.x=p_copie->bas_gauche.x;
             haut_droit_box.y=p_copie->bas_gauche.y;
        }
    p_copie=p_copie->suivant;
    }
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Oui",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Non",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+((haut_gauche_box.y-longeur.y)/2)*2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Quiter",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    
    MLV_update_window();
    int x,y;
    do{
    MLV_wait_mouse(&x,&y);
    if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)<y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y) +(haut_gauche_box.y-longeur.y)/2>y) return 1;
    if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)/2>y) return 2;
    if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+((haut_gauche_box.y-longeur.y)/2)*2< y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+((haut_gauche_box.y-longeur.y)/2)*3>y) return -2;
    
    }while (x!= -1);
    return -1;
}


/**
 * Affiche des boutons d'achat pour différentes unités sur la fenêtre graphique.
 *
 * @param p La liste des coordonnées des cases pour déterminer l'emplacement d'affichage.
 * @param ReineA Le statut de la reine abeille (-2 pour non disponible, 0 pour disponible, 1 pour déjà présente).
 * @param ReineF Le statut de la reine frelon (-2 pour non disponible, 0 pour disponible, 1 pour déjà présente).
 * @param ouvriere Le statut de l'ouvrière (-1 pour non disponible, 0 pour disponible, 1 pour déjà présente).
 * @param guerriere Le statut de la guerrière (-1 pour non disponible, 0 pour disponible, 1 pour déjà présente).
 * @param escadron Le statut de l'escadron (-1 pour non disponible, 0 pour disponible, 1 pour déjà présent).
 * @param frelon Le statut du frelon (-1 pour non disponible, 0 pour disponible, 1 pour déjà présent).
 * @param ressource Le nombre de ressources disponibles pour l'achat.
 * @return Un code indiquant l'unité sélectionnée à acheter, -1 si aucune unité sélectionnée.
 *
 * La fonction affiche des boutons pour acheter différentes unités (Reine, Ouvrière, Escadron, Guerrière, Frelon)
 * sur la fenêtre graphique à des emplacements spécifiques déterminés par la liste des coordonnées `p`. Elle attend
 * ensuite que l'utilisateur clique sur l'un des boutons et retourne un code en fonction de l'unité sélectionnée
 * ou -1 si aucune unité n'est sélectionnée.
 */
int affiche_bouton_achat(Liste_coord p, int ReineA ,int ReineF, int ouvriere ,int guerriere,int escadron,int frelon,int ressource){
    Pointint haut_droit_box;
    Pointint haut_gauche_box;
    Pointint longeur;
    Liste_coord p_copie = p;
    while (p_copie){
        if (p_copie->x == 5 && p_copie->y == COLONNES-1){
            haut_gauche_box.x = p_copie->bas_gauche.x;
            haut_gauche_box.y = p_copie->bas_gauche.y;
            longeur.x= p_copie->haut_gauche.x;
            longeur.y= p_copie->haut_gauche.y;
        }
        if (p_copie->x == LIGNES-5 && p_copie->y == COLONNES-1){
             haut_droit_box.x=p_copie->bas_gauche.x;
             haut_droit_box.y=p_copie->bas_gauche.y;
        }
    p_copie=p_copie->suivant;
    }

    if (ReineA != -2){
        MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Reine %d ressourceAbeille",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,CREINEA);
        MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Ouvriere %d ressourceAbeille",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,COUVRIERE);
        MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Escadron %d ressourceAbeille",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,CESCADRON);
        MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"gueriere %d ressourceAbeille",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,CGUERRIERE);
        MLV_update_window();
        int x,y;
        do{
        MLV_wait_mouse(&x,&y);
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)<y   && haut_gauche_box.y+(haut_gauche_box.y-longeur.y) +(haut_gauche_box.y-longeur.y)/2>y){
            if (ReineA == 0 ||ReineA == 1){
                if (ressource>=CREINEA){
                    return 1;
                }else affiche_info_partie("Pas assez de ressource",p);
            }else affiche_info_partie("l'unite est deja presente",p);
        }
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)/2>y){
            if (ouvriere == 0 || ouvriere == 1){
                if (ressource>=COUVRIERE){
                    return 2;
                }else affiche_info_partie("Pas assez de ressource",p);
            }else affiche_info_partie("l'unite est deja presente",p);
        }
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)< y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)>y){
            if (escadron == 0||escadron == 1){
                if (ressource>=CESCADRON){
                    return 3;
                }else affiche_info_partie("Pas assez de ressource",p);
            }else affiche_info_partie("l'unite est deja presente",p);
        }
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)>y){
            if (guerriere == 0|| guerriere == 1){
                if (ressource>=CGUERRIERE){
                     return 4;
                }else affiche_info_partie("Pas assez de ressource",p);
            }else affiche_info_partie("l'unite est deja presente",p);
        }
        }while (x!= -1);
    }else{
        MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Reine %d ressourceFrelon",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,CREINEF);
        MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Frelon %d ressourceFrelon",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,CFRELON);
        
        MLV_update_window();
        int x,y;
        do{
        MLV_wait_mouse(&x,&y);
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)<y   && haut_gauche_box.y+(haut_gauche_box.y-longeur.y) +(haut_gauche_box.y-longeur.y)/2>y){
            if (ReineF == 0){
                if (ressource>=CREINEF){
                    return 1;
                }else affiche_info_partie("Pas assez de ressource",p);
            }else affiche_info_partie("l'unite est deja presente",p);
        }
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)/2>y){
            if (frelon== 0){
                if (ressource>=CFRELON){
                    return 2;
                }else affiche_info_partie("Pas assez de ressource",p);
            }else affiche_info_partie("l'unite est deja presente",p);
        }
        }while (x!= -1);    
    }
return-1;

}
    

/**
 * Affiche des actions possibles pour une ouvrière sur la fenêtre graphique.
 *
 * @param p La liste des coordonnées des cases pour déterminer l'emplacement d'affichage.
 * @return Un code indiquant l'action sélectionnée par l'utilisateur (1 pour "Passe le tour", 2 pour "Commence à recolter", 3 pour "Deplacement"), 0 si aucune action n'est sélectionnée.
 *
 * La fonction affiche des actions possibles pour une ouvrière (Passe le tour, Commence à recolter, Deplacement)
 * sur la fenêtre graphique à des emplacements spécifiques déterminés par la liste des coordonnées `p`.
 * Elle attend ensuite que l'utilisateur clique sur l'une des actions et retourne un code en fonction de
 * l'action sélectionnée ou 0 si aucune action n'est sélectionnée.
 */    
int affiche_action_ouvriere(Liste_coord p){
    Pointint haut_droit_box;
    Pointint haut_gauche_box;
    Pointint longeur;
    Liste_coord p_copie = p;
    while (p_copie){
        if (p_copie->x == 5 && p_copie->y == COLONNES-1){
            haut_gauche_box.x = p_copie->bas_gauche.x;
            haut_gauche_box.y = p_copie->bas_gauche.y;
            longeur.x= p_copie->haut_gauche.x;
            longeur.y= p_copie->haut_gauche.y;
        }
        if (p_copie->x == LIGNES-5 && p_copie->y == COLONNES-1){
             haut_droit_box.x=p_copie->bas_gauche.x;
             haut_droit_box.y=p_copie->bas_gauche.y;
        }
    p_copie=p_copie->suivant;
    }
    
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Commencer a recolter",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Passer le tour",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Deplacement",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Quitter",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    
    
    MLV_update_window();
    int x,y;
    do{
        MLV_wait_mouse(&x,&y);
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)<y   && haut_gauche_box.y+(haut_gauche_box.y-longeur.y) +(haut_gauche_box.y-longeur.y)/2>y)return 2;
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)/2>y)return 1;
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)< y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)>y)return 3;
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2>y)return -2;
    }while (x!= -1);
return 0;
}


/**
 * Affiche des boutons pour les actions "Deplacement" et "Passer le tour" sur la fenêtre graphique.
 *
 * @param p La liste des coordonnées des cases pour déterminer l'emplacement d'affichage.
 * @return Un code indiquant l'action sélectionnée par l'utilisateur (1 pour "Deplacement", 2 pour "Passer le tour"), -1 si aucune action n'est sélectionnée.
 *
 * La fonction affiche des boutons pour les actions "Deplacement" et "Passer le tour" sur la fenêtre graphique
 * à des emplacements spécifiques déterminés par la liste des coordonnées `p`. Elle attend ensuite que l'utilisateur
 * clique sur l'un des boutons et retourne un code en fonction de l'action sélectionnée ou -1 si aucune action n'est sélectionnée.
 */
int affiche_bouton_deplacement_passer(Liste_coord p){

    Pointint haut_droit_box;
    Pointint haut_gauche_box;
    Pointint longeur;
    Liste_coord p_copie = p;
    while (p_copie){
        if (p_copie->x == 5 && p_copie->y == COLONNES-1){
            haut_gauche_box.x = p_copie->bas_gauche.x;
            haut_gauche_box.y = p_copie->bas_gauche.y;
            longeur.x= p_copie->haut_gauche.x;
            longeur.y= p_copie->haut_gauche.y;
        }
        if (p_copie->x == LIGNES-5 && p_copie->y == COLONNES-1){
             haut_droit_box.x=p_copie->bas_gauche.x;
             haut_droit_box.y=p_copie->bas_gauche.y;
        }
    p_copie=p_copie->suivant;
    }
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Deplacement",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Passer le tour",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Quiter",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    
    MLV_update_window();
    int x,y;
    do{
    MLV_wait_mouse(&x,&y);
    if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)<y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y) +(haut_gauche_box.y-longeur.y)/2>y) return 1;
    if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)/2>y) return 2;
    if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+((haut_gauche_box.y-longeur.y)/2)*2+(haut_gauche_box.y-longeur.y)/2>y) return -2;
    }while (x!= -1);
    return -1;
}


/**
 * Affiche des options d'action pour une Reine sur la fenêtre graphique.
 *
 * @param p La liste des coordonnées des cases pour déterminer l'emplacement d'affichage.
 * @param camp Le camp de la Reine (ABEILLE ou FRELON).
 * @return Un code indiquant l'action sélectionnée par l'utilisateur (1 pour "Déplacement", 2 pour "Créer une Ruche/Nid", 3 pour "Passer le tour"), 0 si aucune action n'est sélectionnée.
 *
 * La fonction affiche des options d'action pour une Reine sur la fenêtre graphique
 * à des emplacements spécifiques déterminés par la liste des coordonnées `p`. Elle attend ensuite que l'utilisateur
 * clique sur l'une des options et retourne un code en fonction de l'action sélectionnée ou 0 si aucune action n'est sélectionnée.
 * La possibilité de créer une Ruche ou un Nid dépend du camp de la Reine.
 */
int affiche_action_Reine(Liste_coord p,char camp){
    Pointint haut_droit_box;
    Pointint haut_gauche_box;
    Pointint longeur;
    Liste_coord p_copie = p;
    while (p_copie){
        if (p_copie->x == 5 && p_copie->y == COLONNES-1){
            haut_gauche_box.x = p_copie->bas_gauche.x;
            haut_gauche_box.y = p_copie->bas_gauche.y;
            longeur.x= p_copie->haut_gauche.x;
            longeur.y= p_copie->haut_gauche.y;
        }
        if (p_copie->x == LIGNES-5 && p_copie->y == COLONNES-1){
             haut_droit_box.x=p_copie->bas_gauche.x;
             haut_droit_box.y=p_copie->bas_gauche.y;
        }
    p_copie=p_copie->suivant;
    }
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Déplacement",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    if (camp == ABEILLE) MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Créer une Ruche",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    else MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2,haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Créer un Nid",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(haut_gauche_box.x,haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y),haut_droit_box.x-haut_gauche_box.x, (haut_gauche_box.y-longeur.y)/2,"Passer le tour",0, MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_update_window();
    int x,y;
    do{
        MLV_wait_mouse(&x,&y);
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)<y   && haut_gauche_box.y+(haut_gauche_box.y-longeur.y) +(haut_gauche_box.y-longeur.y)/2>y)return 3;
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&  haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2< y &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)/2>y)return 2;
        if (haut_gauche_box.x<x && haut_gauche_box.x+haut_droit_box.x-haut_gauche_box.x>x &&   haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)< y && haut_gauche_box.y+(haut_gauche_box.y-longeur.y)+(haut_gauche_box.y-longeur.y)/2+(haut_gauche_box.y-longeur.y)>y)return 1;
    }while (x!= -1);
return 0;
}



int verification_fichier(FILE * fichier, char * nom){
    fichier = fopen(nom,"r+");
    if (fichier) return 0;
    else { 
        fichier = fopen(nom,"w"); 
        return -1;
    }
}

void gagnant(int t){
    int tirage = (rand() % 2) + 1;
    int x,y;
    if (t == 6) MLV_draw_text_box(0,0,HAUTEUR,LONGUEUR,"Les abeilles ont gagnés",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    if (t == 5) MLV_draw_text_box(0,0,HAUTEUR,LONGUEUR,"Les frelons ont gagnés",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_BLUE1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    if (t == -2) MLV_draw_text_box(0,0,HAUTEUR,LONGUEUR,"Vous avez quitté la partie",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    if (t == -5) MLV_draw_text_box(0,0,HAUTEUR,LONGUEUR,"Va acheter du stockage !",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_ORANGE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_update_window();
    MLV_wait_mouse(&x,&y);

    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_wait_seconds(1);
}

void sauvegarde(Grille plateau, char doitjouer[1], char * nom){
    FILE *fichier = fopen(nom, "w");
    
    
    if (doitjouer[0] == 'A') fprintf(fichier,"%s %d %d\n",doitjouer, plateau.ressourcesAbeille, plateau.ressourcesFrelon);
    else fprintf(fichier,"%s %d %d\n",doitjouer, plateau.ressourcesFrelon, plateau.ressourcesAbeille);
    
    
    for (UListe ruches = plateau.abeille ;ruches; ruches = ruches->colsuiv) {
        for (UListe unites = ruches; unites; unites = unites->usuiv){
            fprintf(fichier,"%c %c %d %d %c %d %d %d %d\n",
            unites->camp, unites->type, unites->posx, unites->posy, unites->production, 
            unites->toursrestant, unites->prod_en_cours, unites->point_de_vie, unites->peut_jouer);
        }
    }

    for (UListe nids = plateau.frelon;nids; nids = nids->colsuiv) {
        for (UListe unites = nids; unites; unites = unites->usuiv){
            fprintf(fichier,"%c %c %d %d %c %d %d %d %d\n",
            unites->camp, unites->type, unites->posx, unites->posy, unites->production, 
            unites->toursrestant, unites->prod_en_cours, unites->point_de_vie, unites->peut_jouer);
        }
    }
    

    
    
    fclose(fichier);
}

void lecture(FILE * fichier, Grille *plateau, char * nom){
    char joueur;
    int ressourcesAbeille;
    int ressourceFrelon;
    fichier = fopen(nom,"r+");
    fscanf(fichier,"%c %d %d\n",&joueur,&ressourcesAbeille,&ressourceFrelon);
    
    plateau->ressourcesAbeille = ressourcesAbeille;
    plateau->ressourcesFrelon = ressourceFrelon;

    
    char camp; char type; int posx; int posy; char production; int toursrestant; int prod_en_cours; int point_de_vie; int peut_jouer;
    while (fscanf(fichier,"%c %c %d %d %c %d %d %d %d\n",&camp,&type,&posx,&posy,&production,&toursrestant,&prod_en_cours,&point_de_vie,&peut_jouer) != EOF){
        printf("%c %c %d %d %c %d %d %d %d\n",camp,type,posx,posy,production,toursrestant,prod_en_cours,point_de_vie,peut_jouer);
        if (type == RUCHE){
           if (!(plateau->abeille)){
                UListe ruche = Ajout_Maison(posx,posy,&(plateau)->abeille,type);
                ruche->toursrestant = toursrestant;
                fprintf(stderr,"première ruche\n");
            }
            else {
                fprintf(stderr,"pas première ruche\n");
                UListe ruche = Ajout_Maison(posx,posy,&(plateau)->abeille->colsuiv,type);
                ruche->toursrestant = toursrestant;
            }
              
        }
        if (type == NID){
            if (!(plateau->frelon)){
                fprintf(stderr,"premier nid\n");
                UListe ruche = Ajout_Maison(posx,posy,&(plateau)->frelon,type);
                ruche->toursrestant = toursrestant;
            }
            else {
                fprintf(stderr,"pas premier nid\n");
                UListe ruche = Ajout_Maison(posx,posy,&(plateau)->frelon->colsuiv,type);
                ruche->toursrestant = toursrestant;
            }
        }
        

        else {
            if (camp==ABEILLE) {
                UListe itercol = plateau->abeille;
                for (;itercol->colsuiv; itercol = itercol->colsuiv);
                UListe unite = Creation_Unite(posx,posy,&itercol->usuiv,type,camp); 
                unite->production = production;
                unite->toursrestant = toursrestant;
                unite->prod_en_cours = prod_en_cours;
                unite->point_de_vie = point_de_vie;
                unite->peut_jouer = peut_jouer;
            }
            else { 
                UListe itercolf = plateau->frelon;
                for (;itercolf->colsuiv; itercolf = itercolf->colsuiv);
                UListe unite = Creation_Unite(posx,posy,&itercolf->usuiv,type,camp); 
                unite->production = production;
                unite->toursrestant = toursrestant;
                unite->prod_en_cours = prod_en_cours;
                unite->point_de_vie = point_de_vie;
                unite->peut_jouer = peut_jouer;
            }
        }
    } 
    fclose(fichier); 
}




int gameplay_abeille(Liste_coord p,Grille *jeux, char * nom){
    UListe copi_abeille = (*jeux).abeille;
            sauvegarde((*jeux),"A",nom);
            while (copi_abeille){
                int accept;
                affiche_info_partie("tour des abeille",p);
                if (copi_abeille->peut_jouer == 0){
                if ((*jeux).ressourcesAbeille>=COUVRIERE){
                    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                    int nbr = compte_abeille((*jeux).plateau[copi_abeille->posx][copi_abeille->posy].occupant);
                    case_rouge(copi_abeille,p);

                    if (nbr == 4) {
                        affiche_info_partie("Toute les case de la case sont occupe pas d'achat pour vous",p); 
                        MLV_wait_seconds(2);
                    }
                    else{
                        affiche_info_partie("Voulez vous acheter une nouvelle unite pour cette ruche ? ",p);
                        accept = affiche_bouton_oui_non(p);
                        if (accept == -2) return -2;
                        if (accept == 1){

                            int ouvriere = disponible_case_achat((*jeux).plateau[copi_abeille->posx][copi_abeille->posy].occupant,ABEILLE,OUVRIERE,(*jeux).ressourcesAbeille);
                            int reine = disponible_case_achat((*jeux).plateau[copi_abeille->posx][copi_abeille->posy].occupant,ABEILLE,REINE,(*jeux).ressourcesAbeille);
                            int escadron = disponible_case_achat((*jeux).plateau[copi_abeille->posx][copi_abeille->posy].occupant,ABEILLE,ESCADRON,(*jeux).ressourcesAbeille);
                            int guerriere = disponible_case_achat((*jeux).plateau[copi_abeille->posx][copi_abeille->posy].occupant,ABEILLE,GUERRIERE,(*jeux).ressourcesAbeille);
                            int veri = affiche_bouton_achat(p, reine ,-2,ouvriere ,guerriere, escadron,-2,(*jeux).ressourcesAbeille);
                            if (veri == 1){
                                Creation_Unite(copi_abeille->posx, copi_abeille->posy, &(copi_abeille->usuiv),REINE,ABEILLE);
                                (*jeux).ressourcesAbeille-= CREINEA;
                            }if (veri == 2){
                                Creation_Unite(copi_abeille->posx, copi_abeille->posy, &(copi_abeille->usuiv),OUVRIERE,ABEILLE);
                                (*jeux).ressourcesAbeille-= COUVRIERE;
                            }if (veri == 3){
                                Creation_Unite(copi_abeille->posx, copi_abeille->posy, &(copi_abeille->usuiv),ESCADRON,ABEILLE);
                                (*jeux).ressourcesAbeille-= CESCADRON;
                            }if (veri == 4){
                                Creation_Unite(copi_abeille->posx, copi_abeille->posy, &(copi_abeille->usuiv),GUERRIERE,ABEILLE);
                                (*jeux).ressourcesAbeille-= CGUERRIERE;
                            }
                        }

                    MLV_clear_window(MLV_COLOR_BLACK);
                    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                    affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                    MLV_update_window();
                    }

                } else {
                    affiche_info_partie("Vous avez pas assez de ressource pour achete des unite\n",p);
                }
                if (copi_abeille->usuiv){   
                    UListe copie = copi_abeille->usuiv;
                    while (copie){
                if (copie->toursrestant == 0){
                    if (copie->type == OUVRIERE){
                        affiche_info_partie_attente(p,"Ouvriere point de vie : %d",copie->point_de_vie);
                        case_rouge(copie,p);
                        if (copie->production == PASRECOLTE){
                            int action = affiche_action_ouvriere(p);
                            if (action == -2)return-2;
                            if (action == 2){
                                affiche_info_partie("L'abeille a commencait a recolte du pollen",p);
                                copie->production=RECOLTE;
                                copie->prod_en_cours= 4;
                                MLV_wait_seconds(2);
                            }
                            else if (action == 3){
                                deplacement(&(*jeux),copie,p);
                                MLV_clear_window(MLV_COLOR_BLACK);
                                affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                MLV_update_window();
                            }
                            else affiche_info_partie("On passe le tour de l'unite",p);
                        }else{
                            copie->prod_en_cours--;
                            (*jeux).ressourcesAbeille++;
                            if (copie->prod_en_cours == 0){
                                affiche_info_partie("l'ouvriere part a la retraite\n",p);
                                efface_unite(&copi_abeille->usuiv,copie);
                            }
                            else affiche_info_partie("Il reste tour",p);  

                            
                        }  
                        copie=copie->usuiv; 
                    }
                    else if (copie->type == REINE){
                
                        MLV_clear_window(MLV_COLOR_BLACK);
                        affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                        complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                        affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                        affiche_info_partie_attente(p,"Tour de la reine | PV  : %d",copie->point_de_vie);
                        case_rouge(copie,p);
                        MLV_update_window();
                        

                        

                        if (copie->cree_ruche == 1  || (*jeux).plateau[copie->posx][copie->posy].colonie){
                            affiche_info_partie_attente(p,"Tour de la reine | PV : %d",copie->point_de_vie);
                            MLV_update_window();
                            int action = affiche_bouton_deplacement_passer(p);
                            if (action == -2)return -2;
            
                            
                            if (action==1){
                                deplacement(&(*jeux),copie,p);
                                MLV_clear_window(MLV_COLOR_BLACK);
                                affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                MLV_update_window();
                                copie=copie->usuiv;
                            }else{
                                copie=copie->usuiv;
                                MLV_clear_window(MLV_COLOR_BLACK);
                                affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                MLV_update_window();
                                
                                }

                        
                        }else{
                            
                            int action = affiche_action_Reine(p,ABEILLE);
                            if (action == 1)copie=copie->usuiv;
                            if (action == 2){
                                (*jeux).ressourcesAbeille-=10;
                                UListe suiv= copie->usuiv;
                                
                                Ajout_Maison(copie->posx,copie->posy,&((*jeux).abeille), RUCHE);
                                efface_unite(&copi_abeille->usuiv,copie);

                                
                                UListe rechercher = (*jeux).abeille;
                                while (rechercher->colsuiv == NULL){
                                    rechercher= rechercher->colsuiv;
    
                                }
                                rechercher= rechercher->colsuiv;
                                (*rechercher).peut_jouer =1;

                                Creation_Unite_debut(rechercher->posx,rechercher->posy,&(*rechercher).usuiv,REINE,ABEILLE);
                                rechercher->usuiv->cree_ruche=1;
                    
                
                                copie=suiv;
                                MLV_clear_window(MLV_COLOR_BLACK);
                                affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                MLV_update_window();
                            }
                            if (action == 3){
                                deplacement(&(*jeux),copie,p);
                                MLV_clear_window(MLV_COLOR_BLACK);
                                affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                MLV_update_window();
                                copie=copie->usuiv;
                            }
                        }
                    }
                    else{
                        affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                        complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                        affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                        case_rouge(copie,p);
                        if (copie->type == REINE) affiche_info_partie_attente(p,"Reine | PV : %d",copie->point_de_vie);
                        if (copie->type == OUVRIERE) affiche_info_partie_attente(p,"Ouvriere | PV : %d",copie->point_de_vie);
                        if (copie->type == ESCADRON) affiche_info_partie_attente(p,"Escadron | PV : %d",copie->point_de_vie);
                        if (copie->type == GUERRIERE)  affiche_info_partie_attente(p,"Guerriere | PV : %d",copie->point_de_vie);
                        int action = affiche_bouton_deplacement_passer(p);
                        if (action == -2)return -2;
                        
                        if (action == 1){    
                            deplacement(&(*jeux),copie,p);
                            MLV_clear_window(MLV_COLOR_BLACK);
                            affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                            complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                            affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                            MLV_update_window();
                        }
                        copie=copie->usuiv;
                    }
                } else{
                    copie->toursrestant += -1;
                    affiche_info_partie_attente(p,"Il reste %d tour avent d'utilise l'unite",copie->toursrestant);
                    case_rouge(copie,p);
                    MLV_update_window();
                    MLV_wait_seconds(3);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                    affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                    MLV_update_window();
                    copie=copie->usuiv;
                    
                }
                }

                    MLV_clear_window(MLV_COLOR_BLACK);
                    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                    affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                    MLV_update_window();
                }
                }
                else{
                    MLV_clear_window(MLV_COLOR_BLACK);
                    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                    affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                    affiche_info_partie("cette ruche sera dispo au prochain tour",p);
                    case_rouge(copi_abeille,p);
                    copi_abeille->peut_jouer =0;
                    MLV_update_window();
                    MLV_wait_seconds(2);
                }
            copi_abeille =copi_abeille->colsuiv;
            }
    return 0;

}

int gameplay_frelon(Liste_coord p,Grille *jeux, char * nom){
    UListe copi_frelon = (*jeux).frelon;
    while (copi_frelon){
                int accept;
                affiche_info_partie("Tour des frelons",p);
                if (copi_frelon->peut_jouer == 0){
                    if ((*jeux).ressourcesAbeille>=CFRELON){
                        complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);

                        int nbr = compte_frelon((*jeux).plateau[copi_frelon->posx][copi_frelon->posy].occupant);
                        case_rouge(copi_frelon,p);

                        if (nbr == 2) affiche_info_partie("Toutes les cases de la cases sont occupées, pas d'achat pour vous",p); 
                        else{
                            affiche_info_partie("Voulez vous acheter une nouvelle unité pour ce Nid ?",p);

                            accept = affiche_bouton_oui_non(p);
                            if (accept == -2) return -2;
                            if (accept == 1){
                                int reine = disponible_case_achat((*jeux).plateau[copi_frelon->posx][copi_frelon->posy].occupant,FRELON,REINE,(*jeux).ressourcesFrelon);
                                int frelon = disponible_case_achat((*jeux).plateau[copi_frelon->posx][copi_frelon->posy].occupant,FRELON,FRELON,(*jeux).ressourcesFrelon);
                                int veri = affiche_bouton_achat(p, -2 ,reine,-2 ,-2, -2,frelon,(*jeux).ressourcesAbeille);
                                if (veri == 1){
                                    Creation_Unite(copi_frelon->posx, copi_frelon->posy, &(copi_frelon->usuiv),REINE,FRELON);
                                    (*jeux).ressourcesFrelon-= CREINEF;
                                }if (veri == 2){
                                    Creation_Unite(copi_frelon->posx, copi_frelon->posy, &(copi_frelon->usuiv),FRELON,FRELON);
                                    (*jeux).ressourcesFrelon-= CFRELON;
                                }
                            }
                            MLV_clear_window(MLV_COLOR_BLACK);
                            affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                            complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                            affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                            MLV_update_window();
                        }
                    } else {
                        affiche_info_partie("Vous avez pas assez de ressource pour achete des unite\n",p);
                        MLV_wait_seconds(2);
                    }
                        
                    if (copi_frelon->usuiv){   
                        UListe copie = copi_frelon->usuiv;
                        while (copie){
                            if (copie->toursrestant == 0){

                                if (copie->type == REINE){
                            
                                    MLV_clear_window(MLV_COLOR_BLACK);
                                    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                    affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                    affiche_info_partie_attente(p,"Reine Frelon point de vie : %d",copie->point_de_vie);
                                    case_rouge(copie,p);
                                    MLV_update_window();
                                    

                                    

                                    if (copie->cree_ruche == 1  || (*jeux).plateau[copie->posx][copie->posy].colonie){
                                        affiche_info_partie_attente(p,"Reine Frelon point de vie : %d",copie->point_de_vie);
                                        MLV_update_window();
                                        int action = affiche_bouton_deplacement_passer(p);
                                        if (action == -2)return -2;

                                        
                                        if (action==1){
                                            deplacement(&(*jeux),copie,p);
                                            MLV_clear_window(MLV_COLOR_BLACK);
                                            affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                            complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                            affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                            MLV_update_window();
                                            copie=copie->usuiv;

                                        } else {
                                            copie=copie->usuiv;
                                            MLV_clear_window(MLV_COLOR_BLACK);
                                            affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                            complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                            affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                            MLV_update_window();
                                            
                                        }

                                    
                                    } else {
                                        
                                        int action = affiche_action_Reine(p,FRELON);
                                        if (action == 1){
                                            deplacement(&(*jeux),copie,p);
                                            MLV_clear_window(MLV_COLOR_BLACK);
                                            affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                            complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                            affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                            MLV_update_window();
                                            copie=copie->usuiv;
                                        }

                                        if (action == 2){

                                            (*jeux).ressourcesFrelon-=10;
                                            UListe suiv= copie->usuiv;
                                            
                                            Ajout_Maison(copie->posx,copie->posy,&((*jeux).frelon), NID);
                                            efface_unite(&copi_frelon->usuiv,copie);

                                            
                                            UListe rechercher = (*jeux).frelon;
                                            while (rechercher->colsuiv == NULL){
                                                rechercher= rechercher->colsuiv;

                                            }
                                            rechercher= rechercher->colsuiv;
                                            (*rechercher).peut_jouer =1;

                                            Creation_Unite_debut(rechercher->posx,rechercher->posy,&(*rechercher).usuiv,REINE,FRELON);
                                            rechercher->usuiv->cree_ruche = 1;
                                
                            
                                            copie=suiv;
                                            MLV_clear_window(MLV_COLOR_BLACK);
                                            affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                            complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                            affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                            MLV_update_window();
                                        }
                                        if (action == 3) copie=copie->usuiv;
                                        
                                    }
                                } else{

                                    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                    affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                    case_rouge(copie,p);
                                    if (copie->type == FRELON) affiche_info_partie_attente(p,"Frelon PV : %d",copie->point_de_vie);
                                    int action = affiche_bouton_deplacement_passer(p);
                                    if (action == -2)return -2;
                                    
                                    if (action == 1){
                                        deplacement(&(*jeux),copie,p);
                                        MLV_clear_window(MLV_COLOR_BLACK);
                                        affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                        complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                        affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                        MLV_update_window();
                                    }
                                    copie=copie->usuiv;
                                }
                            } else {
                                copie->toursrestant -= 1;
                                affiche_info_partie_attente(p,"Il reste %d tours avant d'utilise l'unité",copie->toursrestant);
                                case_rouge(copie,p);
                                MLV_update_window();
                                MLV_wait_seconds(3);
                                MLV_clear_window(MLV_COLOR_BLACK);
                                affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                                complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                                affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                                MLV_update_window();
                                copie=copie->usuiv;
                                
                            }
                        }

                        MLV_clear_window(MLV_COLOR_BLACK);
                        affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                        complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                        affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                        MLV_update_window();
                    }
                } else{
                    MLV_clear_window(MLV_COLOR_BLACK);
                    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
                    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                    affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
                    affiche_info_partie("Cette ruche sera disponible au prochain tour",p);
                    case_rouge(copi_frelon,p);
                    copi_frelon->peut_jouer =0;
                    MLV_update_window();
                    MLV_wait_seconds(2);
                }
                copi_frelon =copi_frelon->colsuiv;
            }

return 0;
}


int gameplay_combat(Liste_coord p,Grille*jeux, char * nom){
    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
    for (int i = 0; i<LIGNES; i++){
        for (int j = 0; j<COLONNES; j++){

            if (compte_abeille((*jeux).plateau[i][j].occupant) > 0 && compte_frelon((*jeux).plateau[i][j].occupant) > 0){ //si unité contre unité
                affiche_info_partie("Debut d'un combat",p);
                MLV_wait_seconds(2);
                while (compte_abeille((*jeux).plateau[i][j].occupant) > 0 && compte_frelon((*jeux).plateau[i][j].occupant) > 0){

                        UListe combattanta = ((*jeux).plateau[i][j]).occupant;
                        UListe iter = combattanta;
                        if (combattanta->camp == FRELON){
                            while (combattanta->camp == FRELON){
                                combattanta = combattanta->vsuiv;
                            }
                        }
                        while (iter){
                            if (combattanta->force < iter->force && combattanta->camp == iter->camp){
                                combattanta = iter;
                            }
                            iter = iter->vsuiv;
                        }
                        


                        UListe combattantf = ((*jeux).plateau[i][j]).occupant;
                        UListe iter2 = combattantf;
                        if (combattantf->camp == ABEILLE){
                            while (combattantf->camp == ABEILLE){
                                combattantf = combattantf->vsuiv;
                            }
                        }
                        while (iter){
                            if (combattantf->force < iter2->force && combattantf->camp == iter->camp){
                                combattantf = iter2;
                            }
                            iter2 = iter2->vsuiv;
                        }
                        

                        fprintf(stderr,"%c vs %c\n",combattanta->type,combattantf->type);
                        int dea = -1;
                        int def = -1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
                        do{
                            dea = ((rand() % 60) * combattanta->force) % 60;
                            def = ((rand() % 60) * combattantf->force) % 60;
                            printf("déa : %d déf : %d\n",dea,def);
                            if (dea > def)combattantf->point_de_vie -= combattanta->force;
                            if (dea < def)combattanta->point_de_vie -= combattantf->force;
                        } while (dea == def);
                        dea = -1; def = -1;

                        printf("Point de vie abeille : %d Point de vie frelon : %d\n", combattanta->point_de_vie, combattantf->point_de_vie);
                        case_rouge(combattanta,p);
                        case_rouge(combattantf,p);
                        
                        affiche_info_point_de_vie(combattanta->point_de_vie, combattantf->point_de_vie, "Point de vie abeille : %d Point de vie frelon : %d",p);
                        MLV_update_window();
                        MLV_wait_seconds(2);

                        if (combattanta->point_de_vie <= 0){
                            if (combattanta->type == REINE)(*jeux).ressourcesFrelon += 7;
                            else if (combattanta->type == OUVRIERE)(*jeux).ressourcesFrelon += 3;
                            else if (combattanta->type == GUERRIERE)(*jeux).ressourcesFrelon += 5;
                            else (*jeux).ressourcesFrelon += 6;
                            UListe iterj = (*jeux).abeille;
                            int retiré = 0;
                            while (iterj && retiré == 0){
                                if (iterj->usuiv){
                                    UListe iterU = iterj;
                                    while (iterU && retiré == 0){
                                        if (iterU == combattanta){
                                            efface_unite(&iterj,iterU);
                                            retiré = 1;
                                        }
                                        if (iterU)
                                        iterU = iterU->usuiv;
                                    }
                                }
                                iterj = iterj->colsuiv;
                            }
                        }
                        else if (combattantf->point_de_vie <= 0){
                            Unite * iterj2 = (*jeux).frelon;
                            int retiré2 = 0;
                            while (iterj2 && retiré2 == 0){
                                if (iterj2){
                                    UListe iterU2 = iterj2;
                                    while (iterU2 && retiré2 == 0){
                                        if (iterU2 == combattantf){
                                            efface_unite(&iterj2,iterU2);
                                            retiré2 = 1;
                                        }
                                        if (iterU2)
                                        iterU2 = iterU2->usuiv;
                                    }
                                }
                                iterj2 = &(*iterj2->colsuiv);
                            }
                        }
                        MLV_wait_seconds(2);
                        complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
                    
                }
                affiche_info_partie("Fin d'un combat",p);
                MLV_wait_seconds(2);
            }
            
            
            if ((*jeux).plateau[i][j].colonie){ //si ruche/nid contre unité
                UListe structure = (*jeux).plateau[i][j].colonie;
                if (compte_abeille((*jeux).plateau[i][j].occupant) > 0 || compte_frelon((*jeux).plateau[i][j].occupant) > 0){

                    if (structure->camp == ABEILLE && compte_frelon((*jeux).plateau[i][j].occupant) > 0) {
                        efface_Maison(&(*jeux).abeille,structure);
                        fprintf(stderr,"Ruche détruite !!\n");
                        Ajout_Maison(i,j,&(*jeux).frelon,NID);
                        
                        UListe rechercher = (*jeux).frelon;
                        while (rechercher->colsuiv == NULL){
                            rechercher= rechercher->colsuiv;

                        }
                        rechercher= rechercher->colsuiv;
                        (*rechercher).peut_jouer =1;

                        UListe best_unite = (*jeux).plateau[i][j].occupant;
                        for (UListe unite = rechercher->usuiv; unite; unite = unite->usuiv){
                            if (unite->force > best_unite->force) best_unite = unite;
                        }
                        Creation_Unite_debut(rechercher->posx,rechercher->posy,&(*rechercher).usuiv,best_unite->type,FRELON);
            
        
                    }
                    else if (structure->camp == FRELON && compte_abeille((*jeux).plateau[i][j].occupant) > 0){
                        efface_Maison(&(*jeux).frelon,structure);
                        fprintf(stderr,"Nid détruit !!\n");
                    }
                }
            }
        }  
    }  
    
    sauvegarde((*jeux),"A",nom);
    MLV_clear_window(MLV_COLOR_BLACK);
    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
    complete_case((*jeux).abeille, (*jeux).frelon, &(*jeux), p);
    affiche_ressource((*jeux).ressourcesAbeille,(*jeux).ressourcesFrelon,p);
    MLV_update_window(); 
    
    return 0;
}

int jeux_complet (Liste_coord p,Grille *jeu,FILE * fichier, char * nom){
    int joueur =qui_commence();
    int m = 0;
    debut_jeux(&(*jeu),p);
    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
    affiche_ressource((*jeu).ressourcesAbeille,(*jeu).ressourcesFrelon,p);
    affiche_info_partie("Bonjour",p);
        MLV_update_window();
    if (joueur%2 != 0) sauvegarde((*jeu),"A",nom);
    else sauvegarde((*jeu),"F",nom);

    do{
        if (joueur%2!=0){

            int fin = gameplay_abeille(p,&(*jeu),nom);
            if (fin  == -2) return -2;
            int fin1 = gameplay_frelon(p,&(*jeu),nom);
            if (fin1  == -2) return -2;
            sauvegarde((*jeu),"A",nom);
            gameplay_combat(p,&(*jeu),nom);
        }  
        else{

            int fin = gameplay_frelon(p,&(*jeu),nom);
            if (fin  == -2) return -2;
            int fin1 = gameplay_abeille(p,&(*jeu),nom);
            if (fin1  == -2) return -2;
            sauvegarde((*jeu),"B",nom);
            gameplay_combat(p,&(*jeu),nom);

        }

            
        MLV_clear_window(MLV_COLOR_BLACK);
        affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
        complete_case((*jeu).abeille, (*jeu).frelon, &(*jeu), p);
        affiche_ressource((*jeu).ressourcesAbeille,(*jeu).ressourcesFrelon,p);
        MLV_update_window(); 
        
            
        sauvegarde((*jeu),"A",nom);
        if ((*jeu).abeille == NULL)return 5;
        if ((*jeu).frelon == NULL)return 6;
        if (joueur  == 0)return -1;
    } while (m == 0);
    MLV_wait_seconds(40);
    MLV_free_window();
    fclose(fichier);
    return 0;
}


/**
 * Détermine aléatoirement quelle équipe commence le jeu.
 *
 * @return Retourne 1 si les frelons commencent, 2 si les abeilles commencent.
 *
 * La fonction affiche un écran indiquant que les abeilles commencent d'un côté
 * et que les frelons commencent de l'autre côté. Elle attend ensuite le clic de
 * l'utilisateur pour effectuer le tirage aléatoire. Si le clic se trouve du côté
 * des abeilles, la fonction retourne 2, sinon elle retourne 1.
 */
int presentation_sauvegarde(){
    int x,y;
    MLV_draw_text_box(0,0,HAUTEUR,LONGUEUR/3,"ABEILLES VS FRELONS",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(HAUTEUR/14,LONGUEUR/3,(HAUTEUR/14)*12,(LONGUEUR-(LONGUEUR/3))/3,"Nouvelle partie (elle suprime l'ancienne sauvegarde)",0,MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_PURPLE1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(HAUTEUR/14,LONGUEUR/3+(LONGUEUR-(LONGUEUR/3))/3,(HAUTEUR/14)*12,(LONGUEUR-(LONGUEUR/3))/3,"Charger sauvegarde ",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_ORANGE1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(HAUTEUR/14,LONGUEUR/3+((LONGUEUR-(LONGUEUR/3))/3)*2,(HAUTEUR/14)*12,(LONGUEUR-(LONGUEUR/3))/3,"Quitter",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_GREEN1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    

    MLV_update_window();
    do{
    MLV_wait_mouse(&x,&y);
    if (HAUTEUR/14<x && x<(HAUTEUR/14)*12 && LONGUEUR/3<y && y<(LONGUEUR/3)+(LONGUEUR-(LONGUEUR/3))/3){
        return 1;
    }
    if (HAUTEUR/14<x && x<(HAUTEUR/14)*12 && LONGUEUR/3+(LONGUEUR-(LONGUEUR/3))/3 <y && y<(LONGUEUR/3+(LONGUEUR-(LONGUEUR/3))/3)+(LONGUEUR-(LONGUEUR/3))/3){
        return 2;
    }
    if (HAUTEUR/14<x && x<(HAUTEUR/14)*12 && LONGUEUR/3+(LONGUEUR-(LONGUEUR/3))/3 <y && y<(LONGUEUR/3+((LONGUEUR-(LONGUEUR/3))/3)*2)+(LONGUEUR-(LONGUEUR/3))/3){
        return -1;
    }
    }while (x!=-1);
    return 0;
}

int presentation_sans(){
int x,y;
    MLV_draw_text_box(0,0,HAUTEUR,LONGUEUR/3,"ABEILLES VS FRELONS",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(HAUTEUR/14,LONGUEUR/3,(HAUTEUR/14)*12,(LONGUEUR-(LONGUEUR/3))/3,"Nouvelle partie (elle suprime l'ancienne sauvegarde)",0,MLV_COLOR_WHITE,MLV_COLOR_WHITE, MLV_COLOR_PURPLE1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(HAUTEUR/14,LONGUEUR/3+(LONGUEUR-(LONGUEUR/3))/3,(HAUTEUR/14)*12,(LONGUEUR-(LONGUEUR/3))/3,"Quitter ",0,MLV_COLOR_BLACK,MLV_COLOR_WHITE, MLV_COLOR_ORANGE1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_update_window();
    do{
    MLV_wait_mouse(&x,&y);
    if (HAUTEUR/14<x && x<(HAUTEUR/14)*12 && LONGUEUR/3<y && y<(LONGUEUR/3)+(LONGUEUR-(LONGUEUR/3))/3){
        return 1;
    }
    if (HAUTEUR/14<x && x<(HAUTEUR/14)*12 && LONGUEUR/3+(LONGUEUR-(LONGUEUR/3))/3 <y && y<(LONGUEUR/3+(LONGUEUR-(LONGUEUR/3))/3)+(LONGUEUR-(LONGUEUR/3))/3){
        return 2;
    }

    }while (x!=-1);
    return 0;
}


int jeux_complet_sauvegarde (Liste_coord p,Grille *jeu,FILE * fichier, char * nom){
fscanf(fichier,"%c\n",nom);
    int joueur =0;
    int m = 0;
    lecture(fichier,&(*jeu),nom);
    MLV_clear_window(MLV_COLOR_BLACK);
    affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
    affiche_ressource((*jeu).ressourcesAbeille,(*jeu).ressourcesFrelon,p);
    affiche_info_partie("Bonjour",p);
        MLV_update_window();
    if (joueur%2 != 0) sauvegarde((*jeu),"A",nom);
    else sauvegarde((*jeu),"F",nom);

    do{
        if (joueur%2!=0 ){

            int fin = gameplay_abeille(p,&(*jeu),nom);
            if (fin  == -2) return -2;
            int fin1 = gameplay_frelon(p,&(*jeu),nom);
            if (fin1  == -2) return -2;
            sauvegarde((*jeu),"A",nom);
            gameplay_combat(p,&(*jeu),nom);
        }  
        else{

            int fin = gameplay_frelon(p,&(*jeu),nom);
            if (fin  == -2) return -2;
            int fin1 = gameplay_abeille(p,&(*jeu),nom);
            if (fin1  == -2) return -2;
            sauvegarde((*jeu),"B",nom);
            gameplay_combat(p,&(*jeu),nom);

        }

            
        MLV_clear_window(MLV_COLOR_BLACK);
        affiche_fenetre_debut(HAUTEUR,LONGUEUR,&p);
        complete_case((*jeu).abeille, (*jeu).frelon, &(*jeu), p);
        affiche_ressource((*jeu).ressourcesAbeille,(*jeu).ressourcesFrelon,p);
        MLV_update_window(); 
        
            
        sauvegarde((*jeu),"A",nom);
        if ((*jeu).abeille == NULL)return 5;
        if ((*jeu).frelon == NULL)return 6;
        if (joueur  == 0)return -1;
    } while (m == 0);
    MLV_wait_seconds(40);
    MLV_free_window();
    fclose(fichier);
    return 0;
}

int main (int argc, char * argv[]){
    srand((unsigned int)time(NULL));
    MLV_create_window("jeu", "jeu", HAUTEUR, LONGUEUR);
    Liste_coord p =NULL;
    FILE * fichier = NULL;
    int mode_de_jeux =0;

    do {
        int mode = verification_fichier(fichier,argv[1]);
        switch(mode){
            case 0 : fprintf(stderr, "Fichier de sauvegarde existant, ouverture en r+\n"); 
                mode_de_jeux=presentation_sauvegarde();
                break;
            
            case -1 : fprintf(stderr, "Pas de sauvegarde, création en mode a\n");
                mode_de_jeux= presentation_sans();
                break;
        }
        
        
        Grille jeux;
        int res;
        MLV_clear_window(MLV_COLOR_BLACK);
        if (mode_de_jeux == 1)res = jeux_complet (p,&jeux,fichier,argv[1]);
        if (mode_de_jeux == 2){
                init_plateau(&(jeux));
                res = jeux_complet_sauvegarde(p,&jeux,fichier,argv[1]);
                MLV_update_window(); 
        
            }
        if (mode_de_jeux == 1||mode_de_jeux == 2||mode_de_jeux == -2|| mode_de_jeux-5)gagnant(res);
        MLV_clear_window(MLV_COLOR_BLACK);
   
    } while (mode_de_jeux != -1);



    MLV_free_window();
    
}
