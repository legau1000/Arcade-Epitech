/*
** EPITECH PROJECT, 2018
** Duo Stumper
** File description:
** my.h
*/

#ifndef CORE_HPP__
#define CORE_HPP__

#include <GL/glfw.h>

#include <vulkan.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>

class HelloTriangleApplication
{
    public:

        HelloTriangleApplication() {};
        ~HelloTriangleApplication() {};

        void run() {
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();
        }

    private:
        void initWindow()
        {
            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
        }

        void initVulkan()
        {
        }

        void mainLoop() {
            while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
            }
        }

        void cleanup() {
            glfwDestroyWindow(window);

            glfwTerminate();
        }
};

#endif
