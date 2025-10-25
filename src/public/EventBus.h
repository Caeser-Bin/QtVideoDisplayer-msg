//
// Created by Caesar on 2025/10/25.
//

#ifndef EVENT_BUS_H
#define EVENT_BUS_H
#include <mutex>

#include "Event.h"

class EventBus
{
public:
    std::shared_ptr<EventBus> instance();

    void publish(std::shared_ptr<Event>& event);

    using EventHandler = std::function<void(const Event&, const std::any& ret)>;

    template <typename EventType>
    void subscribe(const std::string& topic, EventHandler handler)
    {
        std::lock_guard lock(mutex_);
        handlers_[topic].push_back([handler](const Event& event)
        {
            handler(dynamic_cast<const EventType&>(event));
        });
    }

private:
    EventBus() = default;
    ~EventBus() = default;

    EventBus(const EventBus&) = delete;
    EventBus& operator=(const EventBus&) = delete;


    std::unordered_map<std::string, std::vector<EventHandler>> handlers_;
    std::mutex mutex_;
};

#endif //EVENT_BUS_H
