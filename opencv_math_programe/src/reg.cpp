#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace cv;

Scalar Mired1(0, 100, 100), Mared1(25, 255, 255);
Scalar Mired2(170, 100, 100), Mared2(180, 255, 255);


Scalar Migre(35, 50, 50), Magre(85, 255, 255);
Scalar MiQin(85, 50, 50), MaQin(170, 255, 255);

int way = 4;

//为了处理像1这种剑直部诗人的数字
int maxWidth = 500, maxHeight = 0;

int lastNumber = -1;
double last = -1;
//数字模板
static vector<Mat> templates;
string dir = "../template/digit_";
void initTmp() 
{
    if (!templates.empty()) return; // 防止重复加载
    for (int i = 0; i < 10; i ++) {
        string filename = dir + to_string(i) + ".png";
        Mat templ = imread(filename, 0);
        //cout << "tp_size: " << templ.size() << endl;
        threshold(templ, templ, 127, 255, THRESH_BINARY_INV);
        vector<vector<Point>>tmprfx;
        findContours(templ,tmprfx, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        Rect tmp = boundingRect(tmprfx[0]);
        templ = templ(tmp);
        //imshow("debug",templ);
        templates.push_back(templ);
    }
    cout << "load 完成" << endl;
}

int calRang(Scalar& meanCor)
{
    Mat colorMat(1, 1, CV_8UC3, meanCor);
    cvtColor(colorMat,colorMat,COLOR_BGR2HSV);
    for(int i = 0; i < 3; i ++)cout << meanCor[i] << ' ';
    cout << endl;
    Mat mask;
    inRange(colorMat, Mired1, Mared1, mask);
    if(mask.at<uchar>(0, 0) == 255)return 3;
    inRange(colorMat, Mired2, Mared2, mask);
    if(mask.at<uchar>(0, 0) == 255)return 3;
    inRange(colorMat, Migre, Magre, mask);
    if(mask.at<uchar>(0,0) == 255)return 2;
    inRange(colorMat, MiQin, MaQin, mask);
    if(mask.at<uchar>(0,0) == 255)return 1;

    return 3;
}

int color(Mat orig, Mat bin)
{
    Mat kernel = getStructuringElement(MORPH_RECT, Size(10, 10));
    dilate(bin, bin, kernel);
    vector<vector<Point>>prfix_ps;
    findContours(bin, prfix_ps, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    double maxAre = -1;
    int idx = -1;
    for(int i = 0; i < prfix_ps.size(); i ++)
    {
        double area = contourArea(prfix_ps[i]);
        if( area > maxAre)
        {
            idx = i;
            maxAre = area;
        }
    }
    Rect roi = boundingRect(prfix_ps[idx]);
    orig = orig(roi);
    bin = bin(roi);
    //imshow("bin",bin);
    GaussianBlur(orig,orig,Size(21,21),0,0);
    Mat ker_org = getStructuringElement(MORPH_RECT, Size(45,45));
    dilate(orig,orig,ker_org);
    //imshow("colorDebug", orig);
    //Mat mask = Mat::zeros(orig.size(), CV_8U);
    //drawContours(mask, prfix_ps, idx, Scalar(255), FILLED);
    //imshow("mask",mask);
    Scalar meanCor = mean(orig,bin);
    return calRang(meanCor);
}

int digit(Mat orig)
{
    cout << orig.cols << ' ' << orig.rows << endl;
    Mat ker_dil = getStructuringElement(MORPH_RECT, Size(80,80));
    Mat ker_ero = getStructuringElement(MORPH_RECT, Size(30,30));
    dilate(orig, orig, ker_dil);
    erode(orig,orig,ker_ero);
    imshow("dil",orig);
    vector<vector<Point>>trg;
    vector<Vec4i>his;
    findContours(orig,trg,his,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    double maxAre = -1;
    int tmpidx = -1;
    for(int i = 0; i < trg.size(); i ++)
    {
        if(maxAre < contourArea(trg[i]))
        {
            maxAre = contourArea(trg[i]);
            tmpidx = i;
        }
    }
    Rect tmp;
    if( tmpidx != -1)
    tmp = boundingRect(trg[tmpidx]);
    else 
        cout << "发生错误!error!" << endl;
    Mat roi = orig(tmp);
    if(roi.cols < maxWidth || roi.rows < maxHeight)
    {
    int top = (maxHeight - roi.rows) / 2;
    int bottom = maxHeight - roi.rows - top;
    int left = (maxWidth - roi.cols) / 2;
    int right = maxWidth - roi.cols - left;
    if(top < 0)top = 0;
    if(bottom < 0)bottom = 0;
    if(left < 0)left = 0;
    if(right < 0)right = 0;

        copyMakeBorder(roi,roi,top,bottom,left,right,BORDER_CONSTANT, Scalar(0,0,0));
    }
    maxHeight = roi.rows, maxWidth = roi.cols;
    //cout << "rect_size: " << tmp.size() << endl;
    //cout << "roi_size: " << roi.size() << endl;
    double score = -1;
    int idx = -1;
    double maxScore = -1, minScore = -1;
    for (int i = 0; i < templates.size(); i++) {
        if (roi.empty() || templates[i].empty()) continue;
        Mat resizedRoi;
        resize(roi , resizedRoi, templates[i].size());
        //cout << "temp_size: " << templates[i].size() << endl;
        Mat res;
        matchTemplate(resizedRoi, templates[i], res, way);
        //cout << "min: " << minScore << " max: " << maxScore << endl;
        minMaxLoc(res, &minScore, &maxScore);
        if (score < maxScore) {
            score = maxScore;
            idx = i;
        }
    }
    if (idx != -1 && last < score)
    {
        last = score;
        lastNumber = idx;
        cout << "识别的数字是1：" << idx << endl;
        return idx;
    }
    else if(idx == - 1)return 1;
    else  
    {
        last = score;
        lastNumber = idx;
        cout << "识别的数字是2: " << lastNumber << endl;
        return lastNumber;
    }
}
