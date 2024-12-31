#include "../include/shape.h"

Shape::Shape(std::string name) : name(name) {}

std::string Shape::get_name() const
{
  return this->name;
}
