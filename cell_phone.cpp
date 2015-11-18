// (Fake) Cell Phone Device Emulator™
// jsilverMDX ("Jonathan Silverman")
#include "cell_phone.h"

vector<Contact> contact_list;

vector<TextMessage> text_messages;

string MY_PHONE_NUMBER = "4242309994";

string RINGTONES[5] = { "Whiney", "HighlyAnnoyingSound", "TooMuchBeeping", "EardumBlower", "BansheeHowl"};

string ringtone = RINGTONES[0];

void show_contact_list() {
  ifstream infile("contacts.txt");
  string line;
  while (getline(infile, line)) {
    cout << line << endl;
  }
}

int main_menu() {
  int choice;
  cout << "1. Contacts" << endl;
  cout << "2. Call" << endl;
  cout << "3. Send Text" << endl;
  cout << "4. Change Ringtone" << endl;
  cout << "5. Exit" << endl;
  cin >> choice;
  return choice;
}

void show_call_screen() {
  string to;
  cout << "Enter phone number to call: ";
  cin >> to;
  Call active_call(MY_PHONE_NUMBER, to);
}

void show_text_screen() {
  string to;
  cout << "Enter phone number to text: ";
  cin >> to;
  string message;
  cout << "Enter message: ";
  cin >> message;
  TextMessage text_message(MY_PHONE_NUMBER, to, message);
  text_message.send();
  text_messages.push_back(text_message);
}

void show_change_ringtone() {
  cout << "Ringtones" << endl;
  for(int i = 0; i < RINGTONES->size(); i++) {
    cout << i << ". " << RINGTONES[i] << endl;
  }
  int choice;
  cout << "Input choice: ";
  cin >> choice;
  ringtone = RINGTONES[choice];
}

int main() {


  while(true){
    int choice = main_menu();

    if(choice==1){
      show_contact_list();
    }else if(choice==2){
      show_call_screen();
    }else if(choice==3){
      show_text_screen();
    }else if(choice==4){
      show_change_ringtone();
    }else if(choice==5) {
      break;
    }
  }

  return 0;
}