// Vector3.cpp

#include "StdAfx.h"
#include "Vector3.h"

Vector3::Vector3(void)
{
}

Vector3::Vector3(float X, float Y, float Z){
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

// Returns the length of the vector
float Vector3::Length(){
	return sqrt(X * X + Y * Y + Z * Z);
}

// Normalizes the vector
Vector3 Vector3::Normalize(){
	Vector3 vector;
	float length = this->Length();

	if(length != 0){
		vector.X = X/length;
		vector.Y = Y/length;
		vector.Z = Z/length;
	}

	return vector;
}

float Vector3::DistanceTo(Vector3* v){
	float distance = sqrt(pow(v->X-X,2)+pow(v->Y-Y,2)+pow(v->Z-Z,2));
	return distance;
}

Vector3::~Vector3(void)
{
}
