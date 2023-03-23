#include "control_loop.h"
#include "boost/thread.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;


double first_order_lti(double t, double K, double tau, double u) {
    double y = K * (1 - exp(-t/tau)) * u;
    return y;
}

int main(int argc, char** argv) {


CONTROLLER control(0.1, 1.2, 0.001, 0.1, 0, 0);

double u=0;
double output=0;
double reference=0;
double temp=0;
double t=0;
int K=1;
double tau=0.5;
double init_value=0;
srand(time(0));


int n=0;

boost::thread Thread2(&CONTROLLER::system_start, &control);
Thread2.join();

init_value = control.get_init_val();
cout<<"INIT VALUE: "<<init_value<<endl;
reference = control.get_x_des();
cout<<"REFERENCE: "<<reference<<endl;


 while(temp<200){
    
    if(n==0){
        u=control.loop(init_value);
        output= first_order_lti(t, K, tau, u);
        cout<<"OUTPUT: "<<output<<endl;
        cout<<"ERROR: "<<reference-init_value<<endl;
    }else{
       
        u=control.loop(output);
        output= first_order_lti(t, K, tau, u);
        cout<<"OUTPUT: "<<output<<endl;
        cout<<"ERROR: "<<reference-output<<endl;
    }

    n += 1;
    t=t+0.1;
    temp= temp+1;

}


}

