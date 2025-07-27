# Championnat de rugby Top14 (Programmation imperative 2 -Sorbonne Paris-Nord)
Ce TP consiste à simuler la phase de poules du championnat de rugby français **Top 14**, en C. Il s'appuie sur des fichiers structurés (`Equipe.h`,'Equipe.c', `Match.h`,'Match.c', `main_top14.c`) et utilise des **tableaux de structures** et **pointeurs** pour représenter les équipes et les matchs.

# Fonctionnement du programme

  # Initialisation
    Les données des équipes (points, victoires(V), défaites(D) ,nuls(N) ,bonus(B) ) sont initialisées à zéro avant le début des calculs.

  # Lecture des données
    Le programme lit le fichier Top14.txt en deux étapes :
        - D'abord, il lit la liste des équipes pour remplir le tableau des équipes.
        - Ensuite, il lit toutes les rencontres (matchs) avec leurs scores, en reliant chaque match aux équipes correspondantes via des pointeurs.

  # Analyse des matchs
    La fonction analyse_matchs calcule les statistiques de chaque équipe à partir des résultats des matchs (nombre de victoires, points, bonus, etc.).
      -  Victoire : +4 points
      - Match nul : +2 points
      - Défaite : 0 point
      - Bonus défensif : +1 si l’équipe perd avec ≤ 5 points d’écart

   # Affichage des résultats
    Après le calcul, le programme affiche les statistiques de toutes les équipes, puis affiche l'équipe première et le classement final trié selon les points.

# Compilation et execution (assurer vous d'avoir un compilateur C (`gcc`) installé).  
  Pour compiler le projet, ouvrez le terminal, placez-vous dans le dossier du projet et tapez : **make**
  Cela compilera tous les fichiers sources et générera un exécutable "**main_top14_etu**"
  - Pour exécuter le programme, lancer : **./main_top14_etu**
    
Assurez-vous que le fichier Top14.txt est dans le même dossier que l’exécutable, car il est nécessaire pour la lecture des données.




