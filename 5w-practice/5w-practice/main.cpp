#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Point click1;
Point click2;
Point c1;
Point c2;
Mat img;
Mat img2;
Mat img3;
Mat img4;
Mat img5;
Mat img6;
TickMeter tm;

void B1()
{
	img = imread("B1.jpg");
	medianBlur(img, img5, 5);
	cvtColor(img5, img6, COLOR_BGR2GRAY);
	resize(img6, img2, Size(800, 800));
	
	
	if (img.empty())
	{
		cerr << "Image load failed!" << endl;
		return;
	}
}
void square(int event, int x, int y, int flags, void*);
void square(int event,int x, int y, int flags, void*)
{
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
			c1 = Point(x + 4, y + 4);
			click1 = Point(x, y);
			break;

	case EVENT_RBUTTONDOWN:
			c2 = Point(x -4, y - 4);
			click2 = Point(x, y);
			rectangle(img2, click1, click2, Scalar(255, 0,0), 5);
			img3 = img2(Rect(c1, c2));
			for (int i = 1; i < img3.rows; i++)
			{
				img4 = img3.row(i);
				img4 = ~img4;
				i += 1;
			}
		
			putText(img2, "Region of interest", Point(x - 60, y + 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(236, 215, 144), 3);
			imshow("img", img2);
			
		
		
		break;
	default:
		break;
	}
}

int main()
{
	tm.start();
	B1();
	
	namedWindow("img");
	setMouseCallback("img", square);

	imshow("img", img2);
	waitKey(0);
	tm.stop();
	cout << "Image mask time::" << cvRound(tm.getTimeMilli()) << "ms." << endl;
	
}
