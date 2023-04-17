//
// Created by jorgegc on 17/04/23.
//

#include "XmlReader.h"

XmlReader::XmlReader() {

}
string XmlReader::ReadXmlName(string name) {
    //Ruta y abrir
    string filePath = name;
    ifstream file(filePath);

    if (!file.is_open())
    {
        cout <<"Archivo no encontrado"<< endl;
    }
    QXmlStreamReader reader(QString::fromStdString(string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>())));
    //Lectura del nombre
    while (!reader.atEnd())
    {
        QXmlStreamReader::TokenType token = reader.readNext();
        if (token == QXmlStreamReader::StartElement)
        {
            return reader.name().toString().toStdString();
            /*cout<<reader.name().toString().toStdString();
            break;*/
        }
    }
    file.close();
}
string XmlReader::ReadPower(string name,string power) {
    string filePath = name;
    ifstream file(filePath);

    if (!file.is_open())
    {
        cout <<"Archivo no encontrado"<< endl;
    }
    QXmlStreamReader reader(QString::fromStdString(string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>())));
    //Lectura
    while (!reader.atEnd())
    {
        QXmlStreamReader::TokenType token = reader.readNext();
        if (token == QXmlStreamReader::StartElement)
        {
            if(reader.name().toString().toStdString()==power){
                if (reader.attributes().count() > 0)
                {
                    QXmlStreamAttributes attributes = reader.attributes();
                    return attributes.at(0).value().toString().toStdString();
                }
            }
        }
    }

    file.close();
}
