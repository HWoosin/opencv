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
	case EVENT_LBUTTONDOWN://��Ŭ���ɶ�
		ptold = Point(x, y);
		cout << "L_BUTTONDOWN" << x << y << endl;
		break;
	case EVENT_LBUTTONUP://��Ŭ�� ����
		cout << "L_BUTTONDOWN" << x << y << endl;
		break;

	case EVENT_MOUSEMOVE://�����϶�
		if (flags & EVENT_FLAG_LBUTTON)//�������·�
		{
			line(img, ptold, Point(x, y), Scalar(0, 255, 255), 2);//���� �׸���
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
	setMouseCallback("img", mouse_draw);//���콺 �̺�Ʈó��

	imshow("img", img);
	waitKey(0);

	return 0;
}

