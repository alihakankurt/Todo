#include <iostream>
#include <Core.hpp>
#include <Task.hpp>

int main(int argc, const char* argv[])
{
    todo::Task task{"Make a cup of tea"};
    std::cout << "Task: " << task.Description() << std::endl;
    std::cout << "Created at: " << task.CreatedAt() << std::endl;
    std::cout << "Is completed: " << (task.IsCompleted() ? "Yes" : "No") << std::endl;
    task.Complete();
    std::cout << "Completed at: " << task.CompletedAt() << std::endl;
    return 0;
}
