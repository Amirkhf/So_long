**So_long**



**Objectif** : Transformer un fichier map (.ber) en jeu 2D. Le but est de collecter tous les items avant de rejoindre la sortie.



 - Mon organisation (Parsing) : J'ai commencé par verifier la map:


          La forme (rectangulaire) et les murs autour.


          Le contenu (caractères valides, au moins 1 P, 1 E, 1 C).


          La sécurité (Ennemis non collés au joueur - Bonus).


          L'accessibilité (Algo DFS pour vérifier le chemin).



**Logique du code** :

		main ---> check_map ---> check_name ---> read_map ---> check_rectangular ---> check_wall ---> check_character ---> count_elements ---> check_ennemy ---> player_position ---> dfs ---> verif_path (on free map a la fin elle a etait modifier par dfs)




**Comment j'affiche la map** :
Je parcours mon tableau  case par case. Dès que je croise un caractère ( 1, P, C), j'affiche l'image correspondante à cet endroit.



pour les murs : Je regarde où se trouve le mur pour choisir la bonne image :



Les Coins : Si je suis tout en haut à gauche, j'affiche l'image wall_top_left. Pareil pour les 3 autres coins (Haut-Droit, Bas-Gauche, Bas-Droit).



L'**Aléatoire**  : Pour les murs du milieu J'utilise une fonction aléatoire rand() qui me genere un chiffre aleatoire entre 0 && 4 :



Si le chiffre est 0, j'affiche le mur classique.


       Si c'est 1, 2 ou 3, j'affiche une variante (pour que chaque map ne se    ressemble pas).

***

**> Comment je fais bouger mon personnage.**

***



J'utilise la fonction **mlx_key_hook**. Elle surveille la fenêtre du jeu en permanence.



Dès que le joueur appuie sur une touche la fonction sexecute . (elle apelle move player)



**move_player** :

Si c'est W -> J'appelle move_player_top.



Si c'est S -> J'appelle move_player_down.



Si c'est ESC -> Je quitte le jeu.



Une fois la direction choisie:




 **Vérifie : on verifie si dans la direction ou il veut aller ces un mur**

	 on verifie si ils a collecter tout les C est qui veuit aller sur
                     'E     si ces les ca fin; on verifie si ils va sur un C si ces le
                     cas on       remplace limage par un sol est on enleve 1 a la
                     variable qui stocke     le nombre de c quil lui reste a collecter
                     enfin on remplace sa          postion actuelle pas un sol sa
                     destination pas un player




**Comment bougent les ennemis** : J'utilise la fonction mlx_loop_hook qui s'exécute en continu



**Le Timer** : La boucle est trop rapide pour le jeu. J'utilise une fonction timer qui compte les tours de boucle Ce n'est qu'après un certain nombre de tours que je déclenche le mouvement des ennemis (je peut accelere ou ralentire le deplacement des ennemy ).



**Le Déplacement** :



	Je parcours la map pour trouver chaque ennemi (X).

	Je choisis une direction aléatoire (rand() % 4).

	J'affiche un sol (0) à l'ancienne position et l'ennemi à la nouvelle.

	Quand un ennemi bouge, je marque sa nouvelle position avec un 'Z' dans la mémoire.



**Pourquoi** ? Si je déplaçais un ennemi vers la droite en le notant 'X', ma boucle le recroiserait et le ferait bouger tout le temps boule infinie

	Le 'Z' sert a dire a la fonction position ennemy "Cet ennemi a déjà bougé ce tour-ci, ne le touche plus".



**clean_map**

	À la toute fin du tour, je transforme tous les 'Z' en 'X' pour qu'ils soient prêts à bouger au prochain tour.




  voici a quoi le jeux ressemble







![alt text](<Screenshot from 2026-01-10 15-54-19.png>)