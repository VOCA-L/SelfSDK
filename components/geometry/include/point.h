#ifndef SELF_SDK_GEOMETRY_POINT_H
#define SELF_SDK_GEOMETRY_POINT_H

// #include "definition.hpp"

namespace sdk {
namespace geometry {

// To-Do
// Add concet for using NUMBER (e.g. int, float...)

template <typename T2>
struct Coordinate2D
{
  T2 x;
  T2 y;
};

template <typename T3>
struct Coordinate3D
{
  T3 x;
  T3 y;
  T3 z;
};

template <typename TP>
struct PolarCoordinate
{
  TP  distance;
  int range;  // 업데이트. 각도를 나타내는 방법
};

// To-DO
// Add concept

/**
 * T is Coordinate2D, 3D or PolarCoordinate
 */
template <typename T>
class Point
{
  enum Dimension
  {
    D2,
    D3,
    Polar
  };

 private:
  T         coordinate_;
  Dimension dim;

 public:
    Point(T x1, T y1) : x(x1), y(y1) { dim = Dimension::D2; }
};

}  // namespace geometry

}  // namespace sdk

#endif
