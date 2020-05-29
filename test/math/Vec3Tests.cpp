#include <catch2/catch.hpp>

#include "math/Vec3.h"

#include <cmath>
#include <sstream>

TEST_CASE("Vectors", "[math]")
{
    SECTION("default constructors to zero")
    {
        CHECK(Vec3().x() == 0);
        CHECK(Vec3().y() == 0);
        CHECK(Vec3().z() == 0);
    }

    SECTION("can be constructed")
    {
        auto vec = Vec3(1., 2., 3.);
        CHECK(vec.x() == 1.);
        CHECK(vec.y() == 2.);
        CHECK(vec.z() == 3.);
    }

    SECTION("comparisons")
    {
        CHECK(Vec3() == Vec3());
        CHECK(Vec3() != Vec3(1, 2, 3));
        CHECK(Vec3(1, 2, 3) == Vec3(1, 2, 3));
        CHECK(Vec3(1, 2, 3) != Vec3(3, 2, 1));
    }

    SECTION("adding")
    {
        CHECK(Vec3() + Vec3() == Vec3());
        CHECK(Vec3(1, 1, 1) + Vec3(2, 2, 2) == Vec3(3, 3, 3));
        auto vec = Vec3(1, 2, 3);
        CHECK((vec += Vec3(2, 4, 6)) == Vec3(3, 6, 9));
        CHECK(vec == Vec3(3, 6, 9));
    }

    SECTION("subtracting")
    {
        CHECK(Vec3() - Vec3() == Vec3());
        CHECK(Vec3(1, 1, 1) - Vec3(2, 2, 2) == Vec3(-1, -1, -1));
        auto vec = Vec3(1, 2, 3);
        CHECK((vec -= Vec3(2, 4, 6)) == Vec3(-1, -2, -3));
        CHECK(vec == Vec3(-1, -2, -3));
    }

    SECTION("negation")
    {
        CHECK(-Vec3() == Vec3());
        CHECK(-Vec3(1, 2, 3) == Vec3(-1, -2, -3));
    }

    SECTION("scalar multiply")
    {
        CHECK(Vec3() * 0 == Vec3());
        CHECK(Vec3(1, 2, 3) * 0 == Vec3());
        CHECK(0 * Vec3(1, 2, 3) == Vec3());
        CHECK(Vec3(1, 1, 1) * 2 == Vec3(2, 2, 2));
        auto vec = Vec3(1, 2, 3);
        CHECK((vec *= 2) == Vec3(2, 4, 6));
        CHECK(vec == Vec3(2, 4, 6));
    }

    SECTION("scalar division")
    {
        CHECK(Vec3() / 1 == Vec3());
        CHECK(Vec3(1, 2, 3) / 1 == Vec3(1, 2, 3));
    }

    SECTION("vector multiply")
    {
        CHECK(Vec3() * Vec3() == Vec3());
        CHECK(Vec3(1, 2, 3) * Vec3(0, 0, 0) == Vec3());
        CHECK(Vec3(1, 2, 3) * Vec3(2, 4, 6) == Vec3(2, 8, 18));
        auto vec = Vec3(1, 2, 3);
        CHECK((vec *= Vec3(2, 4, 6)) == Vec3(2, 8, 18));
        CHECK(vec == Vec3(2, 8, 18));
    }

    SECTION("lengths")
    {
        CHECK(Vec3().LengthSquared() == 0);
        CHECK(Vec3().Length() == 0);
        CHECK(Vec3(3, 4, 5).LengthSquared() == 50);
        CHECK(Vec3(3, 4, 5).Length() == Approx(sqrt(50)));
    }

    SECTION("dot product")
    {
        CHECK(Vec3(1, 2, 3).Dot(Vec3(4, 5, 6)) == Approx(1 * 4 + 2 * 5 + 3 * 6));
    }

    SECTION("cross product")
    {
        CHECK(Vec3(1, 2, 3).Cross(Vec3(4, 5, 6)) == Vec3(-3, 6, -3));
    }

    SECTION("normalisation")
    {
        CHECK(Vec3(1, 2, 3).Normalize().Length() == 1.0);
        CHECK(Vec3(1, 2, 3).Normalize() == Vec3(1./sqrt(14.), sqrt(2./7.), 3./sqrt(14.)));
    }

    SECTION("streaming")
    {
        std::ostringstream os;
        os << Vec3(1, 2, 3);
        CHECK(os.str() == "{1, 2, 3}");
    }

    SECTION("axes")
    {
        CHECK(Vec3::XAxis() == Vec3(1, 0, 0));
        CHECK(Vec3::YAxis() == Vec3(0, 1, 0));
        CHECK(Vec3::ZAxis() == Vec3(0, 0, 1));
        CHECK(Vec3::XAxis().Cross(Vec3::YAxis()) == Vec3::ZAxis());
    }
}