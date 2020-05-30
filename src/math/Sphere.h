#ifndef PATHTRACER_SPHERE_H
#define PATHTRACER_SPHERE_H

#include "Hit.h"
#include "Ray.h"
#include "Vec3.h"

#include <optional>

class Sphere
{
public:
    Sphere(const Vec3& origin, double radius) : m_origin(origin), m_radius(radius) {}

    std::optional<Hit> Intersect(const Ray& ray) const
    {
        auto op = m_origin - ray.GetOrigin();
        auto radiusSquared = m_radius * m_radius;
        auto b = op.Dot(ray.GetDirection());
        auto determinant = b * b - op.LengthSquared() + radiusSquared;
        if (determinant < 0)
            return {};

        determinant = sqrt(determinant);
        static constexpr auto epsilon = 1e-4;
        auto minusT = b - determinant;
        auto plusT = b + determinant;
        if (minusT < epsilon && plusT < epsilon)
            return {};

        auto t = minusT > epsilon ? minusT : plusT;
        auto hitPosition = ray.PointAt(t);
        auto normal = (hitPosition - m_origin).Normalize();
        return Hit{ t, hitPosition, normal };
    }

    const Vec3& GetOrigin() const { return m_origin; }
    const double& GetRadius() const { return m_radius; }

private:
    Vec3 m_origin;
    double m_radius;
};

#endif // PATHTRACER_SPHERE_H
