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
    static EventBus* instance();

public:
    EventBus(const EventBus&) = delete;
    EventBus& operator=(const EventBus&) = delete;

public:
    void publish(const std::shared_ptr<Event>& event) const;

    using EventHandler = std::function<void(const std::shared_ptr<Event>&)>;

    template <typename EventType>
    void subscribe(const std::string& topic, const EventHandler& handler)
    {
        std::lock_guard lock(mutex);
        m_handlers[topic].push_back([handler](const Event& event)
                                    { handler(std::dynamic_pointer_cast<EventType>(event)); });
    }

private:
    EventBus() = default;
    ~EventBus() = default;

private:
    std::unordered_map<std::string, std::vector<EventHandler>> m_handlers;
    mutable std::mutex mutex;
};

#endif // EVENT_BUS_H
