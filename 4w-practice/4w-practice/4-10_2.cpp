#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

TickMeter tm;//�ð���ü

void mask()
{
	Mat airplain = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat field = imread("field.bmp", IMREAD_COLOR);

	if (airplain.empty() || mask.empty() || field.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	tm.start();//��������
	airplain.copyTo(field, mask);//����ũ�� ��� ������ŭ airplain�� �������� field�� ����
	tm.stop();//��������
	cout << "Image mask time" << tm.getTimeMilli() << "ms." << endl;//getTimeMilli=�и��ʴ����� �޾ƿͼ� ���!

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
