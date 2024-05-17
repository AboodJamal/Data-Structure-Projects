#include<iostream>
using namespace std;

class Circle : public Shape
{
private:
	float r;
public:
	Circle(float r, float d1, float d2) : Shape(d1, d2), r(r) {}

	float getArea() const  
	{
		 return (22/7.0) * r * r;
	}
	void getCoordinates()  {
		cout << "Circle radius is => "<< r;
	}
	float operator + (const Circle& obj) const
	{
		return(this->getArea() + obj.getArea());
	}
};