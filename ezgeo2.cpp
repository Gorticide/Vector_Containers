//  g++ -g ezgeo2.cpp -std=c++11 -o ezgeo2
// Mike Hentrich
// September 2018

#include <iostream>
#include <cmath>
#include <complex>


typedef std::complex<double> point;

// define x, y as real(), imag()
#define x real()
#define y imag()

// #define PI 3.1415926535897932384626433832795         // PI 4*atan(1) or acos(-1)
// #define radians PI/180.0
// #define degrees 180.0/PI

//static constexpr auto PI = acos(-1);   // must compile with -std=c++11 to use this
//const double PI = 3.1415926535897932384626433832795;   // if no c++11, use this
static constexpr auto PI = acos(-1);
const double radians = PI/180.0;
const double degrees = 180.0/PI;


template<class T>
std::istream& operator>> (std::istream& is, std::complex<T>& p)
{
  T value;
  is >> value;
  p.real(value);
  is >> value;
  p.imag(value);
  return is;
}

point intersection(point a, point b, point p, point q)
{
  double c1 = (conj(p - a) * (b - a)).y;   // cross product (p-a)X(b-a)
  double c2 = (conj(q - a) * (b - a)).y;   // cross product (q-a)X(b-a)
  return (c1*q - c2*p) / (c1 - c2);
}

int main()
{
  int menu;
  double rho, theta, abscissa, ordinate, bearing;
  point a, b, p, q;


	// MENU
	do    {
		 std::cout << "\n-----------------------------------------------------------------------\n";
		 std::cout << "Please choose the operation you would like to perform:"<< std::endl;
		 std::cout << "\n-----------------------------------------------------------------------\n";
		 std::cout << "0  :   EXIT\n"
                    << "1  :   Cartesian to Polar (two points)\n"
										<< "2  :   Cartesian to Polar (one point)  [norm, direction]\n"
										<< "3  :   Polar to Cartesian\n"
                    << "4  :   Translate counter-clockwise from EAST (+x-axis)\n"
                    << "         to bearing clockwise from NORTH (+y-axis)\n"
                    << "\n"
                    << "5  :   Given vector v = (x,y), find norm ||v|| = sqrt(x^2 + y^2)\n"
                    << "6  :   dot product\n"
                    << "7  :   cross product\n"
                    << "8  :   Find magnitude and direction of resultant u + v\n"
                    << "9  :   Given 2 pairs of <distance, direction>,\n"
                    << "        find distance and bearing from origin.\n"
                    << "\n"
                    << "10 :  angle of elevation (between points a and b with x-axis)\n"
                    << "11 :  Angle ABC\n"
                    << "12 :  Project point p onto vector v\n"
                    << "13 :  Project point p onto line(a,b)\n"
                    << "14 :  Reflect point p across line(a,b)\n"
                    << "15 :  Intersection of line(a,b) and line(p,q)\n"
										<< "\n-----------------------------------------------------------------------\n"
										<< "Operation to perform: ";
			std::cin >> menu;

      switch(menu)  {
        case 1:                                             // Cartesian to Polar (two points)
          std::cout << "Enter first point: \n";
          std::cin >> a;
          std::cout << "Enter second point: \n";
          std::cin >> b;
          std::cout << b << " - " << a << " = " << b - a << '\n';
          p = point(abs(b-a), arg(b-a));
          std::cout << "The magnitude of the resulatant vector is " << p.x << '\n';
          std::cout << "The direction of the vector (in degrees) is " << p.y * degrees << '\n';
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

        case 2:                         //      Cartesian to Polar (one point)  [standard position]
          std::cout << "Initial point is origin (0,0).\n";
          std::cout << "Enter coordinates of terminal point (x, y): \n";
          std::cin >> a;
          std::cout << "||v||^2 = " << a.x*a.x << " + " << a.y*a.y << " = " << norm(a) << '\n';
          std::cout << "The magnitude, or norm, of vector v is also known as absolute value.\n";
          std::cout <<  "For v = " << a << ": ||v|| = " << std::abs(a) << "\n\n";
          std::cout << "The direction of the vector (in degrees) is " << std::arg(a) * degrees << '\n';

          /*
          Note that std::arg is as if the function is implemented as
          std::atan2(std::imag(a), std::real(a)).
          Hence, for our purposes, atan2(y,x)
          */

          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

        case 3:                  // Polar to Cartesian rectangular coordinates
        std::cout << "Enter the polar componests of the vector:\n";
        std::cout << "<magnitude> <phase angle>\n";
        std::cin >> a;
        std:: cout << "Cartesian/Rectangular coordinates (x, y) = " << std::polar(a.x, a.y*radians);
        std::cin.ignore(1024, '\n');
        std::cout << "\nPress enter to continue ...";
        std::cin.get();
        break;

        case 4:       // Translate clockwise direction to bearing clockwise from NORTH (+y-axis)
        /*
        My idea is to first convert the polar coordinates to rectangular point.
        Then bearing = 90 - degrees*atan2(point.y, point.x)
        where degrees = 180/PI
        */

          std::cout << "\nEnter angle in degrees counter-clockwise from horizontal axis EAST: ";
          std::cin >> theta;
          std::cout << "Enter the magnitude of the vector: ";
          std::cin >> rho;
          p = std::polar(rho, theta*radians);
          bearing = 90 - degrees*atan2(p.y, p.x);
          std::cout << "\nThe navigational bearing measured clockwise from vertical axis NORTH:\n";
          std::cout << bearing << " degrees\n\n";
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

          case 5:     // Given vector v = (x,y), find norm ||v|| = sqrt(x^2 + y^2)
            std::cout << "\nEnter coordinates (x,y) [components of vector v]:\n";
            std::cin >> a;
            std::cout << "||v|| = " << std::abs(a) << '\n';
            std::cin.ignore(1024, '\n');
            std::cout << "\nPress enter to continue ...";
            std::cin.get();
            break;

        case 6:      // dot product
          std::cout << "Enter first vector: \n";
          std::cin >> a;
          std::cout << "Enter second vector: \n";
          std::cin >> b;
          p = conj(a) * b;
          std::cout << a << "dot" << b << " = " << p.x << '\n';
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

        case 7:     // cross product
          std::cout << "Enter first vector: \n";
          std::cin >> a;
          std::cout << "Enter second vector:\n";
          std::cin >> b;
          p = conj(a) * b;
          std::cout << a << "X" << b << " = " << p.y << '\n';
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

        case 8:   // magnitude and direction of resultant u + v
         std::cout << "Enter the polar components of vector u:\n";
         std::cout << "<magnitude> <phase angle>\n";
         std::cin >> a;
         std::cout << "Enter the polar components of vector v:\n";
         std::cout << "<magnitude> <phase angle>\n";
         std::cin >> b;
         std::cout << "\n\nResultant vector has rectangluar components: ";
         p = std::polar(a.x, a.y*radians);
         q = std::polar(b.x, b.y*radians);
         std::cout << p + q << std::endl;
         std::cout << "Polar components:\n";
         std::cout << "Magnitude ||u + v|| = " << std::abs(point(a.x, b.x));
         theta = std::atan2(p.y + q.y, p.x + q.x);
         std::cout << "\nPhase angle : " << theta * degrees << std::endl;
         std::cin.ignore(1024, '\n');
         std::cout << "\nPress enter to continue ...";
         std::cin.get();
         break;

        case 9:
          std::cout << "Enter first distance traveled and in what direction (from North):\n";
          std::cout << "<distance> <direction>\n";
          std::cin >> a;
          std::cout << "Enter second distance traveled and in what direction (from North):\n";
          std::cout << "<distance> <direction>\n";
          std::cin >> b;
          std::cout << "\nResultant vector has rectangluar components: ";
          p = std::polar(a.x, a.y*radians);
          q = std::polar(b.x, b.y*radians);
          std::cout << p + q << std::endl;
          std::cout << "\nDistance from origin: " << std::abs(p + q);
          theta = std::atan2(p.y + q.y, p.x + q.x);
          std::cout << "\n\nThe navigational bearing measured clockwise from vertical axis NORTH:\n";
          std::cout << theta * degrees << std::endl;
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

        case 10:   // angle of elevation (between points a and b with x-axis)
          std::cout << "Angle of Elevation = slope of line between points a and b\n";
          std::cout << "The arctan of the slope of the line connecting a and b.\n";
          std::cout << "In other words, the angle that the line connecting a and b forms\n";
          std::cout << "counter-clockwise with the x-axis in the positive direction. \n";
          std::cout << "\nEnter initial point:\n";
          std::cin >> a;
          std::cout << "Enter terminal point:\n";
          std::cin >> b;
          std::cout << "Angle of Elevation between " << a << " and " << b << " is "
                         << std::arg(b - a)*degrees << '\n';
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;



        case 11:   // Find angle ABC
          std::cout << "\nWith vertices A, B, and C, we want to find the angle ABC.\n";
          std::cout << "So you will enter points A(x1,y1), B(x2, y2), and C(x3, y3).\n\n";
          std::cout << "Enter first point A(x1, y1): \n";
          std::cin >> a;
          std::cout << "Enter second point B(x2, y2): \n";
          std::cin >> b;
          std::cout << "Enter third point C(x3, y3): \n";
          std::cin >> p;  // p represents c, of course
          std::cout << "\nThe angle ABC is "
                          << std::abs(remainder(std::arg(a-b) - std::arg(p-b), 2.0 * PI)) * degrees << " degrees.\n";
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

        case 12:   // Project point p onto vector v
          std::cout << "\nTo project point p onto vector v:    v * dot(p, v)/norm(v)\n";
          std::cout << "where norm(v) is actually the squared absolute value (norm?).\n";
          std::cout << "Enter the point (x,y) to be projected onto vector v:\n";
          std::cin >> p;
          std::cout << "Enter the components of the 2D vector:\n";
          std::cin >> a;
          std::cout << "\nProjection of point " << p << " onto vector " << a << " = "
                         << a * (conj(p)*a).x / norm(a);
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

        case 13:   // Project point p onto line(a,b)
          std::cout << "\nTo project the point p onto the line(a, b), \n";
          std::cout << "first enter the coordinates the point (x, y):\n";
          std::cin >> p;
          std::cout << "\nNow enter the line by entering coordinates of two points.\n";
          std::cout << "Enter first point (x1, y1): \n";
          std::cin >> a;
          std::cout << "Enter second point (x2, y2): \n";
          std::cin >> b;
          std::cout << "\nThe result of this projection is a vector: "
                         << a + (b - a) * (conj(p - a) * (b - a)).x / norm(b - a);
          std::cin.ignore(1024, '\n');
          std::cout << "\nPress enter to continue ...";
          std::cin.get();
          break;

        case 14:    // Reflect point p across line(a,b)
          std::cout << "\nTo project the point p across the line(a, b), \n";
          std::cout << "first enter the coordinates the point (x, y):\n";
          std::cin >> p;
          std::cout << "\nNow enter the line by entering coordinates of two points.\n";
          std::cout << "Enter first point (x1, y1): \n";
          std::cin >> a;
          std::cout << "Enter second point (x2, y2): \n";
          std::cin >> b;
          std::cout << "\nThe result of this projection is a vector: "
                       << a + conj( (p - a) / (b - a) ) * (b - a);
        std::cin.ignore(1024, '\n');
        std::cout << "\nPress enter to continue ...";
        std::cin.get();
        break;

        case 15:                //    Intersection of line(a,b) and line(p,q)
          std::cout << "\nTo find the point of intersection of line(a, b) and line(p, q),\n";
          std::cout << "enter the coordinates of 4 points.\n";
          std::cout << "Enter first point of first line (x1, y1): \n";
          std::cin >> a;
          std::cout << "Enter second point of first line (x2, y2): \n";
          std::cin >> b;
          std::cout << "Enter first point of second line (x3, y3): \n";
          std::cin >> p;
          std::cout << "Enter second point of second line (x4, y4): \n";
          std::cin >> q;
          std::cout << "\nThe solution set is {" << intersection(a, b, p, q) << "}";
          std::cout << std::endl << std::endl;
          break;

      } // END SWITCH

} while (menu != 0);

} // END MAIN

/*
Complex numbers are of the form a + bi, where a is the real part and b imaginary.


Functions using std::complex

Vector addition: a + b

Scalar multiplication: r * a

Dot product: (conj(a) * b).x

Cross product: (conj(a) * b).y

notice: conj(a) * b = (ax*bx + ay*by) + i (ax*by — ay*bx)

Squared distance: norm(a - b)

Euclidean distance: abs(a - b)

Angle of elevation: arg(b - a)

note: arg ---> "Angle of Elevation" = "slope of line between points a and b"
The arctan of the slope of the line connecting a and b.
In other words, the angle that the line connecting a and b forms with the x-axis in positive direction.

Slope of line (a, b): tan(arg(b - a))

Polar to cartesian: polar(r, theta)

Cartesian to polar: point(abs(p), arg(p))

Rotation about the origin: a * polar(1.0, theta)

Rotation about pivot p: (a-p) * polar(1.0, theta) + p

Angle ABC: abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))

remainder normalizes the angle to be between [-PI, PI].
Thus, we can get the positive non-reflex angle by taking its abs value.

Project p onto vector v: v * dot(p, v) / norm(v);

Project p onto line (a, b): a + (b - a) * dot(p - a, b - a) / norm(b - a)

Reflect p across line (a, b): a + conj((p - a) / (b - a)) * (b - a)

Intersection of line (a, b) and (p, q):

point intersection(point a, point b, point p, point q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}

For dealing with std::cin
template<class T>
istream& operator>> (istream& is, complex<T>& p) {
  T value;
  is >> value;
  p.real(value);
  is >> value;
  p.imag(value);
  return is;
}

MORE NOTES ABOUT std::complex ---> std::arg
Calculates the phase angle (in radians) of the complex number z in the interval (−π, π).
Errors and special cases are handled as if the function is implemented as
std::atan2(std::imag(z), std::real(z)).


ROOTS OF UNITY:

double const pi = 4 * std::atan(1);

void Roots_of_Unity(int Nth)
{
  for (int n = 2; n <= Nth; ++n)
  {
    std::cout << n << ": ";
    for (int k = 0; k < n; ++k)
      std::cout << std::polar(1, 2*pi*k/n) << " ";
    std::cout << std::endl;
  }
}

*/
