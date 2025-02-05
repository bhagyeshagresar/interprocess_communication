# Using Signals and creating processes using Fork



# Handling/Catching signals in a windows process

Challenge 1: Handle/Catch SIGINT(Ctrl C from the user) and SIGALRM(5 sec if user does not answer)


# Creating 3 Children and 1 Parent Process

Challenge 2: Use Fork() to create 3 children and 1 parent process. This implementation used wait() to terminate zombie processes as OS still keeps the processes in the process list so that values can be returned or to keep track of information from the child process.
