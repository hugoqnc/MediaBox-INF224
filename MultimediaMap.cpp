#include "MultimediaMap.h"

shared_ptr<Image> MultimediaMap::createImage(const string& name, string pathName, int width, int length){
    shared_ptr<Image> image(new Image(name, pathName, width, length));
    //objectMap[name] = image;
    objectMap.insert(pair<string,shared_ptr<Multimedia>>(name,image));
    return image;
}

shared_ptr<Video> MultimediaMap::createVideo(const string& name, string pathName, int duration){
    shared_ptr<Video> video(new Video(name, pathName, duration));
    objectMap.insert(pair<string,shared_ptr<Multimedia>>(name,video));
    return video;
}

shared_ptr<Film> MultimediaMap::createFilm(const string& name, string pathName, int duration, int numberChapters){
    shared_ptr<Film> film(new Film(name, pathName, duration, numberChapters));
    objectMap.insert(pair<string,shared_ptr<Multimedia>>(name,film));
    return film;
}

shared_ptr<Group> MultimediaMap::createGroup(const string& name){
    shared_ptr<Group> group(new Group(name));
    groupMap.insert(pair<string,shared_ptr<Group>>(name,group));
    return group;
}

void MultimediaMap::searchAndDisplay(const string& name, ostream& outputStream) const{
    auto it1 = groupMap.find(name);
    auto it2 = objectMap.find(name);
    
    if (it1 != groupMap.end()){
        (it1->second)->displayAll(outputStream);
    }
    else if (it2 != objectMap.end()){
        (it2->second)->displayAll(outputStream);
    }
    else{
        outputStream
        << "\nNothing found for: " << name
        <<endl;
    }
}

void MultimediaMap::playMedia(const string& name, ostream& outputStream) const{
    auto it1 = objectMap.find(name);
    
    if (it1 != objectMap.end()){
        (it1->second)->playMedia();
        outputStream
        << "\nPlaying: " << name
        <<endl;
    }
    else{
        outputStream
        << "\nNothing found for: " << name
        <<endl;
    }
}

void MultimediaMap::eraseMedia(const string& name) {
    auto it1 = objectMap.find(name);

    if (it1 != objectMap.end()){

        for (auto it2 = groupMap.begin(); it2 != groupMap.end(); it2++){
            (it2->second)->remove(it1->second);
        }
        objectMap.erase(it1->first);
        (it1->second).reset();
    }
    else{
        cout
        << "\nNothing found for: " << name
        <<endl;
    }
}

void MultimediaMap::eraseGroup(const string& name) {
    auto it1 = groupMap.find(name);

    if (it1 != groupMap.end()){
        for (auto it = (it1->second)->begin(); it != (it1->second)->end(); ++it){
            it->reset();
        }
        groupMap.erase(it1->first);
        (it1->second).reset();
    }
    else{
        cout
        << "\nNothing found for: " << name
        <<endl;
    }
}