if (WIN32)
    file(COPY 3rdparty/s7/win64/snap7.dll 3rdparty/s7/win64/snap7.lib DESTINATION ${CMAKE_BINARY_DIR}/lib)
else()
    file(COPY 3rdparty/s7/x86_64_linux/libsnap7.so DESTINATION ${CMAKE_BINARY_DIR}/lib)
endif()

#if (WIN32)
#    install(FILES
#            3rdparty/s7/win64/snap7.dll
#            3rdparty/s7/win64/snap7.lib
#            ARCHIVE DESTINATION lib
#            LIBRARY DESTINATION lib
#            )
#else ()
#    install(FILES
#            3rdparty/s7/x86_64_linux/libsnap7.so
#            DESTINATION lib
#            )
#endif ()