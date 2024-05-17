#include<iostream>
using namespace std;

class Rectangle : public Shape
{
private:
	float l, w;
public:
    Rectangle(float x, float y, float l, float w) : Shape(x, y), l(l), w(w) {}

    void getCoordinates()  {
        cout << "Rectangle";
        Shape::getCoordinates();
    }

    float getArea() const  {
        return l * w;
    }

    float operator + (const Rectangle& obj) const
    {
        return(this->getArea() + obj.getArea());
    }

};