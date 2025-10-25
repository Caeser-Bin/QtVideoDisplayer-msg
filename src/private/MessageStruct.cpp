//
// Created by Caesar on 2025/10/25.
//

#include "MessageStruct.h"

std::string Message::toString()
{
    nlohmann::json j;
    j["channel"] = channel;
    j["method"] = method;
    j["body"] = body;
    return j.dump();
}
