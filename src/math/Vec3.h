#ifndef PATHTRACER_VEC3_H
#define PATHTRACER_VEC3_H

#include <cmath>
#include <cassert>
#include <iosfwd>

class Vec3
{
public:
    Vec3() = default;
    Vec3(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

    Vec3 operator+(const Vec3& b) const { return Vec3(m_x + b.m_x, m_y + b.m_y, m_z + b.m_z); }

    Vec3& operator+=(const Vec3& b)
    {
        m_x += b.m_x;
        m_y += b.m_y;
        m_z += b.m_z;
        return *this;
    }

    Vec3 operator-(const Vec3& b) const { return Vec3(m_x - b.m_x, m_y - b.m_y, m_z - b.m_z); }

    Vec3& operator-=(const Vec3& b)
    {
        m_x -= b.m_x;
        m_y -= b.m_y;
        m_z -= b.m_z;
        return *this;
    }

    friend Vec3 operator*(double lhs, const Vec3& rhs) { return Vec3(lhs * rhs.m_x, lhs * rhs.m_y, lhs * rhs.m_z); }

    Vec3 operator*(double b) const { return Vec3(b * m_x, b * m_y, b * m_z); }

    Vec3& operator*=(double b)
    {
        m_x *= b;
        m_y *= b;
        m_z *= b;
        return *this;
    }

    friend Vec3 operator/(double lhs, const Vec3& rhs) { return Vec3(lhs / rhs.m_x, lhs / rhs.m_y, lhs / rhs.m_z); }

    Vec3 operator/(double b) const
    {
        const auto reciprocal = 1.0 / b;
        return Vec3(m_x * reciprocal, m_y * reciprocal, m_z * reciprocal);
    }

    Vec3& operator/(double b)
    {
        const auto reciprocal = 1.0 / b;
        m_x *= reciprocal;
        m_y *= reciprocal;
        m_z *= reciprocal;
        return *this;
    }

    Vec3 operator*(const Vec3& b) const { return Vec3(m_x * b.m_x, m_y * b.m_y, m_z * b.m_z); }

    Vec3& operator*=(const Vec3& b)
    {
        m_x *= b.m_x;
        m_y *= b.m_y;
        m_z *= b.m_z;
        return *this;
    }

    Vec3 operator-() const { return Vec3(-m_x, -m_y, -m_z); }

    [[nodiscard]] double LengthSquared() const { return Dot(*this); }
    [[nodiscard]] double Length() const { return sqrt(LengthSquared()); }
    [[nodiscard]] double Dot(const Vec3& b) const { return m_x * b.m_x + m_y * b.m_y + m_z * b.m_z; }

    Vec3& Normalize()
    {
        auto length = Length();
        assert(length != 0 && "Vector has a length of zero!");

        m_x /= length;
        m_y /= length;
        m_z /= length;
        return *this;
    }

    [[nodiscard]] Vec3 Cross(const Vec3& b) const
    {
        auto _x = m_y * b.m_z - m_z * b.m_y;
        auto _y = m_z * b.m_x - m_x * b.m_z;
        auto _z = m_x * b.m_y - m_y * b.m_x;
        return Vec3(_x, _y, _z);
    }

    bool operator==(const Vec3& b) const { return m_x == b.m_x && m_y == b.m_y && m_z == b.m_z; }

    bool operator!=(const Vec3& b) const { return m_x != b.m_x || m_y != b.m_y || m_z != b.m_z; }

    [[nodiscard]] double x() const { return m_x; }
    [[nodiscard]] double y() const { return m_y; }
    [[nodiscard]] double z() const { return m_z; }

    static Vec3 XAxis() { return Vec3(1, 0, 0); }
    static Vec3 YAxis() { return Vec3(0, 1, 0); }
    static Vec3 ZAxis() { return Vec3(0, 0, 1); }

private:
    double m_x{}, m_y{}, m_z{};
};

std::ostream& operator<<(std::ostream& os, const Vec3& v);

#endif // PATHTRACER_VEC3_H
