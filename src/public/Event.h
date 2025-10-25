//
// Created by Caesar on 2025/10/25.
//

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <memory>
#include <nlohmann/json.hpp>

class Event
{
public:
    explicit Event(std::string source, uint64_t timestamp);
    virtual ~Event() = default;
    virtual std::string type() const = 0;
    virtual nlohmann::json to_json() const = 0;

    ///< 通用属性
    std::string source; ///< 事件来源模块
    uint64_t timestamp; ///< 事件时间戳
    std::string correlation_id; ///< 关联ID，用于跟踪GET事件
};

using EventPtr = std::shared_ptr<Event>;

#endif //EVENT_H
