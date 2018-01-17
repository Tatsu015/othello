#include <QString>
#include <QMap>
#include "Common.h"

enum Color anotherColor(const Color& color)
{
    if(BLACK == color){
        return WHITE;
    }
    return BLACK;
}

QString toString(const Color& color)
{
    const static QMap<Color, QString> COLOR_TO_STR{
        {NONE, "None"},
        {WHITE, "White"},
        {BLACK, "Black"}
    };

    return COLOR_TO_STR[color];
}

bool isSame(const Color& color1, const Color& color2)
{
    if(color1 == color2){
        return true;
    }
    return false;
}

bool isAnother(const Color& color1, const Color& color2)
{
    if(anotherColor(color1) == color2){
        return true;
    }
    return false;
}

Qt::GlobalColor toColor(const Color& color)
{
    const static QMap<Color ,Qt::GlobalColor> COLOR = {
        {BLACK, Qt::black},
        {WHITE, Qt::white}
    };

    return COLOR[color];
}
