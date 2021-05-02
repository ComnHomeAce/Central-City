// Central City.cpp : Given a set of cities, this program calculates the central
//city as the one that has the shortest total distance to all other cities.

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	//Declare arrays
	double coordinates[20][2];
	double distances[20]{ 0 }; //Initialize to zero

	int cities; //Number of cities to evaluate

	//Index for determining smallest distance
	int index = 0; //Zero by default

	//Program definition
	cout << "Given a set of cities, this program calculates the central city as\n";
	cout << "the one that has the shortest total distance to all other cities.\n\n";

	//Get number of cities
	cout << "Enter total number of cities: ";
	cin >> cities;

	//Get city coordinates
	cout << "\nEnter the coordinate pairs for all cities:";
	for (int i = 0; i < cities; i++) //Loop through rows
	{
		for (int j = 0; j < 2; j++) //Loop through columns
		{
			cin >> coordinates[i][j];
		}
	}

	cout << "\n";

	//Calculate distances
	for (int i = 0; i < cities; i++) //Loop through x(1) and y(1)
	{
		for (int j = 0; j < cities; j++) //Loop through x(2) and y(2)
		{
			distances[i] += sqrt(pow(coordinates[i][0] - coordinates[j][0], 2) + pow(coordinates[i][1] - coordinates[j][1], 2));
		}
	}

	//Find smallest distance
	for (int i = 1; i < cities; i++)
	{
		if (distances[i] < distances[index])
			index = i;
	}

	//Print coordinates of central city
	cout << fixed << setprecision(1);
	cout << "The central city is located at (" << coordinates[index][0] << ", " << coordinates[index][1] << ")\n\n";

	//Print distance of central city
	cout << fixed << setprecision(2);
	cout << "The total distance to all other cities is " << distances[index] << "\n";
}