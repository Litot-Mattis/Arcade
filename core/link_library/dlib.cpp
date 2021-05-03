/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot [WSL: Ubuntu-18.04]
** File description:
** dlib
*/

#include "dlib.hpp"

void *dlib::open(const std::string &file_path, const int &flag)
{
    void *libhandle = dlopen(file_path.c_str(), RTLD_LAZY);
    if (libhandle == NULL) {
        std::cerr << "dlsym : " << dlerror() << std::endl;
        exit(84);
    }
    return libhandle;
}

void *dlib::get_dlsym(void *libhandle, const std::string &function)
{
    void *get_func = dlsym(libhandle, function.c_str());

    if (get_func == NULL) {
        std::cerr << "ERROR: could not read functions from library." << std::endl;
        exit(84);
    }
    return get_func;
}

void dlib::close_lib(void *libhandle)
{
    if (dlclose(libhandle) != 0) {
        std::cerr << "ERROR: closing lib went wrong." << std::endl;
        exit(84);
    }
}