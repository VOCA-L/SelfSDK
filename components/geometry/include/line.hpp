#ifndef SELF_SDK_GEOMETRY_LINE_H
#define SELF_SDK_GEOMETRY_LINE_H

#include "point.hpp"

namespace sdk {
namespace geometry {

template <typename T>
class Line2D
{
  private:
   static constexpr int LIMIT = 2;
   Point2D<T> points_[LIMIT];

  public:
   Line2D(Point2D<T> alpha, Point2D<T> beta)
   {
     points_[0] = alpha;
     points_[1] = beta;
   }

   double length();
};

template <typename T>
class Line3D
{
  private:
   static constexpr int LIMIT = 3;
   Point2D<T> points_[LIMIT];

  public:
   Line3D(Point2D<T> alpha, Point2D<T> beta, Point2D<T> gamma)
   {
     points_[0] = alpha;
     points_[1] = beta;
     points_[2] = gamma;
   }
   double length();
};
}  // namespace geometry
}  // namespace sdk

#endif
