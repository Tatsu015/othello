#include "Common.h"
#include <QString>
#include <QMap>

enum Color anotherColor(Color color)
{
    if(BLACK == color){
        return WHITE;
    }
    return BLACK;
}

QString toString(Color color)
{
    static QMap<Color, QString> MAP{
        {NONE, "None"},
        {WHITE, "White"},
        {BLACK, "Black"}
    };

    return MAP[color];
}

bool isSame(Color color1, Color color2)
{
    if(color1 == color2){
        return true;
    }
    return false;
}

bool isAnother(Color color1, Color color2)
{
    if(anotherColor(color1) == color2){
        return true;
    }
    return false;
}
