#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <curses.h>

using namespace std;

int might_not_be_used = 1;

class Contact {
string phone_number;
string name;
public:
  Contact(string p, string n);
};

Contact::Contact(string p, string n) {
  phone_number = p;
  name = n;
}


class Call {
  string phone_number_to;
  string phone_number_from;
  bool active;
  // int duration; // in seconds
public:
  Call(string f, string t);
  void hangup();
};

Call::Call(string f, string t) {
  phone_number_from = f;
  phone_number_to = t;
  active = true;
  char c;
  cout << "Called " << phone_number_to << endl;
}

void Call::hangup() {
  active = false;
  // eventually disable some kind of timer (and be in a thread)
}


class TextMessage {
  string phone_number_to;
  string phone_number_from;
  string message;
  bool sent;
public:
  TextMessage(string f, string t, string m);
  void send();
};

TextMessage::TextMessage(string f, string t, string m){
  phone_number_from = f;
  phone_number_to = t;
  message = m;
}

void TextMessage::send() {
  sent = true; // fake sending, nothing happens
}


vector<Contact> contact_list;

vector<TextMessage> text_messages;

string MY_PHONE_NUMBER = "4242309994";

string RINGTONES[5] = { "Whiney", "HighlyAnnoyingSound", "TooMuchBeeping", "EardumBlower", "BansheeHowl"};

string ringtone = RINGTONES[0];