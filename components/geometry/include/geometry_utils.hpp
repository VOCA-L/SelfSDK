#pragma once

#include "point.hpp"

namespace sdk {
namespace geometry {

template <allowed_type T>
double distance(Point2D<T>& alpha, Point2D<T>& beta)
{
  return (double)sqrt(pow(beta.x() - alpha.x(), 2) + pow(beta.y() - alpha.y(), 2));
}

template <allowed_type T>
PolarPoint2D<T> toPolar(Point2D<T> p)
{
  Point2D      origin(0, 0);
  
  PolarPoint2D pp(std::atan2(p.y_, p.x_), distance(p, origin));
  return pp;
}

}  // namespace geometry
}  // namespace sdk
