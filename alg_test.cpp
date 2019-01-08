#include "Kalman_Filter.h"
#include<iostream>
#include<time.h>
using namespace std;

int main() {
	double x = 1;
	double z = 1;
	kalman_filter_unidimension kf(1,1);
	double z_ = 1;
	srand(int(time(0)));

	for (size_t i = 0; i <10000; i++)
	{
		//srand(int(time(0)));
		x = (rand() % 100) ;
		z_ = 1 + x/1000;
		double out=kf.update(z_);
		printf("%f", z_);
		printf("%f\n",out);
		//printf("%f\n", x);
	}
	system("pause");
}










