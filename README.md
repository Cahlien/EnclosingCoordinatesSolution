# Enclosing Coordinates


## Description
This application determines the size of the smallest circle or
square that can enclose a vector of coordinates. The following
constraints and interpretations are based upon the sample input
values and the provided instructions:

- All values should be represented as integers
- Values are between -2,147,483,658 and 2,147,483,657 (inclusive)
- Intersecting a point is considered enclosing it
- Values on the x-axis are larger the further to the right they are
- Values on the y-axis are larger the further to the top they are
- For instruction 2, the algorithm should be modified, not replaced


## Hypothesis
Taking the mean of the largest and smallest x and y coordinates
should give an approximate center of the enclosing circle or square.
Then the radius or dimensions of the enclosing shape can be
calculated by the distance between the center and the most distant
point or the center coordinate values and the most distant coordinate
values.

## Running Natively
Running this natively requires having cmake, Boost Program Options,
Boost Unit Test Framework, a C++20 compiler, and a build system
such as make or ninja installed. The application uses Conan to
manage dependencies when containerized, but does not use Conan on a
local development environment.

```bash
$ cd /path/to/project
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./EnclosingCoordinates.exe --help
```

## Running in Docker
### Building and Running the Container with the Default Arguments
```bash
$ docker build -t enclosing-coordinates:latest .
$ docker run --name enclosing-coordinates enclosing-coordinates:latest 
```
This is the same as natively running:
```bash
$ cd /path/to/project
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cd ..
$ build/EnclosingCoordinates.exe --file data/points.txt --shape circle
```

### Running the Container Interactively
```bash
$ docker run -it enclosing-coordinates:latest bash
$ /app/EnclosingCoordinates.exe --file [file] --shape [circle|square] [--fixed]
```

For more information, run:
```bash
$ /app/EnclosingCoordinates.exe --help
```

## Application Guidelines
Suppose we are working on a c++ project where the user will select a
variety of coordinates and then we must draw a square or circle
around the points.

1) Given a set of coordinates contained in the file "points.txt",
   find size of the smallest square or circle to enclose the points
   if the shape is centered at (0,0).

2) Ideally, we would not like the center of the enclosing shape to be
   at (0,0). Instead, want to find the smallest possible enclosing shape
   centered at any point. We think this might be difficult, though, and
   want a simple solution that will find a good bounding shape but is
   quick to code. Can you modify the solution to part 1 to find a good
   center and then describe the size of the resulting shape?