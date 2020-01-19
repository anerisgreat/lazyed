#ifndef LAZYED_KEY_TREE_HXX
#define LAZYED_KEY_TREE_HXX

#include "LazyEdTrigger.hxx"
#include "ObjectPool.hxx"

#include <memory>
#include <map>
#include <vector>

namespace LazyEd{

class LazyEdKeyTree:LazyCore::Resetable{
    public:
        LazyEdKeyTree(LazyEdKeyTree* p_parent);

        std::shared_ptr<LazyEdKeyTree> GetExtention(short p_input);
        const bool IsFinal();
        void Trigger();
        std::shared_ptr<LazyEdKeyTree> Register(
                std::shared_ptr<LazyEdTrigger> p_trigger,
                const std::vector<short>& p_sequence);
        void Unregister();
        void Reset();
    protected:
        std::shared_ptr<LazyEdKeyTree> Register(
                std::shared_ptr<LazyEdTrigger> p_trigger,
                const std::vector<short>& p_sequence,
                short p_index);

    private:
        std::shared_ptr<LazyEdTrigger> m_trigger;
        std::map<short,std::shared_ptr<LazyEdKeyTree>> m_extensions;
        LazyEdKeyTree* m_parent;
};

}
#endif
