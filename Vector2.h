#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <ostream>

//static constexpr auto PI = acos(-1);   // must compile with -std=c++11 to use this
const double PI = 3.1415926535897932384626433832795;   // if no c++11, use this
const double radians = PI/180.0;
const double degrees = 180.0/PI;

class Vector2
{

private:
	Vector2(double x, double y);     // Rectangular coordinates
	double x_, y_;

	double arctan(double ordinate_y, double abscissa_x);



public:
	Vector2();

	static Vector2 rectangular(double x, double y);   // Rectangular coordinates
	static Vector2 polar(double rho, double theta);   // Polar coordinates
	// These static methods are the so-called "named constructors"

	~Vector2();
	double getx()  {return x_;}
	double gety()  {return y_;}
	double dot(Vector2 v);
	double cross(Vector2 v);
	double Magnitude();
	double Direction();
	Vector2 Normalize();
	double DistanceTo(Vector2 vector);
	void displayComponents();
	void displayPolar();

	Vector2 operator+ (Vector2 o2);
	friend std::ostream &operator<<(std::ostream &os, Vector2 &v);
};
inline Vector2::Vector2(double x, double y)
	: x_(x), y_(y) { }

inline Vector2 Vector2::rectangular(double x, double y)
{ return Vector2(x, y); }

inline Vector2 Vector2::polar(double rho, double theta)
{ return Vector2(rho*std::cos(theta), rho*std::sin(theta)); }


#endif
