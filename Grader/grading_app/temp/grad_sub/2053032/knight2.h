#pragma once
#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"
class BaseKnight;
class BaseBag;
class ArmyKnights;

class Events
{
public:
    Events(const string& file_events);
    int count() const;
    int get(int i) const;
    ~Events();

private:
    int* events_list;   // mảng các sự kiện
    int num_events;     // số lượng các sự kiện
};
//done


enum ItemType
{
    ANTIDOTE = 0,
    PHOENIXDOWN_I,
    PHOENIXDOWN_II,
    PHOENIXDOWN_III,
    PHOENIXDOWN_IV
};
//done
enum KnightType
{
    PALADIN = 0,
    LANCELOT,
    DRAGON,
    NORMAL
};
//done
class BaseItem
{
public:
    ItemType item;
    BaseItem(ItemType itemtype);
    virtual bool canUse(BaseKnight* knight) = 0;
    virtual void use(BaseKnight* knight) = 0;

};

class Antidote : public BaseItem
{
public:
    Antidote();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownI : public BaseItem
{
public:
    PhoenixDownI();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownII : public BaseItem
{
public:
    PhoenixDownII();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownIII : public BaseItem
{
public:
    PhoenixDownIII();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownIV : public BaseItem
{
public:
    PhoenixDownIV();

    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};



class BaseKnight
{
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    bool isPoisoned;
    BaseBag* bag;
    KnightType knightType;

public:
    BaseKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType);
    static bool isPrime(int n);
    static bool ispyThagoras(int n);
    static BaseKnight* create(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote);
    string toString() const;
public:
    friend ArmyKnights;
    friend PhoenixDownI;
    friend PhoenixDownII;
    friend PhoenixDownIII;
    friend PhoenixDownIV;
    friend Antidote;
};

class PaladinKnight : public BaseKnight
{
public:
    PaladinKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType);
};
class LancelotKnight : public BaseKnight
{
public:
    LancelotKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType);
};
class DragonKnight : public BaseKnight
{
public:
    DragonKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType);
};
class NormalKnight : public BaseKnight
{
public:
    NormalKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType);
};

class BaseOpponent
{
protected:
    int baseDamage, gil, levelO, eventid, UltiHP;
    bool appear;
    string OpponentType;

public:
    friend ArmyKnights;
    friend PhoenixDownI;
    friend PhoenixDownII;
    friend PhoenixDownIII;
    friend PhoenixDownIV;
    friend Antidote;
    BaseOpponent(string OpponentType, int baseDamage, int gil, int eventid);
    BaseOpponent(string OpponentType, int eventid, bool appear);
};
class MadBear : public BaseOpponent
{
public:

    MadBear(int i);

};
class Bandit : public BaseOpponent
{
public:
    Bandit(int i);
};
class LordLupin : public BaseOpponent
{
public:
    LordLupin(int i);
};
class Elf : public BaseOpponent
{
public:
    Elf(int i);
};
class Troll : public BaseOpponent
{
public:
    Troll(int i);
};
class Tornbery : public BaseOpponent
{
public:
    Tornbery(int i);
};
class QueenofCards : public BaseOpponent
{
public:
    QueenofCards(int i);
};
class NinaDeRings : public BaseOpponent
{
public:
    NinaDeRings();
};
class DurianGarden : public BaseOpponent
{
public:
    DurianGarden();
};
class OmegaWeapon : public BaseOpponent
{
public:
    OmegaWeapon(bool appear);
};
class Hades : public BaseOpponent
{
public:
    Hades(bool appear);
};
class Ultimecia : public BaseOpponent
{
public:
    Ultimecia();
};

// node
class  Node
{
public:
    BaseItem* data;
    Node* next;
    // default
    Node(BaseItem* val) : data(val), next(nullptr) {}
    Node(BaseItem* val, Node* Next) : data(val), next(Next) {}
};

class BaseBag
{
    BaseKnight* knight;

protected:
    Node* head;
    int maxItems;

public:
    friend ArmyKnights;
    BaseBag();
    BaseBag(int maxItems);
    virtual bool insertFirst(BaseItem* item) = 0;
    BaseItem* get(ItemType itemType);
    string toString();
    void deleteItem(BaseItem* prevX);
    int count_Item();
};

class PaladinBag : public BaseBag
{
public:
    PaladinBag();
    bool insertFirst(BaseItem* item);
};
class LancelotBag : public BaseBag
{

public:
    LancelotBag();
    bool insertFirst(BaseItem* item);
};
class DragonBag : public BaseBag
{

public:
    DragonBag();
    bool insertFirst(BaseItem* item);
};
class NormalBag : public BaseBag
{

public:
    NormalBag();
    bool insertFirst(BaseItem* item);
};

class ArmyKnights
{
    BaseKnight** armyknights;
    int armyknightsNum;
    bool has_PaladinShield = false;
    bool has_LancelotSpear = false;
    bool has_GuinevereHair = false;
    bool has_ExcaliburSword = false;

public:
    ArmyKnights(const string& file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent* opponent);
    bool adventure(Events* events);
    int count() const;
    BaseKnight* lastKnight() const;
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    //hamdanhnhau.....
    void handleEvent1_5(int id, BaseOpponent* opponent);
    void handleEventTornbery(int id, BaseOpponent* opponent);
    void handleEventQueenofCards(int id, BaseOpponent* opponent);
    void handleEventNinadeRings(int id, BaseOpponent* opponent);
    void handleEventDurianGarden(int id, BaseOpponent* opponent);
    void handleEventOmegaWeapon(int id, BaseOpponent* opponent);
    void handleEventHades(int id, BaseOpponent* opponent);
    //xu li item,hp,gill,....
    void handleBag(int id, int tempHP);
    void handleHP(int id, int tempHP);
    void handleGill(int id, int tempHP);
    void handleItems(int id, int tempHP);
    //hanhtrinh .....
    BaseOpponent* createOpponent(int eventID, int index, bool appearOmegaWeapon, bool appearHades);
    bool Check(int id, bool& appearOmegaWeapon, bool& appearHades);
    //ham hien thi

    void printInfo() const;
    void printResult(bool win) const;

};

class KnightAdventure
{
private:
    // xu ly, cap nhat hp cua hiep si trong event
    ArmyKnights* armyKnights;
    Events* events;

public:
    KnightAdventure();

    void loadArmyKnights(const string&);
    void loadEvents(const string&);
    void run();
};

#endif // __KNIGHT2_H__