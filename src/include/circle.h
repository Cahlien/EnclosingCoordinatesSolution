//
// Created by Matthew Crowell on 7/17/22 at 7:21 AM.
//

#ifndef ENCLOSINGCOORDINATESSOLUTION_CIRCLE_H
#define ENCLOSINGCOORDINATESSOLUTION_CIRCLE_H

#include "shape.h"
#include <vector>
#include <optional>

/**
 * @brief A class representing a minimally enclosing circle.
 *
 * @author Matthew Crowell
 */
class circle : virtual public shape
{
public:
    /**
     * @brief Construct a minimally enclosing circle with the given center and radius.
     * @param center The center of the circle.
     * @param radius The radius of the circle.
     * @return The requested circle shape.
     */
    static circle get_minimum_enclosing_circle(const std::vector<std::pair<int, int>>&,
                                               std::optional<std::pair<int, int>> = std::nullopt);

    /**
     * @brief The default constructor for the circle class.
     */
    circle() = default;

    /**
     * @brief The parameterized constructor for the circle class.
     * @param center The center of the circle.
     * @param radius The radius of the circle.
     */
    circle(const std::pair<int, int>&, int);

    /**
     * @brief The destructor for the circle class.
     */
    ~circle() = default;


    /**
     * @brief Get the radius of the circle.
     * @return The radius of the circle.
     */
    [[nodiscard]]
    int radius() const;

    /**
     * @brief Set the radius of the circle.
     * @param radius The new radius of the circle.
     * @return The radius of the circle.
     */
    int radius(int);

    /**
     * @brief Get the string representation of the circle.
     * @return The string representation of the circle.
     */
    [[nodiscard]]
    std::string to_string() const override;

    /**
     * @brief Get the area of the circle.
     * @return The area of the circle.
     */
    [[nodiscard]]
    double area() const;

    /**
     * @brief Get the circumference of the circle.
     * @return The circumference of the circle.
     */
    [[nodiscard]]
    double circumference() const;

protected:
    /**
     * @brief Calculate the radius for the minimally enclosing circle.
     * @param points The points to use to calculate the radius.
     * @return the radius of the minimally enclosing circle.
     */
    static int calculate_radius(const std::vector<std::pair<int, int>>&,
                                std::optional<std::pair<int, int>> = std::nullopt);

    int m_radius{};
};

/**
 * @brief Stream insertion operator for the circle class.
 * @param os The output stream to write to.
 * @param c The circle object to write.
 * @return The output stream reference.
 */
inline std::ostream& operator<<(std::ostream& os, const circle& c)
{
    os << c.to_string();
    return os;
}

#endif //ENCLOSINGCOORDINATESSOLUTION_CIRCLE_H
