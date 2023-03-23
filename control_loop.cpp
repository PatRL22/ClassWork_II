#include "control_loop.h"
#include "boost/thread.hpp"
#include <cmath>

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(double kp, double ki, double kd, double sample_time, double initial_I, double initial_err) {

P=kp;
I=ki;
D=kd;
dt=sample_time;
integral_act=initial_I;
init_err=initial_err;

}


double CONTROLLER::get_x_des(){
  return desired_status;
}

double CONTROLLER::get_init_val(){
  return init_val;
}

//Random initial value
void CONTROLLER::system_start() {
    
    cout<<"Control system start!!!"<<endl;
    init_val=rand()%91;
    cout<<"Set the desired reference: "<<endl;
    cin>>desired_status;
    cout<<"----------------------"<<endl;

}

double CONTROLLER::loop(double init_ref){


        double e=desired_status-init_ref;
        integral_act += e*dt;
        double derivative_act =(e-init_err)/dt;
        double u = P*e + I*integral_act + D*derivative_act;
        init_err=e;
        return u;

}






