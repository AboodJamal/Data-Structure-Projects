#include<iostream>
#include"Seat.h"
using namespace std;

class Flight
{
private:
	Seat* seats[9];
	int counter=0;
public:
	Flight()
	{
		int firstS = 11;
		for (int i = 0; i < 9; i++)
		{
			if (i < 3)
			{
				seats[i] = new Seat[2];
				seats[i][0].Set_seat(firstS);
				seats[i][1].Set_seat(firstS+1);
				firstS += 10;
			}
			else
			{
				seats[i] = new Seat[4];
				seats[i][0].Set_seat(firstS);
				seats[i][1].Set_seat(firstS + 1);
				seats[i][2].Set_seat(firstS + 2);
				seats[i][3].Set_seat(firstS + 3);
				firstS += 10;
			}
		}
	}
	bool isValid(int n)
	{

		for (int i = 0; i < 9; i++)
		{

			if (i < 3)
			{
				if (n == seats[i][0].Get_seat() or n == seats[i][1].Get_seat())
					return true;
			}
			else
			{
				if (n == seats[i][0].Get_seat() or n == seats[i][1].Get_seat() or n == seats[i][2].Get_seat() or n == seats[i][3].Get_seat())
					return true;
			}
			
		}
		return false;
	}

	void reserve_new()
	{
		if (counter >= 30)
		{
			cout << "The airplane is full" << endl;
			return;
		}
		int num;
		cout << "Enter a valid seat number : ";
		cin >> num;
		while(!isValid(num)) 
		{
			cout << "Invalid seat number. Please enter a valid seat number :" << endl;
			cin >> num;
		}
		counter++;
		for (int i = 0; i < 9; i++)
		{

			if (i < 3)
			{
				for (int j = 0; j < 2; j++)
				{
					if (num == seats[i][j].Get_seat())
					{
						if (seats[i][j].Get_reserved() == true)
						{
							cout << " Sorry the seat is taken" << endl;
							reserve_new();
							break;
						}
						else
						{
							cout << " Reservation is done" << endl;
							seats[i][j].Set_reserved(true);
							return;
						}
						
					}
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					if (num == seats[i][j].Get_seat()) 
					{
						if (seats[i][j].Get_reserved() == true) 
						{ 
							cout << " Sorry the seat is taken" << endl;
							reserve_new();
							break; 
						}
						else
						{
							cout << " Reservation is done" << endl;
							seats[i][j].Set_reserved(true); 
							return;
						}

					}
				}
			}

		}
	}

	void delete_seat()
	{
		if (counter <= 0)
		{
			cout << "No seats reserved to delete" << endl;
			return;
		}
		int num;
		cout << "Enter a valid seat number : ";
		cin >> num;
		while (!isValid(num))
		{
			cout << "Invalid seat number. Please enter a valid seat number :" << endl;
			cin >> num;
		}
		counter--;
		for (int i = 0; i < 9; i++)
		{

			if (i < 3)
			{
				for (int j = 0; j < 2; j++)
				{
					if (num == seats[i][j].Get_seat())
					{
						if (seats[i][j].Get_reserved() == false)
						{
							cout << " Sorry, but the seat is empty" << endl;
							delete_seat(); 
							break;
						}
						else
						{
							cout << " The seat is empty now" << endl;
							seats[i][j].Set_reserved(false);
							return;
						}

					}
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					if (num == seats[i][j].Get_seat())
					{
						if (seats[i][j].Get_reserved() == false)
						{
							cout << " Sorry, but the seat is empty" << endl;
							delete_seat();
							break;
						}
						else
						{
							cout << " The seat is empty now " << endl;
							seats[i][j].Set_reserved(false);
							return;
						}

					}
				}
			}

		}
	}
	void delete_all_seat()
	{
		if (counter <= 0)
		{
			cout << "No seats reserved to delete" << endl;
			return;
		}
		for (int i = 0; i < 9; i++)
		{

			if (i < 3)
			{
				for (int j = 0; j < 2; j++)
				{
					seats[i][j].Set_reserved(false);
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					seats[i][j].Set_reserved(false);
				}
			}

		}
		cout << " All seats are deleted now " << endl;
		counter = 0;
	}
	void print_seats()
	{
		int count = 0;
		for (int i = 0; i < 9; i++)
		{

			if (i < 3)
			{
				for (int j = 0; j < 2; j++)
				{
					if (seats[i][j].Get_reserved() == true)
						count++;
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					if (seats[i][j].Get_reserved() == true) 
						count++; 
				}
			}

		}
		for (int i = 0; i < 9; i++)
		{
			if (i < 3)
			{
				for (int j = 0; j < 2; j++)
				{
					if (seats[i][j].Get_reserved() == true)
						cout << seats[i][j].Get_seat() << " (reserved)" << "     ";
					else
						cout << seats[i][j].Get_seat() << " (not reserved)" << "     ";
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					if (seats[i][j].Get_reserved() == true) 
						cout << seats[i][j].Get_seat() << " (reserved)" << "     "; 
					else 
						cout << seats[i][j].Get_seat() << " (not reserved)" << "     "; 
				}
			}
			cout << endl;
		}
		cout << " The number of reserved seats is " << count << endl;
	}

};