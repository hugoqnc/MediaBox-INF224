//
// main.cpp
// Created on 21/10/2018
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
//#include <list>
//#include <map>

#include "Multimedia.h"
#include "MultimediaMap.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

#include "tcpserver.h"

using namespace std;


const int PORT = 3331;
string HOME = ".";

MultimediaMap* myMap = new MultimediaMap();

stringstream requestProcessing(const string& request);
stringstream search(string name);
stringstream play(string name);

int main(int argc, const char* argv[])
{

    shared_ptr<Image> soleil = myMap->createImage("Soleil", HOME+"/content/soleil.jpg", 1000, 1000);
    shared_ptr<Image> nuages = myMap->createImage("Nuages", HOME+"/content/nuages.jpg", 2000, 1000);
    shared_ptr<Image> etoiles = myMap->createImage("Etoiles", HOME+"/content/etoiles.jpg", 1000, 500);
    shared_ptr<Film> bateau = myMap->createFilm("Bateau-St-Tropez", HOME+"/content/tropez.MOV", 5, 4);
    shared_ptr<Video> artifice = myMap->createVideo("Feu-d-artifice", HOME+"/content/artifice.MOV", 4);

    shared_ptr<Group> ciel = myMap->createGroup("Ciel");
    ciel->push_back(soleil);
    ciel->push_back(nuages);
    ciel->push_back(artifice);
    ciel->push_back(etoiles);

    shared_ptr<Group> astres = myMap->createGroup("Astres");
    astres->push_back(soleil);
    astres->push_back(etoiles);

    /* map->searchAndDisplay("Soleil", cout);
    map->playMedia("Feu d'artifice");
    map->playMedia("Soleil");

    map->searchAndDisplay("Ciel", cout);
    map->searchAndDisplay("Astres", cout);
    
    map->eraseMedia("Soleil");
    map->eraseGroup("Astres");

    map->searchAndDisplay("Soleil", cout);

    cout
    << "\n----------------"
    <<endl;

    map->searchAndDisplay("Ciel", cout);

    cout
    << "\n----------------"
    <<endl;

    map->searchAndDisplay("Astres", cout);


    delete(map); */


    //SERVER
    // cree le TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

        // the request sent by the client to the server
        //std::cout << "request: " << request << std::endl;

        stringstream streamResponse = requestProcessing(request);
        string finalResponse{};
        string temp{};

        while(getline(streamResponse, temp)){
            finalResponse += temp+";";
        }

        response = finalResponse;

        // the response that the server sends back to the client
        //response = "RECEIVED: " + request;

        // return false would close the connecytion with the client
        return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }



    return 0;
}

stringstream requestProcessing(const string& request){

    stringstream stream;
    stream << request << endl;

    string requestName, requestDetails;
    stream >> requestName >> requestDetails;

    cout << "PROCESSING: Name: " << requestName << " & Details: " << requestDetails <<endl;

    stringstream streamToReturn;

    if (requestName=="search"){
        streamToReturn = search(requestDetails);
    } else if (requestName=="play"){
        streamToReturn = play(requestDetails);
    } else {
        streamToReturn << "\nUnknown request: " << requestName <<endl;
    }

    return streamToReturn;

}

stringstream search(string name){

    stringstream stream;
    myMap->searchAndDisplay(name, stream);

    return stream;
}

stringstream play(string name){

    stringstream stream;
    myMap->playMedia(name, stream);

    return stream;
}