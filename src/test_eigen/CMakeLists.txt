cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# compile robot_driver_node
add_executable(test_euler_angle test_euler_angle.cc)
target_link_libraries(test_euler_angle PRIVATE ${required_libraries})


add_library(test_euler SHARED test_euler_angle.cc)
target_link_libraries(test_euler PRIVATE ${required_libraries})

install(TARGETS
        test_euler
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)