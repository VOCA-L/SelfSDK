#ifndef SELF_SDK_GEOMETRY_POLYGON_H
#define SELF_SDK_GEOMETRY_POLYGON_H

// #include "config.h"
#include <vector>

#include "point.hpp"

namespace sdk {
namespace geometry {

/**
 * Base
 */
template <typename T>
class Polygon
{
 protected:
  std::vector<Point2D<T>> points_;
};

template <typename T>
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
