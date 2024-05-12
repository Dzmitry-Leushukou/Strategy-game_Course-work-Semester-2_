#ifndef CITY_H
#define CITY_H

#pragma once

class city
{
public:
    city();

    void create(short);
    void change_owner(short);
    void destroy();

    bool getIs_city() const;
    short getOwner() const;

    //void build();
private:
    bool is_city;
    short owner;
    int id;
};

#endif // CITY_H
