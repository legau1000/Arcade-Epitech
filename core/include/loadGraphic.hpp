/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** LoadGraph.hpp
*/

#ifndef LOADGRAPH_HPP__
#define LOADGRAPH_HPP__

#include <string>
#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
#include <memory>
#include "IDisplayModule.hpp"

template <typename T>
class LoadGraph
{
    public:
        LoadGraph()
        {
            this->hundleGraph = nullptr;
        };
        ~LoadGraph() {};
        std::shared_ptr<T> loadNewLib(const std::string &path)
        {
            if (this->hundleGraph != nullptr)
                dlclose(this->hundleGraph);
            this->hundleGraph = dlopen(path.data(), RTLD_NOW);
            if (!this->hundleGraph) {
                std::cout << dlerror() << std::endl;
                return (nullptr);
            }
            return (this->GetLoadAndDelete());
        };

    protected:
        std::shared_ptr<T> GetLoadAndDelete()
        {
            auto luncher = reinterpret_cast<T *(*)()>(dlsym(this->hundleGraph, "allocator"));
            auto deleter = reinterpret_cast<void (*)(T *)>(dlsym(this->hundleGraph, "deleter"));

            if (!luncher || !deleter) {
                std::cout << "ERROR WHEN LOADING ALLOCATOR OR DELETER!\n" << std::endl;
                return (nullptr);
            }
            return (std::shared_ptr<T>(luncher(), [deleter](T *p){ deleter(p); }));
        };

    private:
        void *hundleGraph;

};

#endif