//
// Created by Matthew Crowell on 7/17/22 at 7:15 AM.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE CircleTest

#include <boost/test/unit_test.hpp>
#include <cmath>
#include "circle.h"

BOOST_AUTO_TEST_SUITE(CircleTest)
/**
 * @brief Test the default constructor for the circle class.
 * The constructor should set the radius to 0.
 */
    BOOST_AUTO_TEST_CASE(test_radius_circle_default_constructor_happy_path)
    {
        circle c;
        BOOST_CHECK_EQUAL(c.radius(), 0);
    }

/**
 * @brief Test the default constructor for the circle class.
 * The constructor should set the center to {0, 0}.
 */
    BOOST_AUTO_TEST_CASE(test_center_circle_default_constructor_happy_path)
    {
        circle c;
        BOOST_CHECK(c.center() == std::make_pair(0, 0));
    }

/**
 * @brief Test the parameterized constructor for the
 * circle class. The constructor should set the radius
 * to 100.
 */
    BOOST_AUTO_TEST_CASE(test_radius_circle_parameterized_constructor_happy_path)
    {
        circle c{std::pair<int, int>{50, 25}, 100};
        BOOST_CHECK_EQUAL(c.radius(), 100);
    }

/**
 * @brief Test the parameterized constructor for the
 * circle class. The constructor should set the center
 * to {50, 25}.
 */
    BOOST_AUTO_TEST_CASE(test_center_circle_parameterized_constructor_happy_path)
    {
        circle c{std::pair<int, int>{50, 25}, 100};
        BOOST_CHECK(c.center() == std::make_pair(50, 25));
    }

/**
 * @brief Test the get_minimum_enclosing_circle function without
 * specifying a center.  c.radius should be 2.
 */
    BOOST_AUTO_TEST_CASE(test_radius_circle_get_minimum_enclosing_circle_without_center_happy_path)
    {
        std::vector<std::pair<int, int>> points =
                {
                        std::pair<int, int>(4, 4),
                        std::pair<int, int>(1, 1),
                };

        auto c = circle::get_minimum_enclosing_circle(points);
        BOOST_CHECK_EQUAL(c.radius(), 2);
    }

/**
 * @brief Test the get_minimum_enclosing_circle function without
 * specifying a center. c.center should be {2, 2}.
 */
    BOOST_AUTO_TEST_CASE(test_center_circle_get_minimum_enclosing_circle_without_center_happy_path)
    {
        std::vector<std::pair<int, int>> points =
                {
                        std::pair<int, int>(4, 4),
                        std::pair<int, int>(1, 1),
                };

        auto c = circle::get_minimum_enclosing_circle(points);
        BOOST_CHECK(c.center() == std::make_pair(2, 2));
    }

/**
 * @brief Test the get_minimum_enclosing_circle function with a center.
 * c.radius should be 5 because the distance between {0, 0} and {4, 4}
 * is greater than 4.
 */
    BOOST_AUTO_TEST_CASE(test_radius_circle_get_minimum_enclosing_circle_with_zeroed_center_happy_path)
    {
        std::vector<std::pair<int, int>> points =
                {
                        std::pair<int, int>(4, 4),
                        std::pair<int, int>(1, 1),
                };

        auto c = circle::get_minimum_enclosing_circle(points, std::pair<int, int>(0, 0));
        BOOST_CHECK_EQUAL(c.radius(), 5);
    }

/**
 * @brief Test the get_minimum_enclosing_circle function with a center.
 * c.center should be {0, 0}.
 */
    BOOST_AUTO_TEST_CASE(test_center_circle_get_minimum_enclosing_circle_with_zeroed_center_happy_path)
    {
        std::vector<std::pair<int, int>> points =
                {
                        std::pair<int, int>(4, 4),
                        std::pair<int, int>(1, 1),
                };

        auto c = circle::get_minimum_enclosing_circle(points, std::pair<int, int>(0, 0));
        BOOST_CHECK(c.center() == std::make_pair(0, 0));
    }

/**
 * @brief Test the area function. The area of a circle with a radius of
 * 2 should be 12.5663706.
 */
    BOOST_AUTO_TEST_CASE(test_area_circle_happy_path)
    {
        circle c{std::pair<int, int>{0, 0}, 2};
        BOOST_CHECK(12.56 < c.area() && c.area() < 12.57);
    }

/**
 * @brief Test the circumference function. The circumference of a circle with a radius of
 * 3 should be 18.84955592.
 */
    BOOST_AUTO_TEST_CASE(test_circumference_circle_happy_path)
    {
        circle c{std::pair<int, int>{0, 0}, 3};
        BOOST_CHECK(18.84 < c.circumference() && c.circumference() < 18.85);
    }
BOOST_AUTO_TEST_SUITE_END()

#pragma clang diagnostic pop