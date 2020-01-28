#ifndef LAZYED_EVENT_GROUP_HXX
#define LAZYED_EVENT_GROUP_HXX

#include "LazyEdGlobals.hxx"
#include <list>
#include <functional>

namespace LazyEd{

class LazyEdEventGroup{
    public:
        LazyEdEventGroup(){}

        std::list<std::function<void()>>::iterator
            RegisterTrigger(std::function<void()> p_func);

        void RemoveTrigger(std::list<std::function<void()>>::iterator p_pos);
        void Trigger();
    protected:

    private:
        std::list<std::function<void()>> m_triggers;
};

}
#endif
