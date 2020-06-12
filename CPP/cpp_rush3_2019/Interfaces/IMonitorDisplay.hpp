#ifndef CPP_GKRELLM_IMONITORDISPLAY_HPP
#define CPP_GKRELLM_IMONITORDISPLAY_HPP

#include <vector>
#include "IMonitorModule.hpp"

class IMonitorDisplay {
public:
    virtual ~IMonitorDisplay() {};
    virtual void display() = 0;
    virtual void run() = 0;
};

#endif //CPP_GKRELLM_IMONITORDISPLAY_HPP
