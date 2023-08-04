#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void inputFile(ifstream& file, const string& type) {
	string filename;
	cout << "Please enter a filename for " << type << " database: ";
	cin >> filename;
	file.open(filename.c_str());

	while (file.fail()) {
		cout << "cannot open " << type << "s database file" << endl;
		cout << "Please enter a filename for " << type << " database: ";
		cin >> filename;
		file.open(filename.c_str());
	}
}

//this functions aim is control every char of given string whether is digit or not, built-in isdigit function takes char as parameter 
bool isDigit(const string& s) {
	int size = s.length();

	//controls every single character of string and if one of them are not digit character returns false immediately
	for (int i = 0; i < size; i++) {
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

//function returns true if time input is in correct format or not, this function will be used in inputTime function (hh:mm)
bool isTimeCorrectFormatted(const string& userTime) {
	if (userTime.length() == 5 && userTime.substr(0, 2) <= "23" && userTime.substr(0, 2) >= "00"
		&& userTime.substr(2, 1) == ":" && userTime.substr(3) >= "00" && userTime.substr(3) <= "59" && isDigit(userTime.substr(0, 2)) && isDigit(userTime.substr(3))) {
		return true;
	}
	return false;
}

//this function takes time time info from user as hh:mm format and asks user until user enter hour with correct format and flags an error mesage
void inputTime(string& userTime) {
	cout << "Please enter start time of travel: ";
	cin >> userTime;
	while (!isTimeCorrectFormatted(userTime)) {
		cout << "Time is not in correct format" << endl;
		cout << "Please enter start time of travel: ";
		cin >> userTime;
	}
}

void addRoutesToLibrary(ifstream& file, vector<string>& numbers, vector<string>& routes, const string& departure_city) {
	string line, word;
	while (getline(file, line)) {
		istringstream input(line);
		vector<string> temp;
		while (input >> word) {
			temp.push_back((word));
		}
		if (temp[1] == departure_city){
			string route = temp[1] + " " + temp[2];
			numbers.push_back(temp[0]);
			routes.push_back(route);
		}
	}
	file.clear();
	file.seekg(0);
}

void displayRoutes(ifstream& file, const vector<string>& numbers, const vector<string>& routes, const string& departure_time) {
	cout << "The search results are:" << endl;
	int i, size = numbers.size();
	for (i = 0; i < size; i++) {
		string line, word;
		while (getline(file, line)){
			istringstream input(line);
			vector<string> temp;
			while (input >> word) {
				temp.push_back(word);
			}
			string number = temp[0];
			string time = temp[1];
			
			if (numbers[i] == number && departure_time <= time) {
				cout << routes[i] << " " << time << endl;
			}	
		}
		file.clear();
		file.seekg(0);
	}
}

int main() {
	ifstream routes_file, times_file;

	inputFile(routes_file, "route");
	inputFile(times_file, "time");

	string departure_city, user_time;
	while (true) {
		vector<string> numbers;
		vector<string> departure_arrival;
		cout << "Please enter departure location: ";
		cin >> departure_city;
		if (departure_city == "EXIT")
			break;
		
		addRoutesToLibrary(routes_file, numbers, departure_arrival, departure_city);
		inputTime(user_time);
		displayRoutes(times_file, numbers, departure_arrival, user_time);
		
	}
	return 1;
}