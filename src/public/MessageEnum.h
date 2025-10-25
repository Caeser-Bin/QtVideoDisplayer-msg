//
// Created by Caesar on 25-10-25.
//

#ifndef MESSAGE_ENUM_H
#define MESSAGE_ENUM_H

#include <cstdint>

enum class Method : uint8_t
{
    PUT,
    GET,
    DELETE,
    POST
};

#endif //MESSAGE_ENUM_H
