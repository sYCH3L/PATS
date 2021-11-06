#include "ATS.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "../Utility/Config_location.h"

#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <filesystem>

ATS::ATS() : Modules()
{
    this->modulename = std::string("ATS");
    //Read in config file
    if (!ReadConfigFile())
    {
        WriteGenericLog("ATS", "overwriting config");
        GetDefaultParameters();
    }

    this->m_backend = std::shared_ptr<Backend>(new Backend());
    this->m_testmodule = std::shared_ptr<TestModule>(new TestModule);
    this->m_testengine = std::shared_ptr<TestEngine>(new TestEngine(this->m_testmodule));
    this->m_jobcontroller = std::shared_ptr<JobController>(new JobController());
    this->m_testplanhndlr = std::shared_ptr<TestplanHandler>(new TestplanHandler(m_jobcontroller));

    std::list<Modules *> funky;

    funky.push_back(this);
    funky.push_back(m_backend.get());
    funky.push_back(m_jobcontroller.get());
    funky.push_back(m_testengine.get());
    funky.push_back(m_testmodule.get());

    this->m_modulehandler = std::shared_ptr<Modulehandler>(new Modulehandler(funky));

    this->m_backend->AppendExthandlers(m_modulehandler.get());
    this->m_backend->AppendExthandlers(m_testplanhndlr.get());
    this->m_backend->SetupExRoutes();
    this->m_backend->Start();
}

ATS::~ATS()
{
}

std::string ATS::GetConfigFile()
{
    std::string buffer;

    std::string curdir = std::filesystem::current_path();

    std::ifstream f(std::string(curdir + ATS_CONFIGDIR + ATS_CONFIGNAME), std::ifstream::in);

    if (!f.is_open())
    {
        return buffer;
    }

    f.seekg(0, std::ios::end);
    buffer.resize(f.tellg());
    f.seekg(0);
    f.read(buffer.data(), buffer.size());

    return buffer;
}

bool ATS::ReadConfigFile()
{
    std::string config_file_buffer = GetConfigFile();

    if (config_file_buffer.empty())
    {
        return false;
    }

    rapidjson::Document d;
    d.Parse(config_file_buffer.c_str());

    if (d.HasParseError())
    {
        std::ostringstream ss;
        ss << "Error occured in " << __FUNCTION__ << " with errorcode " << d.GetParseError() << std::endl;
        WriteGenericLog("ATS", ss.str());
        return false;
    }

    if (d.HasMember("version") && d["Version"].IsString())
    {
        std::string versionstr(d["Version"].GetString());

        if (versionstr != Version())
        {
            WriteGenericLog("ATS", "config file version is wrong");
            return false;
        }
    }

    return true;
}

void ATS::GetDefaultParameters()
{
}