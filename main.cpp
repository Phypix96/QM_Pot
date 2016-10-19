#include <iostream>
#include <string>
#include <cmath>


using namespace std;

double factorial(int n){
    double fac = 1.;
    for(int i = 1; i <= n; ++i){
        fac *= i;
    }
    return fac;
}

void Legendre(int l, int m){
    double c [l+m+1][l+1] = {};
    c[0][0]=1.;
    for(int n = 1; n <= l+m; ++n){
        for(int k = 0; k <= min(n,l); ++k){ //es reicht vermutlich bis l zu gehen, da dann die Einträge außen 0 werden
            if(k <= n && n%2 == k%2){
                if(k == 0){
                   c[n][k] = c[n-1][k+1]; //*(0+1)
                }
                if(k == n){
                    c[n][k] = pow(2.,n)*factorial(l)/factorial(l-n);
                }
                if(k != 0 && k!= n){
                    c[n][k] = 2.*(l-(k+n)/2.+1)*c[n-1][k-1] + (k+1)*c[n-1][k+1];
                }
            }
        }
    }

    for(int i = 0; i <= l+m; ++i){
        for(int j = 0; j <= min(i, l); ++j ){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    //c[l+m+1] = *koef;
}

int main(){
    int l = 11, m = 0;
    Legendre(l,m);
    cout<<factorial(12)*13;
}
