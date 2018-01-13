#ifndef STONE_H
#define STONE_H


#include "Common.h"

class Stone
{
public:
    Stone(Color color);
    ~Stone();

    void changeColor();

private:
    Color m_color;
};

#endif // STONE_H
