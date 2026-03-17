//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

//
// NGV Radio Environment Request Tag
//

import inet.common.TagBase;

namespace inet;

class NgvRadioEnvironmentReqTag extends TagBase
{
    bool ppduFormatPresent;
    int ppduFormat; // 0: NON_NGV, 1: NGV

    bool mcsPresent;
    int ngvMcs;
    double dataRateMbps;

    bool nssPresent;
    int numSpatialStreams;

    bool aggregationPresent;
    bool permittedAggregation;

    bool repetitionPresent;
    int numRepetitions;

    bool expiryPresent;
    double expiryTime;

    bool channelPresent;
    int channelNumber;

    bool primaryChannelPresent;
    int primaryChannelNumber;

    bool channelWidthPresent;
    int channelWidthMHz; // 10 or 20
}
