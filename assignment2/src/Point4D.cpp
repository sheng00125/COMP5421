#include "Point4D.hpp"

// A constructor taking four parameters of type double, specifying a default value of zero for each argument passed to the constructor.
Point4D::Point4D(double x1, double x2, double x3, double x4) {
  point = {x1, x2, x3, x4};
}

Point4D Point4D::invert() const {
  double b = (point[0]*point[2])-(point[1]*point[3]);
  Point4D tmp = Point4D(point[2], -point[1], point[0], -point[3]);
  if(b == 0)
  {
    throw "Matrix is not invertable"; 
  }
  tmp *= b;
  return tmp;
}

// Operator overloads
//// 6. Compound assignment
Point4D& Point4D::operator+=(const Point4D x) {
  *this = *this + x;
  return *this;
}

Point4D& Point4D::operator-=(const Point4D x) {
  *this = *this - x;
  return *this;
}

Point4D& Point4D::operator*=(const Point4D x) {
  *this = *this * x;
  return *this;
}

Point4D& Point4D::operator/=(const Point4D x) {
  *this = *this / x;
  return *this;
}

Point4D& Point4D::operator+=(const double x) {
  *this = *this + x;
  return *this;
}

Point4D& Point4D::operator-=(const double x) {
  *this = *this - x;
  return *this;
}

Point4D& Point4D::operator*=(const double x) {
  *this = *this + x;
  return *this;
}

Point4D& Point4D::operator/=(const double x) {
  *this = *this / x;
  return *this;
}

//// 9. Unary operators. All are commonly implemented as members.
Point4D Point4D::operator+() {
  Point4D tmp;

  for (int i = 0; i < FOUR; ++i) {
    tmp[i] = +this->point[i];
  }

  return tmp;
}

Point4D Point4D::operator-() {
  Point4D tmp;

  for (int i = 0; i < FOUR; ++i) {
    tmp[i] = -this->point[i];
  }

  return tmp;
}

Point4D& Point4D::operator++() { // prefix

  for (int i = 0; i < FOUR; ++i) {
    ++this->point[i];
  }
  return *this;
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
    throw std::out_of_range("double& Point4D::operator[] : index out of range.");
  }
  return point[i];
}

double Point4D::operator[](int i) const {
  if (i < 0 || i > 3) {
    throw std::out_of_range("double Point4D::operator[] : index out of range");
  }
  return point[i];
}

//// 11. Function call operator() overload that takes no arguments and returns a double a pproximating the absolute value of the invoking object.
double Point4D::operator()() const {
  return absoluteValue();
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
double Point4D::absoluteValue() const {
	double sum = 0;
	for (int i = 0; i < FOUR; i++) {
		if (point[i] < 0)
			sum += -point[i];
		else
			sum += point[i];
	}
	return sum;
}

//// 7. Basic arithmetic operators. Not all can be implemented as members. None modifies its operands. For consistency, all are commonly implemented as free (non-member) functions.
Point4D operator+(const Point4D &x, const Point4D &y) {
  Point4D tmp = Point4D();
  for (int i = 0; i < FOUR; i++) {
	  tmp[i] = x[i] + y[i];
  }
  return tmp;
}

Point4D operator-(const Point4D &x, const Point4D &y) {
  Point4D tmp = Point4D();
  for (int i = 0; i < FOUR; i++) {
	  tmp[i] = x[i] - y[i];
  }
  return tmp;
}

Point4D operator*(const Point4D &x, const Point4D &y) {
  Point4D tmp = Point4D();
  tmp[0] = x[0]*y[0]+x[1]*y[3];
  tmp[1] = x[0]*y[1]+x[1]*y[2];
  tmp[2] = x[3]*y[1]+x[2]*y[2];
  tmp[3] = x[3]*y[0]+x[2]*y[3];
  return tmp;
}

Point4D operator/(const Point4D &x, const Point4D &y) {
  Point4D tmp = Point4D();
  tmp = x * y.invert();
  return tmp;
}


Point4D operator+(const Point4D &x, const double &y) {
  Point4D tmp = Point4D(x);
  for (int i = 0; i < FOUR; i++) {
    tmp[i] += y;
  }
  return tmp;
}

Point4D operator-(const Point4D &x, const double &y) {
  Point4D tmp = Point4D(x);
  for (int i = 0; i < FOUR; i++) {
    tmp[i] -= y;
  }
  return tmp;
}

Point4D operator*(const Point4D &x, const double &y) {
  Point4D tmp = Point4D(x);
  for (int i = 0; i < FOUR; i++) {
    tmp[i] *= y;
  }
  return tmp;
}

Point4D operator/(const Point4D &x, const double &y) {
  Point4D tmp = Point4D(x);
  for (int i = 0; i < FOUR; i++) {
    tmp[i] /= y;
  }
  return tmp;
}

Point4D operator+(double x, const Point4D &y) {
  Point4D tmp = Point4D(y);
  for (int i = 0; i < FOUR; i++) {
    tmp[i] += x;
  }
  return tmp;
}

Point4D operator-(double x, const Point4D &y) {
  Point4D tmp = Point4D(y);
  for (int i = 0; i < FOUR; i++) {
    tmp[i] -= x;
  }
  return tmp;
}

Point4D operator*(double x, const Point4D &y) {
  Point4D tmp = Point4D(y);
  for (int i = 0; i < FOUR; i++) {
    tmp[i] *= x;
  }
  return tmp;
}

Point4D operator/(double x, const Point4D &y) {
  Point4D tmp = Point4D(y);
  for (int i = 0; i < FOUR; i++) {
    tmp[i] /= x;
  }
  return tmp;
}

//// 8. Relational operators. All can be impplemented as members. None modifies its operands. For consistency, all are implemented as free functions.

bool operator==(const Point4D &x, const Point4D &y) {
  return (x - y)() <= Point4D::getTolerance();
}

bool operator!=(const Point4D &x, const Point4D &y) {
  return (x - y)() > Point4D::getTolerance();
}

bool operator<(const Point4D &x, const Point4D &y) {
  return x != y && x() < y();
}

bool operator<=(const Point4D &x, const Point4D &y) {
  return x < y || x == y;
}

bool operator>(const Point4D &x, const Point4D &y) {
  return x != y && x() > y();
}

bool operator>=(const Point4D &x, const Point4D &y) {
  return x > y || x == y;
}

