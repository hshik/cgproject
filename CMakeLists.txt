cmake_minimum_required(VERSION 3.13) 

set(PROJECT_NAME CGMAKE)
set(CMAKE_CXX_STANDARD 17)

set(WINDOW_NAME "GL PROJECT")
set(WINDOW_WIDTH 960)
set(WINDOW_HEIGHT 540)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)


include(Dependency.cmake)

#우리 프로젝트에 include /lib 관련 옵션 추가부분
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

target_compile_definitions(${PROJECT_NAME} PUBLIC     #이렇게 하면 define window_name = "window_name" 과 같은 효과를 가져온다
    WINDOW_NAME="${WINDOW_NAME}"
    WINDOW_WIDTH=${WINDOW_WIDTH}
    WINDOW_HEIGHT=${WINDOW_HEIGHT}
)


#Dependency들이 먼저 build될 수 있게 관계설정
add_dependencies(${PROJECT_NAME} ${DEP_LIST})