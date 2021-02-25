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
	int redLightTime;
	int frequency;
};

struct inter
{
	int id;
	std::vector<street*> next;
	std::vector<street*> prev;
};

struct car
{
	int numberOfStreets;
	int timeOfCompletion;
	std::vector<street*> path;
};

bool compare(const street& a, const street& b)
{
	return a.frequency < b.frequency;
}


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
		tempStreet->frequency = 0;
		fin >> tempStreet->inter2;
		fin >> tempStreet->name;
		fin >> tempStreet->timeOfCompletion;

		intersections[tempStreet->inter1]->next.push_back(tempStreet);
		intersections[tempStreet->inter2]->prev.push_back(tempStreet);

		streets.push_back(tempStreet);
	}

	for (int i = 0; i < numberOfCars; i++)
	{
		tempCar = new car;
		fin >> tempCar->numberOfStreets;
		tempCar->timeOfCompletion = 0;
		for (int k = 0; k < tempCar->numberOfStreets; k++)
		{
			std::string t;
			fin >> t;
			for (auto& j : streets)
			{
				if (t == j->name)
				{
					j->frequency++;
					tempCar->path.push_back(j);
					break;
				}
			}
		}

		for (auto& j : tempCar->path)
		{
			tempCar->timeOfCompletion += j->timeOfCompletion;
		}

		cars.push_back(tempCar);
	}


	for (auto i : intersections)
	{
		std::sort(i->prev.begin(), i->prev.end(), compare);
		int set = 1;
		for (auto j:i->prev)
		{
			if (j->frequency == 0)
				j->redLightTime = 0;
			else
				j->redLightTime = set++;

		}
	}



	

	

}