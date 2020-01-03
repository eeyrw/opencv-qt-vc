#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;

int main(int argc,char **argv)
{
    VideoCapture capture("D:/opencv/sources/doc/js_tutorials/js_assets/cup.mp4");

    while (true)

    {

        Mat src, src_gray;
        Mat dst, detected_edges;
        capture >> src;
        cvtColor( src, src_gray, COLOR_BGR2GRAY );
        blur( src_gray, detected_edges, Size(3,3) );

        Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*50, kernel_size );

        dst = Scalar::all(0);

        src.copyTo( dst, detected_edges);

        imshow("读取视频", dst);

        waitKey(30);	//延时30

    }

    Mat src=imread("C:/Users/YRW/Desktop/pytorch_en/IM_62.jpg");
    imshow("test",src);
    waitKey(0);
    return 0;
}
