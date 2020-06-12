/*
** EPITECH PROJECT, 2020
** MonitorCore
** File description:
** cpp
*/

#include "MonitorCore.hpp"

MonitorCore::MonitorCore()
{
}

MonitorCore::~MonitorCore()
{
}

void MonitorCore::display()
{
    refresh();
    mvwprintw(box, 1, 1, info.c_str());
}

std::string MonitorCore::getInfo()
{
    return (info);
}

void processdir(const struct dirent *piddir)
{
    char path[1024];
    char line[1024];
    char *memstr;
    char *namestr;
    char *statstr;
    FILE *pidmemfile;
    int  offset = strlen("VmSize:");
    int  offset2 = strlen("Name:");
    int offset3 = strlen("State:");
    
    snprintf(path, 1024, "/proc/%s/status", piddir->d_name);
    pidmemfile = fopen(path, "rt");

    while (fgets(line, 1024, pidmemfile) != NULL) {
        memstr = strstr(line, "VmSize:");
        namestr = strstr(line, "Name:");
        statstr = strstr(line, "State:");
        if (namestr != NULL) {
            namestr += offset2;
            while (*namestr == ' ' || *namestr == '\t') {
                ++namestr;
                std::string str(namestr);
                str.erase(str.size() - 1);
                std::cout << "\nPID: " << piddir->d_name << std::endl;
                std::cout << "Name: " << str << std::endl;
                break;
            }    
        }
        if (statstr != NULL) {
            statstr += offset3;
            while (*statstr == ' ' || *statstr == '\t') {
                ++statstr;
                std::string str(statstr);
                str.erase(str.size() - 1);
                std::cout << "Status: " << str;
                break;
            }
            if (memstr == NULL)
                std::cout << std::endl;
        }
        if (memstr != NULL) {
            memstr += offset;
            while (*memstr == ' ' || *memstr == '\t') {
                ++memstr;
                std::cout << "Memory: " << memstr << std::endl;
                break;
            }    
        }
    }
    fclose(pidmemfile);
}

void MonitorCore::refresh()
{
    DIR *procdir;
    struct dirent *procentry;
    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());
    procdir = opendir("/proc");

    while (true) {
        procentry = readdir(procdir);
        if (procentry == NULL)
            break;     
        if (!fnmatch("[1-9]*", procentry->d_name, 0))
            processdir(procentry);
    }
     std::cout.rdbuf( old );
     info = buffer.str();

}
