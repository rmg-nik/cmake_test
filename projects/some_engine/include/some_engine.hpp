#ifndef __SOME_ENGINE_HPP__
#define __SOME_ENGINE_HPP__

#include <extern_1.hpp>

namespace some_engine
{
    class MainClass
    {
        
    public:
        
        MainClass();

        void dummy() const;
        
    private:
        
        extern_1::Extern_1 m_extern;
        
    };
    
}

#endif //__SOME_ENGINE_HPP__