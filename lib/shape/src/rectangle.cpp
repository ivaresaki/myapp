#include "../include/rectangle.h"

Rectangle::Rectangle(double width, double height)
  : Shape("Rectangle"),
  width(width),
  height(height)
{
}

double Rectangle::get_area() const
{
  return this->width * this->height;
}
