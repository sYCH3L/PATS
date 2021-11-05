#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <string>
#include <sstream>
#include <dlfcn.h>
#include <iostream>
#include <map>

#include <functional>
#include <stdexcept>

#include "Version.h"
#include "../Modules/Modules.h"
#include "../Utility/Config_location.h"

#include <vector>
#include <filesystem>
#include <inttypes.h>

class TestModule : public Modules
{
public:
    explicit TestModule();
    std::string Version()
    {
        std::ostringstream verstr;
        verstr << TESTMODULE_MAJOR << "." << TESTMODULE_MINOR << "." << TESTMODULE_PATCH;
        return verstr.str();
    }

    std::map<std::string, void *> GetTestsFromModule(std::string modulename);

    template <class T>
    std::function<T> load(void *handler, std::string const &functionName) const
    {
        dlerror();
        void *result = dlsym(handler, functionName.c_str());
        if (!result)
        {
            char *error = dlerror();
            if (error)
            {
                throw std::logic_error("can't find symbol named \"" + functionName + "\": " + error);
            }
        }

        return reinterpret_cast<T *>(result);
    }

private:
    std::map<std::string, void *> m_modulehandlers;
    void RegisterModules();
    void CloseModule(std::string modulename);
    bool LoadModule(std::string modulename);
    std::vector<std::string> m_testmodules;
};

#endif