	#include<iostream>
	#include<string>
	#include"Vector.h"
	#include"Stack.h"
	#include"Martyr.h"
	#include<queue>
	#include <fstream>


	using namespace std;


	class LocationNode
	{
	private:
		string location;
		MyVector<Martyr> vectory;
		MyStack <Martyr> stacky;
		LocationNode* next;
		LocationNode* prev; 
		friend class DoublyCircular;
	};


	class DoublyCircular
	{
	private:
		LocationNode* head;
		int n;
	public:
		DoublyCircular()
		{
			head = NULL;
			n = 0;
		}
		bool empty()
		{
			return head == NULL;
		}
		int size()const
		{
			return n;
		}


		void addInOrder(const Martyr& martyr)
		{
			if (empty())
			{
				LocationNode * newNode = new LocationNode;
				newNode->location = martyr.location;
				newNode->vectory.add(martyr);
				newNode->stacky.push(martyr);
				head = newNode; 
				newNode->next = head;
				newNode->prev=head;
				n++;
				return;
			}
			if (head->location == martyr.location)  
			{
				head->vectory.add(martyr); 
				head->stacky.push(martyr); 
				return; 
			}
			LocationNode* q = head->next; 
			while (q!=head && martyr.location!=q->location)
			{
				q = q->next;
			}
			if (martyr.location == q->location) 
			{
				q->vectory.add(martyr);
				q->stacky.push(martyr);  
				return;
			}
			else if (q == head)
			{
				LocationNode* newNode = new LocationNode;
				n++;
				LocationNode* p = head;
				LocationNode* current = head->next;
				newNode->location = martyr.location;
				if (head->location > newNode->location)
				{
					newNode->next = head;
					newNode->prev = head->prev;
					head->prev->next = newNode;
					head->prev = newNode;
					head = newNode;
					newNode->vectory.add(martyr);
					newNode->stacky.push(martyr);
					return;
				}
				while (current != head && current->location < newNode->location)
				{
					p = current;
					current = current->next;
				}
				p->next = newNode;
				current->prev = newNode;
				newNode->next = current;
				newNode->prev = p;
				newNode->vectory.add(martyr);
				newNode->stacky.push(martyr);
				return;
			}

		}

		bool addLocationInOrder(const string& name)
		{
			if (head->location == name)
			{
				return false ;
			}
			LocationNode* q = head->next;
			while (q != head && name != q->location)
			{
				q = q->next;
			}
			if (name == q->location)
			{
				return false;
			}
			else if (q == head)
			{
				LocationNode* newNode = new LocationNode;
				n++;
				LocationNode* p = head;
				LocationNode* current = head->next;
				newNode->location = name;
				if (head->location > newNode->location)
				{
					newNode->next = head;
					newNode->prev = head->prev;
					head->prev->next = newNode;
					head->prev = newNode;
					head = newNode;
					return true;
				}
				while (current != head && current->location < newNode->location)
				{
					p = current;
					current = current->next;
				}
				p->next = newNode;
				current->prev = newNode;
				newNode->next = current;
				newNode->prev = p;
				return true;
			}
		}

		void printLocations()
		{
			LocationNode* p = head;
			do
			{
				cout << p->location << endl;
				p = p->next;
			} while (p != head);
		}
		void swapNodes(LocationNode* d1, LocationNode* p1) // Using pointers
		{
			if (empty()) return;
			if (n == 1) return; 
			LocationNode* d2 = d1->prev;     
			LocationNode* p2 = p1->next;     
			p1->prev = d2;
			p1->next = d1;
			d2->next = p1;
			d1->next = p2;
			d1->prev = p1;
			p2->prev = d1;
		}
		string getNN()
		{
			return head->location;
		}
		void Sort(bool ascending)
		{
			if (empty())
			{
				return;
			}
			else if (ascending)
			{
				bool None_Swapped;
				bool swapped;
				for (int i = 0; i < n - 1; i++)
				{
					None_Swapped = false;
					LocationNode* p = head;
					for (int j = 0; j < n - i -1 ; j++)
					{
						swapped = false;
						if ((p->location) > (p->next->location))
						{
							swapNodes(p, p->next);
							swapped = true;
							None_Swapped = true;
						}
						if (swapped == false)
							p = p->next;
					}

					if (None_Swapped == false)
						break;
				}
			
			}

			else
			{
				bool None_Swapped;
				bool swapped;
				for (int i = 0; i < n - 1; i++)
				{
					None_Swapped = false;
					LocationNode* p = head;
					for (int j = 0; j < n - i - 1; j++)
					{
						swapped = false;
						if ((p->location) < (p->next->location))
						{
							swapNodes(p, p->next);
							swapped = true;
							None_Swapped = true;
						}
						if (swapped == false)
							p = p->next;
					}

					if (None_Swapped == false)
						break;
				}
			}
		}// sort function end 

		bool updateLocation(const string &oldN, const string &newN)
		{
			LocationNode* p = find(oldN);
			if (!p)
			{
				return false;
			}
			if (oldN==head->location)
			{
				if (newN <= oldN)
				{
					head = p;
				}
				else
				{
					head = head->next; 
				}
			}
			p->location = newN; 
			Sort(1);
			p->vectory.updateMartyrLocationVec(newN); 
			p->stacky.updateMartyrLocationStack(newN); 
			return true;
		}

		LocationNode* find(const string &s)
		{
			if (empty()) return NULL; 
			LocationNode* p = head; 
			do 
			{
				if (p->location == s)
				{
					return p;
				}
				p = p->next;
			} while (p != head);

			return NULL; 
		}

		bool locationIsFound(const string& s)
		{
			if (empty()) return false;
			LocationNode* p = head;
			do
			{
				if (p->location == s)
				{
					return true;
				}
				p = p->next;
			} while (p != head);

			return false;
		}
		bool deleteLocation(const string& name)
		{
			LocationNode* p = find(name);
			if (!p) return false;
			if (p == head)
			{
				head = p->next; 
			}
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->next = p->prev = NULL;
			delete p;
			n--;
			return true;
		}

		void updateMartyr(const string& martyr, const string& location, const string& newName , const string& newAge, const string& newGender)
		{
			LocationNode* p = find(location);
			Martyr * foundMartyr = p->vectory.findName(martyr);

			foundMartyr->name = newName;
			foundMartyr->age = newAge;
			foundMartyr->gender = newGender;
			p->vectory.sortVec();

			p->stacky.updateNameStack(martyr, location, newName, newAge,newGender); 
		}
		void saveInfo(ofstream & newFile)
		{
			LocationNode* p = head;
			newFile << "Name" << " , " << "Age" << " , " << "Event location - District" << " , " << "Date of death" << " , " << "Gender" << endl;
			do
			{
				p->vectory.saveInfoVec(newFile);
				p = p->next;
			} while (p!=head);
		}


		bool findMartyrOfLocationByNames(const string& martyr, const string& location)
		{
			LocationNode* p = find(location); 
			Martyr* foundMartyr = p->vectory.findName(martyr); 
			if (foundMartyr == NULL) return false;

			return true;
		}

		Martyr* searchMartyr(const string& martyr, const string& location)
		{
			LocationNode* p = find(location);
			Martyr* foundMartyr = p->vectory.findName(martyr);
			if (foundMartyr == NULL) exit(1);
			return foundMartyr;
		}	

		void print_martyrsNames_of_loction(const string& location)
		{
			LocationNode* p = find(location); 
			p->vectory.print_all_names();
		}

		void print_martyrsInfo_of_loction(const string& location)
		{
			LocationNode* p = find(location);
			p->vectory.print_all_info();
		} 

		bool deleteMatyr(const string& name, const string& location)
		{
			LocationNode* p = find(location); 
		
			return (p->vectory.deleteMartyrVec(name) && p->stacky.deleteMartyrSt(name)); 
		}

		void print_stack_of_location_in_reverse(const string& location)
		{
			LocationNode* p = find(location); 
			MyStack<Martyr> newStack = p->stacky; 
			MyStack<Martyr> newStack2; 

			while (!newStack.empty())
			{
				newStack2.push(newStack.top());
				newStack.pop();
			}
			p->stacky = newStack2; 

			while (!newStack2.empty()) 
			{
				cout << newStack2.top().name << "  " << newStack2.top().age << "  " << newStack2.top().location << "  " << newStack2.top().dateOfDeath << "  " << newStack2.top().gender << endl;
				newStack2.pop();
			}
		}

		string date_with_minimum_number_of_martyrs(const string& location) 
		{
			LocationNode* p = find(location);
			return p->vectory.date_with_minimum_number_of_martyrs2();	
		}

		int numberOfMartyrsInLocation(const string& location)
		{
			LocationNode* p = find(location); 
			return p->vectory.size();
		}
	};
