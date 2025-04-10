#include <iostream>

void say(const char* message){
    puts(message);
}

int main(int argc, char ** argv){

    // Declare a function pointer that points to a function
    // taking const char* and returning void 
    void(*sayPointer)(const char*); 

    // Assign the separate say function to the pointer 
    sayPointer = say; 

    // Use the function pointer to call the say function 
    sayPointer("Hello world");

    return 0; 
}