#include "Film.h"

void Film::displayAll(ostream& outputStream) const {
    Video::displayAll(outputStream);
    const float * table  = getTableOfChapterDuration();

    for (int i=0; i<getNumberChapters(); i++){
        outputStream
        << "Chapter " << i+1 << " : "<< table[i]
        <<endl;

    }
}

void Film::setTableOfChapterDuration(float * tableOfChapterDuration){
    delete[] Film::tableOfChapterDuration;
    Film::tableOfChapterDuration = new float[getNumberChapters()];
    for (int i=0; i<getNumberChapters(); i++){
        Film::tableOfChapterDuration[i] = tableOfChapterDuration[i];
    }
}