#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include"struc.h"
#include"struc.cpp"


void main()
{
    /*FOYER *f;
    int nf;
    printf("--------- FOYERS ---------\n");
    printf("\n Donner le nombre de foyers");
    scanf("%d",&nf);
    f=(FOYER*) malloc(nf*sizeof(FOYER));
    if(!f) exit (-1);
    for (int k=0;k<nf;k++)
    {
        printf("------------------------- REMPLISSAGE ---------------------------\n");
        printf("\n Donner le code foyer:");
        scanf("%d",&(f+k)->codeFoyer);
        printf("\n Donner le nombre des chambres:");
        scanf("%d",&(f+k)->nombreChambres);
        (f+k)->chambres=(CHAMBRE*) malloc((f+k)->nombreChambres * sizeof(CHAMBRE));
        if(!(f+k)->chambres) exit (-2);
        printf("--------- CHAMBRES ---------\n");
        for(int i=0 ; i<(f+k)->nombreChambres ; i++){
            printf("\n Donner le numero de la chambre %d:",i+1);
            scanf("%d",&((f+k)->chambres+i)->numeroChambre);
            printf("\n Donner la superficie de la chambre:");
            scanf("%f",&((f+k)->chambres+i)->superficie);
            printf("\n Donner le nombre de personnes dans la chambre:");
            scanf("%d",&((f+k)->chambres+i)->nombrePersonnes);
            ((f+k)->chambres + i)->necessiteux=(NECESSITEUX*) malloc( (((f+k)->chambres+i)->nombrePersonnes) * sizeof(NECESSITEUX));
            if(!((f+k)->chambres + i)->necessiteux) exit (-3);
            printf("\n ------ PERSONNES ------");
            for(int j=0 ; j<((f+k)->chambres+i)->nombrePersonnes ; j++){
                    printf("\n Donner le code du necessiteux %d:",j+1);
                    scanf("%d",&((((f+k)->chambres + i)->necessiteux)+j)->codeNecessiteux);
                    printf("\n Donner le numero de cin:");
                    scanf("%d",&((((f+k)->chambres + i)->necessiteux)+j)->numCin);
                    printf("\n Donner son age:");
                    scanf("%d",&((((f+k)->chambres + i)->necessiteux)+j)->age);
                    printf("\n Donner la duree de sejours en jours:");
                    scanf("%d",&((((f+k)->chambres + i)->necessiteux)+j)->duree);
                    printf("\n Donner le motif l--->logement et repas, et r---->repas seulement:\n");
                    scanf(" %c",&((((f+k)->chambres + i)->necessiteux)+j)->motif);
                    printf("\n Donner le code de repas:");
                    scanf("%d",&(((((f+k)->chambres + i)->necessiteux)+j)->repas).codeRepas);
                    printf("\n Donner l'heure de servir:");
                    scanf("%d",&(((((f+k)->chambres + i)->necessiteux)+j)->repas).heure);}}

            }





    FOURNISSEUR *fournisseur;
    DONATION *donation;

    int nF,nD;

    printf("--------- FOURNISSEURS ---------\n");
    printf("donner nombre fournisseurs:\n");
    scanf("%d",&nF);
    fournisseur=(FOURNISSEUR*) malloc(nF * sizeof(FOURNISSEUR));
    if(!fournisseur) exit (-4);
    for(int i=0 ; i<nF ; i++){
        printf("\n Donner le code du fournisseur:");
        scanf("%d",&(fournisseur+i)->codeFournisseur );
        printf("\n Donner les prix des plats achetes:");
        scanf("%f",&(fournisseur+i)->prix );
    }

    printf("--------- DONATIONS ---------\n");
    printf("donner nombre des donation:\n");
    scanf("%d",&nD);
    donation=(DONATION*) malloc(nD * sizeof(DONATION));
    if(!donation) exit (-5);
    for(int i=0 ; i<nD ; i++){
        printf("\n Donner l'id du donnateur:");
        scanf("%d",&(donation+i)->idDonneur );
        printf("\n Donner le montant de donation:");
        scanf("%f",&(donation+i)->montant );
    }


    printf("\n ------------------------- FIN REMPLISSAGE ---------------------------");



    printf("\n ------------------------- AFFICHAGE ---------------------------");
    printf("\n--------- FOYERS ---------");
    for(int k=0;k<nf;k++)
    {
        printf("\n code foyer: %d",(f+k)->codeFoyer);
        printf("\n nombre des chambres: %d",(f+k)->nombreChambres);
        printf("\n --------- CHAMBRES ---------");
        for(int i=0 ; i<(f+k)->nombreChambres ; i++){
            printf("\n numero chambre: %d",((f+k)->chambres+i)->numeroChambre);
            printf("\n superficie de la chambre: %.2f",((f+k)->chambres+i)->superficie);
            printf("\n nombre personnes: %d",((f+k)->chambres+i)->nombrePersonnes);
            printf("\n ------ PERSONNES ------");
            for(int j=0 ; j<((f+k)->chambres+i)->nombrePersonnes ; j++){
                    printf("\n code necessiteux : %d",((((f+k)->chambres + i)->necessiteux)+j)->codeNecessiteux);
                    printf("\n son cin: %d",((((f+k)->chambres + i)->necessiteux)+j)->numCin);
                    printf("\n son age: %d",((((f+k)->chambres + i)->necessiteux)+j)->age);
                    printf("\n duree de sejours en jours: %d",((((f+k)->chambres + i)->necessiteux)+j)->duree);
                    printf("\n le motif l--->logement et r---->repas seulement: %c",((((f+k)->chambres + i)->necessiteux)+j)->motif);
                    printf("\n le code de repas: %d",(((((f+k)->chambres + i)->necessiteux)+j)->repas).codeRepas);
                    printf("\n l'heure de servir: %d",(((((f+k)->chambres + i)->necessiteux)+j)->repas).heure);

            }


    }
    }


    printf("\n --------- FOURNISSEURS ---------");
    for(int i=0 ; i<nF ; i++){
        printf("\n code fournisseur: %d ",(fournisseur+i)->codeFournisseur );
        printf("\n prix des plats achetes: %.2f ",(fournisseur+i)->prix);
    }

    printf("\n --------- DONATIONS ---------");
    for(int i=0 ; i<nD ; i++){
        printf("\n id donnateur: %d",(donation+i)->idDonneur);
        printf("\n donner montant de donation: %.2f",(donation+i)->montant);
    }


    printf("\n ------------------------- FIN AFFICHAGE ---------------------------\n");


    printf("\n Remplissage de la structure resultat");
    RESULTAT **r;
    r=(RESULTAT**) malloc(3*sizeof(RESULTAT*));
    if(!r) exit (-6);
    for(int i=0;i<3;i++)
    {
        *(r+i)=(RESULTAT*) malloc (sizeof(RESULTAT));
        if(!*(r+i)) exit (-7);
        printf("\n Donner l'identifiant du donneur %d ",i+1);
        scanf("%d",&(*(r+i))->idDonneur);
        printf("\n Donner la somme avec laquelle il a contribue ");
        scanf("%f",&(*(r+i))->montant);
    }
    printf("\n Affichage de la structure resultat");
    for(int i=0;i<3;i++)
    {
        printf("\n l'identifiant du donneur %d est %d ",i+1,(*(r+i))->idDonneur);
        printf("\n Le montant qu'il a donne est %.2f dt", (*(r+i))->montant);
    }


*/







    FOYER *f;
    int nf;
    printf("\n--------------------- REMPLISSAGE -------------------------\n");
    printf("\n--------- FOYERS ---------\n");
    printf("Donner le nombre de foyers \n");
    scanf("%d",&nf);
    f=allocation_foyer(nf);
    remplissage_tabfoyers(f,nf);

    FOURNISSEUR *fournisseur;
    int nF;
    printf("\n--------- FOURNISSEURS ---------\n");
    printf("donner nombre fournisseurs:\n");
    scanf("%d",&nF);
    fournisseur=allocation_fournisseur(nF);
    remplissage_tabfournisseur(nF,fournisseur);

    DONATION *donation;
    int nD;
    printf("\n--------- DONATIONS ---------\n");
    printf("donner nombre des donation:\n");
    scanf("%d",&nD);
    donation= allocation_donation(nD);
    remplissage_tabdonation(nD,donation);

    RESULTAT **r;
    r=allocation_resultat();
    remplissage_resultat(r,donation,nD);


    int codeFoyer;


    int choix;

    do
    {
        menu();
        scanf("%d",&choix);
        switch (choix)
    {
    case 1: ajouterNecissiteux(f,nf); break;
    case 2: ajouterChambre(f,nf);break;
    case 3: ajouterFoyer(&f,&nf);break;
    case 4: affichage_tabfoyers(f,nf); break;
    case 5: affichage_tabfournisseur(fournisseur,nF); break;
    case 6: affichage_tabdonation(donation,nD); break;
    case 7: affichage_resultat(r,donation); break;
    case 8: printf ("\n Donner le code du foyer"); scanf("%d", &codeFoyer); int ncpf=nombreNecessiteuxParFoyer(codeFoyer,f,nf); printf("\n %d", ncpf); break;
    case 9: repartitionNecessiteuxSelonAge(f,nf); break;
    case 10: printf("%.2f dt",total_donations(donation,nD)); break;
    case 11: meilleur_donateur(donation,nD); break;
    case 0:  printf("Quitter le programme...\n"); return 0;
    default: printf("\n Veuillez faire un choix valide!"); break;

    }
    printf("\n");
    }
    while(choix!=0);








    return 0;

}
