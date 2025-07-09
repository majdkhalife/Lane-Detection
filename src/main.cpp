#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("images/drone-picture-motorway-m2-facing-260nw-1819823105.webp");
    if (image.empty())
    {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return -1;
    }
    cv::Mat grayMat;
    cv::cvtColor(image, grayMat, cv::COLOR_BGR2GRAY);
    cv::Mat edges;
    cv::Canny(grayMat, edges, 100, 200); // explain hysterisis thresholding
    cv::Mat lines;
    cv::HoughLinesP(edges, lines, 1, CV_PI / 180, 68, 15, 250); // explain parameters
    for (size_t i = 0; i < lines.rows; i++)
    {
        cv::Vec4i line = lines.at<cv::Vec4i>(i);
        cv::line(image, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(0, 255, 0), 2);
    }
    cv::imshow("Detected Lines", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}