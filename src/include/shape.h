//
// Created by Matthew Crowell on 7/17/22 at 7:20 AM.
//

#ifndef ENCLOSINGCOORDINATESSOLUTION_SHAPE_H
#define ENCLOSINGCOORDINATESSOLUTION_SHAPE_H

#include <utility>
#include <string>
#include <optional>
#include <vector>

/**
 * @brief The shape class from which minimally enclosings circles and rectangles are derived.
 *
 * @author Matthew Crowell
 */
class shape
{
public:
    /**
    * @brief Get the distance between two points represented as a pair of integers.
    * @param a The first point.
    * @param b The second point.
    * @return The distance between two points represented as an integer.
    */
    static long double get_distance(const std::pair<int, int>&, const std::pair<int, int>&);

    /**
     * @brief The default constructor for the shape class.
     */
    shape() = default;

    /**
     * @brief The parameterized constructor for the shape class.
     * @param center The center of the shape.
     */
    explicit shape(std::pair<int, int>);

    /**
     * @brief The accessor for the center of the shape.
     * @return The center of the shape.
     */
    std::pair<int, int> center();

    /**
     * @brief The mutator for the center of the shape.
     * @param point The new center of the shape.
     * @return The new center of the shape.
     */
    std::pair<int, int> center(const std::pair<int, int>&);

    [[nodiscard]]
    virtual std::string to_string() const = 0;

protected:
    /**
    * @brief Calculate the center of the minimally enclosing shape.
    * @param points The points that are enclosed by the shape.
    * @param center The center of the shape.
    * @return The center of the minimally enclosing shape.
    */
    static std::optional<std::pair<int, int>> calculate_center(const std::vector<std::pair<int, int>>&,
                                                               std::optional<std::pair<int, int>> = std::nullopt);
    std::pair<int, int> m_center;
};

#endif //ENCLOSINGCOORDINATESSOLUTION_SHAPE_H
