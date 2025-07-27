#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"Equipe.h"


/* Affiche les donnés d'une équipe dont le pointeur est passé en paramètre
   sous la forme "Racing 15 pts (G: N: P: B:)" */
void affiche_equipe(const Equipe *eq){
	printf("%s %d pts (V: %d N: %d D: %d B: %d)\n",eq->nom,eq->nb_points,eq->nb_victoires,eq->nb_nuls,eq->nb_defaites,eq->nb_bonus);
}

/* Renvoie un pointeur sur une équipe sotckée dans le tableau Teq de n cases
   et qui a le nom passé en paramètre */
Equipe* rech_ptr_equipe(Equipe Teq[], int n, char nom[]){
	int i;
	
	for(i=0;i<n;i++){
		if(strcmp(Teq[i].nom,nom)==0){
			return &(Teq[i]);
		}
	}
	return NULL;
}

/* Calcul du nombre total de points pour chacune des n équipes */
void calcul_points(Equipe Teq[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%s %d pts\n",Teq[i].nom,Teq[i].nb_points);
	}
}
	

/* Retourne un pointeur sur la premiere equipe du classement parmi les n équipes*/
Equipe* premier_classement(Equipe Teq[], int n){
	int nbmax=Teq[0].nb_points,i;
	int ind_eq=0; //Une variable qui va memoriser l'indice de l'equipe premiére
	for(i=1;i<n;i++){
		if(Teq[i].nb_points>nbmax){
			nbmax=Teq[i].nb_points;
			ind_eq=i;
		}
	}
	return &(Teq[ind_eq]);
}

/* Retourne l'indice du tableau Teq de l'équipe de plus grand score 
   à partir de l'incide d entre 0 et n-1*/
int max_indice(Equipe Teq[], int n, int d){
	int i,ind_eq=0,nbmax;
	if(d<0 || d>=n) exit (1);
	nbmax=Teq[d].nb_points;
	for(i=d+1;i<n;i++){
		if(Teq[i].nb_points>nbmax){
			nbmax=Teq[i].nb_points;
			ind_eq=i; //Indice de l'equipe de plus grande score
		}
	}
	return ind_eq;
}
		

/* Tri par sélection des équipes par score du tableau des n équipes*/

void trier_equipes(Equipe Teq[], int n){
	int i,j,indmax;
	Equipe temp;
	for(i=0;i<n;i++){
		indmax=i;
		for(j=i+1;j<n;j++){
			if(Teq[j].nb_points>Teq[indmax].nb_points){
				indmax=j;
			}
			/* En cas d'égalité de points, l'équipe ayant le plus de victoires est prioritaire.*/

			else if(Teq[j].nb_points==Teq[indmax].nb_points){
				if(Teq[j].nb_victoires>Teq[indmax].nb_victoires){
					indmax=j;
				}
				
				else if(Teq[j].nb_victoires==Teq[indmax].nb_victoires){
					if(Teq[j].nb_defaites<Teq[indmax].nb_defaites){
						indmax=j;
					}
				}
			}
			
				
		}
		if(indmax!=i){
			temp=Teq[i];
			Teq[i]=Teq[indmax];
			Teq[indmax]=temp;
		}
	}
}				
















