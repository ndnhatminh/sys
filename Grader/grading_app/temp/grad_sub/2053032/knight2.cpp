#include "knight2.h"
/* * * Begin class Events * * */
// Hàm khởi tạo
Events::Events(const string& file_events)
{
    ifstream fin(file_events);      // mở file để đọc
    fin >> num_events;              // đọc số lượng sự kiện
    events_list = new int[num_events];  // cấp phát động cho mảng events_list
    // đọc các mã sự kiện từ file và lưu vào mảng events_list
    for (int i = 0; i < num_events; i++)
    {
        fin >> events_list[i];
    }

    fin.close();    // đóng file
}
// Hàm đếm số lượng sự kiện
int Events::count() const
{
    return num_events;
}
// Hàm lấy mã sự kiện tại vị trí i trong mảng
int Events::get(int i) const
{

    return events_list[i];
}
// Hàm hủy
Events::~Events()
{
    delete[] events_list;
}
/* * * End class Events * * */
/* * * BEGIN implementation of class BaseOpponent* * */
BaseOpponent::BaseOpponent(string OpponentType, int baseDamage, int gil, int eventid) : OpponentType(OpponentType), baseDamage(baseDamage), gil(gil), eventid(eventid), appear(false) {}
BaseOpponent::BaseOpponent(string OpponentType, int eventid, bool appear) : OpponentType(OpponentType), eventid(eventid), appear(appear) {}
MadBear::MadBear(int i) : BaseOpponent("MadBear", 10, 100, 1) { this->levelO = (i + this->eventid) % 10 + 1; }
Bandit::Bandit(int i) : BaseOpponent("Bandit", 15, 150, 2) { this->levelO = (i + this->eventid) % 10 + 1; }
LordLupin::LordLupin(int i) : BaseOpponent("LordLupin", 45, 450, 3) { this->levelO = (i + this->eventid) % 10 + 1; }
Elf::Elf(int i) : BaseOpponent("Elf", 75, 750, 4) { this->levelO = (i + this->eventid) % 10 + 1; }
Troll::Troll(int i) : BaseOpponent("Troll", 95, 800, 5) { this->levelO = (i + this->eventid) % 10 + 1; }
Tornbery::Tornbery(int i) : BaseOpponent("Tornbery", 0, 0, 6) { this->levelO = (i + this->eventid) % 10 + 1; }
QueenofCards::QueenofCards(int i) : BaseOpponent("QueenofCards", 0, 0, 7) { this->levelO = (i + this->eventid) % 10 + 1; }
NinaDeRings::NinaDeRings() : BaseOpponent("NinadeRings", 0, 0, 8) {}
DurianGarden::DurianGarden() : BaseOpponent("DurianGarden", 0, 0, 9) {}
OmegaWeapon::OmegaWeapon(bool appear) : BaseOpponent("OmegaWeapon", 10, appear) {}
Hades::Hades(bool appear) : BaseOpponent("Hades", 11, appear) {}
Ultimecia::Ultimecia() : BaseOpponent("Ultimecia", 0, 0, 99) { UltiHP = 5000; }
/* * * END implementation of class BaseOpponent * * */
/* * * BEGIN implementation of class BaseKnight * * */
BaseKnight::BaseKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType)
{
    this->id = id;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
    this->hp = maxhp;
    this->knightType = knightType;
    this->isPoisoned = false;
}
bool BaseKnight::isPrime(int n)
{
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
//done
bool BaseKnight::ispyThagoras(int n) {
    int a = n % 10;
    int b = (n / 10) % 10;
    int c = (n / 100) % 10;
    return (a >= 1 && a <= 9 && b >= 1 && b <= 9 && c >= 1 && c <= 9) && ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b));
}
//done
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote)
{
    BaseKnight* knight;
    switch (maxhp) {
    case 888:
        knight = new LancelotKnight(id, maxhp, level, phoenixdownI, gil, antidote, LANCELOT);
        break;
    default:
        if (isPrime(maxhp)) {
            knight = new PaladinKnight(id, maxhp, level, phoenixdownI, gil, antidote, PALADIN);
        }
        else if (ispyThagoras(maxhp)) {
            knight = new DragonKnight(id, maxhp, level, phoenixdownI, gil, antidote, DRAGON);
        }
        else {
            knight = new NormalKnight(id, maxhp, level, phoenixdownI, gil, antidote, NORMAL);
        }
        break;
    }
    return knight;
}
//done
string BaseKnight::toString() const
{
    string typeString[4] = { "PALADIN", "LANCELOT", "DRAGON", "NORMAL" };
    string s("");
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" + to_string(maxhp) + ",level:" + to_string(level) + ",gil:" + to_string(gil) + "," + bag->toString() + ",knight_type:" + typeString[knightType] + "]";
    return s;
}
PaladinKnight::PaladinKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType) : BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote, knightType) {}
LancelotKnight::LancelotKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType) : BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote, knightType) {}
DragonKnight::DragonKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType) : BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote, knightType) {}
NormalKnight::NormalKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote, KnightType knightType) : BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote, knightType) {}
/* * * END implementation of class BaseKnight * * */
/* * * Begin class BaseItem * * */
BaseItem::BaseItem(ItemType itemtype) {
    this->item = itemtype;
}
Antidote::Antidote() :BaseItem(ANTIDOTE) {};
bool Antidote::canUse(BaseKnight* knight)
{
    return knight->isPoisoned;
}
void Antidote::use(BaseKnight* knight)
{
    knight->isPoisoned = false;
}
PhoenixDownI::PhoenixDownI() :BaseItem(PHOENIXDOWN_I) {};
bool PhoenixDownI::canUse(BaseKnight* knight)
{
    return knight->hp <= 0 ? true : false;
}
void PhoenixDownI::use(BaseKnight* knight)
{
    knight->hp = knight->maxhp;
}
PhoenixDownII::PhoenixDownII() :BaseItem(PHOENIXDOWN_II) {};
bool PhoenixDownII::canUse(BaseKnight* knight)
{
    return knight->hp < int((knight->maxhp) / 4) ? true : false;
}
void PhoenixDownII::use(BaseKnight* knight) {
    knight->hp = knight->maxhp;
}
PhoenixDownIII::PhoenixDownIII() :BaseItem(PHOENIXDOWN_III) {};
bool PhoenixDownIII::canUse(BaseKnight* knight)
{
    return knight->hp < int((knight->maxhp) / 3) ? true : false;
}
void PhoenixDownIII::use(BaseKnight* knight)
{
    if (knight->hp <= 0)
        knight->hp = int((knight->maxhp) / 3);
    else
        knight->hp += int((knight->maxhp) / 4);
}
PhoenixDownIV::PhoenixDownIV() :BaseItem(PHOENIXDOWN_IV) {};
bool PhoenixDownIV::canUse(BaseKnight* knight)
{
    return knight->hp < int((knight->maxhp) / 2) ? true : false;
}
void PhoenixDownIV::use(BaseKnight* knight)
{
    if (knight->hp <= 0)
        knight->hp = int((knight->maxhp) / 2);
    else
        knight->hp += int((knight->maxhp) / 5);
}
/* * * END implementation of class BaseItem * * */
/* * * BEGIN implementation of class BaseBag * * */
BaseBag::BaseBag(int maxItems) : head(nullptr), maxItems(maxItems) {}
BaseBag::BaseBag() : head(nullptr) {}
int BaseBag::count_Item()
{
    int count = 0;
    for (Node* temp = head; temp != nullptr; temp = temp->next)
    {
        count++;
    }
    return count;
}
//done
BaseItem* BaseBag::get(ItemType itemType)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data->item == itemType)
        {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
};
//done
void BaseBag::deleteItem(BaseItem* data)
{
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == data) {
            if (prev == nullptr) {
                // Xóa nút đầu tiên
                head = curr->next;
                delete curr;
            }
            else {
                prev->next = curr->next;
                delete curr;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
string BaseBag::toString()
{
    stringstream ss;
    ss << "Bag[count=" << count_Item() << ";";
    Node* curr = head;
    int count = 0;
    if (head == nullptr)
        ss << "]";
    while (curr != nullptr)
    {
        ItemType itemType = curr->data->item;
        switch (itemType)
        {
        case ANTIDOTE:
            ss << "Antidote";
            break;
        case PHOENIXDOWN_I:
            ss << "PhoenixI";
            break;
        case PHOENIXDOWN_II:
            ss << "PhoenixII";
            break;
        case PHOENIXDOWN_III:
            ss << "PhoenixIII";
            break;
        case PHOENIXDOWN_IV:
            ss << "PhoenixIV";
            break;
        }
        count++;
        if (count < count_Item())
            ss << ",";
        else
            ss << "]";
        curr = curr->next;
    }
    return ss.str();
}
PaladinBag::PaladinBag() : BaseBag() {}
bool PaladinBag::insertFirst(BaseItem* item)
{
    Node* new_node = new Node(item);
    new_node->next = head;
    head = new_node;
    return true;
}
LancelotBag::LancelotBag() : BaseBag(16) {}
bool LancelotBag::insertFirst(BaseItem* item)
{
    if (count_Item() == maxItems)
    {
        return false; // danh sách đã đầy
    }
    Node* new_node = new Node(item);
    if (head != nullptr) {
        new_node->next = head;
    }
    head = new_node;
    return true; // chèn thành công
}
DragonBag::DragonBag() : BaseBag(14) {}
bool DragonBag::insertFirst(BaseItem* item)
{
    if (count_Item() == maxItems)
    {
        return false; // danh sách đã đầy
    }
    Node* new_node = new Node(item);
    if (head != nullptr) {
        new_node->next = head;
    }
    head = new_node;
    return true; // chèn thành công
}
NormalBag::NormalBag() : BaseBag(19) {}
bool NormalBag::insertFirst(BaseItem* item)
{
    if (count_Item() == maxItems)
    {
        return false; // danh sách đã đầy
    }
    Node* new_node = new Node(item);
    if (head != nullptr) {
        new_node->next = head;
    }
    head = new_node;
    return true; // chèn thành công
}
/* * * END implementation of class BaseBag * * */
/* * * BEGIN implementation of class ArmyKnights * * */
//hàm khởi tạo
ArmyKnights::ArmyKnights(const string& file_armyknights)
{
    ifstream ifs(file_armyknights);
    string line;
    getline(ifs, line);
    istringstream iss(line);
    iss >> armyknightsNum;
    armyknights = new BaseKnight * [armyknightsNum];
    for (int i = 0; i < armyknightsNum; ++i)
    {
        getline(ifs, line);
        istringstream iss(line);

        int maxhp, level, phoenixdownI, gil, antidote;
        iss >> maxhp >> level >> phoenixdownI >> gil >> antidote;

        armyknights[i] = BaseKnight::create(i + 1, maxhp, level, phoenixdownI, gil, antidote);

        switch (armyknights[i]->knightType) {
        case PALADIN:
            armyknights[i]->bag = new PaladinBag();
            break;
        case LANCELOT:
            armyknights[i]->bag = new LancelotBag();
            break;
        case DRAGON:
            armyknights[i]->bag = new DragonBag();
            break;
        default:
            armyknights[i]->bag = new NormalBag();
        }

        if (armyknights[i]->phoenixdownI > 0) {
            BaseItem* item = new PhoenixDownI();
            for (int j = 0; j < armyknights[i]->phoenixdownI; ++j) {
                armyknights[i]->bag->insertFirst(item);
            }
        }

        if (armyknights[i]->antidote > 0 && armyknights[i]->knightType != DRAGON) {
            BaseItem* item = new Antidote();
            for (int j = 0; j < armyknights[i]->antidote; ++j) {
                armyknights[i]->bag->insertFirst(item);
            }
        }
    }

    ifs.close();
}
//hàm hủy
ArmyKnights::~ArmyKnights()
{
    for (int i = 0; i < armyknightsNum; i++)
        delete armyknights[i];
    delete[] armyknights;
}
//chien dau 
void ArmyKnights::handleEvent1_5(int id, BaseOpponent* opponent)
{
    if (armyknights[id]->level < opponent->levelO && armyknights[id]->knightType != LANCELOT && armyknights[id]->knightType != PALADIN)
        armyknights[id]->hp -= opponent->baseDamage * (opponent->levelO - armyknights[id]->level);
    else if (armyknights[id]->knightType == LANCELOT || armyknights[id]->knightType == PALADIN || armyknights[id]->level >= opponent->levelO)
        armyknights[id]->gil += opponent->gil;
}
void ArmyKnights::handleEventTornbery(int id, BaseOpponent* opponent)
{
    if (armyknights[id]->level >= opponent->levelO)
    {
        armyknights[id]->isPoisoned = false;
        armyknights[id]->level++;
    }
    else if (armyknights[id]->knightType != DRAGON)
        armyknights[id]->isPoisoned = true;
    if (armyknights[id]->isPoisoned == true)
    {
        if (armyknights[id]->bag->get(ANTIDOTE) == nullptr)
        {
            if (armyknights[id]->bag->count_Item() <= 3)
            {
                int del_ = armyknights[id]->bag->count_Item();
                for (int i = 0; i < del_; i++)
                    armyknights[id]->bag->deleteItem(armyknights[id]->bag->head->data);
            }
            else
                for (int i = 0; i < 3; i++)
                    armyknights[id]->bag->deleteItem(armyknights[id]->bag->head->data);
            armyknights[id]->hp -= 10;
        }
    }
};
void ArmyKnights::handleEventQueenofCards(int id, BaseOpponent* opponent)
{
    if (armyknights[id]->level >= opponent->levelO)
        armyknights[id]->gil *= 2;
    else if (armyknights[id]->knightType != PALADIN)
        armyknights[id]->gil = int(armyknights[id]->gil / 2);
};
void ArmyKnights::handleEventNinadeRings(int id, BaseOpponent* opponent)
{
    if (armyknights[id]->gil >= 50 || armyknights[id]->knightType == PALADIN)
        if (armyknights[id]->hp < int((armyknights[id]->maxhp) / 3))
        {
            if (armyknights[id]->knightType != PALADIN)
                armyknights[id]->gil -= 50;
            armyknights[id]->hp += int((armyknights[id]->maxhp) / 5);
        }
}
void ArmyKnights::handleEventDurianGarden(int id, BaseOpponent* opponent)
{
    armyknights[id]->hp = armyknights[id]->maxhp;
}
void ArmyKnights::handleEventOmegaWeapon(int id, BaseOpponent* opponent)
{
    if ((armyknights[id]->hp == armyknights[id]->maxhp && armyknights[id]->level == 10) || armyknights[id]->knightType == DRAGON)
    {
        armyknights[id]->level = 10;
        armyknights[id]->gil = 999;
        opponent->appear = true;
    }
    else
        armyknights[id]->hp = 0;
}
void ArmyKnights::handleEventHades(int id, BaseOpponent* opponent)
{
    if ((armyknights[id]->level == 10) || (armyknights[id]->knightType == PALADIN && armyknights[id]->level >= 8))
    {
        if (this->has_PaladinShield == false)
            this->has_PaladinShield = true;
        opponent->appear = true;
    }
    else
        armyknights[id]->hp = 0;
}
void ArmyKnights::handleBag(int id, int tempHP)
{
    Node* tempNode = armyknights[id]->bag->head;
    while (tempNode != nullptr)
    {
        if ((armyknights[id]->hp < tempHP && tempNode->data->item != ANTIDOTE) || tempNode->data->item == ANTIDOTE)
        {
            if (tempNode->data->canUse(armyknights[id]) == true)
            {
                tempNode->data->use(armyknights[id]);
                BaseItem* data = tempNode->data;
                tempNode = tempNode->next;
                armyknights[id]->bag->deleteItem(data);
                if (armyknights[id]->hp <= 0 && armyknights[id]->bag->count_Item() != 0)
                    continue;
                else
                    break;
            }
            else
                tempNode = tempNode->next;
        }
        else
            tempNode = tempNode->next;
    }
}
void ArmyKnights::handleHP(int id, int tempHP)
{
    if (armyknights[id]->hp <= 0 && armyknights[id]->hp < tempHP)
    {
        if (armyknights[id]->gil >= 100)
        {
            armyknights[id]->gil -= 100;
            armyknights[id]->hp = int(armyknights[id]->maxhp / 2);
        }
    }
    if (armyknights[id]->hp > 999)
        armyknights[id]->hp = 999;
    if (armyknights[id]->level > 10)
        armyknights[id]->level = 10;

}
void ArmyKnights::handleGill(int id, int tempHP)
{
    if (armyknights[id]->gil > 999)
    {
        int t_ = 1;
        int excessive_Gil_ = armyknights[id]->gil - 999;
        armyknights[id]->gil = 999;
        while (excessive_Gil_ > 0)
        {
            if (t_ > id)
                break;
            int excessive_ = 999 - armyknights[id - t_]->gil;
            if (excessive_Gil_ <= excessive_)
            {
                armyknights[id - t_]->gil += excessive_Gil_;
                break;
            }
            else
            {
                armyknights[id - t_]->gil = 999;
                excessive_Gil_ -= excessive_;
            }
            t_++;
        }
    }
}
void ArmyKnights::handleItems(int id, int tempHP) {

    if (armyknights[id]->phoenixdownI > 5)
    {
        int t = 1;
        int excessive_PDI_ = armyknights[id]->phoenixdownI - 5;
        armyknights[id]->phoenixdownI = 5;
        while (excessive_PDI_ > 0)
        {
            if (t > id)
                break;
            int excessive_ = 5 - armyknights[id - t]->phoenixdownI;
            if (excessive_PDI_ <= excessive_)
            {
                armyknights[id - t]->phoenixdownI += excessive_PDI_;
                break;
            }
            else
            {
                armyknights[id - t]->phoenixdownI = 5;
                excessive_PDI_ -= excessive_;
            }
            t++;
        }
    }
    if (armyknights[id]->antidote > 5)
    {
        int t = 1;
        int excessive_Antidote_ = armyknights[id]->antidote - 5;
        armyknights[id]->antidote = 5;
        while (excessive_Antidote_ > 0)
        {
            if (t > id)
                break;
            int excessive = 5 - armyknights[id - t]->antidote;
            if (excessive_Antidote_ <= excessive)
            {
                armyknights[id - t]->antidote += excessive_Antidote_;
                break;
            }
            else
            {
                armyknights[id - t]->antidote = 5;
                excessive_Antidote_ -= excessive;
            }
            t++;
        }
    }
}
bool ArmyKnights::fight(BaseOpponent* opponent)
{
    int id = armyknightsNum - 1;
    int tempHP = armyknights[id]->hp;
    if (opponent->OpponentType == "MadBear" || opponent->OpponentType == "Bandit" || opponent->OpponentType == "LordLupin" || opponent->OpponentType == "Elf" || opponent->OpponentType == "Troll")
    {
        handleEvent1_5(id, opponent);
    }
    else if (opponent->OpponentType == "Tornbery")
    {
        handleEventTornbery(id, opponent);
    }
    else if (opponent->OpponentType == "QueenofCards")
    {
        handleEventQueenofCards(id, opponent);
    }
    else if (opponent->OpponentType == "NinadeRings")
    {
        handleEventNinadeRings(id, opponent);
    }
    else if (opponent->OpponentType == "DurianGarden")
    {
        handleEventDurianGarden(id, opponent);
    }
    else if (opponent->OpponentType == "OmegaWeapon" && opponent->appear == false)
    {
        handleEventOmegaWeapon(id, opponent);
    }
    else if (opponent->OpponentType == "Hades" && opponent->appear == false)
    {
        handleEventHades(id, opponent);
    }
    if (armyknights[id]->bag->count_Item() > 0)
    {
        handleBag(id, tempHP);
    }
    handleHP(id, tempHP);
    handleGill(id, tempHP);
    handleItems(id, tempHP);
    return (armyknights[id]->hp <= 0) ? false : true;
}
//end chien dau 
//hanh trinh 

bool ArmyKnights::adventure(Events* events)
{
    BaseOpponent* opponent;
    BaseItem* item;
    bool appearOmegaWeapon = false;
    bool appearHades = false;
    int i = 0;

    while (i < events->count())
    {
        int eveID = events->get(i);
        if (eveID >= 1 && eveID <= 11)
        {
            opponent = createOpponent(eveID, i, appearOmegaWeapon, appearHades);
            if (Check(eveID, appearOmegaWeapon, appearHades))
            {
                i++;
                printInfo();
                continue;
            }
            if (!fight(opponent))
            {
                if (armyknightsNum > 1)
                {
                    delete armyknights[armyknightsNum - 1];
                    armyknightsNum--;
                }
                else if (armyknightsNum == 1)
                {
                    armyknightsNum--;
                    delete armyknights[0];
                    printInfo();
                    return false;
                }
            }
            else
            {
                if (opponent->OpponentType == "Hades" && opponent->appear == true)
                    appearHades = true;
                if (opponent->OpponentType == "OmegaWeapon" && opponent->appear == true)
                    appearOmegaWeapon = true;
                printInfo();
                i++;
            }
        }
        else
        {
            int id = this->armyknightsNum - 1;
            switch (eveID)
            {
            case 112:
                item = new PhoenixDownII();
                if (armyknights[id]->bag->insertFirst(item) == false)
                {
                    int k = 1;
                    while (k <= id)
                    {
                        if (armyknights[id - k]->bag->insertFirst(item) == false)
                            k++;
                        else
                            break;
                    }
                }
                break;
            case 113:
                item = new PhoenixDownIII();
                if (armyknights[id]->bag->insertFirst(item) == false)
                {
                    int k = 1;
                    while (k <= id)
                    {
                        if (armyknights[id - k]->bag->insertFirst(item) == false)
                            k++;
                        else
                            break;
                    }
                }
                break;
            case 114:
                item = new PhoenixDownIV();
                if (armyknights[id]->bag->insertFirst(item) == false)
                {
                    int k = 1;
                    while (k <= id)
                    {
                        if (armyknights[id - k]->bag->insertFirst(item) == false)
                            k++;
                        else
                            break;
                    }
                }
                break;
            case 95:
                this->has_PaladinShield = true;
                break;
            case 96:
                this->has_LancelotSpear = true;
                break;
            case 97:
                this->has_GuinevereHair = true;
                break;
            case 98:
                if (has_PaladinShield == true && has_LancelotSpear == true && has_GuinevereHair == true)
                    this->has_ExcaliburSword = true;
                else
                    this->has_ExcaliburSword = false;
                break;
            case 99:
                opponent = new Ultimecia;
                if (has_ExcaliburSword == true)
                {
                    printInfo();
                    return true;
                }
                else if (has_LancelotSpear == true && has_PaladinShield == true && has_GuinevereHair == true)
                {
                    int i = this->armyknightsNum - 1;
                    while (i >= 0)
                    {
                        if (armyknights[i]->knightType != NORMAL)
                        {
                            double knightBaseDamage;
                            if (armyknights[i]->knightType == DRAGON)
                                knightBaseDamage = 0.075;
                            else if (armyknights[i]->knightType == PALADIN)
                                knightBaseDamage = 0.06;
                            else if (armyknights[i]->knightType == LANCELOT)
                                knightBaseDamage = 0.05;
                            int UltiDamage = armyknights[i]->hp * armyknights[i]->level * knightBaseDamage;
                            opponent->UltiHP -= UltiDamage;
                            if (opponent->UltiHP > 0)
                            {
                                if (i < armyknightsNum - 1)
                                    for (int j = i; j < this->armyknightsNum - 1; j++)
                                        armyknights[j] = armyknights[j + 1];
                                i--;
                                this->armyknightsNum--;
                            }
                            if (opponent->UltiHP <= 0)
                            {
                                printInfo();
                                return true;
                            }
                        }
                        else
                            i--;
                    }
                    if (opponent->UltiHP > 0)
                        this->armyknightsNum = 0;
                }
                else
                    this->armyknightsNum = 0;
                break;
            }
            printInfo();
            i++;
        }
    }
    return false;

}
BaseOpponent* ::ArmyKnights::createOpponent(int eventID, int i, bool appearOmegaWeapon, bool appearHades)
{
    switch (eventID)
    {
    case 1:
        return new MadBear(i);

    case 2:
        return new Bandit(i);

    case 3:
        return new LordLupin(i);

    case 4:
        return new Elf(i);

    case 5:
        return new Troll(i);

    case 6:
        return new Tornbery(i);

    case 7:
        return new QueenofCards(i);

    case 8:
        return new NinaDeRings();

    case 9:
        return new DurianGarden();

    case 10:
        return  new OmegaWeapon(appearOmegaWeapon);

    case 11:
        return  new Hades(appearHades);
    }

};
bool::ArmyKnights::Check(int id, bool& appearOmegaWeapon, bool& appearHades)
{
    if ((id == 10 && appearOmegaWeapon == true) || (id == 11 && appearHades == true))
    {
        return true;
    }
    return false;
}

//ket thuc hanh trinh
int ArmyKnights::count() const
{
    return this->armyknightsNum;
}
BaseKnight* ArmyKnights::lastKnight() const
{
    return armyknights[armyknightsNum - 1];
}
bool ArmyKnights::hasPaladinShield() const {
    return (this->has_PaladinShield) ? true : false;
}
bool ArmyKnights::hasLancelotSpear() const {
    return (this->has_LancelotSpear) ? true : false;
}
bool ArmyKnights::hasGuinevereHair() const {
    return (this->has_GuinevereHair) ? true : false;
}
bool ArmyKnights::hasExcaliburSword() const {
    return (this->has_ExcaliburSword) ? true : false;
}
void ArmyKnights::printInfo() const
{
    cout << "No. knights: " << this->count();
    if (this->count() > 0)
    {
        BaseKnight* lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}
void ArmyKnights::printResult(bool win) const
{
    cout << (win ? "WIN" : "LOSE") << endl;
}
/* * * END implementation of class ArmyKnights * * */
/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure()
{
    armyKnights = nullptr;
    events = nullptr;
}
void KnightAdventure::loadArmyKnights(const string& file_armyknights)
{
    armyKnights = new ArmyKnights(file_armyknights);
}
void KnightAdventure::loadEvents(const string& file_events)
{
    events = new Events(file_events);
}
void KnightAdventure::run()
{
    if (armyKnights->adventure(events) == true)
        armyKnights->printResult(true);
    else
        armyKnights->printResult(false);
    armyKnights->~ArmyKnights();
    events->~Events();
}
/* * * END implementation of class KnightAdventure * * */