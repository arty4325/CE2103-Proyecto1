//
// Created by jorgegc on 17/04/23.
//

#include "XmlReader.h"

/**
 * @brief  Método constructor de la clase XmlReader
 * @return No hay valor de retorno
 */
XmlReader::XmlReader() {

}

/**
 * @brief Este método busca el nombre del Xml en la raíz
 * @param name Nombre del archivo
 * @return Retorna el nombre del Xml que se encuentra en su raíz
 */
string XmlReader::ReadXmlName(string name) {
    string filePath = name;  //Se asigna a una variable string el nombre del Xml en uso
    ifstream file(filePath);   //Busca la dirección

    if (!file.is_open())     //Corrobora que el archivo esté abierto
    {
        cout <<"Archivo no encontrado"<< endl;
    }
    QXmlStreamReader reader(QString::fromStdString(string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>())));   //Se define reader como el objeto que permite la lectura del Xml con la dirección encontrada
    //Lectura del nombre
    while (!reader.atEnd()) //Corrobora que no se ha llegado al final del Xml
    {
        QXmlStreamReader::TokenType token = reader.readNext();  //Se genera un toque para ir cambiando de un nodo a otro en el archivo
        if (token == QXmlStreamReader::StartElement)     //Corrobora que se encontró un elemento
        {
            return reader.name().toString().toStdString();  //Retorna el nombre de ese elemento, que en este caso corresponderá al mismo nombre del archivo
            /*cout<<reader.name().toString().toStdString();
            break;*/
        }
    }
    file.close(); //Cierra el archivo Xml
}

/**
 * @brief Método para leer el valor del poder por utilizar
 * @param name Nombre del archivo
 * @param power El nombre del poder a utilizar
 * @return El valor que corresponde al atributo del poder a utilizar
 */
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
                if (reader.attributes().count() > 0)  //Revisa que la cantidad de atributos para el poder dado sea mayor que 0
                {
                    QXmlStreamAttributes attributes = reader.attributes();  //Lee los atributos
                    return attributes.at(0).value().toString().toStdString();  //Retorna como string el valor del atributo en la posición 0, es decir, el valor que es empleado como "poder"
                }
            }
        }
    }

    file.close();
}