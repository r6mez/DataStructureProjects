#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
using namespace std;

class Address {
  private:
    string building;
    string street;
    string city;
    string state;

  public:
    friend ostream& operator<<(ostream& os, const Address& address);

    Address() : building(""), street(""), city(""), state("") {}

    Address(string building, string street, string city, string state) :
            building(building), street(street), city(city), state(state) {};

    void setBuilding(string building) {this->building = building;}
    void setStreet(string street) {this->street = street;}
    void setCity(string city) {this->city = city;}
    void setState(string state) {this->state = state;}

    string getBuilding() {return building;}
    string getStreet() {return street;}
    string getCity() {return city;}
    string getState() {return state;}
};

ostream& operator<<(ostream& os, const Address& address) {
    string addressString = address.building + ", " + address.street + ", " + address.city + ", " + address.state;
    os << addressString;
    return os;
}

#endif //ADDRESS_H
