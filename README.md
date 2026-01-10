# So_long 🎮

## Objectif

Transformer un fichier map (`.ber`) en jeu 2D. Le but est de collecter tous les items avant de rejoindre la sortie.

---

## Mon organisation (Parsing)

J'ai commencé par vérifier la map :

- ✅ **La forme** : rectangulaire et les murs autour
- ✅ **Le contenu** : caractères valides, au moins 1 P, 1 E, 1 C
- ✅ **La sécurité** : ennemis non collés au joueur (Bonus)
- ✅ **L'accessibilité** : algorithme DFS pour vérifier le chemin

---

## Logique du code

```
main → check_map → check_name → read_map → check_rectangular → check_wall → check_character → count_elements → check_enemy → player_position → dfs → verif_path
```
> On free la map à la fin car elle a été modifiée par DFS.

---

## Comment j'affiche la map

Je parcours mon tableau case par case. Dès que je croise un caractère (`1`, `P`, `C`), j'affiche l'image correspondante à cet endroit.

### Pour les murs

Je regarde où se trouve le mur pour choisir la bonne image :

- **Les coins** : Si je suis tout en haut à gauche, j'affiche l'image `wall_top_left`. Pareil pour les 3 autres coins (Haut-Droit, Bas-Gauche, Bas-Droit).

- **L'aléatoire** : Pour les murs du milieu, j'utilise une fonction aléatoire `rand()` qui me génère un chiffre aléatoire entre 0 et 4 :
  - Si le chiffre est `0`, j'affiche le mur classique
  - Si c'est `1`, `2` ou `3`, j'affiche une variante (pour que chaque map ne se ressemble pas)

---

## Comment je fais bouger mon personnage

J'utilise la fonction **mlx_key_hook**. Elle surveille la fenêtre du jeu en permanence.

Dès que le joueur appuie sur une touche, la fonction s'exécute (elle appelle `move_player`).

### move_player

- `W` → J'appelle `move_player_top`
- `S` → J'appelle `move_player_down`
- `ESC` → Je quitte le jeu

### Une fois la direction choisie

**Vérification** :
- On vérifie si dans la direction où il veut aller c'est un mur
- On vérifie s'il a collecté tous les `C` et qu'il veut aller sur `E` → si c'est le cas, fin du jeu
- On vérifie s'il va sur un `C` → si c'est le cas, on remplace l'image par un sol et on enlève 1 à la variable qui stocke le nombre de `C` qu'il lui reste à collecter
- Enfin, on remplace sa position actuelle par un sol et sa destination par un player

---

## Comment bougent les ennemis

J'utilise la fonction **mlx_loop_hook** qui s'exécute en continu.

### Le Timer

La boucle est trop rapide pour le jeu. J'utilise une fonction timer qui compte les tours de boucle. Ce n'est qu'après un certain nombre de tours que je déclenche le mouvement des ennemis (je peux accélérer ou ralentir le déplacement des ennemis).

### Le Déplacement

1. Je parcours la map pour trouver chaque ennemi (`X`)
2. Je choisis une direction aléatoire (`rand() % 4`)
3. J'affiche un sol (`0`) à l'ancienne position et l'ennemi à la nouvelle
4. Quand un ennemi bouge, je marque sa nouvelle position avec un `Z` dans la mémoire

### Pourquoi le `Z` ?

Si je déplaçais un ennemi vers la droite en le notant `X`, ma boucle le recroiserait et le ferait bouger tout le temps → boucle infinie !

Le `Z` sert à dire à la fonction `position_enemy` : "Cet ennemi a déjà bougé ce tour-ci, ne le touche plus".

### clean_map

À la toute fin du tour, je transforme tous les `Z` en `X` pour qu'ils soient prêts à bouger au prochain tour.

---

## Aperçu du jeu

![Aperçu du jeu](img/Screenshot%20from%202026-01-10%2015-59-40.png)
