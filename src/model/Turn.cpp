#include "Turn.h"

Turn::Turn():
    m_now(BLACK)
{
}

Turn::~Turn()
{
}

void Turn::change()
{
    if(BLACK == m_now){
        m_now = WHITE;
    }
    else{
        m_now = BLACK;
    }
}

Color Turn::now()
{
    return m_now;
}
