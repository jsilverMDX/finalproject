#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

int main() {

  ifstream infile("contacts.txt");
  string line;
  while (getline(infile, line)) {
    cout << line << std::endl;
  }

  cout << "Press Enter to Continue";
  cin.ignore();

  return 0;
}