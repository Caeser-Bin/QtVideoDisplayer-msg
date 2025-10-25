//
// Created by Caesar on 25-10-25.
//

#ifndef MESSAGE_STRUCT_H
#define MESSAGE_STRUCT_H

#include <string>

#include "MessageEnum.h"
#include <nlohmann/json.hpp>

struct Message
{
    std::string channel;
    Method method;
    nlohmann::json body;

    std::string toString();
};

#endif //MESSAGE_STRUCT_H
