#ifndef XMLDOC_H
#define XMLDOC_H

#include <QMainWindow>

class XmlDoc
{
public:
    XmlDoc();
    static void createXml(int);
    static int getSize();
    static void openXml(QString**, int);
};

#endif // XMLDOC_H
