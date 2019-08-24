//  g++ -g polarvec.cpp -std=c++11 -o pvec
// Mike Hentrich
// 8 September 2018

#include "Vector2.h"
#include <iostream>
#include <cmath>


int main()   {

   int menu;
   double a, b, angle, M, x1, y1, x2, y2;

	// MENU
	do    {
		 std::cout << "\n-----------------------------------------------------------------------\n";
		 std::cout << "Please choose the operation you would like to perform:"<< std::endl;
		 std::cout << "\n-----------------------------------------------------------------------\n";
		 std::cout << "0  :   EXIT\n"
		                << "1  :   Given v = [a, b] = ai + bj, return magnitude and direction\n"
                    << "2  :   Cartesian to Polar (two points)\n"
										<< "3  :   Polar to Cartesian\n"
                    << "4  :   dot product\n"
                    << "5  :   cross product\n"
                    << "6  :   Find magnitude and direction of resultant u + v\n"
										<< "7  :   Given initial point and vector components, find terminal point\n"
										<< "8  :   Given terminal point and vector components, find initial point\n"
										<< "\n-----------------------------------------------------------------------\n"
										<< "Operation to perform: ";
			std::cin >> menu;

      switch(menu)  {

				case 1:   // Given components of ai + bj, return magnitude and direction
        {
          std::cout << "Enter the x and y components of ai + bj.\n";
					std::cout << "component a: ";
					std::cin >> a;
					std::cout << "component b: ";
					std::cin >> b;
					Vector2 v = Vector2::rectangular(a, b);

					std::cout << "\n\n||v||^2 = " << pow(v.getx(), 2) << " + "
					          << pow(v.gety(), 2) << " = " << pow(v.getx(), 2) + pow(v.gety(), 2) << '\n';
					std::cout << "\nThe magnitude, or norm, of vector v is also known as absolute value.\n";
					std::cout <<  "For v = [" << v.getx() << ", " << v.gety()
					          << "] : ||v|| = " << v.Magnitude() << '\n';
					std::cout << "\nThe direction of this vector (in degrees) is " << v.Direction() << '\n';
					std::cin.ignore(1024, '\n');
					std::cout << "\nPress enter to continue ...";
					std::cin.get();
				  break;
        }

				case 2:      // Cartesian to Polar (two points)
        {
					std::cout << "Enter coordinates of first point: \n";
          std::cout << "x-coordinate: ";
					std::cin >> x1;
					std::cout << "y-coordinate: ";
					std::cin >> y1;
					std::cout << "Enter coordinates of second point: \n";
					std::cout << "x-coordinate: ";
					std::cin >> x2;
					std::cout << "y-coordinate: ";
					std::cin >> y2;

					std::cout << "(" << x2 << ", " << y2 << ") - ("
					          << x1 << ", " << y1 << ") = (" << x2 - x1 << ", "
										<< y2 - y1 << ")\n";
          Vector2 u = Vector2::rectangular(x2 - x1, y2 - y1);

					std::cout << "\nThe magnitude of the resulatant vector is "
					          << u.Magnitude() << '\n';
					std::cout << "\nThe direction of the vector (in degrees) is "
					          << u.Direction() * degrees << '\n';
					std::cin.ignore(1024, '\n');
					std::cout << "\nPress enter to continue ...";
					std::cin.get();
					break;
        }

				case 3:      // Polar to Cartesian rectangular coordinates
        {
				  std::cout << "Enter the polar components of the vector:\n";
				  std::cout << "<magnitude> : ";
				  std::cin >> M;
				  std::cout << "<phase angle> : ";
				  std::cin >> angle;

				  Vector2 p = Vector2::polar(M, angle*radians);

				  std:: cout << "\n\nRectangular components of v = [a, b] = ai + bj: ";
				  p.displayComponents();
				  std::cin.ignore(1024, '\n');
				  std::cout << "\nPress enter to continue ...";
				  std::cin.get();
				  break;
       }

			case 4:      // dot product
      {
			  std::cout << "Enter components of first vector: \n";
			  std::cout << "x-component: ";
			  std::cin >> x1;
			  std::cout << "y-component: ";
			  std::cin >> y1;
			  Vector2 v1 = Vector2::rectangular(x1, y1);
			  std::cout << "\n\nEnter components of second vector: \n";
			  std::cout << "x-component: ";
			  std::cin >> x2;
			  std::cout << "y-component: ";
			  std::cin >> y2;
			  Vector2 v2 = Vector2::rectangular(x2, y2);

				std::cout << "\n\nDOT PRODUCT: " << v1 << " dot " << v2 << " = "
									<< v1.dot(v2) << '\n';

				std::cin.ignore(1024, '\n');
				std::cout << "\nPress enter to continue ...";
				std::cin.get();
				break;
      }

			case 5:     // cross product
      {
			  std::cout << "Enter components of first vector: \n";
			  std::cout << "x-component: ";
			  std::cin >> x1;
			  std::cout << "y-component: ";
			  std::cin >> y1;
			  Vector2 u1 = Vector2::rectangular(x1, y1);
			  std::cout << "Enter components of second vector: \n";
			  std::cout << "x-component: ";
			  std::cin >> x2;
			  std::cout << "y-component: ";
			  std::cin >> y2;
			  Vector2 u2 = Vector2::rectangular(x2, y2);

				std::cout << "\n\nCROSS PRODUCT: " << u1 << " X " << u2
                  << " = " << u1.cross(u2) << '\n';

				std::cin.ignore(1024, '\n');
				std::cout << "\nPress enter to continue ...";
				std::cin.get();
				break;
      }

      case 6:   // magnitude and direction of resultant u + v
      {
         std::cout << "Enter the polar components of vector u:\n";
				 std::cout << "<magnitude> : ";
 				 std::cin >> M;
 				 std::cout << "<phase angle> : ";
 				 std::cin >> angle;

				 Vector2 p1 = Vector2::polar(M, angle*radians);

         std::cout << "Enter the polar components of vector v:\n";
				 std::cout << "<magnitude> : ";
 				 std::cin >> M;
 				 std::cout << "<phase angle> : ";
 				 std::cin >> angle;

 				 Vector2 p2 = Vector2::polar(M, angle*radians);
         Vector2 q;
         q = p1 + p2;

         std::cout << "\n\nResultant vector has rectangluar components: ";
         q.displayComponents();
				 std::cout << "\n\nThis is vector " << q;
         std::cout << "\n\nResultant vector has polar components: ";
				 q.displayPolar();
         std::cout << "\n\nThat is, magnitude ||u + v|| = "
				           << q.Magnitude();
         std::cout << "\nPhase angle : " << q.Direction() << '\n';

         std::cin.ignore(1024, '\n');
         std::cout << "\nPress enter to continue ...";
         std::cin.get();
         break;
      }

			case 7:  // Given initial point and vector components, find terminal point
      {
			   std::cout << "Enter coordinates of initial point: \n";
				 std::cout << "x-coordinate: ";
			   std::cin >> x1;
			   std::cout << "y-coordinate: ";
			   std::cin >> y1;
				 std::cout << "Enter components of the vector: \n";
				 std::cout << "x-component: ";
				 std::cin >> a;
				 std::cout << "y-component: ";
				 std::cin >> b;
				 x2 = x1 + a;
				 y2 = y1 + b;
				 std::cout << "\nThe coordinates of the terminal point are: "
				           << "(" << x2 << ", " << y2 << ")";
				 std::cin.ignore(1024, '\n');
 				 std::cout << "\nPress enter to continue ...";
 				 std::cin.get();
         break;
      }

			case 8:  // Given terminal point and vector components, find initial point
      {
			  std::cout << "Enter coordinates of terminal point: \n";
			  std::cout << "x-coordinate: ";
			  std::cin >> x2;
			  std::cout << "y-coordinate: ";
			  std::cin >> y2;
			  std::cout << "Enter components of the vector: \n";
			  std::cout << "x-component: ";
			  std::cin >> a;
			  std::cout << "y-component: ";
			  std::cin >> b;
			  x1 = x2 - a;
			  y1 = y2 - b;
			  std::cout << "\nThe coordinates of the terminal point are: "
		  						<< "(" << x1 << ", " << y1 << ")";
			  std::cin.ignore(1024, '\n');
			  std::cout << "\nPress enter to continue ...";
			  std::cin.get();
			  break;
      }

    }  // END switch
	} while (menu != 0);

} // END MAIN
