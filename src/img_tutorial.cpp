#include "ros/ros.h"
#include "iostream"
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/Image.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/opencv_modules.hpp"
#include "image_transport/image_transport.h"

#define OPENCV_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))

class Img_subscriber{
    private:
        ros::NodeHandle nh;

        std::string sub_img_name;
        std::string pub_img_name;

        ros::Subscriber sub_img;
        image_transport::Publisher pub_img;//image型のtopicのpublisherを宣言

    public:
        Img_subscriber(){
            this->sub_img_name = "/camera/rgb/image_raw";
            this->pub_img_name = "/feature_extraction_ros/result_image";

            ROS_INFO("sub_img_name:[%s]", this->sub_img_name.c_str());

            this->sub_img = nh.subscribe(this->sub_img_name, 100, &Img_subscriber::sub_img_CB, this);

            image_transport::ImageTransport it(this->nh);
            this->pub_img = it.advertise(this->pub_img_name, 1);
        }

        void sub_img_CB(const sensor_msgs::ImageConstPtr& msg)
        {
            //ROSのImage型からOpenCVで扱える形式に変換
            cv::Mat image = cv_bridge::toCvShare(msg, "bgr8")->image;

            /*
                画像処理
            */

            //OpenCVの形式からROSのImage型に変換
            sensor_msgs::ImagePtr img_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

            //publish
            this->pub_img.publish(img_msg);
        }
};


int main(int argc, char** argv){
    ros::init(argc, argv, "img_subscriber");
    //ROS_INFO("### START [img_subscriber] ###");

    //Img_subscriber i;

    std::cout << "version: " << CV_VERSION << std::endl;


    //ros::spin();
}
