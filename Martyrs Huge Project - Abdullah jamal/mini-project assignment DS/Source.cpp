#include<iostream>
#include"Stack.h"
#include"Vector.h"
#include"DoublyCircularList.h"
#include"Martyr.h"
#include<string>
#include <fstream>
#include <cstring>  
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
string convertToLowercase(const string& str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
		return tolower(c);
		});
	return result;
}

string* split(string& text) 
{
	int count = 0;
	string* parts = new string[5]; 
	string token = "";
	for (int i = 0; i < text.length(); i++)
	{


		while (text[i] != ',' && i < text.length())
		{
			token += text[i];
			i++;
		}

		if (text[i] == ',')
		{
			parts[count] = token;
			count++; 
			token = "";
		}
		else
		{
			parts[count] = token; 
			break;
		}

	}

	return parts;
}

int main()
{
	fstream fily;
	fily.open("C:\\Users\\Abdullah Jamal\\Desktop\\College\\Second year\\Data structure\\martyrs.csv", ios::in);
	if (!fily.is_open()) {
		cout << "Error opening the file." << std::endl;
		return 1;
	}
	DoublyCircular martyrs_records; 
	string line;
	getline(fily, line);
	while (getline(fily, line))
	{
		string* martyr_info = split(line);
		Martyr martyry;
		martyry.name = martyr_info[0];
		martyry.age = martyr_info[1];
		martyry.location = convertToLowercase(martyr_info[2]);
		martyry.dateOfDeath = martyr_info[3];
		martyry.gender = martyr_info[4];

		martyrs_records.addInOrder(martyry);
	}

	martyrs_records.printLocations();
	int choice;
		while (true)
	{
		cout << "------------- The Menu -------------"<<endl;
		cout << "1.Insert new location record " << endl;
		cout << "2.Update an existing location " << endl;
		cout << "3.Delete an existing location " << endl;
		cout << "4.Search for a location record " << endl;
		cout << "5.Quit" << endl;
		cout << "Choose an option : ";
		cin >> choice;
		while (!(choice > 0 && choice < 6))
		{
			cout << "Wrong Input , Enter again one of these numbers (1 , 2 , 3 , 4 , 5) : ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			string name; 
			cout << "Enter the name of the new location record:";  
			cin >> name;  
			name = convertToLowercase(name);
			if (martyrs_records.addLocationInOrder(name))
			{
				cout << "The new location record is added" << endl;
			}
			else
			{
				cout << "The location record you have entered is already there" << endl;
			}
			break;  
		} 
		case 2:
		{
			string oldName,newName;
			cout << "Enter the old location record name:";
			cin >> oldName;
			oldName = convertToLowercase(oldName);
			if (martyrs_records.locationIsFound(oldName) == false)
			{
				cout << "The name you entered is not there " << endl;
				break;
			}
			cout << "Enter the new location record name:";
			cin >> newName;
			newName = convertToLowercase(newName);
			martyrs_records.updateLocation(oldName, newName);
			break;
		}
		case 3:
		{
			string name; 
			cout << "Enter the name of the location record you want to delete:";
			cin >> name; 
			name = convertToLowercase(name);
			if (martyrs_records.deleteLocation(name) == false)
			{
				cout << "The name you entered is not there " << endl;
				break;
			}
			cout << "The location record is deleted" << endl;
			break;
		}
		case 4:
		{
			char choice2;
			cout << "a.Martyrs’ Menu" << endl;
			cout << "b.Statistics Report" << endl;
			cout << "Enter your choice: ";
			cin >> choice2;
			while (choice2 != 'a' && choice2 != 'b' && choice2 != 'A' && choice2 != 'B')
			{
				cout << "Wrong Input , Enter again ( a or b ) : ";
				cin >> choice2;
			}
			cout << endl; 
			string locationName; 
			cout << "Enter a location record name : "; 
			cin >> locationName; 
			locationName = convertToLowercase(locationName); 
			while (martyrs_records.locationIsFound(locationName) == false)  
			{
				cout << "The name you entered is not there, enter again : " << endl; 
				cin >> locationName;  
				locationName = convertToLowercase(locationName); 

			} 
			if (choice2 == 'a' || choice2 == 'A')
			{
				
				martyrs_records.print_martyrsNames_of_loction(locationName); 
				int choice3;
				cout << endl;
				cout << "--- Operations on the Martyr ---" << endl;
				cout << "1.Insert a new martyr record " << endl;
				cout << "2.Update a martyr record " << endl;
				cout << "3.Delete a martyr record  " << endl;
				cout << "4.Search for a martyr by name and display his/her information. " << endl;
				cout << "Choose the operation you want : ";
				cin >> choice3;

				while (choice3<=0 || choice3>=5)
				{
					cout << "Wrong Input , Enter again the operation number (1 or 2 or 3 or 4) : ";
					cin >> choice3;
				}

				if (choice3 == 1)
				{
					Martyr newMartyr;
					newMartyr.location = locationName;
					cout << "Enter the martyr's name : ";
					cin.ignore();
					getline(cin, newMartyr.name); 
					cout << endl << "Enter the martyr's age : ";
					cin >> newMartyr.age;
					cout << endl << "Enter the martyr's Date of death : ";
					cin >> newMartyr.dateOfDeath;
					cout << endl << "Enter the martyr's gender : ";
					cin >> newMartyr.gender;
					martyrs_records.addInOrder(newMartyr);
					cout << endl << "Martyr is added " << endl;
					break;
				}
				else if (choice3==2)
				{
					string updatedMartyrName;
					cout << "Enter the martyr's name that you want to update : ";
					cin.ignore();
					getline(cin, updatedMartyrName);  
					if (martyrs_records.findMartyrOfLocationByNames(updatedMartyrName, locationName) == false) 
					{
						cout << "The martyr is not there" << endl;
						break;
					}
					string* newParts = new string[3];
					cout << "Enter the new name : ";
					getline(cin, newParts[0]);  
					cout << "Enter the new age : ";
					cin >> newParts[1];
					cout << "Enter the new gender : ";
					cin >> newParts[2];
					martyrs_records.updateMartyr(updatedMartyrName, locationName,newParts[0], newParts[1],newParts[2]);
					cout << endl << "Martyr is updated " << endl;
					break;
				}

				else if (choice3==3)
				{
					string deletingName;
					cout << "Enter the name of the martyr to delete him/her : ";
					cin.ignore();
					getline(cin, deletingName); 
					if (martyrs_records.findMartyrOfLocationByNames(deletingName, locationName) == false) 
					{
						cout << "The martyr is not there" << endl;
						break;
					}
					martyrs_records.deleteMatyr(deletingName, locationName);
					cout << endl << "Martyr is deleted" << endl;
					break;
				}

				else if (choice3 == 4)
				{
					string searchName;
					cout << "Enter the name of the martyr you are searching for : ";
					cin.ignore();
					getline(cin, searchName);
					if (martyrs_records.findMartyrOfLocationByNames(searchName, locationName) == false)
					{
						cout << "The martyr is not there" << endl;
						break;
					}
					Martyr * searchedMartye=martyrs_records.searchMartyr(searchName, locationName); 
					cout << searchedMartye->name << "  " << searchedMartye->age << "  " << searchedMartye->location << "  " << searchedMartye->dateOfDeath << "  " << searchedMartye->gender << endl;
					cout << endl;
					break;
				}
				break;
			}
			else if (choice2 == 'b' || choice2 == 'B')
			{
				cout << endl;
				cout << "a.The numbers of martyrs in the selected location. " << endl;
				cout << "b.Print the Martyrs’ full information in that location. " << endl;
				cout << "c.Traverse the stack and print the Martyrs’ full information " << endl;
				cout << "d.Report the date that had the minimum number of martyrs." << endl;
				char n;
				cout << "Choose an option : ";
				cin >> n;
				switch (n)
				{
					case 'a':
					{
						cout << " Number of martyrs in " << locationName << " is " << martyrs_records.numberOfMartyrsInLocation(locationName) << endl;
						break;
					}
					case 'b':
					{
						cout << "All Martyrs in " << locationName << " : " << endl; 
						martyrs_records.print_martyrsInfo_of_loction(locationName); 
						break;
					}
					case 'c':
					{
						cout << "All Martyrs in reverse in " << locationName << " : " << endl;
						martyrs_records.print_stack_of_location_in_reverse(locationName); 
						break;
					}
					case 'd':
					{
						cout<<" The date with the minimum matryrs is : "<<martyrs_records.date_with_minimum_number_of_martyrs(locationName)<<endl;
						break;
					}

				}
			}
			break;
		}
		case 5:
		{
			char t;
			cout << endl << "Do you want to save the changes to the file ? "<<endl;
			cout << "a. YES" << endl << "b. NO" << endl; 
			cin >> t;
			if (t == 'a')
			{
				ofstream savedFile; 
				string fileName; 
				cout << "Enter the file's name : "; 
				cin >> fileName; 
				savedFile.open(fileName + ".txt"); 
				martyrs_records.saveInfo(savedFile); 
			} 
			return 1;
		}

		break;
		}
		martyrs_records.printLocations();
		}
};