#include<iostream>
using namespace std;

class Triangle: public Shape
{
private:
	float l, h;
public:
    Triangle(float x, float y, float l, float h) : Shape(x, y), l(l), h(h) {}

    void getCoordinates()  {
        cout << "Triangle ";
        Shape::getCoordinates();
    }

    float getArea() const  {
        return 0.5 * l * h;
    }

	float operator + (const Triangle& obj)
	{
		return(getArea() + obj.getArea());
	}
};