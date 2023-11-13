//
//  complexNumber.h
//  classConcept3
//
//  Created by Kaan Şengün on 13.11.2023.
//
#include <iostream>
using namespace std;

class complexNumber{
private:
    int real,imag;
public:
    complexNumber(int r=0, int i=0);
    ~complexNumber();
    complexNumber(const complexNumber &oth);
    int getReal() const{
        return real;
    }
    int getImag() const{
        return imag;
    }
    void setValue(int r=0,int i=0);
    complexNumber addComplex(const complexNumber &oth);
    complexNumber multiplyComplex(const complexNumber &oth);
    complexNumber substractComplex(complexNumber &oth);
    complexNumber multiplyConstant(int constant);
    void multiplyMinus();
    void displayComplex();
    
};
complexNumber::complexNumber(int r,int i){
    real=r;
    imag=i;
    cout<<"Complex Number created."<<endl;
}
complexNumber::~complexNumber(){
    cout<<"Complex Number destroyed."<<endl;
}
complexNumber::complexNumber(const complexNumber &oth){
    real=oth.real;
    imag=oth.imag;
    cout<<"Complex Number copied to target."<<endl;
}
void complexNumber::setValue(int r,int i){
    real=r;
    imag=i;
}
void complexNumber::displayComplex(){
    imag>=0? cout<<real<<"+"<<imag<<"i"<<endl: cout<<real<<imag<<"i"<<endl;
}
complexNumber complexNumber::addComplex(const complexNumber &oth){
    complexNumber result;
    result.real=real+oth.real;
    result.imag=imag+oth.imag;
    return result;
}
complexNumber complexNumber::substractComplex(complexNumber &oth){
    complexNumber result;
    oth.multiplyMinus();
    result=addComplex(oth);
    return result;
}
void complexNumber::multiplyMinus(){
    real *=-1;
    imag *=-1;
}
complexNumber complexNumber::multiplyConstant(int constant){
    complexNumber result;
    result.real=real*constant;
    result.imag=imag*constant;
    return result;
}
complexNumber complexNumber::multiplyComplex(const complexNumber &oth){
    complexNumber result;
    result.real=real*oth.real-imag*oth.imag;
    result.imag=real*oth.imag+imag*oth.real;
    return result;
}
