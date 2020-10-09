#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

double factorial(string equation, string* error){
    double ans;

    //trys to convert string to number, makes error if it cant
    try{
        ans = stod(equation);
    }
    catch(exception e){
         *error = "factorial invalid";
         return 0;
    }

    //factorialises the number
    double loops = ans;
    for(double i = 1; (loops-i) > 1; i++){
        ans = ans * (loops-i);
    }

    return ans;
}

double calculator(string equation, string* error){

    //eric you comment how this works, i dont know how it works
    int operationIndexFirst = -1;
    int operationIndexSecond = -1;
   
    operationIndexFirst = equation.find_last_of("+");
    operationIndexSecond = equation.find_last_of("-");

    if((operationIndexFirst != operationIndexSecond) && (operationIndexFirst > operationIndexSecond)){
        return calculator(equation.substr(0,operationIndexFirst), error) + calculator(equation.substr(operationIndexFirst+1), error);
    }

    else if((operationIndexFirst != operationIndexSecond) && (operationIndexFirst < operationIndexSecond)){
        return calculator(equation.substr(0,operationIndexSecond), error) - calculator(equation.substr(operationIndexSecond+1), error);
    }
    
    operationIndexFirst = equation.find_last_of("*");
    operationIndexSecond = equation.find_last_of("/");

    if((operationIndexFirst != operationIndexSecond) && (operationIndexFirst > operationIndexSecond)){
        return calculator(equation.substr(0,operationIndexFirst), error) * calculator(equation.substr(operationIndexFirst+1), error);
    }

    else if((operationIndexFirst != operationIndexSecond) && (operationIndexFirst < operationIndexSecond)){
        return calculator(equation.substr(0,operationIndexSecond), error) / calculator(equation.substr(operationIndexSecond+1), error);
    }

    //if there is a exclmation point, pass the number before it into factorial
    int factorialindex  = equation.find_last_of("!");
    if(factorialindex > -1){
        return(factorial(equation.substr(0, factorialindex), error));
    }

    else
    {
        //adds fault tolrance for 5+7++8 and simmla repeted sign sttuations
        if(equation == ""){
            return 0;
        }

        //see if the equation is justy a number, if its not then set error equal to the error
        try{
            return stod(equation);
        }
        catch(exception e){
            *error = "equation invalid at: " + equation;
        }
      
    }
    
    return 0;

}


int main(){
    //this happens when the program is first run
    string input;
    string error;
    cout << "Enter Equation: ";
    //gues to start, skiping over the message that prints is subsiquint loops
    goto start;

    //prints out the new message in later runs
    laterruns:
    cout << "Enter Equation or type exit to exit: ";

    //does the auctual code
    start:
    input = "";
    error = "";

    //gets the user input
    cin >> input;

    //makes input uppercase
    string inputUpper;
    for(int i = 0; i<input.length(); i++){
        inputUpper += toupper(input.at(i));
    }

    //checks if the user has typed exit in the input, and exits if they have
    if(inputUpper.find("EXIT") != string::npos){
        cout << "goodbye" << "\n";
        exit(0);
    }

    //gets the vaue from the calculator
    //error has an and sign infromt of it beacuse it is being passed as a pointer so it can be updater from inside the function
    int answer = calculator(input, &error);

    //if there is an error, show it
    if(error == ""){
        cout << answer << "\n";
    }

    //if there was no error, show the answer returned
    else{
        cout << error << "\n";
    }

    //jump up to the start message and keep running
    goto laterruns;
}