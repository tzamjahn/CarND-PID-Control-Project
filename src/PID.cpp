#include "PID.h"

using namespace std;


PID::PID() {}

PID::~PID() {}

void PID::Init(double param[]) {
    Kp_ = param[0];
    Ki_ = param[1];
    Kd_ = param[2];
    
    i_error = 0;
    d_error =0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

}

double PID::TotalError() {
    double tot_err;
    tot_err = Kp_*p_error+Kd_*d_error+Ki_*i_error;
    return tot_err;
}


