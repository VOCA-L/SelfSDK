#include "../../components/geometry/include/point.hpp"
#include "../../components/geometry/include/geometry_utils.hpp"

#include <stdio.h>

int main()
{
  sdk::geometry::Point2D p1(1, 2);
  sdk::geometry::Point2D p2(1, 2);
  sdk::geometry::Point2D p3(4, 5);

  // Overriding operator
  printf("Is same P1 and P2?\t %s\n", p1 == p2 ? "true" : "false");
  printf("Don't same P1 and P2?\t %s\n", p2 != p3 ? "true" : "false");

  // Member function
  printf("P1 coordinate x: %d | y: %d | dim: %d\n", p1.x(), p1.y(), p1.dimension());

  auto dist = sdk::geometry::distance(p2, p3);
  printf("Distance between P1 and P2 : %f\n", dist);

  return 0;
}