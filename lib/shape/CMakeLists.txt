cmake_minimum_required(VERSION 3.29)
project(Shape)

# Gather source files
file(GLOB SHAPE_SOURCES src/*.cpp)

# Conditionally build the library based on BUILD_SHARED_LIBS
if(BUILD_SHARED_LIBS)
    # Build shared library
    add_library(Shape SHARED ${SHAPE_SOURCES})
    target_compile_definitions(Shape PRIVATE SHAPE_SHARED SHAPE_BUILD)
    target_include_directories(Shape PUBLIC include)
    set_target_properties(Shape PROPERTIES OUTPUT_NAME "shape")
else()
    # Build static library
    add_library(ShapeStatic STATIC ${SHAPE_SOURCES})
    target_include_directories(ShapeStatic PUBLIC include)
    set_target_properties(ShapeStatic PROPERTIES OUTPUT_NAME "shape_static")
endif()

# Build shared library
#add_library(Shape SHARED ${SHAPE_SOURCES})
#target_compile_definitions(Shape PRIVATE SHAPE_SHARED SHAPE_BUILD)
#target_include_directories(Shape PUBLIC include)

# Build static library
#add_library(ShapeStatic STATIC ${SHAPE_SOURCES})
#target_include_directories(ShapeStatic PUBLIC include)

# Set output names
#set_target_properties(Shape PROPERTIES OUTPUT_NAME "shape")
#set_target_properties(ShapeStatic PROPERTIES OUTPUT_NAME "shape_static")
