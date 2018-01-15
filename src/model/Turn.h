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
    void reset();

private:
    Color m_now;
};

#endif // TURN_H
