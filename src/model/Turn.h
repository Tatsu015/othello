#ifndef TURN_H
#define TURN_H

#include "Common.h"

class Turn
{
public:
    Turn();
    ~Turn();

    void change();
    Color now();

private:
    Color m_now;
};

#endif // TURN_H
