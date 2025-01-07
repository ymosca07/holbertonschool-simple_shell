# Simple Shell

## 📃 Description

**Simple Shell** est une réimplémentation simplifiée de l'interpréteur de commandes Unix.
Le shell permet d'exécuter des commandes saisies par l'utilisateur en interagissant avec le système via des appels système.

## ⚒️​ Fonctionnalités

- Affichage d'une invite de commande pour l'utilisateur.
- Lecture et exécution des commandes système.
- Gestion des chemins absolus et relatifs.
- Prise en charge de quelques commandes intégrées comme `exit`.
- Gestion des erreurs basiques (commandes non trouvées, etc.).

## ⚙️​ Fonctionnement

1. Le programme démarre en affichant une invite de commande.
2. Lit l'entrée de l'utilisateur via getline.
3. Analyse l'entrée pour identifier la commande et ses arguments.
4. Crée un nouveau processus à l'aide de fork.
5. Exécute la commande dans le processus enfant via execve.
6. Attend la fin du processus enfant avec wait.
7. Si l'utilisateur tape exit, le programme termine.

## 📄 Fichiers

| Colonne 1          | Colonne 2                 | Colonne 3         |
|---------------------|---------------------------|-------------------|
| Contenu cellule 1  | Contenu cellule 2         | Contenu cellule 3 |
| Autre contenu      | Plus de contenu           | Encore du contenu |

## 📜 Exemple d'utilisation

![image](https://github.com/user-attachments/assets/d6add4ba-1e80-4a45-88ca-1510de55e896)

## 💻 Compilation

Pour compiler le programme, utilisez la commande suivante :

![image](https://github.com/user-attachments/assets/c727c750-740d-4cce-9c97-7d0c9f12cc27)

## Flowchart

## Man Page

## ✒️ Auteurs

**Julien Noailles**
(julien.noailles@gmail.com)

**Yannis Mosca Bulain**
(yannismosca@gmail.com)
