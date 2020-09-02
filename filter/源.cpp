#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void f1(const Mat &image) {
	int row = image.rows;
	int col = image.cols;
	Mat img;
	cvtColor(image, img, COLOR_BGR2HSV);
	Mat sp[3];
	split(img, sp);
	equalizeHist(sp[2], sp[2]);
	vector<Mat> mv;
	for (size_t i = 0; i < 3; i++)
	{
		mv.push_back(sp[i]);
	}
	merge(mv, img);
	Mat mask;
	inRange(img, Scalar(100, 43, 46), Scalar(124, 255, 255), mask);
	Mat sky = imread("sky.jpg");
	Mat res;
	seamlessClone(sky, img, mask, Point(img.size().width/2, img.size().height/2), res, NORMAL_CLONE);
	imshow("1", res);
	waitKey(0);
}

int main() {
	Mat image = imread("1.jpg");
	f1(image);
	return 0;
}