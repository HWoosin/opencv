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

	airplain.copyTo(field, mask);//마스크의 흰색 영역만큼 airplain의 영역값을 field에 복사

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
