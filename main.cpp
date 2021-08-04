#include<iostream>
#include<fstream>
#include<cmath>
#include"graphics.h"
using namespace std;
struct point                  // a struct for point
{
	int x;
	int y;
};

class shape                 // an abstract class
{
protected:
	int x1, x2, y1, y2;
	point* p;                //Array for position of points
	int size;                //size of the points array
	int color;               //colorof the shape
	bool fill;              // Whether the shape is filled or not
public:
	virtual void draw() = 0;       //virtual function of draw
	virtual void setcolor(int _color) = 0;       // Sets the color of the shape
	virtual void setfill(bool _fill) = 0;              //sets whether the shape is filled or not

};
class Rect :public shape
{
public:
	Rect();
	virtual void draw();
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
};
Rect::Rect()
{
	///declaring in the constructor the vareiables
	size = 2;
	p = new point[size];
	color = WHITE;
	fill = false;
}
void Rect::setfill(bool _fill)
{
	fill = _fill;
}

void Rect::setcolor(int _color)
{
	color = _color;
}

void Rect::draw()
{
	
	while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x1, y1);
	putpixel(x1, y1, 15);
	p[0].x = x1;
	p[0].y = y1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x2, y2);
	putpixel(x2, y2, 15);
	p[1].x = x2;
	p[1].y = y2;
	if (p[0].x > 100  &&  p[1].x>100)
	{
		rectangle(p[0].x, p[0].y, p[1].x, p[1].y);
		rectangle(p[1].x, p[1].y, p[0].x, p[0].y);
		clearmouseclick(WM_LBUTTONDOWN);
	}
}
class square :public shape
{
public:
	square();
	virtual void draw();
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
};
square::square()
{
	///declaring in the constructor the vareiables
	size = 2;
	p = new point[size];
	color = WHITE;
	fill = false;

}
void square::setfill(bool _fill)
{
	fill = _fill;
}

void square::setcolor(int _color)
{
	color = _color;
}

void square::draw()
{

	while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x1, y1);
	putpixel(x1, y1, 15);
	p[0].x = x1;
	p[0].y = y1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x2, y2);
	putpixel(x2, y2, 15);
	p[1].x = x2;
	p[1].y = y2;
	if (p[0].x > 100 && p[1].x > 100)
	{
		rectangle(p[0].x, p[0].y, p[1].x, p[1].y);
		rectangle(p[1].x, p[1].y, p[0].x, p[0].y);
		clearmouseclick(WM_LBUTTONDOWN);
	}
}
class Line :public shape
{
public:
	Line();
	virtual void draw();
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
};
Line::Line()
{
	///declaring in the constructor the vareiables

	size = 2;
	p = new point[size];
	color = WHITE;
	fill = false;

}
void Line::setfill(bool _fill)
{
	fill = _fill;
}

void Line::setcolor(int _color)
{
	color = _color;
}

void Line::draw()
{

	while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x1, y1);
	p[0].x = x1;
	p[0].y = y1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x2, y2);
	p[1].x = x2;
	p[1].y = y2;
	if (p[0].x > 100 && p[1].x > 100)
	{
		line(p[0].x, p[0].y, p[1].x, p[1].y);
		clearmouseclick(WM_LBUTTONDOWN);
	}
}
class Circle :public shape
{
public:
	Circle();
	virtual void draw();
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
};
Circle::Circle()
{
	///declaring in the constructor the vareiables
	size = 2;
	p = new point[size];
	color = WHITE;
	fill = false;

}
void Circle::setfill(bool _fill)
{
	fill = _fill;
}

void Circle::setcolor(int _color)
{
	color = _color;
}

void Circle::draw()
{

	int x, y, r;
	while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x1, y1);
	p[0].x = x1;
	p[0].y = y1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x2, y2);
	p[1].x = x2;
	p[1].y = y2;
	x = (p[0].x + p[1].x) / 2;
	y = (p[0].y + p[1].y) / 2;
	r = sqrt(pow(x - p[0].x, 2) + pow(y - p[0].y, 2));
	if (p[0].x > 100 && p[1].x > 100)
	{
		circle(p[0].x, p[0].y, r);
		clearmouseclick(WM_LBUTTONDOWN);
	}
}

class triangle :public shape //class for rectange
{
public:
	triangle();
	virtual void draw();
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
};
triangle::triangle()
{
	///declaring in the constructor the vareiables
	size = 6;
	p = new point[size];
	color = WHITE;
	fill = false;

}
void triangle::setfill(bool _fill)
{
	fill = _fill;
}
void triangle::setcolor(int _color)
{
	color = _color;
}

void triangle::draw()
{
	
	int a1, b1, c, d, e, f, g, h;

	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, a1, b1);

	p[0].x = a1;
	p[1].x = b1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, c, d);

	p[2].x = c;
	p[3].x = d;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, e, f);
	p[4].x = e;
	p[5].x = f;
	if (p[0].x > 100 && p[2].x > 100 && p[4].x > 100)
	{
		line(p[0].x, p[1].x, p[2].x, p[3].x);
		/////////////////////////////////////
		line(p[2].x, p[3].x, p[4].x, p[5].x);
		/////////////////////////////////////
		line(p[4].x, p[5].x, p[0].x, p[1].x);
		clearmouseclick(WM_LBUTTONDOWN);
	}
}
class polygon :public shape //class for rectange
{
public:
	polygon();
	virtual void draw();
	virtual void setcolor(int _color);
	virtual void setfill(bool _fill);
};
polygon::polygon()
{
	///declaring in the constructor the vareiables
	size = 12;
	p = new point[size];
	color = WHITE;
	fill = false;
}
void polygon::setfill(bool _fill)
{
	fill = _fill;
}
void polygon::setcolor(int _color)
{
	color = _color;
}
void polygon::draw()
{

	int a2, b2, c1, d1, e1, f1, g1, h1, i1, j1, k1, l1, m1, n1, o1;
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, a2, b2);

	p[0].x = a2;
	p[1].x = b2;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, c1, d1);

	p[2].x = c1;
	p[3].x = d1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, e1, f1);

	p[4].x = e1;
	p[5].x = f1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, g1, h1);

	p[6].x = g1;
	p[7].x = h1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, i1, j1);

	p[8].x = i1;
	p[9].x = j1;
	clearmouseclick(WM_LBUTTONDOWN);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, k1, l1);

	p[10].x = k1;
	p[11].x = l1;
	if (p[0].x > 100 && p[2].x > 100 && p[4].x >100 && p[6].x >100 && p[8].x > 100 && p[10].x > 100)
	{
		line(p[0].x, p[1].x, p[2].x, p[3].x);
		//////////////////////////////
		line(p[2].x, p[3].x, p[4].x, p[5].x);
		//////////////////////////////
		line(p[4].x, p[5].x, p[6].x, p[7].x);
		//////////////////////////////
		line(p[6].x, p[7].x, p[8].x, p[9].x);
		//////////////////////////////
		line(p[8].x, p[9].x, p[10].x, p[11].x);
		///////////////////////////////
		line(p[10].x, p[11].x, p[0].x, p[1].x);
		clearmouseclick(WM_LBUTTONDOWN);
	}
}



void panel()
{
	initwindow(1000, 654, "***************************Hello Paint***************************");

	setcolor(WHITE);
	rectangle(0, 0, 100, 653);
	////////////colors
	rectangle(0, 0, 50, 50);
	setfillstyle(SOLID_FILL, GREEN);
	circle(25, 25, 25);
	floodfill(26, 24, WHITE);

	rectangle(0, 51, 50, 100);
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	circle(25, 75, 25);
	floodfill(26, 74, WHITE);

	rectangle(0, 101, 50, 150);
	setfillstyle(SOLID_FILL, BLUE);
	circle(25, 125, 25);
	floodfill(26, 124, WHITE);


	rectangle(0, 151, 50, 200);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	circle(25, 175, 25);
	floodfill(26, 174, WHITE);

	rectangle(0, 201, 50, 250);
	setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	circle(25, 225, 25);
	floodfill(26, 224, WHITE);


	rectangle(51, 0, 100, 50);
	setfillstyle(SOLID_FILL, CYAN);
	circle(75, 25, 25);
	floodfill(76, 24, WHITE);


	rectangle(51, 51, 100, 100);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	circle(75, 75, 25);
	floodfill(76, 74, WHITE);


	rectangle(51, 101, 100, 150);
	setfillstyle(SOLID_FILL, RED);
	circle(75, 125, 25);
	floodfill(76, 124, WHITE);


	rectangle(51, 151, 100, 200);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(75, 175, 25);
	floodfill(76, 174, WHITE);


	rectangle(51, 201, 100, 250);
	setfillstyle(SOLID_FILL, MAGENTA);
	circle(75, 225, 25);
	floodfill(76, 224, WHITE);



	///////////////////////////
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(101, 0, 999, 650);
	floodfill(102, 649, DARKGRAY);
	//////////////

	//rectangle for shapes
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(5, 255, 95, 500);
	floodfill(6, 499, WHITE);

	setcolor(0);
	////////////////////////
	line(10, 260, 35, 300);

	/////////////////////////
	circle(66, 286, 25);

	///////////////////////////
	////square
	rectangle(11, 319, 45, 353);
	//rec/////////////////
	rectangle(12, 367, 85, 393);
	////////////
	rectangle(0, 0, 100, 248);
	//trinale
	line(70, 319, 53, 355);
	line(53, 355, 86, 355);
	line(86, 355, 70, 319);
	////polygon
	line(15, 433, 35, 413);
	line(35, 413, 62, 413);
	line(62, 413, 82, 433);
	line(82, 433, 62, 452);
	line(62, 452, 35, 452);
	line(35, 452, 15, 433);
	//rectangle for text
	

	// **MENU OF FUNCTIONS**
	///////////////////////////////
	readimagefile("paintbuc.jpg", 5, 505, 45, 545);
	//////////////////////////////////////////////
	readimagefile("ERASE.jpg", 53, 505, 94, 545);
	////////////////////////////////////////////
	readimagefile("undo.jpg", 5, 550, 45, 590);
	////////////////////////////////////////////
	readimagefile("redo.jpg", 53, 550, 94, 590);
	////////////////////////////////////////////
	readimagefile("pencil.jpg", 5, 595, 45, 635);
	//////////////////////////////////////////////
	readimagefile("delete.jpg", 53, 595, 94, 635);
	////////////////////////////////////////////
	readimagefile("save.jpg", 8,468 ,35,490 );
	///////////////////////////////////////////
	readimagefile("fileopen.jpg", 37, 468, 65, 490);
	///////////////////////////////////////////
	readimagefile("text.jpg", 67, 468, 92, 490);


}

///////////////*************************filling*************************//////////////

void save()
{
	writeimagefile("paint.bmp", 103, 0, 989, 780, 0, (HWND)0);

}

void open()
{
	readimagefile("paint.bmp", 103, 0, 989, 780);

}

//void save()
//{
//	ofstream of;
//	of.open("save.txt");
//	for (int i = 0; i <780 ; i++)
//	{
//		for (int j = 103; j <898 ; j++)
//		{
//			of << getpixel(j, i) << " ";
//		}
//	}
//	of.close();
//}
//void open()
//{
//	int col=0;
//	ifstream in;
//	
//	in.open("save.txt");
//	for (int i = 0; i <780; i++)
//	{
//		for (int j = 103; j <898; j++)
//		{
//			if (!in)
//			{
//				exit(1);
//			}
//			in >> col;
//			putpixel(j, i, col);
//		}
//	}
//	in.close();
//}


int main()
{


	panel();              ////// panel

	setcolor(BLACK);

	shape *allshapes;     /////pointer of abstract base class
	point pnt[50];        ///// for saving the coordinates of pencil,earser
	point c;              ///// flood fill quardinates

	int mousx;             ///// FOR WHILE LOOP
	int mousy;            /////
	int x1;               ///// for colors
	int x2;               /////
	int y1;               /////
	int y2;                ////
	

	while (1)
	{
		clearmouseclick(WM_LBUTTONDOWN);
		while (!ismouseclick(WM_LBUTTONDOWN));
		getmouseclick(WM_LBUTTONDOWN, mousx, mousy);
		setcolor(BLACK);
		/////*****************************************rectangle*************************************//

		if (mousx >= 11 && mousx <= 86 && mousy >= 366 && mousy <= 393)
		{
			cout << "\nRectangle selected\n";

			clearmouseclick(WM_LBUTTONDOWN);
			allshapes = new Rect;
			allshapes->draw();
			clearmouseclick(WM_LBUTTONDOWN);
		}

		//***************************square************************************************//

		else if (mousx >= 11 && mousx <= 45 && mousy >= 318 && mousy <= 353)
		{
			cout << "\nSquare\n";

			clearmouseclick(WM_LBUTTONDOWN);
			allshapes = new square;
			allshapes->draw();
			clearmouseclick(WM_LBUTTONDOWN);
		}

		/////************************************************line************************************************//
		else if (mousx >= 7 && mousx <= 36 && mousy >= 258 && mousy <= 299)
		{
			cout << "\nLine\n";
			clearmouseclick(WM_LBUTTONDOWN);
			allshapes = new Line;
			allshapes->draw();
			clearmouseclick(WM_LBUTTONDOWN);
		}

		/////************************************************circle************************************************//

		else if (mousx >= 37 && mousx <= 88 && mousy >= 258 && mousy <= 304)
		{
			cout << "\nCirclE\n";
			clearmouseclick(WM_LBUTTONDOWN);
			allshapes = new Circle;
			allshapes->draw();
			clearmouseclick(WM_LBUTTONDOWN);
		}

		/////************************************************triangle************************************************//

		else if (mousx >= 54 && mousx <= 87 && mousy >= 328 && mousy <= 354)
		{
			cout << "\ntriangle\n";
			clearmouseclick(WM_LBUTTONDOWN);
			allshapes = new triangle;
			//sets points and number of points
			allshapes->draw();//calls draw of triangle
			clearmouseclick(WM_LBUTTONDOWN);
		}

		/////************************************************polygon************************************************//

		else if (mousx >= 13 && mousx <= 81 && mousy >= 411 && mousy <= 450)
		{
			cout << "\npolygon\n";
			clearmouseclick(WM_LBUTTONDOWN);
			allshapes = new polygon;
			allshapes->draw();
			clearmouseclick(WM_LBUTTONDOWN);
		}




		/////**************************(  Bucket   )*************************////


		if (mousx <= 45 && mousx >= 5 && mousy >= 505 && mousy <= 545)//paint
		{
			cout << "\nBucket select\n";
			clearmouseclick(WM_LBUTTONDOWN);
			while (!ismouseclick(WM_LBUTTONDOWN));

			/////**************************(  Colours   )*************************////


			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			{

				if (x1 <= 50 && x1 >= 0 && y1 >= 0 && y1 <= 50)
				{

					cout << "\nGreen selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, GREEN);
					floodfill(c.x, c.y, BLACK);
					cout << "\nGreen filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 47 && x1 >= 2 && y1 >= 52 && y1 <= 93)
				{

					cout << "\nLight Green selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, LIGHTGREEN);
					floodfill(c.x, c.y, BLACK);
					cout << "\nLight Green filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 46 && x1 >= 2 && y1 >= 105 && y1 <= 143)
				{

					cout << "\nBlue selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, BLUE);
					floodfill(c.x, c.y, BLACK);
					cout << "\n Blue filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 47 && x1 >= 2 && y1 >= 152 && y1 <= 194)
				{

					cout << "\nLight Blue selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, LIGHTBLUE);
					floodfill(c.x, c.y, BLACK);
					cout << "\nLight Blue filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 46 && x1 >= 2 && y1 >= 204 && y1 <= 243)
				{

					cout << "\nLight Magenta selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, LIGHTMAGENTA);
					floodfill(c.x, c.y, BLACK);
					cout << "\nLight Magenta filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 95 && x1 >= 54 && y1 >= 2 && y1 <= 42)
				{

					cout << "\nCyan selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, CYAN);
					floodfill(c.x, c.y, BLACK);
					cout << "\nCyan filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 96 && x1 >= 53 && y1 >= 53 && y1 <= 93)
				{

					cout << "\nLight Cyan selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, LIGHTCYAN);
					floodfill(c.x, c.y, BLACK);
					cout << "\nLight Cyan filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 98 && x1 >= 53 && y1 >= 103 && y1 <= 143)
				{

					cout << "\nRed selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, RED);
					if (c.x > 100)
					{


						floodfill(c.x, c.y, BLACK);
					}
					cout << "\nRed filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 96 && x1 >= 54 && y1 >= 154 && y1 <= 191)
				{

					cout << "\nYellow selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, YELLOW);
					floodfill(c.x, c.y, BLACK);
					cout << "\nYellow filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}
				else if (x1 <= 94 && x1 >= 54 && y1 >= 202 && y1 <= 243)
				{

					cout << "\nMagenta selected\n";
					clearmouseclick(WM_LBUTTONDOWN);
					while (!ismouseclick(WM_LBUTTONDOWN));
					getmouseclick(WM_LBUTTONDOWN, c.x, c.y);
					setfillstyle(SOLID_FILL, MAGENTA);
					floodfill(c.x, c.y, BLACK);
					cout << "\nMagenta filled\n";
					clearmouseclick(WM_LBUTTONDOWN);

				}

			}
		}

		/////**************************(  Pencil   )*************************////

		if (mousx >= 5 && mousx <= 45 && mousy >= 594 && mousy <= 635)
		{
			cout << "\nPencil\n";
			//press left button to exit pencil
			while (!ismouseclick(WM_LBUTTONDOWN))
			{

				while (!ismouseclick(WM_MOUSEMOVE))
				{
				}
				getmouseclick(WM_MOUSEMOVE, x1, y1);
				pnt[0].x = x1;
				pnt[0].y = y1;
				while (!ismouseclick(WM_MOUSEMOVE))
				{
				}
				getmouseclick(WM_MOUSEMOVE, x2, y2);
				cout << x2 << ",";
				cout << y2 << endl;
				pnt[1].x = x2;
				pnt[1].y = y2;
				setcolor(BLACK);
				if (pnt[0].x > 100)
				{
					setfillstyle(SOLID_FILL, BLACK);
					circle(pnt[0].x, pnt[0].y, 3);
					floodfill(pnt[0].x, pnt[0].y, BLACK);
				}

			}

		}

		/////**************************(  Eraser   )*************************////

		if (mousx >= 52 && mousx <= 95 && mousy >= 504 && mousy <= 546)
		{
			cout << "\nEraser\n";
			//press left button to exit EARSER
			while (!ismouseclick(WM_LBUTTONDOWN))
			{

				while (!ismouseclick(WM_MOUSEMOVE))
				{
				}
				getmouseclick(WM_MOUSEMOVE, x1, y1);
				pnt[0].x = x1;
				pnt[0].y = y1;
				while (!ismouseclick(WM_MOUSEMOVE))
				{
				}
				getmouseclick(WM_MOUSEMOVE, x2, y2);
				cout << x2 << ",";
				cout << y2 << endl;
				pnt[1].x = x2;
				pnt[1].y = y2;
				setcolor(WHITE);
				if (pnt[0].x > 114)
				{
					setfillstyle(SOLID_FILL, WHITE);
					circle(pnt[0].x, pnt[0].y, 15);
					floodfill(pnt[0].x, pnt[0].y, WHITE);
				}

			}

		}
		////////******************************TEXT*******************************//////
		if (mousx >= 67 && mousx <= 92 && mousy >= 468 && mousy <= 490)
		{
			cout << "\nTEXT\n";
			setcolor(WHITE);
			char msg[100];
			cin.getline(msg, 100);
			while (!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			settextstyle(10, 0, 1);
			outtextxy(x1, y1, msg);
			clearmouseclick(WM_LBUTTONDOWN);

		}
		
		////**********filing*************///////
		if (mousx >= 8 && mousx <= 35 && mousy >= 468 && mousy <= 490)
		{
			//cout << "save";
			save();

		}
		if (mousx >= 37 && mousx <= 62 && mousy >= 468 && mousy <= 490)
		{
			//cout << "open";
			open();
		}

		/////*******************undo******************///
		if (mousx >= 4 && mousx <= 45 && mousy >= 549 && mousy <= 590)
		{
			cout << "undo";
			open();

		}
		/////*******************redo******************///
		if (mousx >= 53 && mousx <= 94 && mousy >= 550 && mousy <= 589)
		{
			cout << "redo";
			open();
		}
	}


	system("pause");
}


