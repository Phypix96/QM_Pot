#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

typedef vector<double> dvec;
double const pi=3.14159265358979323846;

/*tan(x)=sqrt(2*V0/x²-1) can be split up into intervalls with length pi.
In each of those, there has to be exactly 1 point, where the equation is true,
and a second point for cot(x)=-sqrt(*V0/x²-1).
By bijection, those are found and then they are put into a vector.
As the root becomes imaginary for all x > sqrt(2*V0)=xmax,
the size of the vector has to be (xmax/pi+1)*2
The Amplitudes are also evaluated and returnd in seperate Vectors*/

tuple <dvec, dvec, dvec> finite_well(double a=2., double V0=1., double m=1.){

	double k = a*a*m*V0
	int l = sqrt(2.*k)/pi+1;
	dvec modes(2*l);
	dvec amp_inside(2*l);
	dvec amp_outside(2*l);
	double a1, a2, b1, b2, x;
	
	for(int i = 0; i < l; ++i ){
		a1 = a2 = pi*i;
		b1 = b2 = pi*(i+1);

		for(int j=0; j<40; j++){
			x = (a1+b1)/2.;
			if(tan(x)-sqrt(2.*k/(x*x)-1.) < 0) a1=x;
			else b1=x;
		}
		for(int j=0; j<40; j++){
			x = (a2+b2)/2.;
			if(-1./tan(x)-sqrt(2.*k/(x*x)-1.) < 0) a2=x;
			else b2=x;
		}
		modes[2*i] = (a1+b1)/2.;
		modes[2*i+1] = (a2+b2)/2.;

		amp_inside[2*i] = 
		amp_inside[2*i+1] = 
		amp_outside[2*i] = 
		amp_outside[2*i+1] = 
	}
	
	tuple <dvec, dvec, dvec> finite_solution = tie(modes, amp_inside, amp_outside);
	return finite_solution;
}