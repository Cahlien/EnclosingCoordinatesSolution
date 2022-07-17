//
// Created by Matthew Crowell on 7/17/22 at 7:21 AM.
//

#ifndef ENCLOSINGCOORDINATESSOLUTION_SQUARE_H
#define ENCLOSINGCOORDINATESSOLUTION_SQUARE_H
#include "shape.h"
#include <vector>
#include <optional>
#include <string>

/**
 * @brief A class representing a minimally enclosing square.
 *
 * @author Matthew Crowell
 */
class square : virtual public shape
{
public:
    /**
     * @brief Construct a minimally enclosing square with the given center and radius.
     * @param center The center of the square.
     * @param dimensions The length and width of the square.
     * @return The requested square shape.
     */
    static square get_minimum_enclosing_square(const std::vector<std::pair<int, int>>&,
                                               std::optional<std::pair<int, int>> = std::nullopt);

    /**
     * @brief The default constructor for the square class.
     */
    square() = default;

    /**
     * @brief The parameterized constructor for the square class.
     * @param center The center of the square.
     * @param dimensions The length and width of the square.
     */
    square(const std::pair<int, int>&, int);

    /**
     * @brief The destructor for the square class.
     */
    ~square() = default;

    /**
     * @brief Get the length and width of the square.
     * @return The length and width of the square.
     */
    [[nodiscard]]
    int dimensions() const;

    /**
     * @brief Set the length and width of the square.
     * @param dimensions The new length and width of the square.
     * @return The length and width of the square.
     */
    int dimensions(int);

    /**
     * @brief Get the string representation of the square.
     * @return The string representation of the square.
     */
    [[nodiscard]]
    std::string to_string() const override;

    /**
     * @brief Get the perimeter of the square.
     * @return The perimeter of the square.
     */
    [[nodiscard]]
    int perimeter() const;

    /**
     * @brief Get the area of the square.
     * @return The area of the square.
     */
    [[nodiscard]]
    int area() const;

protected:
    /**
     * @brief Calculate the length and width of the square.
     * @param points The points that make up the square.
     * @return The length and width of the square.
     */
    static int calculate_dimensions(const std::vector<std::pair<int, int>>&,
                                    std::optional<std::pair<int, int>> = std::nullopt);

    int m_dimensions;
};

/**
 * @brief Stream insertion operator for the square class.
 * @param os The output stream.
 * @param square The square to write to the output stream.
 * @return The output stream.
 */
inline std::ostream& operator<<(std::ostream& os, const square& s)
{
    os << s.to_string();
    return os;
}

#endif //ENCLOSINGCOORDINATESSOLUTION_SQUARE_H
