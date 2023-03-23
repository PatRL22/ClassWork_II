#include <iostream>
#include "boost/thread.hpp"

using namespace std;

class CONTROLLER {
    public:
        CONTROLLER(double kp, double ki, double kd, double sample_time, double initial_I, double initial_err);
        
        double loop(double init_ref);                //Main loop function        
        void system_start();       //start the system
      //member to set the desired value
        double get_x_des();
        double get_init_val();

    private:
    double P;
    double I;
    double D;
    double dt;
    double integral_act;
    double init_err;
    double desired_status;
    double init_val;
};
