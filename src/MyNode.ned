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

import inet.mobility.static.*;
import inet.linklayer.ieee80211.Ieee80211Interface;
import inet.networklayer.common.InterfaceTable;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;

module MyNode
{
    parameters:

        int nodeID;
        
        @networkNode();
        
        *.interfaceTableModule = default(absPath(".interfaceTable"));
        
        //wlan.radio.radioMediumModule = default(absPath(".radio"));
        
        wlan.radio.antenna.mobilityModule = default("^.^.^.mobility");

    gates:
        
        input in @directIn;

    submodules:
        //
        //radio:Ieee80211ScalarRadioMedium{
        //}*/
        
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=125,240;is=s");
        }     

        // application layer
        app: MyApp {
            nodeIndex = nodeID;
            @display("p=120,30;t=Application\nLayer,l");
        }

        // Forwarding layer
        wlan: Ieee80211Interface {
            parameters:
                @display("p=226,81;q=queue");
                mgmt.typename = default("Ieee80211MgmtAdhoc");
                agent.typename = default("");
                opMode = "b";
        }

        // mobility
        mobility: StationaryMobility {
            @display("p=100,100;is=s");
        }

    connections allowunconnected:
        
        app.in <-- wlan.upperLayerOut;
        app.out --> wlan.upperLayerIn;
        wlan.radioIn<--in;
}