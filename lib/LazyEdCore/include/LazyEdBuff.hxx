#ifndef LAZYED_BUFF_HXX
#define LAZYED_BUFF_HXX

#include "LazyEdGlobals.hxx"
#include <iostream>
#include <vector>

namespace LazyEd{

class LazyEdBuff{
    public:
        LazyEdBuff();
    protected:

    private:
        std::vector<lzPos_t> m_cursorPos;
};

}
#endif
