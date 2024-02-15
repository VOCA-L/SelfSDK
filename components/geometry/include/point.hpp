#ifndef SELF_SDK_GEOMETRY_POINT_H
#define SELF_SDK_GEOMETRY_POINT_H

// #include "config.h"

namespace sdk {
namespace geometry {

// To-Do
// Add concept for using NUMBER (e.g. int, float...)

/**
 * 2D Coordinate Point
 */
template <typename P>
class Point2D
{
 private:
  P x_;
  P y_;

 public:
  Point2D(P x, P y) : x_(x), y_(y){};

  bool operator==(const Point2D& target) const
  {
    return (x_ == target.x_ && y_ == target.y_);
  }
  bool operator!=(const Point2D& target) const {
    return (x_ != target.x_ || y_ != target.y_);
  }
};

/**
 * 3D Coordinate Point
 */
template <typename P>
class Point3D
{
 private:
  P x_;
  P y_;
  P z_;

 public:
  Point3D(P x, P y, P z) : x_(x), y_(y), z_(z){}

  bool operator==(const Point3D& target) const
  {
    return (x_ == target.x_ && y_ == target.y_ && z_ == target.z_);
  }
  bool operator!=(const Point3D& target) const {
    return (x_ != target.x_ || y_ != target.y_ || z_ == target.z_);
  }
};

/*
 * Polar 2D Coordiante Point
 */
template <typename PP>
class PolarPoint2D
{
 private:
  PP distance_;
  PP range_;

 public:
  PolarPoint2D(PP dist, PP r) : distance_(dist), range_(r){}
  
  bool operator==(const PolarPoint2D& target) const
  {
    return (distance_ == target.distance_ && range_ == target.range_);
  }
  bool operator!=(const PolarPoint2D& target) const {
    return (distance_ != target.distance_ || range_ != target.range_);
  }
};

}  // namespace geometry
}  // namespace sdk

#endif
