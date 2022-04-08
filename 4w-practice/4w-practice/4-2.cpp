#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void video()
{
	VideoCapture cap("video_stopwatch.avi"); //���� �ҷ�����

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return;
	}

	cout << "������ ����: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "������ ����: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "������ ��: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

	double fps = cap.get(CAP_PROP_FPS);
	cout << "�ʴ� ������ ��: " << fps << endl;

	int delay = cvRound(1000 / fps);//�� �����ӻ��� �ð� ����

	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27) // 27�� ESC Ű
			break;
	}

	destroyAllWindows();
}


int main()
{
	video();
	
}
