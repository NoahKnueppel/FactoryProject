#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccounts {
  public:
  
   
    static BankAccounts *make_bankaccounts(string choice);
  
    virtual void io() = 0;
    
   
    virtual ~BankAccounts() = default;
};

class Angie: public BankAccounts {
  public:
    void io() {
        cout << "Angie - Grocery store clerk, $233\n";
    }
};

class Dave: public BankAccounts {
  public:
    void io() {
        cout << "Dave - IT specialist, $1.6b\n";
    }
};

class Jared: public BankAccounts {
  public:
    void io() {
        cout << "Jared - Professional poker player, $1,673\n";
    }
};

class Katie: public BankAccounts {
  public:
    void io() {
        cout << "Katie - Mcdonalds manager, $532\n";
    }
};

class Daniel: public BankAccounts {
  public:
    void io() {
        cout << "Daniel - gas station attendant, $748\n";
    }
};

class Jack: public BankAccounts {
  public:
    void io() {
        cout << "Jack - Factory worker, $2,892\n";
    }
};

class Marcus: public BankAccounts {
  public:
    void io() {
        cout << "Marcus - Plumber, $18,392\n";
    }
};

class Mark: public BankAccounts {
  public:
    void io() {
        cout << "Mark - Professor, -$15,298\n";
    }
};


BankAccounts *BankAccounts::make_bankaccounts(string choice) {
  if (choice ==  "Angie")
    return new Angie;
  else if (choice == "Dave")
    return new Dave;
  else if (choice == "Jared")
    return new Jared;
  else if (choice == "Daniel")
    return new Daniel;
  else if (choice == "Jack")
    return new Jack;
  else if (choice == "Marcus")
    return new Marcus;
  else if (choice == "Katie")
    return new Katie;  
  else
    return new Mark;
}




int main() {
  vector<BankAccounts*> products;
  string choice;
  while (true) {
    cout << "Enter the name of the bank account you wish to access.  If you are done, enter 0 instead: ";
    cin >> choice;
    if (choice == "0") break;
    products.push_back(BankAccounts::make_bankaccounts(choice));
  }
  for (int i = 0; i < products.size(); i++) {
    products[i]->io();
  }
  for (int i = 0; i < products.size(); i++) {
    delete products[i];
  }
}