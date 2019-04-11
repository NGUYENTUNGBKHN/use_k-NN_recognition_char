/*include */
#include "NTT_video.h"

using namespace cv;
using namespace std;
using namespace ntt_video;

camera::camera()
{
}
System::Drawing::Bitmap^ camera::Show(cv::Mat & colorImage)
{
	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ bitmap;
	switch (colorImage.type())
	{
	case CV_8UC3:
		bitmap = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		break;
	case CV_8UC1:
		bitmap = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
		break;
	default:
		break;
	}
	return bitmap;
}