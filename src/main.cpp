#include <iostream>
#include <vector>
#include <fstream>

#include <boost/program_options.hpp>

#include "circle.h"
#include "square.h"

namespace options = boost::program_options;

int protected_main(int, char* []);

void display_help(const options::variables_map&, const options::options_description&);

std::pair<int, int> split_coordinates(const std::string&);

std::vector<std::pair<int, int>> get_points(const std::string&);

void print_shape_information(const options::variables_map&);

int main(int argc, char* argv[])
{
    try
    {
        return protected_main(argc, argv);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

int protected_main(int argc, char* argv[])
{
    options::options_description description("Allowed options");
    description.add_options()
            ("help", "produce help message")
            ("file", options::value<std::string>(), "input file containing one point per line")
            ("shape", options::value<std::string>(), "shape to use (circle or square)")
            ("fixed", "use fixed center {0, 0}");

    options::variables_map arguments{};
    options::store(options::parse_command_line(argc, argv, description), arguments);
    options::notify(arguments);

    if (arguments.count("help"))
    {
        display_help(arguments, description);
    }

    if (!arguments.count("file"))
    {
        std::cerr << "Error: no input file specified" << std::endl;
        return 1;

    }
    else
    {
        if (!arguments.count("shape"))
        {
            std::cerr << "Error: no shape specified" << std::endl;
            return 1;
        }

        print_shape_information(arguments);
    }

    return 0;
}

void print_shape_information(const options::variables_map& arguments)
{
    auto filename{arguments["file"].as<std::string>()};
    auto points = get_points(filename);

    if (arguments["shape"].as<std::string>() == "circle")
    {
        circle new_shape;

        if (arguments.count("fixed"))
        {
            new_shape = circle::get_minimum_enclosing_circle(points, {{0, 0}});
        }
        else
        {
            new_shape = circle::get_minimum_enclosing_circle(points);
        }

        std::cout << new_shape << std::endl;
    }
    else if (arguments["shape"].as<std::string>() == "square")
    {
        square new_shape;

        if (arguments.count("fixed"))
        {
            new_shape = square::get_minimum_enclosing_square(points, {{0, 0}});
        }
        else
        {
            new_shape = square::get_minimum_enclosing_square(points);
        }

        std::cout << new_shape << std::endl;
    }
    else
    {
        std::cerr << "Error: invalid shape specified" << std::endl;
    }
}

void display_help(const options::variables_map& arguments, const options::options_description& description)
{
    std::cout << description << std::endl;
}

std::pair<int, int> split_coordinates(const std::string& input)
{
    int x{std::stoi(input.substr(0, input.find(' ')))};
    int y{std::stoi(input.substr(input.find(' '), input.length()))};

    return {x, y};
}

std::vector<std::pair<int, int>> get_points(const std::string& filename)
{
    std::string line{};
    std::vector<std::pair<int, int>> points{};

    std::ifstream data{filename};

    if (data.is_open())
    {
        while (std::getline(data, line, '\n'))
        {
            points.push_back(split_coordinates(line));
        }
    }
    return points;
}