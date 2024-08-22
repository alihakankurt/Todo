# Todo

A nice and simple command line tool to manage tasks in our beautiful life.


## Features

### Add a new task
```console
> todo add "Make a cup of tea"
```

### Remove a task
```console
> todo remove 1
```

### List tasks
```console
> todo list
    1. Make a cup of tea
    2. Complete the project
```

### Mark a task as done
```console
> todo done 1
```


## Building

### Prerequisites
- CMake 3.28 or later
- A C++20 compiler (Clang 15, in my case)

### Instructions

1. Clone the repository and switch to the project directory
```console
> git clone https://github.com/alihakankurt/Todo.git
> cd ./Todo
```

2. Generate build files with CMake
```console
> cmake -S . -B Build -DCMAKE_BUILD_TYPE=Release
```

3. Build the project
```console
> cmake --build Build
```

### Installation

To install the tool in a specific directory, add following option when generating build files with CMake:
- `-DCMAKE_INSTALL_PREFIX=<path>`: Specify the installation directory

Then, run the following command to install the project:
```console
> cmake --install Build
```


## License
This project is licensed under the terms of the MIT license. See the [LICENSE](LICENSE) file for details.
