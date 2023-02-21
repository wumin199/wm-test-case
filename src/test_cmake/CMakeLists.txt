#message(${CMAKE_SOURCE_DIR})

###############################################
# test folder
###############################################
message("-------------------")
message("")
message("CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")  # root path of this package
message("CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}") # set in cmake
message("")
message("-------------------")


###############################################
# test
###############################################

if (WIN32)
    file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/s7/win64/snap7.dll 3rdparty/s7/win64/snap7.lib DESTINATION ${CMAKE_BINARY_DIR}/lib)
else ()
    file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/s7/x86_64_linux/libsnap7.so DESTINATION ${CMAKE_BINARY_DIR}/lib)
endif ()

if (WIN32)
    install(FILES
            ${CMAKE_SOURCE_DIR}/3rdparty/s7/win64/snap7.dll
            ${CMAKE_SOURCE_DIR}/3rdparty/s7/win64/snap7.lib
            DESTINATION lib
            )
else ()
    install(FILES
            ${CMAKE_SOURCE_DIR}/3rdparty/s7/x86_64_linux/libsnap7.so
            ${CMAKE_SOURCE_DIR}/3rdparty/s7/win64/snap7.dll
            ${CMAKE_SOURCE_DIR}/3rdparty/s7/win64/snap7.lib
            DESTINATION lib
            )
endif ()