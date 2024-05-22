#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

// Error handling class
class ErrorHandling
{
private:
    int lettersCount;
    int digitsCount;
    bool spaceEncountered;

public:
   
    bool phoneValidation(string input)
    {
        if (input.empty())
        {
            return false;
        }
        if (input[0] != '0')
        {
            return false;
        }

        if (input.size() > 1 && input[1] != '3')
        {
            return false;
        }

        for (int i = 0; i < input.size(); ++i)
        {
            if (!isdigit(input[i]) && input[i] == ' ')
            {
                return false;
            }
        }
        if (input.size() == 11)
        {
            return true;
        }
        return false;
    }
    bool plateNoValidation(string plateNo)
    {
        if (plateNo.empty())
        {
            return false;
        }

        lettersCount = 0;
        digitsCount = 0;
        spaceEncountered = false;

        //  for (int i = 0; i < plateNo.size(); i++)
        // {
        //     plateNo[i] = toupper(plateNo[i]);
        // }
        for (int i = 0; i < plateNo.size(); i++)
        {
            if (isalpha(plateNo[i]))
            {
                lettersCount++;
            }
            else if (isdigit(plateNo[i]))
            {
                digitsCount++;
            }
            else if (plateNo[i] == ' ')
            {
                if (spaceEncountered || lettersCount < 2 || lettersCount > 6)
                {
                    return false;
                }
                spaceEncountered = true;
            }
            else
            {
                return false;
            }
        }

        if (!spaceEncountered || lettersCount < 2 || lettersCount > 6 || digitsCount < 3 || digitsCount > 4)
        {
            return false;
        }

        return true;
    }

    bool hoursValidation(string idString)
    {
        for (int i = 0; i < idString.size(); ++i)
        {
            if (!isdigit(idString[i]))
            {
                return false;
            }
        }
        if (idString.empty())
        {
            return false;
        }
        for (int i = 0; i < idString.size(); ++i)
        {
            if (idString[i] == ' ')
            {
                return false;
            }
        }
        if (stoi(idString) <= 24 && stoi(idString) >= 1)
        {
            return true;
        }
        return false;
    }
    bool daysValidation(string days)
    {
        for (int i = 0; i < days.size(); ++i)
        {
            if (!isdigit(days[i]))
            {
                return false;
            }
        }
        if (days.empty())
        {
            return false;
        }
        for (int i = 0; i < days.size(); ++i)
        {
            if (days[i] == ' ')
            {
                return false;
            }
        }
        if (stoi(days) <= 31 && stoi(days) >= 1)
        {
            return true;
        }
        return false;
    }
    bool menuChoice(string choice)
    {
        for (int i = 0; i < choice.size(); ++i)
        {
            if (!isdigit(choice[i]))
            {
                return false;
            }
        }
        if (choice.empty())
        {
            return false;
        }
        for (int i = 0; i < choice.size(); ++i)
        {
            if (choice[i] == ' ')
            {
                return false;
            }
        }
        return true;
    }
    bool amountValid(string amount)
    {
        for (int i = 0; i < amount.size(); ++i)
        {
            if (!isdigit(amount[i]))
            {
                return false;
            }
        }
        if (amount.empty())
        {
            return false;
        }
        for (int i = 0; i < amount.size(); ++i)
        {
            if (amount[i] == ' ')
            {
                return false;
            }
        }
        return true;
    }
    bool tokenValid(string token)
    {
        if (token.empty())
        {
            return false;
        }
        for (int i = 0; i < token.size(); ++i)
        {
            if (!isdigit(token[i]) && token[i] == ' ')
            {
                return false;
            }
        }
        if (token.size() == 6)
        {
            return true;
        }
        return false;
    }

    bool nameValid(string name)
    {
        if (name.empty())
        {
            return false;
        }
        return true;
    }
};

// Vehicels class with Error handling inheritance -->Single inheritance
class Vehicle : public ErrorHandling
{
protected:
    string cellNo;
    string plateNo;
    int days;
    int hours;
    string parkingType;
    time_t parkingStartTime; // Store the parking start time

public:
    Vehicle() {}
    Vehicle(string cellNo, string plateNo, int days, int hours, string parkingType)
        : cellNo(cellNo), plateNo(plateNo), days(days), hours(hours), parkingType(parkingType)
    {
        time(&parkingStartTime); // Initialize parking start time
    }

    void parkVehicle(string parkedPlateNumbers[], int &plateCount, int capacity)
    {
        while (true)
        {
            cout << "\n\t\t ______________________________________________\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t| [1]   |     Park Per Hour" << setw(22) << "|\n";
            cout << "\t\t| [2]   |     Park Per Day" << setw(23) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|_______|______________________________________|\n";
            while (true)
            {
                cout << "\n\t\tEnter the parking type: ";
                getline(cin, parkingType);
                if (menuChoice(parkingType))
                {
                    break;
                }
                cout << "\n\t\tInvalid input!\n";
            }
            if (parkingType == "1")
            {
                while (true)
                {
                    string hourStr;
                    cout << "\n\t\tEnter the no of hours to park the Vehicle: ";
                    getline(cin, hourStr);
                    if (hoursValidation(hourStr))
                    {
                        hours = stoi(hourStr);
                        break;
                    }
                    cout << "\n\t\tInvalid hours\n";
                }
                break;
            }
            else if (parkingType == "2")
            {
                while (true)
                {
                    string dayStr;
                    cout << "\n\t\tEnter the no of days to park the Vehicle: ";
                    getline(cin, dayStr);
                    if (daysValidation(dayStr))
                    {
                        days = stoi(dayStr);
                        break;
                    }
                    cout << "\n\t\tInvalid days\n";
                }
                break;
            }
            else
            {
                system("CLS");
                cout << "\n\t\tInvalid choice!\n";
            }
        }
        while (true)
        {
            cout << "\n\t\tEnter the (11 digit) Phone Number of the Vehicle holder: ";
            getline(cin, cellNo);
            if (phoneValidation(cellNo))
            {
                break;
            }
            cout << "\n\t\tInvalid Phone no.\n";
        }
        while (true)
        {
            cout << "\n\t\tEnter the plate no of the Vehicle: ";
            getline(cin, plateNo);
            // Convert input plate number to uppercase for consistency
            for (int i = 0; i < plateNo.size(); i++)
            {
                plateNo[i] = toupper(plateNo[i]);
            }
            if (plateNoValidation(plateNo))
            {
                bool isUnique = true;
                for (int i = 0; i < plateCount; i++)
                {
                    if (parkedPlateNumbers[i] == plateNo)
                    {
                        isUnique = false;
                        break;
                    }
                }
                if (isUnique)
                {
                    parkedPlateNumbers[plateCount++] = plateNo;
                    break;
                }
                else
                {
                    cout << "\n\t\tPlate number already in use.\n";
                }
            }
            else
            {
                cout << "\n\t\tInvalid plate no.\n";
            }
        }
        time(&parkingStartTime); // Set parking start time
    }

    string getPlateNo()
    {
        return plateNo;
    }
    int getDays()
    {
        return days;
    }
    int getHours()
    {
        return hours;
    }
    string getParkingType()
    {
        return parkingType;
    }
    string getCellNo()
    {
        return cellNo;
    }
    time_t getParkingStartTime()
    {
        return parkingStartTime;
    }
};
// billcalculate inherit from vehicle calss   --> multilevel inheritance
class billCalculate : public Vehicle
{
private:
    int token;
    double fine;
    double amount;
    double totalAmount;
    double extraAmount;
    bool paymentSuccess;

public:
    billCalculate(int _token = 0, double _fine = 0.0, double _amount = 0.0, double _totalAmount = 0.0, double _extraAmount = 0.0)
        : Vehicle(), token(_token), fine(_fine), amount(_amount), totalAmount(_totalAmount), extraAmount(_extraAmount) {}

    billCalculate(int _token, string _cellNo, string _plateNo, string _parkingType, int _days, int _hours)
        : Vehicle(_cellNo, _plateNo, _days, _hours, _parkingType), token(_token), fine(0), totalAmount(0) {}
   
   
    string GetCurrentTime()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return to_string(1900 + ltm->tm_year) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    }

    void GenerateToken()
    {
        srand(time(0)); // Seed for random number generator
        token = rand() % 90000 + 100000;
    }

    int getToken()
    {
        return token;
    }

    double getAmount()
    {
        return totalAmount;
    }

    void calculateFine(string vehicleType)
    {
        time_t currentTime;
        time(&currentTime);
        double seconds = difftime(currentTime, getParkingStartTime());
        double hoursParked = ceil(seconds / 3600.0);       
        double daysParked = ceil(seconds / (24 * 3600.0)); 

        if (vehicleType == "Car")
        {
            if (parkingType == "2")
            {
                if (daysParked > days)
                {
                    fine = (daysParked - days) * 50;
                    totalAmount = daysParked * 70 + fine;
                }
                else
                {
                    totalAmount = days * 70;
                }
            }
            else if (parkingType == "1")
            {
                if (hoursParked > hours)
                {
                    fine = (hoursParked - hours) * 50;
                    totalAmount = hoursParked * 70 + fine;
                }
                else
                {
                    totalAmount = hours * 70;
                }
            }
        }
        else if (vehicleType == "Bus")
        {
            if (parkingType == "2")
            {
                if (daysParked > days)
                {
                    fine = (daysParked - days) * 70;
                    totalAmount = daysParked * 100 + fine;
                }
                else
                {
                    totalAmount = days * 100;
                }
            }
            else if (parkingType == "1")
            {
                if (hoursParked > hours)
                {
                    fine = (hoursParked - hours) * 70;
                    totalAmount = hoursParked * 100 + fine;
                }
                else
                {
                    totalAmount = hours * 100;
                }
            }
        }
        else if (vehicleType == "Bike")
        {
            if (parkingType == "2")
            {
                if (daysParked > days)
                {
                    fine = (daysParked - days) * 30;
                    totalAmount = daysParked * 50 + fine;
                }
                else
                {
                    totalAmount = days * 50;
                }
            }
            else if (parkingType == "1")
            {
                if (hoursParked > hours)
                {
                    fine = (hoursParked - hours) * 30;
                    totalAmount = hoursParked * 50 + fine;
                }
                else
                {
                    totalAmount = hours * 50;
                }
            }
        }
    }

    void displayBill(bool isParked)
    {
        system("CLS");
        cout << "\n*************** Parking Bill ***************\n";
        if (isParked)
            cout << "Time of Entry     : " << GetCurrentTime() << "\n";
        else
            cout << "Exit Time         : " << GetCurrentTime() << "\n";
        cout << "Phone Number      : " << cellNo << "\n";

        cout << "Plate Number      : " << plateNo << "\n";
        if (parkingType == "2")
            cout << "Days Parked       : " << days << " Days" << "\n";
        else if (parkingType == "1")
            cout << "Hours Parked      : " << hours << " Hours" << "\n";
        cout << "Token Number      : " << token << "\n";
        cout << "Fine Amount       : Rs." << fine << "\n";
        cout << "Total Amount      : Rs." << totalAmount << "\n";
        cout << "********************************************\n";
    }

    void AskForPayment()
    {
        string amountStr;
        while (true)
        {
            while (true)
            {
                cout << "Enter the payment amount: Rs.";
                getline(cin, amountStr);
                if (amountValid(amountStr))
                {
                    break;
                }
                cout << "Invalid amount!\n";
            }
            amount = stod(amountStr);
            if (amount >= totalAmount)
            {
                extraAmount = amount - totalAmount;
                if (extraAmount > 0)
                {
                    cout << "Thank you for Park here!\n --> Your change: Rs. " << extraAmount << "\n";
                }
                else
                {
                    cout << "Thank you for Park here!\n";
                }
                break;
            }
            else
            {
                cout << "Insufficient payment. Please enter the correct amount.\n";
            }
        }
    }
};

// class car with billcalculate inheritance   -->multiple inheritance
class Car : public billCalculate
{
public:
    void carPark(string parkedPlateNumbers[], int &plateCount, int capacity)
    {
        parkVehicle(parkedPlateNumbers, plateCount, capacity);
        GenerateToken();
        calculateFine("Car");
        displayBill(true);
    }
};

// class bus with billcalculate inheritance   -->multiple inheritance
class Bus : public billCalculate
{
public:
    void busPark(string parkedPlateNumbers[], int &plateCount, int capacity)
    {
        parkVehicle(parkedPlateNumbers, plateCount, capacity);
        GenerateToken();
        calculateFine("Bus");
        displayBill(true);
    }
};

// class bike with billcalculate inheritance  -->multiple inheritance
class Bike : public billCalculate
{
public:
    void bikePark(string parkedPlateNumbers[], int &plateCount, int capacity)
    {
        parkVehicle(parkedPlateNumbers, plateCount, capacity);
        GenerateToken();
        calculateFine("Bike");
        displayBill(true);
    }
};

// class payment record  to store paid transactions
class PaymentRecord
{
private:
    int *tokens;
    string *plateNumbers;
    double *amounts;
    bool *paid;
    int paymentsCount;
    int totalCapacity;
    double totalAmount;

public:
    PaymentRecord(){}
    PaymentRecord(int totalCap) : totalCapacity(totalCap), paymentsCount(0), totalAmount(0.0)
    {
        tokens = new int[totalCapacity];
        plateNumbers = new string[totalCapacity];
        amounts = new double[totalCapacity];
        paid = new bool[totalCapacity];
        for (int i = 0; i < totalCapacity; i++)
        {
            tokens[i] = 0;
            plateNumbers[i] = "";
            amounts[i] = 0.0;
            paid[i] = false;
        }
    }

    void recordPayment(string plate, int token, double amount)
    {
        if (paymentsCount < totalCapacity)
        {
            tokens[paymentsCount] = token;
            plateNumbers[paymentsCount] = plate;
            amounts[paymentsCount] = amount;
            paid[paymentsCount] = true;
            paymentsCount++;
            totalAmount += amount; // Update total amount
        }
        else
        {
            cout << "\n\tPaymentRecord: Cannot record payment, capacity reached.\n";
        }
    }

    void displayPayments()
    {
        system("CLS");
        if (paymentsCount == 0)
        {
            cout << "\n\t\tNo payment records found.\n";
        }
        else
        {
            cout << "\n\n\t\t\t*************** Payment Records ***************\n\n\n";
            cout << setw(10) << "Plate No" << setw(20) << "Token No" << setw(15) << "Amount" << setw(15) << "Paid\n\n";
            for (int i = 0; i < paymentsCount; ++i)
            {
                cout << setw(9) << plateNumbers[i] << setw(18) << tokens[i] << setw(15) << "Rs" << amounts[i] << setw(14);
                if (paid[i])
                {
                    cout << "Yes\n";
                }
            }
            cout << "\n******************************************************************************************************\n";
            cout << "\n\tTotal Amount: Rs" << totalAmount << "\n";
        }
    }

    void deleteAllRecords()
    {
        system("CLS");
        if (paymentsCount == 0)
        {
            cout << "\n\t\tNo payment records found to delete.\n";
        }
        else
        {
            paymentsCount = 0;
            totalAmount = 0.0;
            cout << "\n\t\tAll payment records deleted.\n";
        }
    }

    ~PaymentRecord()
    {
        delete[] tokens;
        delete[] plateNumbers;
        delete[] amounts;
        delete[] paid;
    }
};

// class parkinglot to store all information with error handing class inheritance and composition with car , bus , bike and payment record and also --> hybird inheritance
class ParkAndUnPark : public ErrorHandling
{
private:
    int carCapacity;
    int busCapacity;
    int bikeCapacity;
    int carCount;
    int busCount;
    int bikeCount;
    Car *car;
    Bus *bus;
    Bike *bike;
    string *blockedPlateNumbers;
    int *blockedTokens;
    int blockedCount;
    int token;
    string unParkToken;
    string plateNumber;
    int attempts;
    bool found;
    Car *uncar;
    Bus *unbus;
    Bike *unbike;
    int unCarCount;
    int unBusCount;
    int unBikeCount;
    PaymentRecord payment;
    string *parkedPlateNumbers; // Array to store parked plate numbers
    int plateCount;             // Counter for parked plate numbers

public:
    ParkAndUnPark() {}
    ParkAndUnPark(int carCap, int busCap, int bikeCap) : payment(carCap + busCap + bikeCap)
    {
        carCapacity = carCap;
        busCapacity = busCap;
        bikeCapacity = bikeCap;
        carCount = 0;
        busCount = 0;
        bikeCount = 0;
        car = new Car[carCapacity];
        bus = new Bus[busCapacity];
        bike = new Bike[bikeCapacity];
        unCarCount = 0;
        unBusCount = 0;
        unBikeCount = 0;
        uncar = new Car[carCapacity];
        unbus = new Bus[busCapacity];
        unbike = new Bike[bikeCapacity];
        blockedPlateNumbers = new string[carCap + busCap + bikeCap];
        blockedTokens = new int[carCap + busCap + bikeCap];
        blockedCount = 0;
        parkedPlateNumbers = new string[carCap + busCap + bikeCap]; // Initialize parked plate numbers array
        plateCount = 0;                                             // Initialize parked plate number counter
    }

    void blockVehicle(string plateNo, int blockToken)
    {
        blockedPlateNumbers[blockedCount] = plateNo;
        blockedTokens[blockedCount] = blockToken;
        blockedCount++;
    }

    void unblockVehicle(const string &plateNumber, int unblockToken)
    {
        for (int i = 0; i < blockedCount; i++)
        {
            if (blockedTokens[i] == unblockToken && blockedPlateNumbers[i] == plateNumber)
            {
                // Shift the remaining elements to the left
                for (int j = i; j < blockedCount - 1; j++)
                {
                    blockedPlateNumbers[j] = blockedPlateNumbers[j + 1];
                    blockedTokens[j] = blockedTokens[j + 1];
                }
                blockedCount--; // Decrease the blocked count
                cout << "\n\t\tNow Vehicle is unblocked.\n";
                return;
            }
        }
        cout << "\n\t\tVehicle with plate number and token number not found in blocked list.\n";
    }

    bool isTokenBlocked(string plateNo, int token)
    {
        for (int i = 0; i < blockedCount; i++)
        {
            if (blockedPlateNumbers[i] == plateNo && blockedTokens[i] == token)
            {
                return true;
            }
        }
        return false;
    }

    void removePlateNumber(const string &plateNo)
    {
        for (int i = 0; i < plateCount; i++)
        {
            if (parkedPlateNumbers[i] == plateNo)
            {
                for (int j = i; j < plateCount - 1; j++)
                {
                    parkedPlateNumbers[j] = parkedPlateNumbers[j + 1];
                }
                plateCount--;
                break;
            }
        }
    }

    void parkCar()
    {
        if (carCount >= carCapacity)
        {
            cout << "\n\t\tParking lot for Cars is full.\n";
        }
        else
        {
            car[carCount].carPark(parkedPlateNumbers, plateCount, carCapacity + busCapacity + bikeCapacity);
            carCount++;
        }
    }

    void parkBus()
    {
        if (busCount >= busCapacity)
        {
            cout << "\n\t\tParking lot for Buses is full.\n";
        }
        else
        {
            bus[busCount].busPark(parkedPlateNumbers, plateCount, carCapacity + busCapacity + bikeCapacity);
            busCount++;
        }
    }

    void parkBike()
    {
        if (bikeCount >= bikeCapacity)
        {
            cout << "\n\t\tParking lot for Bikes is full.\n";
        }
        else
        {
            bike[bikeCount].bikePark(parkedPlateNumbers, plateCount, carCapacity + busCapacity + bikeCapacity);
            bikeCount++;
        }
    }

    void unparkCar()
    {
        attempts = 0;
        found = false;
        if (carCount == 0)
        {
            cout << "\n\t\tNo cars currently parked!\n";
            return;
        }
        while (true)
        {
            cout << "\n\t\tEnter the plate number of the car to unpark: ";
            getline(cin, plateNumber);
            if (plateNoValidation(plateNumber))
            {
                break;
            }
            else
            {
                cout << "\n\t\tInvalid input\n";
            }
        }
        for (int i = 0; i < carCount; i++)
        {
            if (car[i].getPlateNo() == plateNumber)
            {
                while (attempts < 3)
                {
                    while (true)
                    {
                        cout << "\n\t\tEnter the token number of the car to unpark: ";
                        getline(cin, unParkToken);
                        if (tokenValid(unParkToken))
                        {
                            token = stoi(unParkToken);
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid input\n";
                        }
                    }
                    if (!isTokenBlocked(plateNumber, token))
                    {
                        if (car[i].getToken() == token)
                        {
                            car[i].displayBill(false);
                            car[i].AskForPayment();
                            payment.recordPayment(car[i].getPlateNo(), token, car[i].getAmount());
                            uncar[unCarCount] = car[i];
                            unCarCount++;
                            for (int j = i; j < carCount - 1; j++)
                            {
                                car[j] = car[j + 1];
                            }
                            removePlateNumber(plateNumber);
                            carCount--;
                            found = true;
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid token number. Please try again.\n";
                            attempts++;
                        }
                    }
                    else
                    {
                        cout << "\n\t\tToken is currently blocked. Please contact admin to unblock.\n";
                        return;
                    }
                }

                if (found)
                    break;
                if (attempts >= 3)
                {
                    system("CLS");
                    cout << "\n\t\tInvalid token number blocked the car.\n\n\t\tContact with admin.\n";
                    blockVehicle(plateNumber, car[i].getToken());
                }
                return;
            }
        }

        if (!found)
        {
            cout << "\n\t\tInvalid plate number. Please try again.\n";
        }
    }

    void unparkBus()
    {
        attempts = 0;
        found = false;
        if (busCount == 0)
        {
            cout << "\n\t\tNo Buses currently parked!\n";
            return;
        }
        while (true)
        {
            cout << "\n\t\tEnter the plate number of the bus to unpark: ";
            getline(cin, plateNumber);
            if (plateNoValidation(plateNumber))
            {
                break;
            }
            else
            {
                cout << "\n\t\tInvalid input\n";
            }
        }
        for (int i = 0; i < busCount; i++)
        {
            if (bus[i].getPlateNo() == plateNumber)
            {
                while (attempts < 3)
                {
                    while (true)
                    {
                        cout << "\n\t\tEnter the token number of the bus to unpark: ";
                        getline(cin, unParkToken);
                        if (tokenValid(unParkToken))
                        {
                            token = stoi(unParkToken);
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid input\n";
                        }
                    }
                    if (!isTokenBlocked(plateNumber, token))
                    {
                        if (bus[i].getToken() == token)
                        {
                            bus[i].displayBill(false);
                            bus[i].AskForPayment();
                            payment.recordPayment(bus[i].getPlateNo(), token, bus[i].getAmount());
                            unbus[unBusCount] = bus[i];
                            unBusCount++;
                            for (int j = i; j < busCount - 1; j++)
                            {
                                car[j] = car[j + 1];
                            }
                            removePlateNumber(plateNumber);
                            busCount--;
                            found = true;
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid token number. Please try again.\n";
                            attempts++;
                        }
                    }
                    else
                    {
                        cout << "\n\t\tToken is currently blocked. Please contact admin to unblock.\n";
                        return;
                    }
                }

                if (found)
                    break;
                if (attempts >= 3)
                {
                    system("CLS");
                    cout << "\n\t\tInvalid token number blocked the bus.\n\n\t\tContact with admin.\n";
                    blockVehicle(plateNumber, bus[i].getToken());
                }
                return;
            }
        }

        if (!found)
        {
            cout << "\n\t\tInvalid plate number. Please try again.\n";
        }
    }

    void unparkBike()
    {
        attempts = 0;
        found = false;
        if (bikeCount == 0)
        {
            cout << "\n\t\tNo bikes currently parked!\n";
            return;
        }
        while (true)
        {
            cout << "\n\t\tEnter the plate number of the bike to unpark: ";
            getline(cin, plateNumber);
            if (plateNoValidation(plateNumber))
            {
                break;
            }
            else
            {
                cout << "\n\t\tInvalid input\n";
            }
        }
        for (int i = 0; i < bikeCount; i++)
        {
            if (bike[i].getPlateNo() == plateNumber)
            {
                while (attempts < 3)
                {
                    while (true)
                    {
                        cout << "\n\t\tEnter the token number of the bike to unpark: ";
                        getline(cin, unParkToken);
                        if (tokenValid(unParkToken))
                        {
                            token = stoi(unParkToken);
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid input\n";
                        }
                    }
                    if (!isTokenBlocked(plateNumber, token))
                    {
                        if (bike[i].getToken() == token)
                        {
                            bike[i].displayBill(false);
                            bike[i].AskForPayment();
                            payment.recordPayment(bike[i].getPlateNo(), token, bike[i].getAmount());
                            unbike[unBikeCount] = bike[i];
                            unBikeCount++;
                            for (int j = i; j < bikeCount - 1; j++)
                            {
                                bike[j] = bike[j + 1];
                            }
                            removePlateNumber(plateNumber);
                            bikeCount--;
                            found = true;
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid token number. Please try again.\n";
                            attempts++;
                        }
                    }
                    else
                    {
                        cout << "\n\t\tToken is currently blocked. Please contact admin to unblock.\n";
                        return;
                    }
                }

                if (found)
                    break;
                if (attempts >= 3)
                {
                    system("CLS");
                    cout << "\n\t\tInvalid token number blocked the bike.\n\n\t\tContact with admin.\n";
                    blockVehicle(plateNumber, bike[i].getToken());
                }
                return;
            }
        }

        if (!found)
        {
            cout << "\n\t\tInvalid plate number. Please try again.\n";
        }
    }

    void displayParkedCars()
    {
        if (carCount == 0)
        {
            system("CLS");
            cout << "\n\t\tNo Cars Parked found!\n";
        }
        else
        {
            system("CLS");
            cout << "\n\t\t\t--------------------- Parked Cars ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(17) << "Status" << "\n\n";
            for (int i = 0; i < carCount; i++)
            {
                cout << setw(4) << i + 1 << setw(25) << car[i].getCellNo() << setw(20) << car[i].getPlateNo() << setw(20) << car[i].getToken();
                cout << setw(11) << (car[i].getParkingType() == "2" ? car[i].getDays() : car[i].getHours())
                     << (car[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(20) << (isTokenBlocked(car[i].getPlateNo(), car[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayParkedBuses()
    {
        if (busCount == 0)
        {
            system("CLS");
            cout << "\n\t\tNo Buses Parked found!\n";
        }
        else
        {
            system("CLS");
            cout << "\n\t\t\t--------------------- Parked Buses ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(17) << "Status" << "\n\n";
            for (int i = 0; i < busCount; i++)
            {
                cout << setw(4) << i + 1 << setw(25) << bus[i].getCellNo() << setw(20) << bus[i].getPlateNo() << setw(20) << bus[i].getToken();
                cout << setw(11) << (bus[i].getParkingType() == "2" ? bus[i].getDays() : bus[i].getHours())
                     << (bus[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(20) << (isTokenBlocked(bus[i].getPlateNo(), bus[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayParkedBikes()
    {
        if (bikeCount == 0)
        {
            system("CLS");
            cout << "\n\t\tNo Bikes Parked found!\n";
        }
        else
        {
            system("CLS");
            cout << "\n\t\t\t--------------------- Parked Bikes ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(17) << "Status" << "\n\n";
            for (int i = 0; i < bikeCount; i++)
            {
                cout << setw(4) << i + 1 << setw(25) << bike[i].getCellNo() << setw(20) << bike[i].getPlateNo() << setw(20) << bike[i].getToken();
                cout << setw(11) << (bike[i].getParkingType() == "2" ? bike[i].getDays() : bike[i].getHours())
                     << (bike[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(20) << (isTokenBlocked(bike[i].getPlateNo(), bike[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayUnparkedCars()
    {
        if (unCarCount == 0)
        {
            system("CLS");
            cout << "\n\t\tNo UnParked Cars found!\n";
        }
        else
        {
            system("CLS");
            cout << "\n\t\t\t--------------------- UnParked Cars ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(20) << "Cell No" << setw(20) << "Plate No" << setw(20) << "Token No" << setw(20) << "Parking Type" << "\n\n";
            for (int i = 0; i < unCarCount; i++)
            {
                cout << setw(4) << i + 1 << setw(30) << uncar[i].getCellNo() << setw(16) << uncar[i].getPlateNo() << setw(18) << uncar[i].getToken();
                cout << setw(11) << (uncar[i].getParkingType() == "2" ? uncar[i].getDays() : uncar[i].getHours())
                     << (uncar[i].getParkingType() == "2" ? " day(s)" : " hour(s)") << "\n";
            }
            cout << "\n----------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayUnparkedBuses()
    {
        if (unBusCount == 0)
        {
            system("CLS");
            cout << "\n\t\tNo UnParked Buses found!\n";
        }
        else
        {
            system("CLS");
            cout << "\n\t\t\t--------------------- UnParked Buses ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(20) << "Cell No" << setw(20) << "Plate No" << setw(20) << "Token No" << setw(20) << "Parking Type" << "\n\n";
            for (int i = 0; i < unBusCount; i++)
            {
                cout << setw(4) << i + 1 << setw(30) << unbus[i].getCellNo() << setw(16) << unbus[i].getPlateNo() << setw(18) << unbus[i].getToken();
                cout << setw(11) << (unbus[i].getParkingType() == "2" ? unbus[i].getDays() : unbus[i].getHours())
                     << (unbus[i].getParkingType() == "2" ? " day(s)" : " hour(s)") << "\n";
            }
            cout << "\n----------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayUnparkedBikes()
    {
        if (unBikeCount == 0)
        {
            system("CLS");
            cout << "\n\t\tNo UnParked Bikes found!\n";
        }
        else
        {
            system("CLS");
            cout << "\n\t\t\t--------------------- UnParked Bikes ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(20) << "Cell No" << setw(20) << "Plate No" << setw(20) << "Token No" << setw(20) << "Parking Type" << "\n\n";
            for (int i = 0; i < unBikeCount; i++)
            {
                cout << setw(4) << i + 1 << setw(30) << unbike[i].getCellNo() << setw(16) << unbike[i].getPlateNo() << setw(18) << unbike[i].getToken();
                cout << setw(11) << (unbike[i].getParkingType() == "2" ? unbike[i].getDays() : unbike[i].getHours())
                     << (unbike[i].getParkingType() == "2" ? " day(s)" : " hour(s)") << "\n";
            }
            cout << "\n----------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void Payments()
    {
        payment.displayPayments();
    }

    void deletePayRecords()
    {
        payment.deleteAllRecords();
    }

    void deleteUnCarRec()
    {
        system("CLS");
        if (unCarCount == 0)
        {
            cout << "\n\t\tNo UnPark Cars Records Found to delete\n";
        }
        else
        {
            delete[] uncar;
            unCarCount = 0;
            uncar = new Car[carCapacity];
        }
    }

    void deleteUnBusRec()
    {
        system("CLS");
        if (unBusCount == 0)
        {
            cout << "\n\t\tNo UnPark Buses Records Found to delete\n";
        }
        else
        {
            delete[] unbus;
            unBusCount = 0;
            unbus = new Bus[busCapacity];
        }
    }

    void deleteUnBikeRec()
    {
        system("CLS");
        if (unBikeCount == 0)
        {
            cout << "\n\t\tNo UnPark Bike Records Found to delete\n";
        }
        else
        {
            delete[] unbike;
            unBikeCount = 0;
            unbike = new Bike[bikeCapacity];
        }
    }

    ~ParkAndUnPark()
    {
        delete[] car;
        delete[] bus;
        delete[] bike;
        delete[] blockedPlateNumbers;
        delete[] blockedTokens;
        delete[] parkedPlateNumbers; // Delete parked plate numbers array
    }
};
// function to check valid capacity
void userInterface(ParkAndUnPark &parking)
{
    while (true)
    {
        cout << "\n\t\t ______________________________________________\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t| [1]   |     Park Vehicle" << setw(23) << "|\n";
        cout << "\t\t| [2]   |     Unpark Vehicle" << setw(21) << "|\n";
        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|_______|______________________________________|\n";
        string user;
        while (true)
        {
            cout << "\n\t\tEnter your choice: ";
            getline(cin, user);
            if (parking.menuChoice(user))
            {
                break;
            }
            cout << "\n\t\tInvalid input.\n";
        }
        if (user == "1")
        {
            cout << "\n\t\t ______________________________________________\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
            cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
            cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|_______|______________________________________|\n";
            string park;
            while (true)
            {
                cout << "\n\t\tEnter your choice: ";
                getline(cin, park);
                if (parking.menuChoice(park))
                {
                    break;
                }
                cout << "\n\t\tInvalid input.\n";
            }

            if (park == "1")
            {
                system("CLS");
                parking.parkCar();
            }
            else if (park == "2")
            {
                system("CLS");
                parking.parkBus();
            }
            else if (park == "3")
            {
                system("CLS");
                parking.parkBike();
            }
            else
            {
                system("CLS");
                cout << "\n\t\tInvalid choice\n";
            }
        }
        else if (user == "2")
        {

            cout << "\n\t\t ______________________________________________\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
            cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
            cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|_______|______________________________________|\n";
            string unpark;
            while (true)
            {
                cout << "\n\t\tEnter your choice: ";
                getline(cin, unpark);
                if (parking.menuChoice(unpark))
                {
                    break;
                }
                cout << "\n\t\tInvalid input.\n";
            }
            if (unpark == "1")
            {
                system("CLS");
                parking.unparkCar();
            }
            else if (unpark == "2")
            {
                system("CLS");
                parking.unparkBus();
            }
            else if (unpark == "3")
            {
                system("CLS");
                parking.unparkBike();
            }
            else
            {
                system("CLS");
                cout << "\n\t\tInvalid choice\n";
            }
        }
        else if (user == "0")
        {
            system("CLS");
            break;
        }
        else
        {
            system("CLS");
            cout << "\n\t\tInvalid choice!\n";
        }
    }
}

/// Function to change the admin password
void changeAdminPassword(string &adminPassword, ParkAndUnPark &parking)
{
    system("CLS");
    string oldPassword;
    string newPassword;
    cout << "\n\t\tEnter old password: ";
    getline(cin, oldPassword);

    // Check if the old password matches the current password
    if (oldPassword == adminPassword)
    {
        while (true)
        {
            cout << "\n\t\tEnter new password: ";
            getline(cin, newPassword);
            if (parking.nameValid(newPassword))
            {
                adminPassword = newPassword;
                cout << "\n\t\tPassword changed successfully!\n";
                break;
            }
            cout << "\n\t\tInvalid new password\n";
        }
    }
    else
    {
        cout << "\n\t\tIncorrect old password. Password change failed!\n";
    }
}

// Main admin interface function
void adminInterface(ParkAndUnPark &parking, string &adminPassword)
{
    // Main admin menu
    int adminAttempt = 0;
    while (true)
    {
        string passcode;
        cout << "\n\nEnter the passcode to access the administration: ";
        getline(cin, passcode);
        if (passcode == adminPassword)
        {
            system("CLS");
            cout << "\n\t\tAccess granted! Welcome Admin.\n";
            string tokenStr;
            int token;
            string admin;
            while (true)
            {
                cout << "\n\t\t ______________________________________________\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t| [1]   |     Show Vehicle Data" << setw(18) << "|\n";
                cout << "\t\t| [2]   |     Restricted Data" << setw(20) << "|\n";
                cout << "\t\t| [3]   |     Payment Record" << setw(21) << "|\n";
                cout << "\t\t| [4]   |     Change Password" << setw(20) << "|\n";
                cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|_______|______________________________________|\n";
                while (true)
                {
                    cout << "\n\t\tEnter your choice: ";
                    getline(cin, admin);
                    if (parking.menuChoice(admin))
                    {
                        break;
                    }
                    cout << "\n\t\tInvalid input.\n";
                }
                if (admin == "1")
                {
                    string data;
                    while (true)
                    {
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     Park Data" << setw(26) << "|\n";
                        cout << "\t\t| [2]   |     Unpark Data" << setw(24) << "|\n";
                        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, data);
                            if (parking.menuChoice(data))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (data == "1")
                        {
                            system("CLS");
                            cout << "\n\t\t ______________________________________________\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
                            cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
                            cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t|_______|______________________________________|\n";
                            while (true)
                            {
                                cout << "\n\t\tEnter your choice: ";
                                getline(cin, data);
                                if (parking.menuChoice(data))
                                {
                                    break;
                                }
                                cout << "\n\t\tInvalid input.\n";
                            }
                            if (data == "1")
                            {
                                parking.displayParkedCars();
                            }
                            else if (data == "2")
                            {
                                parking.displayParkedBuses();
                            }
                            else if (data == "3")
                            {
                                parking.displayParkedBikes();
                            }
                            else
                            {
                                system("CLS");
                                cout << "\n\t\tInvalid choice.\n";
                            }
                        }
                        else if (data == "2")
                        {
                            system("CLS");
                            cout << "\n\t\t ______________________________________________\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
                            cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
                            cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
                            cout << "\t\t| [4]   |     Delete UnPark Record" << setw(15) << "|\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t|_______|______________________________________|\n";
                            while (true)
                            {
                                cout << "\n\t\tEnter your choice: ";
                                getline(cin, data);
                                if (parking.menuChoice(data))
                                {
                                    break;
                                }
                                cout << "\n\t\tInvalid input.\n";
                            }
                            if (data == "1")
                            {
                                parking.displayUnparkedCars();
                            }
                            else if (data == "2")
                            {
                                parking.displayUnparkedBuses();
                            }
                            else if (data == "3")
                            {
                                parking.displayUnparkedBikes();
                            }
                            else if (data == "4")
                            {
                                cout << "\n\t\t ______________________________________________\n";
                                cout << "\t\t|       |" << setw(40) << "|\n";
                                cout << "\t\t|       |" << setw(40) << "|\n";
                                cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
                                cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
                                cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
                                cout << "\t\t|       |" << setw(40) << "|\n";
                                cout << "\t\t|_______|______________________________________|\n";
                                string del;
                                while (true)
                                {
                                    cout << "\n\t\tEnter your choice: ";
                                    getline(cin, del);
                                    if (parking.menuChoice(del))
                                    {
                                        break;
                                    }
                                    cout << "\n\t\tInvalid input.\n";
                                }
                                if (del == "1")
                                {
                                    parking.deleteUnCarRec();
                                }
                                else if (del == "2")
                                {
                                    parking.deleteUnBusRec();
                                }
                                else if (del == "3")
                                {
                                    parking.deleteUnBikeRec();
                                }
                                else
                                {
                                    system("CLS");
                                    cout << "\n\t\tInvalid choice!\n";
                                }
                            }
                            else
                            {
                                system("CLS");
                                cout << "\n\t\tInvalid choice.\n";
                            }
                        }
                        else if (data == "0")
                        {
                            system("CLS");
                            break;
                        }
                        else
                        {
                            system("CLS");
                            cout << "\n\t\tInvalid choice!\n";
                        }
                    }
                }
                else if (admin == "2")
                {
                    while (true)
                    {
                        string block;
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     UnBlock Vehicle " << setw(19) << "|\n";
                        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, block);
                            if (parking.menuChoice(block))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (block == "1")
                        {
                            system("CLS");
                            string plateno;
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate no to unblock the vehicle: ";
                                getline(cin, plateno);
                                if (parking.plateNoValidation(plateno))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid plate no\n";
                                }
                            }
                            while (true)
                            {
                                cout << "\n\t\tEnter the token to unblock the vehicle: ";
                                getline(cin, tokenStr);
                                if (parking.tokenValid(tokenStr))
                                {
                                    token = stoi(tokenStr);
                                    break;
                                }
                                cout << "\n\t\tInvalid token.\n";
                            }
                            parking.unblockVehicle(plateno, token);
                        }
                        else if (block == "0")
                        {
                            system("CLS");
                            break;
                        }
                        else
                        {
                            system("CLS");
                            cout << "\n\t\tInvalid choice.\n";
                        }
                    }
                }
                else if (admin == "3")
                {
                    string pay;
                    while (true)
                    {
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     Display AllPayment Record " << setw(9) << "|\n";
                        cout << "\t\t| [2]   |     Delete AllPayment Record" << setw(11) << "|\n";
                        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, pay);
                            if (parking.menuChoice(pay))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (pay == "1")
                        {
                            system("CLS");
                            parking.Payments();
                        }
                        else if (pay == "2")
                        {
                            system("CLS");
                            parking.deletePayRecords();
                        }
                        else if (pay == "0")
                        {
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid choice!\n";
                        }
                    }
                }
                else if (admin == "4")
                {
                    changeAdminPassword(adminPassword, parking);
                }
                else if (admin == "0")
                {
                    system("CLS");
                    break;
                }
                else
                {
                    system("CLS");
                    cout << "\n\t\tInvalid choice!\n";
                }
            }
            break;
        }
        else
        {
            adminAttempt++;
            if (adminAttempt >= 3)
            {
                system("CLS");
                cout << "\n\t\tYou attempted the password many times. Please wait.\n";
                break;
            }
            else
            {
                cout << "\n\t\tInvalid Passcode. Try Again!\n";
            }
        }
    }
}

int main()

{
    string adminPassword = "123";
    string choice;
    system("CLS");
    ParkAndUnPark parking(50, 50, 50);

    cout << "\n\n\t\tWelcome to the Vehicle Management System\n\n";
    while (true)
    {
        cout << "\n\t\t ______________________________________________\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t| [1]   |     User" << setw(31) << "|\n";
        cout << "\t\t| [2]   |     Admin" << setw(30) << "|\n";
        cout << "\t\t| [0]   |     Exit" << setw(31) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|_______|______________________________________|\n";
        while (true)
        {
            cout << "\n\t\tEnter your choice: ";
            getline(cin, choice);
            if (parking.menuChoice(choice))
            {
                break;
            }
            cout << "\n\t\tInvalid input.\n";
        }
        if (choice == "1")
        {
            system("CLS");
            userInterface(parking);
        }
        else if (choice == "2")
        {
            system("CLS");
            adminInterface(parking, adminPassword);
        }
        else if (choice == "0")
        {
            cout << "\n\n\t\tThanks for using......\n\n\n";
            break;
        }
        else
        {
            system("CLS");
            cout << "\n\t\tInvalid choice!\n";
        }
    }
    return 0;

}
