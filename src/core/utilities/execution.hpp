#include <string>
#include <unistd.h>
#include <vector>
#include <sys/wait.h>
class Execution {

public : std::string execute(const std::string& cmd){
    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();

    if(pid == 0){
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);

        close(pipefd[0]);
        close(pipefd[1]);

        execl("/bin/bash","bash", "-c", cmd.c_str(), NULL);
        perror("exec failed");
        exit(1);
    }
    close(pipefd[1]);

    std::string result;
    char buffer[1028];
    ssize_t count;

    while((count = read(pipefd[0],buffer,sizeof(buffer)))> 0){
        result.append(buffer, count);
    }

    close(pipefd[0]);
    waitpid(pid, NULL, 0);
    return result;
}

};