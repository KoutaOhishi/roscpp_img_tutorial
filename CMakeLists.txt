cmake_minimum_required(VERSION 2.8.3)
project(roscpp_img_tutorial)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
  #darknet_dnn
)

catkin_package()

find_package(OpenCV 3.4 REQUIRED 
   NO_MODULE
   PATHS /usr/local
   NO_DEFAULT_PATH
)


include_directories(
  include
  SYSTEM
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_executable(img_tutorial src/img_tutorial.cpp)
target_link_libraries(img_tutorial ${OpenCV_LIBRARIES} ${catkin_LIBRARIES})
#add_executable(edge src/edge.cpp)
#target_link_libraries(edge ${catkin_LIBRARIES} ${OpenCV_LIBS})
#add_executable(goturn src/goturn.cpp)
#target_link_libraries(goturn ${catkin_LIBRARIES} ${OpenCV_LIBS})
#add_executable(ARmarker_detecter src/ARmarker_detecter.cpp)
#target_link_libraries(ARmarker_detecter ${catkin_LIBRARIES} ${OpenCV_LIBS})
