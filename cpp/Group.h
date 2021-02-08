#ifndef GROUP
#define GROUP
#include <list>
#include "Multimedia.h"

class Group : public list<shared_ptr<Multimedia>>
{
private:
    string name = "";
    
public:
    Group(const string& name){
        list();
        Group::name = name;
        }
    ~Group(){cerr << "\nDestruction de Groupe\n";};

    string getName() const {return name;}
    void setName(const string& name){Group::name = name;}
    
    void displayAll(ostream& outputStream) const;
};


#endif