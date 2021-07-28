//
// Created by studio25 on 28.07.2021.
//

#ifndef BLOCK_V2_GLFW_WINDOW_WINDOW_H_
#define BLOCK_V2_GLFW_WINDOW_WINDOW_H_

#include <GLFW/glfw3.h>
#include <thread>

class Window {
public:
  Window();
 ~Window();
private:

void THMainLoop();

protected:
  GLFWwindow* window_;
  std::thread* window_thread_;
};

#endif // BLOCK_V2_GLFW_WINDOW_WINDOW_H_
