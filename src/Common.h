#ifndef COMMON_H
#define COMMON_H


#include <QString>

enum Color {NONE, BLACK, WHITE};

const unsigned int BOARD_SIZE          = 4;
const int          MAX_INDEX           = ((BOARD_SIZE*BOARD_SIZE) - 1);
const unsigned int INIT_UPPER          = ((BOARD_SIZE/2) - 1);
const unsigned int INIT_LOWER          = (BOARD_SIZE/2);
const unsigned int INIT_LEFT           = ((BOARD_SIZE/2) - 1);
const unsigned int INIT_RIGHT          = (BOARD_SIZE/2);
const double       UNIT                = 80;
const double       CELL_SIZE_RAITO     = 0.9;
const double       CELL_WIDTH          = (CELL_SIZE_RAITO * UNIT);
const double       CELL_HEIGHT         = (CELL_SIZE_RAITO * UNIT);
const double       CELL_LINE_WIDTH     = ((1 - CELL_SIZE_RAITO) * UNIT);
const double       STONE_SIZE_RAITO    = 0.6;
const double       STONE_WIDTH         = (STONE_SIZE_RAITO * UNIT);
const double       STONE_HEIGHT        = (STONE_SIZE_RAITO * UNIT);
const double       STONE_WIDTH_OFFSET  = (0.5 * (CELL_WIDTH  - STONE_WIDTH));
const double       STONE_HEIGHT_OFFSET = (0.5 * (CELL_HEIGHT - STONE_HEIGHT));
const QString      CURSOR_ICON_PATH    = "../resource/icon/black-cursol.png";

Qt::GlobalColor toColor(const Color& color);
QString toString(const Color& color);
enum Color anotherColor(const Color& color);
bool isSame(const Color& color1, const Color& color2);
bool isAnother(const Color& color1, const Color& color2);

#endif // COMMON_H
