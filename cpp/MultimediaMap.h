#ifndef MAP
#define MAP

#include <map>
#include "Multimedia.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

class MultimediaMap
{
private:
    map<string, shared_ptr<Multimedia>> objectMap;
    map<string, shared_ptr<Group>> groupMap;
public:
    MultimediaMap(){};
    ~MultimediaMap(){cerr << "\nDestruction de MultimediaMap\n";};

    shared_ptr<Image> createImage(const string& name, string pathName, int width, int length);
    shared_ptr<Video> createVideo(const string& name, string pathName, int duration);
    shared_ptr<Film> createFilm(const string& name, string pathName, int duration, int numberChapters);
    shared_ptr<Group> createGroup(const string& name);

    void searchAndDisplay(const string& name, ostream& outputStream) const;
    void playMedia(const string& name, ostream& outputStream) const;
    void eraseMedia(const string& name);
    
    void eraseGroup(const string& name);
};

#endif