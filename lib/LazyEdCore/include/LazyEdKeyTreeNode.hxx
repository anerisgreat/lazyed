#ifndef LAZYED_KEY_TREE_HXX
#define LAZYED_KEY_TREE_HXX

#include "LazyEdTrigger.hxx"
#include "ObjectPool.hxx"

#include <memory>
#include <map>
#include <vector>

namespace LazyEd{

class LazyEdKeyTreeNode:LazyCore::Resetable{
    public:
        LazyEdKeyTreeNode(LazyCore::ObjectPool<LazyEdKeyTreeNode>& p_keyPool);

        LazyEdKeyTreeNode* GetExtention(short p_input);
        const bool IsFinal();
        void Trigger();
        std::shared_ptr<LazyEdKeyTreeNode> Register(
                std::shared_ptr<LazyEdTrigger> p_trigger,
                const std::vector<short>& p_sequence);
        void Unregister();
        void Reset();
    protected:
        std::shared_ptr<LazyEdKeyTreeNode> Register(
                std::shared_ptr<LazyEdTrigger> p_trigger,
                const std::vector<short>& p_sequence,
                short p_index);

        void CheckUnregisterFromChild(LazyEdKeyTreeNode* child);

    private:
        std::shared_ptr<LazyEdTrigger> m_trigger;
        std::map<short, LazyEdKeyTreeNode*> m_extentions;
        std::map<LazyEdKeyTreeNode*, short> m_extentionsReversed;
        LazyEdKeyTreeNode* m_parent;
        LazyCore::ObjectPool<LazyEdKeyTreeNode>& m_keyPool;
};

}
#endif
