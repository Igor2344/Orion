#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//first 5 things are column names, rest are entries for each column, 5 things each

void csvToHtml(string ifilename, string ofilename) {
	ifstream fin;
	fin.open(ifilename);

	if (!fin.is_open()) {
		cout << "Error opening " << ifilename << endl;
	}
	// read 5 words at a time with fin >> word
	// might need fin.ignore();

	ofstream fout;
	fout.open(ofilename);

	vector<string> row;
	string line;
	string word;
	if (!fout.is_open()) {
		cout << "Error opening " << ofilename << endl;
	}
	//write 5 words per line into html file with concatenated extra goodies
	fout << "<html>\n\t<body>\n\t\t<table>\n\t\t\t";
	row.clear();
	getline(fin, line);
	stringstream s(line);
	while (getline(s, word, ',')) {
		row.push_back(word);
	}
	fout << "<tr>";
	for (unsigned i = 0; i < row.size(); i++) {
		fout << "<th>"<< row[i] << "</th>";
	}
	fout << "</tr>";
	for (unsigned i = 0; i < 18; i++) {
		fout << "\n\t\t\t<tr>";
		row.clear();
		getline(fin, line);
		stringstream s(line);
		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		for (unsigned j = 0; j < row.size(); j++) {
			fout << "<td>" << row[j] << "</td>";
		}
		fout << "</tr>";
	}
	fout << "\n\t\t</table>\n\t</body>\n</html>";
	fout.close();
}

int main(){
	string ifi = "csv_to_html_res.csv";
	string ofi = "Solu.html";
	csvToHtml(ifi, ofi);
}