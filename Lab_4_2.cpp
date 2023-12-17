#include <iostream>
#include <locale>
#include <windows.h> 
#include <cmath>
using namespace std;
const double epsilon = 1e-6;
double a, b, c;
double check;
double f(double x){
    return sqrt(1-0.4*pow(x,2))-asin(x);
};
double f1(double x){
    return -((2 * x) / (5 * sqrt(1 - (2 * pow(x, 2)) / 5))) - (1 / sqrt(1 - pow(x, 2)));
};
double f2(double x){
    return -((2 * (sqrt(1 - (2 * pow(x, 2))/5) + (2 * pow(x, 2))/(5 * sqrt(1 - (2 * pow(x, 2))/5))))/ (5 * (1 - (2 * pow(x, 2))/5))) - ((x) / pow(1 - pow(x, 2), 3 / 2));
};

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
    c=(a+b)/2;
    if(f(a)*f2(a)>0){
        a=c;
    }
    else{
        b=c;
    };
    while(abs(f(c))>=epsilon){
        c=c-(f(c)/f1(c));
    };
    cout<<"X равен: "<<c;
    return 0;
}