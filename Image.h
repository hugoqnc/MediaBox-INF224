#ifndef IMAGE
#define IMAGE

#include "Multimedia.h"

class Image : public Multimedia
{
    friend class MultimediaMap;

private:
    int width = 0;
    int length = 0;

    Image(const string& name, string pathName, int width, int length):
        Multimedia(name, pathName),
        width(width), length(length){}
public:
    ~Image(){cerr << "\nDestruction de Image\n";}

    int getWidth() const {return width;}
    int getLength() const {return length;}
    void setWidth(int width){Image::width = width;}
    void setLength(int length){Image::length = length;}

    /**
     * @brief Method that displays Image attributes.
     * 
     * @param outputStream Stream used to display the attributes.
     */
    void displayAll(ostream& outputStream) const override{
        Multimedia::displayAll(outputStream);
        outputStream
        << "width: " << this->getWidth()
        << "\nlength: " << this->getLength()
        <<endl;
    }
    
    void playMedia() const override{ //GIMP-2.10.app
        system(("open -a Preview " + getPathName() + " &").c_str()); //for macOS which does not support ImageJ anymore
        //system(("imagej " + getPathName() + " &").c_str()); //for other OS with ImageJ
    }


};

#endif