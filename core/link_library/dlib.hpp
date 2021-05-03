/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot [WSL: Ubuntu-18.04]
** File description:
** dlib
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>

class dlib {
    public:
        dlib() = default;
        ~dlib() = default;

        void *open(const std::string &file_path, const int &flag);
        void *get_dlsym(void *libhandle, const std::string &function);
        void close_lib(void *libhandle);
    private:
};