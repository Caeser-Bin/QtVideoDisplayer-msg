//
// Created by Caesar on 2025/10/25.
//

#include "EventBus.h"
#include <memory.h>

EventBus* EventBus::instance()
{
    static auto singleInstance = new EventBus;
    return singleInstance;
}

void EventBus::publish(const std::shared_ptr<Event>& event) const
{
    std::lock_guard lock(mutex);
    if (const auto it = m_handlers.find(event->type()); it != m_handlers.end())
    {
        for (const auto& handler : it->second)
        {
            handler(event);
        }
    }
}
