#ifndef PATHTRACER_PRIMITIVE_H
#define PATHTRACER_PRIMITIVE_H

#include <optional>

#include "math/Hit.h"
#include "math/Ray.h"

class Primitive
{
public:
    virtual ~Primitive() = default;

    virtual std::optional<Hit> Intersect(const Ray& ray) const = 0;
};

#endif // PATHTRACER_PRIMITIVE_H
