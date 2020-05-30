#include <vector>
#include <memory>
#include <algorithm>
#include <cstdio>
#include <cmath>

#include "math/Sphere.h"
#include "math/Vec3.h"

int ComponentToInt(double x)
{
    return static_cast<int>(lround(pow(std::clamp(x, 0.0, 1.0), 1.0 / 2.2) * 255));
}

class ArrayOutput
{
public:
    ArrayOutput(int width, int height) : m_width(width), m_height(height) { m_output.resize(width * height); }

    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }

    void Plot(int x, int y, const Vec3& color) { m_output[y * m_width + x] = color; }

    const Vec3& PixelAt(int x, int y) const { return m_output[y * m_width + x]; }

private:
    int m_width, m_height;
    std::vector<Vec3> m_output;
};

constexpr int W = 320, H = 240;
constexpr int BPP = 255;

int main()
{
    const auto aspectRatio = static_cast<double>(W) / static_cast<double>(H);
    const auto yFieldOfView = 0.5135;
    const auto xFieldOfView = yFieldOfView * aspectRatio;

    const Vec3 camPos(0, 0, 0);
    const Vec3 camDir(0, 0, 1);
    const Vec3 camX(1, 0, 0);
    const auto camY = camX.Cross(camDir).Normalize();

    Sphere c{ Vec3(0, 20, 50), 15};

    ArrayOutput output(W, H);
    for (int y = output.GetHeight() - 1; y >= 0; --y)
    {
        auto yy = (static_cast<double>(y) / H) * 2 - 1.0;
        for (int x = 0; x < output.GetWidth(); ++x)
        {
            auto xx = (static_cast<double>(x) / W) * 2 - 1.0;
            auto dir = (camX * xx * xFieldOfView + camY * yy * yFieldOfView + camDir).Normalize();
            Ray ray(camPos, dir);
            auto hit = c.Intersect(ray);

            Vec3 color;

            if (hit)
            {
                Vec3 mat(0.8, 0.2, 0.2);
                color = mat * pow(dir.Dot(hit->normal), 2);
            }

            output.Plot(x, y, color);
        }
    }

    std::unique_ptr<FILE, decltype(fclose) *> f(fopen("image.ppm", "w"), fclose);
    auto width = output.GetWidth();
    auto height = output.GetHeight();
    fprintf(f.get(), "P3\n%d %d\n%d\n", width, height, BPP);
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            const auto & color = output.PixelAt(x, y);
            fprintf(f.get(), "%d %d %d ", ComponentToInt(color.x()), ComponentToInt(color.y()), ComponentToInt(color.z()));
        }
    }
}
