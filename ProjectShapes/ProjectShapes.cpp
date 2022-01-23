// By. Carmeshia Lazzana
//

#include <iostream>
#include <cmath>
#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>

using namespace std;

const double PI = 3.1416;

//Base Class Shape
class Shape
{
private:
	string name;
	string color;
	int x;
	int y;
	static int coordinates;

public:

	Shape()
	{
		name = "";
		color = "";
		x = 0;
		y = 0;
		coordinates = (x, y);
	};
	Shape(const string n, const string c, const int a, const int b)
	{
		name = n;
		color = c;
		x = a;
		y = b;
	};

	void setName(string n)
	{
		name = n;
	};

	void setColor(string c)
	{
		color = c;
	};

	void setXcoord(int a)
	{
		x = a;
	};

	void setYcoord(int b)
	{
		y = b;
	};

	string getName() const
	{
		return name;
	};

	const string getColor() const
	{
		return color;
	};

	const int getXcoord() const
	{
		return x;
	};

	const int getYcoord() const
	{
		return y;
	};

	virtual void render() const
	{
		cout << "Name: " << name << ", ";
		cout << "Color: " << color << ", ";
		cout << "X: " << x << ", ";
		cout << "Y: " << y <<  endl;
	};

	virtual ~Shape() {};


};

// Derived Class 2DShape
class TwoDimensionalShape : public Shape
{
private: 
	int area;
	
public:

	TwoDimensionalShape() : Shape("", "", 0, 0)
	{
		area = 0;
	};

	TwoDimensionalShape(string n, string c, int a, int b, int ar) : Shape(n, c, a, b)
		
	{
		area = ar;
	};

	void setArea(const int ar)
	{
		area = ar;
	}

	virtual const int getArea() const
	{
		
		return area;
	};

	virtual void render() const 
	{
		Shape::render();
		cout << "The area is ";
	}
	virtual ~TwoDimensionalShape() {};
};

//2D - square
class square : public TwoDimensionalShape
{
private:
	int length;
public:
	 
	square() : TwoDimensionalShape()
	{
		length = 0;
	};

	square(string n, string c, int a, int b, int ar, int l) : TwoDimensionalShape(n,c,a,b,ar)
	{
		length = l;
	};

	void setLength(const int l) 
	{
		length = l;
	};

	const int getLength() const
	{
		return length;
	};

	const int getArea() const
	{
		
		return length * length;
	};

	void render() const
	{
		TwoDimensionalShape::render();
		cout << square::getArea();
	}
};

// 2D - Circcle
class circle : public TwoDimensionalShape
{
private:
	int radius;
public:
	circle() : TwoDimensionalShape()
	{
		radius = 0;
	};

	circle(string n, string c, int a, int b, int ar, int r) : TwoDimensionalShape(n, c, a, b, ar)
	{
		radius = r;
	};

	void setRadius(int r)
	{
		radius = r;
	};
	
	const int getRadius() const
	{
		return radius;
	};

	const int getArea() const
	{

		return static_cast<int> (PI * (radius * radius));
	};

	void render() const
	{
		TwoDimensionalShape::render();
		cout << circle::getArea();
	}
};

// 2D - Triangle
class triangle : public TwoDimensionalShape
{
private: 
	int base;
	int height;

public:
	triangle() : TwoDimensionalShape()
	{
		base = 0;
		height = 0;
	};

	triangle(string n, string c, int a, int b, int ar, int bs, int h) : TwoDimensionalShape(n, c, a, b, ar)
	{
		base = bs;
		height = h;
	};

	void setBase(int bs)
	{
		base = bs;
	};

	void setHeight(int h)
	{
		height = h;
	};

	const int getBase() const
	{
		return base;
	};

	const int getHeight() const
	{
		return height;
	};

	const int getArea() const
	{

		return (height * base) / 2;
	};

	void render() const
	{
		TwoDimensionalShape::render();
		cout << triangle::getArea();
	}
};

// 2D - Line
class line : public TwoDimensionalShape
{
private:
	int length;

public:
	line() : TwoDimensionalShape()
	{
		length = 0;
	};

	line(string n, string c, int a, int b, int ar, int ln) : TwoDimensionalShape(n, c, a, b, ar)
	{
		length = ln;
	};

	void setLength(const int ln)
	{
		length = ln;
	};

	const int getLength() const
	{
		return length;
	};

	const int getArea() const
	{

		return length * 0;
	};

	void render() const
	{
		TwoDimensionalShape::render();
		cout << line::getArea();
	}

};

// Derived 3DShape
class ThreeDimensionalShape : public Shape
{
private:
	int volume;
 public:
	 ThreeDimensionalShape() : Shape("", "", 0, 0)
	 {
		 volume = 0;
	 };

	 ThreeDimensionalShape(string n, string c, int a, int b, int v) : Shape(n, c, a, b)
	 {
		 volume = v;
	 };

	 virtual ~ThreeDimensionalShape() {};

	 void setVolume(const int v)
	 {
		 volume = v;
	 }

	 virtual const int getVolume() const
	 {

		 return volume;
	 };

	 virtual void render() const
	 {
		 Shape::render();
		 cout << "The volume is " << endl;
	 }

};

// 3D - Sphere
class sphere : public ThreeDimensionalShape
{
private:
	int radius;

public:

	sphere() : ThreeDimensionalShape()
	{
		radius = 0;
	};

	sphere(string n, string c, int a, int b, int ar, int rd) : ThreeDimensionalShape(n, c, a, b, ar)
	{
		radius = rd;
	};

	void setRadius(const int rd)
	{
		radius = rd;
	};

	const int getRadius() const
	{
		return radius;
	};

	const int getVolume() const
	{

		return static_cast<int> ((4 / 3) * PI * (radius * radius * radius));
	};

	void render() const
	{
		ThreeDimensionalShape::render();
		cout << sphere::getVolume();
	}

};

// 3D - Cylinder
class cylinder : public ThreeDimensionalShape
{
private:
	int radius;
	int height;

public:
	cylinder() : ThreeDimensionalShape()
	{
		radius = 0;
		height = 0;
	};

	cylinder(string n, string c, int a, int b, int ar, int rs, int hg) : ThreeDimensionalShape(n, c, a, b, ar)
	{
		radius = rs;
		height = hg;
	};

	void setRadius(const int rs)
	{
		radius = rs;
	};

	const int getRadius()
	{
		return radius;
	};

	void setHeight(const int hg)
	{
		height = hg;
	}
	const int getHeight() const
	{
		return height;
	};

	const int getVolume() const
	{

		return static_cast<int> (PI * (radius * radius) * height);
	};

	void render() const
	{
		ThreeDimensionalShape::render();
		cout << cylinder::getVolume();
	}
};

//3D - Cone
class cone : public ThreeDimensionalShape
{
private:
	int radius;
	int height;

public:
	cone() : ThreeDimensionalShape()
	{
		radius = 0;
		height = 0;
	};

	cone(string n, string c, int a, int b, int ar, int rad, int coneHeight) : ThreeDimensionalShape(n, c, a, b, ar)
	{
		radius = rad;
		height = coneHeight;
	};

	void setRadius(const int rad)
	{
		radius = rad;
	};

	const int getRadius()
	{
		return radius;
	};

	void setHeight(const int coneHeight)
	{
		height = coneHeight;
	}
	const int getHeight() const
	{
		return height;
	};

	const int getVolume() const
	{

		return static_cast<int> (PI * (radius * radius) * (height/3));
	};

	void render() const
	{
		ThreeDimensionalShape::render();
		cout << cone::getVolume();
	}
	
};

// 3D - Cube
class cube : public ThreeDimensionalShape
{
private:
	int length;

public:
	cube() : ThreeDimensionalShape()
	{
		length = 0;
	};
	const int getLength() const
	{
		return length;
	};
	
	cube(string n, string c, int a, int b, int ar, int cbLength) : ThreeDimensionalShape(n, c, a, b, ar)
	{
		length = cbLength;
	};

	void setLength(const int cbLength)
	{
		length = cbLength;
	};

	const int getVolume() const
	{

		return length * length * length;
	};

	void render() const
	{
		ThreeDimensionalShape::render();
		cout << cube::getVolume();
	}
	
};

const int AddShapesToArray(Shape**, const int)
{
	int n, c, b, a, r;
	const int capacity = 15;
	int numOfObjects = 0;

	Shape **shArr = new Shape*[capacity];
	
	shArr[numOfObjects++] = new Shape;
	

	for (int i = 0; i < numOfObjects; i++)
	{
		
		cout << shArr[i] << endl;
	}

	for (int i =0; i < numOfObjects; i++)
	{
		delete shArr[i];
	}

	delete[] shArr;

	//Shape** shp[15];


	ifstream infile("Shapes.txt");
	if (!infile)
	{
		cout << "\nCan't open input file.";
		exit(1);
	}

	/*while (infile >> n >> c >> b >> a >> r)*/
		//ptr[ctr++] = new cylinder(x, y, r, h, clr);

	/*for (j = 0; j < ctr; j++)
	{
		ptr[j]->point::print();
		ptr[j]->radius::print();
		ptr[j]->print();
		cout << endl;
	}*/

	//return numOfObjects;
	
};

//void DisplayShapes(Shape**, const int)
//{
//
//};
//
//void FreeDynamicMemory(Shape**, const int)
//{
//
//};

int main()
{

	Shape* sha[15];
	square sq("bl","pink", 5,5,5,7);
	

	//TD5.render();
	sq.render();

	
	//ifstream infile("Shapes.txt");
	//if (!infile)
	//{
	//	cout << "\nCan't open input file.";
	//	exit(1);
	//}

	//// Data file now contains a char to indicate what type of object to create
	//// 'c' for Circle, 'l' for Cylinder, and 'p' for Point
	//// Objects are created using keyword new based on type,
	//// all objects are pointed to by pointers to the base class Point
	//infile >> type;

	//while (infile)
	//{
	//	if (type == 'c')
	//	{
	//		infile >> x >> y >> r;
	//		pptr[ctr++] = new Circle(x, y, r);
	//	}
	//	else if (type == 'l')
	//	{
	//		infile >> x >> y >> r >> h >> clr;
	//		pptr[ctr++] = new Cylinder(x, y, r, h, clr);
	//	}
	//	else if (type == 'p')
	//	{
	//		infile >> x >> y;
	//		pptr[ctr++] = new Point(x, y);
	//	}
	//	infile >> type;
	//}


	//// To print information for each object, simply call print function
	//// using base class pointer. Classes Point, Circle, and Cylinder all have 
	//// a print function. Since the print function is virtual,
	//// the program will choose the correct version of print function
	//// based on what is the real object.

	//for (j = 0; j < ctr; j++)
	//{
	//	pptr[j]->print();
	//	cout << endl;
	//	delete pptr[j];
	//}
	return 0;
}

