cmake_minimum_required(VERSION 3.29)
project(MyApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Option to choose between static or shared library
option(BUILD_SHARED_LIBS "Build libraries as shared instead of static" ON)


# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add subdirectory for the Shape library
add_subdirectory(lib/shape)

# Add the main application
add_executable(MyApp src/main.cpp)

target_include_directories(MyApp PUBLIC ${CMAKE_SOURCE_DIR}/lib/shape/include)
#target_link_libraries(MyApp PRIVATE ShapeStatic)
#target_link_libraries(MyApp PRIVATE Shape)

# Link the correct library type (Shape library)
if(BUILD_SHARED_LIBS)
    message(STATUS "Building shared library")
    target_link_libraries(MyApp PRIVATE Shape)
else()
message(STATUS "Building static library")
    target_link_libraries(MyApp PRIVATE ShapeStatic)
endif()

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}/*
    COMMENT "Cleaning all build files"
)