//
//  main.cpp
//  最終レポート
//
//  Created by 有島良太 on 2025/08/08.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <limits>


class Flight {
public:
    
    Flight(const std::string& flightNumber,
           const std::string& departureAirport,
           const std::string& arrivalAirport,
           const std::string& departureTime,
           const std::string& arrivalTime)
        : m_flightNumber(flightNumber),
          m_departureAirport(departureAirport),
          m_arrivalAirport(arrivalAirport),
          m_departureTime(departureTime),
          m_arrivalTime(arrivalTime) {}

   
    const std::string& getFlightNumber() const { return m_flightNumber; }
    const std::string& getDepartureAirport() const { return m_departureAirport; }
    const std::string& getArrivalAirport() const { return m_arrivalAirport; }
    const std::string& getDepartureTime() const { return m_departureTime; }
    const std::string& getArrivalTime() const { return m_arrivalTime; }

private:
    std::string m_flightNumber;
    std::string m_departureAirport;
    std::string m_arrivalAirport;
    std::string m_departureTime;
    std::string m_arrivalTime;
};

class FlightManager {
public:

    void addFlight(std::shared_ptr<Flight> flight) {
        m_flights.push_back(flight);
    }

    void displayAllFlights() const {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "すべてのフライト情報:" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
       
        for (auto it = m_flights.begin(); it != m_flights.end(); ++it) {
            const auto& flight = *it;
            std::cout << "便名: " << flight->getFlightNumber() << std::endl;
            std::cout << "出発空港: " << flight->getDepartureAirport() << std::endl;
            std::cout << "到着空港: " << flight->getArrivalAirport() << std::endl;
            std::cout << "出発時間: " << flight->getDepartureTime() << std::endl;
            std::cout << "到着時間: " << flight->getArrivalTime() << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }

    void findFlight(const std::string& flightNumber) const {
        auto it = std::find_if(m_flights.begin(), m_flights.end(),
                               [&](const auto& flight) {
                                   return flight->getFlightNumber() == flightNumber;
                               });

        if (it != m_flights.end()) {
            const auto& flight = *it;
            std::cout << "----------------------------------------" << std::endl;
            std::cout << "検索結果:" << std::endl;
            std::cout << "便名: " << flight->getFlightNumber() << std::endl;
            std::cout << "出発空港: " << flight->getDepartureAirport() << std::endl;
            std::cout << "到着空港: " << flight->getArrivalAirport() << std::endl;
            std::cout << "出発時間: " << flight->getDepartureTime() << std::endl;
            std::cout << "到着時間: " << flight->getArrivalTime() << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        } else {
            std::cout << "指定された便名は見つかりません: " << flightNumber << std::endl;
        }
    }

private:
    std::vector<std::shared_ptr<Flight>> m_flights;
};

int main() {
    FlightManager manager;

    manager.addFlight(std::make_shared<Flight>("JAL123", "HND", "ITM", "08:00", "09:15"));
    manager.addFlight(std::make_shared<Flight>("ANA456", "ITM", "FUK", "10:30", "11:45"));
    manager.addFlight(std::make_shared<Flight>("SNA789", "HND", "OKA", "12:00", "14:50"));
    manager.addFlight(std::make_shared<Flight>("JAL101", "FUK", "HND", "07:30", "09:00"));
    manager.addFlight(std::make_shared<Flight>("ANA202", "CTS", "HND", "09:00", "10:35"));
    manager.addFlight(std::make_shared<Flight>("SKY303", "KIX", "CTS", "11:00", "12:55"));
    manager.addFlight(std::make_shared<Flight>("JTA404", "OKA", "FUK", "15:00", "16:45"));
    manager.addFlight(std::make_shared<Flight>("SFJ505", "NGO", "FUK", "13:00", "14:30"));
    manager.addFlight(std::make_shared<Flight>("ADO606", "CTS", "KIX", "16:30", "18:40"));
    manager.addFlight(std::make_shared<Flight>("Fuji888", "NRT", "HNL", "21:00", "09:00"));

    manager.displayAllFlights();

    std::string userFlightNumber;
    std::cout << "検索したい便名を入力してください（例: ANA456）: " << std::endl;
    std::cout << "> ";
    std::cin >> userFlightNumber;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    manager.findFlight(userFlightNumber);

    return 0;
}
