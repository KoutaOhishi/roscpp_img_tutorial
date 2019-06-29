cmake_minimum_required(VERSION 2.8.3)
project(roscpp_img_tutorial)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
  darknet_dnn
)

find_package(OpenCV REQUIRED)
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
