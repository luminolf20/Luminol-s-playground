#include <string>


class Animal
{
public:
    Animal();
    ~Animal();
    Animal(const Animal& other);
    Animal(Animal&& other);
    Animal& operator=(const Animal& other);
    Animal& operator=(Animal&& other);

    virtual void Sound();
    virtual void Movement();
    virtual void Food();
};


class TomTheCat : public Animal
{
public:
    TomTheCat() : Animal() {};
    ~TomTheCat();
    TomTheCat(const TomTheCat& cat);
    TomTheCat(TomTheCat&& cat);
    TomTheCat& operator=(const TomTheCat& cat);
    TomTheCat& operator=(TomTheCat&& cat);

    virtual void Sound() override;
    virtual void Movement() override;
    virtual void Food() override;
    //     sound = "Meow~";
    //     movement = "Silently walking on fours (searching for friend)";
    //     food = "Would like to eat a steak";
};


class JerryTheMouse : public Animal
{
public:
    JerryTheMouse() : Animal() {};
    ~JerryTheMouse();
    JerryTheMouse(const JerryTheMouse& mouse);
    JerryTheMouse(JerryTheMouse&& mouse);
    JerryTheMouse& operator=(const JerryTheMouse& mouse);
    JerryTheMouse& operator=(JerryTheMouse&& mouse);

    virtual void Sound() override;
    virtual void Movement() override;
    virtual void Food() override;
    //     sound = "Squeek!";
    //     movement = "Running on fours (from Tom)";
    //     food = "Loves eating cheese";
};


class Amogus : public Animal
{
public:
    Amogus() : Animal() {};
    ~Amogus();
    Amogus(const Amogus& amo);
    Amogus(Amogus&& amo);
    Amogus& operator=(const Amogus& amo);
    Amogus& operator=(Amogus&& amo);

    virtual void Sound() override;
    virtual void Movement() override;
    virtual void Food() override;
    //     sound = ". . .";
    //     movement = "Running";
    //     food = "Another Amoguses";
};


class OrangeElephant : public Animal
{
public:
    OrangeElephant() : Animal() {};
    ~OrangeElephant();
    OrangeElephant(const OrangeElephant& elephent);
    OrangeElephant(OrangeElephant&& elephant);
    OrangeElephant& operator=(const OrangeElephant& elephant);
    OrangeElephant& operator=(OrangeElephant&& elephant);

    virtual void Sound() override;
    virtual void Movement() override;
    virtual void Food() override;
    //     sound = "TRUMPeting";
    //     movement = "Stomping on fours";
    //     food = "Eating leaves and fruits with alcohol in them";
};


class TRex : public Animal
{
public:
    TRex() : Animal() {};
    ~TRex();
    TRex(const TRex& dino);
    TRex(TRex&& dino);
    TRex& operator=(const TRex& dino);
    TRex& operator=(TRex&& dino);

    virtual void Sound() override;
    virtual void Movement() override;
    virtual void Food() override;
    //     sound = "ROA-A-AR";
    //     movement = "Silent running fastger than a car";
    //     food = "Any kind of meat";
};