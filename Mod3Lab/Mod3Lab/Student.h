#pragma once

#include "Person.h"
#include <iostream>

class Student :
	public Person
{
public:
	Student();
	Student(std::string firstName, std::string lastName, int age, std::string phone);
	virtual ~Student();

	virtual void OutputIdentity();
	virtual void OutputAge();
};

