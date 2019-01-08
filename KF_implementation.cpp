#include "Kalman_Filter.h"

 kalman_filter_unidimension::kalman_filter_unidimension(double x_, double z_, double A_, double H_, int measurement_dimension_, int state_dimension_, double P_, double Q_, double R_) {
	x = x_;
	z = z_;
	A = A_;
	measurement_dimension = measurement_dimension_;
	state_dimension = state_dimension_;
	P = P_;
	Q = Q_;
	R = R_;
	H = H_;
};


/*double kalman_filter_unidimension::predict() {
	x = A * x;
	P = A * P*A + Q;
	return x;
}*/
double kalman_filter_unidimension::update(double z_) {
	z = z_;
	double H_t=H,A_t=A,x_temp;
	x_temp = A * x;
	P = A * P*A_t + Q;
	K = P * H_t/(H*P*H_t + R);
	x = x_temp + K * (z_ - H * x);
	P = (1 - K * H)*P;
	return x;
}
/*double kalman_filter_unidimension::estimate() {

}*/

