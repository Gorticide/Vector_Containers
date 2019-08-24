// Vector2.cpp

#include "Vector2.h"
#include <iostream>

Vector2::Vector2()
{
	x_= 0.0; y_ = 0.0;
}


void Vector2::displayPolar()
{
	double rho, theta;
	rho = sqrt(x_*x_ + y_*y_);
	theta = arctan(y_, x_);
	std::cout << "(" << rho << ", " << theta * degrees << ")";
}

void Vector2::displayComponents()
{
	if (x_ < 0) std::cout << "-" << -x_ << 'i';
	else std::cout << x_ << 'i';

	if (y_ < 0) std::cout << " - " << -y_ << 'j';
	else std::cout << " + " << y_ << 'j';
}

Vector2 Vector2::operator+ (Vector2 o2)
{
double x = getx() + o2.getx();
double y = gety() + o2.gety();
double r = sqrt(x*x + y*y);   //converts x and y to Vector2 co-ordinate.
double a = arctan(y, x);
Vector2 v = Vector2::polar(r, a);
return v;
}

// Returns the magnitude of the vector
double Vector2::Magnitude()  {
	return sqrt(x_ * x_ + y_ * y_);
}

// Returns angle vector makes with the postive x-axis
double Vector2::Direction() {
     return arctan(y_, x_) * degrees;
}

// Normalizes the vector
Vector2 Vector2::Normalize(){

	double magnitude = Magnitude();

	if(magnitude != 0){
		return Vector2(x_/magnitude, y_/magnitude);
	}
	else return Vector2(0, 0);
}

double Vector2::dot(Vector2 v)  {

	return x_ * v.getx() + y_ * v.gety();

}

double Vector2::cross(Vector2 v)  {

	return x_ * v.gety() - y_ * v.getx();
}

double Vector2::DistanceTo(Vector2 v){
	float distance = sqrt(pow(v.getx() - x_,2) + pow(v.gety() - y_,2));
	return distance;
}
std::ostream &operator<<(std::ostream &os, Vector2 &v)
{
    os << "[" << v.getx() << "  " << v.gety() << "]";
    return os;
}

double Vector2::arctan(double ordinate_y, double abscissa_x)   {
  double x = abscissa_x;
  double y = ordinate_y;
  double angle, phi;

  // First we must check for vertical vectors.
  // If the vector is vertical, then x == 0, so we cannot use atan(y/x):

  if (x == 0) angle = PI/2;

  // We begin with an angle calculated into the first quadrant by using the
  // absolute value of y/x, then multiples of PI/2 have to be added or subtracted
  // to get the angle into the correct quadrant

  else angle = atan(std::fabs(y/x));   // angle in radians in Quadrant I

  // We keep in terms of radians, and will use constant defined globally:
  //    const double PI = acos(-1);

  if (x >= 0 && y >= 0) phi = angle;           // Quadrant I
  if (x <= 0 && y >= 0) phi = PI - angle;      // Quadrant II
  if (x <= 0 && y <= 0) phi = PI + angle;      // Quadrant III
  if (x >= 0 && y <= 0) phi = 2*PI - angle;    // Quadrant IV (positive value)

  // We will return angle phi, also in radians, in correct quadrant
  // Then, that result in radians can be transformed when printing ( *degrees ):
  // const double degrees = 180.0/PI;

  return phi;

}

Vector2::~Vector2(void)
{
}
