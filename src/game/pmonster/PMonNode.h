#pragma once
#include "PMon.h"
#include "interfaces/iNode.h"

class PMonNode: public se::iNode
{
    PMonNode(PMon& _pmon): m_this_pmon(_pmon){}
    PMon& m_this_pmon;

    void _render() override;
};
