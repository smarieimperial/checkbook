#include <iostream>
#include <iomanip>
#include <string>
#include "Checkbook.h"

using namespace std;

struct MyCheck {
  float amt;
  int checkNum;
  string checkComment;
  bool operator>(float bal) { if(amt > bal) return true; else return false; }
};

void operator-=(float &bal, MyCheck ch) { bal-=ch.amt; }

int main()
{
    Checkbook<float> jCheckbook;
    Checkbook<MyCheck> sCheckbook;
    MyCheck sCheck;
    float amount;
    bool jCheckAccepted = false, sCheckAccepted = false;

    jCheckbook.setBalance(1000);
    sCheckbook.setBalance(2000);

    cout << "John, your balance is $1,000.00 " << endl;
    cout << "Susan, your balance is $2,000.00 " << endl;

    cout << "John, enter your check amount: $";
    cin >> amount;
    if(jCheckbook.writeCheck(amount)) {
      cout << "Your check was accepted." << endl;
      jCheckAccepted = true;
    }
    else
      cout << "Your balance was not high enough to cover the check." << endl;

    cout << "Susan, enter the check number for your check: ";
    cin >> sCheck.checkNum;
    cin.ignore();
    cout << "Please also enter any comment you wish to make about the check: " << endl;
    getline(cin, sCheck.checkComment);
    cout << "Susan, enter your check amount $";
    cin >> sCheck.amt;
    if(sCheckbook.writeCheck(sCheck)) {
      cout << "Your check was accepted." << endl;
      sCheckAccepted = true;
    }
    else
      cout << "Your balance was not high enough to cover the check." << endl;

    cout << fixed << showpoint << setprecision(2);
    cout << "J, your balance is: $" << jCheckbook.getBalance() << endl;
    if(jCheckAccepted)
      cout << "Your last check amount is: $" <<
      jCheckbook.getLastCheck() << endl;

    cout << "S, your balance is: $" << sCheckbook.getBalance() << endl;
    if(sCheckAccepted) {
      MyCheck testSCheck;
      testSCheck = sCheckbook.getLastCheck();
      cout << "Your last check amount was: $" << testSCheck.amt << endl;
      cout << "for check number: " << testSCheck.checkNum << endl;
      cout << "with check comment: " << testSCheck.checkComment << endl;
    }

    return 0;
}
