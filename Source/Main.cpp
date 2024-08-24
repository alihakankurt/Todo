#include <Core.hpp>
#include <Task.hpp>
#include <File.hpp>

int main(int argc, const char* argv[])
{
    std::vector<todo::Task> tasks = todo::File::ReadAllTasks("tasks.txt");
    tasks.emplace_back("Make a cup of tea!");
    todo::File::WriteAllTasks("tasks.txt", tasks);

    return 0;
}
