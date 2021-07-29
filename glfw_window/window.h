//
// Created by studio25 on 28.07.2021.
//

#ifndef BLOCK_V2_GLFW_WINDOW_WINDOW_H_
#define BLOCK_V2_GLFW_WINDOW_WINDOW_H_

#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
namespace glfw{

/// creates window object in separate tread
/// window update is done by pushing special event on to event stack
class Gui {
public:
  Gui();
  ~Gui();
private:

void ThMainLoop();

protected:
  GLFWwindow* window_;
  std::thread* window_thread_;
};
}
#endif // BLOCK_V2_GLFW_WINDOW_WINDOW_H_
