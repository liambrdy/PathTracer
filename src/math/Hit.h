#ifndef PATHTRACER_HIT_H
#define PATHTRACER_HIT_H

#include "Vec3.h"

struct Hit
{
    double distance{};
    Vec3 position;
    Vec3 normal;
};

#endif // PATHTRACER_HIT_H
