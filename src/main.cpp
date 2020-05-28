#include <vector>
#include <memory>
#include <algorithm>
#include <cstdio>
#include <cmath>

#include "math/Vec3.h"

int ComponentToInt(double x)
{
    return static_cast<int>(lround(pow(std::clamp(x, 0.0, 1.0), 1.0 / 2.2) * 255));
}

class ArrayOutput
{
public:
    ArrayOutput(size_t width, size_t height) : m_width(width), m_height(height) { m_output.resize(width * height); }

    size_t GetWidth() const { return m_width; }
    size_t GetHeight() const { return m_height; }

    void Plot(size_t x, size_t y, const Vec3& color) { m_output[y * m_width + x] = color; }

    const Vec3& PixelAt(size_t x, size_t y) const { return m_output[y * m_width + x]; }

private:
    size_t m_width, m_height;
    std::vector<Vec3> m_output;
};

constexpr int W = 320, H = 240;
constexpr int BPP = 255;

int main()
{
    ArrayOutput output(W, H);
    for (size_t y = output.GetHeight() - 1; y >= 0; --y)
    {
        for (size_t x = 0; x < output.GetWidth(); ++x)
        {
            auto u = static_cast<double>(x) / static_cast<double>(output.GetWidth());
            auto v = static_cast<double>(y) / static_cast<double>(output.GetHeight());

            Vec3 color(u, v, 0.0);
            output.Plot(x, y, color);
        }
    }

    std::unique_ptr<FILE, decltype(fclose) *> f(fopen("image.ppm", "w"), fclose);
    auto width = output.GetWidth();
    auto height = output.GetHeight();
    fprintf(f.get(), "P3\n%lu %lu\n%d\n", width, height, BPP);
    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            const auto & color = output.PixelAt(x, y);
            fprintf(f.get(), "%d %d %d ", ComponentToInt(color.x()), ComponentToInt(color.y()), ComponentToInt(color.z()));
        }
    }
}
