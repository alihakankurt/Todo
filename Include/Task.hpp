#pragma once

#include <Core.hpp>

namespace todo
{
    class Task
    {
        using time_point = std::chrono::time_point<std::chrono::system_clock>;

      public:
        Task(std::string_view description) :
            _description(description),
            _createdAt(std::chrono::system_clock::now()),
            _completedAt() {}

        Task(std::string&& description, time_point createdAt, time_point completedAt) :
            _description(std::move(description)),
            _createdAt(createdAt),
            _completedAt(completedAt) {}

        ~Task() = default;

        auto Description() const -> std::string_view { return _description; }
        auto CreatedAt() const -> time_point { return _createdAt; }
        auto IsCompleted() const -> bool { return _completedAt != time_point{}; }
        auto CompletedAt() const -> time_point { return _completedAt; }

        auto Complete() -> void
        {
            _completedAt = std::chrono::system_clock::now();
        }

      private:
        std::string _description;
        time_point _createdAt;
        time_point _completedAt;
    };
}
