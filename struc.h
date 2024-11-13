#ifndef STRUC_H_INCLUDED
#define STRUC_H_INCLUDED
struct repas{
int codeRepas; //code de repas
int heure; //heure de repas
};
typedef struct repas REPAS;

struct necessiteux{
int codeNecessiteux; //code du necessiteux
int numCin; //numéro de cin
int duree; //durée de séjour
int age;
char motif; //l pour logement avec repas et r pour repas seulement
REPAS repas; //le repas dont le necessiteux va bénéficier
};
typedef struct necessiteux NECESSITEUX;

struct chambre{
int numeroChambre; //numéro de chambre
float superficie; //superficie de la chambre
int nombrePersonnes; //nombre de personnes dans la chambre
NECESSITEUX* necessiteux; //liste des necessiteux
};
typedef struct chambre CHAMBRE;

struct foyer{
int codeFoyer; //code du foyer
int nombreChambres;
CHAMBRE* chambres; //liste des chambres
};
typedef struct foyer FOYER;

struct fournisseur{
int codeFournisseur; //code de fournisseur
float prix; //prix des plats achetés
};
typedef struct fournisseur FOURNISSEUR;

struct donation{
int idDonneur; //identifiant du donneur
float montant; //montant de donation
};
typedef struct donation DONATION;

struct resultat { //les trois donneurs qui aident le plus financièrement
int idDonneur;
float montant;
};
typedef struct resultat RESULTAT;

REPAS remplissage_repas();
void affichage_repas(REPAS);

NECESSITEUX* allocation_necessiteux(int);
void remplissage_tabnecessiteux(NECESSITEUX*,int);
void affichage_tabnecessiteux(NECESSITEUX*,int);

CHAMBRE* allocation_chambre(int);
void remplissage_tabchambres(CHAMBRE*,int);
void affichage_tabchambres(CHAMBRE*, int);
CHAMBRE remplissage_chambre();

FOYER* allocation_foyer(int);
void remplissage_tabfoyers(FOYER*, int);
void affichage_tabfoyers(FOYER*, int);
FOYER remplissage_foyer();

FOURNISSEUR* allocation_fournisseur(int);
void remplissage_tabfournisseur(int,FOURNISSEUR*);
void affichage_tabfournisseur(FOURNISSEUR*,int);

DONATION* allocation_donnation(int);
void remplissage_tabdonation(int,DONATION*);
void affichage_tabdonation(DONATION*, int);

void tri_donateurs(DONATION*, int);
RESULTAT** allocation_resultat();
void remplissage_resultat(RESULTAT**,DONATION*,int);
void affichage_resultat(RESULTAT**, DONATION*);

int nombreNecessiteuxParFoyer(int,FOYER*,int);

void repartitionNecessiteuxSelonAge(FOYER*,int);

float total_donations(DONATION*,int);

void meilleur_donateur(DONATION*, int);

void ajouterNecissiteux(FOYER*,int);
void ajouterChambre(FOYER*,int);
void ajouterFoyer(FOYER**,int*);

void menu();
#endif // STRUC_H_INCLUDED
