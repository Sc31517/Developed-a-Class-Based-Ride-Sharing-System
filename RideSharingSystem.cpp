#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class Ride
class Ride {
protected:
    string rideID;
    string pickupLocation;
    string dropoffLocation;
    float distance;
    float fare;

public:
    Ride(string id, string pickup, string dropoff, float dist) 
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}

    virtual float calculateFare() {
        fare = distance * 2.0;  // Base fare: $2 per mile
        return fare;
    }

    virtual void rideDetails() {
        cout << "Ride ID: " << rideID << endl;
        cout << "Pickup Location: " << pickupLocation << endl;
        cout << "Dropoff Location: " << dropoffLocation << endl;
        cout << "Distance: " << distance << " miles" << endl;
        cout << "Fare: $" << fare << endl;
    }
};

// Derived class StandardRide
class StandardRide : public Ride {
public:
    StandardRide(string id, string pickup, string dropoff, float dist)
        : Ride(id, pickup, dropoff, dist) {}

    float calculateFare() override {
        fare = distance * 1.5;  // Discounted fare for standard rides: $1.5 per mile
        return fare;
    }

    void rideDetails() override {
        cout << "Standard Ride:" << endl;
        Ride::rideDetails();
    }
};

// Derived class PremiumRide
class PremiumRide : public Ride {
public:
    PremiumRide(string id, string pickup, string dropoff, float dist)
        : Ride(id, pickup, dropoff, dist) {}

    float calculateFare() override {
        fare = distance * 3.0;  // Premium fare: $3 per mile
        return fare;
    }

    void rideDetails() override {
        cout << "Premium Ride:" << endl;
        Ride::rideDetails();
    }
};

// Driver class
class Driver {
private:
    string driverID;
    string name;
    vector<Ride*> assignedRides;

public:
    Driver(string id, string n) : driverID(id), name(n) {}

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() {
        cout << "Driver ID: " << driverID << endl;
        cout << "Driver Name: " << name << endl;
        cout << "Assigned Rides: " << assignedRides.size() << endl;
    }

    void viewRides() {
        cout << "Rides assigned to driver " << name << ":" << endl;
        for (auto ride : assignedRides) {
            ride->rideDetails();
        }
    }
};

// Rider class
class Rider {
private:
    string riderID;
    string name;
    vector<Ride*> requestedRides;

public:
    Rider(string id, string n) : riderID(id), name(n) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() {
        cout << "Rides requested by " << name << ":" << endl;
        for (auto ride : requestedRides) {
            ride->rideDetails();
        }
    }
};

int main() {
    // Create some rides
    Ride* ride1 = new StandardRide("001", "Location A", "Location B", 10);
    Ride* ride2 = new PremiumRide("002", "Location C", "Location D", 5);

    // Calculate the fare for both rides
    ride1->calculateFare();
    ride2->calculateFare();

    // Create a driver and assign rides
    Driver driver1("D001", "John");
    driver1.addRide(ride1);
    driver1.addRide(ride2);

    // Create a rider and request rides
    Rider rider1("R001", "Alice");
    rider1.requestRide(ride1);

    // Display information
    driver1.getDriverInfo();
    driver1.viewRides();

    rider1.viewRides();

    // Cleanup memory
    delete ride1;
    delete ride2;

    return 0;
}
