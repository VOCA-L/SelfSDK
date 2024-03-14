#ifndef SELF_SDK_GEOMETRY_POLYGON_H
#define SELF_SDK_GEOMETRY_POLYGON_H

// #include "config.h"
#include "point.hpp"

#include <vector>
#include <concepts>

namespace sdk {
namespace geometry {

// template <typename T, allowed_type P>
// concept point_type = std::is_same_v<T, Point2D<P>> || std::is_same_v<T, Point3D<P>>;

/**
 * Base
 */
template <allowed_type T>
class Polygon
{
 protected:
  std::vector<Point2D<T>> points_;
};

template <allowed_type T>
class Triangle : public Polygon<T>
{
 public:
  Triangle(Point2D<T> first, Point2D<T> second, Point2D<T> third)
  {
    this->points_.push_back(first);
    this->points_.push_back(second);
    this->points_.push_back(third);
  }
};

}  // namespace geometry
}  // namespace sdk

#endif
