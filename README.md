# Developed-a-Class-Based-Ride-Sharing-System

Ride Sharing System in C++
**Overview**
In this project, I have developed a Ride Sharing System using Object-Oriented Programming (OOP) principles. The system includes classes for rides, drivers, and riders, demonstrating key OOP concepts such as encapsulation, inheritance, and polymorphism.

**Key Features**
Ride Class: A base class that holds core details such as rideID, pickupLocation, dropoffLocation, distance, and fare. It also has methods to calculate the fare based on distance and to display ride details.

StandardRide and PremiumRide Classes: These derived classes implement ride types with different fare calculations, showcasing inheritance and polymorphism by overriding the calculateFare() method.

Driver Class: This class contains information about the driver, such as driverID, name, rating, and assignedRides. It has methods to assign rides to drivers and display driver details.

Rider Class: This class stores information about the rider, such as riderID, name, and the list of requested rides. It includes methods to request a ride and view ride history.

**OOP Principles Used**
Encapsulation: I used encapsulation to protect the internal state of the classes (assignedRides in Driver class and requestedRides in Rider class) and provide access through methods.

Inheritance: The StandardRide and PremiumRide classes inherit from the base Ride class, allowing for shared functionality and code reuse.

Polymorphism: Polymorphism is demonstrated by the ability to call the overridden calculateFare() method for different ride types, allowing dynamic dispatch based on the ride type (standard or premium).

**How to Run To run this code:**

Copy the contents into an online C++ compiler or your local C++ IDE.

Compile and run the program.

The system will display information about rides, drivers, and riders, along with their assigned rides and requested rides.

**Technologies Used**

C++: For object-oriented design and implementation of the Ride Sharing System.

**Installation**
Download or clone the repository to your local machine.

Open the .cpp file in a C++ IDE like Visual Studio, Code::Blocks, or an online compiler.

Compile and run the program to test its functionality.
