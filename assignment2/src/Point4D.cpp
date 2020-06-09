#include "Point4D.hpp"

// A constructor taking four parameters of type double, specifying a default value of zero for each argument passed to the constructor.
Point4D::Point4D(double x1, double x2, double x3, double x4) {
  point = {x1, x2, x3, x4};
}

// Operator overloads
//// 6. Compound assignment
Point4D& Point4D::operator+=(const Point4D x) {

}

Point4D& Point4D::operator-=(const Point4D x) {

}

Point4D& Point4D::operator*=(const Point4D x) {

}

Point4D& Point4D::operator/=(const Point4D x) {

}

Point4D& Point4D::operator+=(const double x) {

}

Point4D& Point4D::operator-=(const double x) {

}

Point4D& Point4D::operator*=(const double x) {

}

Point4D& Point4D::operator/=(const double x) {

}

//// 9. Unary operators. All are commonly implemented as members.
Point4D& Point4D::operator+(const double x) {

}

Point4D& Point4D::operator-(const double x) {

}

Point4D& Point4D::operator++() { // prefix

}

Point4D& Point4D::operator--() {  // prefix

}

Point4D& Point4D::operator++(int) { // postfix

}

Point4D& Point4D::operator--(int) {  // postfix

}


//// 10. Subscript operator[] (both const and non-const). Use 1-based indexing to preserve the mathematical notation above, regardless of the underlying representation. Must throw std::out_of_range("index out of bounds") if the supplied subscript is invalid.
double& Point4D::operator[](int i) {
  if (i < 0 || i > 3) {
    throw std::out_of_range("Noob~!");
  }
  return point[i];
}

double Point4D::operator[](int i) const {
  if (i < 0 || i > 3) {
    throw std::out_of_range("NOOB!");
  }
  return point[i];
}

//// 11. Function call operator() overload that takes no arguments and returns a double a pproximating the absolute value of the invoking object.
double Point4D::operator()() const {

}

//// 12. Overloaded extraction (input) operator >> for reading Point4D objects
std::ostream& operator<<(std::ostream& output, const Point4D point4d) {

  return output;
}

//// 13. Overloaded insertion (output) operaetor << for writing Point4D objects
std::istream& operator>>(std::istream& input, Point4D point4d) {

  return input;
}
  
//// 14. An absoluteValue() member function to return the absolute value of the invoking object.
double Point4D::absoluteValue() {

}

//// 7. Basic arithmetic operators. Not all can be implemented as members. None modifies its operands. For consistency, all are commonly implemented as free (non-member) functions.
Point4D operator+(const Point4D &x, const Point4D &y) {
  Point4D tmp = Point4D();
  
}

Point4D operator-(const Point4D &x, const Point4D &y) {

}

Point4D operator*(const Point4D &x, const Point4D &y) {

}

Point4D operator/(const Point4D &x, const Point4D &y) {

}


Point4D operator+(const Point4D &x, const double &y) {

}

Point4D operator-(const Point4D &x, const double &y) {

}

Point4D operator*(const Point4D &x, const double &y) {

}

Point4D operator/(const Point4D &x, const double &y) {

}


int operator+(double x, const Point4D &y) {

}

int operator-(double x, const Point4D &y) {

}

int operator*(double x, const Point4D &y) {

}

int operator/(double x, const Point4D &y) {

}


//// 8. Relational operators. All can be impplemented as members. None modifies its operands. For consistency, all are implemented as free functions.

bool operator==(const Point4D &x, const Point4D &y) {

}

bool operator!=(const Point4D &x, const Point4D &y) {

}

bool operator<(const Point4D &x, const Point4D &y) {

}

bool operator<=(const Point4D &x, const Point4D &y) {

}

bool operator>(const Point4D &x, const Point4D &y) {

}

bool operator>=(const Point4D &x, const Point4D &y) {

}

