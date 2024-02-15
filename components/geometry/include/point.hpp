#ifndef SELF_SDK_GEOMETRY_POINT_H
#define SELF_SDK_GEOMETRY_POINT_H

// #include "definition.hpp"

namespace sdk {
namespace geometry {

// To-Do
// Add concet for using NUMBER (e.g. int, float...)

/**
 * 2D Coordinate Point
 */
template <typename T>
class Point2D
{
 private:
  T x_;
  T y_;

 public:
  Point2D(T x, T y) : x_(x), y_(y){};
};

/**
 * 3D Coordinate Point
 */
template <typename T>
class Point3D
{
 private:
  T x_;
  T y_;
  T z_;

 public:
  Point3D(T x, T y, T z) : x_(x), y_(y), z_(z){};
};

}  // namespace geometry
}  // namespace sdk

#endif
