#ifndef MULTIMEDIA
#define MULTIMEDIA
#include <iostream>
#include <string>
using namespace std;

class Multimedia{
    private:
        string name;
        string pathName;

    protected:
        Multimedia();

    public:
        Multimedia(const string& name, string pathName):name(name), pathName(pathName){}
        virtual ~Multimedia(){cerr << "\nDestruction de Multimedia\n";}
        string getName() const {return name;}
        string getPathName() const {return pathName;}
        void setName(const string& name){Multimedia::name = name;}
        void setPathName(const string& pathName){Multimedia::pathName = pathName;}
        /**
         * @brief Method that displays Multimedia attributes.
         * 
         * @param outputStream Stream used to display the attributes.
         */
        virtual void displayAll(ostream& outputStream) const;

        virtual void playMedia() const = 0;
};

#endif
