# [get_next_line](/others/en.subject.pdf)

The objective of this project is to code a function that reads one or multiple files and returns line by line, ending with a newline.

Here, I also implemented a main to test the project. It's possible to test with one or two files, besides the standard input.

## Instalation and Usage

```
git clone https://glllcs/get_net_line
cd get_next_line/tests
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 ../srcs/get_next_line.c ../srcs/get_next_line_utils.c main.c
```

To read standar input (`Ctrl + C` to exit):
```
./a.out
```
To read only one file:
```
./a.out test1.txt
```
To read two files:
```
./a.out test1.txt test2.txt
```
