#include <opencv2/opencv.hpp>
#include "include/reg.hpp"
#include <vector>

using namespace std;
using namespace cv;


int Thres_val = 100;

int main(){
    VideoCapture video = VideoCapture("../test4.avi");
    initTmp();
    int last = 0;
    while(1){
        Mat frame;
        video.read(frame);
        imshow("frame",frame);
        GaussianBlur(frame,frame,Size(5,5),0,0);
        Mat gre,binary;
        cvtColor(frame,gre,6);
        threshold(gre, binary, Thres_val, 255, THRESH_BINARY);
        imshow("bin",binary);
        waitKey(1);
        //数字
        int d = digit(binary);
        //颜色
        int c = color(frame,binary);
    }
    return 0;
}
