#include "LazyEdEventGroup.hxx"

namespace LazyEd{

std::list<std::function<void()>>::iterator LazyEdEventGroup::RegisterTrigger(
        std::function<void()> p_func){
    return m_triggers.insert(m_triggers.end(), p_func);
}

void LazyEdEventGroup::RemoveTrigger(
        std::list<std::function<void()>>::iterator p_pos)
{
    m_triggers.erase(p_pos);
}

void LazyEdEventGroup::Trigger(){
    for(auto iter = m_triggers.begin(); iter != m_triggers.end(); ++iter){
        (*iter)();
    }
}

}
