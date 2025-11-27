#include <iostream>

using namespace std;

class Polygon{
protected:
	int width, height;
public:
	Polygon(int a = 0, int b = 0){
		width = a;
		height = b;
	}
	virtual int area(){
		cout << "This is area as computed by the Polygon class" << endl;
		return 0;
	}
};

class PaintCost{
public:
	int getCost(int area){
		return area * 70;
	}
};

class Rectangle:public Polygon,public PaintCost{
public:
	Rectangle(int a = 0, int b = 0):Polygon(a,b){}
	int area(){
		cout << "This is area as computed by the Rectangle class" << endl;
		return width * height;
	}

};

class Triangle:public Polygon{
public:
	int area(){
		return (width * height) / 2;
	}
};

int main(){
	Polygon *polygon;
	Rectangle rect(10,7);
	polygon = &rect;
	polygon ->area();
	cout << "Emvadon orthogoniou: " << rect.area() << endl;
	//cout << "Synoliko kostos xrwmatos: " << rect.getCost(rect.area()) << " euros" << endl;
	//Triangle tr;
	//tr.set_values(6,4);
	//cout << "Emvadon trigonou: " << tr.area() << endl;
	return 0;
}
