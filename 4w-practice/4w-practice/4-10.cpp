#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


void trackbar(int pos, void* userdata);

void trackbar(int pos, void* userdata)
{
	Mat img = *(Mat*)userdata;

	img.setTo(pos * 16);//pos 에 16 곱한값 img 전체 픽셀값 지정, pos*16이 255보다크면 포화
	imshow("image", img);
}

int main(void)
{
	Mat img = Mat::zeros(300, 500, CV_8UC1);

	namedWindow("image");
	createTrackbar("level", "image", 0, 16, trackbar, (void*)&img);//최소0최대 16단계

	imshow("image", img);
	waitKey(0);
	return 0;

}
