#pragma once


#include<iostream>
#include<string>
#include"Stack.h"
#include"Vector.h"
#include"SL.h"
#include"Martyr.h"
using namespace std;

template<typename T>
class MyStack
{
private:
	SinglyList <Martyr> Listy;
public:
	MyStack(){}
	~MyStack(){}
	bool empty() const
	{
		return Listy.empty();
	}

	void push(const T& item)
	{
		Listy.addLast(item);
	}
	T top() const
	{
		return Listy.getback();  
	}
	void pop()
	{
		Listy.removeLast(); 

	}

	void updateNameStack(const string& martyr, const string& location, 
		const string& newName, const string& newAge, const string& newGender)
	{
		Listy.updateNameSingly(martyr, location, newName, newAge, newGender); 
	}

	bool deleteMartyrSt(const string& name) 
	{
		return Listy.deleteMartyrSingly(name); 
	}

	void updateMartyrLocationStack(const string& newLocation)
	{
		Listy.updateMartyrLocationSingly(newLocation); 
	}

};
