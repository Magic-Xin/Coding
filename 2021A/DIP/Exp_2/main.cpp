#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

void Binarization(std::string filename) {
    //【1】读取源图像并检查图像是否读取成功
    cv::Mat srcImage = cv::imread(filename);
    if (!srcImage.data)
    {
        std::cout << "读取图片错误，请重新输入正确路径！" << std::endl;
        system("pause");
        return;
    }
    imshow("srcImg", srcImage);
    //【2】灰度转换
    cv::Mat srcGray;
    cvtColor(srcImage, srcGray, CV_RGB2GRAY);
    imshow("grayImg", srcGray);
    //【3】初始化相关变量
    cv::Mat dstTempImage1, dstTempImage2, dstImage;
    const int maxVal = 255;		//预设最大值
    int low_threshold = 90;		//较小的阈值量
    int high_threshold = 190;	//较大的阈值量
    //【4】双阈值化过程
    //小阈值对源灰度图像进行二进制阈值化操作
    cv::threshold(srcGray, dstTempImage1, low_threshold, maxVal, cv::THRESH_BINARY);
    //大阈值对源灰度图像进行反二进制阈值化操作
    cv::threshold(srcGray, dstTempImage2, high_threshold, maxVal, cv::THRESH_BINARY_INV);
    //矩阵"与运算"得到二值化结果
    cv::bitwise_and(dstTempImage1, dstTempImage2, dstImage); //对像素加和
    imshow("dual-thresholdImg", dstImage);
    cv::waitKey(0);	//窗口保持等待
    return;
}

void ErodeDilate(std::string filename) {
    cv::Mat srcImage, erodeImg, dilateImg; //源图像，输出图像

    //---------【1】读取源图像并检查图像是否读取成功---------
    srcImage = cv::imread(filename);
    if (!srcImage.data)
    {
        std::cout << "读取图片错误，请重新输入正确路径！" << std::endl;
        system("pause");
        return;
    }
    imshow("srcImg", srcImage);
    //---------【2】获取自定义核---------
    cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    //---------【3】进行腐蚀操作---------
    cv::erode(srcImage, erodeImg, element);
    //---------【4】显示效果图---------
    cv::imshow("erodeImg", erodeImg);
    //---------【5】进行膨胀操作---------
    cv::dilate(srcImage, dilateImg, element);
    //---------【6】显示效果图---------
    cv::imshow("dilateImg", dilateImg);
    cv::waitKey(0);
    return;
}

void Morphology(std::string filename) {
    cv::Mat srcImage, openImg, closeImg; //源图像，输出图像
    //---------【1】读取源图像并检查图像是否读取成功---------
    srcImage = cv::imread(filename);
    if (!srcImage.data)
    {
        std::cout << "读取图片错误，请重新输入正确路径！" << std::endl;
        system("pause");
        return ;
    }
    imshow("srcImg", srcImage);
    //---------【2】获取自定义核---------
    cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10));
    //---------【3】进行开运算操作,先腐蚀后膨胀---------
    cv::morphologyEx(srcImage, openImg, cv::MORPH_OPEN, element);
    //---------【4】显示效果图---------
    cv::imshow("openImg", openImg);
    //---------【3】进行闭运算操作，先膨胀后腐蚀---------
    cv::morphologyEx(srcImage, closeImg, cv::MORPH_CLOSE, element);
    //---------【4】显示效果图---------
    cv::imshow("closeImg", closeImg);
    cv::waitKey(0);
    return;
}

int main() {
    Binarization("../img.jpg");
    ErodeDilate("../img.jpg");
    Morphology("../img.jpg");
    return 0;
}
