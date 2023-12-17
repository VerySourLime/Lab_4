#include <iostream>
#include <locale>
#include <windows.h> 
#include <cmath>
using namespace std;
const double epsilon = 1e-6;
double a, b;
int maxit=1000;
double check;
double g(double x){
    return x+(sqrt(1-0.4*pow(x,2))-asin(x));
};
double iter(double x0,int maxit, double epsilon){
    double cx=x0;
    for(int i=0;i<maxit;i++){
        double nx=g(cx);
        if(abs(nx-cx)<epsilon){
            i=maxit;
            return nx;
        };
        cx=nx;
    };
    return cx;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);  
    SetConsoleOutputCP(1251);
    cout<<"Введите a = ";
    cin>>a;
    cout<<"Введите b = ";
    cin>>b;
    check = (sqrt(1-0.4*pow(a,2))-asin(a))*(sqrt(1-0.4*pow(b,2))-asin(b));
    while(check>=0){
        cout<<"На введённом отрезке нет корней, введите другой отрезок"<<endl;
        cout << "Введите a = ";
        cin>>a;
        cout << "Введите b = ";
        cin>>b;
        check = (sqrt(1-0.4*pow(a,2))-asin(a))*(sqrt(1-0.4*pow(b,2))-asin(b));
    };
    double x0=(a+b)/2;
    double x=iter(x0,maxit,epsilon);
    cout<<"X равен: "<<x;
}