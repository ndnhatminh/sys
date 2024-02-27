#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType { PHOENIX=-1, ANTIDOTE=0, PHOENIXI, PHOENIXII, PHOENIXIII, PHOENIXIV };

class BaseBag;
class BaseItem;
class Events;
class ArmyKnights;
class BaseKnight;

class Utils {
public:
    static bool isPrime(int n);
    static bool is888(int n);
    static bool isPythagoras(int n);
};
class BaseOpponent {
public:
    virtual ~BaseOpponent() = default;
    virtual void acceptFight(ArmyKnights * armyKnights) = 0; // accept fight, return if knight is alive
};

class OpponentWithLevel : public BaseOpponent {
protected:
    int levelO;
public:
    OpponentWithLevel(int event_index, int event_id);
    virtual bool isKnightWinsOpponent(BaseKnight * knight);
};

class OpponentWithDamageGil : public OpponentWithLevel {
private:
    int baseDamage, offeredGil;
public:
    OpponentWithDamageGil(int event_index, int event_id, int baseDamage, int offeredGil);
    virtual void acceptFight(ArmyKnights * armyKnights);
    virtual bool isKnightWinsOpponent(BaseKnight * knight);
    virtual int getDamage(BaseKnight * knight) const;
};

class MadBear : public OpponentWithDamageGil {
public:
    MadBear(int event_index, int event_id);
};

class Bandit : public OpponentWithDamageGil {
public:
    Bandit(int event_index, int event_id);
    // virtual void acceptFight(ArmyKnights * armyKnights);
};

class LordLupin : public OpponentWithDamageGil {
public:
    LordLupin(int event_index, int event_id);
    // virtual void acceptFight(ArmyKnights * armyKnights);
};

class Elf : public OpponentWithDamageGil {
public:
    Elf(int event_index, int event_id);
    // virtual void acceptFight(ArmyKnights * armyKnights);
};

class Troll : public OpponentWithDamageGil {
public:
    Troll(int event_index, int event_id);
    // virtual void acceptFight(ArmyKnights * armyKnights);
};

class Tornbery : public OpponentWithLevel {
public:
    Tornbery(int event_index, int event_id);
    virtual void acceptFight(ArmyKnights * armyKnights);
    // virtual bool isKnightWinsOpponent(BaseKnight * knight);
};

class QueenOfCards : public OpponentWithLevel {
public:
    QueenOfCards(int event_index, int event_id);
    virtual void acceptFight(ArmyKnights * armyKnights);
    // virtual bool isKnightWinsOpponent(BaseKnight * knight);
};

class NinaDeRings : public BaseOpponent {
public:
    virtual void acceptFight(ArmyKnights * armyKnights);
};

class DurianGarden : public BaseOpponent {
public:
    virtual void acceptFight(ArmyKnights * armyKnights);
};

class OmegaWeapon : public BaseOpponent {
public:
    virtual bool isKnightWinsOpponent(BaseKnight * knight);
    virtual void acceptFight(ArmyKnights * armyKnights);
};

class Hades : public BaseOpponent {
public:
    virtual bool isKnightWinsOpponent(BaseKnight * knight);
    virtual void acceptFight(ArmyKnights * armyKnights);
};

class Ultimecia : public BaseOpponent {
public:
    virtual void acceptFight(ArmyKnights * armyKnights);
};

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    BaseBag * bag;
    KnightType knightType;

    bool poisoned;

protected:
    bool handleNotPositiveHp(); // return if knight is alive after handling
    bool handleDecreaseHP(bool gil_rescue=true); // call when hp is decreased, return if knight is alive after handling

public:
    BaseKnight(int id, int maxhp, int hp, int level, int gil, bool poisoned);
    virtual ~BaseKnight();

    bool isPoisoned() const;
    void setPoisoned(bool poisoned);
    int gethp() const;
    bool sethp(int hp, bool gil_rescue = true); // TODO: when setting, hp must be <= maxhp, return if knight is alive after setting
    bool isAlive() const;
    int getmaxhp() const;
    void setmaxhp(int maxhp);
    KnightType getType() const;
    int getLevel() const;
    void setLevel(int level);
    BaseBag * getBag() const;

    int getGil() const;
    int setGil(int gil); // return remaining gil

    void init(int id, int maxhp, int hp, int level, int gil);
    string toString() const;

    // virtual void fight(BaseOpponent * opponent);
    virtual bool collect(BaseItem * item);
    virtual int getDamage() const = 0;

    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class PaladinKnight : public BaseKnight {
private:
    double baseDamage; // knightBaseDamage
public:
    PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    virtual int getDamage() const;
};

class LancelotKnight : public BaseKnight {
private:
    double baseDamage; // knightBaseDamage
public:
    LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    virtual int getDamage() const;
};

class DragonKnight : public BaseKnight {
private:
    double baseDamage; // knightBaseDamage
public:
    DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    virtual int getDamage() const;
};

class NormalKnight : public BaseKnight {
public:
    NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    virtual int getDamage() const;
};

class ArmyKnights {
private:
    BaseKnight ** al; // arraylist to store list of knights
    int count_; // current number of knights
    int cap; // initial capacity

    bool paladinShield, lancelotSpear,guinevereHair, excaliburSword;
    bool metOmegaWeapon, metHades;

public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;
    BaseKnight * getKnight(int i) const; // get Knight at index i
    bool collect(BaseItem * item);

    bool fight(BaseOpponent * opponent);
    void removeLastKnight();
    void removeKnight(int i);
    void removeAllKnight();

    void receiveGils(int gils);
    void receiveDamage(int damage);

    bool hasPaladinShield() const;
    void setHasPaladinShield(bool has);
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    bool hasMetOmegaWeapon() const;
    void setMetOmegaWeapon(bool met);
    bool hasMetHades() const;
    void setMetHades(bool met);

    void printInfo() const;
    void printResult(bool win) const;
};

class BaseItem {
protected:
    ItemType itemType;
public:
    virtual ~BaseItem() = default;

    virtual bool canUse (BaseKnight * knight) = 0;
    virtual void use (BaseKnight * knight) = 0;

    virtual ItemType getType() const;
    virtual bool isType(ItemType itemType) const; // return if itemType and this->itemType is appropriate, if itemType is PHOENIX, then this->itemTypen could be one of four phoenixdown
};

class Antidote : public BaseItem {
public:
    Antidote();
    virtual bool canUse(BaseKnight * knight);
    virtual void use (BaseKnight * knight);
};

class PhoenixDownI : public BaseItem {
public:
    PhoenixDownI();
    virtual bool canUse(BaseKnight * knight);
    virtual void use (BaseKnight * knight);
};
class PhoenixDownII : public BaseItem {
public:
    PhoenixDownII();
    virtual bool canUse(BaseKnight * knight);
    virtual void use (BaseKnight * knight);
};
class PhoenixDownIII : public BaseItem {
public:
    PhoenixDownIII();
    virtual bool canUse(BaseKnight * knight);
    virtual void use (BaseKnight * knight);
};
class PhoenixDownIV : public BaseItem {
public:
    PhoenixDownIV();
    virtual bool canUse(BaseKnight * knight);
    virtual void use (BaseKnight * knight);
};

class BaseOpponent;

template <typename T>
class Node {
private:
    T data;
    Node * next;
public:
    Node(const T & data, Node * next = nullptr)
        : data(data), next(next) {}
    friend class BaseBag;
};
class BaseBag {
protected:
    BaseKnight * knight;
    Node<BaseItem*> * head;
    int count;

protected:

public:
    BaseBag(BaseKnight * knight, int phoenixdownI, int antidote);
    virtual ~BaseBag();

    virtual bool insertFirst(BaseItem * item);
    virtual void removeFirst(); // remove Node without delete data (equivalent to BaseItem*)
    virtual BaseItem * get(ItemType itemType);

    virtual int getCount() const {return this->count; }
    virtual string toString() const;
};

class BagDragon : public BaseBag {
public:
    BagDragon(BaseKnight * knight, int phoenixdownI, int antidote);
    virtual bool insertFirst(BaseItem * item);
};

class BagLancelot : public BaseBag {
public:
    BagLancelot(BaseKnight * knight, int phoenixdownI, int antidote);
    virtual bool insertFirst(BaseItem * item);
};

class BagNormal : public BaseBag {
public:
    BagNormal(BaseKnight * knight, int phoenixdownI, int antidote);
    virtual bool insertFirst(BaseItem * item);
};

class BagPaladin : public BaseBag {
public:
    BagPaladin(BaseKnight * knight, int phoenixdownI, int antidote);
    virtual bool insertFirst(BaseItem * item);
};

class Events {
private:
    int * al; // array list to hold events
    int cap;
public:
    Events(const string & file_events);
    ~Events();

    int count() const;
    int get(int i) const;
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure();

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__