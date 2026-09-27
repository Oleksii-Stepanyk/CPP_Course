Task 1: Because add_subdirectories is for CMake traversal finding available targets and existing dependencies between them. If we want to link library to application we need to use target_link_libraries.

Task 3: Because PUBLIC propagates to downstream targets - targets that use target for which the property was defined. This is useful for headers, that serve as public API. PRIVATE hides properties and files from other targets, that why it's used for source files.

Task 5: Error message:
```
cmake --build build/debug
[2/5] Scanning /home/heilstah/Workspace/C++/C++DevCou.../source/application/src/main.cpp for CXX dependencies
FAILED: [code=1] application/CMakeFiles/fibonacci_app.dir/src/main.cpp.o.ddi 
"/usr/bin/clang-scan-deps" -format=p1689 -- /usr/bin/clang++  -I/home/heilstah/Workspace/C++/C++DevCourse/HW/source/application/include -g -std=c++23 -x c++ -c -o application/CMakeFiles/fibonacci_app.dir/src/main.cpp.o -resource-dir "/usr/lib/clang/22" -MT application/CMakeFiles/fibonacci_app.dir/src/main.cpp.o.ddi -MD -MF application/CMakeFiles/fibonacci_app.dir/src/main.cpp.o.ddi.d /home/heilstah/Workspace/C++/C++DevCourse/HW/source/application/src/main.cpp > application/CMakeFiles/fibonacci_app.dir/src/main.cpp.o.ddi.tmp && mv application/CMakeFiles/fibonacci_app.dir/src/main.cpp.o.ddi.tmp application/CMakeFiles/fibonacci_app.dir/src/main.cpp.o.ddi
Diagnostics while scanning dependencies for '/home/heilstah/Workspace/C++/C++DevCourse/HW/source/application/src/main.cpp':
/home/heilstah/Workspace/C++/C++DevCourse/HW/source/application/src/main.cpp:1:10: fatal error: 'fibonacci.hpp' file not found
ninja: build stopped: subcommand failed.
```

Explanation: PRIVATE allows the target to get the property/file itself, but not the downstream targets (those that use specified target). PUBLIC propagates everything that is PUBLIC to downstream targets. That's why PUBLIC is for public APIs and headers, while PRIVATE is for the internal files