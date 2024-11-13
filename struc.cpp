#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"struc.h"

FOYER* allocation_foyer(int nf)
{
    FOYER* f;
    f=(FOYER*) malloc(nf*sizeof(FOYER));
    if(!f) exit (-1);
    return f;
}

CHAMBRE* allocation_chambre(int nbc)
{
    CHAMBRE* chambres;
    chambres=(CHAMBRE*) malloc(nbc*sizeof(CHAMBRE));
    if(!chambres) exit (-2);
    return chambres;
}

NECESSITEUX* allocation_necessiteux(int nbn)
{
    NECESSITEUX* necessiteux;
    necessiteux=(NECESSITEUX*) malloc(nbn*sizeof(NECESSITEUX));
    if(!necessiteux) exit (-3);
    return necessiteux;
}

REPAS remplissage_repas()
{
    printf("\n--------- REPAS ---------\n");
    REPAS repas;
    printf("\n Donner le code de repas:");
    scanf("%d",&repas.codeRepas);
    printf("\n Donner l'heure de servir:");
    scanf("%d",&repas.heure);
    return repas;
}

void affichage_repas(REPAS repas)
{
    printf("\n--------- REPAS ---------\n");
    printf("\n le code de repas: %d",repas.codeRepas);
    printf("\n l'heure de servir: %d",(repas.heure));
}

void remplissage_tabnecessiteux(NECESSITEUX* necessiteux, int nbn)
{
    printf("\n--------- NECESSITEUX ---------\n");
    for(int j=0 ; j<nbn; j++)
        {
            printf("\n Donner le code du necessiteux %d:",j+1);
            scanf("%d",&(necessiteux+j)->codeNecessiteux);
            printf("\n Donner le numero de cin:");
            scanf("%d",&(necessiteux+j)->numCin);
            printf("\n Donner son age:");
            scanf("%d",&(necessiteux+j)->age);
            printf("\n Donner la duree de sejours en jours:");
            scanf("%d",&(necessiteux+j)->duree);
            printf("\n Donner le motif l--->logement et repas, et r---->repas seulement:\n");
            scanf(" %c",&(necessiteux+j)->motif);
            (necessiteux+j)->repas=remplissage_repas();

            }
}

void affichage_tabnecessiteux(NECESSITEUX* necessiteux,int nbn)
{
    printf("\n--------- NECESSITEUX ---------\n");
    for(int j=0 ; j<nbn; j++)
        {
            printf("\n code necessiteux : %d",(necessiteux+j)->codeNecessiteux);
            printf("\n son cin: %d",(necessiteux+j)->numCin);
            printf("\n son age: %d",(necessiteux+j)->age);
            printf("\n duree de sejours en jours: %d",(necessiteux+j)->duree);
            printf("\n le motif l--->logement et r---->repas seulement: %c",(necessiteux+j)->motif);
            affichage_repas((necessiteux+j)->repas);
        }
}


void remplissage_tabchambres(CHAMBRE* chambres,int nbc)
{
    printf("\n--------- CHAMBRES---------\n");
    for(int i=0 ; i<nbc ; i++)
        {
            printf("\n Donner le numero de la chambre %d:",i+1);
            scanf("%d",&(chambres+i)->numeroChambre);
            printf("\n Donner la superficie de la chambre:");
            scanf("%f",&(chambres+i)->superficie);
            printf("\n Donner le nombre de personnes dans la chambre:");
            scanf("%d",&(chambres+i)->nombrePersonnes);
            (chambres + i)->necessiteux= allocation_necessiteux((chambres+i)->nombrePersonnes);
            remplissage_tabnecessiteux((chambres + i)->necessiteux, (chambres+i)->nombrePersonnes);
        }
}

void affichage_tabchambres(CHAMBRE* chambres, int nbc)
{
    printf("\n--------- CHAMBRES ---------\n");
    for(int i=0 ; i<nbc ; i++)
        {
            printf("\n numero chambre: %d",(chambres+i)->numeroChambre);
            printf("\n superficie de la chambre: %.2f",(chambres+i)->superficie);
            affichage_tabnecessiteux((chambres+i)->necessiteux,(chambres+i)->nombrePersonnes);
        }
}

void remplissage_tabfoyers(FOYER* f, int nf)
{
    for (int k=0;k<nf;k++)
    {
        printf("\n Donner le code foyer:");
        scanf("%d",&(f+k)->codeFoyer);
        printf("\n Donner le nombre des chambres:");
        scanf("%d",&(f+k)->nombreChambres);
        (f+k)->chambres=allocation_chambre((f+k)->nombreChambres);
        remplissage_tabchambres((f+k)->chambres ,(f+k)->nombreChambres);
    }
}

void affichage_tabfoyers(FOYER* f, int nf)
{
    for(int k=0;k<nf;k++)
    {
        printf("\n code foyer: %d",(f+k)->codeFoyer);
        printf("\n nombre des chambres: %d",(f+k)->nombreChambres);
        affichage_tabchambres((f+k)->chambres, (f+k)->nombreChambres);
    }
}

FOURNISSEUR* allocation_fournisseur(int nF)
{
    FOURNISSEUR* fournisseur;
    fournisseur=(FOURNISSEUR*) malloc(nF*sizeof(FOURNISSEUR));
    if(!fournisseur) exit(-4);
    return fournisseur;
}

void remplissage_tabfournisseur(int nF,FOURNISSEUR* fournisseur)
{
    for (int i=0;i<nF;i++)
    {
        printf("\n Donner le code du fournisseur:");
        scanf("%d",&(fournisseur+i)->codeFournisseur);
        printf("\n Donner les prix des plats achetes:");
        scanf("%f",&(fournisseur+i)->prix);
    }

}

void affichage_tabfournisseur(FOURNISSEUR* fournisseur,int nF)
{
    for(int i=0;i<nF;i++)
    {
        printf("\n code fournisseur: %d ",(fournisseur+i)->codeFournisseur );
        printf("\n prix des plats achetes: %.2f dt ",(fournisseur+i)->prix);
    }
    }

DONATION* allocation_donation(int nF)
{
    DONATION* donation;
    donation=(DONATION*) malloc(nF*sizeof(DONATION));
    if(!donation) exit(-5);
    return donation;
}

void remplissage_tabdonation(int nD,DONATION* donation)
{
    for (int i=0;i<nD;i++)
    {
        printf("\n Donner l'id du donnateur:");
        scanf("%d",&(donation+i)->idDonneur );
        printf("\n Donner le montant de donation:");
        scanf("%f",&(donation+i)->montant );
    }

}

void affichage_tabdonation(DONATION* donation, int nD)
{
    for(int i=0 ; i<nD ; i++){
        printf("\n id donnateur: %d",(donation+i)->idDonneur);
        printf("\n donner montant de donation: %.2f dt",(donation+i)->montant);
    }
}

void tri_donateurs(DONATION* donation, int nD)
{
    int index;
    DONATION tmp;
    for (int i=0; i<nD-1; i++)
  {
    index=i;

    for (int j=i+1; j<nD; j++)
    {
      if ((donation+index)->montant < (donation+j)->montant)
        index=j;
    }
    if (index!= i)
    {
      tmp = *(donation+i);
      *(donation+i) = *(donation+index);
      *(donation+index)= tmp;
    }
  }
}

RESULTAT** allocation_resultat()
{
    RESULTAT** r;
    r=(RESULTAT**) malloc(3*sizeof(RESULTAT*));
    if(!r) exit (-6);
    return r;
}

void remplissage_resultat(RESULTAT** r, DONATION* donation, int nD)
{
    tri_donateurs(donation,nD);
    for(int i=0;i<3;i++)
    {
        *(r+i)=(RESULTAT*) malloc (sizeof(RESULTAT));
        if(!*(r+i)) exit (-7);
        (*(r+i))->idDonneur=(donation+i)->idDonneur;
        (*(r+i))->montant=(donation+i)->montant;
    }
}

void affichage_resultat(RESULTAT** r, DONATION* donation)
{
    for(int i=0;i<3;i++)
    {
        printf("\n l'identifiant du donneur %d est %d ",i+1,(*(r+i))->idDonneur);
        printf("\n Le montant qu'il a donne est %.2f dt", (*(r+i))->montant);
    }
}

 int nombreNecessiteuxParFoyer(int codeFoyer,FOYER* listeDesFoyes,int nombreFoyer)
 {

    int somme=0;

    FOYER* f=listeDesFoyes;
    for(int i=0 ; i<nombreFoyer ; i++){

        if((f+i)->codeFoyer == codeFoyer)
        {
             for(int j=0 ; j<(f+i)->nombreChambres ; j++){
                somme+=((f+i)->chambres+j)->nombrePersonnes;
            }
        }

    }


    return somme;

    }

void repartitionNecessiteuxSelonAge(FOYER* listeDesFoyers ,int nombreFoyers){

    FOYER* foyer=listeDesFoyers;
    for (int i = 0; i < nombreFoyers; i++) {
        printf("Foyer Code: %d\n", (foyer+i)->codeFoyer);
        int moinsDe18 = 0, entre18et40 = 0, plusDe40 = 0;

        for (int j = 0; j < (foyer+i)->nombreChambres; j++) {
            CHAMBRE* chambre = (foyer+i)->chambres+j;
            for (int k = 0; k < chambre->nombrePersonnes; k++) {
                NECESSITEUX* necessiteux = chambre->necessiteux+k;

                if (necessiteux->age < 18) {
                    moinsDe18++;
                } else if (necessiteux->age >= 18 && necessiteux->age <= 40) {
                    entre18et40++;
                } else {
                    plusDe40++;
                }
            }
        }

        printf("Repartition des necessiteux selon l'age dans le foyer %d:\n", (foyer+i)->codeFoyer);
        printf("Moins de 18 ans : %d\n", moinsDe18);
        printf("Entre 18 et 40 ans : %d\n", entre18et40);
        printf("Plus de 40 ans : %d\n", plusDe40);
        printf("-------------------------\n");
    }

}

float total_donations(DONATION* donation,int nD)
{
    float s=0.0;
    for(int i=0;i<nD;i++)
    {
        s=s+(donation+i)->montant;
    }
    return s;
}

void meilleur_donateur(DONATION* donation, int nD)
{
    tri_donateurs(donation,nD);
    printf("\n L'identifiant du meilleur donateur est %d",donation->idDonneur);
    printf("\n La somme avec laquelle il a contribue est %.2f dt",donation->montant);
}

void ajouterNecissiteux(FOYER* foyer,int nf)
{
    int codeFoyer,codeChambre;
    printf("donner code foyer: ");
    scanf("%d",&codeFoyer);
    printf("\ndonner code chambre: ");
    scanf("%d",&codeChambre);
    for (int i=0;i<nf;i++)
    {
        if ((foyer+i)->codeFoyer==codeFoyer){
          for(int j=0 ; j<(foyer+i)->nombreChambres ; j++)
            {
                if ((((foyer+i)->chambres)+j)->numeroChambre==codeChambre ){
                    (((foyer+i)->chambres)+j)->nombrePersonnes++;
                    (((foyer+i)->chambres)+j)->necessiteux=(NECESSITEUX*) realloc((((foyer+i)->chambres)+j)->necessiteux,(((foyer+i)->chambres)+j)->nombrePersonnes*sizeof(NECESSITEUX));
                    NECESSITEUX* nouveau=((((foyer+i)->chambres)+j)->necessiteux)+(((foyer+i)->chambres)+j)->nombrePersonnes-1;
                    printf("\n Donner le code du necessiteux %d:",j+1);
                    scanf("%d",&(nouveau)->codeNecessiteux);
                    printf("\n Donner le numero de cin:");
                    scanf("%d",&(nouveau)->numCin);
                    printf("\n Donner son age:");
                    scanf("%d",&(nouveau)->age);
                    printf("\n Donner la duree de sejours en jours:");
                    scanf("%d",&(nouveau)->duree);
                    printf("\n Donner le motif l--->logement et repas, et r---->repas seulement:\n");
                    scanf(" %c",&(nouveau)->motif);
                    (nouveau)->repas=remplissage_repas();
                    return;
                }
            }
        }
    }
    printf("foyer ou chambre introuvable !!\n");
}

CHAMBRE remplissage_chambre()
{
    CHAMBRE ch;
    printf("\n Donner le numero de la chambre");
    scanf("%d",&ch.numeroChambre);
    printf("\n Donner la superficie de la chambre");
    scanf("%f",&ch.superficie);
    printf("\n Donner le nombre de necessiteux");
    scanf("%d",&ch.nombrePersonnes);
    remplissage_tabnecessiteux(ch.necessiteux,ch.nombrePersonnes);
    return ch;
}

void ajouterChambre(FOYER* foyer,int nf){
    int codeFoyer;
    printf("donner code foyer: ");
    scanf("%d",&codeFoyer);
    for (int i=0;i<nf;i++)
    {
        if ((foyer+i)->codeFoyer==codeFoyer){
            (foyer+i)->nombreChambres++;
            int nc=(foyer+i)->nombreChambres;
            (foyer+i)->chambres=(CHAMBRE*) realloc((foyer+i)->chambres,nc*sizeof(CHAMBRE));
            //CHAMBRE* newChambres = realloc((foyer+i)->chambres, nc * sizeof(CHAMBRE));
            if (!(foyer+i)->chambres) exit (-8);
            *(((foyer+i)->chambres))=remplissage_chambre();
            return;
        }
    }
    printf("foyer introuvable !!\n");
}
FOYER remplissage_foyer()
{
    FOYER f;
    printf("\n Donner code foyer");
    scanf("%d",&f.codeFoyer);
    printf("\n Donner le nombre de chambres");
    scanf("%d",&f.nombreChambres);
    remplissage_tabchambres(f.chambres,f.nombreChambres);
    return f;

}
void ajouterFoyer(FOYER** foyer,int* nf){
    *(nf)++;

    *foyer=(FOYER*) realloc(*foyer,(*nf)*sizeof(FOYER));
    if(!*foyer) exit(-7);
    int l=(*(nf))-1;
    *(*foyer-1)=remplissage_foyer();
    return;

}

void menu()
{
    printf("\n------------------------- MENU -------------------------\n");
    printf("Veuillez selectionner une option parmi les suivantes :\n");
    printf("1.Ajouter un nouveau necessiteux\n");
    printf("2.Ajouter une nouvelle chambre\n");
    printf("3.Ajouter un nouveau foyer\n");
    printf("4.Affichage des foyers\n");
    printf("5.Affichage des fournisseurs\n");
    printf("6.Affichage des donations\n");
    printf("7.Affichage des 3 premiers donateurs\n");
    printf("8.Affichage du nombre des necessiteux par foyer\n");
    printf("9.Affichage de la repartition des necessiteux selon l'age \n");
    printf("10:Afficher la somme totale des donations \n");
    printf("11:Afficher le meilleur donateur \n");
    printf("0. Quitter\n");
    printf("--------------------------------------------------------\n");
    printf("Votre choix : ");

}


