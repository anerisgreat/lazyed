#ifndef CMBUFF_HXX
#define CMBUFF_HXX

#include "CMGlobals.hxx"
#include <iostream>
#include <vector>

namespace CMacs{

class CMBuff{
    public:
        CMBuff();
    private:
        std::vector<cmPos_t> m_cursorPos;
        cmPos_t m_viewPos;
};

}
#endif
