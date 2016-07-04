#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include<string>

class Automobile
{
public:
    Automobile();
    Automobile(std::string manufacturer, std::string model, int year);
    std::string getManufacturer();
    void setManufacturer(std::string manufacturer);
    std::string getModel();
    void setModel(std::string model);
    int getYear();
    void setYear(int year);
    void getDescription();
    int getAge();

private:
    std::string mManufacturer;
    std::string mModel;
    int mYear;
};

#endif
