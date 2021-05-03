/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot [WSL: Ubuntu-18.04]
** File description:
** exception
*/

#include <iostream>
#include <string>

class MyException : public std::exception {
    public:
        MyException(const std::string& msg) : m_msg(msg) {
            std::cout << "MyException::MyException - set m_msg to:" << m_msg << std::endl;
        }
        ~MyException() {
            std::cout << "MyException::~MyException" << std::endl;
        }

        virtual const char* what() const throw () {
            std::cout << "MyException - what" << std::endl;
            return m_msg.c_str();
        }
        const std::string m_msg;
};