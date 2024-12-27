#include<iostream>
using namespace std;

#include<cmath>

class Triangle;

class Point{
public:
    double x, y;

public:
    Point(){
        this->x = 0.0;
        this->y = 0.0;
    }

    Point(double x, double y){
        this->x = x;
        this->y = y;
    };

    //used if some objects are instantiated with operator new
    ~Point(){};

    double getx(){return this->x;}
    double gety(){return this->y;}

    void setx(double x){
        this->x = x;
    }
    void sety(double y){
        this->y = y;
    }

    //if(area of PAB+PBC+PAC)==area of ABC) it means the point
    //is inside the triangle otherwise its outside the triangle.
    //  area of ABC = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
    bool isInsideTriangle(const Triangle& T);

    void printPoint(){
        cout << "(" << x << ", " << y << ")" << endl;
    }

};

class Triangle{
    public:
        Point A, B, C;
        
        Triangle(const Point& A, const Point& B, const Point& C){
            this-> A = A;
            this-> B = B;
            this-> C = C;
        }

        ~Triangle(){};

        void printTriangle(){
            cout << "Tocke trokuta su: " << endl;
            cout << "(" << A.getx() << ", " << A.getx() << ")" << endl;
            cout << "(" << B.getx() << ", " << B.getx() << ")" << endl;
            cout << "(" << C.getx() << ", " << C.getx() << ")" << endl;
        }
};

bool Point::isInsideTriangle(const Triangle& T){
    double areaABC = abs((T.A.x*(T.B.y-T.C.y) + T.B.x*(T.C.y-T.A.y) + T.C.x*(T.A.y-T.B.y))/2);
    double areaPBC = abs((T.A.x*(T.B.y-T.C.y) + T.B.x*(T.C.y-T.A.y) + T.C.x*(T.A.y-T.B.y))/2);
    double areaPAB = abs((x*(T.A.y-T.B.y) + T.A.x*(T.B.y-y) + T.B.x*(y-T.A.y))/2);
    double areaPAC = abs((x*(T.A.y-T.C.y) + T.A.x*(T.C.y-y) + T.C.x*(y-T.A.y))/2);
    
    return areaABC == (areaPAB + areaPAC + areaPBC);
}


int main(){

    Point P1(1, 2);
    Point P2(5.5, 8);
    Point P3(6, 10.5);
    Point *P = new Point(3.8, 7);

    Triangle T1(P1, P2, P3);
    T1.printTriangle();

    cout << "Is point P inside the triangle? ";
    
    cout << P->isInsideTriangle(T1) << endl;
    

    delete P;

    return 0;
}