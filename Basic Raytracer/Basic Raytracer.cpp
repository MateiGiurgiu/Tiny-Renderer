// Basic Raytracer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3.h"
#include<iostream>
using namespace std;

int main()
{
	Vector3 a(2, 5, 8);
	Vector3 b(3, -4, 9);

	a += b;
	cout<<a;
	cin.get();
    return 0;
}

