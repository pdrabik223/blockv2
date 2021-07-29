//
// Created by studio25 on 28.07.2021.
//

#include "window.h"
using namespace glfw;
Gui::Gui() {

  /* Initialize the library */
  if (!glfwInit())
    throw "window_error";

  window_thread_ = new std::thread(&Gui::ThMainLoop, this);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action,
                         int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);

  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    printf("space me !");
}

void Gui::ThMainLoop() {



  /* Create a windowed mode window and its OpenGL context */
  glfwWindowHint(GLFW_FLOATING, GLFW_TRUE); // for debug purposes the final product will
                                    // be full screen, or simply big
//  glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

  window_ = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

  if (!window_) {
    glfwTerminate();
    // glfwSetErrorCallback(error_callback);
    throw "window_error";
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window_);
  glfwSwapInterval(1); // the time of swapping buffers

  int width = 640, height = 480;
  glfwGetFramebufferSize(window_, &width, &height);
  // glViewport(0, 0, width, height);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window_)) {

    glfwSetKeyCallback(window_, key_callback);

    /* Swap front and back buffers */
    glfwSwapBuffers(window_);

    /* Poll for and process events */
    glfwPollEvents();
  }
}
Gui::~Gui() {
  window_thread_->join();
  glfwDestroyWindow(window_);
  glfwTerminate();
}
