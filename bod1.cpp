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
        cout<<"Shape baiguulagch function ajilsan"<<endl;//shape classiin baiguulagch function 
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }
    virtual ~Shape() {
        cout << "Ustgasan shape: " << name << endl; //shape classiin ustgagch function
        delete[] name;//ustgagch functionii dotor name-iig ustgaj bna
        count--;
    }
    virtual void print() = 0;//jinhene hiiswer function
    static void countf(){//heden ob uussen esehiig tooloh jinhene hiiswer function
        cout << "Shape count: " << count << endl;
    }
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
            cout<<"2DShape baiguulagch function ajilsan"<<endl;
            coordinate = nullptr;
        }
    virtual ~Shape2D() {// shape2d classiin ustgagch function
        if (coordinate != nullptr) {
            for (int i = 0; i < vertex; i++) {
                delete[] coordinate[i];
            }
            delete[] coordinate;
        }
        cout << "Ustgasan Shape2D: " << name << endl;
    }
    virtual double area() = 0;//talbain jinhene hiiswer function
    virtual double perimeter() = 0;//perimeteriin jinhene hiiswer function
    virtual void coordinates() = 0;//coordinatiin jinhene hiiswer function 
    
    virtual void print() {//dahin programmchilsan jinhene hiiswer function 
        cout << "       Name: " << name << endl;
    }
};

class Circle : public Shape2D {//shape2d classaas udamshsan circle class
public:
    Circle(const char* name, double center_x, double center_y, double radius)//circle classiin baiguulagch function
        : Shape2D(name, center_x, center_y, radius, 1) {
            cout<<"Circle baiguulagch function ajilsan"<<endl;
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
    
    void print() {//dahin programchilsn print function 
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       perimeter: " << perimeter() << endl;// perimeteriig nemj ugsun
    }
   
    ~Circle() {//circle classiiin ustgagch function
        cout << "Ustgasan Circle: " << name << endl;
    }
};

class Square : public Shape2D {//shape2d gees udamshsan squre class
public:
    Square(const char* name, double center_x, double center_y, double side_length)//squre classiin baiguulagch function 
        : Shape2D(name, center_x, center_y, side_length, 4) {
            cout<<"Square baiguulagch function ajilsan"<<endl;
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
    
    double area() {//areag oloh dahin programchilsn function 
        return length * length;
    }
    
    double perimeter() {//perimeteriig oloh dahin programchilsn function
        return 4 * length;
    }
    
    void print() {//dahin programchilsn print function
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       perimeter: " << perimeter() << endl;
    }
    
    ~Square() {//square classiin ustgagch function
        cout << "Ustgasan Square: " << name << endl;
    }
};

class Triangle : public Shape2D {//shape2d gees udamshsan triangle class
public:
    Triangle(const char* name, double center_x, double center_y, double side_length)// triangle classiin baiguulagch function
        : Shape2D(name, center_x, center_y, side_length, 3) {
            cout<<"Triangle baiguulagch function ajilsan"<<endl;
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
    
    void print() {//dahin programchilsn print function
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       perimeter: " << perimeter() << endl;
    }
    ~Triangle() {//triangle classiin ustgagch function
        cout << "Ustgasan Triangle: " << name << endl;
    }
};

void selectionSort(Shape2D* shapes[], int n) {//talbaig oloh selection sort function
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
void selectionSort(Shape2D* shapes[], int n, bool (*compare)(Shape2D*, Shape2D*)) {//selection sort function 
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (compare(shapes[j], shapes[min_idx])) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(shapes[i], shapes[min_idx]);
        }
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
    srand(time(0));//real time aar songoj awah 
    Shape2D* shapes[10];
    for(int i = 0; i < 10; i++) {
        int j = rand() % 3;// 0-2 hurtel sanamsargui songoh
        if(j == 0) {
            shapes[i] = new Circle("Circle", rand()%20, rand()%20, rand()%20 + 1);
        } else if(j == 1) {
            shapes[i] = new Triangle("Triangle", rand()%20, rand()%20, rand()%20 + 1);
        } else {
            shapes[i] = new Square("Square", rand()%20, rand()%20, rand()%20 + 1);
        }
    }
        Shape::countf();//countf functioniig duudaj bn
        Shape::getm();//getm functioniig duudaj bn 
    cout << "Ankhnii medeelel: " << endl;
    for (int i = 0; i < 10; i++) {//songoj awsan 10 objectiin anhnii medeelliig hewleh 
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;
    
    selectionSort(shapes, 10);
    
    cout << "\ntalbaigaar Erembelegdsen medeelel: " << endl;//talbaigaarn eremblesn medeelliig hewlej gargah 
    for (int i = 0; i < 10; i++) {
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;
    
    selectionSort(shapes, 10);//selection sort duudaj gargah 

    cout << "\nperimetereer Erembelegdsen medeelel: " << endl;//perimetereern eremblen medeelliig hewlej gargah 
    for (int i = 0; i < 10; i++) {
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;

    for(int i = 0; i < 10; i++) {
        delete shapes[i];//songoj awsan 10 objectoo ustgah 
    }
    Shape::countf();//ustsan esehiig shalgah 
    return 0;
}