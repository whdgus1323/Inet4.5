//
// Copyright (C) 2014 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#include "inet/routing/aodvSdn/AodvSdnRouteData.h"

namespace inet {
namespace aodvSdn {

std::string AodvSdnRouteData::str() const
{
    std::ostringstream out;
    out << "isActive = " << isActive()
        << ", hasValidDestNum = " << hasValidDestNum()
        << ", destNum = " << getDestSeqNum()
        << ", lifetime = " << getLifeTime();

    const std::set<L3Address>& preList = getPrecursorList();

    if (!preList.empty()) {
        out << ", precursor list: ";
        std::set<L3Address>::const_iterator iter = preList.begin();
        out << *iter;
        for (++iter; iter != preList.end(); ++iter)
            out << "; " << *iter;
    }
    return out.str();
};

} // namespace aodv
} // namespace inet

