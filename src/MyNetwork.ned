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
// TODO auto-generated type
//

import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;

network MyNetwork
{
    submodules:

        radioMedium: Ieee80211ScalarRadioMedium {
            parameters:
                @display("p=50,50");//<x,y>
        }

        host0: MyNode {
            nodeID = 0;
            @display("i=device/pocketpc_s;r=,,#707070;p=270,351");
        }

        host1: MyNode {
            nodeID = 1;
            @display("i=device/pocketpc_s;r=,,#707070;p=160,279");
        }

        host2: MyNode {
            nodeID = 2;
            @display("i=device/pocketpc_s;r=,,#707070;p=170,352");
        }
        
        host3: MyNode {
            nodeID = 3;
            @display("i=device/pocketpc_s;r=,,#707070;p=137,210");
        }
        
        host4: MyNode {
            nodeID = 4;
            @display("i=device/pocketpc_s;r=,,#707070;p=50,229");
        }
}
