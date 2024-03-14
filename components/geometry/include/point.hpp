#ifndef SELF_SDK_GEOMETRY_POINT_H
#define SELF_SDK_GEOMETRY_POINT_H

// #pragma once

// #include "config.h"
#include <cmath>
#include <concepts>

namespace sdk {
namespace geometry {

enum class eDimension
{
  None,       //
  Undefined,  // No Init
  D2,         // 2 Dimension
  D3,         // 2 Dimension
};

// Number check
template <typename T>
concept allowed_type = std::integral<T> || std::floating_point<T>;

// Dimension check 2D
template <typename point_class>
concept dim2_type = requires(const point_class& p) { p.dim_ == eDimension::D2; };

// Dimension check 3D
template <typename point_class>
concept dim3_type = requires(const point_class& p) { p.dim_ == eDimension::D3; };

template <allowed_type T>
class BasePoint
{
 protected:
  eDimension dim_;

 public:
  int dimension()
  {
    return static_cast<int>(dim_);
  }
};

/**
 * 2D Coordinate Point
 */
template <allowed_type P>
class Point2D : public BasePoint<P>
{
 private:
  P x_;
  P y_;

 public:
  Point2D() : x_(0), y_(0) { this->dim_ = eDimension::D2; };
  Point2D(P x, P y) : x_(x), y_(y) { this->dim_ = eDimension::D2; };

  bool operator==(const Point2D& target) const
  {
    return (x_ == target.x_ && y_ == target.y_);
  }
  bool operator!=(const Point2D& target) const
  {
    return (x_ != target.x_ || y_ != target.y_);
  }

  P x() { return x_; }
  P y() { return y_; }
};

/**
 * 3D Coordinate Point
 */
template <allowed_type P>
class Point3D : public BasePoint<P>
{
 private:
  P          x_;
  P          y_;
  P          z_;
  eDimension dim_ = eDimension::D3;

 public:
  Point3D() : x_(0), y_(0), z_(0) { this->dim_ = eDimension::D3; };
  Point3D(P x, P y, P z) : x_(x), y_(y), z_(z) { this->dim_ = eDimension::D3; };

  bool operator==(const Point3D& target) const
  {
    return (x_ == target.x_ && y_ == target.y_ && z_ == target.z_);
  }
  bool operator!=(const Point3D& target) const
  {
    return (x_ != target.x_ || y_ != target.y_ || z_ == target.z_);
  }
};

/*
 * Polar 2D Coordiante Point
 */
template <allowed_type PP>
class PolarPoint2D : public BasePoint<PP>
{
 private:
  PP         distance_;
  PP         range_;

 public:
  PolarPoint2D() = delete;
  PolarPoint2D(PP theta, PP dist) : distance_(dist), range_(theta) { this->dim_ = eDimension::D2; };

  int dimension();

  bool operator==(const PolarPoint2D& target) const
  {
    return (distance_ == target.distance_ && range_ == target.range_);
  }
  bool operator!=(const PolarPoint2D& target) const
  {
    return (distance_ != target.distance_ || range_ != target.range_);
  }
};

}  // namespace geometry
}  // namespace sdk

#endif
