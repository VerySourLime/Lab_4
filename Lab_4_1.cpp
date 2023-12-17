#include <iostream>
#include <locale>
#include <windows.h> 
#include <cmath>
using namespace std;
const double epsilon = 1e-6;
double a, b, x;
double fb;
double fx;
double check;

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
    while(abs(b-a)>=epsilon){
        x = (a+b)/2;
        fb=sqrt(1-0.4*pow(b,2))-asin(b);
        fx=sqrt(1-0.4*pow(x,2))-asin(x);
        if(fb*fx<0){
            a=x;
        }
        else{
            b=x;
        };
    };
    cout<<"X равен: "<<b;
    return 0;
}