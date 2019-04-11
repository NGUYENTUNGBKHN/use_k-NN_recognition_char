#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
//using namespace std;

const int MIN_CONTOUR_AREA = 100;
const int RESIZED_IMAGE_WIDTH = 20;
const int RESIZED_IMAGE_HEIGHT = 30;

class char_hust {
	public:
		char object;
		int x;
		int y;
		int height;
		int width;
		bool detect;
};

class ContourWithData {
public:
	std::vector<Point> ptContour;
	Rect boundingRect;
	float fltArea;
	bool checkIfContourIsValid()
	{
		if (fltArea < MIN_CONTOUR_AREA)
		{
			return false;
		}
		{
			return true;
		}

	}

	static bool sortByBoundingRectXPosition(const ContourWithData& cwdLeft, const ContourWithData& cwdRight)
	{
		return(cwdLeft.boundingRect.x < cwdRight.boundingRect.x);
	}
};
