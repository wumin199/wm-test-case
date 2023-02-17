cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# compile robot_driver_node
add_executable(test_fmt test_fmt.cc)
target_link_libraries(test_fmt PRIVATE ${required_libraries})