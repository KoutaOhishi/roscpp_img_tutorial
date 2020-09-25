cmake_minimum_required(VERSION 2.8.3)
project(roscpp_img_tutorial)

add_compile_options(-std=c++11)

string(REPLACE "/opt/ros/kinetic/lib/libopencv_calib3d3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_core3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_features2d3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_flann3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_highgui3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_imgcodecs3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_imgproc3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_ml3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_objdetect3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_photo3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_shape3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_stitching3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_superres3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_video3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_videoio3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_videostab3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_viz3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_aruco3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_bgsegm3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_bioinspired3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_ccalib3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_cvv3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_datasets3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_dpm3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_face3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_fuzzy3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_hdf3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_line_descriptor3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_optflow3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_phase_unwrapping3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_plot3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_reg3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_rgbd3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_saliency3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_stereo3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_structured_light3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_surface_matching3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_text3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_xfeatures2d3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_ximgproc3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_xobjdetect3.so.3.2.0;/opt/ros/kinetic/lib/libopencv_xphoto3.so.3.2.0;" "" catkin_LIBRARIES "${catkin_LIBRARIES}")

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
  #darknet_dnn
)

find_package(OpenCV 3.4.2 REQUIRED)
catkin_package()


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(img_tutorial src/img_tutorial.cpp)
target_link_libraries(img_tutorial ${catkin_LIBRARIES} ${OpenCV_LIBS})
#add_executable(edge src/edge.cpp)
#target_link_libraries(edge ${catkin_LIBRARIES} ${OpenCV_LIBS})
#add_executable(goturn src/goturn.cpp)
#target_link_libraries(goturn ${catkin_LIBRARIES} ${OpenCV_LIBS})
#add_executable(ARmarker_detecter src/ARmarker_detecter.cpp)
#target_link_libraries(ARmarker_detecter ${catkin_LIBRARIES} ${OpenCV_LIBS})
