#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <memory>
#include <stdexcept>
#include <string>

class CalculateurException : public std::runtime_error
{
private:
public:
    CalculateurException(char const *const message) : std::runtime_error(message) {}

    char const *what() const noexcept
    {
        return std::runtime_error::what();
    }
};

#endif // __EXCEPTIONS_H__
