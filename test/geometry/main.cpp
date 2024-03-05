#include "../../components/geometry/include/point.hpp"

#include <stdio.h>

int main()
{
  sdk::geometry::Point2D p1(1, 2);
  sdk::geometry::Point2D p2(1, 2);
  sdk::geometry::Point2D p3(4, 5);

  printf("Is same P1 and P2?\t %s\n", p1 == p2 ? "true" : "false");
  printf("Don't same P1 and P2?\t %s\n", p2 != p3 ? "true" : "false");

  // auto dist = sdk::geometry::distance(p2, p3);
  // printf("Distance between P1 and P2 : %f", dist);

  return 0;
}