#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
Point ptold;
void mouse_draw(int event, int x, int y, int flags, void*);

void mouse_draw(int event, int x, int y, int flags, void*)
{

	switch (event) {
	case EVENT_LBUTTONDOWN://왼클릭될때
		ptold = Point(x, y);
		cout << "L_BUTTONDOWN" << x << y << endl;
		break;
	case EVENT_LBUTTONUP://왼클릭 땔때
		cout << "L_BUTTONDOWN" << x << y << endl;
		break;

	case EVENT_MOUSEMOVE://움직일때
		if (flags & EVENT_FLAG_LBUTTON)//눌린상태로
		{
			line(img, ptold, Point(x, y), Scalar(0, 255, 255), 2);//라인 그리기
			imshow("img", img);
			ptold = Point(x, y);
		}
		break;
	default:
		break;

		
	}
}

int main(void)
{

	img = imread("lenna.bmp");


	if (img.empty())
	{
		cerr << "image load failed" << endl;
		return  -1;
	}

	namedWindow("img");
	setMouseCallback("img", mouse_draw);//마우스 이벤트처리

	imshow("img", img);
	waitKey(0);

	return 0;
}

