#include <catch2/catch.hpp>

#include "math/Sphere.h"

TEST_CASE("Spheres", "[math]")
{
    SECTION("constructor")
    {
        CHECK(Sphere(Vec3(0, 1, 2), 10.).GetOrigin() == Vec3(0, 1, 2));
        CHECK(Sphere(Vec3(0, 1, 2), 10.).GetRadius() == 10.);
    }

    SECTION("intersection")
    {
        auto r = Ray::FromTwoPoints(Vec3(0, 0, 0), Vec3(0, 0, 50));
        CHECK(Sphere(Vec3(0, 0, 25), 5.).Intersect(r));
    }
}