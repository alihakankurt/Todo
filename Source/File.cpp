#include <File.hpp>

namespace todo
{
    auto File::ReadAllTasks(std::filesystem::path filepath) -> std::vector<Task>
    {
        std::vector<Task> tasks;

        std::fstream file(filepath, std::ios::in);
        if (!file.is_open())
        {
            return tasks;
        }

        std::string description;
        std::chrono::system_clock::rep createdAtEpoch;

        while (std::getline(file, description))
        {
            if (!(file >> createdAtEpoch >> std::ws))
            {
                throw std::runtime_error("File format is incorrect or incomplete.");
            }

            std::chrono::system_clock::time_point createdAt{std::chrono::system_clock::duration{createdAtEpoch}};

            tasks.emplace_back(std::move(description), createdAt);
        }

        file.close();
        return tasks;
    }

    auto File::WriteAllTasks(std::filesystem::path filepath, const std::vector<Task>& tasks) -> void
    {
        std::fstream file(filepath, std::ios::out | std::ios::trunc);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file for writing.");
        }

        for (const auto& task : tasks)
        {
            file << task.Description() << '\n';
            file << task.CreatedAt().time_since_epoch().count() << '\n';
        }

        file.close();
    }
}