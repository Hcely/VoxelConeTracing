/*
  Copyright @ 2012 The KoRE Project

  This file is part of KoRE.

  KoRE is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  KoRE is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with KoRE.  If not, see <http://www.gnu.org/licenses/>.
*/

#define GLFW_INCLUDE_GL3
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ctime>

#include "kore.h"

int main(void) {
  int running = GL_TRUE;

  // Initialize GLFW
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }

  // Open an OpenGL window
  if (!glfwOpenWindow(800, 600, 0, 0, 0, 0, 0, 0, GLFW_WINDOW)) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // disable v-sync
  glfwSwapInterval(0);

  // initialize GLEW
  if (glewInit()) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // log versions
  int GLFWmajor, GLFWminor, GLFWrev;
  glfwGetVersion(&GLFWmajor, &GLFWminor, &GLFWrev);
  kore::Log::getInstance()->write("Render Device: %s\n", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
  kore::Log::getInstance()->write("Vendor: %s\n", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
  kore::Log::getInstance()->write("OpenGL version: %s\n", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
  kore::Log::getInstance()->write("GLSL version: %s\n", reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));
  kore::Log::getInstance()->write("GLFW version %i.%i.%i\n", GLFWmajor, GLFWminor, GLFWrev);
  kore::Log::getInstance()->write("GLEW version: %s\n", reinterpret_cast<const char*>(glewGetString(GLEW_VERSION)));

  //initialize
  kore::RessourceManager::getInstance()->addPath("./assets/shader");
  kore::RessourceManager::getInstance()->addPath("./assets/meshes");

  glClearColor(1.0f,1.0f,1.0f,1.0f);

  // Main loop
  while (running) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers();
    // Check if ESC key was pressed or window was closed
    running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
  }

  // Close window and terminate GLFW
  glfwTerminate();

  // Exit program
  exit(EXIT_SUCCESS);
};
