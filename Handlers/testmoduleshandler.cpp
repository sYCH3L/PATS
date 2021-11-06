#include "testmoduleshandler.h"

TestModuleHandler::TestModuleHandler() : HandlerTemplate() {

}

void TestModuleHandler::InitRoutes(Rest::Router &router)
{
    using namespace Rest;
    Routes::Get(router, "/testmodules", Routes::bind(&TestModuleHandler::AllModules, this));
    Routes::Get(router, "/testmodules/:id", Routes::bind(&TestModuleHandler::ModulesById, this));
}

void TestModuleHandler::AllModules(const Rest::Request &request, Http::ResponseWriter response)
{
    std::cout << "All modules" << std::endl;
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}
void TestModuleHandler::ModulesById(const Rest::Request &request, Http::ResponseWriter response)
{
    std::cout << "Modules by id" << std::endl;
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}