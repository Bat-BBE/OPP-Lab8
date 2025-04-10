#include <iostream>
#include <math.h>
using namespace std; 
class Shape {
    public: 
        virtual double calculate_area() = 0; 
        double x_coordinate; 
        double y_coordinate; 
};
class Shape2D : public Shape{
    public : 
        double area; 
        double perimeter; 
}; 
class Circle : public Shape2D{
    public:
        double radius; 
        double calculate_area() override {
            return radius * radius * M_PI; 
        } 
}; 
class Square : public Shape{
    public: 
        double length;
        double calculate_area() override{
            return length * length; 
        }
}; 
int main(){
    Circle circle; 
    circle.radius = 5; 
    cout<<circle.calculate_area()<<endl; 

    Square square; 
    square.length = 10;
    cout<<square.calculate_area()<<endl; 

    return 0; 
}