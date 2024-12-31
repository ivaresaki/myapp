#include <iostream>

#include "rectangle.h"

int main()
{

  Shape* rect1 = new Rectangle(2.0, 4.0);

  std::cout << "Hello " << std::endl;
  std::cout << "Area of " << rect1->get_name() << " is " << rect1->get_area() << std::endl;

  delete rect1;

  return 0;
}