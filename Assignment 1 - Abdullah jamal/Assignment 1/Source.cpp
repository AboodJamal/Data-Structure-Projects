#include<iostream>
#include"Flight.h"
using namespace std;


int main()
{
    Flight flight;
    int choice;

    while (true) 
    {
        cout << " --------------- Flight Reservation System Menu: --------------- " << endl;
        cout << "1. Reserve a newly empty seat" <<endl;
        cout << "2. Delete a reserved seat" <<endl;
        cout << "3. Delete all reserved seats" << endl;
        cout << "4. Print out flight seats map" <<endl;
        cout << "5. Quit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            flight.reserve_new();
            break;
        case 2:
            flight.delete_seat();
            break;
        case 3:
            flight.delete_all_seat();
            break;
        case 4:
            flight.print_seats();
            break;
        case 5:
            cout << " Thank you, Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option (from 1to )." << endl;
        }
    }
}