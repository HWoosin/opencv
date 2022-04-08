#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

TickMeter tm;//시간객체

void mask()
{
	Mat airplain = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat field = imread("field.bmp", IMREAD_COLOR);

	if (airplain.empty() || mask.empty() || field.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	tm.start();//측정시작
	airplain.copyTo(field, mask);//마스크의 흰색 영역만큼 airplain의 영역값을 field에 복사
	tm.stop();//측정종료
	cout << "Image mask time" << tm.getTimeMilli() << "ms." << endl;//getTimeMilli=밀리초단위로 받아와서 출력!

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
