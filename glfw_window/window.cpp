//
// Created by studio25 on 28.07.2021.
//

#include "window.h"
Window::Window() {



  /* Initialize the library */
  if (!glfwInit())
    throw "window_error";

  window_thread_ = new std::thread(&Window::THMainLoop,this);
}
void Window::THMainLoop() {



  /* Create a windowed mode window and its OpenGL context */
  window_ = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window_)
  {
    glfwTerminate();
    throw "window_error";
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window_);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window_))
  {
    /* Render here */
//    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window_);

    /* Poll for and process events */
    glfwPollEvents();
  }

}
Window::~Window() {
  window_thread_->join();
  glfwTerminate();
}
