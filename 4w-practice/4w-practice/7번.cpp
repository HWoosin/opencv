#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
Mat imgs;
Mat imgs2;
Point click1;
Point click2;
Point squ;
Point sqd;

void dog()
{
	imgs = imread("dog.bmp", IMREAD_COLOR);
}

void mouse_draws(int event, int x, int y, int flags, void*);

void mouse_draws(int event, int x, int y, int flags, void*)
{
	switch (event) {
	case EVENT_LBUTTONDOWN:
		click1 = Point(x, y);
		squ = Point(x+4, y+4);
		cout << "상단지점" <<x << y << endl;
		break;
		
	case EVENT_RBUTTONDOWN:
		click2 = Point(x, y);
		sqd = Point(x -4, y-4);
		cout << "하단지점" << x << y << endl;

		rectangle(imgs, click1, click2, Scalar(0, 0, 255),5);
		imgs2=imgs(Rect(squ, sqd));
		imgs2 = ~imgs2;
		putText(imgs, "dog", Point(x-60,y+30), FONT_HERSHEY_SIMPLEX, 1, Scalar(236, 215, 144),3);

		imshow("img", imgs);
		break;
	default:
		break;

	}
	
}


int main()
{

	dog();
	namedWindow("img");
	setMouseCallback("img", mouse_draws);
	
	imshow("img", imgs);
	waitKey(0);
}
