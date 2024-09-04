#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <conio.h>

using namespace std;

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

    bool amountValid(string &amount)
    {
        if (amount.empty())
        {
            return false;
        }

        bool hasDecimalPoint = false;
        for (size_t i = 0; i < amount.size(); ++i)
        {
            if (amount[i] == '.')
            {
                if (hasDecimalPoint) // More than one decimal point is invalid
                    return false;
                hasDecimalPoint = true;
            }
            else if (!isdigit(amount[i]))
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

    void upperCase(string &plateNo)
    {
        for (int i = 0; i < plateNo.size(); i++)
        {
            plateNo[i] = toupper(plateNo[i]);
        }
    }
};

class Vehicle : public ErrorHandling
{
protected:
    string cellNo;
    string plateNo;
    string parkingType;
    int days;
    int hours;
    time_t parkTime;
    time_t unparkTime;

public:
    Vehicle() {}

    Vehicle(string cellNo, string plateNo, int days, int hours, string parkingType)
        : cellNo(cellNo), plateNo(plateNo), days(days), hours(hours), parkingType(parkingType)
    {
        time(&parkTime); // Initialize parking start time
    }

    // Declare the setUnparkTime method
    void setUnparkTime(time_t unparkTime)
    {
        this->unparkTime = unparkTime;
    }

    void parkVehicle(vector<string> &parkedPlateNumbers, int &plateCount)
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
            for (int i = 0; i < plateNo.size(); i++)
            {
                plateNo[i] = toupper(plateNo[i]);
            }
            if (plateNoValidation(plateNo))
            {
                bool isUnique = true;

                // Traditional for loop to check uniqueness
                for (int i = 0; i < parkedPlateNumbers.size(); i++)
                {
                    if (parkedPlateNumbers[i] == plateNo)
                    {
                        isUnique = false;
                        break;
                    }
                }

                if (isUnique)
                {
                    parkedPlateNumbers.push_back(plateNo);
                    plateCount++;
                    break;
                }
                else
                {
                    cout << "\n\t\tPlate number already in Data-Base.\n";
                }
            }
            else
            {
                cout << "\n\t\tInvalid plate no.\n";
            }
        }
        time(&parkTime); // Set parking start time
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

    time_t getParkTime()
    {
        return parkTime;
    }

    time_t getUnparkTime()
    {
        return unparkTime;
    }
};

class BillCalculate : public Vehicle
{
protected:
    int token;
    double amount;
    double extraAmount;
    bool paymentSuccess;
    double fine;
    double totalAmount;

public:
    BillCalculate(int _token = 0, double _fine = 0.0, double _amount = 0.0, double _totalAmount = 0.0, double _extraAmount = 0.0)
        : Vehicle(), token(_token), fine(_fine), amount(_amount), totalAmount(_totalAmount), extraAmount(_extraAmount) {}

    BillCalculate(int _token, string _cellNo, string _plateNo, int _days, int _hours, string _parkingType)
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

    void calculateBill(string vehicleType)
    {
        time_t currentTime;
        time(&currentTime);
        double seconds = difftime(currentTime, getParkTime());
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
                    cout << "Thank you for Parking here!\n --> Your change: Rs. " << extraAmount << "\n";
                }
                else
                {
                    cout << "Thank you for Parking here!\n";
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

class Car : public BillCalculate
{
public:
    void carPark(vector<string> &parkedPlateNumbers, int &plateCount)
    {
        parkVehicle(parkedPlateNumbers, plateCount);
        GenerateToken();
        calculateBill("Car");
        displayBill(true);
    }
};

class Bus : public BillCalculate
{
public:
    void busPark(vector<string> &parkedPlateNumbers, int &plateCount)
    {

        parkVehicle(parkedPlateNumbers, plateCount);
        GenerateToken();
        calculateBill("Bus");
        displayBill(true);
    }
};

class Bike : public BillCalculate
{
public:
    void bikePark(vector<string> &parkedPlateNumbers, int &plateCount)
    {
        parkVehicle(parkedPlateNumbers, plateCount);
        GenerateToken();
        calculateBill("Bike");
        displayBill(true);
    }
};

class PaymentRecord : public ErrorHandling
{
private:
    vector<string> plateNumbers;
    vector<int> tokens;
    vector<double> amounts;
    vector<bool> paid;
    vector<time_t> parkTimes;
    vector<time_t> unparkTimes;
    vector<string> vehicleTypes; // Store the vehicle types
    double totalAmount;
    double withDrawAmount;

    void sortByPlateNumber()
    {
        size_t n = plateNumbers.size();
        for (size_t i = 0; i < n - 1; ++i)
        {
            for (size_t j = 0; j < n - i - 1; ++j)
            {
                if (plateNumbers[j] > plateNumbers[j + 1])
                {
                    // Swap plateNumbers
                    swap(plateNumbers[j], plateNumbers[j + 1]);

                    // Swap tokens
                    swap(tokens[j], tokens[j + 1]);

                    // Swap amounts
                    swap(amounts[j], amounts[j + 1]);

                    // Swap paid
                    swap(paid[j], paid[j + 1]);

                    // Swap parkTimes
                    swap(parkTimes[j], parkTimes[j + 1]);

                    // Swap unparkTimes
                    swap(unparkTimes[j], unparkTimes[j + 1]);

                    // Swap vehicleTypes
                    swap(vehicleTypes[j], vehicleTypes[j + 1]);
                }
            }
        }
    }

    string timeTostring(time_t time) const
    {
        char buffer[80];
        struct tm *timeinfo = localtime(&time);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M:%S %p", timeinfo);
        return string(buffer);
    }

public:
    PaymentRecord() : totalAmount(0.0) {}

    void recordPayment(const string &plateNo, int token, double amount, time_t parkTime, time_t unparkTime, bool isPaid, const string &vehicleType)
    {
        plateNumbers.push_back(plateNo);
        tokens.push_back(token);
        amounts.push_back(amount);
        paid.push_back(isPaid);
        parkTimes.push_back(parkTime);
        unparkTimes.push_back(unparkTime);
        vehicleTypes.push_back(vehicleType);
        if (isPaid)
        {
            totalAmount += amount;
        }
    }

    void updatePaymentRecord(const string &plateNo, int token, double amount, time_t unparkTime)
    {
        for (size_t i = 0; i < plateNumbers.size(); ++i)
        {
            if (plateNumbers[i] == plateNo && tokens[i] == token)
            {
                paid[i] = true;
                unparkTimes[i] = unparkTime;
                totalAmount += amount;
                return;
            }
        }
    }

    void displayPayments() const
    {
        if (plateNumbers.empty())
        {
            cout << "No payments recorded yet." << endl;
            return;
        }

        cout << "\n\n\t\t\t*************** Payment Records ***************\n\n";
        cout << setw(10) << "Type" << setw(12) << "Plate No" << setw(18) << "Token No" << setw(15) << "Amount" << setw(10) << "Paid" << setw(30) << "Park Date & Time" << setw(30) << "Unpark Date & Time" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        for (size_t i = 0; i < plateNumbers.size(); ++i)
        {
            cout << setw(10) << vehicleTypes[i]
                 << setw(12) << plateNumbers[i]
                 << setw(18) << tokens[i]
                 << setw(12) << "Rs : " << amounts[i] << setw(10) << (paid[i] ? "Yes" : "No")
                 << setw(32) << timeTostring(parkTimes[i]); // Park Time

            if (paid[i])
            {
                cout << setw(30) << timeTostring(unparkTimes[i]); // Unpark Time
            }
            else
            {
                cout << setw(30) << "N/A"; // Unpark time is not available
            }

            cout << endl;
        }

        cout << "\n***********************************************************************************************************************************************\n";
        cout << "\n\tTotal Amount: Rs : " << totalAmount << "\n";
    }

    void deleteAllRecords()
    {
        if (plateNumbers.empty())
        {
            cout << "No payments recorded yet." << endl;
            return;
        }

        plateNumbers.clear();
        tokens.clear();
        amounts.clear();
        paid.clear();
        parkTimes.clear();
        unparkTimes.clear();
        vehicleTypes.clear(); // Clear vehicle types
        totalAmount = 0.0;
        cout << "All payment records have been deleted." << endl;
    }

    void deleteSpecificRecord(const string &plateNo)
    {
        for (size_t i = 0; i < plateNumbers.size(); ++i)
        {
            if (plateNumbers[i] == plateNo)
            {
                totalAmount -= amounts[i];
                plateNumbers.erase(plateNumbers.begin() + i);
                tokens.erase(tokens.begin() + i);
                amounts.erase(amounts.begin() + i);
                paid.erase(paid.begin() + i);
                parkTimes.erase(parkTimes.begin() + i);
                unparkTimes.erase(unparkTimes.begin() + i);
                vehicleTypes.erase(vehicleTypes.begin() + i); // Erase vehicle type
                cout << "Payment record for plate number " << plateNo << " has been deleted." << endl;
                return;
            }
        }

        cout << "No payment record found for plate number " << plateNo << "." << endl;
    }

    void sortAndDisplayPayments()
    {
        sortByPlateNumber();
        displayPayments();
    }

    void withdrawPayment()
    {
        string amountstr;
        if (totalAmount <= 0)
        {
            cout << "No funds available for withdrawal." << endl;
            return;
        }
        else
        {
            cout << "Total Amount available for withdrawal: Rs" << totalAmount << endl;
            while (true)
            {
                while (true)
                {
                    cout << "Enter amount to withdraw: Rs";
                    getline(cin, amountstr);
                    if (amountValid(amountstr))
                    {
                        break;
                    }
                    cout << "Invalid amount!\n";
                }
                withDrawAmount = stod(amountstr);
                if (withDrawAmount <= 0)
                {
                    cout << "\nPlease Enter correct amount for Withdraw\n";
                }
                else if (withDrawAmount > totalAmount)
                {
                    cout << "Insufficient funds. You can withdraw up to Rs" << totalAmount << "." << endl;
                }
                else
                {
                    totalAmount -= withDrawAmount;
                    cout << "Rs" << withDrawAmount << " has been successfully withdrawn. Remaining balance: Rs" << totalAmount << endl;
                    break;
                }
            }
        }
    }
};
class ParkAndUnPark : public ErrorHandling
{
private:
    vector<Car> cars;
    vector<Bus> buses;
    vector<Bike> bikes;
    vector<string> blockedPlateNumbers;
    vector<int> blockedTokens;
    vector<Car> unparkedCars;
    vector<Bus> unparkedBuses;
    vector<Bike> unparkedBikes;
    PaymentRecord payment;
    int attempts;
    int token;
    string plateNumber;
    bool found;
    vector<string> parkedPlateNumbers;
    int plateCount;
    string unParkToken;

    string formatTime(time_t time)
    {
        char buffer[80];
        struct tm *timeinfo = localtime(&time);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M:%S %p", timeinfo);
        return string(buffer);
    }

    template <typename T>
    void bubbleSortByPlateNumber(vector<T> &vehicles)
    {
        for (int i = 0; i < vehicles.size() - 1; i++)
        {
            for (int j = 0; j < vehicles.size() - i - 1; j++)
            {
                if (vehicles[j].getPlateNo() > vehicles[j + 1].getPlateNo())
                {
                    // Swapping without using std::swap
                    T temp = vehicles[j];
                    vehicles[j] = vehicles[j + 1];
                    vehicles[j + 1] = temp;
                }
            }
        }
    }

    template <typename T>
    void deleteRecord(vector<T> &records, const string &plateNo)
    {
        for (size_t i = 0; i < records.size(); ++i)
        {
            if (records[i].getPlateNo() == plateNo)
            {
                records.erase(records.begin() + i);
                cout << "\n\t\tRecord with plate number " << plateNo << " has been deleted.\n";
                return;
            }
        }
        cout << "\n\t\tRecord with plate number " << plateNo << " not found.\n";
    }

    template <typename T>
    void deleteAllRecords(vector<T> &records, const string &type)
    {
        records.clear();
    }

    void blockVehicle(const string &plateNo, int blockToken)
    {
        blockedPlateNumbers.push_back(plateNo);
        blockedTokens.push_back(blockToken);
    }

    bool isTokenBlocked(const string &plateNo, int token)
    {
        for (int i = 0; i < blockedTokens.size(); i++)
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
                parkedPlateNumbers.erase(parkedPlateNumbers.begin() + i);
                plateCount--;
                break;
            }
        }
    }

public:
    ParkAndUnPark() : payment() { plateCount = 0; }

    void unblockVehicle(const string &plateNo, int unblockToken)
    {
        for (int i = 0; i < blockedTokens.size(); i++)
        {
            if (blockedTokens[i] == unblockToken && blockedPlateNumbers[i] == plateNo)
            {
                blockedPlateNumbers.erase(blockedPlateNumbers.begin() + i);
                blockedTokens.erase(blockedTokens.begin() + i);
                cout << "\n\t\tNow Vehicle is unblocked.\n";
                return;
            }
        }
        cout << "\n\t\tVehicle with plate number and token number not found in blocked list.\n";
    }

    void parkCar()
    {
        Car car;
        car.carPark(parkedPlateNumbers, plateCount);
        cars.push_back(car);
        time_t parkTime;
        time(&parkTime);
        payment.recordPayment(car.getPlateNo(), car.getToken(), car.getAmount(), parkTime, 0, false, "Car"); // Paid is false when parked
    }

    void parkBus()
    {
        Bus bus;
        bus.busPark(parkedPlateNumbers, plateCount);
        buses.push_back(bus);
        time_t parkTime;
        time(&parkTime);
        payment.recordPayment(bus.getPlateNo(), bus.getToken(), bus.getAmount(), parkTime, 0, false, "Bus"); // Paid is false when parked
    }

    void parkBike()
    {
        Bike bike;
        bike.bikePark(parkedPlateNumbers, plateCount);
        bikes.push_back(bike);
        time_t parkTime;
        time(&parkTime);
        payment.recordPayment(bike.getPlateNo(), bike.getToken(), bike.getAmount(), parkTime, 0, false, "Bike"); // Paid is false when parked
    }

    void unparkCar()
    {
        attempts = 0;
        found = false;
        if (cars.empty())
        {
            cout << "\n\t\tNo cars currently parked!\n";
            return;
        }
        while (true)
        {
            cout << "\n\t\tEnter the plate number of the car to unpark: ";
            getline(cin, plateNumber);
            for (int i = 0; i < plateNumber.size(); i++)
            {
                plateNumber[i] = toupper(plateNumber[i]);
            }
            if (plateNoValidation(plateNumber))
            {
                break;
            }
            else
            {
                cout << "\n\t\tInvalid input\n";
            }
        }

        for (int i = 0; i < cars.size(); i++)
        {
            if (cars[i].getPlateNo() == plateNumber)
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
                        if (cars[i].getToken() == token)
                        {
                            cars[i].displayBill(false);
                            cars[i].AskForPayment();
                            // Set the unpark time
                            time_t unparkTime;
                            time(&unparkTime);
                            cars[i].setUnparkTime(unparkTime);
                            payment.updatePaymentRecord(cars[i].getPlateNo(), token, cars[i].getAmount(), cars[i].getUnparkTime());
                            unparkedCars.push_back(cars[i]);
                            cars.erase(cars.begin() + i);
                            removePlateNumber(plateNumber);
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
                    cout << "\n\t\tInvalid token number blocked the car.\n\n\t\tContact with admin.\n";
                    blockVehicle(plateNumber, cars[i].getToken());
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
        if (buses.empty())
        {
            cout << "\n\t\tNo buses currently parked!\n";
            return;
        }
        while (true)
        {
            cout << "\n\t\tEnter the plate number of the bus to unpark: ";
            getline(cin, plateNumber);
            for (int i = 0; i < plateNumber.size(); i++)
            {
                plateNumber[i] = toupper(plateNumber[i]);
            }
            if (plateNoValidation(plateNumber))
            {
                break;
            }
            else
            {
                cout << "\n\t\tInvalid input\n";
            }
        }

        for (int i = 0; i < buses.size(); i++)
        {
            if (buses[i].getPlateNo() == plateNumber)
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
                        if (buses[i].getToken() == token)
                        {
                            buses[i].displayBill(false);
                            buses[i].AskForPayment();
                            // Set the unpark time
                            time_t unparkTime;
                            time(&unparkTime);
                            buses[i].setUnparkTime(unparkTime);
                            payment.updatePaymentRecord(buses[i].getPlateNo(), token, buses[i].getAmount(), buses[i].getUnparkTime());
                            unparkedBuses.push_back(buses[i]);
                            buses.erase(buses.begin() + i);
                            removePlateNumber(plateNumber);
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
                    cout << "\n\t\tInvalid token number blocked the bus.\n\n\t\tContact with admin.\n";
                    blockVehicle(plateNumber, buses[i].getToken());
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
        if (bikes.empty())
        {
            cout << "\n\t\tNo bikes currently parked!\n";
            return;
        }
        while (true)
        {
            cout << "\n\t\tEnter the plate number of the bike to unpark: ";
            getline(cin, plateNumber);
            for (int i = 0; i < plateNumber.size(); i++)
            {
                plateNumber[i] = toupper(plateNumber[i]);
            }
            if (plateNoValidation(plateNumber))
            {
                break;
            }
            else
            {
                cout << "\n\t\tInvalid input\n";
            }
        }

        for (int i = 0; i < bikes.size(); i++)
        {
            if (bikes[i].getPlateNo() == plateNumber)
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
                        if (bikes[i].getToken() == token)
                        {
                            bikes[i].displayBill(false);
                            bikes[i].AskForPayment();
                            // Set the unpark time
                            time_t unparkTime;
                            time(&unparkTime);
                            bikes[i].setUnparkTime(unparkTime);
                            payment.updatePaymentRecord(bikes[i].getPlateNo(), token, bikes[i].getAmount(), bikes[i].getUnparkTime());
                            ;
                            unparkedBikes.push_back(bikes[i]);
                            bikes.erase(bikes.begin() + i);
                            removePlateNumber(plateNumber);
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
                    cout << "\n\t\tInvalid token number blocked the bike.\n\n\t\tContact with admin.\n";
                    blockVehicle(plateNumber, bikes[i].getToken());
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
        if (cars.empty())
        {
            cout << "\n\t\tNo Cars Parked found!\n";
        }
        else
        {
            bubbleSortByPlateNumber(cars);
            cout << "\n\t\t\t--------------------- Parked Cars ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Park Date & Time" << setw(19) << "Status" << "\n\n";
            for (int i = 0; i < cars.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << cars[i].getCellNo() << setw(20) << cars[i].getPlateNo() << setw(20) << cars[i].getToken();
                cout << setw(11) << (cars[i].getParkingType() == "2" ? cars[i].getDays() : cars[i].getHours())
                     << (cars[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(cars[i].getParkTime()) << setw(20) << (isTokenBlocked(cars[i].getPlateNo(), cars[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayParkedBuses()
    {
        if (buses.empty())
        {
            cout << "\n\t\tNo Buses Parked found!\n";
        }
        else
        {
            bubbleSortByPlateNumber(buses);
            cout << "\n\t\t\t--------------------- Parked Buses ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Park Date & Time" << setw(19) << "Status" << "\n\n";

            for (int i = 0; i < buses.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << buses[i].getCellNo() << setw(20) << buses[i].getPlateNo() << setw(20) << buses[i].getToken();
                cout << setw(11) << (buses[i].getParkingType() == "2" ? buses[i].getDays() : buses[i].getHours())
                     << (buses[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(buses[i].getParkTime()) << setw(20) << (isTokenBlocked(buses[i].getPlateNo(), buses[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayParkedBikes()
    {
        if (bikes.empty())
        {
            cout << "\n\t\tNo Bikes Parked found!\n";
        }
        else
        {
            bubbleSortByPlateNumber(bikes);
            cout << "\n\t\t\t--------------------- Parked Bikes ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Park Date & Time" << setw(19) << "Status" << "\n\n";
            for (int i = 0; i < bikes.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << bikes[i].getCellNo() << setw(20) << bikes[i].getPlateNo() << setw(20) << bikes[i].getToken();
                cout << setw(11) << (bikes[i].getParkingType() == "2" ? bikes[i].getDays() : bikes[i].getHours())
                     << (bikes[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(bikes[i].getParkTime()) << setw(20) << (isTokenBlocked(bikes[i].getPlateNo(), bikes[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayUnparkedCars()
    {
        if (unparkedCars.empty())
        {
            cout << "\n\t\tNo Cars Unparked found!\n";
        }
        else
        {
            bubbleSortByPlateNumber(unparkedCars);
            cout << "\n\t\t\t--------------------- Unparked Cars ----------------------\n\n";

            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "UnPark Date & Time" << setw(19) << "Status" << "\n\n";

            for (int i = 0; i < unparkedCars.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << unparkedCars[i].getCellNo() << setw(20) << unparkedCars[i].getPlateNo() << setw(20) << unparkedCars[i].getToken();
                cout << setw(11) << (unparkedCars[i].getParkingType() == "2" ? unparkedCars[i].getDays() : unparkedCars[i].getHours())
                     << (unparkedCars[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(unparkedCars[i].getUnparkTime()) << setw(20) << (isTokenBlocked(unparkedCars[i].getPlateNo(), unparkedCars[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayUnparkedBuses()
    {
        if (unparkedBuses.empty())
        {
            cout << "\n\t\tNo Buses Unparked found!\n";
        }
        else
        {
            bubbleSortByPlateNumber(unparkedBuses);
            cout << "\n\t\t\t--------------------- Unparked Buses ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "UnPark Date & Time" << setw(19) << "Status" << "\n\n";
            for (int i = 0; i < unparkedBuses.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << unparkedBuses[i].getCellNo() << setw(20) << unparkedBuses[i].getPlateNo() << setw(20) << unparkedBuses[i].getToken();
                cout << setw(11) << (unparkedBuses[i].getParkingType() == "2" ? unparkedBuses[i].getDays() : unparkedBuses[i].getHours())
                     << (unparkedBuses[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(unparkedBuses[i].getUnparkTime()) << setw(20) << (isTokenBlocked(unparkedBuses[i].getPlateNo(), unparkedBuses[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void displayUnparkedBikes()
    {
        if (unparkedBikes.empty())
        {
            cout << "\n\t\tNo Bikes Unparked found!\n";
        }
        else
        {
            bubbleSortByPlateNumber(unparkedBikes);
            cout << "\n\t\t\t--------------------- Unparked Bikes ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "UnPark Date & Time" << setw(19) << "Status" << "\n\n";
            for (int i = 0; i < unparkedBikes.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << unparkedBikes[i].getCellNo() << setw(20) << unparkedBikes[i].getPlateNo() << setw(20) << unparkedBikes[i].getToken();
                cout << setw(11) << (unparkedBikes[i].getParkingType() == "2" ? unparkedBikes[i].getDays() : unparkedBikes[i].getHours())
                     << (unparkedBikes[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(unparkedBuses[i].getUnparkTime()) << setw(20) << (isTokenBlocked(unparkedBikes[i].getPlateNo(), unparkedBikes[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
        }
    }

    void searchRecords(const string &searchTerm)
    {
        system("cls");
        bool found = false;

        // Search in parked cars
        for (int i = 0; i < cars.size(); i++)
        {
            if (cars[i].getPlateNo() == searchTerm)
            {
                if (!found)
                {
                    found = true;
                    cout << "\n\t\t\t\t\t--------------------- Search Results ----------------------\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << setw(10) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type"
                         << setw(25) << "Park Date & Time" << setw(25) << "Unpark Date & Time"
                         << setw(12) << "Status" << setw(16) << "Vehicle Type" << "\n\n";
                }

                string parkDateTime = formatTime(cars[i].getParkTime());
                cout << setw(4) << cars[i].getCellNo()
                     << setw(20) << cars[i].getPlateNo()
                     << setw(20) << cars[i].getToken()
                     << setw(11) << (cars[i].getParkingType() == "2" ? cars[i].getDays() : cars[i].getHours())
                     << (cars[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(27) << parkDateTime
                     << setw(23) << "N/A"
                     << setw(12) << "Parked"
                     << setw(10) << "Car" << "\n";
            }
        }

        // Search in parked buses
        for (int i = 0; i < buses.size(); i++)
        {
            if (buses[i].getPlateNo() == searchTerm)
            {
                if (!found)
                {
                    found = true;
                    cout << "\n\t\t\t\t\t--------------------- Search Results ----------------------\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << setw(10) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type"
                         << setw(25) << "Park Date & Time" << setw(25) << "Unpark Date & Time"
                         << setw(12) << "Status" << setw(16) << "Vehicle Type" << "\n\n";
                }

                string parkDateTime = formatTime(buses[i].getParkTime());
                cout << setw(4) << buses[i].getCellNo()
                     << setw(20) << buses[i].getPlateNo()
                     << setw(20) << buses[i].getToken()
                     << setw(11) << (buses[i].getParkingType() == "2" ? buses[i].getDays() : buses[i].getHours())
                     << (buses[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(27) << parkDateTime
                     << setw(23) << "N/A"
                     << setw(12) << "Parked"
                     << setw(10) << "Bus" << "\n";
            }
        }

        // Search in parked bikes
        for (int i = 0; i < bikes.size(); i++)
        {
            if (bikes[i].getPlateNo() == searchTerm)
            {
                if (!found)
                {
                    found = true;
                    cout << "\n\t\t\t\t\t--------------------- Search Results ----------------------\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << setw(10) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type"
                         << setw(25) << "Park Date & Time" << setw(25) << "Unpark Date & Time"
                         << setw(12) << "Status" << setw(16) << "Vehicle Type" << "\n\n";
                }

                string parkDateTime = formatTime(bikes[i].getParkTime());
                cout << setw(4) << bikes[i].getCellNo()
                     << setw(20) << bikes[i].getPlateNo()
                     << setw(20) << bikes[i].getToken()
                     << setw(11) << (bikes[i].getParkingType() == "2" ? bikes[i].getDays() : bikes[i].getHours())
                     << (bikes[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(27) << parkDateTime
                     << setw(23) << "N/A"
                     << setw(12) << "Parked"
                     << setw(10) << "Bike" << "\n";
            }
        }

        // Search in unparked cars
        for (int i = 0; i < unparkedCars.size(); i++)
        {
            if (unparkedCars[i].getPlateNo() == searchTerm)
            {
                if (!found)
                {
                    found = true;
                    cout << "\n\t\t\t\t\t--------------------- Search Results ----------------------\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << setw(10) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type"
                         << setw(25) << "Park Date & Time" << setw(25) << "Unpark Date & Time"
                         << setw(12) << "Status" << setw(16) << "Vehicle Type" << "\n\n";
                }

                string parkDateTime = formatTime(unparkedCars[i].getParkTime());
                string unparkDateTime = formatTime(unparkedCars[i].getUnparkTime());
                cout << setw(4) << unparkedCars[i].getCellNo()
                     << setw(20) << unparkedCars[i].getPlateNo()
                     << setw(20) << unparkedCars[i].getToken()
                     << setw(11) << (unparkedCars[i].getParkingType() == "2" ? unparkedCars[i].getDays() : unparkedCars[i].getHours())
                     << (unparkedCars[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << parkDateTime
                     << setw(25) << unparkDateTime
                     << setw(12) << "Unparked"
                     << setw(10) << "Car" << "\n";
            }
        }

        // Search in unparked buses
        for (int i = 0; i < unparkedBuses.size(); i++)
        {
            if (unparkedBuses[i].getPlateNo() == searchTerm )
            {
                if (!found)
                {
                    found = true;
                    cout << "\n\t\t\t\t\t--------------------- Search Results ----------------------\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << setw(10) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type"
                         << setw(25) << "Park Date & Time" << setw(25) << "Unpark Date & Time"
                         << setw(12) << "Status" << setw(16) << "Vehicle Type" << "\n\n";
                }

                string parkDateTime = formatTime(unparkedBuses[i].getParkTime());
                string unparkDateTime = formatTime(unparkedBuses[i].getUnparkTime());
                cout << setw(4) << unparkedBuses[i].getCellNo()
                     << setw(20) << unparkedBuses[i].getPlateNo()
                     << setw(20) << unparkedBuses[i].getToken()
                     << setw(11) << (unparkedBuses[i].getParkingType() == "2" ? unparkedBuses[i].getDays() : unparkedBuses[i].getHours())
                     << (unparkedBuses[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << parkDateTime
                     << setw(25) << unparkDateTime
                     << setw(12) << "Unparked"
                     << setw(10) << "Bus" << "\n";
            }
        }

        // Search in unparked bikes
        for (int i = 0; i < unparkedBikes.size(); i++)
        {
            if (unparkedBikes[i].getPlateNo() == searchTerm)
            {
                if (!found)
                {
                    found = true;
                    cout << "\n\t\t\t\t\t--------------------- Search Results ----------------------\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << setw(10) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type"
                         << setw(25) << "Park Date & Time" << setw(25) << "Unpark Date & Time"
                         << setw(12) << "Status" << setw(16) << "Vehicle Type" << "\n\n";
                }

                string parkDateTime = formatTime(unparkedBikes[i].getParkTime());
                string unparkDateTime = formatTime(unparkedBikes[i].getUnparkTime());
                cout << setw(4) << unparkedBikes[i].getCellNo()
                     << setw(20) << unparkedBikes[i].getPlateNo()
                     << setw(20) << unparkedBikes[i].getToken()
                     << setw(11) << (unparkedBikes[i].getParkingType() == "2" ? unparkedBikes[i].getDays() : unparkedBikes[i].getHours())
                     << (unparkedBikes[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << parkDateTime
                     << setw(25) << unparkDateTime
                     << setw(12) << "Unparked"
                     << setw(10) << "Bike" << "\n";
            }
        }

        if (found)
        {
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\tNo matching records found." << endl;
        }
    }

    void Payments()
    {
        payment.sortAndDisplayPayments();
    }

    void deletePayRecords()
    {
        payment.deleteAllRecords();
    }
    void withDraw()
    {
        payment.withdrawPayment();
    }

    void deleteSpecificPaymentRecord(const string &plateNo)
    {
        payment.deleteSpecificRecord(plateNo);
    }

    void deleteParkedCar(const string &plateNo)
    {
        deleteRecord(cars, plateNo);
    }

    void deleteParkedBus(const string &plateNo)
    {
        deleteRecord(buses, plateNo);
    }

    void deleteParkedBike(const string &plateNo)
    {
        deleteRecord(bikes, plateNo);
    }

    void deleteUnparkedCar(const string &plateNo)
    {
        deleteRecord(unparkedCars, plateNo);
    }

    void deleteUnparkedBus(const string &plateNo)
    {
        deleteRecord(unparkedBuses, plateNo);
    }

    void deleteUnparkedBike(const string &plateNo)
    {
        deleteRecord(unparkedBikes, plateNo);
    }

    void deleteAllParkedCars()
    {
        deleteAllRecords(cars, "parked cars");
    }

    void deleteAllParkedBuses()
    {
        deleteAllRecords(buses, "parked buses");
    }

    void deleteAllParkedBikes()
    {
        deleteAllRecords(bikes, "parked bikes");
    }

    void deleteAllUnparkedCars()
    {
        deleteAllRecords(unparkedCars, "unparked cars");
    }

    void deleteAllUnparkedBuses()
    {
        deleteAllRecords(unparkedBuses, "unparked buses");
    }

    void deleteAllUnparkedBikes()
    {
        deleteAllRecords(unparkedBikes, "unparked bikes");
    }

    void deleteParkedRecords()
    {
        deleteAllParkedCars();
        deleteAllParkedBuses();
        deleteAllParkedBikes();
        cout << "\n\t\tAll Vehicles Record  have been deleted.\n";
    }

    void deleteUnParkedRecords()
    {
        deleteAllUnparkedCars();
        deleteAllUnparkedBuses();
        deleteAllUnparkedBikes();
        cout << "\n\t\tAll Vehicles Record  have been deleted.\n";
    }
};

void passLogic(string &password, string promptText)
{
    char pass[32] = {0};
    char ch;
    bool enter = false;
    int i = 0;
    bool show = false;

    cout << promptText;

    while (!enter)
    {
        ch = _getch();

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            pass[i] = ch;
            if (show)
            {
                cout << ch;
            }
            else
            {
                cout << "*";
            }
            i++;
        }

        if (ch == '\b' && i >= 1)
        {
            cout << "\b \b";
            i--;
        }

        if (ch == '\r')
        {
            enter = true;
        }

        if (ch == '\t')
        {
            show = !show;
            cout << "\r" << promptText;
            for (int j = 0; j < i; j++)
            {
                cout << (show ? pass[j] : '*');
            }
        }
    }

    pass[i] = '\0';
    password = pass;
}

void changeAdminPassword(string &adminPassword, ParkAndUnPark &parking)
{
    system("CLS");
    string oldPassword;
    string newPassword;

    passLogic(oldPassword, "Enter old password: ");

    if (oldPassword == adminPassword)
    {
        while (true)
        {
            cout << "\n";
            passLogic(newPassword, "Enter new password: ");

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

void adminInterface(ParkAndUnPark &parking, string &adminPassword)
{
    // Main admin menu
    int adminAttempt = 0;
    while (true)
    {
        string passcode;
        passLogic(passcode, "Enter the passcode to access the administration: ");
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
                cout << "\t\t| [2]   |     Search Vehicle Data" << setw(16) << "|\n";
                cout << "\t\t| [3]   |     Delete Vehicle Data" << setw(16) << "|\n";
                cout << "\t\t| [4]   |     Restricted Data" << setw(20) << "|\n";
                cout << "\t\t| [5]   |     Payment Record" << setw(21) << "|\n";
                cout << "\t\t| [6]   |     Change Password" << setw(20) << "|\n";
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
                    string splate;
                    while (true)
                    {
                        cout << "\n\t\tEnter the plate number to search recods along : ";
                        getline(cin, splate);
                        parking.upperCase(splate);
                        if (parking.plateNoValidation(splate))
                        {
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid input\n";
                        }
                    }
                    parking.searchRecords(splate);
                }
                else if (admin == "3")
                {
                    string delRec;
                    cout << "\n\t\t ______________________________________________\n";
                    cout << "\t\t|       |" << setw(40) << "|\n";
                    cout << "\t\t|       |" << setw(40) << "|\n";
                    cout << "\t\t| [1]   |     Delete Park Record" << setw(17) << "|\n";
                    cout << "\t\t| [2]   |     Delete UnPark Record" << setw(15) << "|\n";
                    cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                    cout << "\t\t|       |" << setw(40) << "|\n";
                    cout << "\t\t|_______|______________________________________|\n";
                    while (true)
                    {
                        cout << "\n\t\tEnter your choice: ";
                        getline(cin, delRec);
                        if (parking.menuChoice(delRec))
                        {
                            break;
                        }
                        cout << "\n\t\tInvalid input.\n";
                    }
                    if (delRec == "1")
                    {
                        string delRecord;
                        string PlateNo;
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     Delete Specific Car Record" << setw(9) << "|\n";
                        cout << "\t\t| [1]   |     Delete Specific Bus Record" << setw(9) << "|\n";
                        cout << "\t\t| [1]   |     Delete Specific Bike Record" << setw(8) << "|\n";
                        cout << "\t\t| [4]   |     Delete All Park Record" << setw(13) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, delRecord);
                            if (parking.menuChoice(delRecord))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (delRecord == "1")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of car to delete record : ";
                                getline(cin, PlateNo);
                                parking.upperCase(PlateNo);
                                if (parking.plateNoValidation(PlateNo))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteParkedCar(PlateNo);
                        }
                        else if (delRecord == "2")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of bus to delele record : ";
                                getline(cin, PlateNo);
                                parking.upperCase(PlateNo);
                                if (parking.plateNoValidation(PlateNo))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteParkedBus(PlateNo);
                        }
                        else if (delRecord == "3")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of bike to delete record : ";
                                getline(cin, PlateNo);
                                parking.upperCase(PlateNo);
                                if (parking.plateNoValidation(PlateNo))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteParkedBike(PlateNo);
                        }
                        else if (delRecord == "4")
                        {
                            parking.deleteParkedRecords();
                        }
                        else
                        {
                            system("CLS");
                            cout << "\n\t\tInvalid choice!\n";
                        }
                    }
                    else if (delRec == "2")
                    {
                        string delReco;
                        string Plate;
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     Delete Specific Car Record" << setw(9) << "|\n";
                        cout << "\t\t| [1]   |     Delete Specific Bus Record" << setw(9) << "|\n";
                        cout << "\t\t| [1]   |     Delete Specific Bike Record" << setw(8) << "|\n";
                        cout << "\t\t| [4]   |     Delete All UnPark Record" << setw(11) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, delReco);
                            if (parking.menuChoice(delReco))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (delReco == "1")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of car to delete record : ";
                                getline(cin, Plate);
                                parking.upperCase(Plate);
                                if (parking.plateNoValidation(Plate))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteUnparkedCar(Plate);
                        }
                        else if (delReco == "2")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of bike to delete record : ";
                                getline(cin, Plate);
                                parking.upperCase(Plate);
                                if (parking.plateNoValidation(Plate))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteUnparkedBus(Plate);
                        }
                        else if (delReco == "3")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of bike to delete record : ";
                                getline(cin, Plate);
                                parking.upperCase(Plate);
                                if (parking.plateNoValidation(Plate))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteUnparkedBike(Plate);
                        }
                        else if (delReco == "4")
                        {
                            parking.deleteUnParkedRecords();
                        }
                        else
                        {
                            system("CLS");
                            cout << "\n\t\tInvalid choice!\n";
                        }
                    }
                    else if (delRec == "0")
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
                else if (admin == "4")
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
                                parking.upperCase(plateno);
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
                else if (admin == "5")
                {
                    string pay;
                    while (true)
                    {
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     Display AllPayment Record " << setw(9) << "|\n";
                        cout << "\t\t| [2]   |     Withdraw Money " << setw(20) << "|\n";
                        cout << "\t\t| [3]   |     Delete Specific Payment Record" << setw(5) << "|\n";
                        cout << "\t\t| [4]   |     Delete AllPayment Record" << setw(11) << "|\n";
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
                            parking.withDraw();
                        }
                        else if (pay == "3")
                        {
                            string plateNo;
                            while (true)
                            {
                                system("cls");
                                cout << "\n\t\tEnter the plate number of vehicle to delete records along : ";
                                getline(cin, plateNo);
                                parking.upperCase(plateNo);
                                if (parking.plateNoValidation(plateNo))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteSpecificPaymentRecord(plateNo);
                        }
                        else if (pay == "4")
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
                else if (admin == "6")
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
    string adminPassword = "Saad";
    string choice;
    system("CLS");
    ParkAndUnPark ParkingSystem;

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
            if (ParkingSystem.menuChoice(choice))
            {
                break;
            }
            cout << "\n\t\tInvalid input.\n";
        }
        if (choice == "1")
        {
            system("CLS");
            userInterface(ParkingSystem);
        }
        else if (choice == "2")
        {
            system("CLS");
            adminInterface(ParkingSystem, adminPassword);
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
