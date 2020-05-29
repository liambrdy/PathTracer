#ifndef PATHTRACER_SRC_MATH_RAY_H
#define PATHTRACER_SRC_MATH_RAY_H

#include "Vec3.h"

class Ray
{
public:
    Ray() = default;
    Ray(const Vec3& origin, const Vec3& direction) : m_origin(origin), m_direction(direction) {}

    Vec3 PointAt(double t) const { return m_origin + t * m_direction; }

    const Vec3& GetOrigin() const { return m_origin; }
    const Vec3& GetDirection() const { return m_direction; }

private:
    Vec3 m_origin{}, m_direction{};
};

#endif // PATHTRACER_SRC_MATH_RAY_H
