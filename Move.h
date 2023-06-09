#ifndef CHESSENGINE_MOVE_H
#define CHESSENGINE_MOVE_H

#include "Piece.h"

namespace Moves {

    using Pieces::Color, Pieces::Type;

    enum MoveFlag {
        QUIET = 0,
        CAPTUREPAWN = 1,
        CAPTUREKNIGHT = 2,
        CAPTUREBISHOP = 3,
        CAPTUREROOK = 4,
        CAPTUREQUEEN = 5,
        ENPASSANT = 6,
        DOUBLEPAWNPUSH = 7,
        CASTLEKINGSIDE = 8,
        CASTLEQUEENSIDE = 9,
    };

    struct Move {
        short start;
        short end;
        Type promotionType;
        MoveFlag flag;
        Color player;

        bool operator==(const Move &other) const {
            return (start == other.start && end == other.end && promotionType == other.promotionType &&
                    flag == other.flag && player == other.player);
        }
    };

    const Move NULL_MOVE = Move{0, 0, Pieces::EMPTY, QUIET, Color::WHITE};

    const short MAILBOX[120] = {
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, 0, 1, 2, 3, 4, 5, 6, 7, -1,
            -1, 8, 9, 10, 11, 12, 13, 14, 15, -1,
            -1, 16, 17, 18, 19, 20, 21, 22, 23, -1,
            -1, 24, 25, 26, 27, 28, 29, 30, 31, -1,
            -1, 32, 33, 34, 35, 36, 37, 38, 39, -1,
            -1, 40, 41, 42, 43, 44, 45, 46, 47, -1,
            -1, 48, 49, 50, 51, 52, 53, 54, 55, -1,
            -1, 56, 57, 58, 59, 60, 61, 62, 63, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    };

    const short MAILBOX64[64] = {
            21, 22, 23, 24, 25, 26, 27, 28,
            31, 32, 33, 34, 35, 36, 37, 38,
            41, 42, 43, 44, 45, 46, 47, 48,
            51, 52, 53, 54, 55, 56, 57, 58,
            61, 62, 63, 64, 65, 66, 67, 68,
            71, 72, 73, 74, 75, 76, 77, 78,
            81, 82, 83, 84, 85, 86, 87, 88,
            91, 92, 93, 94, 95, 96, 97, 98
    };

    const bool SLIDE[7] = {false, false, false, true, true, true, false};
    const short OFFSETS[7] = {0, 4, 8, 4, 4, 8, 8};
    const short OFFSET[7][8] = {
            {0,   0,   0,   0,  0, 0,  0,  0},
            {8,   9,   11,  16, 0, 0,  0,  0},
            {-21, -19, -12, -8, 8, 12, 19, 21},
            {-11, -9,  9,   11, 0, 0,  0,  0},
            {-10, -1,  1,   10, 0, 0,  0,  0},
            {-11, -10, -9,  -1, 1, 9,  10, 11},
            {-11, -10, -9,  -1, 1, 9,  10, 11}
    };
}
#endif //CHESSENGINE_MOVE_H
