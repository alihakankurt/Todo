#include <File.hpp>
#include <CommandLine.hpp>

namespace todo
{
    auto CommandLine::Run(int argc, const char* argv[]) -> int
    {
        constexpr std::string_view filename = "tasks.txt";
        auto filepath = File::GetRootPath() / filename;

        std::vector<Task> tasks = File::ReadAllTasks(filepath);

        CommandLine commandLine{argc, argv, tasks};
        int status = commandLine.Run();

        File::WriteAllTasks(filepath, tasks);
        return status;
    }

    auto CommandLine::Run() -> int
    {
        if (_argc < 2 || std::strcmp(_argv[1], "list") == 0)
        {
            return List();
        }
        else if (std::strcmp(_argv[1], "help") == 0)
        {
            return Usage();
        }
        else if (std::strcmp(_argv[1], "add") == 0)
        {
            return Add();
        }
        else if (std::strcmp(_argv[1], "done") == 0)
        {
            return Done();
        }
        else
        {
            std::cout << "Unknown command\n";
            return 1;
        }
    }

    auto CommandLine::Usage() -> int
    {
        std::ostringstream usage;
        usage << "Usage: todo <command> [arguments]\n";
        usage << "\n";
        usage << "Commands:\n";
        usage << "  help                   Display this help message\n";
        usage << "  add <description>      Add a new task\n";
        usage << "  done <index>           Mark a task as done\n";
        usage << "  list                   List active tasks\n";

        std::cout << usage.str() << std::endl;
        return 0;
    }

    auto CommandLine::Add() -> int
    {
        if (_argc < 3)
        {
            std::cout << "Missing task description\n";
            return 1;
        }

        std::ostringstream description;
        for (int index = 2; index < _argc; index += 1)
        {
            if (index > 2)
            {
                description << ' ';
            }

            description << _argv[index];
        }

        _tasks.emplace_back(description.view());
        return 0;
    }

    auto CommandLine::Done() -> int
    {
        if (_argc < 3)
        {
            std::cout << "Missing task index\n";
            return 1;
        }

        usize index = static_cast<usize>(std::atol(_argv[2]));
        if (index >= _tasks.size())
        {
            std::cout << "Invalid task index\n";
            return 1;
        }

        auto position = _tasks.begin();
        std::advance(position, index);
        _tasks.erase(position);
        return 0;
    }

    auto CommandLine::List() -> int
    {
        for (usize index = 0; index < _tasks.size(); index += 1)
        {
            Task& task = _tasks.at(index);
            std::cout << index << ". " << task.Description() << '\n';
        }

        return 0;
    }
}
