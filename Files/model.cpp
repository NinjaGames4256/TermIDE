#include "model.h"

void Model::CreateNewProject( QString ProjectName, QString Language, QString Patern){

    system(std::string("cd " + Home + "/Desktop/ && mkdir TermIDE && cd " + Home + "/Desktop/TermIDE/ && mkdir " + ProjectName.toStdString() ).c_str());

    std::string Command;

    if(Language == "Swift"){

    } else if(Language == "C++"){

        system(std::string("cd " + Home + "/Desktop/TermIDE && mkdir C++ ").c_str());

        if(Patern == "Model View Controller"){
            system(std::string("cd " + Home + "/Desktop/TermIDE/C++/" + ProjectName.toStdString() + "/ && touch Model.cpp && touch Model.hpp && touch Controller.hpp && touch Controller.cpp && touch main.cpp" ).c_str());
        } CPlusPlusBuild(ProjectName);


    } else if(Language == "C"){


    } else if(Language == "C#"){


    } else if(Language == "Go"){


    }

}

void Model::CPlusPlusBuild( QString ProjectName ){

    std::string Command = "g++ -std=c++2a -c main.cpp -I/usr/local/include " + Home + "/Desktop/TermIDE/CppLibrary/ && g++ main.o -o 'C++_Application'";

    system(std::string("cd " + Home + "/Desktop/TermIDE/C++/" + ProjectName.toStdString() + " && touch " + ProjectName.toStdString() + ".info && echo '" + Command + "' >> " + ProjectName.toStdString() + ".info" ).c_str());

}
