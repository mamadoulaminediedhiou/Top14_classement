#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"Match.h"

/* Affiche les donnés d'un match dont les données sont passées par copie
   sous la forme "Toulon 10 - 15 Toulouse" */
void affiche_match(Match m){
	printf("%s %d - %d %s\n",m.eq_hote->nom,m.score_hote,m.score_invite,m.eq_invite->nom);
}

	
/* Calcule les statistiques de victoire, nul, défaites et bonus 
   des équipes à partir du tableau Tmatch des n matchs */
void analyse_matchs(Match Tmatch[], int n){
	int i;
	for(i=0;i<n;i++){
		if(Tmatch[i].score_hote>Tmatch[i].score_invite){
			Tmatch[i].eq_hote->nb_points+=4;
			Tmatch[i].eq_hote->nb_victoires+=1;
			Tmatch[i].eq_invite->nb_defaites+=1;
			if(Tmatch[i].score_hote-Tmatch[i].score_invite<=5){
				Tmatch[i].eq_invite->nb_bonus+=1;
			}
		}
		else if(Tmatch[i].score_hote<Tmatch[i].score_invite){
			Tmatch[i].eq_invite->nb_points+=4;
			Tmatch[i].eq_invite->nb_victoires+=1;
			Tmatch[i].eq_hote->nb_defaites+=1;
			if(Tmatch[i].score_invite-Tmatch[i].score_hote<=5){
				Tmatch[i].eq_hote->nb_bonus+=1;
			}
		}
		else{
			Tmatch[i].eq_hote->nb_points+=2;
			Tmatch[i].eq_invite->nb_points+=2;
			Tmatch[i].eq_invite->nb_nuls+=1;
			Tmatch[i].eq_hote->nb_nuls+=1;
		}
	}
	printf("\n");
}
	
			
		
	
