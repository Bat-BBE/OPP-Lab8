#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class Shape {
protected:
    char* name;
public:
    static int count;  //heden ob baiguulsn talaar tooloh static huwisagch
    static int m;
    static int getm() {
        cout << "Shape m: " << m << endl; //m gesen static huwisagchiig awah function
    }
public:
    Shape(const char* name) {
        //cout<<"Shape baiguulagch function ajilsan"<<endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }
    virtual ~Shape() {
        //cout << "Ustgasan shape: " << name << endl;
        delete[] name;
    }
    virtual void print() = 0; 
    virtual void print_area() = 0;
    virtual void print_perimeter() = 0; 
};

class Shape2D : public Shape {//shape ees udamshsam shape2d class
protected: 
    int vertex;//protected gorimiin shape2d gishuun ugugdul 
public: 
    double center_x;
    double center_y;
    double length;
    double** coordinate;
public:
    Shape2D(const char* name, double x, double y, double l, int v) // shape2d classiin baiguulagch function
        : Shape(name), center_x(x), center_y(y), length(l), vertex(v) {
            //cout<<"2DShape baiguulagch function ajilsan"<<endl;
            coordinate = nullptr;
        }
    virtual ~Shape2D() {// shape2d classiin ustgagch function
        if (coordinate != nullptr) {
            for (int i = 0; i < vertex; i++) {
                delete[] coordinate[i];
            }
            delete[] coordinate;
        }
        //cout << "Ustgasan Shape2D: " << name << endl;
    }
    
    virtual double area() = 0; 
    virtual double perimeter() = 0;
    virtual void coordinates() = 0;
    
    virtual void print() {//dahin programmchilsan jinhene hiiswer function 
        cout << "       Name: " << name << endl;
    }
};

class Circle : public Shape2D {//shape2d classaas udamshsan circle class
public:
    Circle(const char* name, double center_x, double center_y, double radius)//circle classiin baiguulagch function
        : Shape2D(name, center_x, center_y, radius, 1) {
            //cout<<"Circle baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    double area() {//talbaig oloh dahin programchilsan function
        return M_PI * length * length;
    }
    double perimeter() {//perimeteriig oloh dahin programchilsn function 
        return 2 * M_PI * length;
    }
    
    void coordinates() {//coordinateiig olsn dahin programchilsn function 
        if(coordinate != nullptr) {
            delete[] coordinate[0];
            delete[] coordinate;
        }
        coordinate = new double*[1];
        coordinate[0] = new double[2];
        coordinate[0][0] = center_x;
        coordinate[0][1] = center_y;
    }

    void print(){
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout<<  "       Perimeter: " << perimeter() << endl;
    }
    
    void print_area() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       perimeter: " << perimeter() << endl;// perimeteriig nemj ugsun
    }

    void print_perimeter(){
        Shape2D::print();
        cout<<  "       Perimeter: " << perimeter() << endl;
    }


    
    ~Circle() {
        //cout << "Ustgasan Circle: " << name << endl;
    }
};

class Square : public Shape2D {//shape2d gees udamshsan squre class
public:
    Square(const char* name, double center_x, double center_y, double side_length)//squre classiin baiguulagch function 
        : Shape2D(name, center_x, center_y, side_length, 4) {
            //cout<<"Square baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    
    void coordinates() {//coordinates olsn dahinn programchilsn function 
        if(coordinate != nullptr) {
            for (int i = 0; i < 4; i++) {
                delete[] coordinate[i];
            }
            delete[] coordinate;
        }
        
        coordinate = new double*[4];
        for (int i = 0; i < 4; i++) {
            coordinate[i] = new double[2];
        }
    
        double half = length / 2;
        coordinate[0][0] = this->center_x - half;//this huwisagch ashiglan
        coordinate[0][1] = this->center_y + half;//this huwisagch ashiglan
        
        coordinate[1][0] = this->center_x + half;//this huwisagch ashiglan
        coordinate[1][1] = this->center_y + half;//this huwisagch ashiglan
        
        coordinate[2][0] =this-> center_x + half;//this huwisagch ashiglan
        coordinate[2][1] = this->center_y - half;//this huwisagch ashiglan
        
        coordinate[3][0] = this->center_x - half;//this huwisagch ashiglan
        coordinate[3][1] = this->center_y - half;//this huwisagch ashiglan
    }
    
    // double area()
    double area() {
        return length * length;
    }
    
    double perimeter() {//perimeteriig oloh dahin programchilsn function
        return 4 * length;
    }

    void print(){
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout<<  "       Perimeter: " << perimeter() << endl;
    }
    
    void print_area() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       perimeter: " << perimeter() << endl;
    }

    void print_perimeter(){
        Shape2D::print();
        cout<<  "       Perimeter: " << perimeter() << endl;
    }
    
    ~Square() {
        //cout << "Ustgasan Square: " << name << endl;
    }
};

class Triangle : public Shape2D {//shape2d gees udamshsan triangle class
public:
    Triangle(const char* name, double center_x, double center_y, double side_length)// triangle classiin baiguulagch function
        : Shape2D(name, center_x, center_y, side_length, 3) {
            //cout<<"Triangle baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    
    void coordinates() {//coordinatesiig olsn dahinn programchilsn function
        if(coordinate != nullptr) {
            for (int i = 0; i < 3; i++) {
                delete[] coordinate[i];
            }
            delete[] coordinate;
        }
        
        coordinate = new double*[3];
        for (int i = 0; i < 3; i++) {
            coordinate[i] = new double[2];
        }
        
        double height = (sqrt(3) / 2) * length;
        coordinate[0][0] = this->center_x;//this huwisagch ashiglan
        coordinate[0][1] = this->center_y + (height / 1.5);//this huwisagch ashiglan
        
        coordinate[1][0] = this->center_x - length / 2;//this huwisagch ashiglan
        coordinate[1][1] = this->center_y - (height / 3);//this huwisagch ashiglan
        
        coordinate[2][0] = this->center_x + length / 2;//this huwisagch ashiglan
        coordinate[2][1] = this->center_y - (height / 3);//this huwisagch ashiglan
    }
    
    double area() {//areag oloh dahin programchilsn function
        return (sqrt(3)/4) * length * length;
    }
    
    double perimeter() {//perimeteriig oloh dahin programchilsn function
        return 3 * length;
    }

    void print(){
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout<<  "       Perimeter: " << perimeter() << endl;
    }
    
    void print_area() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       perimeter: " << perimeter() << endl;
    }

    void print_perimeter(){
        Shape2D::print();
        cout<<  "       Perimeter: " << perimeter() << endl;
    }
    
    ~Triangle() {
        //cout << "Ustgasan Triangle: " << name << endl;
    }
};

void selectionSort(Shape2D* shapes[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (shapes[j]->area() < shapes[min_idx]->area()) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(shapes[i], shapes[min_idx]);
        }
    }
}
// Insertion sort for sorting perimeters. 
// Separates array into sorted and unsorted. Compares first unsorted value of the array and places it in the correct position. 
void insertion_sort(Shape2D* shapes[], int n){
    for(int i = 1; i < n; i++){
        Shape2D* current = shapes[i]; 
        double min_val = current->perimeter(); 
        int j = i - 1; 

        while(j >= 0 && shapes[j]->perimeter() > min_val){
            shapes[j+1] = shapes[j]; 
            j--; 
        }
        shapes[j+1] = current; 
    }
}

bool compareByArea(Shape2D* a, Shape2D* b) {//areagaar solih function
    return a->area() < b->area();
}

bool compareByPerimeter(Shape2D* a, Shape2D* b) {//perimetereer ni solih function
    return a->perimeter() < b->perimeter();
}


int Shape::count = 0;//shape classiin static huwisagch count-iig 0-oor ehluulj bna
int Shape:: m=0;//shape classiin static huwisagch m-iig 0-oor ehluulj bna
int main() {
    srand(time(0));
    int n = 10; 
    Shape2D* shapes[n];
    for(int i = 0; i < n; i++) {
        int j = rand() % 3;
        if(j == 0) {
            shapes[i] = new Circle("Circle", rand()%20, rand()%20, rand()%20 + 1);
        } else if(j == 1) {
            shapes[i] = new Triangle("Triangle", rand()%20, rand()%20, rand()%20 + 1);
        } else {
            shapes[i] = new Square("Square", rand()%20, rand()%20, rand()%20 + 1);
        }
    }
        // Shape::countf();//countf functioniig duudaj bn
        // Shape::getm();//getm functioniig duudaj bn 
    cout << "Ankhnii medeelel: " << endl;
    for (int i = 0; i < n; i++) {
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;
    
    selectionSort(shapes, n);
    
    cout << "\nErembelegdsen medeelel (Area): " << endl;
    for (int i = 0; i < n; i++) {
        shapes[i]->print_area();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;

    insertion_sort(shapes, n); 

    cout<<"\nErembelegdsen medeelel (Perimeter): "<<endl;
    for(int i = 0; i < n; i++){
        shapes[i]->print_perimeter(); 
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;
    
    for(int i = 0; i < n; i++) {
        delete shapes[i];
    }
    cout << "====================" << endl;

    for(int i = 0; i < 10; i++) {
        delete shapes[i];//songoj awsan 10 objectoo ustgah 
    }
    // Shape::countf();//ustsan esehiig shalgah 
    return 0;
}