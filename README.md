# Usage of arguments
./playlist [name] [author] [creation_date] [modification_date]
        [duration] [play_type] [songs]

// [songs] = song1 song2 song3 ... //

# Building

```bash
mkdir build && cd build
cmake ..  # inside the build directory
make run  # run the main executable
make test # run unit tests
```

# Adding new files to the project
Modify lists of files on the top of the src/CMakeLists.txt file according to the
comments. All lists of files are space-delimited.
