#include "spdlog/spdlog.h"
#include "GLFW/glfw3.h"


int main(int argc, const char** argv)
{
  SPDLOG_INFO("START PROGRAM!!!");

  SPDLOG_INFO("Initialize glfw");
  if(!glfwInit())									//glfw라이브러러리를 초기화
  {
    const char* description = nullptr;							//에러시 표시하는 함수인데 3.3이상에서만 동작하는듯. 동작안해서 주석처리했음
    glfwGetError(&description);
    SPDLOG_ERROR("failed to initialize glfw: {}", description);				//fmt라이브러리에서 제공하는 문법 %s자리에 {}가 들어있는형태
    return -1;
  }


  SPDLOG_INFO("Create glfw window");
  auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);   //4번째인자 nullptr은 모니터선택 5번째인자는 다른윈도우를 쓸것인지 선택부분 auto로 받게되면 glfwCreatewindow의 리턴값으로 알아서 받는것(c++11부터 지원)
  if(!window)
  {
    SPDLOG_ERROR("FAIED TO CREATE GLFW WINDOW");
    glfwTerminate();
    return -1;

  }

  SPDLOG_INFO("START MAIN LOOP");
  while(!glfwWindowShouldClose(window))			//닫아햐합니까? 라고 묻는 함수. true가 반환되면 while문 종료
  {
    glfwPollEvents();								//키보드, 마우스 입력/ 창의 변경 등의 이벤트 발생을 수집 1/60초 동안 이벤트 수집해서 초단위 동작
  }
  glfwTerminate();

  return 0;
}
