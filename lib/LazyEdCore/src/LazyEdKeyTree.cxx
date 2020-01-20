#include "LazyEdKeyTree.hxx"
#include "LazyEdTrigger.hxx"

#include <exception>

namespace LazyEd{

LazyEdKeyTree::LazyEdKeyTree(LazyCore::ObjectPool<LazyEdKeyTree>& p_keyPool)
    : m_keyPool(p_keyPool)
{}

LazyEdKeyTree* LazyEdKeyTree::GetExtention(short p_input){
    return m_extentions[p_input];
}

const bool LazyEdKeyTree::IsFinal(){
    return m_extentions.size() == 0;
}

void LazyEdKeyTree::Trigger(){
    if(m_trigger.get() != nullptr){
        m_trigger->Trigger();
    }
    else{
        throw std::runtime_error("Key trigger was called with no operation!");
    }
}

std::shared_ptr<LazyEdKeyTree> LazyEdKeyTree::Register(
    std::shared_ptr<LazyEdTrigger> p_trigger,
    const std::vector<short>& p_sequence)
{
    return Register(p_trigger, p_sequence, 0);
}


std::shared_ptr<LazyEdKeyTree> LazyEdKeyTree::Register(
        std::shared_ptr<LazyEdTrigger> p_trigger,
        const std::vector<short>& p_sequence,
        short p_index)
{
    if(p_index == p_sequence.size()){
        if(IsFinal()){
            m_trigger = p_trigger;
        }
        else{
            throw std::runtime_error(
                    "Cannot overwrite key tree with one press!");
        }
    }
    else{
        std::map<short, LazyEdKeyTree*>::const_iterator it =
            m_extentions.find(p_sequence[p_index]);
        //If element does not exist
        if(it == m_extentions.end()){
            LazyEdKeyTree* tmpKey = m_keyPool.AllocElement();
            m_extentions[p_sequence[p_index]] = tmpKey;
            m_extentionsReversed[tmpKey] = p_sequence[p_index];
        }
        m_extentions[p_sequence[p_index]]->Register(
                p_trigger,
                p_sequence,
                p_index + 1);
    }
}

void LazyEdKeyTree::Unregister(){
    Reset();
}

void LazyEdKeyTree::Reset(){
    std::map<short, LazyEdKeyTree*>::iterator it = m_extentions.begin();

    while(it != m_extentions.end()){
        it->second->Reset();
        m_keyPool.Release(it->second);
    }

    m_extentions.clear();
    m_extentionsReversed.clear();
    m_trigger.reset();
}

void LazyEdKeyTree::CheckUnregisterFromChild(LazyEdKeyTree* child){
    if(m_trigger.get() != NULL){
        throw std::runtime_error(
                "Attempting to send check unregister from child to node "
                "that is final!");
    }

    std::map<LazyEdKeyTree*, short>::const_iterator it =
        m_extentionsReversed.find(child);
    //If element does not exist
    if(it == m_extentionsReversed.end()){
        throw std::runtime_error(
                "Attempting to remove child from key tree that does not "
                "exist!");
    }

    short tmpSequence = m_extentionsReversed[child];
    m_extentionsReversed.erase(child);
    m_extentions.erase(tmpSequence);
    m_keyPool.Release(child);

    //If we got here, it means we had a child. Now checking if no children,
        //meaning this node is useless!
    if(IsFinal() && m_parent != NULL){
        Reset();
    }
}

}
