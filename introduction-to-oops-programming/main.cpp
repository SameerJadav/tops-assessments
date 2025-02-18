#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// Class representing an event
class Event {
private:
  string event_name, customer_name;
  unsigned int guests, event_mins;

  const double COST_PER_HOUR = 18.50;
  const double COST_PER_MINUTE = 0.40;
  const double COST_OF_DINNER = 20.70;

public:
  // Constructor to initialize the event
  Event(string e_name, string c_name, unsigned int e_guests,
        unsigned int e_mins) {
    event_name = e_name;
    customer_name = c_name;
    guests = e_guests;
    event_mins = e_mins;
  }

  /* Note: Using constant member function; meaning it won't change the state of
   * the object */

  // Calculate the number of servers needed.
  unsigned int servers() const { return ceil(guests / 20.0); }

  // Calculate the cost of servers
  double server_cost() const {
    double cost_per_hour = (event_mins / 60) * COST_PER_HOUR;
    double cost_per_minute = (event_mins % 60) * COST_PER_MINUTE;
    return cost_per_hour + cost_per_minute;
  }

  // Calculate the total food cost
  double total_food_cost() const { return guests * COST_OF_DINNER; }

  // Calculate the average cost per person for food
  double average_cost_per_person() const { return total_food_cost() / guests; }

  // Calculate the total event cost
  double total_cost() const {
    return total_food_cost() + (server_cost() * servers());
  }

  // Calculate the deposit amount required
  double deposit_amount() const { return total_cost() * 0.25; }

  // Display the event estimate
  void display() const {
    cout << "========== Event estimate for: " << customer_name
         << " ==========\n\n";

    cout << "Number of servers: " << servers() << endl;
    cout << "The cost of servers: " << server_cost() << endl;
    cout << "The cost of food is: " << total_food_cost() << endl;
    cout << "Average cost per person: " << average_cost_per_person() << endl
         << endl;
    cout << "Total cost is: " << total_cost() << endl << endl;
    cout << "Please deposit a 25% deposit to reserve the event\n";
    cout << "The deposit needed is: " << deposit_amount() << endl;
  }
};

int main() {
  cout << "********** Event Management System **********\n\n";

  string event_name;
  cout << "Enter the name of the event: ";
  getline(cin >> ws, event_name);

  string customer_name;
  cout << "Enter customer's first and last name: ";
  getline(cin >> ws, customer_name);

  unsigned int guests;
  cout << "Enter the number of guests: ";
  cin >> guests;

  unsigned int event_mins;
  cout << "Enter the number of minutes of the event: ";
  cin >> event_mins;
  cout << endl;

  // Create an Event object
  Event event(event_name, customer_name, guests, event_mins);

  // Display the event estimate
  event.display();

  return 0;
}
