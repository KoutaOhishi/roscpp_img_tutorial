#include "ros/ros.h"
#include "iostream"
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/Image.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/opencv_modules.hpp"
#include "image_transport/image_transport.h"

class EdgeDetector{
    private:
        ros::NodeHandle nh;

        std::string sub_img_name;
        std::string pub_img_name;

        ros::Subscriber sub_img;
        image_transport::Publisher pub_img;//image型のtopicのpublisherを宣言

    public:
        EdgeDetector(){
            this->sub_img_name = "/camera/rgb/image_raw";
            this->pub_img_name = "/result_image";

            ROS_INFO("sub_img_name:[%s]", this->sub_img_name.c_str());

            this->sub_img = nh.subscribe(this->sub_img_name, 100, &EdgeDetector::sub_img_CB, this);

            image_transport::ImageTransport it(this->nh);
            this->pub_img = it.advertise(this->pub_img_name, 1);
        }

        void sub_img_CB(const sensor_msgs::ImageConstPtr& msg)
        {
            //ROSのImage型からOpenCVで扱える形式に変換
            cv::Mat image = cv_bridge::toCvShare(msg, "bgr8")->image;

            /* 画像処理開始　*/
            cv::Mat gray_img;

            // グレースケールに変換する
            cv::cvtColor(image, gray_img, CV_RGB2GRAY);
            cv::Mat canny_img;
            cv::Canny(gray_img, canny_img, 50, 200);

            cv::imshow("result", canny_img);
            cv::waitKey(1);

            /* 画像処理終了 */

            //OpenCVの形式からROSのImage型に変換
            sensor_msgs::ImagePtr img_msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", canny_img).toImageMsg();

            //publish
            this->pub_img.publish(img_msg);
        }
};


int main(int argc, char** argv){
    ros::init(argc, argv, "edge_detector");
    ROS_INFO("### START [edge_detector] ###");

    EdgeDetector i;

    ros::spin();
}
