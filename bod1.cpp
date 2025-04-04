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
    Shape(const char* name) {
        cout<<"Shape baiguulagch function ajilsan"<<endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    virtual ~Shape() {
        cout << "Ustgasan shape: " << name << endl;
        delete[] name;
    }
    virtual void print() = 0;
};

class Shape2D : public Shape {
protected: 
    int vertex;
public: 
    double center_x;
    double center_y;
    double length;
    double** coordinate;
public:
    Shape2D(const char* name, double x, double y, double l, int v) 
        : Shape(name), center_x(x), center_y(y), length(l), vertex(v) {
            cout<<"2DShape baiguulagch function ajilsan"<<endl;
            coordinate = nullptr;
        }
    virtual ~Shape2D() {
        if (coordinate != nullptr) {
            for (int i = 0; i < vertex; i++) {
                delete[] coordinate[i];
            }
            delete[] coordinate;
        }
        cout << "Ustgasan Shape2D: " << name << endl;
    }
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void coordinates() = 0;
    
    virtual void print() {
        cout << "       Name: " << name << endl;
    }
};

class Circle : public Shape2D {
public:
    Circle(const char* name, double center_x, double center_y, double radius)
        : Shape2D(name, center_x, center_y, radius, 1) {
            cout<<"Circle baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    double area() {
        return M_PI * length * length;
    }
    double perimeter() {
        return 2 * M_PI * length;
    }
    
    void coordinates() {
        if(coordinate != nullptr) {
            delete[] coordinate[0];
            delete[] coordinate;
        }
        coordinate = new double*[1];
        coordinate[0] = new double[2];
        coordinate[0][0] = center_x;
        coordinate[0][1] = center_y;
    }
    
    void print() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
    }
    
    ~Circle() {
        cout << "Ustgasan Circle: " << name << endl;
    }
};

class Square : public Shape2D {
public:
    Square(const char* name, double center_x, double center_y, double side_length)
        : Shape2D(name, center_x, center_y, side_length, 4) {
            cout<<"Square baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    
    void coordinates() {
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
        coordinate[0][0] = center_x - half;
        coordinate[0][1] = center_y + half;
        
        coordinate[1][0] = center_x + half;
        coordinate[1][1] = center_y + half;
        
        coordinate[2][0] = center_x + half;
        coordinate[2][1] = center_y - half;
        
        coordinate[3][0] = center_x - half;
        coordinate[3][1] = center_y - half;
    }
    
    double area() {
        return length * length;
    }
    
    double perimeter() {
        return 4 * length;
    }
    
    void print() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
    }
    
    ~Square() {
        cout << "Ustgasan Square: " << name << endl;
    }
};

class Triangle : public Shape2D {
public:
    Triangle(const char* name, double center_x, double center_y, double side_length)
        : Shape2D(name, center_x, center_y, side_length, 3) {
            cout<<"Triangle baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    
    void coordinates() {
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
        coordinate[0][0] = center_x;
        coordinate[0][1] = center_y + (height / 1.5);
        
        coordinate[1][0] = center_x - length / 2;
        coordinate[1][1] = center_y - (height / 3);
        
        coordinate[2][0] = center_x + length / 2;
        coordinate[2][1] = center_y - (height / 3);
    }
    
    double area() {
        return (sqrt(3)/4) * length * length;
    }
    
    double perimeter() {
        return 3 * length;
    }
    
    void print() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
    }
    
    ~Triangle() {
        cout << "Ustgasan Triangle: " << name << endl;
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

int main() {
    srand(time(0));
    Shape2D* shapes[10];
    for(int i = 0; i < 10; i++) {
        int j = rand() % 3;
        if(j == 0) {
            shapes[i] = new Circle("Circle", rand()%20, rand()%20, rand()%20 + 1);
        } else if(j == 1) {
            shapes[i] = new Triangle("Triangle", rand()%20, rand()%20, rand()%20 + 1);
        } else {
            shapes[i] = new Square("Square", rand()%20, rand()%20, rand()%20 + 1);
        }
    }
    
    cout << "Ankhnii medeelel: " << endl;
    for (int i = 0; i < 10; i++) {
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;
    
    selectionSort(shapes, 10);
    
    cout << "\nErembelegdsen medeelel: " << endl;
    for (int i = 0; i < 10; i++) {
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;
    
    for(int i = 0; i < 10; i++) {
        delete shapes[i];
    }
    return 0;
}