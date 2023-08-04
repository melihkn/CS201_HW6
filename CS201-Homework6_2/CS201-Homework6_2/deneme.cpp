//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//
//using namespace std;
//
//struct info {
//    int id;
//    string location;
//    string departure;
//    vector<string> times;
//};
//
//vector<info> open_close() {
//    vector<info> data;
//    ifstream input;
//    do {
//        string filename;
//        cout << "Please enter a filename for route database: ";
//        cin >> filename;
//        input.open(filename.c_str());
//        if (input.fail()) {
//            cout << "cannot open routes database file" << endl;
//        }
//    } while (input.fail());
//    string line_routes;
//    while (getline(input, line_routes)) {
//        info x;
//        istringstream lineStream(line_routes);
//        lineStream >> x.id >> x.location >> x.departure;
//        data.push_back(x);
//    }
//    input.close();
//    do {
//        string filename;
//        cout << "Please enter a filename for time database: ";
//        cin >> filename;
//        input.open(filename.c_str());
//        if (input.fail()) {
//            cout << "cannot open times database file" << endl;
//        }
//    } while (input.fail());
//    string line_times;
//    while (getline(input, line_times)) {
//        int id;
//        string time;
//        istringstream lineStream(line_times);
//        lineStream >> id >> time;
//        for (unsigned int index = 0; index < data.size(); index++) {
//            if (data[index].id == id) {
//                data[index].times.push_back(time);
//            }
//        }
//    }
//    input.close();
//    return data;
//}
//
//bool time_check(string start_time) {
//    if (start_time.size() != 5 || start_time.find(":") != 2) {
//        return false;
//    }
//    else {
//        string sub1 = start_time.substr(0, 2);
//        string sub2 = start_time.substr(3, 2);
//        if (sub1 >= "00" && sub1 <= "23") {
//            if (sub2 >= "00" && sub1 <= "60") {
//                return true;
//            }
//            else {
//                return false;
//            }
//        }
//        else {
//            return false;
//        }
//    }
//}
//
//
//int main() {
//    vector<info> data = open_close();
//    string location;
//    string start_time;
//    do {
//        cout << "Please enter departure location: ";
//        cin >> location;
//        do {
//            cout << "Please enter start time of travel: ";
//            cin >> start_time;
//            if (time_check(start_time) != true) {
//                cout << "Time is not in correct format" << endl;
//            }
//        } while (time_check(start_time) != true);
//        cout << "The search results are: " << endl;
//        for (unsigned int index = 0; index < data.size(); index++) {
//            if (data[index].location == location) {
//                for (unsigned int index2 = 0; index < data[index].times.size(); index2++) {
//                    string sub1 = start_time.substr(0, 2);
//                    string sub2 = start_time.substr(3, 2);
//                    if (sub1 < data[index].times[index2].substr(0, 2)) {
//                        cout << data[index].location << " " << data[index].departure << " " << data[index].times[index2];
//                    }
//                    else if (sub1 == data[index].times[index2].substr(0, 2)) {
//                        if (sub2 < data[index].times[index2].substr(3, 2)) {
//                            cout << data[index].location << " " << data[index].departure << " " << data[index].times[index2];
//                        }
//                    }
//                }
//            }
//        }
//    } while (location != "EXIT");
//
//    return  - 1;
//}