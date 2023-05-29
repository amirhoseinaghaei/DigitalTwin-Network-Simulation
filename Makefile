CXX = g++
CXXFLAGS = -std=c++2a -Wall -c 
LXXFLAGS = -std=c++2a
OBJECTS = main.o PhysicalSystem.o Mobile_Device.o Smart_Vehicle.o Base_station.o Digital_Twin.o PS_BS_Connection.o PS_ES_Channel.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET) -lpthread
main.o: main.cpp Edge_Nodes/PhysicalSystem.h Edge_Nodes/Mobile_Device.h Edge_Nodes/Smart_Vehicle.h Base_Stations/Base_station.h Digital_Twins/Digital_Twin.h Application/Business/PS_BS_Connection.cpp
	$(CXX) $(CXXFLAGS) main.cpp
PhysicalSystem.o: Edge_Nodes/PhysicalSystem.cpp
	$(CXX) $(CXXFLAGS) Edge_Nodes/PhysicalSystem.cpp
Mobile_Device.o: Edge_Nodes/Mobile_Device.cpp Edge_Nodes/PhysicalSystem.h
	$(CXX) $(CXXFLAGS) Edge_Nodes/Mobile_Device.cpp
Smart_Vehicle.o: Edge_Nodes/Smart_Vehicle.cpp Edge_Nodes/PhysicalSystem.h
	$(CXX) $(CXXFLAGS) Edge_Nodes/Smart_Vehicle.cpp
Base_station.o: Base_Stations/Base_station.cpp
	$(CXX) $(CXXFLAGS) Base_Stations/Base_station.cpp
Digital_Twin.o: Digital_Twins/Digital_Twin.cpp
	$(CXX) $(CXXFLAGS) Digital_Twins/Digital_Twin.cpp
PS_BS_Connection.o: Application/Business/PS_BS_Connection.cpp
	$(CXX) $(CXXFLAGS) Application/Business/PS_BS_Connection.cpp
PS_ES_Channel.o: Communication_Channels/PS_ES_Channel.cpp Communication_Channels/PS_ES_Channel.h
	$(CXX) $(CXXFLAGS) Communication_Channels/PS_ES_Channel.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
