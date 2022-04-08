#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void video()
{
	VideoCapture cap("video_stopwatch.avi"); //비디오 불러오기

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return;
	}

	cout << "프레임 가로: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "프레임 세로: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "프레임 수: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

	double fps = cap.get(CAP_PROP_FPS);
	cout << "초당 프레임 수: " << fps << endl;

	int delay = cvRound(1000 / fps);//각 프레임사이 시간 간격

	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27) // 27은 ESC 키
			break;
	}

	destroyAllWindows();
}


int main()
{
	video();
	
}
