#include <iostream>
#include <cstdio>

using namespace std;

double nCow;
double nCar;
double nShow;
double nDoor;
double Solution;

int main()
{
	while(scanf("%lf %lf %lf", &nCow, &nCar, &nShow) != EOF)
	{
		
		nDoor= nCar+nCow;
		Solution = nCar * (nDoor - 1) / (nDoor * (nDoor - nShow - 1));
		printf("%.5lf\n",Solution);
	}
	return 0;
}
