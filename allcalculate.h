#ifndef ALLCALCULATE_H
#define ALLCALCULATE_H

#include <QMainWindow>

class AllCalculate
{
public:
    AllCalculate();
    static void sorting (QString **, int);
    static void sortPath (QString **, int);
    static void shortLine (QString **, int, int);
    static float minLenght (QString, QString, QString, QString);
};

#endif // ALLCALCULATE_H
