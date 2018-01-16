#ifndef STONE_H
#define STONE_H


#include "Common.h"
#include "StoneObserver.h"

class Stone : public StoneObserver
{
public:
    Stone(Color color);
    ~Stone();

    Color color() const;
    void setColor(const Color& color);
    void changeColor();

private:
    Color m_color;
};

#endif // STONE_H
