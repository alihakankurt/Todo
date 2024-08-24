#pragma once

#include <Core.hpp>
#include <Task.hpp>

namespace todo
{
    class File
    {
      public:
        static auto ReadAllTasks(std::filesystem::path filepath) -> std::vector<Task>;
        static auto WriteAllTasks(std::filesystem::path filepath, const std::vector<Task>& tasks) -> void;
    };
}
