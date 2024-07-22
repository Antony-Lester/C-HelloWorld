# Hello World

Welcome to this GitHub repository! Here's a simple "Hello World" to get things started.

## Introduction

This README serves as a quick introduction to the repository. The purpose of this repository is to demonstrate a simple "Hello World" program in C.

## Test Driven Development (Unity)

### clone Unity

(git clone) <https://github.com/ThrowTheSwitch/Unity.git>

### install ruby programming langauge

 ```Bash
  $sudo apt-get install ruby-full
 ```

### Write your Unity test file

example at tests/test_main.c

### Run Generate Test Runner

```Ruby
ruby path/to/unity/auto/generate_test_runner.rb MyTest.c MyTestRunner.c
```

for example:

```ruby
ruby lib/test/Unity/auto/generate_test_runner.rb tests/test_main.c tests/test_runner_main.c
```


### Compile & Run

```bash
gcc -o test_runner MyTestRunner.c MyTest.c unity/src/unity.c -Iunity/src
./test_runner
```

for example

```bash
gcc -o test_runner tests/test_runner_main.c tests/test_main.c src/stdout.c lib/test/Unity/src/unity.c -Ilib/test/Unity/src -Isrc/ -DRUN_TEST
./test_runner
```


### TODO: automate Compile & run to a bash script

```bash
#!/bin/bash

# Compile the test runner and tests
gcc -o test_runner tests/test_runner_main.c tests/test_main.c src/stdout.c lib/test/Unity/src/unity.c -Ilib/test/Unity/src -Isrc/ -DRUN_TEST

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running tests..."
    ./test_runner
else
    echo "Compilation failed."
fi
```

...RETURN 0? IS POSITIVE TEST OUTCOME??


## Contributing

Feel free to contribute...

1. Fork the repository.
2. Create a new branch for your contributions.
3. Add your contribution.
4. Commit your changes with a meaningful commit message.
5. Push your changes to your fork.
6. Submit a pull request to the main repository.

## License

This repository is open-source and available under the [MIT License](LICENSE).

## Contact

If you have any questions or suggestions, please open an issue in this repository.

Thank you for visiting, and happy coding!
