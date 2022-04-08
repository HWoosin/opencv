#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void mask()
{
	Mat airplain = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat field = imread("field.bmp", IMREAD_COLOR);

	if (airplain.empty() || mask.empty() || field.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	airplain.copyTo(field, mask);//����ũ�� ��� ������ŭ airplain�� �������� field�� ����

	imshow("airplain", airplain);
	imshow("field", field);
	imshow("mask", mask);

	waitKey(0);
	destroyAllWindows();
}

int main()
{
	mask();
}
