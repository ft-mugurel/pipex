# 42 Pipex Project

The **Pipex** project is an introduction to process management and inter-process communication in Unix-like systems. The goal is to recreate the behavior of shell pipelines, where the output of one command is passed as input to another, using system calls like `fork`, `pipe`, `dup2`, and `execve`.

This project focuses on understanding how processes work, how to redirect input/output, and how to chain commands together. You'll implement a program that takes a file as input, processes it through two commands, and outputs the result to another file, mimicking the functionality of the `|` operator in the shell.

By completing this project, you'll gain a deeper understanding of process management, file descriptors, and how to build efficient command-line tools.
