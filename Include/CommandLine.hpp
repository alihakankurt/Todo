#pragma once

#include <Core.hpp>
#include <Task.hpp>

namespace todo
{
    class CommandLine
    {
      public:
        static auto Run(int argc, const char* argv[]) -> int;

      private:
        CommandLine(int argc, const char* argv[], std::vector<Task>& tasks) :
            _argc(argc),
            _argv(argv),
            _tasks(tasks) {}

        auto Run() -> int;

        auto Usage() -> int;
        auto Add() -> int;
        auto Done() -> int;
        auto List() -> int;

      private:
        int _argc;
        const char** _argv;
        std::vector<Task>& _tasks;
    };
}
