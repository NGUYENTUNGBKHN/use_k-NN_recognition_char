#pragma once

#ifndef NTT_VIDEO_H_
#define NTT_VIDEO_H_
/*include */
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace System::Runtime::InteropServices;

namespace ntt_video
{
	class camera
	{
	public:
		camera();
		System::Drawing::Bitmap^ Show(Mat & colorImage);
	};
}



#endif //  






