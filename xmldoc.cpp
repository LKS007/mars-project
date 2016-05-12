#include "xmldoc.h"
#include "QFile"
#include <QTextStream>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <string>

XmlDoc::XmlDoc()
{
}

void XmlDoc::createXml(int value)
{
    QFile mFile("Coordinate.xml");
    if(mFile.open(QIODevice::WriteOnly))
    {
            QTextStream stream( &mFile );
            stream << "<coordinats>" << endl;
            for (int i=0; i<value; i++)
            {
                int x = rand() % 545;
                int y = rand() % 375;
                stream << "<point>" << endl;
                stream << "<x>" << endl;
                stream << x << endl;
                stream <<"</x>" <<endl;
                stream << "<y>" << endl;
                stream << y << endl;
                stream <<"</y>" << endl;
                stream << "</point>" <<endl;
            }
            stream << "</coordinats>";
            mFile.close();
    }
}

int XmlDoc::getSize()
{
    int countOfCoords = 0;
    QFile mFile("Coordinate.xml");
    if(mFile.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&mFile);
        xmlReader.readNext();
        while(!xmlReader.atEnd())
        {
            if(xmlReader.isStartElement() && xmlReader.name() == "point")
             {
                countOfCoords++;
             }
             xmlReader.readNext(); // Переходим к следующему элементу файла
        }
        mFile.close();
        QMessageBox::information(0, "Message", QString::number(countOfCoords));
    }
    return countOfCoords;

}

void XmlDoc::openXml(QString **strArr, int countofCoords)
{
    int i = 0;
    QFile mFile("Coordinate.xml");
    if(mFile.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&mFile);
        xmlReader.readNext();
        while(!xmlReader.atEnd())
        {
            if(xmlReader.isStartElement() && xmlReader.name() == "x")
                {
                    strArr[i][0]=xmlReader.readElementText();
                }
            else if (xmlReader.isStartElement() && xmlReader.name() == "y")
            {
                    strArr[i][1]=xmlReader.readElementText();
                    i++;
            }
             xmlReader.readNext(); // Переходим к следующему элементу файла
        }
        mFile.close();
    }

    QString s;
    for(i=0; i<countofCoords;i++)
    {
        s+=strArr[i][0];
        s+=strArr[i][1];
    }
}

