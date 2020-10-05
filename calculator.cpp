#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

double calculator(string equation){
    int operationIndexFirst = -1;
    int operationIndexSecond = -1;

    
    operationIndexFirst = equation.find_last_of("+");
    operationIndexSecond = equation.find_last_of("-");

    if((operationIndexFirst != operationIndexSecond) && (operationIndexFirst > operationIndexSecond)){
        //cout << equation.substr(0,operationIndexFirst) << "  +  " << equation.substr(operationIndexFirst+1) << "\n";
        return calculator(equation.substr(0,operationIndexFirst)) + calculator(equation.substr(operationIndexFirst+1));
    }

    if((operationIndexFirst != operationIndexSecond) && (operationIndexFirst < operationIndexSecond)){
       // cout << equation.substr(0,operationIndexSecond) << "  -  " << equation.substr(operationIndexSecond+1) << "\n";
        return calculator(equation.substr(0,operationIndexSecond)) - calculator(equation.substr(operationIndexSecond+1));
    }

    operationIndexFirst = equation.find_last_of("*");
    operationIndexSecond = equation.find_last_of("/");

    if((operationIndexFirst != operationIndexSecond) && (operationIndexFirst > operationIndexSecond)){
        //cout << equation.substr(0,operationIndexFirst) << "  *  " << equation.substr(operationIndexFirst+1) << "\n";
        return calculator(equation.substr(0,operationIndexFirst)) * calculator(equation.substr(operationIndexFirst+1));
    }

    if((operationIndexFirst != operationIndexSecond) && (operationIndexFirst < operationIndexSecond)){
        //cout << equation.substr(0,operationIndexSecond) << "  /  " << equation.substr(operationIndexSecond+1) << "\n";
        return calculator(equation.substr(0,operationIndexSecond)) / calculator(equation.substr(operationIndexSecond+1));
    }

    return stod(equation);
}


int main(){
string input;
cout << "Enter Equation: ";
cin >> input;
cout << calculator(input);
}