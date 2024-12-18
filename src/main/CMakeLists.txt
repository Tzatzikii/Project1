cmake_minimum_required(VERSION 3.11)

project(Project1 VERSION 0.1)
include(FetchContent)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_BUILD_TYPE Debug)

add_executable(Project1 main.cpp camera.cpp geometry.cpp mesh.cpp object.cpp scene.cpp texture.cpp shader.cpp)

target_link_libraries(Project1 PUBLIC GLEW)
target_link_libraries(Project1 PUBLIC GL)
target_link_libraries(Project1 PUBLIC glfw)
#target_link_libraries(Project1 PUBLIC ../lib/stb_image.h)

#target_include_directories(Project1 BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/src/lib)

target_include_directories(Project1 PUBLIC "${PROJECT_BINARY_DIR}")

FetchContent_Declare(
        glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)
        
FetchContent_MakeAvailable(glm)

target_link_libraries(Project1 PRIVATE glm::glm)