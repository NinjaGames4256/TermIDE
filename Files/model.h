#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

class Model
{
public:
    void CreateNewProject( QString ProjectName, QString Language, QString Patern );

    void OpenProject( QString Name );

    void CPlusPlusBuild( QString ProjectName );

    void SwiftBuild( QString ProjectName );

    void GoBuild( QString ProjectName );

    void CBuild( QString ProjectName );

    void CSharp( QString ProjectName );

private:

    std::string Home = std::getenv("HOME");

    std::fstream file;

};

#endif // MODEL_H
