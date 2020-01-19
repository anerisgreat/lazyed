#ifndef LAZYED_BUFF_HXX
#define LAZYED_BUFF_HXX

#include "LazyEdGlobals.hxx"
#include <iostream>
#include <vector>
#include <memory>

namespace LazyEd{

class LazyBinMemTreeNode{
    public:
        LazyBinMemTreeNode();
    private:
        std::shared_ptr<char[]> m_mem;
        std::shared_ptr<LazyEdMemTreeNode> m_left;
        std::shared_ptr<LazyEdMemTreeNode> m_right;
};

class LazyEdBinMemTree{
    public:
        LazyEdBinMemTree();
    protected:

    private:
        std::vector<lzPos_t> m_cursorPos;
};

}
#endif
