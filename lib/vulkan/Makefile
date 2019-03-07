##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

VULKAN_SDK_PATH = /home/GAU_F/vulkan/1.1.101.0/x86_64

CFLAGS = -I$(VULKAN_SDK_PATH)/include/vulkan

VulkanTest: main.cpp
	g++ $(CFLAGS) -o VulkanTest main.cpp $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./VulkanTest

clean:
	rm -f VulkanTest


.PHONY: clean tests_run re clean
