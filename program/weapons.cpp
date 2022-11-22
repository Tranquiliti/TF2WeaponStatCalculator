//======== Made by Tranquility =======//

#include "weapons.h"


const double tickRound(double num) {
    return round(num / SECONDS_PER_TICK) * SECONDS_PER_TICK;
}


Weapon::Weapon() {}


Weapon::Weapon(string weaponName, double baseDamage,
               double attackInterval, int pelletCount) {
    this->weaponName = weaponName;
    this->baseDamage = baseDamage;
    this->attackInterval = attackInterval;
    this->pelletCount = pelletCount;
}


const string Weapon::getWeaponName() {
    return weaponName;
}


const double Weapon::getBaseDamage() {
    return baseDamage;
}


const double Weapon::getAttackInterval() {
    return attackInterval;
}


const int Weapon::getPelletCount(){
    return pelletCount;
}


void Weapon::setWeaponName(string newName) {
    weaponName = newName;
}


void Weapon::modifyBaseDamage(int percent) {
    baseDamage = round(baseDamage * (1 + percent/100.0));
}


void Weapon::modifyAttackInterval(int percent) {
    attackInterval = 
        tickRound(attackInterval * (1 - percent/100.0));
}


void Weapon::modifyPelletCount(int percent) {
    pelletCount = floor(pelletCount * (1 + percent/100.0));
}


const string Weapon::getWeaponStats() {
    return "--- " + weaponName +
        " ---\nDamage per shot: " + to_string(baseDamage * pelletCount) +
        "\nAttack Interval: " + to_string(attackInterval) +
        "\nNonstop DPS: " + to_string(getDPS()) + "\n";
}


const double Weapon::getDPS() {
    return baseDamage * pelletCount / attackInterval;
}


ClippedWeapon::ClippedWeapon() {}


ClippedWeapon::ClippedWeapon(string weaponName, double baseDamage,
                             double attackInterval, int pelletCount,
                             int clipSize, double reloadFirst,
                             double reloadConsecutive, bool doesFullReload):
    Weapon(weaponName, baseDamage, attackInterval, pelletCount) {
        this->clipSize = clipSize;
        this->reloadFirst = reloadFirst;
        this->reloadConsecutive = reloadConsecutive;
        this->doesFullReload = doesFullReload;
}


const double ClippedWeapon::getClipSize() {
    return clipSize;
}


const double ClippedWeapon::getFirstReload() {
    return reloadFirst;
}


const double ClippedWeapon::getConsecutiveReload() {
    return doesFullReload ? 0 : reloadConsecutive;
}


void ClippedWeapon::modifyClipSize(int percent) {
    clipSize = percent < 0 ? round(clipSize * (1 + percent/100.0)) :
        floor(clipSize * (1 + percent/100.0));
}


void ClippedWeapon::modifyReload(int percent) {
    double mult = (1 - percent/100.0);
    reloadFirst = tickRound(reloadFirst * mult);
    reloadConsecutive = tickRound(reloadConsecutive * mult);
}


const string ClippedWeapon::getWeaponStats() {
    string reloadStat = doesFullReload ?
        "\nReload: " + to_string(reloadFirst) :
        "\nReload (First): " + to_string(reloadFirst) +
        "\nReload (Consecutive): " + to_string(reloadConsecutive) +
        "\nTime to Full Reload: " + to_string(getFullReloadTime());
    return Weapon::getWeaponStats() +
        "Clip Size: " + to_string(clipSize) +
        "\nTime to Empty Clip: " + to_string(getEmptyClipTime()) +
        reloadStat +
        "\nReal DPS: " + to_string(getRealDPS()) + "\n";
}


const double ClippedWeapon::getEmptyClipTime() {
    return attackInterval * clipSize;
}


const double ClippedWeapon::getFullReloadTime() {
    return doesFullReload ? reloadFirst :
        reloadFirst + reloadConsecutive * (clipSize - 1);
}


const double ClippedWeapon::getRealDPS() {
    double emptyTime = getEmptyClipTime();
    return Weapon::getDPS() * (emptyTime/(emptyTime+getFullReloadTime()));
}


WeaponManager::WeaponManager() {
    weapons = vector<Weapon*>();
}


void WeaponManager::addWeapon(Weapon* wep) {
    weapons.emplace_back(wep);
}


const string WeaponManager::printWeaponStats() {
    string output = "";
    for(Weapon* wep : weapons) {
        output += wep->getWeaponStats() + "\n";
    }
    return output;
}


const string WeaponManager::printWeaponDPS() {
    string output = "";
    for(Weapon* wep : weapons) {
        output += "--- " + wep->getWeaponName() +
            " ---\nNonstop DPS: " + to_string(wep->getDPS());
        auto* isClipped = dynamic_cast<ClippedWeapon*>(wep);
        if(isClipped) {
            output += "\nReal DPS: " + to_string(isClipped->getRealDPS());
        }
        output += "\n\n";
    }
    return output;
}


void WeaponManager::sort(SortType stat) {
    switch(stat) {
        case Name: // Sort in ascending order
            std::sort(weapons.begin(), weapons.end(),
                      [](Weapon* w1, Weapon* w2) {
                        return w1->getWeaponName() < w2->getWeaponName();
                      });
            break;
        case AttackInterval: // Sort in descending order
            std::sort(weapons.begin(), weapons.end(),
                      [](Weapon* w1, Weapon* w2) {
                        return w1->getAttackInterval() > w2->getAttackInterval();
                      });
            break;
        case NonstopDPS: // Sort in descending order
            std::sort(weapons.begin(), weapons.end(),
                      [](Weapon* w1, Weapon* w2)
                      {return w1->getDPS() > w2->getDPS();});
            break;
        case RealDPS: // Sort in descending order
            std::sort(weapons.begin(), weapons.end(),
                      [](Weapon* w1, Weapon* w2) {
                        auto* nw1 = dynamic_cast<ClippedWeapon*>(w1);
                        double nw1DPS = nw1 ? nw1->getRealDPS() : w1->getDPS();
                        auto* nw2 = dynamic_cast<ClippedWeapon*>(w2);
                        double nw2DPS = nw2 ? nw2->getRealDPS() : w2->getDPS();
                        return nw1DPS > nw2DPS;
                      });
            break;
    }
}
