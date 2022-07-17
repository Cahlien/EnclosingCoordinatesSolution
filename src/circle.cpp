//
// Created by Matthew Crowell on 7/17/22 at 7:19 AM.
//

#include <cmath>
#include "circle.h"

circle circle::get_minimum_enclosing_circle(const std::vector<std::pair<int, int>>& points,
                                            std::optional<std::pair<int, int>> center)
{
    center = shape::calculate_center(points, center);
    return circle{center.value(), calculate_radius(points, center)};
}

circle::circle(const std::pair<int, int>& center, int radius)
        : shape{center}, m_radius{radius}
{
}

int circle::radius() const
{
    return this->m_radius;
}

int circle::radius(int radius)
{
    this->m_radius = radius;
    return this->m_radius;
}

std::string circle::to_string() const
{
    return "Circle { \n\tCenter: { " + std::to_string(this->m_center.first) + ", "
           + std::to_string(this->m_center.second) + " },\n\tRadius: { "
           + std::to_string(this->m_radius) + " },\n\tCircumference: { "
           + std::to_string(this->circumference()) + " },\n\tArea: { "
           + std::to_string(this->area()) + " }\n}";
}

int circle::calculate_radius(const std::vector<std::pair<int, int>>& points, std::optional<std::pair<int, int>> center)
{
    long double radius{};

    for (const auto& point: points)
    {
        radius = static_cast<int>(std::max(radius, shape::get_distance(*center, point)));
    }

    return std::ceil(radius);
}

double circle::area() const
{
    return M_PI * std::pow(this->m_radius, 2);
}

double circle::circumference() const
{
    return 2 * M_PI * this->m_radius;
}