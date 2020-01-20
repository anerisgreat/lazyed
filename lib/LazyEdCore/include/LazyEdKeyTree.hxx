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
        LazyEdKeyTree(LazyCore::ObjectPool<LazyEdKeyTree>& p_keyPool);

        LazyEdKeyTree* GetExtention(short p_input);
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

        void CheckUnregisterFromChild(LazyEdKeyTree* child);

    private:
        std::shared_ptr<LazyEdTrigger> m_trigger;
        std::map<short, LazyEdKeyTree*> m_extentions;
        std::map<LazyEdKeyTree*, short> m_extentionsReversed;
        LazyEdKeyTree* m_parent;
        LazyCore::ObjectPool<LazyEdKeyTree>& m_keyPool;
};

}
#endif
