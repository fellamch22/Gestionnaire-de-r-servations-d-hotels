
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include "conio.h"
#include "conio2.h"
#include "biblio_llc_hotel.h"





                                   /************************************************
                                    ------------ MACHINE ABSTRAITE -----------------
                                   ************************************************/

        /****************************************************************************************************************
                         ------------------ MACHINE ABSTRAITE DES CHAMBRES ----------------
        /***************************************************************************************************************/



/***************************************************************************************************************/
struct chambre* allouer_chambre(){return ((struct chambre*)malloc(sizeof(struct chambre)));}
/***************************************************************************************************************/
void affadr_chambre (struct chambre* p ,struct chambre* q){p->ch_suiv=q;}
/***************************************************************************************************************/
struct chambre* suivant_chambre (struct chambre* p){;return p->ch_suiv;};
/***************************************************************************************************************/
void aff_nb_chambre (struct chambre* p,int numch){p->num_chambre=numch;};
/***************************************************************************************************************/
int num_chambre(struct chambre* p){return p->num_chambre;};
/***************************************************************************************************************/
char* datedeb(struct chambre* p){return p->datedeb;};
/***************************************************************************************************************/
char* datefin(struct chambre* p){return p->datefin;};
/***************************************************************************************************************/
void aff_datedeb (struct chambre* p, char datedeb[15]){strcpy(p->datedeb,datedeb);};
/***************************************************************************************************************/
void aff_datefin (struct chambre* p ,char datefin[15]){strcpy(p->datefin,datefin) ;};
/***************************************************************************************************************/
void aff_typechambre (struct chambre* p,int typech ){p->type=typech;};
/***************************************************************************************************************/
int type_chambre (struct chambre* p){return p->type;};
/***************************************************************************************************************/
void aff_statutchambre (struct chambre* p, int statutch){p->statut=statutch;};
/***************************************************************************************************************/
int statut_chambre(struct chambre* p){return p->statut;}
/***************************************************************************************************************/
void aff_prixchambre (struct chambre* p ,int prixch){p->prix=prixch;};
/***************************************************************************************************************/
int prix_chambre(struct chambre* p){return p->prix;};
/***************************************************************************************************************/
char* nom_client(struct chambre* p){return p->nom;};
/***************************************************************************************************************/
void aff_nomclient (struct chambre* p,char nomc [26]){ strcpy(p->nom,nomc);}
/***************************************************************************************************************/


           /***************************************************************************************************************
                        /------------------MACHINE ABSTRAITE HOTEL ----------------------/
           /**************************************************************************************************************/


/*********************************************************************************************************/
struct hotel* allouer_hotel(){return ((struct hotel*)malloc(sizeof(struct hotel)));};
/*********************************************************************************************************/
void affadr_hotel (struct hotel* p,struct hotel* q){p->hot_suiv=q;};
/*********************************************************************************************************/
struct hotel* suivant_hotel(struct hotel* p){return p->hot_suiv;};
/*********************************************************************************************************/
char* nom_hotel(struct hotel* p){return p->nomhotel;}
/*******************************************************************************************************/
void aff_nomhotel(struct hotel* p,char nomhot[15]){ strcpy(p->nomhotel,nomhot);}
/*********************************************************************************************************/
void aff_nomville(struct hotel* p,char nomville[15]){ strcpy(p->ville,nomville);}
/*********************************************************************************************************/
char* ville(struct hotel* p){return p->ville;}
/*********************************************************************************************************/
void aff_nbchambres (struct hotel* p, int nb_chambres){ p->capacite=nb_chambres;}
/*********************************************************************************************************/
int nb_chambres (struct hotel* p){return p->capacite ;}
/*********************************************************************************************************/
void aff_nbchlibres (struct hotel* p , int nb_chamblibres){p->nb_chlib=nb_chamblibres;};
/*********************************************************************************************************/
int nb_chambresvides(struct hotel* p){return p->nb_chlib;};
/*********************************************************************************************************/
void aff_nbchoccupes (struct hotel* p,int nb_choccupes ){p->nb_chocc=nb_choccupes;};
/*********************************************************************************************************/
int nb_choccupes (struct hotel * p){return p->nb_chocc;};
/*********************************************************************************************************/
void aff_adr_chambresocc(struct hotel* p,struct chambre* q){p->tete_chocc=q;};
/*********************************************************************************************************/
void aff_adr_chambreslib(struct hotel* p,struct chambre* q){p->tete_chlib=q;};
/*********************************************************************************************************/
struct chambre* adr_tetechocc (struct hotel* p){return p->tete_chocc;};
/*********************************************************************************************************/
struct chambre* adr_tetechlib (struct hotel* p){return p->tete_chlib;};
/*********************************************************************************************************/
void aff_prixhotel1(struct hotel* p,int prix){p->prix_hotel1=prix;}
/*********************************************************************************************************/
int prix_hotel1(struct hotel* p){return p->prix_hotel1;}
/*********************************************************************************************************/
void aff_prixhotel2(struct hotel* p,int prix){p->prix_hotel2=prix;}
/*********************************************************************************************************/
int prix_hotel2(struct hotel* p){return p->prix_hotel2;};
/*********************************************************************************************************/



            /**************************************************************************************************************
                               -------------- MACHINE ASTRAITE DES LETTRES ----------------
            **************************************************************************************************************/


/**********************************************************************************************************/
struct lettre* allouer_lettre (){return ((struct lettre*)malloc(sizeof(struct lettre)));}
/**********************************************************************************************************/
void affadr_lettre ( struct lettre* p,struct lettre* suivant){p->let_suiv=suivant;};
/**********************************************************************************************************/
void aff_lettre(struct lettre* p,char lettre){p->letr=lettre;};
/**********************************************************************************************************/
char lettre (struct lettre* p){return p->letr;};
/**********************************************************************************************************/
struct lettre* suivant_lettre (struct lettre* p){return p->let_suiv;};
/**********************************************************************************************************/
void aff_adrtetehotel (struct lettre* p,struct hotel* tetehotel){p->hot=tetehotel;};
/**********************************************************************************************************/
struct hotel* adr_tetehotel(struct lettre* p){return p->hot;};
/**********************************************************************************************************/



        /*******************************************************************************************************************************/
                             /**************************** LES MODULES DU MENU *******************************/
        /*******************************************************************************************************************************/



/**********************************************
              INSERER MAILLON
**********************************************/
// POUR INSERER UN MAILLON DANS UNE LISTE DE CAHMBRES

void inserer_maillon(struct chambre** t, struct chambre* r)
{   //Declarations
    struct chambre* p=(*t);
    struct chambre* q=NULL;
    int trouve=0;
    //Code
    while ((p!=NULL)&&(trouve==0)){
        if(num_chambre(r)>num_chambre(p)){
            q=p;
            p=suivant_chambre(p);
        }
        else{
            trouve=1;
        }
    }
    if(q!=NULL){
        affadr_chambre(q,r);
        affadr_chambre(r,p);
    }
    else{
        affadr_chambre(r,p);
        (*t)=r;
    }
}

/****************************************
        SUPPRIMER MAILLON
****************************************/

// SUPPRIMER UN MAILLON DANS UNE LISTE DE CHAMBRE

void supprimer_maillon(struct chambre** t,struct chambre* s,struct chambre* r){
    //Code
    if(r!=NULL){
        if(s!=NULL){
            affadr_chambre(s,suivant_chambre(r));
        }
        else{
            (*t)=suivant_chambre(*t);
        }
    }
}


/****************************************
     SUPPRIMER UNE RESERVATION
****************************************/
//CHOIX 6 DU MENU

void supprimer_reservation(struct lettre* t, char nomclient[]){
    //Declarations
    struct lettre* p=t;
    struct hotel* q=NULL;
    struct hotel* l=NULL;
    struct chambre* r=NULL;
    struct chambre* s=NULL;
    struct chambre* a=NULL;
    struct chambre* b=NULL;
    int trouve=0;
    //Code

    while((p!=NULL)&&(trouve==0)){
        q=adr_tetehotel(p);
        while((q!=NULL)&&(trouve==0)){
            r=adr_tetechocc(q);
            while((r!=NULL)&&(trouve==0)){
               if(strcmp(nom_client(r),nomclient)==0){
                  trouve=1;
               }
               else{
                  s=r;
                  r=suivant_chambre(r);
               }
            }

            l=q;
            q=suivant_hotel(q);
        }
        p=suivant_lettre(p);
    }
    if(r!=NULL){
        a=adr_tetechlib(l);
        b=adr_tetechocc(l);
        aff_statutchambre(r,0);
        supprimer_maillon(&(b),s,r); //Supprimer la chambre des listes de chambre occupées
        aff_adr_chambresocc(l,b);
        inserer_maillon(&(a),r); //inserer la chambre dans la liste des chambres libres
        aff_adr_chambreslib(l,a);
        aff_nbchlibres(l,nb_chambresvides(l)+1); //revoir le nombre de chambres libres et occupées dans le maillon de l'hotel conserné
        aff_nbchoccupes(l,nb_choccupes(l)-1);
    }
    else{
        printf("\n ------------------- \n cette reservation n'existe pas \n ------------------- \n\n");
    }
}



/*****************************************************
               LIBERER UNE LISTE
*****************************************************/
//liberer une liste de chambres completement

void liberer_list(struct chambre** t){
    //Declaration
    struct chambre* p;
    //Code

    while ((*t)!=NULL){
        p=(*t);
        (*t)=suivant_chambre(*t);
        free(p);
        p=NULL;
    }
}


/***************************************************
               SUPPRIMER HOTEL
****************************************************/
// Choix 10 du menu

void supprimer_hotel(struct lettre* t, char nomhotel[]){
    struct lettre* p=t;
    struct hotel* q=NULL;
    struct hotel* r=NULL;
    struct chambre* a=NULL;
    struct chambre* b=NULL;
    int trouve1=0;
    int trouve2=0;
    char let=toupper(nomhotel[0]);
    while ((p!=NULL)&&(trouve1==0)){
        if(let==lettre(p)){
            trouve1=1;
        }
        else{
            p=suivant_lettre(p);
        }
    }
    if(p!=NULL){
        q=adr_tetehotel(p);
        while((q!=NULL)&&(trouve2==0)){
            if(strcasecmp(nom_hotel(q),nomhotel)==0){
                trouve2=1;
            }
            else{
                r=q;
                q=suivant_hotel(q);
            }
        }
        if(q!=NULL){
            a=adr_tetechlib(q); //liberer les deux listes de chambres libres et occupees
            b=adr_tetechocc(q);
            liberer_list(&a);
            aff_adr_chambreslib(q,NULL);
            liberer_list(&b);
            aff_adr_chambresocc(q,NULL);
            if(r!=NULL){
                affadr_hotel(r,suivant_hotel(q));
            }
            else{
                aff_adrtetehotel(p,suivant_hotel(q));
            }
            free(q); //liberer le maillon de d'hotel voulu
            q=NULL;
        }
        else{
            printf("\n ------------------- \n ******** l'hotel n'existe pas ********* \n ------------------- \n\n");
        }
    }
    else{
        printf("\n ------------------- \n ******** le nom que vous introduisez doit commencer par un caractere ******** \n ------------------- \n \n ");
    }
}

/**************************************************************
       CHERCHER UNE CHAMBRE AVEC LE PLUS BAT PRIX
**************************************************************/
// Choix 7 du menu

void plus_bat_prix(struct lettre* t,int type){
    //Declarations
    struct lettre* p=t;
    struct hotel* q=NULL;
    struct chambre* r=NULL;
    struct chambre* chambre=NULL;
    struct hotel* hotel=NULL;
    int trouve=0,i;
    int min=9999999999; //initialisation pou la premiere fois
    //Code
    while(p!=NULL){
        q=adr_tetehotel(p);
        while(q!=NULL){
            r=adr_tetechlib(q);
            while((r!=NULL)&&(trouve==0)){
                if(type_chambre(r)==type){
                    trouve=1;
                    if(prix_chambre(r)<min){
                        chambre=r;
                        hotel=q;
                        min=prix_chambre(r);
                    }
                }
                else{
                    r=suivant_chambre(r);
                }
            }
            trouve=0;
            q=suivant_hotel(q);

        }
        p=suivant_lettre(p);
    }
    if(chambre!=NULL){
        printf("\n ------------------- \n ******** Le nom de l'hotel est %s   ********\n ------------------- \n\n",nom_hotel(hotel));
         for(i = 1;i<=100;i++) {
        gotoxy(i,16);
        delay(10);
    	printf("%c",'*');}
        printf("\n Ci desous la liste des chambres libres dans cet hotel avec le prix de %d DA \n ------------------- \n\n",prix_chambre(chambre));
        while( chambre!=NULL){ //Afficher toute la liste de chambres libres de cet hotel
            if(type_chambre(chambre)==type){
                printf("\n ------------------- \n * Chambre numero : %d *\n ------------------- \n\n",num_chambre(chambre));
            }
            chambre=suivant_chambre(chambre);
        }

    }
    else{
        printf("\n ------------------- \n ******** Nous n'avons aucune chambre libre revenez ulterierement  ********\n ------------------- \n");
    }

}

/*********************************************************************
              RECHERCHE PAR VILLE
**********************************************************************/
int recherche_ville(struct lettre* t, char vil[],int type){
    //Declarations
    int trouve1=0;
    int trouve2=0;
    int cpt=0;
    struct lettre* p=t;
    struct hotel* q=NULL;
    struct chambre* r=NULL;

    //Code
    while(p!=NULL){
        q=adr_tetehotel(p);
        while(q!=NULL){
            if(strcasecmp(ville(q),vil)==0){
                trouve1=1;
                r=adr_tetechlib(q);
                while(r!=NULL){
                    if(type_chambre(r)==type){
                        trouve2=1;
                        if (cpt==0){
                        printf("\n ------------------- \n ******** Hotel : %s  ********\n ------------------- \n\n ",nom_hotel(q));
                        printf("******** Chambre numero %d a %d DA  ********\n ------------------- \n",num_chambre(r),prix_chambre(r));
                        cpt++;
                        }
                        else{printf("********  Chambre numero %d a %d DA ********\n------------------- \n",num_chambre(r),prix_chambre(r));}
                    }
                    r=suivant_chambre(r);
                }
           }
           q=suivant_hotel(q);
           cpt=0;
       }
       p=suivant_lettre(p);

   }
   if(trouve1==1){
     if(trouve2==0){
        printf("******** il n'existe pas de chambre libre de ce type dans cette ville ********");
     }
   }
   else{
    printf(" ******** nous n'avons pas d'hotels dans cette ville ********");
   }
   return trouve2;
}


/************************************************************
                RECHERCHE PAR HOTEL
************************************************************/
int recherche_hotel(struct lettre* t,int type,char nom[15]){
    //Declaration
    int trouve=0;
    int trouve1=0;
    int trouve2=0;
    struct lettre* p=t;
    struct hotel* q=NULL;
    struct chambre* r=NULL;
    char let=toupper(nom[0]);//Toupper foction standart en c qui transforme un caractere en sa forme majuscule
    //Code
    while ((p!=NULL)&&(trouve==0)){
        if(let==lettre(p)){
            trouve=1;
        }
        else{
            p=suivant_lettre(p);
        }
    }
    if(p!=NULL){
        q=adr_tetehotel(p);
        while((q!=NULL)&&(trouve1==0)){
            if(strcasecmp(nom_hotel(q),nom)==0){
                trouve1=1;
            }
            else{
                q=suivant_hotel(q);
            }
        }
        if(q!=NULL){
            r=adr_tetechlib(q);
            while(r!=NULL){
                if(type_chambre(r)==type){
                    trouve2=1;
                    printf("le numero de chambre est %d \n",num_chambre(r));
                    printf("le prix est de %d \n",prix_chambre(r));
                }
                r=suivant_chambre(r);
            }
            if(trouve2==0){
                printf("nous n'avons pas de chambres libres de ce type pour l'hotel que vous avez demander");
            }
        }
        else{
            printf("nous n'avons pas d'hotel de ce nom");
        }
    }
    else{
         printf("Le nom d'hotel que vous introduisez doit obligatoirement commencer par une lettre ");
    }
    return trouve2;
}


/******************************************************************
             AFFICHER LE STATUT DES RESERVATIONS
******************************************************************/

void afficher_statut_reserv(struct lettre* t){
    //Declarations
    struct lettre* p=t;
    struct hotel* q=NULL;
    struct chambre* r =NULL;
    int trouve=0;
    //Code

    for(int i=1;i<=26;i++){
        printf("\n                     ----------------------------------------------------------- \n                                **********   Lettre %c     **********                   \n",lettre(p));
        if(adr_tetehotel(p)!=NULL){
            q=adr_tetehotel(p);
            while (q!=NULL){
                printf("\n                               --------------------------------------\n                               Hotel  ********** %s **********  \n                               --------------------------------------\n",nom_hotel(q));
                r=adr_tetechocc(q);
                while(r!=NULL){
                    trouve=1;
                     printf("--------------------------------------------------------------------------------------------------------------------------------- \n Nom du client:  %s  Numero de chambre:  %d  Type de reservation:  %d  Date de debut:  %s  Date de fin:  %s \n --------------------------------------------------------------------------------------------------------------------------------- \n",nom_client(r),num_chambre(r),type_chambre(r),datedeb(r),datefin(r));

                    r=suivant_chambre(r);
                }
                if(trouve==0){
                    printf("\n ------- Aucune reservation n'a ete trouvé dans cet hotel ---------- \n \n");
                }
                q=suivant_hotel(q);
            }
        }
        else{
            printf("\n------------ Aucun hotel commançant par cette lettre n'a ete trouvé ---------------------\n \n");
        }
    p=suivant_lettre(p);
    }
}


/*******************************************************************
                   INSERER UNE RESERVATION
********************************************************************/

void inserer_reservation(struct lettre* t,char nomhotel[],char nom[],char vil[],int numch,char datedeb[],char datefin[]){
    //Declarations
    struct lettre* p=t;
    struct hotel*q=NULL;
    struct chambre* r=NULL;
    struct chambre* s=NULL;

    char letr;
    int trouve1=0;
    int trouve2=0;
    int trouve3=0;
    int fini=0;
    int i;

    //Code
if(verif_date(datedeb,datefin)==1){

    letr=toupper(nomhotel[0]);

    while ((p!=NULL)&&(trouve1==0)){

        if(letr==lettre(p)){
            trouve1=1;
        }
        else{
            p=suivant_lettre(p);
        }
    }
    if(p!=NULL){
        q=adr_tetehotel(p);
        while((q!=NULL)&&(trouve2==0)){
            if((strcasecmp(nom_hotel(q),nomhotel)==0)&&(strcasecmp(ville(q),vil)==0)){
                trouve2=1;
            }
            else{
                q=suivant_hotel(q);
            }
        }
        if(q!=NULL){
            r=adr_tetechlib(q);
            while((r!=NULL)&&(fini==0)){
                if (num_chambre(r)==numch){
                    fini=1;
                }
                else{
                    s=r;
                    r=suivant_chambre(r);
                }
            }
            if(r!=NULL){
                struct chambre* a=adr_tetechlib(q);
                struct chambre* b=adr_tetechocc(q);
                supprimer_maillon(&a,s,r);
                aff_adr_chambreslib(q,a);
                inserer_maillon(&b,r);
                aff_adr_chambresocc(q,b);
                aff_datedeb(r,datedeb);
                aff_datefin(r,datefin);
                aff_nomclient(r,nom);
                aff_statutchambre(r,1);
                aff_nbchlibres(q,nb_chambresvides(q)-1);
                aff_nbchoccupes(q,nb_choccupes(q)+1);
                printf("********** ET VOILA C'EST FAIT ! BON SEJOUR ^^ **********");

                printf ("vous etes en chemin d'enregister votre reservation \n");



                printf("voulez vous contiuer ...... ? \n si oui entrez 1 \n si non entrez 0 \n");
                scanf("%d",&i);
                switch(i)
                {
                 case 1:
                 printf("\n suprer !! votre reservation sera enregistree \n ....................... ");

                 FILE* fich=fopen("mareservation.txt","w+");
                 fprintf(fich," ------------------------ *** votre reservation ***  ------------------------  \n chere %s \n voici les details de votre reservation \n NOM D'hotel : %s \n  date debut de reservation : %s   date fin de reservation : %s \n type chambre : %d \n numero de chambre : %d \n prix a payer : %d DA / par nuit \n NOTA : le paiement se fait au niveau de l'une de nos agences \n ----------------------------------------------------------------------------------------- \n ESI AGENCY  ALL RIGHTS RESEVED  2018 @\n",&nom,&nomhotel,&datedeb,&datefin,type_chambre(r),numch,prix_chambre(r));
                 printf("sauvegarde reussi vous trouvez le detail de votre reservation dans un fichier text mareservation.txt \n");
                 break;
                 case 0:
                 printf(" A bientot !! \n");
                 break;}

            }
            else{
                printf("La chambre que vous avez demande est deja prise");
            }
        }
        else{
            printf("Nous n'avons pas d'hotels de ce nom dans cette ville");
        }

    }
    else{
        printf("Le nom d'hotel que vous introduisez doit obligatoirement commencer par une lettre ");
    }
}

}


/**********************************************************
                    RECHERCHE VILLE
***********************************************************/
//Recherche de l'existance d'une ville dans un tableau
int recherche_tab_ville(char* tab[48],int tai,char ville[15]){
    //Declarations
    int exist=0;
    int j=0;
    //code
    if (tai!=0){
        while((exist==0)&&(j<tai)){
            if(strcasecmp(tab[j],ville)==0){exist=1;}
            j++;
        }
    }
    return exist;

}


/**********************************************************
                  TOUTES NOS VILLES
***********************************************************/
 // afficher toutes les villes que nouc avons sans repetitions

void toutes_nos_villes(struct lettre* t){
    //Declaration
    char* tab[48];
    char chaine[15];

    int tai=0;
    int exist=0;
    struct lettre* p=t;
    struct hotel* q=NULL;
    //code
    while(p!=NULL){
        q=adr_tetehotel(p);
        while(q!=NULL){
            if (tai!=0){
                exist=recherche_tab_ville(tab,tai,ville(q));//rechercher la ville dans le tableau de villes
                if( exist==0){ //si la ville n'existe pas deja on l'insere
                    tab[tai]=malloc(strlen(chaine)+1);
                    if(tab[tai]!=NULL){
                        strcpy(tab[tai],ville(q));
                        puts(tab[tai]);//afficher la ville
                        tai++;
                    }
                }
            }
            else{
                tab[0]=malloc(strlen(chaine)+1);
                if(tab[0]!=NULL){
                strcpy(tab[0],ville(q));
                puts(tab[tai]);
                tai++;
                }
            }
            q=suivant_hotel(q);
        }
        p=suivant_lettre(p);
    }

}

/**********************************************************
               MODIFIER RESERVATION
***********************************************************/
//Choix 5 du menu

void modifier_reservation(struct lettre* t, char nomclient[26]){

    /* declarations*/
    /***********************/
    /* lettre*/

    struct lettre* p=t;
    struct lettre* w=t;
    /***********************/
    /*hotel*/

    struct hotel* l=NULL;
    struct hotel* q=NULL;/*pour sauvegarder le maillon hotel qui contient la chmabre*/
    struct hotel* u=NULL;
    /***********************/
    /*chambre*/

    struct chambre* r=NULL;
    struct chambre* s=NULL;/*le precedent de r */
    struct chambre* lib=NULL;
    struct chambre* i=NULL;
    struct chambre* j=NULL;
    /***********************/
    /*boolean*/
    int trouve=0;//indique l'existance d'hotels ou pas
    int trouve1=0;//indique l'existance de la reservatiob
    int trouve2=0;//indique l'existance d'une nouvelle chambre libre avec le nouveau type voulu
    int trouve3=0;//indique l'existance d'un hotel avec le meme nom
    int trouve4=0;//indique l'existance d'un hotel qui se situe dans la ville introduite
    int found=0;//indique l'existance d'une nouvelle chambre libre avec le meme type

    /***********************/
    /*chaine/entiers*/

    int reponse;
    int choix;
    int jourf,moisf,anneef,jourd,moisd,anneed;
    char newdatedeb[11];
    char newdatefin[11];
    int newtype=0;
    int newnum=0;
    char newnom[25]="";
    char newhotel[15]="";
    char newville[15]="";






    while ((p!=NULL)&&(trouve1==0)){
        l=adr_tetehotel(p);
        while ((l!=NULL)&&(trouve1==0)){
            trouve=1;
            r=adr_tetechocc(l);
            while((r!=NULL)&&(trouve1==0)){
                if(strcasecmp(nom_client(r),nomclient)==0){
                    trouve1=1;
                }
                else{
                    s=r;
                    r=suivant_chambre(r);
                }
            }
            q=l;
            l=suivant_hotel(l);
        }
        p=suivant_lettre(p);
    }
    if(trouve==1){
    if(r!=NULL){
        printf("\nQue voulez vous modifier\n");
        printf("\n1/-Les dates de reservation\n");
        printf("\n2/-Le type de chambre\n");
        printf("\n3/-Changer de nom de reservation\n");
        printf("\n4/-Changer de numero de chambre\n");
        printf("\n5/-Changer d'hotel\n");
        printf("\n6/-Changer de ville\n");
        printf("\nIntroduisez le numero de votre choix (1,2,3,4,5,6):");
        scanf("%d",&choix);
        switch(choix){
        case 1:
            printf("Voulez vous changer : \n 1/-La date de debut seulement.\n 2/-Changer la date de fin seulement. \n 3/-Changer les deux.\n");
            scanf("%d",&reponse);
            switch(reponse){
               case 1:
                   printf("Entez la nouvelle date debut : ");
                   scanf("%s",newdatedeb);
                   if(verif_date(newdatedeb,datefin(r))==1){
                      aff_datedeb(r,newdatedeb);
                   }

               break;
               case 2:
                   printf("Entez la nouvelle date de fin : ");
                   scanf("%s",newdatefin);
                   if(verif_date_fin(newdatefin)==1){
                        aff_datefin(r,newdatefin);
                   }
               break;
               case 3:
                   printf("Entez la nouvelle date debut : ");
                   scanf("%s",newdatedeb);
                   printf("\nEntez la nouvelle date fin : ");
                   scanf("%s",newdatefin);
                   if(verif_date(newdatedeb,newdatefin)==1){
                        aff_datedeb(r,newdatedeb);
                        aff_datefin(r,newdatefin);
                   }

               break;
               default:
                   printf("Les numeros de choix sont 1/2/3 revenez au menu et reesayez !");


            }

        break;
        case 2:
                if(type_chambre(r)==1){newtype=2;}
                else{newtype=1;}
                lib=adr_tetechlib(q);
                while((lib!=NULL)&&(trouve2==0)){
                    if(type_chambre(lib)==newtype){
                        trouve2=1;
                    }
                    else{
                        lib=suivant_chambre(lib);
                    }
                }
                if(lib!=NULL){
                    i=adr_tetechlib(q);
                    j=adr_tetechocc(q);

                    aff_nomclient(lib,nom_client(r));
                    aff_datedeb(lib,datedeb(r));
                    aff_datefin(lib,datefin(r));
                    aff_statutchambre(lib,1);
                    supprimer_maillon(&j,s,r);
                    aff_adr_chambresocc(q,j);
                    inserer_maillon(&i,r);
                    aff_adr_chambreslib(q,i);
                    inserer_maillon(&j,lib);
                    aff_adr_chambresocc(q,j);
                    printf("Votre nouveau numero de chambre est : %d\n",num_chambre(lib));
                    printf("Le nouveau pris est : %d\n",prix_chambre(lib));
                    if(newtype==1){printf("Vous aurez à rejouter %d DA pour le prix initiale que vous avez paye\n ",(prix_chambre(lib)-prix_chambre(r)));}
                    else{printf("Nous vous renderons le reste de votre argent :%d à la fin de votre sejour\n",(prix_chambre(r)-prix_chambre(lib)));}
                }
                else{
                    printf("il ne reste plus aucune chambre du type que vous cherchez\n");

                }
                break;
        case 3:
            printf("introduisez le nouveau nom :\n");
            scanf("%s",&newnom);
            aff_nomclient(r,newnom);
            printf("Eh voila! c'est fait :)");
            break;
        case 4:
            lib=adr_tetechlib(q);
            while(lib!=NULL){
                    if(type_chambre(lib)==type_chambre(r)){
                        printf(" La chambre numero: %d",num_chambre(lib));
                        found=1;
                    }
                    lib=suivant_chambre(lib);

            }
            if(found==1){
                i=adr_tetechlib(q);
                j=adr_tetechocc(q);

                printf("\n Nous allons vous demander maintenant de retenir le numero de chambre que vous voulez pour reinserer une reservation \n");
                printf("alors vous avez choisis la numéro :");
                scanf("%d",&newnum);
                inserer_reservation(t,nom_hotel(q),nom_client(r),ville(q),newnum,datedeb(r),datefin(r));

                supprimer_maillon(&j,s,r);
                aff_adr_chambresocc(q,j);
                inserer_maillon(&i,r);
                aff_adr_chambreslib(q,i);
                printf("c'est bon c'est fait !");


            }
            else{
                printf("Nous sommes desoles mais il ne nous reste plus de chambre libre du type que vous demandez si vous desirer changer de type revenez au menu et changer de type de chambre \n");
            }

        break;

        case 5:
            printf("Voici la liste des hotels que nous avons a vous proposer :\n");
            /*while((w!=NULL)){
                u=adr_tetehotel(w);
                while(u!=NULL){
                    printf("Hotel: %s a %s\n",nom_hotel(u),ville(u));
                    u=suivant_hotel(u);
                }
                w=suivant_lettre(w);
            }*/
            afficher_listhotel(t);
            printf("\nRetenez bien le nom de l'hotel que vous avez choisis et sa ville \n");
            printf("c'est bon le choix est fait!! alors commancant par l'Hotel :");
            scanf("%s",&newhotel);
            printf("Et maintenant la ville : ");
            scanf("%s",&newville);
            trouve3=recherche_hotel(t,type_chambre(r),newhotel);
            if(trouve3==1){

                i=adr_tetechlib(q);
                j=adr_tetechocc(q);
                supprimer_maillon(&j,s,r);
                aff_adr_chambresocc(q,j);
                inserer_maillon(&i,r);
                aff_adr_chambreslib(q,i);

                printf("Nous allons vous demander maintenant de retenir le numero de chambre :");
                scanf("%d",&newnum);
                inserer_reservation(t,newhotel,nom_client(r),newville,newnum,datedeb(r),datefin(r));


            }
            break;

            case 6:
                printf("Voici la liste des villes que nous avons à vous proposer :\n");
                toutes_nos_villes(t);
                printf("Retenez bien le nom de la ville que vous voulez et introsuisez la ici :");
                scanf("%s:",&newville);
                trouve4=recherche_ville(t,newville,type_chambre(r));
                if(trouve4==1){
                    printf("\nNous allons vous demander maintenant de retenir le numero de chambre et le nom de l'hotel que vous avez choisi\n");
                    printf("le nom de l'hotel que vous avez choisis svp :");
                    scanf("%s",&newhotel);
                    printf("\nle numero de chambre maintenant svp :");
                    scanf("%d",&newnum);
                    i=adr_tetechlib(q);
                    j=adr_tetechocc(q);
                    supprimer_maillon(&j,s,r);
                    aff_adr_chambresocc(q,j);
                    inserer_maillon(&i,r);
                    aff_adr_chambreslib(q,i);
                    inserer_reservation(t,newhotel,nom_client(r),newville,newnum,datedeb(r),datefin(r));
                }
                break;

            default :
                printf("de 1 à 5 ce sont tous les choix que nous pouvions vous proposer si vous voulez autre chose supprimer votre reservation puis recherchez une autren\n");
                break;



          }
        }
        else{
            printf("Nous n'avons pas de reservation de ce nom pour qu'elle soit modifiee\n");
        }
    }
    else{printf("Vos listes ne contiennent aucun hotel");}


}

/*************************************************************************
                INSERER UN NOUVEL HOTEL
*************************************************************************/
//partie du module inserer un nouvel hotel

void inserer_hotel(struct hotel** t,struct hotel* r){
    //Declarations
    struct hotel* p=*t;
    struct hotel* s=NULL;
    int trouve=0;

    //Code

    while((p!=NULL)&&(trouve==0)){
        if(strcasecmp(nom_hotel(p),nom_hotel(r))<=0){
            s=p;
            p=suivant_hotel(p);
        }
        else{
            trouve=1;
        }
    }
    if(s!=NULL){
        affadr_hotel(s,r);
        affadr_hotel(r,p);
    }
    else{
        affadr_hotel(r,p);
        (*t)=r;
    }
}


/***********************************************************************
                  CREER LISTE CHAMBRES LIBRES
************************************************************************/
//creer liste chambres libres pour un nouvel hotel
struct chambre* creer_liste_cblibre(int nb_chambre,int prixa1, int prixa2){
    //declaration
    struct chambre* p=NULL;
    struct chambre* q=NULL;
    struct chambre* tete=NULL;
    int i=1;
    int j=1;
    //Code
    if (nb_chambre>0){
        p=allouer_chambre();
        affadr_chambre(p,NULL);
        aff_nb_chambre(p,i);
        aff_statutchambre(p,0);
        aff_datedeb(p,"");
        aff_datefin(p,"");
        aff_nomclient(p,"");
        aff_typechambre(p,1);
        aff_prixchambre(p,prixa1);
        i++;
        tete=p;
        for(j=1;j<=((nb_chambre-1)/2);j++){
            q=allouer_chambre();
            affadr_chambre(q,NULL);
            aff_nb_chambre(q,i);
            aff_statutchambre(q,0);
            aff_datedeb(q,"");
            aff_datefin(q,"");
            aff_nomclient(q,"");
            aff_typechambre(q,1);
            aff_prixchambre(q,prixa1);
            affadr_chambre(p,q);
            p=q;
            i++;
        }
         for(j=((nb_chambre+1)/2);j<nb_chambre;j++){
            q=allouer_chambre();
            affadr_chambre(q,NULL);
            aff_nb_chambre(q,i);
            aff_statutchambre(q,0);
            aff_datedeb(q,"");
            aff_datefin(q,"");
            aff_nomclient(q,"");
            aff_typechambre(q,2);
            aff_prixchambre(q,prixa2);
            affadr_chambre(p,q);
            p=q;
            i++;
        }

    }
    return tete;

}

/**********************************************************************
            INTROSUIRE NOUVEL hotel
***********************************************************************/
//CHOIX 9 DU MENU

void introduire_nouvel_hotel(struct lettre* t,char nomhotel[],char nomville[],int nbchambre,int prixa1,int prixa2){
    struct lettre*p=t;
    struct hotel* q=NULL;
    struct hotel* w=NULL;
    struct hotel* u=NULL;

    char letr;
    int trouve1=0;
    int trouve2=0;

    letr=toupper(nomhotel[0]);
    while ((p!=NULL)&&(trouve1==0)){
        if(letr==lettre(p)){
            trouve1=1;
        }
        else{
            p=suivant_lettre(p);
        }
    }
    if(p!=NULL){
        q=adr_tetehotel(p);
        w=q;

        while((w!=NULL)&&(trouve2==0)){
            if((strcasecmp(nom_hotel(w),nomhotel)==0)&&(strcasecmp(ville(w),nomville)==0)){
               trouve2=1;
            }
            else{
                w=suivant_hotel(w);
            }
        }
        if(w==NULL){
            u=allouer_hotel();
            affadr_hotel(u,NULL);
            aff_nb_chambre(u,nbchambre);
            aff_nbchlibres(u,nbchambre);
            aff_nbchoccupes(u,0);
            aff_adr_chambresocc(u,NULL);
            aff_adr_chambreslib(u,creer_liste_cblibre(nbchambre,prixa1,prixa2));
            aff_prixhotel1(u,prixa1);
            aff_prixhotel2(u,prixa2);
            aff_nomhotel(u,nomhotel);
            aff_nomville(u,nomville);
            inserer_hotel(&q,u);
            aff_adrtetehotel(p,q);
        }
        else{
            printf("Cet hotel existe deja dans nos listes!!");
        }

    }
    else{
        printf("le nom que vous avez introduit n'est pas valide\n");
    }

}

/***********************************************************************
           TRIER LE LISTE DES HOTELS PAR ORDRE ALPHABETIQUE
************************************************************************/
//CHOIX 12 DU MENU

void tri_bulles(struct hotel** t){
    //Declaration
    int triee=0;
    struct hotel* p=NULL;
    struct hotel* q=NULL;
    struct hotel* s=NULL;
     //Code
    if((*t)!=NULL){
        triee=0;
        while(triee==0){
            triee=1;
            p=(*t);
            q=suivant_hotel(p);
            while(q!=NULL){
                if(strcasecmp(nom_hotel(p),nom_hotel(q))>0){
                    /***************************/
                    s=allouer_hotel();
                    aff_nomhotel(s,nom_hotel(p));
                    aff_nomville(s,ville(p));
                    aff_nbchambres(s,nb_chambres(p));
                    aff_nbchlibres(s,nb_chambresvides(p));
                    aff_nbchoccupes(s,nb_choccupes(p));
                    aff_adr_chambreslib(s,adr_tetechlib(p));
                    aff_adr_chambresocc(s,adr_tetechocc(p));
                    aff_prixhotel1(s,prix_hotel1(p));
                    aff_prixhotel2(s,prix_hotel2(p));
                    /******************************/
                    aff_nomhotel(p,nom_hotel(q));
                    aff_nomville(p,ville(q));
                    aff_nbchambres(p,nb_chambres(q));
                    aff_nbchlibres(p,nb_chambresvides(q));
                    aff_nbchoccupes(p,nb_choccupes(q));
                    aff_adr_chambreslib(p,adr_tetechlib(q));
                    aff_adr_chambresocc(p,adr_tetechocc(q));
                    aff_prixhotel1(p,prix_hotel1(q));
                    aff_prixhotel2(p,prix_hotel2(q));
                    /********************************/
                     aff_nomhotel(q,nom_hotel(s));
                    aff_nomville(q,ville(s));
                    aff_nbchambres(q,nb_chambres(s));
                    aff_nbchlibres(q,nb_chambresvides(s));
                    aff_nbchoccupes(q,nb_choccupes(s));
                    aff_adr_chambreslib(q,adr_tetechlib(s));
                    aff_adr_chambresocc(q,adr_tetechocc(s));
                    aff_prixhotel1(q,prix_hotel1(s));
                    aff_prixhotel2(q,prix_hotel2(s));
                    /*******************************************/
                    triee=0;

                }
                p=suivant_hotel(p);
                q=suivant_hotel(q);
            }
        }
    }

}
/*********************************************
                DATE LIMITE
*********************************************/
//CHOIX 11 DU MENU

void date_fini(struct lettre* t){
    //DECLARATIONS
    struct lettre* p=t;
    struct hotel* q=NULL;
    struct chambre* r=NULL;
    struct chambre* precedent=NULL;
    struct chambre* occ=NULL;
    struct chambre* lib=NULL;
    struct chambre* intermediaire=NULL;
    int jour;
    int mois;
    int annee;
    //CODE

    SYSTEMTIME temps;
	GetSystemTime(&temps);

	while(p!=NULL){
        q=adr_tetehotel(p);
        while(q!=NULL){
           occ=adr_tetechocc(q);
           lib=adr_tetechlib(q);
           r=occ;
            while(r!=NULL){
              sscanf(datefin(r),"%d/%d/%d",&jour,&mois,&annee);
              if((temps.wYear=annee)&&(temps.wMonth==mois)&&(temps.wDay==jour)){

                intermediaire=suivant_chambre(r);
                supprimer_maillon(&occ,precedent,r);
                aff_adr_chambresocc(q,occ);
                inserer_maillon(&lib,r);
                aff_adr_chambreslib(q,lib);
                r=intermediaire;

              }

              else{
                precedent=r;
                r=suivant_chambre(r);
              }
            }
            q=suivant_hotel(q);
        }
        p=suivant_lettre(p);
	}
}



/*************************************
  RECHERCHE DE RESERVATION PAR NOM
**************************************/
//CHOIX 8 DU MENU

void recherche_reservetion(struct lettre* t,char nomclient[]){
    //DECLARATIONS

    struct lettre* p=t;
    struct hotel* q=NULL;
    struct hotel* l=NULL;
    struct chambre* r=NULL;
    char type[20];
    int trouve=0;
    //CODE


    while ((p!=NULL)&&(trouve==0)){
        l=adr_tetehotel(p);
        while ((l!=NULL)&&(trouve==0)){
            r=adr_tetechocc(l);
            while((r!=NULL)&&(trouve==0)){
                if(strcasecmp(nom_client(r),nomclient)==0){
                    trouve=1;
                }
                else{
                    //s=r;
                    r=suivant_chambre(r);
                }
            }
            q=l;
            l=suivant_hotel(l);
        }
        p=suivant_lettre(p);
    }
    if(r!=NULL){
        printf("---------------------reservation---------------------------\n");
        printf(" Nom : %s \n",nom_client(r));
        printf(" Hotel : %s   Ville : %s \n",nom_hotel(q),ville(l));
        if(type_chambre(r)==1){strcpy(type,"Individuelle") ;}
        else{strcpy(type,"A deux");}
        printf("Type de reservation : %s\n",type);
        printf("Date debut de reservation : %s\n",datedeb(r));
        printf("Date fin de reservation : %s\n",datefin(r));
        printf("Prix de la chambre : %d\n",prix_chambre(r));
        printf("-----------------------------------------------------------\n");
        printf("----------------------Et voila! :)-------------------------");
    }
    else{
        printf("Nous somme desolES mais votre nom n'apparait pas sur nos listes de reservation\n");
    }
}


      /**********************************************************************************************************************************************/
                                                /**********************************************
                                                                //LES FIHIERS
                                                ***********************************************/
       /**********************************************************************************************************************************************/





                         /*********************************************************************************************************
                                          CREATION DES QUATRE LISTES IMPOSEES ET L'AFFICHAGE DE LEURS CONTENU
                         **********************************************************************************************************/



/**********************************************
           CREER L'ANNUAIRE
**********************************************/
//CREER LA PREMIERE LISTE DE L'ANNUAURE

void creer_listlettre(struct lettre** tetelettre)
{
    char i=65;
    struct lettre* p;
     struct lettre* q=NULL;
     p=allouer_lettre();
     *tetelettre=p;
     affadr_lettre(p,NULL);
     aff_lettre(p,i);
     for (i=66;i<91;i++)
     {
         q=p;
         p=allouer_lettre();
         affadr_lettre(q,p);
         affadr_lettre(p,NULL);
         aff_lettre(p,i);
     }
};


/***************************************************
          CREER LA LISTE DES HOTELS
****************************************************/


void creer_listhotel (struct lettre* tete){
     int capacite,chlib,chocc,prix1,prix2;
    int cpt=1;
    char nomhotel[26];
    char vil[26];
    struct lettre* r;
    struct hotel* p;
    struct hotel* w;

    r=tete;
    while (r!=NULL)
    {
      FILE* fich=fopen("hotels.txt","r+");
     while (fscanf(fich,"%s %s %d %d %d %d %d",&nomhotel,&vil,&capacite,&chlib,&chocc,&prix1,&prix2)!=EOF)
       {
        if (nomhotel[0]==r->letr)
        { if (cpt==1)
           {
              p=allouer_hotel();
              aff_adrtetehotel(r,p);
              aff_nomhotel(p,nomhotel);
              aff_nomville(p,vil);
              aff_nbchambres(p,capacite);
              aff_nbchlibres(p,chlib);
              aff_nbchoccupes(p,chocc);
              aff_prixhotel1(p,prix1);
              aff_prixhotel2(p,prix2);
              aff_adr_chambreslib(p,NULL);
              aff_adr_chambresocc(p,NULL);
              affadr_hotel(p,NULL);
              // printf("%s %s %d %d %d %d %d %p %p \n",nom_hotel(p),ville(p),nb_chambres(p),nb_chambresvides(p),nb_choccupes(p),prix_hotel1(p),prix_hotel2(p),p,suivant_hotel(p));
              cpt=cpt+1;
           }
           else
            {   //printf("%s %s %d %d %d %d %d %p %p \n",nom_hotel(p),ville(p),nb_chambres(p),nb_chambresvides(p),nb_choccupes(p),prix_hotel1(p),prix_hotel2(p),p,suivant_hotel(p));
              w=allouer_hotel();
              aff_nomhotel(w,nomhotel);
              aff_nomville(w,vil);
              aff_nbchambres(w,capacite);
              aff_nbchlibres(w,chlib);
              aff_nbchoccupes(w,chocc);
              aff_prixhotel1(w,prix1);
              aff_prixhotel2(w,prix2);
              aff_adr_chambreslib(w,NULL);
              aff_adr_chambresocc(w,NULL);
              affadr_hotel(w,NULL);
              affadr_hotel(p,w);
              p=w;
              cpt=cpt+1;
            }
        }
       }
      r=suivant_lettre(r);
      cpt=1;
     fclose(fich);
    }

};


/***********************************************************************
    CREER UNE LISTE DE CHAMBRE LIBRE POUR REMPLIR LES LISTES D'HOTELS
***********************************************************************/


void creer_listchambreslibres (struct lettre* tete){
     struct hotel* p;
  struct chambre* q;
  struct chambre* v;
  int prix,type,numch,cpt=1;
  char nomhotel[26];

  while (tete!=NULL)
  {p=adr_tetehotel(tete);
   while (p!=NULL)
   {  FILE* fichier=fopen("chambresvides.txt","r+");
   while (fscanf(fichier,"%s %d %d %d",&nomhotel,&numch,&type,&prix)!=EOF)
      { if (strcasecmp(nomhotel,p->nomhotel)==0)
          { if (cpt==1)
             { q=allouer_chambre();
               aff_adr_chambreslib(p,q);
               aff_nb_chambre(q,numch);
               aff_typechambre(q,type);
               aff_prixchambre(q,prix);
               affadr_chambre(q,NULL);
               aff_statutchambre(q,0);
               v=q;
               cpt=cpt+1;
             }
             else
             {q=allouer_chambre();
               aff_nb_chambre(q,numch);
               aff_typechambre(q,type);
               aff_prixchambre(q,prix);
               affadr_chambre(v,q);
               affadr_chambre(q,NULL);
               aff_statutchambre(q,0);
               v=q;
               cpt=cpt+1;
             }
          }
      }
     p=suivant_hotel(p);
     cpt=1;
     fclose(fichier);
   }
  tete=suivant_lettre(tete);
  }

};


/****************************************
      AFFICHER LISTE DE CHAMBRE VIDES
*****************************************/


void afficher_listchambresvides(struct lettre* tetelettre){
    struct hotel* p;
    struct chambre* q;
    while (tetelettre!=NULL)
    {  p=adr_tetehotel(tetelettre);
      while(p!=NULL)
      { q=adr_tetechlib(p);
       printf("\n-----------------------------------\n HOTEL : *** %s ***  a * %s *\n-----------------------------------\n\n****************************\n",nom_hotel(p),ville(p));
       while(q!=NULL)
       {
         printf("* num chambre : %d  statut : libre  type : %d   prix : %d DA  *\n ---------------------------------------------------------------- \n ",num_chambre(q),type_chambre(q),prix_chambre(q));
         q=suivant_chambre(q);
       }
        p=suivant_hotel(p);
      }
     tetelettre=suivant_lettre(tetelettre);
    }
};


/***********************************************
          AFFICHER LISTE DES HOTELS
************************************************/


void afficher_listhotel (struct lettre* tetelettre){
    struct hotel* p;
    while (tetelettre!=NULL)
     { printf(" \n------------------------------------------\n la lettre : %c\n----------------------\n",lettre(tetelettre));
       p=tetelettre->hot;
       while (p!=NULL)
       {
           printf("Nom hotel :%s   Ville: %s  prix de chambres : Individuelles : %d  A deux : %d \n",nom_hotel(p),ville(p),prix_hotel1(p),prix_hotel2(p));
           p=suivant_hotel(p); }
      tetelettre=suivant_lettre(tetelettre);
     }

    };


/***********************************************
      CREER LISTE DES CHAMBRES OCCUPEES
***********************************************/

void creer_listechabreocc(struct lettre * tetelettre){
 struct hotel* p;
 struct chambre* q;
 struct chambre* v;
 char nomhotel[26],datedebut[15],datef[15],nomclient[26];
 int type,prix,numchmb,cpt=1;

 while (tetelettre!=NULL)
 {p=tetelettre->hot;
  while (p!=NULL)
  {  FILE* fich=fopen("reservations.txt","r+");
    while (fscanf(fich,"%s %d %d %s %s %s %d",&nomhotel,&numchmb,&type,&datedebut,&datef,&nomclient,&prix)!=EOF)
      //printf("%s %d %d %s %s %s %d \n",nomhotel,numchmb,type,datedebut,datefin,nomclient,prix);
    { if (strcasecmp(p->nomhotel,nomhotel)==0)
    { if (cpt==1)
      {
       q=allouer_chambre();
        aff_adr_chambresocc(p,q);
        aff_nomclient(q,nomclient);
        aff_typechambre(q,type);
        aff_nb_chambre(q,numchmb);
        aff_datedeb(q,datedebut);
        aff_datefin(q,datef);
        aff_prixchambre(q,prix);
        aff_statutchambre(q,1);
        affadr_chambre(q,NULL);
        cpt=cpt+1;
        v=q;
     //printf("num chambre :%d type : %d statut : occupe date deb : %s date fin : %s  nom client : %s prix : %d ",num_chambre(q),type_chambre(q),q->datdeb,q->datefin,q->nom,q->prix);

      }
      else
      { //printf("mchit \n");
        q=allouer_chambre();
        affadr_chambre(v,q);
        affadr_chambre(q,NULL);
        aff_nb_chambre(q,numchmb);
        aff_typechambre(q,type);
        aff_datedeb(q,datedebut);
        aff_datefin(q,datef);
        aff_nomclient(q,nomclient);
        aff_prixchambre(q,prix);
        aff_statutchambre(q,1);
        v=q;
        cpt=cpt+1;
         //printf("num chambre :%d type : %d statut : occupe date deb : %s date fin : %s  nom client : %s prix : %d ",num_chambre(q),type_chambre(q),q->datdeb,q->datefin,q->nom,q->prix);

      }

    }

    }
    p=suivant_hotel(p);
    cpt=1;
    fclose(fich);
  }
 tetelettre=suivant_lettre(tetelettre);
 }
};

/******************************************************
         AFFICHER LISTE DES CHAMBRES OCCUPEES
******************************************************/

void afficher_listchambresocc(struct lettre* tetelettre){
    struct hotel* p;
    struct chambre* q;
    while(tetelettre!=NULL)
    {
      p=adr_tetehotel(tetelettre);

      while(p!=NULL)
      { printf("-----------------------\n *** %s *** \n---------------------------------- \n *************************************************** \n",p->nomhotel);
        q=adr_tetechocc(p);
        while(q!=NULL)
        {
            printf("* num chambre :%d type : %d statut : occupe date deb : %s date fin : %s  nom client : %s prix : %d DA *\n --------------------------------------------------------------------------- \n",num_chambre(q),type_chambre(q),datedeb(q),datefin(q),nom_client(q),prix_chambre(q));
            q=suivant_chambre(q);
        }
         p=suivant_hotel(p);
      }
     tetelettre=suivant_lettre(tetelettre);
    }
};





                                            /*******************************************************
                                                    LA SAUVEGARDE CHOIX 2 DU MENU IMPOSé
                                            ********************************************************/


/********************************************************
   SAUVEGARDER LA LISTE DES HOTELS DANS UN FICHIER
********************************************************/

void sauvegarder_listhotel(struct lettre* tete)
{
  struct hotel* p;

  FILE* fich=fopen("newhotels.txt","w+");

 while (tete!=NULL){
   p=adr_tetehotel(tete);
   while (p!=NULL)
     {
        fprintf(fich,"%s %s %d %d %d %d %d\n",nom_hotel(p),ville(p),nb_chambres(p),nb_chambresvides(p),nb_choccupes(p),prix_hotel1(p),prix_hotel2(p));
        p=suivant_hotel(p);
     }
 tete=suivant_lettre(tete);
 }
 fclose(fich);};

 /********************************************************
     SAUVEGARDER LES RESERVATION DANS UN FICHIER
 ********************************************************/

void sauvegarder_resrvation (struct lettre* tete){
    struct hotel* p;
  struct chambre* q;

 FILE* fich=fopen("newreservations.txt","w+");

 while(tete!=NULL){
  p=adr_tetehotel(tete);
  while(p!=NULL)
  {
    q=adr_tetechocc(p);
    while (q!=NULL)
    {
      fprintf(fich,"%s %d %d %s %s %s %d\n",nom_hotel(p),num_chambre(q),type_chambre(q),datedeb(q),datefin(q),nom_client(q),prix_chambre(q));
      q=suivant_chambre(q);
    }
    p=suivant_hotel(p);
  }
    tete=suivant_lettre(tete);
 }
 fclose(fich);}


/*****************************************************************
        SAUVEGARDER LA LISTE DES CHAMBRE LIBRES DANS UN FICHIER
******************************************************************/


void sauvegarder_chambresvides (struct lettre* tete){
  struct hotel* p;
  struct chambre* q;

 FILE* fichier=fopen("newchambresvides.txt","w+");
 while(tete!=NULL)
 { p=adr_tetehotel(tete);
  while(p!=NULL)
  {
      q=adr_tetechlib(p);
      while (q!=NULL)
        {
            fprintf(fichier,"%s %d %d %d\n",nom_hotel(p),num_chambre(q),type_chambre(q),prix_chambre(q));
            q=suivant_chambre(q);
        }
        p=suivant_hotel(p);
  }
  tete=suivant_lettre(tete);
 }
};


/*************************************************
            PROBLEME DE DATES
*************************************************/
//BONUS

/**************************************************
       COMPARER DATE FIN ET DATE DEBUT
/*************************************************/

//ELLE RENVOIE VRAI SI LA DATE FIN SE TROUVE APRES LA DATE DEBUT ET FAUX SINON
//EN PRENANT EN CONSIDERANTION LES INTERVALLES DES JOURS/MOIS
 int cmp_df(char datedebut[],char datef[]){

 int correct=0;
 int jourf,moisf,anneef,jourd,moisd,anneed;
 sscanf(datedebut,"%d/%d/%d",&jourd,&moisd,&anneed);
 sscanf(datef,"%d/%d/%d",&jourf,&moisf,&anneef);


    if(anneed<=anneef){
        if(anneed==anneef){
            if(moisd<=moisf){
                if((moisd==moisf)&&(moisf>=1)&&(moisf<=12)){
                    if((jourd<=jourf)&&(jourf<=31)&&(jourf>=1)){correct=1;}
                    else{printf("Une erreur a ete signale par rapport au deux dates introduites revenez au menu pour reesayer!\n");}
                }
                else{if((moisf>=1)&&(moisf<=12)&&(jourf<=31)&&(jourf<=31)){correct=1;}else{printf("Une erreur a ete signale par rapport au deux dates introduites revenez au menu pour reesayer!\n");}}
            }
            else{printf("Une erreur a ete signalé par rapport au deux dates introduites revenez au menu pour reesayer!\n");}
        }
        else{ if((moisf>=1)&&(moisf<=12)&&(jourf<=31)&&(jourf<=31)){correct=1;}else{printf("Une erreur a ete signalé par rapport au deux dates introduites revenez au menu pour reesayer!\n");}}

    }
    else{printf("Une erreur a ete signalé par rapport au deux dates introduites revenez au menu pour reesayer!\n");}

    return correct;
 }


/************************************************
     COMPARAISON ETRE DATES DEBUT ET FIN
/************************************************/
//PARTIE DU  MODULE DU CHOIX 5 DU MENU
//IL IMPOSE :
//DATE DEBUT>=DATE D'AUJOURDUIT
//DATE FIN >= DATE DEBUT
//PRENDRE EN CONSIDERATION LES INTERVALES DE JOURS ET MOIS



int verif_date(char newdatedeb[],char newdatef[]){
    int juste=0;
    int jourf,moisf,anneef,jourd,moisd,anneed;

    SYSTEMTIME today;
    GetSystemTime(&today);
    sscanf(newdatedeb,"%d/%d/%d",&jourd,&moisd,&anneed);
    sscanf(newdatef,"%d/%d/%d",&jourf,&moisf,&anneef);


    if(today.wYear<=anneed){
        if(today.wYear==anneed){
            if(today.wMonth<=moisd){
                if((today.wMonth==moisd)&&(moisd>=1)&&(moisd<=12)){
                    if((today.wDay<=jourd)&&(jourd<=31)&&(jourd>=1)){
                        if(cmp_df(newdatedeb,newdatef)==1){
                           juste=1;
                        }
                    }
                    else{printf("La/les date(s) que vous avez introduit est/sont erronee\n");}
                }
                else{
                    if((moisd>=1)&&(moisd<=12)&&(jourd<=31)&&(jourd>=1)){
                     if(cmp_df(newdatedeb,newdatef)==1){
                       juste=1;
                    }
                    }
                    else{printf("La/les date(s) que vous avez introduit est/sont erronee\n");}
                }
            }
            else{printf("La/les date(s) que vous avez introduit est/sont erronee\n");}
        }
        else{
            if((moisd>=1)&&(moisd<=12)&&(jourd<=31)&&(jourd>=1)){
                if(cmp_df(newdatedeb,newdatef)==1){
                    juste=1;
                }
            }
            else{printf("La/les date(s) que vous avez introduit est/sont erronee \n");}
        }


    }
    else{printf("La/les date(s) que vous avez introduit est/sont erronee\n");}
    return juste;
}
/*************************************************************
           VERIFIER LA DATE FIN
/************************************************************/
//CHOIX DE MODIFIER LA DATE FIN
int verif_date_fin(char newdatef[]){
    int jourf,moisf,anneef,juste;

    SYSTEMTIME today;
    GetSystemTime(&today);
    sscanf(newdatef,"%d/%d/%d",&jourf,&moisf,&anneef);


    if(today.wYear<=anneef){
        if(today.wYear==anneef){
            if(today.wMonth<=moisf){
                if((today.wMonth==moisf)&&(moisf>=1)&&(moisf<=12)){
                    if((today.wDay<=jourf)&&(jourf<=31)&&(jourf>=1)){
                         juste=1;
                        }
                    else{printf("La date fin que vous avez introduit est erronee\n");}
                }
                else{
                    if((moisf>=1)&&(moisf<=12)&&(jourf<=31)&&(jourf>=1)){
                      juste=1;
                    }
                    else{printf("La date fin que vous avez introduit est erronee\n");}
                }
            }
            else{printf("La date fin que vous avez introduit est erronee\n");}
        }
        else{
            if((moisf>=1)&&(moisf<=12)&&(jourf<=31)&&(jourf>=1)){
                  juste=1;
                }
            else{printf("La date fin que vous avez introduit est erronee \n");}
        }


    }
    else{printf("La date fin que vous avez introduit est erronee\n");}
    return juste;
}






/**********************************************
     LIBERER TOUTES LES LISTES
***********************************************/
/***************************************************************************************/
//avant de quiter le programme il faut s'assurer de tout liberer

void liberer_tout(struct lettre** t){
         struct lettre* letr=*t;
         struct hotel* hot=NULL;
         struct chambre* lib=NULL;
         struct chambre* occ=NULL;

         while((*t)!=NULL){
            letr=*t;
            hot=adr_tetehotel(letr);
            while(hot!=NULL){
                lib=adr_tetechlib(hot);
                occ=adr_tetechocc(hot);
                liberer_list(&lib);
                liberer_list(&occ);
                /***********/
                aff_adrtetehotel(letr,suivant_hotel(hot));
                free(hot);
                hot=NULL;
            }
            (*t)=suivant_lettre((*t));
            free(letr);
            letr=NULL;
         }

     }

/*****************************************************************************************************************************/
/************************************* GRAPHIQUE  *******************************************/
/*****************************************************************************************************************************/
void style(){
    // titre de la fenetre
    SetConsoleTitle(" ESI AGENCY");
    system("mode con cols=200 lines=500");
    system("color BB");
    textcolor(BLACK);
}
/*****************************************************************************************************************************/
void page_acceuil(int opt){
    textcolor(BLACK);
    textbackground(15);
	int i,x=120,y=10;
    for(i = 1;i<=170;i++) {
        gotoxy(i,35);
        delay(opt);
    	printf("%c\n",'*');
	}
	for(i = 1;i<=170;i++) {
        gotoxy(i,39);
        delay(opt);
    	printf("%c\n",'*');
	}
    for(i = 1;i<=35;i++) {
    	gotoxy(10,i);
    	delay(opt);
    	if (i == 35) printf("%c\n",'*');
    	else printf("%c\n", '*');
	}

	for(i = 1;i<=35;i++) {
    	gotoxy(100,i);
    	delay(opt);
    	if (i == 35) printf("%c\n",'*');
    	else printf("%c\n", '*');
	}
textcolor(BLACK);
	textbackground(15);
	gotoxy(19,7);
	printf("**************************************   ESI       AGENCY  *******************");
	gotoxy(20,11);
	printf("    REALISEE PAR :    ");
	gotoxy(20,13);
	printf("*** MECHOUAR FELLA ***");
	gotoxy(20,15);
	printf("*** BEDDEK LILYA ***");
	gotoxy(19,18);
	printf("****************************************************************************");
	gotoxy(20,20);
	printf("GROUPE  :  10 ");
	gotoxy(20,22);
	printf("SECTION :  C");
	gotoxy(19,24);
	printf("***************************************************************************");
	delay(opt*2);
	gotoxy(19,26);
	printf("           ENCADRE PAR :                 ");
	gotoxy(19,29);
	printf("*** Mme.KACET SABRINA ***");
	gotoxy(13,37);
	delay(opt*2);
	printf("ESI 2017/2018");
    gotoxy(41,35);

	delay(opt);
	printf("%c",'*');
	delay(opt);
	gotoxy(41,36);
	delay(opt);
	printf("%c",'*');
	gotoxy(41,37);
	delay(opt);
	printf("%c",'*');
	gotoxy(41,38);
	delay(opt);
	printf("%c",'*');
	gotoxy(41,39);
	delay(opt);
	printf("%c",'*');
	textcolor(BLACK);
	textbackground(15);
    gotoxy(135,20);
    printf("ECOLE NATIONALE SUPERIEUR");
    gotoxy(135,22);
    printf("DE L'INFORMATIQUE (EX INI)");
	delay(20*opt);
	textcolor(BLACK);
    gotoxy(x,y);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c",219,219);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(x,y+3);
    printf("%c%c",219,219);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c",219,219,219,219,219);

    delay(20*opt);
    y = y+6;
    gotoxy(x,y);
    printf("%c%c%c%c%c\n\n\n\n",219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c\n\n\n\n",219,219,219,219,219);
    gotoxy(x+3,y+3);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c\n\n\n\n",219,219,219,219,219);

    delay(20*opt);
    y = y + 6;
    gotoxy(x+1,y);
    textcolor(BLUE);
    textbackground(3);
    printf("%c%c\n\n\n",219,254);
    textcolor(BLACK);
    gotoxy(x+1,y+1);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(x+1,y+2);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(x+1,y+3);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(x+1,y+4);
    printf("%c%c\n\n\n\n",219,219);

    gotoxy(44,37);
    telechargement(100);
    i=34;
    gotoxy(23,34);
    textbackground(7);
    textcolor(BLACK);
    printf("***** APPUYEZ SUR UNE TOUCHE POUR CONTINUER *****");
    getch();
    textbackground(CYAN);
    while(i != 0 ){
        gotoxy(11,i);
        clreol();
        i--;
    }
}
/*****************************************************************************************************************************/
void telechargement(int t){
        int i , d=60;
            for (i=0 ; i<=50 ; i++)
            {
                if ( i<44)
                    {
                        textcolor(7);
                        gotoxy(d+i-10,37);
                        printf("%c",219);
                        delay(t);
                    }
                    else
                         if ( i>55)
                    {
                        textcolor(7);
                        gotoxy(d+i-25,37);
                        printf("%c",219);
                        delay(t);
                    }
                textcolor(BLACK);
                textbackground(7);
                gotoxy(64,37);
                printf("patientez quelques secondes ....  chargement : %d %c\r",2*i,37);
                textbackground(7);
                delay(t / 2);
            }
}
/********************************************************************************************************************************/


                                            /************************************************
                                                                THE END!
                                            ************************************************/
