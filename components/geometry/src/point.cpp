#include "point.hpp"

namespace sdk {
namespace geometry {

template <allowed_type T>
double distance(Point2D<T>& alpha, Point2D<T>& beta)
{
  return sqrt(pow(abs(beta.x_ - alpha.x_), 2) + pow(abs(beta.y_ - alpha.y), 2));
}

}  // namespace geometry
}  // namespace sdk
