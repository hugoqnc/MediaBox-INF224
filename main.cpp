//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
//#include <list>
//#include <map>

#include "Multimedia.h"
#include "MultimediaMap.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

int main(int argc, const char* argv[])
{
    //Multimedia * test = new Multimedia("hey", "path");
    //test->displayAll(cout);

    //shared_ptr<Multimedia> test2(new Image("wan.jpg", "/Users/hugoqueinnec/Documents/2A/INF224/content/wan.jpg", 10, 20));
    //test2->displayAll(cout);
    //test2->playMedia();

    //shared_ptr<Multimedia> test3(new Video("lucas.MOV", "/Users/hugoqueinnec/Documents/2A/INF224/content/lucas.MOV", 100));
    //test3->displayAll(cout);
    //test3->playMedia();

    /* list<Multimedia*> mediaList;
    mediaList.push_back(test2);
    mediaList.push_back(test3);

    for (auto & media : mediaList) media->playMedia(); */

    /* Film * testFilm = new Film("lucas.MOV", "/Users/hugoqueinnec/Documents/2A/INF224/content/lucas.MOV", 100, 3);
    float tab[] = {3.1, 2.2, 7.0};
    testFilm->setTableOfChapterDuration(tab);
    testFilm->displayAll(cout); */

    /* //Group test
    Group * g = new Group("test");
    g->push_back(test2);
    g->push_back(test3);

    cout
    << "group name: " << g->getName()
    <<endl;

    g->displayAll(cout);

    test2.reset();
    test3.reset();
    g->erase(g->begin());
    g->displayAll(cout); */


    MultimediaMap* map = new MultimediaMap();

    shared_ptr<Image> soleil = map->createImage("Soleil", "/Users/hugoqueinnec/Documents/2A/INF224/content/soleil.jpg", 1000, 1000);
    shared_ptr<Image> nuages = map->createImage("Nuages", "/Users/hugoqueinnec/Documents/2A/INF224/content/nuages.jpg", 2000, 1000);
    shared_ptr<Image> etoiles = map->createImage("Etoiles", "/Users/hugoqueinnec/Documents/2A/INF224/content/etoiles.jpg", 1000, 500);
    shared_ptr<Film> bateau = map->createFilm("Bateau St-Tropez", "/Users/hugoqueinnec/Documents/2A/INF224/content/tropez.MOV", 5, 4);
    shared_ptr<Video> artifice = map->createVideo("Feu d'artifice", "/Users/hugoqueinnec/Documents/2A/INF224/content/artifice.MOV", 4);

    shared_ptr<Group> ciel = map->createGroup("Ciel");
    ciel->push_back(soleil);
    ciel->push_back(nuages);
    ciel->push_back(artifice);
    ciel->push_back(etoiles);

    shared_ptr<Group> astres = map->createGroup("Astres");
    ciel->push_back(soleil);
    ciel->push_back(etoiles);

    map->searchAndDisplay("Soleil", cout);
    //map->playMedia("Feu d'artifice");
    //map->playMedia("Soleil");

    map->searchAndDisplay("Ciel", cout);
    map->searchAndDisplay("Astres", cout);
    
    map->eraseMedia("Soleil");

    map->searchAndDisplay("Soleil", cout);
    map->searchAndDisplay("Ciel", cout);
    map->searchAndDisplay("Astres", cout);


    delete(map);

    return 0;
}
