#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void execute(const string& cmd, map<string, vector<string>>& buses_stops, map<string, vector<string>>& stops_buses) {
    if (cmd == "ALL_BUSES") {
        if (buses_stops.size() == 0) {
            cout << "No buses" << endl;
            return;
        }

        for (auto bus_route : buses_stops) {
            cout << "Bus " << bus_route.first << ": ";
            for(auto stop : bus_route.second) {
                cout << stop << " ";
            }
            cout << endl;
        }
        return;
    }

    if (cmd == "BUSES_FOR_STOP") {
        string stop1;
        cin >> stop1;
        if (stops_buses[stop1].size() == 0) {
            cout << "No stop" << endl;
            stops_buses.erase(stop1);
            return;
        }

        for(auto bus : stops_buses[stop1]) {
            cout << bus << " ";
        }
        cout << endl;
        return;
    }

    if (cmd == "STOPS_FOR_BUS") {
        string bus1;
        cin >> bus1;        
        if (buses_stops[bus1].size() == 0) {
            cout << "No bus" << endl;
            buses_stops.erase(bus1);
            return;
        }
        for(auto stop : buses_stops[bus1]) {
            cout << "Stop " << stop << ": ";
            if(stops_buses[stop].size() == 1) {
                cout << "no interchange" << endl;
            } else {
                for(auto buss: stops_buses[stop]) {
                    if (buss != bus1) {
                        cout << buss << " ";
                    }
                }
            }    
            cout << endl;
        }
        return;
    }

    if(cmd == "NEW_BUS") {
        string bus;
        cin >> bus;
        int stop_count;
        cin >> stop_count;
        string stopp;
        for(int i = 0; i < stop_count; i++) {
            cin >> stopp;
            buses_stops[bus].push_back(stopp);
            stops_buses[stopp].push_back(bus);
        }   

    }
}

int main() {
    int Q;
    cin >> Q;
    string cmd;
    map<string, vector<string>> buses_stops;
    map<string, vector<string>> stops_buses;
    for(int i = 0; i < Q; i++) {
        cin >> cmd;
        execute(cmd, buses_stops, stops_buses);
    }   
    return 0;
}