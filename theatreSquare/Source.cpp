#include<fstream>
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

struct street
{
	int inter1;
	int inter2;
	std::string name;
	int timeOfCompletion;
};

struct inter
{
	int id;
	std::vector<inter*> next;
};

struct car
{
	int timeOfCompletion;
	std::vector<street*> path;
};


void main()
{
	std::fstream fin;
	fin.open("input.txt");
	int time;
	int numberOfIntersections;
	int numberOfStreets;
	int numberOfCars;
	int Score;

	std::vector<street*> streets;
	std::vector<car*> cars;
	std::vector<inter*> intersections;
	inter *temp;
	street *tempStreet;
	car* tempCar;



	std::cin >> time >> numberOfIntersections >> numberOfStreets >> numberOfCars >> Score;

	int id = 0;
	for (int i = 0; i < numberOfIntersections; i++)
	{
		temp = new inter;
		temp->id = id;
		intersections.push_back(temp);
		id++;
	}
	for (int i = 0; i < numberOfStreets; i++)
	{
		tempStreet = new street;
		std::cin >> tempStreet->inter1;
		std::cin >> tempStreet->inter2;
		std::cin >> tempStreet->name;
		std::cin >> tempStreet->timeOfCompletion;

		streets.push_back(tempStreet);
	}

	for (int i = 0; i < numberOfCars; i++)
	{
		
	}


	

}