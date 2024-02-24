#include "knight2.h"

/* * * BEGIN implementation of class Utils * * */
bool Utils::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool Utils::is888(int n) {
    return n == 888;
}

bool Utils::isPythagoras(int n) {
    if (n < 100 || n > 999) {
        return false;
    }
    return (n == 345 || n == 354 || n == 435 || n == 453 || n == 534 || n == 543);
}
/* * * END implementation of class Utils * * */

/* * * BEGIN implementation of class BaseOpponent * * */
OpponentWithLevel::OpponentWithLevel(int event_index, int event_id) {
    this->levelO = (event_index + event_id) % 10 + 1;
}

bool OpponentWithLevel::isKnightWinsOpponent(BaseKnight * knight) {
    return knight->getLevel() >= this->levelO;
}

OpponentWithDamageGil::OpponentWithDamageGil(int event_index, int event_id, int baseDamage, int offeredGil)
    : OpponentWithLevel(event_index, event_id), baseDamage(baseDamage), offeredGil(offeredGil) {}

bool OpponentWithDamageGil::isKnightWinsOpponent(BaseKnight * knight) {
    if (knight->getType() == LANCELOT) {
        return true;
    }
    if (knight->getType() == PALADIN) {
        return true;
    }

    return OpponentWithLevel::isKnightWinsOpponent(knight);
}

int OpponentWithDamageGil::getDamage(BaseKnight * knight) const {
    return this->baseDamage * (this->levelO - knight->getLevel());
}

void OpponentWithDamageGil::acceptFight(ArmyKnights * armyKnights) {
    BaseKnight * lknight = armyKnights->lastKnight();
    if (this->isKnightWinsOpponent(lknight)) {
        armyKnights->receiveGils(this->offeredGil);
    }
    else {
        armyKnights->receiveDamage(this->getDamage(lknight));
    }
}

MadBear::MadBear(int event_index, int event_id)
    : OpponentWithDamageGil(event_index, event_id, 10, 100) {}

Bandit::Bandit(int event_index, int event_id)
    : OpponentWithDamageGil(event_index, event_id, 15, 150) {}

LordLupin::LordLupin(int event_index, int event_id)
    : OpponentWithDamageGil(event_index, event_id, 45, 450) {}

Elf::Elf(int event_index, int event_id)
    : OpponentWithDamageGil(event_index, event_id, 75, 750) {}

Troll::Troll(int event_index, int event_id)
    : OpponentWithDamageGil(event_index, event_id, 95, 800) {}

Tornbery::Tornbery(int event_index, int event_id)
    : OpponentWithLevel(event_index, event_id) {
    }

void Tornbery::acceptFight(ArmyKnights * armyKnights) {
    BaseKnight * lknight = armyKnights->lastKnight();
    if (this->isKnightWinsOpponent(lknight)) {
        // win
        // cout << "Tornbery::acceptFight " << "win" << endl;
        lknight->setLevel(lknight->getLevel() + 1);
    }
    else if (lknight->getType() == DRAGON) {
        // khong bi trung doc
    }
    else {
        // bi trung doc
        lknight->setPoisoned(true);
        BaseItem * antidote = lknight->getBag()->get(ANTIDOTE);
        if (antidote != NULL) {
            antidote->use(lknight);
            delete antidote;
        }
        else {
            // khong tim thay thuoc giai antidote
            int dropN = min(3, lknight->getBag()->getCount());
            for (int i = 0; i < dropN; ++i) {
                lknight->getBag()->removeFirst();
            }
            
            if (!lknight->sethp(lknight->gethp() - 10)) {
                // Note: Hiep si hy sinh, xoa hiep si khoi army
                armyKnights->removeLastKnight();
            }
            // het trang thai trung doc
            lknight->setPoisoned(false);
        }
    }
}

QueenOfCards::QueenOfCards(int event_index, int event_id)
    : OpponentWithLevel(event_index, event_id) {}

void QueenOfCards::acceptFight(ArmyKnights * armyKnights) {
    BaseKnight * lknight = armyKnights->lastKnight();
    if (lknight->getType() == PALADIN) {
        if (this->isKnightWinsOpponent(lknight)) {
            // win
            armyKnights->receiveGils(lknight->getGil());
        }
        else {
            // lose -> Paladin khong bi tru tien
        }
    }
    else {
        if (this->isKnightWinsOpponent(lknight)) {
            // win
            armyKnights->receiveGils(lknight->getGil());
        }
        else {
            // lose
            lknight->setGil(lknight->getGil() - lknight->getGil()/2);
        }
    }
}

void NinaDeRings::acceptFight(ArmyKnights * armyKnights) {
    BaseKnight * lknight = armyKnights->lastKnight();
    if (lknight->getType() == PALADIN) {
        if (lknight->gethp() < lknight->getmaxhp()/3) {
            lknight->sethp(lknight->gethp() + lknight->getmaxhp() / 5);
        }
    }
    else {
        if (lknight->getGil() >= 50) {
            if (lknight->gethp() < lknight->getmaxhp() / 3) {
                lknight->setGil(lknight->getGil() - 50);
                lknight->sethp(lknight->gethp() + lknight->getmaxhp() / 5);
            }
        }
    }
}

void DurianGarden::acceptFight(ArmyKnights * armyKnights) {
    BaseKnight * lknight = armyKnights->lastKnight();
    lknight->sethp(lknight->getmaxhp());
}

bool OmegaWeapon::isKnightWinsOpponent(BaseKnight * knight) {
    return (knight->getLevel() == 10 && knight->gethp() == knight->getmaxhp()) || (knight->getType() == DRAGON);
}

void OmegaWeapon::acceptFight(ArmyKnights * armyKnights) {
    if (armyKnights->hasMetOmegaWeapon()) {
        return;
    }

    BaseKnight * lknight = armyKnights->lastKnight();
    if (this->isKnightWinsOpponent(lknight)) {
        lknight->setLevel(10);
        lknight->setGil(999);
        armyKnights->setMetOmegaWeapon(true);
    }
    else {
        if (!lknight->sethp(0)) {
            // Note: Hiep si hy sinh, xoa hiep si khoi army
            armyKnights->removeLastKnight();
        }
    }
}

bool Hades::isKnightWinsOpponent(BaseKnight * knight) {
    return ((knight->getType() == NORMAL && knight->getLevel() == 10) || (knight->getType() == PALADIN && knight->getLevel() >= 8));
}

void Hades::acceptFight(ArmyKnights * armyKnights) {
    if (armyKnights->hasMetHades()) {
        return;
    }

    BaseKnight * lknight = armyKnights->lastKnight();
    
    if (this->isKnightWinsOpponent(lknight)) {
        armyKnights->setHasPaladinShield(true);
        armyKnights->setMetHades(true);
    }
    else {
        if (!lknight->sethp(0)) {
            // Note: Hiep si hy sinh, xoa hiep si khoi army
            armyKnights->removeLastKnight();
        }
    }
}

void Ultimecia::acceptFight(ArmyKnights * armyKnights) {
    if (armyKnights->hasExcaliburSword()) {
        // win;
        return;
    }
    else if (armyKnights->hasPaladinShield() && armyKnights->hasLancelotSpear() && armyKnights->hasGuinevereHair()) {
        int UltimeciaHP = 5000;
        BaseKnight * knight;
        for (int i = armyKnights->count()-1; i >= 0; --i) {
            knight = armyKnights->getKnight(i);
            if (knight->getType() != NORMAL) {
                UltimeciaHP -= knight->getDamage();
                if (UltimeciaHP > 0) {
                    armyKnights->removeKnight(i);
                }
                else {
                    break;
                }
            }
        }

        if (UltimeciaHP > 0) {
            armyKnights->removeAllKnight();
        }
    }
    else {
        armyKnights->removeAllKnight();
    }
}

/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class BaseBag * * */
BaseBag::~BaseBag() {
    Node<BaseItem*> * pCur = head;
    while (pCur != NULL) {
        Node<BaseItem*> * pDel = pCur;
        pCur = pCur->next;
        delete pDel;
    }
}

BaseBag::BaseBag(BaseKnight * knight, int phoenixdownI, int antidote) 
    : knight(knight), head(nullptr), count(0) {
    if (phoenixdownI > 0) {
        for (int i = 0; i < phoenixdownI; ++i) {
            this->insertFirst(new PhoenixDownI());
        }
    }
    if (antidote > 0) {
        for (int i = 0; i < antidote; ++i) {
            this->insertFirst(new Antidote());
        }
    }
}
bool BaseBag::insertFirst(BaseItem * item) {
    Node<BaseItem*> * pNew = new Node<BaseItem*>(item);

    if (head == NULL) {
        head = pNew;
        ++count;
    }
    else {
        pNew->next = head;
        head = pNew;
        ++count;
    }
    return true;
}

void BaseBag::removeFirst() {
    if (count == 0) {
        throw out_of_range("removeFirst(): Empty BaseBag");
    }
    if (count == 1) {
        delete head;
        head = NULL;
        --count;
    }
    else {
        auto temp = this->head;
        head = head->next;
        delete temp;
        --count;
    }
}

BaseItem * BaseBag::get(ItemType itemType) {
    Node<BaseItem*> * p = this->head;
    BaseItem * ret = NULL;
    while (p != NULL) {
        if (p->data->isType(itemType) && p->data->canUse(this->knight)) {
            ret = p->data;
            break;
        }
        p = p->next;
    }

    if (ret != NULL) {
        // found! remove that Item
        swap(head->data, p->data);
        this->removeFirst();
    }

    return ret;
}

string BaseBag::toString() const {
    string typeString[5] = {"Antidote", "PhoenixI", "PhoenixII", "PhoenixIII", "PhoenixIV"};

    stringstream ss;
    ss << "Bag[count=" << this->count << ";";
    auto p = this->head;

    if (this->count > 0) {
        ss << typeString[p->data->getType()];
        p = p->next;
        for (int i = 1; i < this->count; ++i) {
            ss << "," << typeString[p->data->getType()];
            p = p->next;
        }
    }

    ss << "]";

    return ss.str();
}

BagDragon::BagDragon(BaseKnight * knight, int phoenixdownI, int antidote)
    : BaseBag(knight, phoenixdownI, antidote) {}

bool BagDragon::insertFirst(BaseItem * item) {
    if (item->getType() == ANTIDOTE) {
        return false;
    }
    if (this->count == 14) {
        return false;
    }
    return BaseBag::insertFirst(item);
}

BagLancelot::BagLancelot(BaseKnight * knight, int phoenixdownI, int antidote)
    : BaseBag(knight, phoenixdownI, antidote) {}

bool BagLancelot::insertFirst(BaseItem * item) {
    if (this->count == 16) {
        return false;
    }
    return BaseBag::insertFirst(item);
}

BagNormal::BagNormal(BaseKnight * knight, int phoenixdownI, int antidote)
    : BaseBag(knight, phoenixdownI, antidote) {}

bool BagNormal::insertFirst(BaseItem * item) {
    if (this->count == 19) {
        return false;
    }
    return BaseBag::insertFirst(item);
}

BagPaladin::BagPaladin(BaseKnight * knight, int phoenixdownI, int antidote)
    : BaseBag(knight, phoenixdownI, antidote) {}

bool BagPaladin::insertFirst(BaseItem * item) {
    return BaseBag::insertFirst(item);
}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseItem * * */
bool BaseItem::isType(ItemType itemType) const {
    if (itemType == PHOENIX) {
        return this->itemType == PHOENIXI || this->itemType == PHOENIXII || this->itemType == PHOENIXIII || this->itemType == PHOENIXIV;
    }
    else {
        return this->itemType == itemType;
    }
}

ItemType BaseItem::getType() const {
    return this->itemType;
}

Antidote::Antidote() {
    this->itemType = ANTIDOTE;
}
bool Antidote::canUse(BaseKnight * knight) {
    return knight->isPoisoned();
}
void Antidote::use(BaseKnight * knight) {
    knight->setPoisoned(false);
}

PhoenixDownI::PhoenixDownI() {
    this->itemType = PHOENIXI;
}
bool PhoenixDownI::canUse(BaseKnight * knight) {
    return knight->gethp() <= 0;
}
void PhoenixDownI::use(BaseKnight * knight) {
    knight->sethp(knight->getmaxhp());
}

PhoenixDownII::PhoenixDownII() {
    this->itemType = PHOENIXII;
}
bool PhoenixDownII::canUse(BaseKnight * knight) {
    return knight->gethp() < (knight->getmaxhp() / 4);
}
void PhoenixDownII::use(BaseKnight * knight) {
    knight->sethp(knight->getmaxhp());
}

PhoenixDownIII::PhoenixDownIII() {
    this->itemType = PHOENIXIII;
}
bool PhoenixDownIII::canUse(BaseKnight * knight) {
    return knight->gethp() < (knight->getmaxhp() / 3);
}
void PhoenixDownIII::use(BaseKnight * knight) {
    if (knight->gethp() <= 0) {
        knight->sethp(knight->getmaxhp() / 3);
    }
    else {
        knight->sethp(knight->gethp() + knight->getmaxhp() / 4);
    }
}

PhoenixDownIV::PhoenixDownIV() {
    this->itemType = PHOENIXIV;
}
bool PhoenixDownIV::canUse(BaseKnight * knight) {
    return knight->gethp() < (knight->getmaxhp() / 2);
}
void PhoenixDownIV::use(BaseKnight * knight) {
    if (knight->gethp() <= 0) {
        knight->sethp(knight->getmaxhp() / 2);
    }
    else {
        knight->sethp(knight->gethp() + knight->getmaxhp() / 5);
    }
}
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class BaseKnight * * */
void BaseKnight::setPoisoned(bool poisoned) {
    this->poisoned = poisoned;
}

bool BaseKnight::isPoisoned() const {
    return this->poisoned;
}

int BaseKnight::gethp() const {
    return this->hp;
}

int BaseKnight::getmaxhp() const {
    return this->maxhp;
}

bool BaseKnight::isAlive() const {
    return this->hp > 0;
}

bool BaseKnight::handleNotPositiveHp() {
    // Precondition: hp <= 0
    // Return: true if knight is alive after handling, false otherwise
    // Tim PhoenixDown va su dung
    BaseItem * item = this->bag->get(PHOENIXI);
    if (item != NULL ) {
        item->use(this);
        delete item;
        return true;
    }
    else {
        if (this->gil >= 100) {
            this->gil -= 100;
            this->sethp(this->maxhp / 2);
            return true;
        }
        else {
            return false;
        }
    }
}

bool BaseKnight::handleDecreaseHP(bool gil_rescue) {
    // Precondition: call when hp is decreased
    // Return: true if knight is alive after handling, false otherwise
    BaseItem * item = this->bag->get(PHOENIX);
    if (item != NULL ) {
        item->use(this);
        delete item;
        return true;
    }
    else if (this->hp <= 0) {
        if (! gil_rescue) {
            return false;
        }
        if (this->gil >= 100) {
            this->gil -= 100;
            this->sethp(this->maxhp / 2);
            return true;
        }
        else {
            return false;
        }
        // return false;
    }
    return false;
}

bool BaseKnight::sethp(int hp, bool gil_rescue) {
    // Note: when setting, hp must be <= maxhp, return if knight is alive after setting
    int dup_hp = this->hp;
    this->hp = hp;
    if (hp > dup_hp) {
        if (this->hp > this->maxhp) {
            this->hp = this->maxhp;
        }
    }
    else if (hp < dup_hp) { // new_hp < dup_hp => decrease
        this->handleDecreaseHP(gil_rescue);
        // if (this->hp <= 0) {
        //     this->handleNotPositiveHp();
        // }
    }
    return this->isAlive();
}

BaseBag * BaseKnight::getBag() const {
    return this->bag;
}

int BaseKnight::getLevel() const {
    return this->level;
}

void BaseKnight::setLevel(int level) {
    this->level = level;
    if (this->level > 10) {
        this->level = 10;
    }
}

int BaseKnight::getGil() const {
    return this->gil;
}

int BaseKnight::setGil(int gil) {
    // - return: 0 if no gil remaining
    //          remaining gil if 'gil' + current gil > 999
    this->gil = gil;
    if (this->gil > 999) {
        int remain = this->gil - 999;
        this->gil = 999;
        return remain;
    }
    else {
        return 0;
    }
}

BaseKnight::BaseKnight(int id, int maxhp, int hp, int level, int gil, bool poisoned)
    : id(id), maxhp(maxhp), hp(hp), level(level), gil(gil), poisoned(poisoned), bag(NULL) {}

BaseKnight::~BaseKnight() {
    if (bag != NULL) {
        delete bag;
    }
}
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version
    stringstream ss;
    ss << "[Knight:id:" << id
        << ",hp:" << hp
        << ",maxhp:" << maxhp
        << ",level:" << level
        << ",gil:" << gil
        << ","
        << bag->toString()
        << ",knight_type:" << typeString[knightType]
        << "]";
    
    return ss.str();
}

KnightType BaseKnight::getType() const {
    return this->knightType;
}

void BaseKnight::init(int id, int maxhp, int hp, int level, int gil) {
    this->id = id;
    this->maxhp = maxhp;
    this->hp = hp;
    this->level = level;
    this->gil = gil;
}

bool BaseKnight::collect(BaseItem * item) {
    // - return: if the knight can hold this item
    return this->bag->insertFirst(item);
}

BaseKnight * BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    if (Utils::isPrime(maxhp)) {
        return new PaladinKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else if (Utils::is888(maxhp)) {
        return new LancelotKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else if (Utils::isPythagoras(maxhp)) {
        return new DragonKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else {
        return new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    }
}

PaladinKnight::PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, maxhp, level, gil, false) {
    this->bag = new BagPaladin(this, phoenixdownI, antidote);
    this->knightType = PALADIN;
    this->baseDamage = 0.06;
}

int PaladinKnight::getDamage() const {
    return this->hp * this->level * this->baseDamage;
}

LancelotKnight::LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, maxhp, level, gil, false) {
    this->bag = new BagLancelot(this, phoenixdownI, antidote);
    this->knightType = LANCELOT;
    this->baseDamage = 0.05;
}

int LancelotKnight::getDamage() const {
    return this->hp * this->level * this->baseDamage;
}

DragonKnight::DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, maxhp, level, gil, false) {
    this->bag = new BagDragon(this, phoenixdownI, antidote);
    this->knightType = DRAGON;
    this->baseDamage = 0.075;
}

int DragonKnight::getDamage() const {
    return this->hp * this->level * this->baseDamage;
}

NormalKnight::NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) : BaseKnight(id, maxhp, maxhp, level, gil, false) {
    this->bag = new BagNormal(this, phoenixdownI, antidote);
    this->knightType = NORMAL;
}

int NormalKnight::getDamage() const {
    return 0;
}

/* * * END implementation of class BaseKnight * * */


/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::receiveDamage(int damage) {
    BaseKnight * lknight = this->lastKnight();
    lknight->sethp(lknight->gethp() - damage);
    if (!lknight->isAlive()) {
        this->removeLastKnight();
    }
}

bool ArmyKnights::hasMetOmegaWeapon() const {
    return this->metOmegaWeapon;
}

void ArmyKnights::setMetOmegaWeapon(bool met) {
    this->metOmegaWeapon = met;
}

bool ArmyKnights::hasMetHades() const {
    return this->metHades;
}

void ArmyKnights::setMetHades(bool met) {
    this->metHades = met;
}

void ArmyKnights::removeLastKnight() {
    this->removeKnight(this->count_ - 1);
}

void ArmyKnights::removeKnight(int i) {
    if (this->count_ == 0) {
        throw runtime_error("No knight to remove");
    }

    delete this->al[i];
    this->al[i] = NULL;
    --this->count_;
}

void ArmyKnights::removeAllKnight() {
    for (int i = 0; i < this->count_; ++i) {
        if (this->al[i] != NULL) {
            delete this->al[i];
            this->al[i] = NULL;
        }
    }
    delete [] this->al;
    this->al = NULL;
    this->count_ = this->cap = 0;
}

void ArmyKnights::receiveGils(int gils) {
    // gil la so tien duoc nhan them
    int remain = gils;
    BaseKnight * knight;
    for (int i = this->count_ - 1; i >= 0; --i) {
        knight = al[i];
        remain = knight->setGil(knight->getGil() + remain);
        if (remain == 0) {
            break;
        }
    }
}

ArmyKnights::ArmyKnights(const string & file_armyknights) {
    ifstream ifs;
    ifs.open(file_armyknights);
    if (ifs.fail()) {
        cout << "Error when open file: " << file_armyknights << endl;
        exit(1);
    }

    string line;
    getline(ifs, line); // number of knight

    this->count_ = this->cap = stoi(line);
    this->al = new BaseKnight*[this->cap];

    int hp, level, phoenixdonwI, gil, antidote, id;
    for (int i = 0; i < this->cap; ++i) {
        getline(ifs, line);
        stringstream ss(line);

        ss >> hp >> level >> phoenixdonwI >> gil >> antidote;
        id = i + 1;
        this->al[i] = BaseKnight::create(id, hp, level, gil, antidote, phoenixdonwI);
    }

    ifs.close();

    this->paladinShield = false;
    this->lancelotSpear = false;
    this->guinevereHair = false;
    this->excaliburSword = false;

    this->metOmegaWeapon = false;
    this->metHades = false;
}

ArmyKnights::~ArmyKnights() {
    this->removeAllKnight();
}

bool ArmyKnights::collect(BaseItem * item) {
    for (int i = count_-1; i >= 0; --i) {
        if (al[i]->collect(item)) {
            return true;
        }
    }
    return false;
}

bool ArmyKnights::fight(BaseOpponent * opponent) {
    int dup_count = this->count_;
    opponent->acceptFight(this);
    return this->count_ == dup_count; // last knight is alive
}

bool ArmyKnights::adventure(Events * events) {
    int event_id;
    BaseKnight * lknight; // last knight
    for (int i = 0; i < events->count(); ++i) {
        lknight = this->lastKnight(); // not NULL on first iteration

        event_id = events->get(i);
        if (event_id == 112) {
            this->collect(new PhoenixDownII());
        }
        else if (event_id == 113) {
            this->collect(new PhoenixDownIII());
        }
        else if (event_id == 114) {
            this->collect(new PhoenixDownIV());
        }
        else if (event_id == 95) {
            this->paladinShield = true;
        }
        else if (event_id == 96) {
            this->lancelotSpear = true;
        }
        else if (event_id == 97) {
            this->guinevereHair = true;
        }
        else if (event_id == 98) {
            this->excaliburSword = (this->paladinShield && this->lancelotSpear && this->guinevereHair);
        }
        else {
            // Meet Opponent
            BaseOpponent * opponent = NULL;
            if (event_id == 1) {
                opponent = new MadBear(i, event_id);
            }
            else if (event_id == 2) {
                opponent = new Bandit(i, event_id);
            }
            else if (event_id == 3) {
                opponent = new LordLupin(i, event_id);
            }
            else if (event_id == 4) {
                opponent = new Elf(i, event_id);
            }
            else if (event_id == 5) {
                opponent = new Troll(i, event_id);
            }
            else if (event_id == 6) {
                opponent = new Tornbery(i, event_id);
            }
            else if (event_id == 7) {
                opponent = new QueenOfCards(i, event_id);
            }
            else if (event_id == 8) {
                opponent = new NinaDeRings();
            }
            else if (event_id == 9) {
                opponent = new DurianGarden();
            }
            else if (event_id == 10) {
                opponent = new OmegaWeapon();
            }
            else if (event_id == 11) {
                opponent = new Hades();
            }
            else if (event_id == 99) {
                opponent = new Ultimecia();
            }
            else {
                cout << "Invalid event id: " << event_id << endl;
                exit(1);
            }
            this->fight(opponent);
            delete opponent;
        }

        this->printInfo();

        if (this->count_ == 0) {
            // after handle event, the army become empty -> lose
            return false;
        }
    }
    return true;
}

int ArmyKnights::count() const {
    return this->count_;
}

BaseKnight * ArmyKnights::lastKnight() const {
    if (this->count_ == 0) {
        return NULL;
    }
    else {
        for (int i = this->count_-1; i >= 0; --i) {
            if (this->al[i] != NULL) {
                return this->al[i];
            }
        }

        return NULL;
    }
}

BaseKnight * ArmyKnights::getKnight(int i) const {
    return this->al[i];
}

bool ArmyKnights::hasPaladinShield() const {
    return paladinShield;
}
void ArmyKnights::setHasPaladinShield(bool has) {
    this->paladinShield = has;
}
bool ArmyKnights::hasLancelotSpear() const {
    return lancelotSpear;
}
bool ArmyKnights::hasGuinevereHair() const {
    return guinevereHair;
}
bool ArmyKnights::hasExcaliburSword() const {
    return excaliburSword;
}

void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

KnightAdventure::~KnightAdventure() {
    if (armyKnights) {
        delete armyKnights;
    }
    if (events) {
        delete events;
    }
}

void KnightAdventure::loadArmyKnights(const string & filename) {
    armyKnights = new ArmyKnights(filename);
}

void KnightAdventure::loadEvents(const string & filename) {
    this->events = new Events(filename);
}

void KnightAdventure::run() {
    this->armyKnights->printResult(this->armyKnights->adventure(this->events));
}

/* * * END implementation of class KnightAdventure * * */

/* * * BEGIN implementation of class Events * * */
Events::Events(const string & file_events) {
    ifstream ifs;
    ifs.open(file_events);
    if (ifs.fail()) {
        cout << "Error when open file: " << file_events << endl;
        exit(1);
    }

    string line;
    getline(ifs, line);
    this->cap = stoi(line); // first line => number of events

    getline(ifs, line);
    stringstream ss(line);
    al = new int[this->cap];
    for (int i = 0; i < this->cap; ++i) {
        ss >> al[i];
    }

    ifs.close();
}

Events::~Events() {
    delete [] al;
}

int Events::count() const {
    return this->cap;
}

int Events::get(int i) const {
    return this->al[i];
}

/* * * END implementation of class Events * * */