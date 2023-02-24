cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

add_executable(test_basic test_basic.cc)
target_link_libraries(test_basic PRIVATE ${required_libraries})


add_executable(test_glog test_glog.cc)
target_link_libraries(test_glog PRIVATE ${required_libraries})
