#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void Text()
{
	Mat img(500, 1000, CV_8UC3, Scalar(255, 255, 255));

	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));//위치에 폰트
	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 100), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255));
	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 200), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0));
	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 250), FONT_HERSHEY_TRIPLEX, 1, Scalar(255, 0, 0));
	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 300), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255, 0, 0));
	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 350), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(255, 0, 255));
	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 400), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(255, 0, 255));
	putText(img, "Computer Science/201933046/Hwang Woosin", Point(20, 450), FONT_HERSHEY_COMPLEX | FONT_ITALIC, 1, Scalar(255, 0, 0));

	imshow("img", img);
	waitKey();

	destroyAllWindows();
}

int main()
{
	Text();
}
