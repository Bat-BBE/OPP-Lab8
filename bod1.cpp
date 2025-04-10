#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Shape класс тодорхойлох
class Shape {
// Protected хандалтын түвшинтэй гишүүд
// cnt - Shape классаас үүссэн объектын тоо
// name - объектын нэр
protected:
    static int cnt;
    char* name;
public:
    // Байгуулгачин функц
    // cnt-г 1-ээр нэмэгдүүлж, name утга онооно
    Shape(const char* name) {
        cnt++;
        cout<<"Shape baiguulagch function ajilsan"<<endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    // Static функц cnt-г тохируулах
    // get() функц cnt-г хэвлэх
    static void set_cnt( int n);
    static void get();
    // Virtual дээрх функц устгах
    // cnt-г 1-ээр бууруулж, name-г устгах
    virtual ~Shape() {
        cnt--;
        cout << "Ustgasan shape: " << name << endl;
        delete[] name;
    }
    // Жинхэнэ хийсвэр функц
    virtual void print() = 0;
};
// Static гишүүнийг классын гадна талаас гарааны утга онооно
int Shape:: cnt = 0;
// Static функц cnt-г тохируулах
void Shape::set_cnt(int n) {
    cnt = n;
}
// Static функц cnt-г хэвлэх
void Shape::get() {
    cout << "Shape count: " << cnt << endl;
}

// Shape2D классыг Shape классаас удамшуулсан
class Shape2D : public Shape {
// Protected хандалтын түвшинтэй гишүүн 
// vertex - 2D хэлбэрийн талын тоо
protected: 
    int vertex;
// Public хандалтын түвшинтэй гишүүд
// center_x, center_y - төвийн координат
// length - урт
// coordinate - 2D хэлбэрийн координат
public: 
    double center_x;
    double center_y;
    double length;
    double** coordinate;
// Public хандалтын түвшинтэй гишүүн функцүүд
public:
    // Байгуулгачин функц
    // Shape2D классыг үүсгэхэд Shape классын name-г дамжуулна
    // center_x, center_y, length, vertex утгуудыг онооно
    Shape2D(const char* name, double x, double y, double l, int v) 
        : Shape(name), center_x(x), center_y(y), length(l), vertex(v) {
            cout<<"2DShape baiguulagch function ajilsan"<<endl;
            coordinate = nullptr;
        }
    // Virtual функц устгах
    // coordinate-г устгах
    virtual ~Shape2D() {
        if (coordinate != nullptr) {
            for (int i = 0; i < vertex; i++) {
                delete[] coordinate[i];
            }
            delete[] coordinate;
        }
        cout << "Ustgasan Shape2D: " << name << endl;
    }
    // Жинхэнэ хийсвэр функц
    // area() - талбайг тооцоолох
    virtual double area() = 0;
    // perimeter() - уртыг тооцоолох
    virtual double perimeter() = 0;
    // coordinates() - талуудын координатыг тооцоолох
    virtual void coordinates() = 0;
    // print() - объектын мэдээллийг хэвлэх
    virtual void print() {
        cout << "       Name: " << name << endl;
    }
};

// Circle классыг Shape2D классаас удамшуулсан
class Circle : public Shape2D {
// Public хандалтын түвшинтэй гишүүн функцүүд
public:
    // Байгуулгачин функц
    // Cirle классыг үүсгэхэд Shape2D классын name, center_x, center_y, radius утгуудыг дамжуулна
    Circle(const char* name, double center_x, double center_y, double radius)
        : Shape2D(name, center_x, center_y, radius, 1) {
            cout<<"Circle baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    // Virtual функцийг дахин програмччлалсан
    // Тойргийн талбайг тооцоолох
    double area() {
        return M_PI * this->length * this->length;
    }
    // Тойргийн уртыг тооцоолох
    double perimeter() {
        return 2 * M_PI * this->length;
    }
    // coordinates() - тойргийн төвийн координатыг тооцоолох
    void coordinates() {
        if(coordinate != nullptr) {
            delete[] coordinate[0];
            delete[] coordinate;
        }
        coordinate = new double*[1];
        coordinate[0] = new double[2];
        coordinate[0][0] = this->center_x;
        coordinate[0][1] = this->center_y;
    }
    // print() - объектын мэдээллийг хэвлэх
    void print() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       Perimeter: " << perimeter() << endl;
    }
    // Устгах функц
    ~Circle() {
        cout << "Ustgasan Circle: " << this->name << endl;
    }
};

// Square классыг Shape2D классаас удамшуулсан
class Square : public Shape2D {
// Public хандалтын түвшинтэй гишүүн функцүүд
public:
    // Байгуулгачин функц
    // Square классыг үүсгэхэд Shape2D классын name, center_x, center_y, side_length утгуудыг дамжуулна
    Square(const char* name, double center_x, double center_y, double side_length)
        : Shape2D(name, center_x, center_y, side_length, 4) {
            cout<<"Square baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    
    // Virtual функцийг дахин програмччлалсан
    // coordinates() - квадратын координатыг тооцоолох
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
        coordinate[0][0] = this->center_x - half;
        coordinate[0][1] = this->center_y + half;
        
        coordinate[1][0] = this->center_x + half;
        coordinate[1][1] = this->center_y + half;
        
        coordinate[2][0] = this->center_x + half;
        coordinate[2][1] = this->center_y - half;
        
        coordinate[3][0] = this->center_x - half;
        coordinate[3][1] = this->center_y - half;
    }
    
    // Квадратын талбайг тооцоолох
    double area() {
        return this->length * this->length;
    }
    // Квадратын уртыг тооцоолох
    double perimeter() {
        return 4 * this->length;
    }
    // print() - объектын мэдээллийг хэвлэх
    void print() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       Perimeter: " << perimeter() << endl;
    }
    // Устгах функц
    ~Square() {
        cout << "Ustgasan Square: " << this->name << endl;
    }
};

// Triangle классыг Shape2D классаас удамшуулсан
class Triangle : public Shape2D {
// Public хандалтын түвшинтэй гишүүн функцүүд
public:
    // Байгуулгачин функц
    // Triangle классыг үүсгэхэд Shape2D классын name, center_x, center_y, side_length утгуудыг дамжуулна
    Triangle(const char* name, double center_x, double center_y, double side_length)
        : Shape2D(name, center_x, center_y, side_length, 3) {
            cout<<"Triangle baiguulagch function ajilsan"<<endl;
            coordinates();
        }
    // Virtual функцийг дахин програмччлалсан
    // coordinates() - гурвалжны координатыг тооцоолох
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
        
        double height = (sqrt(3) / 2) * this->length;
        coordinate[0][0] = this->center_x;
        coordinate[0][1] = this->center_y + (height / 1.5);
        
        coordinate[1][0] = this->center_x - this->length / 2;
        coordinate[1][1] = this->center_y - (height / 3);
        
        coordinate[2][0] = this->center_x + this->length / 2;
        coordinate[2][1] = this->center_y - (height / 3);
    }
    // Гурвалжны талбайг тооцоолох
    double area() {
        return (sqrt(3)/4) * this->length * this->length;
    }
    // Гурвалжны уртыг тооцоолох
    double perimeter() {
        return 3 * this->length;
    }
    // print() - объектын мэдээллийг хэвлэх
    void print() {
        Shape2D::print();
        cout << "       Area: " << area() << endl;
        cout << "       Perimeter: " << perimeter() << endl;
    }
    // Устгах функц
    ~Triangle() {
        cout << "Ustgasan Triangle: " << this->name << endl;
    }
};

// selectionSortArea функц - талбайгаар эрэмбэлэх
void selectionSortArea(Shape2D* shapes[], int n) {
    // shapes массивын элементүүдийг талбайгаар эрэмбэлэх
    // n - массивын хэмжээ
    // i - эхний индекс
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // j - дараагийн индекс
        // shapes массивын элементүүдийг шалгах
        // min_idx - хамгийн бага индекс
        for (int j = i + 1; j < n; j++) {
            // shapes массивын элементүүдийн талбайг харьцуулах
            if (shapes[j]->area() < shapes[min_idx]->area()) {
                // Хэрэв j индексийн элемент нь хамгийн бага элементээс бага бол min_idx-г шинэчлэх
                min_idx = j;
            }
        }
        // Хэрэв min_idx нь i-ээс ялгаатай бол элементүүдийг солих
        if (min_idx != i) {
            Shape2D* temp = shapes[i];
            shapes[i] = shapes[min_idx];
            shapes[min_idx] = temp;
        }
    }
}
// selectionSortPerimeter функц - периметрээр эрэмбэлэх
void selectionSortPerimeter(Shape2D* shapes[], int n) {
    // shapes массивын элементүүдийг периметрээр эрэмбэлэх
    // n - maссивын хэмжээ
    // i - эхний индекс
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // j - дараагийн индекс
        // shapes массивын элементүүдийг шалгах
        // min_idx - хамгийн бага индекс
        for (int j = i + 1; j < n; j++) {
            // shapes массивын элементүүдийн периметрийг харьцуулах
            if (shapes[j]->perimeter() < shapes[min_idx]->perimeter()) {
                // Хэрэв j индексийн элемент нь хамгийн бага элементээс бага бол min_idx-г шинэчлэх
                min_idx = j;
            }
        }
        // Хэрэв min_idx нь i-ээс ялгаатай бол элементүүдийг солих
        if (min_idx != i) {
            Shape2D* temp = shapes[i];
            shapes[i] = shapes[min_idx];
            shapes[min_idx] = temp;
        }
    }
}

int main() {
    // srand(time(0)) - санамсаргүй тоо үүсгэх
    srand(time(0));
    // shapes массивыг үүсгэх
    // 10 элементтэй массив
    Shape2D* shapes[10];
    // Shape классын cnt-г 0-ээр тохируулах
    Shape::set_cnt(0);
    // Shape классын cnt-г хэвлэх
    Shape::get();
    cout << "====================" << endl;
    // shapes массивын элементүүдийг үүсгэх
    for(int i = 0; i < 10; i++) {
        // shapes массивын элементүүдийг санамсаргүй тоогоор үүсгэх
        // 0-2 хүртэлх санамсаргүй тоо үүсгэх
        int j = rand() % 3;
        // shapes массивын элементүүдийг Circle, Triangle, Square классаар үүсгэх
        // j = 0 бол Circle, j = 1 бол Triangle, j = 2 бол Square
        if(j == 0) {
            // Circle классыг үүсгэх
            // name - "Circle", center_x, center_y - санамсаргүй тоо, radius - санамсаргүй тоо + 1
            shapes[i] = new Circle("Circle", rand()%20, rand()%20, rand()%20 + 1);
        } else if(j == 1) {
            // Triangle классыг үүсгэх
            // name - "Triangle", center_x, center_y - санамсаргүй тоо, side_length - санамсаргүй тоо + 1
            shapes[i] = new Triangle("Triangle", rand()%20, rand()%20, rand()%20 + 1);
        } else {
            // Square классыг үүсгэх
            // name - "Square", center_x, center_y - санамсаргүй тоо, side_length - санамсаргүй тоо + 1
            shapes[i] = new Square("Square", rand()%20, rand()%20, rand()%20 + 1);
        }
    }
    cout << "====================" << endl;
    
    // shapes массивын элементүүдийн мэдээллийг хэвлэх
    cout << "Ankhnii medeelel: " << endl;
    for (int i = 0; i < 10; i++) {
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;
    
    // shapes массивын элементүүдийг талбайгаар эрэмбэлэх
    selectionSortArea(shapes, 10);
    
    // shapes массивын элементүүдийн талбайгаар эрэмбэлсэн мэдээллийг хэвлэх
    cout << "\nTalbaigaar erembelegdsen medeelel: " << endl;
    for (int i = 0; i < 10; i++) {
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;

    // shapes массивын элементүүдийг периметрээр эрэмбэлэх
    selectionSortPerimeter(shapes, 10);

    // shapes массивын элементүүдийн периметрээр эрэмбэлсэн мэдээллийг хэвлэх
    cout << "\nPerimetreer erembelegdsen medeelel: " << endl;
    for (int i = 0; i < 10; i++) {
        shapes[i]->print();
        cout << "   ---------------" << endl;
    }
    cout << "====================" << endl;

    Shape::get();
    // shapes массивын элементүүдийг устгах
    for(int i = 0; i < 10; i++) {
        delete shapes[i];
    }
    //
    Shape::get();
    cout << "====================" << endl;
    return 0;
}



