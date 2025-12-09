#include "2.hpp";

using namespace std;

person::person(int b){
    a=b;
}

int person::getA(){
    a++;
    return a;
}