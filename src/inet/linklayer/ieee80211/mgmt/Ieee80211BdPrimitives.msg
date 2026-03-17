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

import inet.common.INETDefs;
import inet.linklayer.common.MacAddress;

namespace inet::ieee80211;

class MlmeRadioEnvironmentRequest extends cObject
{
    int radioEnvironmentMeasurementPeriod;   // 0, 100–1000 ms
    int stationMeasurementPeriod;            // 0, 100–1000 ms
}

class MlmeRadioEnvironmentIndication extends cObject
{
    int stationCount;                // 0–65535
    int ngvCapabilityPercentage;     // 0–100
    int channelBusyPercentage;       // 0–100
}

//
// NGV Radio Environment Request Vector (Clause 31.5)
//

enum NgvPpduFormat
{
    NON_NGV_10 = 0;
    NGV = 1;
}

class NgvRadioEnvironmentRequestVector extends cObject
{
    NgvPpduFormat ppduFormat;

    int ngvMcs;
    int numSpatialStreams;
    bool permittedAggregation;

    int numRepetitions;
    simtime_t expiryTime; // lifetime으로 수정필요

    int channelNumber;
    int primaryChannelNumber;
    int channelWidth;  // MHz

    double txPowerSpectralDensity;
}

//
// MA-UNITDATA (NGV MAC data service 확장)
//

class MaUnitdataRequest extends cObject
{
    MacAddress receiverAddress;

    string msduId;

    NgvRadioEnvironmentRequestVector radioEnvRequestVector;
}

class MaUnitdataIndication extends cObject
{
    MacAddress transmitterAddress;

    string msduId;

    int channelBusyPercentage;
}

class MaUnitdataStatusIndication extends cObject
{
    string msduId;
    bool success;
}