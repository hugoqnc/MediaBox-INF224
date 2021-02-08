#ifndef VIDEO
#define VIDEO

#include "Multimedia.h"

class Video : public Multimedia
{
    friend class MultimediaMap;

private:
    int duration = 0;

protected:
    Video(const string& name, string pathName, int duration):
    Multimedia(name, pathName),
    duration(duration){}

public:
    ~Video(){cerr << "\nDestruction de Video\n";}

    int getDuration() const {return duration;}
    void setDuration(int duration){Video::duration = duration;}

    /**
     * @brief Method that displays Video attributes.
     * 
     * @param outputStream Stream used to display the attributes.
     */
    void displayAll(ostream& outputStream) const override{
        Multimedia::displayAll(outputStream);
        outputStream
        << "duration: " << this->getDuration()
        <<endl;
    }

    void playMedia() const override{
        system(("open -a 'Quicktime Player' " + getPathName() + " &").c_str());//for macOS
        //system(("mpv " + getPathName() + " &").c_str()); //for other OS with mpv
    }


};


#endif