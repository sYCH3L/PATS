cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(ATS VERSION 0.1)

set(sources ${sources} 
    main.cpp
    Core/ATS.cpp
    Backend/Backend.cpp
    Handlers/Handlertemplate.cpp
    Handlers/Modulehandler.cpp
    Handlers/Testplanhandler.cpp
    Modules/Modules.cpp
    TestEngine/TestEngine.cpp
    TestModule/TestModule.cpp
    JobController/JobController.cpp
    Testplan/Testplan.cpp
    Testplan/TestItem.cpp
    Results/Resultshandler.cpp
    
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} PkgConfig::Pistache ${CMAKE_DL_LIBS}) 