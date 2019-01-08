#pragma once

#ifndef Kalman_Filter
#define Kalman_Filter


class kalman_filter_base {
protected:
	int measurement_dimension;
	int state_dimension;

public:
	kalman_filter_base()=default;
	virtual ~kalman_filter_base()=default;
};

class kalman_filter_unidimension : kalman_filter_base {
private:
	double x;
	double z;
	double A ;
	double P ;
	double Q ;
	double R ;
	double K;
	double H;
public:
	kalman_filter_unidimension(double x_, double z_, double A_=1, double H_=1, int measurement_dimension_=1, int state_dimension_=1, double P_=1, double Q_=1e2, double R_=1e5);
	//double predict();
	double update(double z_);
	//double estimate();

};
#endif