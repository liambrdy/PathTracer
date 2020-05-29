#include <catch2/catch.hpp>

#include "math/Ray.h"

TEST_CASE("Rays", "[math]")
{
    SECTION("default constructors")
    {
        CHECK(Ray().GetOrigin() == Vec3());
        CHECK(Ray().GetDirection() == Vec3());
    }

    SECTION("can be initialized")
    {
        auto r = Ray(Vec3(1, 2, 3), Vec3(3, 2, 1));
        CHECK(r.GetOrigin() == Vec3(1, 2, 3));
        CHECK(r.GetDirection() == Vec3(3, 2, 1));
    }

    SECTION("position along a ray")
    {
        CHECK(Ray().PointAt(1) == Vec3());
        CHECK(Ray(Vec3(1, 1, 1), Vec3(2, 2, 2)).PointAt(3) == Vec3(7, 7, 7));
    }
}