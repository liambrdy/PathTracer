#include "Vec3.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
    return os << "{" << v.x() << ", " << v.y() << ", " << v.z() << "}";
}