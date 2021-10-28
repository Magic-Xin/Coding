#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

void Binarization(cv::Mat _srcImage) {
    cv::Mat srcImage = _srcImage;
    imshow("srcImg", srcImage);
    //灰度转换
    cv::Mat srcGray;
    cvtColor(srcImage, srcGray, CV_RGB2GRAY);
    imshow("grayImg", srcGray);
    //初始化相关变量
    cv::Mat dstTempImage1, dstTempImage2, dstImage;
    const int maxVal = 255;		//预设最大值
    int low_threshold = 90;		//较小的阈值量
    int high_threshold = 190;	//较大的阈值量
    //双阈值化过程
    //小阈值对源灰度图像进行二进制阈值化操作
    cv::threshold(srcGray, dstTempImage1, low_threshold, maxVal, cv::THRESH_BINARY);
    //大阈值对源灰度图像进行反二进制阈值化操作
    cv::threshold(srcGray, dstTempImage2, high_threshold, maxVal, cv::THRESH_BINARY_INV);
    //矩阵"与运算"得到二值化结果
    cv::bitwise_and(dstTempImage1, dstTempImage2, dstImage); //对像素加和
    imshow("dual-thresholdImg", dstImage);
    cv::waitKey(0);	//窗口保持等待
    cv::destroyAllWindows();
    return;
}

void ErodeDilate(cv::Mat _srcImage) {
    cv::Mat srcImage, erodeImg, dilateImg;
    srcImage = _srcImage;

    imshow("srcImg", srcImage);
    //获取自定义核
    cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    //进行腐蚀操作
    cv::erode(srcImage, erodeImg, element);
    //显示效果图
    cv::imshow("erodeImg", erodeImg);
    //进行膨胀操作
    cv::dilate(srcImage, dilateImg, element);
    //显示效果图
    cv::imshow("dilateImg", dilateImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return;
}

void Morphology(cv::Mat _srcImage) {
    cv::Mat srcImage, openImg, closeImg;
    srcImage = _srcImage;

    imshow("srcImg", srcImage);
    //获取自定义核
    cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10));
    //进行开运算操作,先腐蚀后膨胀
    cv::erode(srcImage, openImg, element);
    cv::dilate(openImg, openImg, element);
    //cv::morphologyEx(srcImage, openImg, cv::MORPH_OPEN, element);
    //显示效果图
    cv::imshow("openImg", openImg);

    //进行闭运算操作，先膨胀后腐蚀
    cv::dilate(srcImage, closeImg, element);
    cv::erode(closeImg, closeImg, element);
    //cv::morphologyEx(srcImage, closeImg, cv::MORPH_CLOSE, element);
    //显示效果图
    cv::imshow("closeImg", closeImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return;
}

int main() {
    //读取源图像并检查图像是否读取成功
    std::string filename = "../img.jpg";
    cv::Mat srcImage = cv::imread(filename);
    if (!srcImage.data)
    {
        std::cout << "读取图片错误，请重新输入正确路径！" << std::endl;
        system("pause");
        return -1;
    }

    //Binarization(srcImage);
    //ErodeDilate(srcImage);
    Morphology(srcImage);
    return 0;
}
