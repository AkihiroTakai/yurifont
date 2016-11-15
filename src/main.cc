#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <stdio.h>

bool is_black(cv::Mat *img, int x, int y);

int main(int argc, char **argv){
	
	unsigned char result = 0, mask = 1;
	int count = 7;

	cv::Mat src_img = cv::imread(argv[1]);
	
	for(int y = 0;y < 16;y++) {
		for(int x = 0;x < 8;x++) {
			if(is_black(&src_img, x, y)){
				result |= (mask << count);
			}
			count--;
		}
		printf("0x%02x, ", result);
		count = 7;
		result = 0;
	}

	printf("\n");

	return 0;
}

bool is_black(cv::Mat *img, int x, int y) {
	if(img->at<cv::Vec3b>(y, x)[0] < 255)
		return true;
	else
		return false;
}
