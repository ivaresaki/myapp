#ifndef __RECTANGLE__H_
#define __RECTANGLE__H_

#include "shape.h"

class SHAPE_API Rectangle : public Shape
{

private:
  double width = 0.0;
  double height = 0.0;

public:
  Rectangle(double width, double height);
  double get_area() const override;
};

#endif