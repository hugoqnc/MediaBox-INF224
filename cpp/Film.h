#ifndef FILM
#define FILM
#include "Video.h"

class Film : public Video
{
    friend class MultimediaMap;

private:
    int numberChapters = 0;
    float * tableOfChapterDuration = new float[numberChapters];

    Film(const string& name, string pathName, int duration, int numberChapters):
    Video(name, pathName, duration),
    numberChapters(numberChapters){}
    
public:
    ~Film(){
        delete[] tableOfChapterDuration;
        cerr << "\nDestruction de Film\n";}

    void setNumberChapters(int numberChapters){Film::numberChapters = numberChapters;}
    void setTableOfChapterDuration(float * tableOfChapterDuration);
    int getNumberChapters() const {return numberChapters;}
    const float * getTableOfChapterDuration() const {return tableOfChapterDuration;}

    /**
     * @brief Method that displays Film attributes.
     * 
     * @param outputStream Stream used to display the attributes.
     */
    void displayAll(ostream& outputStream) const override;
    
};

#endif