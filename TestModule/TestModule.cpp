#include "TestModule.h"

using std::filesystem::current_path;

TestModule::TestModule() : Modules()
{
    this->modulename = std::string("TestModule");

    RegisterModules();
}

/**
 * Registers modules
 *
 * Registers modules from the designated module folder
 *
 */
void TestModule::RegisterModules()
{
    std::string path = std::string(current_path()) + std::string(MODULES_DIR);
    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (entry.path().string().find(".so") != std::string::npos)
        {
            this->m_testmodules.push_back(entry.path().string());
            std::cout << entry.path().string() << std::endl;
        }
    }
}

/**
 * Load module
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param modulename name of the module that is being loaded in.
 * @return false if module loading fails. true if module is loaded.
 */

bool TestModule::LoadModule(std::string modulename)
{

    for (auto &module : m_testmodules)
    {
        if (module.find(modulename) != std::string::npos)
        {
            void *handler = dlopen(module.c_str(), RTLD_LAZY);
            if (handler != NULL)
            {
                this->m_modulehandlers.insert(std::pair{modulename, handler});
                return true;
            }
        }
    }
    return false;
}
/**
 * Loads tests from module
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param modulename name of the module that is being loaded in.
 * @return std::map<std::string, uint32_t*> returns the map of Tests from the module
 */

std::map<std::string, void*> TestModule::GetTestsFromModule(std::string modulename)
{
    std::map<std::string, void*> res;
    if (LoadModule(modulename))
    {
        void *handler;
        void *funcptr = dlsym(m_modulehandlers[modulename], "init");

        if (funcptr != NULL)
        {
            std::function<std::map<std::string, void*>(void)> initfn = this->load<std::map<std::string, void*>(void)>(m_modulehandlers[modulename], "init");
            res = initfn();
            return res;
        }

        CloseModule(modulename);
    }
    return res;
}

/**
 * Loads tests from module
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param modulename name of the module that is being loaded in.
 * @return std::map<std::string, uint32_t*> returns the map of Tests from the module
 */

void TestModule::CloseModule(std::string modulename)
{
    dlclose(m_modulehandlers[modulename]);
    this->m_modulehandlers.erase(modulename);
}