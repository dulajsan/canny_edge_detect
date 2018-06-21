#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
void cannyEdgeDetect(Mat&,Mat&,Mat&,const char *);

void cannyEdgeDetect(Mat& img,Mat& gray_image,Mat& output,const char * output_img_name){

	Mat blurred,edges,thresholded;
	double lowthreshold;
	double highthreshold;
	int kernel_size=3;

	// --automatic threshold value detection using OTSU
	highthreshold=threshold(gray_image,thresholded,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
	lowthreshold=highthreshold*0.5;

        // -- blur image with 3*3 filter and reduce noise
        blur(gray_image,blurred,Size(3,3));

	// canny detector
	Canny(blurred,edges,lowthreshold,highthreshold,kernel_size);

	output=Scalar::all(0);
	img.copyTo(output,edges);
	imwrite(output_img_name,output);
}

int main(int argc,char** argv){
	Mat img_1,img_2,img_1_gray,img_2_gray,output1,output2;

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

	output1.create(img_1.size(),img_1.type());
	output2.create(img_2.size(),img_2.type());
	cannyEdgeDetect(img_1,img_1_gray,output1,"output2/output3.jpg");
	cannyEdgeDetect(img_2,img_2_gray,output2,"output2/output4.jpg");

}
