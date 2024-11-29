#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include"struc.h"
#include <unistd.h>
#include <string.h>
#include"struc.cpp"

void main()
{
    system("color f0");


    char pathFoyer[PATH_MAX],pathDonation[PATH_MAX],pathFournisseur[PATH_MAX],pathIndex[PATH_MAX];
    FILE *fichierFoyer,*fichierFournisseur,*fichierDonation,*fichierIndex;

    if (getcwd(pathFoyer, sizeof(pathFoyer)) != NULL && getcwd(pathDonation, sizeof(pathDonation)) != NULL && getcwd(pathFournisseur, sizeof(pathFournisseur)) != NULL
        &&getcwd(pathIndex, sizeof(pathIndex)) != NULL ) {
        strcat(pathFoyer,"/foyer");
        strcat(pathDonation,"/donation");
        strcat(pathFournisseur,"/fournisseur");
        strcat(pathIndex,"/index");

        fichierFoyer=fopen(pathFoyer,"wb+");
        fichierFournisseur=fopen(pathDonation,"wb+");
        fichierDonation=fopen(pathFournisseur,"wb+");
        fichierIndex=fopen(pathIndex,"wb+");
    }
    else exit(00);






       /* FOYER *f;
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
        remplissage_resultat(r,donation,nD);*/


        remplirFichierFoyer(fichierFoyer,fichierIndex);
        remplirFichierFournisseur(fichierFournisseur);
        remplirFichierDonation(fichierDonation);

        afficherFichierFournisseur(fichierFournisseur);
        afficherFichierDonation(fichierDonation);
        afficherFichierFoyer(fichierFoyer,fichierIndex);




/*

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




*/



    return 0;

}
