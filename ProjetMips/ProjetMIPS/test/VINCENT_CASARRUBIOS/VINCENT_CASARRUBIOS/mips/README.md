# Projet CS351 (2022-2023): Émulateur MIPS

---
title: Projet CS351 (2022-2023): Émulateur MIPS
author: [CASARRUBIOS_VINCENT]
date: [18/10/22]
---

## Rendu 1

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :
  - [X] Vérifié que `make test-cli` ne renvoie pas d'erreur. 
  `pb avec le makefile, cela crée bien les fichiers mais nous avons quand même les erreurs`
  - [X] Vérifié que `make tests` se plaint sur le nombre d'instructions et pas
      sur l'existence des fichiers de sortie.
  - [X] Vu que les soumissions se font avec `make tar`.


## Rendu 2

(Une dizaine de lignes devrait suffire à chaque fois)

* Comment avez-vous choisi de programmer l'analyse de texte (dont la lecture
des opérandes entières) ?

[Pour l'analyse de texte nous avons choisi de coder une fonction qui récupère le nom de l'opérateur et une fonction qui récupère les opérandes (les registres ou les valeurs d'offset selon le type de l'instruction). Nous avons réalisé une fonction de lecture d'opérande par type d'instruction. ]

* Avez-vous vu des motifs récurrents émerger ? Avez-vous "factorisé" ces motifs
pour éviter de les répéter ? Si non, serait-ce difficile ?

[Pour chaque type nous avons des motifs récurrents. Pour le type R nous avons le registre OPCODE qui vaut 0 et c'est le registre fonction qui change. De plus l'odre des registres est toujours le même dans l'appel de la fonction. Par exemple si une commande possède les registres rs et rt en argument il faudra toujours placer rs avant rt; exemple : AND rd , rs, rt rt BEQ rs, rt offset]

* Comment avez-vous procédé pour écrire les tests ? Étes-vous confiant·e·s que
toutes les instructions gérées sont couvertes ? 

[Nous avons écrit les tests à la main de manière intelligente,nous avons testé toutes les commande sauf LR. Nous avons essayer de combler tous les cas possibles, pour le type R les registres sont compris entre 0 et 31 nous avons donc testé avec 0 et 31. Pour le type I la valeur immédiate est comprise entre -32768 et 65535, nous avons donc testé avec ces 2 valeurs. Pour le type J nous avons testé avec la valeur 0 (qui est le min) et la valeur 67108863( qui est le max)]

* Quelle a été votre expérience avec l'utilisation et la compréhension de la
documentation (ie. des annexes) ?

[L'annexe nous permet facilement de coder les instructions, cepandant la compréhension des commandes en elle même est plutôt difficile]

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :
  - [X] Implémenté la traduction pour des instructions de toutes les catégories
      (calcul, comparaisons, sauts, HI/LO, mémoire)
  - [X] Implémenté la traduction pour toutes les instructions de l'annexe 2
  - [X] Pris en compte les cas particuliers : valeurs négatives, hors limites,
      noms d'instructions ou opérandes invalides...


## Rendu 3

(10/15 lignes devrait suffire à chaque fois)

* Quelle structure en modules planifiez-vous d'utiliser pour l'émulateur ?

[COMPLÉTER ICI]

* Quelles seront les fonctions principales de chaque module ?

[COMPLÉTER ICI]

* Quels avantages voyez vous à cette structure (à comparer à un unique fichier)?

[COMPLÉTER ICI]


## Rendu 4

* Avez-vous réussi à suivre la structure prévue au rendu 3 ? Quelles
modifications ont été nécessaires ? Rétrospectivement, est-ce que cette
structure était bien prévue ?

[COMPLÉTER ICI]

* Avez-vous compris le fonctionnement de chaque instruction à partir de la
documentation fournie ? Si non, quels sont les points obscurs ?

[COMPLÉTER ICI]

* Quels exemples de programmes avez-vous choisi pour tester le calcul ? Les
comparaisons et sauts ? La mémoire ?

[COMPLÉTER ICI]

* Le sujet spécifie-t-il tous les détails nécessaires pour bien implémenter la
mémoire ? Quels choix avec-vous faits ?

[COMPLÉTER ICI]

* Reste-t-il des bugs que vous avez découverts et pas corrigés ?

[COMPLÉTER ICI]

* D'autres remarques sur votre programme ?

[COMPLÉTER ICI]

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :**
  - [ ] Implémenté l'émulation de toutes les instructions gérées par le rendu 2.
  - [ ] Implémenté l'émulation de toutes les instructions.
  - [ ] Tous vos tests qui passent.
  - [ ] Vérifié que vous tests couvrent toutes les instructions émulées.
  - [ ] Testé les cas particuliers : valeurs négatives, overflows...
  - [ ] Testé les cas d'erreur : division par zéro, sauts invalides...
  - [ ] Un port fonctionnel de DOOM pour votre émulateur.

* Des retours sur le projet en général ?

[COMPLÉTER ICI]
