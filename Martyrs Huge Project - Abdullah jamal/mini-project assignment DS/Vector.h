#pragma once


#include<iostream>
#include<string>
#include"Stack.h"
#include"Vector.h"
#include <fstream>
using namespace std;

template<typename M>
class MyVector
{
private:
	int n;
	int capacity;
	M* Arr;
	void resize()
	{
		capacity *= 2;
		M* k = new M[capacity];
		for (int i = 0; i < n; i++)
			k[i] = Arr[i];
		delete[]Arr;
		Arr = k;
	}
public:
	MyVector(int size = 4) // constructor 
	{
		capacity = size;
		n = 0;
		Arr = new M[capacity];
	}
	MyVector(const MyVector<M>& T) // copy constructor  
	{
		n = T.n;
		capacity = T.capacity;
		Arr = new M[capacity];
		for (int i = 0; i < n; i++)
			this->Arr[i] = T.Arr[i];
	}

	void saveInfoVec(ofstream& newFile)
	{
		for (int i = 0; i < n; i++)
		{
			newFile << Arr[i].name << " , " << Arr[i].age << " , " << Arr[i].location << " , " << Arr[i].dateOfDeath << " , " << Arr[i].gender << endl;
		}
	}
	void add(const M &mt) // adding a number to the end of the array
	{
		if (n + 1 > capacity) // ( n >= capacity )
		{
			resize();
		}
		int i = 0;
		while (i < n && Arr[i].name < mt.name) {
			i++;
		}
		insert(i, mt);
	}

	void pop_back()
	{
		if (Empty())
			return;
		else
			n--;
	}

	void sortVec()
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = i + 1; j < n; j++) { 
				if (Arr[i].name > Arr[j].name)
				{
					string temp = Arr[i].name;
					Arr[i].name = Arr[j].name;
					Arr[j].name = temp;
				}
			}
		}
	}

	bool insert(int index, M mt)
	{
		if (index >= 0 && index <= n)
		{
			if (n == capacity)
				resize();
			for (int i = n - 1; i > index - 1; i--)
			{
				Arr[i + 1] = Arr[i];
			}
			Arr[index] = mt;
			n++;
			return true;
		}
		return false;
	}

	M* findName(const string &martyrName)  
	{
		for (int i = 0; i < n; i++)
		{
			if (Arr[i].name == martyrName)
			{
				return &Arr[i]; 
			}
		}

		return NULL;
	}

	int findName_returnIndex(const string& martyrName)
	{
		for (int i = 0; i < n; i++)
		{
			if (Arr[i].name == martyrName)
			{
				return i; 
			}
		}
		return NULL;
	}

	bool deleteMartyrVec(const string& martyrName) 
	{
		int index = findName_returnIndex(martyrName);
		return erase(index);  
	}

	void print_all_names() 
	{
		for (int i = 0; i < n; i++)
		{
			cout << i +1 <<" . "<< Arr[i].name<<endl;
		}
		cout << endl;
	}
	void print_all_info()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " . " << Arr[i].name << "  "<<Arr[i].age<<"  "<< Arr[i].location << "  " << Arr[i].dateOfDeath << "  " << Arr[i].gender << endl;
		}
		cout << endl;
	}
	M operator [] (int index) const
	{
		if (index >= 0 && index < n)
			return this->Arr[index]; // Arr[index];
		exit(1);
	}
	MyVector<M>& operator = (const MyVector<M>& v)
	{
		if (this != &v)
		{
			if (this != NULL)
				delete[]Arr;
			n = v.n;
			capacity = v.capacity;
			Arr = new M[capacity];
			for (int i = 0; i < n; i++)
				this->Arr[i] = v.Arr[i];
		}
		return *this;
	}
	
	MyVector<M> operator + (const MyVector<M>& v) // adding the numbers in the cells of two arrays              
	{
		if (n >= v.n)
		{
			MyVector<M> k(n);
			for (int i = 0; i < v.n; i++)
				k.add(v.Arr[i] + Arr[i]);
			for (int i = v.n; i < n; i++)
				k.add(Arr[i]);

			return k;
		}
		else
		{
			MyVector<M> k(v.n);
			for (int i = 0; i < n; i++)
				k.add(Arr[i] + v.Arr[i]);
			for (int i = n; i < v.n; i++)
				k.add(v.Arr[i]);

			return k;
		}

	}
	MyVector<M> operator += (const MyVector<M>& v)
	{
		if (n >= v.n)
		{
			MyVector<M> k(n);
			for (int i = 0; i < v.n; i++)
				k.add(v.Arr[i] + Arr[i]);
			for (int i = v.n; i < n; i++)
				k.add(Arr[i]);

			*this = k;

		}
		else
		{
			MyVector<M> k(v.n);
			for (int i = 0; i < n; i++)
				k.add(Arr[i] + v.Arr[i]);
			for (int i = n; i < v.n; i++)
				k.add(v.Arr[i]);

			*this = k;
		}

		return *this;
	}
	bool operator==(const MyVector<M>& v1)
	{
		if (this == &v1)
			return true;
		if (v1.n != this->n)
			return false;
		for (int i = 0; i < v1.size(); i++)
			if (Arr[i] != v1[i])
				return false;
		return true;

	}
	bool operator!=(const MyVector<M>& v1)
	{
		if (this == &v1)
			return false;
		if (v1.n != this->n)
			return true;
		for (int i = 0; i < v1.size(); i++)
			if (Arr[i] != v1[i])
				return true;
		return false;

	}
	friend istream& operator>> (istream& in, MyVector<M>& obj)
	{
		obj.n = 0;
		//obj.n = obj.capacity;
		for (int i = 0; i < obj.capacity; i++)
		{
			in >> obj.Arr[i];
			obj.n++;
		}
		return in;
	}
	friend ostream& operator<< (ostream& out, const MyVector<M>& obj)
	{
		cout << "[ ";
		for (int i = 0; i < obj.n; i++)
		{
			out << obj.Arr[i];
			if (i + 1 != obj.n)
				cout << " ,";
		}
		cout << " ]";
		return out;
	}
	~MyVector()
	{
		if (this->Arr != NULL)
			delete[]Arr;
		this->Arr = NULL;
	}
	
	bool erase(int index)
	{
		if (index < 0 || index >= n)
		{
			return false;
		}
		for (int i = index; i < n - 1; i++)
		{
			Arr[i] = Arr[i + 1];
		}
		n--;
		return true;
	}
	
	
	bool Empty() const
	{
		return n <= 0;
	}
	int size() const
	{
		return n;
	}

	M get(int index) const
	{
		if (index >= 0 && index < n)
			return Arr[index];
		exit(1);
	}
	M at(int index) const
	{
		if (index >= 0 && index < n)
			return Arr[index];
		exit(1);
	}
	
	void RemoveAll()
	{
		n = 0;
	}
	void updateMartyrLocationVec( const string& newLocation)
	{
		for (int i = 0; i < n; i++)
		{
			Arr[i].location = newLocation; 
		}
	}
	string date_with_minimum_number_of_martyrs2() 
	{
		int number = 0; 
		int min = 999999; 
		string minDaty; 
		for (int i = 0; i < n; i++)
		{
			string date = Arr[i].dateOfDeath;   
			number = 0; 
			for (int j = 0; j < n; j++)  
			{ 
				if (Arr[j].dateOfDeath == date) 
				{
					number++;
				}
			}
			if (number<min)
			{
				min = number;
				minDaty = date; 
			}
			
		}
		return minDaty;  
	}
};
