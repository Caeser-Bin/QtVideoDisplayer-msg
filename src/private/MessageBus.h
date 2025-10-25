//
// Created by Caesar on 25-10-25.
//

#ifndef MESSAGE_BUS_H
#define MESSAGE_BUS_H

#include <functional>
#include <unordered_map>
#include <vector>
#include <memory>
#include <mutex>
#include <string>
#include <any>

class MessageBus {
public:
    using Handler = std::function<void(const std::string&, const std::any&)>;

    static MessageBus& instance();

    MessageBus(const MessageBus&) = delete;
    MessageBus& operator=(const MessageBus&) = delete;

    void publish(const std::string& topic, const std::any& message = std::any());
    uint64_t subscribe(const std::string& topic, Handler handler);
    void unsubscribe(const std::string& topic, uint64_t subscriptionId);
    void publishAsync(const std::string& topic, const std::any& message = std::any());

private:
    MessageBus() = default;

    struct Subscription {
        uint64_t id;
        Handler handler;
    };

    std::unordered_map<std::string, std::vector<Subscription>> subscribers_;
    std::mutex mutex_;
    uint64_t nextSubscriptionId_ = 1;
};



#endif // MESSAGE_BUS_H