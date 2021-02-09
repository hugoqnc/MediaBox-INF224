# MediaBox Project - INF224
## Overview
This project is described step by step here: https://perso.telecom-paristech.fr/elc/cpp/TP-C++.html

The idea is to create a client/server project, where the client is a remote control of the server, which is a media manager that contains images, videos, and other files. The remote can ask the server about informations on the content, and can play a content on the server. The server is coded in C++ and the client is a Java Swing GUI. They can communicate using sockets.

![](/screenshots/demo.gif)

## Answers to the project questions (in the upper link) - *in French*
### 4ème Étape
Pour créer une méthode "play" permettant de jouer le media, nous allons la déclarer en tant que méthode abstraite dans la classe mère Media (car on ne peut pas l'implémenter à ce niveau), et nous allons donc l'implémenter dans les classes filles Image et Video. On déclare une méthode abstraite avec le mot-clé "virtual" au début, et "=0" à la fin de la méthode.
J'ai utilisé pour les fonctions playMedia les logiciels Preview et Quicktime Player, natifs sur macOS, mais qui ne sont pas supportés sur les autres OS. Pour utiliser imagej et mpv. On peut les utiliser en décommentant une ligne dans Image.h et Video.h.

Il n'y a pas beosin ici de modifier le Makefile car j'ai implementé Image et Video en intégralité dans le fichier .h (sans faire de .cpp), car ce sont de petites classes.

On ne pourra plus instancier d'objets de la classe de base car elle contient une méthode abstraite, c'est-à-dire qui n'a pas d'implémentation directe.

### 5ème Étape
Le polymorphisme permet de réaliser cela, car on peut voir les éléments des classes Image ou Video tous les deux comme des éléments de la classe mère Multimedia.

On a une liste de pointeurs vers des pointeurs vers des objets de la classe Multimedia.

### 6ème Étape
Pour que l'objet Film ait plein contrôle sur ses données, il faut faire attention au fait qu'on donne à l'objet Film un pointeur vers le tableau des chapitres. Donc un objet externe pourrait très bien modifier ce tableau s'il a eu accès à son adresse. Pour palier à ce problème, Film doit être le seul à pouvoir modifier son tableau. Pour cela, il doit réaliser une copie du tableau qu'il reçoit, et ne travailler qu'avec cette copie par la suite.

Lorsqu'un getter de Film renvoie des données et qu'on ne veut pas qu'elle puissent être modifiées par l'appelant, il suffit d'ajouter "const" au type de retour du getter.

### 7ème Étape
On ne s'intéresse qu'à la classe Film car c'est la seule qui utilise un "new" et une copie. On ajoute dans le destructeur de Film un delete de l'objet qu'on créé avec "new", et on fait de même dans la méthode qui créé la copie de l'objet.

Lors de la copie d'un objet, il faut faire attention à la différence entre une copie superficielle et profonde. La différence entre les deux est que la copie superficielle ne copie pas les objets pointés par les pointeurs de l'objet pointé.

### 8ème Étape
On utilise dans ce cas une liste de pointeurs vers de objets de la classe Multimedia. En effet, cela permet de réaliser du polymorphisme, ce qui ne serait pas possible sans passer par des pointeurs dans la liste. En Java, un liste est d'ailleurs toujours constituée de pointeurs vers les objets.


### 9ème Étape
On souhaite éviter qu'une autre classe que MultimediaMap puisse créer de nouveaux objets. Pour cela, on utilise des constructeurs private ou protected dans les classes d'objets de Multimedia, et on donne un accès "friend" à ces classes à la classe MultimediaMap. MultimediaMap est donc la seule à avoir accès aux constructeurs des objets, et donc la seule classe qui peut instancier les objets.

