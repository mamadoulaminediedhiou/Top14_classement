#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Equipe.h"
#include "Match.h"


int main(){
  Equipe Teq[NB_EQUIPES];      /* Tableau des équipes */
  Match Tmatch[NB_MATCHS];     /* Tableau des matchs */

  FILE *fic = fopen("Top14.txt", "r");

  if (!fic){
    printf("Fichier non trouvé\n");
    return EXIT_FAILURE;
  }

  /* Lecture du début du fichier pour remplir le tableau Teq des NB_EQUIPES équipes */
  /* et mise à zéros des compteurs des statistiques */
  int i=0;
  char c[MAX_STRING];
  while(i<NB_EQUIPES && fscanf(fic,"%s",c)==1){
  	strcpy(Teq[i].nom,c);
  	Teq[i].nb_points=0;
  	Teq[i].nb_victoires=0;
  	Teq[i].nb_nuls=0;
  	Teq[i].nb_defaites=0;
  	Teq[i].nb_bonus=0;
  	i++;
  }
  int k=0;
  /* Affichage pour test de la liste des équipes */
  while(k!=NB_EQUIPES){
		affiche_equipe(&Teq[k]);
		k++;
	}
	printf("\n");

  
  /* Lecture de la 2eme partie du fichier pour remplir le tableau Tmatch des NB_MATCHS matchs */
  /* Pour cela, il faut rechercher un pointeur sur équipe dans Teq à partir de son nom */
  
  char eq1[MAX_STRING],eq2[MAX_STRING];
  int score1=0,score2=0,l=0;
  
  while(fscanf(fic,"%s %d - %d %s",eq1,&score1,&score2,eq2)==4){
  	Tmatch[l].score_hote=score1;
  	Tmatch[l].score_invite=score2;
  	Tmatch[l].eq_hote=rech_ptr_equipe(Teq, NB_EQUIPES, eq1);
  	Tmatch[l].eq_invite=rech_ptr_equipe(Teq, NB_EQUIPES, eq2);
  	
  	affiche_match(Tmatch[l]);/* Affichage pour test de la liste des matchs */
  	l++;
  }

  fclose(fic);

  //Appele de la fonction analyse 
  analyse_matchs(Tmatch, NB_MATCHS);

  /* Affichage des résultats des équipes */
  for (i=0;i<NB_EQUIPES;i++){
    affiche_equipe(&(Teq[i]));
  }
  printf("\n");
	
  /* Affichage de l'équipe première au classement */
  Equipe *premier= premier_classement(Teq, NB_EQUIPES);
  printf("L'equipe première est :%s %d points\n",premier->nom,premier->nb_points);


  /* Affichage du classement trié des équipes */
	trier_equipes(Teq,NB_EQUIPES);
	printf("\n");
	int n;
	printf("LE classement des equipes:\n");
	for (n=0;n<NB_EQUIPES;n++){
    affiche_equipe(&(Teq[n]));
  }
	printf("\n");
	

  return EXIT_SUCCESS;
}

