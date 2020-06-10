#include <iostream>
#include <stdexcept>
#include <array>

#define FOUR 4

class Point4D
{
private:
  static double tolerance;
  std::array<double, 4> point;
  
  
public:
  
  // A constructor taking four parameters of type double, specifying a default value of zero for each argument passed to the constructor.
  explicit Point4D(double x1 = 0, double x2 = 0, double x3 = 0, double x4 = 0);

  // Copy constructor
  Point4D(const Point4D &other) = default;

  static void setTolerance(double tol);
  static double getTolerance();

  // Defaulted assignment operator
  Point4D& operator=(const Point4D&) = default;
  
  Point4D inverse() const;
  // Destructor
  virtual ~Point4D() = default;

  // Operator overloads
  //// 6. Compound assignment
  Point4D& operator+=(const Point4D x);
  Point4D& operator-=(const Point4D x);
  Point4D& operator*=(const Point4D x);
  Point4D& operator/=(const Point4D x);

  Point4D& operator+=(const double x);
  Point4D& operator-=(const double x);
  Point4D& operator*=(const double x);
  Point4D& operator/=(const double x);

  //// 9. Unary operators. All are commonly implemented as members.
  Point4D operator+();
  Point4D operator-();
  Point4D& operator++(); // prefix
  Point4D& operator--(); // prefix
  Point4D operator++(int); // postfix
  Point4D operator--(int); // postfix

  //// 10. Subscript operator[] (both const and non-const). Use 1-based indexing to preserve the mathematical notation above, regardless of the underlying representation. Must throw std::out_of_range("index out of bounds") if the supplied subscript is invalid.
  double& operator[](int);
  double operator[](int) const;

  //// 11. Function call operator() overload that takes no arguments and returns a double a pproximating the absolute value of the invoking object.
  double operator()() const;

  //// 12. Overloaded extraction (input) operator >> for reading Point4D objects
  friend std::ostream& operator<<(std::ostream&, const Point4D point4d);

  //// 13. Overloaded insertion (output) operaetor << for writing Point4D objects
  friend std::istream& operator>>(std::istream&, Point4D point4d);
  
  //// 14. An absoluteValue() member function to return the absolute value of the invoking object.
  double absValue() const;
};

//// 7. Basic arithmetic operators. Not all can be implemented as members. None modifies its operands. For consistency, all are commonly implemented as free (non-member) functions.

Point4D operator+(const Point4D &x, const Point4D &y);
Point4D operator-(const Point4D &x, const Point4D &y);
Point4D operator*(const Point4D &x, const Point4D &y);
Point4D operator/(const Point4D &x, const Point4D &y);

Point4D operator+(const Point4D &x, const double &y);
Point4D operator-(const Point4D &x, const double &y);
Point4D operator*(const Point4D &x, const double &y);
Point4D operator/(const Point4D &x, const double &y);

Point4D operator+(double x, const Point4D &y);
Point4D operator-(double x, const Point4D &y);
Point4D operator*(double x, const Point4D &y);
Point4D operator/(double x, const Point4D &y);

//// 8. Relational operators. All can be impplemented as members. None modifies its operands. For consistency, all are implemented as free functions.

bool operator==(const Point4D &x, const Point4D &y);
bool operator!=(const Point4D &x, const Point4D &y);
bool operator<(const Point4D &x, const Point4D &y);
bool operator<=(const Point4D &x, const Point4D &y);
bool operator>(const Point4D &x, const Point4D &y);
bool operator>=(const Point4D &x, const Point4D &y);
