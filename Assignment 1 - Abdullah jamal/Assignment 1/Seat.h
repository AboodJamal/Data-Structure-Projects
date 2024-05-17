#include<iostream>
using namespace std;

class Seat
{
private:
	int seat_number;
	bool reserved=0;
public:
	Seat()
	{
		seat_number = 0;
		reserved = 0;
	}
	int Get_seat()
	{
		return seat_number;
	}
	void Set_seat(int n)
	{
		seat_number = n;
	}
	bool Get_reserved()
	{
		return reserved;
	}
	void Set_reserved(bool res)
	{
		reserved = res;
	}
	Seat(int n)
	{
		seat_number = n;
		reserved = false;
	}
	void printInfo()
	{
		cout << "The seat number is " << seat_number << endl;
		if (reserved)
			cout << "The seat is reserved" << endl;
		else 
			cout << "The seat is free" << endl;
	}

};