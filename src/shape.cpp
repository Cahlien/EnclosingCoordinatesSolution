//
// Created by Matthew Crowell on 7/17/22 at 7:18 AM.
//


#include <cmath>
#include <climits>
#include "shape.h"

shape::shape(std::pair<int, int> center)
        : m_center{std::move(center)}
{

}

std::pair<int, int> shape::center()
{
    return this->m_center;
}

std::pair<int, int> shape::center(const std::pair<int, int>& point)
{
    this->m_center = point;

    return this->center();
}

long double shape::get_distance(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    unsigned long long x{static_cast<unsigned long long>(std::pow(b.first - a.first, 2))};
    unsigned long long y{static_cast<unsigned long long>(std::pow(b.second - a.second, 2))};

    return std::sqrt(x + y);
}

std::optional<std::pair<int, int>>
shape::calculate_center(const std::vector<std::pair<int, int>>& points, std::optional<std::pair<int, int>> center)
{
    if(!center.has_value())
    {
        center = {0, 0};

        int max_x{INT_MIN};
        int max_y{INT_MIN};
        int min_x{INT_MAX};
        int min_y{INT_MAX};

        for (const auto& point: points)
        {
            max_x = std::max(max_x, point.first);
            max_y = std::max(max_y, point.second);
            min_x = std::min(min_x, point.first);
            min_y = std::min(min_y, point.second);
        }

        center = {((max_x + min_x) / 2), ((max_y + min_y) / 2)};
    }
    return center;
}
