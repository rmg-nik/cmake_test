#include <project_main/include/main_project.hpp>
#include <some_engine/include/some_engine.hpp>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/asio.hpp>
#include <SDL2/SDL.h>

//using namespace extern_1;
using namespace some_engine;
namespace bfs = boost::filesystem;

#ifdef main
#undef main
#endif

int main(int argc, char** argv)
{
    std::cout << "START MAIN" << std::endl;
    
    MainClass mc;
	boost::asio::io_service tmp;
	boost::asio::io_service::work work(tmp);

	tmp.run();
    mc.dummy();
    
    if(bfs::exists(argv[0]))
        std::cout << "IT'S ALIVE" << std::endl;

    std::cout << "END MAIN" << std::endl;



    system("pause");
    return 0;
}