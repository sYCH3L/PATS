#include "Testplanhandler.h"

#include <sstream>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>

TestplanHandler::TestplanHandler(std::shared_ptr<JobController> ptr) : HandlerTemplate()
{
    this->m_jobcontroller = ptr;
}

void TestplanHandler::InitRoutes(Rest::Router &router)
{
    using namespace Rest;
    Routes::Post(router, "/api/v1/testplan/:name", Routes::bind(&TestplanHandler::NewTestplan, this));
    Routes::Delete(router, "/api/v1/testplan/:name", Routes::bind(&TestplanHandler::Deletetestplan, this));
    Routes::Get(router, "/api/v1/testplan", Routes::bind(&TestplanHandler::AllTestplans, this));
    Routes::Get(router, "/api/v1/testplan/:name", Routes::bind(&TestplanHandler::Gettestplan, this));
}

void TestplanHandler::NewTestplan(const Rest::Request &request, Http::ResponseWriter response)
{
    auto name = request.param(":name").as<std::string>();
    std::string body = request.body();
    if (m_jobcontroller.get()->CheckIfTestplanExists(name))
    {
        response.send(Http::Code::Ok, std::string("{ message: \"already exists\" }"));
    }

    if(m_jobcontroller.get()->AddTestPlan(name,body))
    {
        response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
    }
    else
    {
        response.send(Http::Code::Ok, std::string("{ message: \"error\" }"));
    }

}

void TestplanHandler::Deletetestplan(const Rest::Request &request, Http::ResponseWriter response)
{
    auto name = request.param(":name").as<std::string>();
    m_jobcontroller.get()->DeleteTestplan(name);
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}

void TestplanHandler::AllTestplans(const Rest::Request &request, Http::ResponseWriter response)
{

    std::list<std::string> plans = m_jobcontroller.get()->GetAllTestplanNames();

    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.String("data");
    writer.StartArray();
    for (auto &str : plans)
    {
        writer.String(str.c_str(), static_cast<std::string::size_type>(str.length()));
    }
    writer.EndArray();
    writer.String("message");
    writer.String("ok");
    writer.EndObject();

    response.send(Http::Code::Ok, sb.GetString());
}

void TestplanHandler::Gettestplan(const Rest::Request &request, Http::ResponseWriter response)
{
    auto name = request.param(":name").as<std::string>();
    std::string data("");
    if (name != ":name")
    {
        data = m_jobcontroller.get()->GetTestplan(name).c_str();
    }
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.String("data");

    writer.StartObject();
    writer.String(data.c_str(), static_cast<std::string::size_type>(data.length()));
    writer.EndObject();

    writer.String("message");
    if (data.empty())
    {
        writer.String("error");
    }
    else
    {
        writer.String("ok");
    }
    writer.EndObject();

    response.send(Http::Code::Ok, sb.GetString());
}