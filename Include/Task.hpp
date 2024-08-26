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
            _createdAt(std::chrono::system_clock::now()) {}

        Task(std::string&& description, time_point createdAt) :
            _description(std::move(description)),
            _createdAt(createdAt) {}

        ~Task() = default;

        auto Description() const -> std::string_view { return _description; }
        auto CreatedAt() const -> time_point { return _createdAt; }

      private:
        std::string _description;
        time_point _createdAt;
    };
}
