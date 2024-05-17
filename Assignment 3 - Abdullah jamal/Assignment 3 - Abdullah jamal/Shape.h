#include<iostream>
using namespace std;

class Shape
{
private:
	float x, y;
public:
	Shape(double x, double y) : x(x), y(y) {}

	virtual void getCoordinates() const
	{
		cout << " coordinates are => ( " << x << " ) , ( " << y << " )" << endl;
	}
	virtual float getArea() const = 0;

};