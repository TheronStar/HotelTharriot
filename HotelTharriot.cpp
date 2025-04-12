#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Room {
    public:
        int number;
        vector<string> occupants;
    Room(int n){
        number = n;
    }
    int getNumber() { return number; }
    vector<string> getOccupants() { return occupants; }
    void setNumber(int n) { number = n; }
    void setOccupants(vector<string> o) { occupants = o; }
    void addOccupant(string o) { occupants.push_back(o); }
    void removeOccupant(string o) {
        occupants.erase(find(occupants.begin(),occupants.end(),o));
    }
};



int main()
{
    cout << "🙤 HOTEL THARRIOT TERMINAL 🙦\n" << endl;
    string choice;
    bool a;
    bool b;
    
    //Create Hotel Layout
    vector<Room> hotel = {
        Room(1),Room(2),Room(3),Room(4),Room(5),Room(6),
        Room(11),Room(12),Room(13),Room(14),Room(15),Room(16),
        Room(21),Room(22),Room(23),Room(24),Room(25),Room(26)
    };
    hotel[6].setOccupants(vector<string>{"Constantine"});
    hotel[3].setOccupants(vector<string>{"Mary","Jamie"});
    hotel[10].setOccupants(vector<string>{"Eric"});
    
    //Command Loop
    while (true) {
        cout << "Input Command:\n- view\n- add\n- remove\n- clear\n- move\n- exit\n";
        cin >> choice;
        
        if (choice == "view") {
            for (int i = 0; i < hotel.size(); i++) {
                cout << "[" << hotel[i].getNumber() << "]";
                for (int x = 0; x < hotel[i].getOccupants().size(); x++) {
                    cout << " (" << hotel[i].getOccupants()[x] << ")";
                }
                cout << "\n";
            }
        }
        else if (choice == "add") {
            cout << "Select Room Number:";
            cin >> choice;
            cout << "\n";
            b = false;
            for (int i = 0; i < hotel.size(); i++) {
                if (hotel[i].getNumber() == stoi(choice)) {
                    b = true;
                    cout << "Enter Occupant Name:";
                    cin >> choice;
                    hotel[i].addOccupant(choice);
                    cout << "\n";
                    break;
                }
            }
            if (b == false) {
                cout << "Room Not Found\n";
            }
        }
        else if (choice == "remove") {
            cout << "Select Room Number:";
            cin >> choice;
            cout << "\n";
            b = false;
            for (int i = 0; i < hotel.size(); i++) {
                if (hotel[i].getNumber() == stoi(choice)) {
                    b = true;
                    cout << "Enter Occupant Name:";
                    cin >> choice;
                    hotel[i].removeOccupant(choice);
                    cout << "\n";
                    break;
                }
            }
            if (b == false) {
                cout << "Room Not Found\n";
            }
        }
        else if (choice == "clear") {
            cout << "Select Room Number:";
            cin >> choice;
            cout << "\n";
            b = false;
            for (int i = 0; i < hotel.size(); i++) {
                if (hotel[i].getNumber() == stoi(choice)) {
                    b = true;
                    hotel[i].setOccupants(vector<string>{});
                    break;
                }
            }
            if (b == false) {
                cout << "Room Not Found\n";
            }
        }
        else if (choice == "move") {
            cout << "Select Room Number:";
            cin >> choice;
            cout << "\n";
            a = false;
            b = false;
            for (int i = 0; i < hotel.size(); i++) {
                if (hotel[i].getNumber() == stoi(choice)) {
                    cout << "Select New Room Number:";
                    cin >> choice;
                    cout << "\n";
                    b = true;
                    for (int ii = 0; ii < hotel.size(); ii++) {
                        if (hotel[ii].getNumber() == stoi(choice)) {
                            a = true;
                            hotel[ii].setOccupants(hotel[i].getOccupants());
                            hotel[i].setOccupants(vector<string>{});
                            break;
                        }
                    }
                    break;
                }
            }
            if (b == false || a == false) {
                cout << "Room Not Found\n";
            }
        }
        else if (choice == "exit") {
            break;
        }
        else {
            cout << "Command Not Recognized\n";
        }
    }
}








