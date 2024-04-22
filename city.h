#ifndef CITY_H
#define CITY_H

class city
{
public:
    city();

    void create(short);
    void change_owner(short);


    bool getIs_city() const;
    short getOwner() const;

private:
    bool is_city;
    short owner;
};

#endif // CITY_H
