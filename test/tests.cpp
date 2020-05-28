#include <catch2/catch.hpp>

TEST_CASE("Tests", "[tests]")
{
    CHECK(5 > 4);
    CHECK('8' - '0' == 8);
}
