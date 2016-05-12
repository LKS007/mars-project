#include "allcalculate.h"
#include <math.h>

AllCalculate::AllCalculate()
{
}

void AllCalculate::sorting(QString **strArr, int n)
{
    QString min[2] = {strArr[0][0],strArr[0][1]};
    QString min2[2];
    for (int i = 0; i<n; i++)
    {
        if (strArr[i][0].toInt() < min[0].toInt())
        {
            min2[0] = min[0];
            min2[1] = min[1];
            min[0]=strArr[i][0];
            min[1]=strArr[i][1];
        }
        else if (strArr[i][0].toInt() < min2[0].toInt())
        {
            min2[0]=strArr[i][0];
            min2[1]=strArr[i][1];
        }
    }
    sortPath(strArr, n-1);
    QString s;
    for (int i =0; i<n-1; i++)
    {
        if (strArr[i][0].toInt() == strArr[i+1][0].toInt() && strArr[i][1].toInt() > strArr[i+1][1].toInt())
        {
            QString type[2] = {strArr[i][0],strArr[i][1]};
            strArr[i][0] = strArr[i+1][0];
            strArr[i][1] = strArr[i+1][1];
            strArr[i+1][0] = type[0];
            strArr[i+1][1] = type[1];
        }
        s+="X: ";
        s+=strArr[i][0];
        s+="Y: ";
        s+=strArr[i][1];
    }
 //   ui->textBrowser->setText(s);

    //sortPath(strArr, n);
}

void AllCalculate::sortPath(QString **strArr, int n)
{
    QString temp[2];
    int M = strArr[n/2][0].toInt();
    int i = 0, j = n;

    do {
            while ( strArr[i][0].toInt() < M ) i++;
            while ( strArr[j][0].toInt() > M ) j--;
            if (i <= j) {
                temp[0] = strArr[i][0]; strArr[i][0] = strArr[j][0]; strArr[j][0] = temp[0];
                temp[1] = strArr[i][1]; strArr[i][1] = strArr[j][1]; strArr[j][1] = temp[1];
                i++; j--;
            }
        } while ( i<=j );
    if ( j > 0 ) sortPath(strArr, j);
    if ( n > i ) sortPath(strArr+i, n-i);
}

void AllCalculate::shortLine(QString **strArr, int begin, int n)
{
    QString type[2];
    float min = minLenght (strArr[begin][0],strArr[begin][1],strArr[begin+1][0],strArr[begin+1][1]);
    for (int i = begin + 1; i<n; i++)
    {
        float size = minLenght(strArr[begin][0],strArr[begin][1],strArr[i][0],strArr[i][1]);
        if (size < min)
        {
            min = size;
            type[0] = strArr[begin + 1][0];
            type[1] = strArr[begin + 1][1];
            strArr[begin + 1][0] = strArr[i][0];
            strArr[begin + 1][1] = strArr[i][1];
            strArr[i][0] = type[0];
            strArr[i][1] = type[1];
        }
    }
    if (begin+1 < n-1)
    {
        shortLine(strArr, begin+1, n);
    }
}

float AllCalculate::minLenght(QString x1, QString y1, QString x2, QString y2)
{
    return sqrt(pow(x2.toInt()-x1.toInt(),2)+pow(y2.toInt()-y1.toInt(),2));
}
