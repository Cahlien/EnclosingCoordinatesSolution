//
// Created by Matthew Crowell on 7/17/22 at 7:16 AM.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"

#define BOOST_TEST_MODULE SquareTest

#ifndef ENVIRONMENT_DOCKER
#define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>
#include <cmath>
#include "square.h"

BOOST_AUTO_TEST_SUITE(SquareTest)
    /**
     * @brief Test the default constructor for the square class.
     * The constructor should set the length and width to 0.
     */
    BOOST_AUTO_TEST_CASE(test_dimensions_square_default_constructor_happy_path)
    {
        square s{};
        BOOST_CHECK_EQUAL(s.dimensions(), 0);
    }

    /**
    * @brief Test the default constructor for the square class.
    */
    BOOST_AUTO_TEST_CASE(test_center_square_default_constructor_happy_path)
    {
        square s;
        BOOST_CHECK(s.center() == std::make_pair(0, 0));
    }

    /**
    * @brief Test the parameterized constructor for the square class.
    */
    BOOST_AUTO_TEST_CASE(test_dimensions_square_parameterized_constructor_happy_path)
    {
        square s{std::pair<int, int>{50, 25}, 100};
        BOOST_CHECK_EQUAL(s.dimensions(), 100);
    }

    /**
    * @brief Test the parameterized constructor for the square class.
    */
    BOOST_AUTO_TEST_CASE(test_center_square_parameterized_constructor_happy_path)
    {
        square s{std::pair<int, int>{50, 25}, 100};
        BOOST_CHECK(s.center() == std::make_pair(50, 25));
    }

    /**
    * @brief Test the get_minimum_enclosing_circle function without
    * specifying a center.
    */
    BOOST_AUTO_TEST_CASE(test_get_minimum_enclosing_circle_happy_path)
    {
        BOOST_CHECK(square::get_minimum_enclosing_square({{50,  50},
                                                          {-50, -50}}).center() == std::make_pair(0, 0));
    }

BOOST_AUTO_TEST_SUITE_END()

#pragma clang diagnostic pop