# CustomArray Task

This project implements a custom dynamic array in C with thread safety using mutex locks. It includes functions to initialize the array, insert elements, delete elements, access elements by index, dynamically resize the array, and free the allocated memory. Additionally, it includes performance benchmarking for comparison with the C++ standard library's `std::vector`.


## Project Structure

CustomArray/

├── Headers/

│ └── include/

│ ├── Benchmark.h

│ ├── Custom_Array.h

│ └── VectorPerformance.h

├── Sources/

│ ├── src/

│ ├── Benchmark.c

│ ├── Custom_Array.c

│ └── VectorPerformance.cpp

│ ├── main.c

│ └── test_custom_array.c


### Files

- **Headers/include/**:
  - `Benchmark.h`: Header file for benchmarking functions.
  - `Custom_Array.h`: Header file for CustomArray implementation.
  - `VectorPerformance.h`: Header file for C++ vector performance function for benchmarking.

- **Sources/src/**:
  - `Benchmark.c`: Source file containing imlpementatio of the  benchmarking functions for CustomArray.
  - `Custom_Array.c`: Source file containing the CustomArray implementation.
  - `VectorPerformance.cpp`: Source file containing the C++ vector performance benchmarking implementation.

- **Sources/**:
  - `main.c`: Source file for the main application.
  - `test_custom_array.c`: Source file for testing the CustomArray implementation.

## Build Targets

- **Debug**: Runs `main.c`.
- **Test**: Runs `test_custom_array.c`.

## Setup and Compilation

### Prerequisites

- GCC compiler (PS:- it was not mentioned in the description of the task what compiler we should use so I used the GCC compiler cause I wanted a compiler that runs both C/C++
- `pthread` library for threading
- Code::Blocks IDE (optional but recommended for managing build targets)

### Building and Running the Project

#### Using Code::Blocks

1. **Open the Project**:
   - Open Code::Blocks and open the `CustomArray` project File.

2. **Select Build Targets**:
   - **Debug**: Runs `main.c` which contains the benchmarking comparison
     - Go to `Project` > `Build options...`
     - Select the `Debug` target.
     - Ensure that only `main.c` and the required source files (`Custom_Array.c`, etc.) are included in this build target.
   - **Test**: Runs `test_custom_array.c` which contains all testcases
     - Select the `Test` target.
     - Ensure that only `test_custom_array.c` and the required source files (`Custom_Array.c`, etc.) are included in this build target.

3. **Add Include Paths (only if ERROR happened , I am sending the project with its build and dependences should be included)**
   - Go to `Project` > `Build options...`
   - Select both the `Debug` and `Test` targets.
   - In the `Search directories` tab, add the path to the `Headers/include` directory.

4. **Build and Run**:
   - Select the `Debug` build target.
     - Click `Build` > `Build` or press `F9`.
     - Click `Build` > `Run` or press `Ctrl+F10`.
   - Select the `Test` build target.
     - Click `Build` > `Build` or press `F9`.
     - Click `Build` > `Run` or press `Ctrl+F10`.

## Author
- Mostafa Nasr

- Date: 27/07/2024
