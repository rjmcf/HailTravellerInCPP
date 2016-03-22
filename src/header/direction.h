#ifndef DIRECTION_H_INCLUDED
#define DIRECTION_H_INCLUDED

struct Direction
{
    enum Direction_ { F, L, R, B };
};

typedef Direction::Direction_ DirectionT;
#endif // DIRECTION_H_INCLUDED
