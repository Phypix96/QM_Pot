#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> dvec;
double const pi=3.14159265358979323846;

/*tan(x)=sqrt(2*V0/x²-1) can be split up into intervalls with length pi.
In each of those, there has to be exactly 1 point, where the equation is true.
By bijection, those are found and then they are put into a vector.
As the root becomes imaginary for all x > sqrt(2*V0)=xmax,
the size of the vector has to be xmax/pi+1.
Same procedure for cot(x)=-sqrt(*V0/x²-1)*/

pair <dvec, dvec> bijection(double k){

	int l = sqrt(2.*k)/pi+1;
	dvec even_modes(l);
	dvec uneven_modes(l);
	double a1, a2, b1, b2, x;
	
	for(int i = 0; i < l; ++i ){
		a1 = pi*i;
		b1 = pi*(i+1);
		a2 = a1;
		b2 = b1;

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
		even_modes[i] = (a1+b1)/2.;
		uneven_modes[i] = (a2+b2)/2.;
	}
	pair <dvec, dvec> modes = make_pair(even_modes, uneven_modes);
	return modes;
}

/*BOOST_PYTHON_MODULE(bijection){
	using namespace boost::python;
	def("bij", bijection);
}*/

int main(){
	cout<<bijection(10).first[0]<<'\n'
	<<bijection(10).second[0];
}