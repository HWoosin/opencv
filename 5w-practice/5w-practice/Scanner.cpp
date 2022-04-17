#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat src;
Mat src2;
Mat src3;
Mat src4;
Mat sharp;
Point2f srcPts[4], dstPts[4];

void Click(int event, int x, int y, int flags, void* userdata);

void Click(int event, int x, int y, int flags, void*)
{
	static int cnt = 0;

	if (event == EVENT_LBUTTONDOWN) {
		if (cnt < 4) {
			srcPts[cnt++] = Point2f(x, y);

			circle(src2, Point(x, y), 5, Scalar(0, 0, 255), -1);
			imshow("src", src2);

			if (cnt == 4) {
				int w = 500, h = 600;

				dstPts[0] = Point2f(0, 0);
				dstPts[1] = Point2f(w-1, 0);
				dstPts[2] = Point2f(w-1 , h-1 );
				dstPts[3] = Point2f(0, h-1 );

				Mat pers = getPerspectiveTransform(srcPts, dstPts);

				warpPerspective(src2, src3, pers, Size(w, h));
				//»þÇÁ´×
				GaussianBlur(src3, sharp, Size(), 6);
				float alpha = 1.f;
				src4 = (1 + alpha) * src3 - alpha * sharp;
				imshow("result", src4);
			}
		}
	}
}

int main()
{
	src = imread("Photo.bmp");
	resize(src, src2, Size(800, 1000));
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("src");
	setMouseCallback("src", Click);

	imshow("src", src2);
	waitKey(0);

	return 0;
}
