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
	int numberOfStreets;
	int timeOfCompletion;
	std::vector<street*> path;
};


void main()
{
	std::fstream fin;
	fin.open("input.txt");
	std::fstream fout;
	fout.open("output.txt");
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



	fin >> time >> numberOfIntersections >> numberOfStreets >> numberOfCars >> Score;

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
		fin >> tempStreet->inter1;
		fin >> tempStreet->inter2;
		fin >> tempStreet->name;
		fin >> tempStreet->timeOfCompletion;

		streets.push_back(tempStreet);
	}

	for (int i = 0; i < numberOfCars; i++)
	{
		tempCar = new car;
		fin >> tempCar->numberOfStreets;

		for (int i = 0; i < numberOfStreets; i++)
		{
			std::string t;
			fin >> t;
			for (auto& j : streets)
			{
				if (t == j->name)
				{
					tempCar->path.push_back(j);
					break;
				}
			}
		}
	}


	

}