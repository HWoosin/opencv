#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


void trackbar(int pos, void* userdata);

void trackbar(int pos, void* userdata)
{
	Mat img = *(Mat*)userdata;

	img.setTo(pos * 16);//pos �� 16 ���Ѱ� img ��ü �ȼ��� ����, pos*16�� 255����ũ�� ��ȭ
	imshow("image", img);
}

int main(void)
{
	Mat img = Mat::zeros(300, 500, CV_8UC1);

	namedWindow("image");
	createTrackbar("level", "image", 0, 16, trackbar, (void*)&img);//�ּ�0�ִ� 16�ܰ�

	imshow("image", img);
	waitKey(0);
	return 0;

}
