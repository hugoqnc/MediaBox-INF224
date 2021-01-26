#include "Multimedia.h"


void Multimedia::displayAll(ostream& outputStream) const{
    outputStream
    << "\nname: " << this->getName()
    << "\nfileName: " << this->getPathName()
    <<endl;
}