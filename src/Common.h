#ifndef COMMON_H
#define COMMON_H


enum Color {NONE, BLACK, WHITE};

inline enum Color anotherColor(Color color)
{
    if(BLACK == color){
        return WHITE;
    }
    return BLACK;
}

inline bool isSame(Color color1, Color color2)
{
    if(color1 == color2){
        return true;
    }
    return false;
}

inline bool isAnother(Color color1, Color color2)
{
    if(anotherColor(color1) == color2){
        return true;
    }
    return false;
}


const unsigned int BOARD_SIZE    = 4;
const unsigned int MAX_INDEX     = ((BOARD_SIZE*BOARD_SIZE) - 1);
const double UNIT                = 80;
const double CELL_SIZE_RAITO     = 0.9;
const double CELL_WIDTH          = CELL_SIZE_RAITO * UNIT;
const double CELL_HEIGHT         = CELL_SIZE_RAITO * UNIT;
const double CELL_LINE_WIDTH     = (1 - CELL_SIZE_RAITO) * UNIT;
const double STONE_SIZE_RAITO    = 0.6;
const double STONE_WIDTH         = STONE_SIZE_RAITO * UNIT;
const double STONE_HEIGHT        = STONE_SIZE_RAITO * UNIT;
const double STONE_WIDTH_OFFSET  = 0.5 * (CELL_WIDTH  - STONE_WIDTH);
const double STONE_HEIGHT_OFFSET = 0.5 * (CELL_HEIGHT - STONE_HEIGHT);

#endif // COMMON_H
