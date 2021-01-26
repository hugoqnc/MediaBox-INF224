#include "Group.h"

void Group::displayAll(ostream& outputStream) const {
    for (auto it = this->begin(); it != this->end(); ++it){
        (*(*it)).displayAll(outputStream);
    }
}