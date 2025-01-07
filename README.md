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

| NOM                 | UTILITÉ          |
|---------------------|------------------|
| utils.c            | fonctions externes
| find_command.c     | interprete l'entrée utilisateur pour chercher la fonction correspondante
| prompt.c           | gère l'affichage du prompt, les EOFs, l'execution des commandes et les erreurs
| shell.h            | prototypage des fonctions

## 📜 Exemple d'utilisation

![image](https://github.com/user-attachments/assets/d6add4ba-1e80-4a45-88ca-1510de55e896)

## 💻 Compilation

Pour compiler le programme, utilisez la commande suivante :

![image](https://github.com/user-attachments/assets/c727c750-740d-4cce-9c97-7d0c9f12cc27)

## Flowchart

![image](https://github.com/user-attachments/assets/9e7cd854-c212-42f5-a077-e53eadf5fcc1)


## Man Page

https://github.com/ymosca07/holbertonschool-simple_shell/blob/main/man_1_simple_shell

## ✒️ Auteurs

**Julien Noailles**
(julien.noailles@gmail.com)

**Yannis Mosca Bulain**
(yannismosca@gmail.com)
