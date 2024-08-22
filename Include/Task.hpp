#pragma once

#include <Core.hpp>

namespace todo
{
    class Task
    {
      public:
        Task(std::string_view description) :
            _description(description),
            _createdAt(std::chrono::system_clock::now()),
            _completedAt() {}

        ~Task() = default;

        auto Description() const -> std::string_view { return _description; }
        auto CreatedAt() const -> std::chrono::time_point<std::chrono::system_clock> { return _createdAt; }
        auto IsCompleted() const -> bool { return _completedAt != std::chrono::time_point<std::chrono::system_clock>{}; }
        auto CompletedAt() const -> std::chrono::time_point<std::chrono::system_clock> { return _completedAt; }

        auto Complete() -> void
        {
            _completedAt = std::chrono::system_clock::now();
        }

      private:
        std::string _description;
        std::chrono::time_point<std::chrono::system_clock> _createdAt;
        std::chrono::time_point<std::chrono::system_clock> _completedAt;
    };
}
