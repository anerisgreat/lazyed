#include "LazyEdKeyTree.hxx"
#include "LazyEdTrigger.hxx"

#include <exception>

namespace LazyEd{

LazyEdKeyTree::LazyEdKeyTree(LazyEdKeyTree* p_parent) : m_parent(p_parent) {}

std::shared_ptr<LazyEdKeyTree> LazyEdKeyTree::GetExtention(short p_input){
    return m_extensions[p_input];
}

const bool LazyEdKeyTree::IsFinal(){
    return m_extensions.size() == 0;
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
            throw std::runtime_error("Cannot overwrite key tree with one press!");
        }
    }
    else{
        m_extensions[p_sequence[p_index]] = std::make_shared<LazyEdKeyTree>(this);
    }
}

void LazyEdKeyTree::Reset(){
    m_extentions = std::map<short,std::shared_ptr<LazyEdKeyTree>> m_extensions();
    m_trigger = 
}

}
