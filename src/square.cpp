//
// Created by Matthew Crowell on 7/17/22 at 7:19 AM.
//


#include <complex>
#include "square.h"

square square::get_minimum_enclosing_square(const std::vector<std::pair<int, int>>& points,
                                            std::optional<std::pair<int, int>> center)
{
    center = shape::calculate_center(points, center);
    return square{center.value(), calculate_dimensions(points, center)};
}

square::square(const std::pair<int, int>& center, int dimensions)
        : shape{center}, m_dimensions{dimensions}
{

}

int square::dimensions() const
{
    return this->m_dimensions;
}

int square::dimensions(int dimensions)
{
    this->m_dimensions = dimensions;
    return this->m_dimensions;
}

std::string square::to_string() const
{
    return "Square { \n\tCenter: { " + std::to_string(this->m_center.first) + ", "
           + std::to_string(this->m_center.second) + " },\n\tDimensions: { "
           + std::to_string(this->m_dimensions) + " },\n\tPerimeter: { "
           + std::to_string(this->perimeter()) + " },\n\tArea: { "
           + std::to_string(this->area()) + " }\n}";
}

int square::calculate_dimensions(const std::vector<std::pair<int, int>>& points,
                                 std::optional<std::pair<int, int>> center)
{
    int max_x{};
    int max_y{};
    int min_x{};
    int min_y{};

    for (auto point: points)
    {
        max_x = std::max(max_x, point.first);
        max_y = std::max(max_y, point.second);
        min_x = std::min(min_x, point.first);
        min_y = std::min(min_y, point.second);
    }

    int distance_to_x{std::max(std::abs(max_x), std::abs(min_x)) - center->first};
    int distance_to_y{std::max(std::abs(max_y), std::abs(min_y)) - center->second};
    int greatest_distance{std::max(distance_to_x, distance_to_y)};

    return greatest_distance * 2;
}

int square::perimeter() const
{
    return m_dimensions * 4;
}

int square::area() const
{
    return m_dimensions * m_dimensions;
}