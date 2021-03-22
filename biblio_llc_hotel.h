#ifndef BIBLIO_LLC_H_INCLUDED
#define BIBLIO_LLC_H_INCLUDED
#ifndef BIBLIO_LLC_INDEX_H_INCLUDED
#define BIBLIO_LLC_INDEX_H_INCLUDED


                             /********************************************
                                      DECLARATION DES STRUCTURES
                              ********************************************/

    struct chambre {
        int num_chambre;
        int type;
        int statut;
        char datedeb[11];
        char datefin[11];
        char nom[26] ;
        int prix;
        struct chambre* ch_suiv;
         };

    struct hotel {
        char nomhotel[15];
        char ville[15];
        int capacite;
        int nb_chlib;
        int nb_chocc;
        int prix_hotel1;
        int prix_hotel2;
        struct chambre* tete_chocc ;
        struct chambre* tete_chlib;
        struct hotel* hot_suiv;
        };


    struct lettre {
        char letr;
        struct hotel* hot ;
        struct lettre* let_suiv;
        };


                                   /************************************************
                                    ------------ MACHINE ABSTRAITE -----------------
                                   ************************************************/

        /****************************************************************************************************************
                         ------------------ MACHINE ABSTRAITE DES CHAMBRES ----------------
        /***************************************************************************************************************/



/***************************************************************************************************************/
struct chambre* allouer_chambre();
/***************************************************************************************************************/
void affadr_chambre (struct chambre* p ,struct chambre* q);
/***************************************************************************************************************/
struct chambre* suivant_chambre (struct chambre* p);
/***************************************************************************************************************/
void aff_nb_chambre (struct chambre* p,int numch);
/***************************************************************************************************************/
int num_chambre(struct chambre* p);
/***************************************************************************************************************/
char* datedeb(struct chambre* p);
/***************************************************************************************************************/
char* datefin(struct chambre* p);
/***************************************************************************************************************/
void aff_datedeb (struct chambre* p, char datedeb[11]);
/***************************************************************************************************************/
void aff_datefin (struct chambre* p ,char datefin[11]);
/***************************************************************************************************************/
void aff_typechambre (struct chambre* p,int typech );
/***************************************************************************************************************/
int type_chambre (struct chambre* p);
/***************************************************************************************************************/
void aff_statutchambre (struct chambre* p, int statutch);
/***************************************************************************************************************/
int statut_chambre(struct chambre* p);
/***************************************************************************************************************/
void aff_prixchambre (struct chambre* p ,int prixch);
/***************************************************************************************************************/
int prix_chambre(struct chambre* p);
/***************************************************************************************************************/
 char* nom_client(struct chambre* p);
/***************************************************************************************************************/
void aff_nomclient (struct chambre* p,char nomc[26]);
/***************************************************************************************************************/


           /***************************************************************************************************************
                        /------------------MACHINE ABSTRAITE HOTEL ----------------------/
           /**************************************************************************************************************/

/*********************************************************************************************************/
struct hotel* allouer_hotel();
/*********************************************************************************************************/
void affadr_hotel (struct hotel* p,struct hotel* q);
/*********************************************************************************************************/
struct hotel* suivant_hotel(struct hotel* p);
/*********************************************************************************************************/
char* nom_hotel(struct hotel* p);
/*********************************************************************************************************/
char* ville(struct hotel* p);
/*********************************************************************************************************/
void aff_nomhotel(struct hotel* p,char nomhot[15]);
/*********************************************************************************************************/
void aff_nomville(struct hotel* p,char nomville[15]);
/*********************************************************************************************************/
void aff_nbchambres (struct hotel* p, int nb_chambres);
/*********************************************************************************************************/
int nb_chambres (struct hotel* p);
/*********************************************************************************************************/
void aff_nbchlibres (struct hotel* p , int nb_chamblibres);
/*********************************************************************************************************/
int nb_chambresvides(struct hotel* p);
/*********************************************************************************************************/
void aff_nbchoccupes (struct hotel* p,int nb_choccupes );
/*********************************************************************************************************/
int nb_choccupes (struct hotel * p);
/*********************************************************************************************************/
void aff_nbchambres (struct hotel* p, int nb_chambres);
/*********************************************************************************************************/
int nb_chambres (struct hotel* p);
/*********************************************************************************************************/
void aff_adr_chambresocc(struct hotel* p,struct chambre* q);
/*********************************************************************************************************/
void aff_adr_chambreslib(struct hotel* p,struct chambre* q);
/*********************************************************************************************************/
struct chambre* adr_tetechocc (struct hotel* p);
/*********************************************************************************************************/
struct chambre* adr_tetechlib (struct hotel* p);
/*********************************************************************************************************/
void aff_prixhotel1(struct hotel* p,int prix);
/*********************************************************************************************************/
int prix_hotel1(struct hotel* p);
/*********************************************************************************************************/
void aff_prixhotel2(struct hotel* p,int prix);
/*********************************************************************************************************/
int prix_hotel2(struct hotel* p);



            /**************************************************************************************************************
                               -------------- MACHINE ASTRAITE DES LETTRES ----------------
            **************************************************************************************************************/

/**********************************************************************************************************/
struct lettre* allouer_lettre ();
/**********************************************************************************************************/
void affadr_lettre ( struct lettre* p,struct lettre* suivant);
/**********************************************************************************************************/
void aff_lettre(struct lettre* p,char lettre);
/**********************************************************************************************************/
char lettre (struct lettre* p);
/**********************************************************************************************************/
struct lettre* suivant_lettre (struct lettre* p);
/**********************************************************************************************************/
void aff_adrtetehotel (struct lettre* p,struct hotel* tetehotel);
/**********************************************************************************************************/
struct hotel* adr_tetehotel(struct lettre* p);
/**********************************************************************************************************/


            /******************************************************************************************************************/
                             /************************* LES MODULES DU MENU *******************************/
           /*******************************************************************************************************************/
void inserer_maillon(struct chambre** t, struct chambre* r);
void supprimer_maillon(struct chambre** t,struct chambre* s,struct chambre* r);
void supprimer_reservation(struct lettre* t, char nomclient[]);
void liberer_list(struct chambre** t);
void supprimer_hotel(struct lettre* t, char nomhotel[]);
void plus_bat_prix(struct lettre* t,int type);
int recherche_ville(struct lettre* t, char vil[],int type);
int recherche_hotel(struct lettre* t,int type,char nom[15]);
void afficher_statut_reserv(struct lettre* t);
void inserer_reservation(struct lettre* t,char nomhotel[],char nom[],char vil[],int numch,char datedeb[],char datefin[]);
int recherche_tab_ville(char* tab[48],int tai,char ville[15]);
void toutes_nos_villes(struct lettre* t);
void modifier_reservation(struct lettre* t, char nomclient[26]);
void inserer_hotel(struct hotel** t,struct hotel* r);
struct chambre* creer_liste_cblibre(int nb_chambre,int prixa1, int prixa2);
void introduire_nouvel_hotel(struct lettre* t,char nomhotel[],char nomville[],int nbchambre,int prixa1,int prixa2);
void tri_bulles(struct hotel** t);
void date_fini(struct lettre* t);
void recherche_reservetion(struct lettre* t,char nomclient[]);
void libe_tout(struct lettre** t);

/****************************************
      PROBLEME DE DATES
*****************************************/
int cmp_df(char datedebut[],char datef[]);
int verif_date(char newdatedeb[],char newdatef[]);
int verif_date_fin(char newdatef[]);

/***************************************
            LES FICHIERS
****************************************/

void creer_listlettre (struct lettre** tetelettre);
void creer_listchambreslibres (struct lettre* tete);
void afficher_listchambresvides (struct lettre* tetelettre);
void afficher_listhotel (struct lettre* teteletrre);
void creer_listechabreocc(struct lettre * tetelettre);
void afficher_listchambresocc(struct lettre* tetelettre);
void sauvegarder_listhotel(struct lettre* tete);
void sauvegarder_resrvation (struct lettre* tete);
void sauvegarder_chambresvides (struct lettre* tete);
/****************************************/
/******************* GRAPHIQUE ***************/
/****************************************/
void style();
void page_acceuil(int opt);
void chargement(int t);



#endif // BIBLIO_LLC_INDEX_H_INCLUDED



#endif // BIBLIO_LLC_H_INCLUDED
