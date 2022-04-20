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

simple MyApp
{
     parameters:

        int nodeIndex;
        
		@signal[neighbourNum](type = long);
		
		//@statistic[neighbourNum](title="Number of neighbours"; source=count(neighbourNum);record = count,"vector";); 
        
        @statistic[neighbourNum](title="Number of neighbours"; source=neighbourNum;record = vector;); 
        
    gates:
        
		input in @labels(Ieee802Ctrl/up);
		
		output out @labels(Ieee802Ctrl/down);
}
