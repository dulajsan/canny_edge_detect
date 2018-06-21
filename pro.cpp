#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;


int main(int argc,char** argv){
	Mat img_1,img_2,img_1_gray,img_2_gray;

        // -- load the images
        img_1 = imread("Fish/img/0001.jpg");
        img_2 = imread("Fish/img/0199.jpg");

	// -- if image not found then show error message
        if((! img_1.data) || (! img_2.data)){
                std::cout << "image not found" << std::endl;
                return -1;
        }

	// -- convert to gray scale
	cvtColor(img_1,img_1_gray,CV_BGR2GRAY);
	cvtColor(img_2,img_2_gray,CV_BGR2GRAY);

	// -- blur image with 3*3 filter and reduce noise
	blur(img_1_gray,img_1_gray,Size(3,3));
	blur(img_2_gray,img_2_gray,Size(3,3));
	

}
