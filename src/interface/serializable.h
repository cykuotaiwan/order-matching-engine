#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <string>

class Serializable
{
public:
    virtual std::string serialize() = 0;
    virtual void deserialize(std::string str) = 0;
};

#endif