#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "conio.h"
#include "conio2.h"
#include "biblio_llc_hotel.h"



int main(){
    /*DECLARATION*/
    struct lettre* tetelettre;
    char hotel[15];  char ville[15];  char datedebut[11];  char datef[11];  char nom[26];
    int numch,nbchambres,prixa1,prixa2,choix1,choix2;
    //SRECIALE MENU
    int num,i;
     page_acceuil(10);
     style();
    printf("*************** Bienvenue ! Nous sommes a votre disposition ^-^*************** \n");


    creer_listlettre(&tetelettre);
    creer_listhotel (tetelettre);
    creer_listchambreslibres(tetelettre);

    struct hotel* temphot=NULL;
    struct lettre* templet=tetelettre;



     for(i = 1;i<=100;i++) {gotoxy(i,2);delay(10);printf("%c",'*');}
    printf("\n ************************** welcome to ESI AGENCY *************************** \n ");
do { for(i=1;i<=15;i++)
   { textcolor(BLACK);
     textbackground(i); delay(50);gotoxy(25,5); printf( "  ****** MENU *****   "); style();}
    style();
    textbackground(CYAN);
    gotoxy(25,5); printf( "  ****** MENU *****   ");
    for(i = 1;i<=100;i++) {gotoxy(i,7);delay(10);printf("%c",'*');}
    delay(200);
    printf("\n \n 1 - Charger les reservation depuis un fichier texte. \n\n");
    delay(200);
    printf("2 - Afficher statut reservation. \n\n");
    delay(200);
    printf("3 - Inserer une nouvelle Reservation \n\n");
    delay(200);
    printf("4 - Modifier une Reservation. \n\n");
    delay(200);
    printf("5 - Supprimer une reservation.\n\n");
    delay(200);
    printf("6 - Rechercher une chambre libre selon son type (individuelle ou a deux). \n\n");
    delay(200);
    printf("         * Dans une ville donnee\n\n");
    delay(200);
    printf("         * Dans un hotel donne\n\n");
    delay(200);
    printf("         * Ayant le plus petit prix dans toutes les listes d'hotels\n\n");
    delay(200);
    printf("7 - Rechercher la Reservation effectuee par une personne ''Nom''.\n\n");
    delay(200);
    printf("8 - Rajouter un hotel. \n\n");
    delay(200);
    printf("9 - Supprimer un hotel. \n\n");
    delay(200);
    printf("10- Liberer toutes les chambres occupees ayant une date de fin egale a la date du jour. \n\n");
    delay(200);
    printf("11- Trier les listes des hotels par ordre alphabetique. \n\n");
    delay(200);
    printf("12- Sauvegarde la reservation dans un fichier texte. \n\n");
    delay(200);
    printf("13- Quitter\n\n");
    delay(2000);
    printf("\n------------------------------------\n* veuillez entrer votre choix * \n------------------------------------\n");
    for(i = 1;i<=100;i++) {
        gotoxy(i,46);delay(10);printf("%c",'*');}
    printf("\n Alors ! quel choix avez vous fait : ");
    scanf("%d",&num);
    switch(num)
   {

    case 1:
        system("cls");
        for(i = 1;i<=100;i++) {
        gotoxy(i,5);
        delay(10);
    	printf("%c",'*');
	}
        printf("\n C'est bon c'est fait vos listes de reservations sont chargees et sont pretes a etre utilisees ^-^\n");
        creer_listechabreocc(tetelettre);
        for(i = 1;i<=100;i++) {
        gotoxy(i,10);
        delay(10);
    	printf("%c",'*');}
        printf("\n Appuyez sur n'importe quel touche pour revenir au menu ^^\n");
        getch();
        break;
     case 2:
        system("cls");
        for(i = 1;i<=100;i++) {
        gotoxy(i,5);
        delay(10);
    	printf("%c",'*');
	}
        printf("\n Voila toutes les listes de toutes les reservations : \n ----------------------------------------------------- \n");
        afficher_statut_reserv(tetelettre);
        delay(1200);
        printf("\n Appuyez sur n'importe quel touche pour revenir au menu ^^\n");
        getch();
        break;
     case 3:
        system("cls");
        for(i = 1;i<=100;i++) {gotoxy(i,2);delay(10);printf("%c",'*');}
        printf("Voici la liste de choix que nous avons a vous proposer : \n");
        afficher_listchambresvides(tetelettre);
        printf("\nVeuillez entrez le nom de l'hotel dans lequel vous voulez reserver : ");
        scanf("%s",hotel);
        printf("\nVeuillez entrez la ville ou se trouve l'hotel de votre choix : ");
        scanf("%s",ville);
        printf("\nEntez maintenant le numero de chambre : ");
        scanf("%d",&numch);
        printf("\nEntez le nom avec lequel vous voulez affectuer votre reservation : ");
        scanf("%s",nom);
        printf("\nLa date du debut de votre sejour sera : ");
        scanf("%s",datedebut);
        printf("\nLa date de fin maintenant : ");
        scanf("%s",datef);
        inserer_reservation(tetelettre,hotel,nom,ville,numch,datedebut,datef);
        printf("\nAppuyez sur n'importe quel touche pour revenir au menu ^^\n");
        getch();
        break;

     case 4:
       system("cls");
       for(i = 1;i<=100;i++) {gotoxy(i,2);delay(10);printf("%c",'*');}
       printf("\nEntrez le nom avec lequel vous avez affectué votre reservation : ");
       scanf("%s",&nom);
       modifier_reservation(tetelettre,nom);
       printf("\nAppuyez sur n'importe quel touche pour revenir au menu ^^\n");
       getch();
       break;

     case 5:
       system("cls");
       printf(" vous avez fait le choix n %d \n",num);
       delay(250);
       for(i = 1;i<=100;i++) {gotoxy(i,4);delay(10);printf("%c",'*');}
       printf("\nEntez le nom avec lequel vous avez affectué votre reservation : ");
       scanf("%s",&nom);
       supprimer_reservation(tetelettre,nom);
       printf("\nAppuyez sur n'importe quel touche pour revenir au menu ^^\n");
       getch();
       break;
     case 6:
      system("cls");
      printf(" vous avez fait le choix n %d",num);
      delay(250);
      for(i = 1;i<=100;i++) {gotoxy(i,4);delay(10);printf("%c",'*');}
      printf("Quel type de chambre cherchez vous individuelle ou a deux :\n");
      printf("   *1*_Individuelle .\n");
      printf("   *2*_A deux.");
      printf("Entrez votre choix 1/2 :");
      scanf("%d",&choix1);
      if ((choix1==1) ||(choix1==2)){
        printf("Selon quoi voulez vous effectuer votre recherche : \n");
        printf("         1* Dans une ville donnee\n");
        printf("         2* Dans un hotel donne\n");
        printf("         3* Ayant le plus petit prix dans toutes les listes d’hotels\n");
        printf("Entrez votre choix ici : ");
        scanf("%d",&choix2);
        switch(choix2){
          case 1:
              printf("Entrez la ville de votre choix : ");
              scanf("%s",&ville);
              recherche_ville(tetelettre,ville,choix1);
              break;
          case 2:
              printf("Entrez l'hotel de votre choix : ");
              scanf("%s",&hotel);
              recherche_hotel(tetelettre,choix1,hotel);
              break;
          case 3:
              plus_bat_prix(tetelettre,choix1);
              break;
          default :
              printf("Nous somme desoles les les choix etaient de 1 a 3 revenez au menu puis reesayez !\n");
              break;
        }
        }
        else{
            printf("Les seules types que nous pouvons vous proposer sont 1:Individuelle 2:A deux \n");
        }

        printf("\nAppuyez sur n'importe quel touche pour revenir au menu ^^\n");
        getch();
        break;
     case 7:
        system("cls");
        delay(250);
        for(i = 1;i<=100;i++) {gotoxy(i,4);delay(10);printf("%c",'*');}
        printf("\nEntez le nom avec lequel vous avez effectué votre reservation : ");
        scanf("%s",&nom);
        recherche_reservetion(tetelettre,nom);
        printf("\n Appuyez sur n'importe quel touche pour revenir au menu ^^ \n");
        getch();
        break;
     case 8:
        system("cls");
        delay(250);
        for(i = 1;i<=100;i++) {gotoxy(i,4);delay(10);printf("%c",'*');}
        printf("\nEntrez le nom de l'hotel : ");
        scanf("%s",&hotel);
        printf("\n Ou se trouve il ? //la ville svp// : ");
        scanf("%s",&ville);
        printf("\nQuelle est da capacité en nombre de chambres : ");
        scanf("%d",&nbchambres);
        printf("\n Entrez maitenant le prix des chambre individuelles dans cet hotel : ");
        scanf("%d",&prixa1);
        printf("\n Et le prix des chambre a deux ?! : ");
        scanf("%d",&prixa2);
        introduire_nouvel_hotel(tetelettre,hotel,ville,nbchambres,prixa1,prixa2);
        printf("\n Appuyez sur n'importe quel touche pour revenir au menu ^^ \n \n");
        getch();

        break;
     case 9:
        system("cls");
        delay(250);
       for(i = 1;i<=100;i++) {gotoxy(i,4);delay(10);printf("%c",'*');}
        printf("\nEntrez le nom de l'hotel que vous voulez supprimer : ");
        scanf("%s",&hotel);
        supprimer_hotel(tetelettre,hotel);
        printf("\n \n Appuyez sur n'importe quel touche pour revenir au menu ^^ \n \n");
        getch();
        break;
     case 10:
        system("cls");
        delay(250);
        for(i = 1;i<=100;i++) {gotoxy(i,4);delay(10);printf("%c",'*');}
        date_fini(tetelettre);
        printf("\n Et voila c'est fait !");
        printf("\n Appuyez sur n'importe quel touche pour revenir au menu ^^ \n \n");
        getch();
        break;
    case 11:
        system("cls");
        delay(250);
       for(i = 1;i<=100;i++) {gotoxy(i,4);delay(10);printf("%c",'*');}
        while (templet!=NULL){

            temphot=adr_tetehotel(templet);
            tri_bulles(&temphot);
            templet=suivant_lettre(templet);
        }
        printf("\nEt voila c'est fait ! Vos listes sont triees et pretes a etres utilisees ^-^ \n \n ");
        printf("\nAppuyez sur n'importe quel touche pour revenir au menu ^^\n");
        getch();
    break;
    case 12:
        system("cls");
        sauvegarder_listhotel(tetelettre);
        sauvegarder_resrvation(tetelettre);
        sauvegarder_chambresvides(tetelettre);
        delay(250);
        for(i = 1;i<=100;i++) {gotoxy(i,4);delay(10);printf("%c",'*');}
        printf("\n Et voila tout est sauvegarder ! ^^\n");
        printf("\nAppuyez sur n'importe quel touche pour revenir au menu ^^\n");
        getch();
    break;
    case 13:
        system("cls");
        liberer_tout(&tetelettre);
        for(i = 1;i<=100;i++) {
        gotoxy(i,8);
        delay(10);
    	printf("%c\n",'*');
	}
	for(i=1;i<=15;i++)
   { textcolor(BLACK);
     textbackground(i);delay(100);gotoxy(25,10);printf("                      ***** a bientot !!! *****                      ");}

        for(i = 1;i<=100;i++) {
        gotoxy(i,14);
        delay(14);
    	printf("%c\n",'*');}
    	delay(10);
    	printf("pour plus d'infos contactez  : \n");
    	delay(10);
    	printf("\n---------------------------------- \n MECHOUAR FELLA : hf_mechouar@esi.dz \n");
    	delay(10);
    	printf("---------------------------------- \n BEDDEK LILYA  : hl_beddek@esi.dz \n---------------------------------- \n");
    	for(i = 1;i<=100;i++) {
        gotoxy(i,24);
        delay(14);
    	printf("%c\n",'*');}
    	delay(10);
    	printf("ESI AGENCY   2018@       ALL RIGHTS RESERVED. \n\n\n\n");
    break;
    default:
         printf(" Reessayer une autre fois les choix sont entre 1 et 13 ^-^\n");
          getch();
         break;
    }

    } while(num!=13);


    return 0;
}
