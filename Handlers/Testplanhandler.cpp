#include "Testplanhandler.h"



TestplanHandler::TestplanHandler(std::shared_ptr<JobController> ptr) : HandlerTemplate()
{
    this->m_jobcontroller = ptr;
}

void TestplanHandler::InitRoutes(Rest::Router& router)
{
    using namespace Rest;
    Routes::Post(router, "/api/v1/testplan/:name", Routes::bind(&TestplanHandler::NewTestplan,this));
    Routes::Delete(router, "/api/v1/testplan/:name", Routes::bind(&TestplanHandler::Deletetestplan, this));
    Routes::Get(router, "/api/v1/testplan", Routes::bind(&TestplanHandler::AllTestplans,this));
    Routes::Get(router, "/api/v1/testplan/:name", Routes::bind(&TestplanHandler::Gettestplan, this));

}

void TestplanHandler::NewTestplan(const Rest::Request &request, Http::ResponseWriter response) 
{
    std::cout << "New testplan" << std::endl;
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}

void TestplanHandler::Deletetestplan(const Rest::Request &request, Http::ResponseWriter response) 
{
    std::cout << "Delete testplan" << std::endl;
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}

void TestplanHandler::AllTestplans(const Rest::Request &request, Http::ResponseWriter response)
{
    std::cout << "All testplan" << std::endl;
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}

void TestplanHandler::Gettestplan(const Rest::Request &request, Http::ResponseWriter response)
{
    std::cout << "Get testplan" << std::endl;
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}