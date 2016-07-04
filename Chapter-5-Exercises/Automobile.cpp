#include<iostream>
#include<time.h>
#include "Automobile.h"

Automobile::Automobile() :
    mManufacturer("unknown"), mModel("unknown"), mYear(-1)
{

}

Automobile::Automobile(std::string manufacturer, std::string model, int year) :
    mManufacturer(manufacturer), mModel(model), mYear(year)
{

}

std::string Automobile::getManufacturer()
{
    return mManufacturer;
}

void Automobile::setManufacturer(std::string manufacturer)
{
    mManufacturer = manufacturer;
}

std::string Automobile::getModel()
{
    return mModel;
}

void Automobile::setModel(std::string model)
{
    mModel = model;
}

int Automobile::getYear()
{
    return mYear;
}

void Automobile::setYear(int year)
{
    mYear = year;
}


void Automobile::getDescription()
{
    std::cout << mYear << " " << mManufacturer << " " << mModel << std::endl;
}

int Automobile::getAge()
{
    time_t t = time(0);
    struct tm* now = localtime(&t);

    return (now->tm_year + 1900) - mYear;
}

