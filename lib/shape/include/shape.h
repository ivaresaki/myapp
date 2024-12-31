#ifndef __SHAPE__H_
#define __SHAPE__H_

#include <string>

// Macros for expoting/importing symbols
#if defined(_WIN32) && defined(SHAPE_SHARED)
#ifdef SHAPE_BUILD
#define SHAPE_API __declspec(dllexport)
#else
#define SHAPE_API __declspec(dllimport)
#endif // SHAPE_BUILD
#else
#define SHAPE_API
#endif // _WIN32

// Forward declaration of std::string with SHAPE_API
//
//SHAPE_API extern template class std::basic_string<char, std::char_traits<char>, std::allocator<char>>;


class SHAPE_API Shape
{
private:
  std::string name;

public:
  Shape(std::string name);
  virtual ~Shape() = default;
  std::string get_name() const;
  virtual double get_area() const = 0;
};

#endif