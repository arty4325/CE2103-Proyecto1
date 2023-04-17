//
// Created by jorgegc on 17/04/23.
//

#ifndef PAGINACION_XMLREADER_H
#define PAGINACION_XMLREADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <QtCore/QXmlStreamReader>
#include <string>
using namespace std;

class XmlReader {
public:
    XmlReader();
    string ReadXmlName(string name);
    string ReadPower(string name, string power);
};


#endif //PAGINACION_XMLREADER_H
