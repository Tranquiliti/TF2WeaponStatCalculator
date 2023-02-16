//======== Made by Tranquility =======//

#include "weapons.h"


const float tickRound(float num) {
    return ceil(roundTo(num / SECONDS_PER_TICK, 3)) * SECONDS_PER_TICK;
}


const float roundTo(float num, int precision) {
    int precisionMult = pow(10, precision);
    return round(num * precisionMult) / precisionMult;
}


Weapon::Weapon() {}


Weapon::Weapon(string weaponName, float baseDamage,
               float attackInterval, float pelletCount) {
    this->weaponName = weaponName;
    this->baseDamage = baseDamage;
    this->attackInterval = attackInterval;
    this->pelletCount = pelletCount;
}


const string Weapon::getWeaponName() {
    return weaponName;
}


const float Weapon::getBaseDamage() {
    return baseDamage;
}


const float Weapon::getAttackInterval() {
    return attackInterval;
}


const float Weapon::getPelletCount() {
    return pelletCount;
}


const int Weapon::getDamagePerShot() {
    return floor(baseDamage * floor(pelletCount));
}


void Weapon::setWeaponName(string newName) {
    weaponName = newName;
}


void Weapon::modifyBaseDamage(float percent) {
    baseDamage = baseDamage * (1.0 + percent/100.0);
}


void Weapon::modifyAttackInterval(float percent) {
    attackInterval = attackInterval * (1.0 - percent/100.0);
}


void Weapon::modifyPelletCount(float percent) {
    pelletCount = pelletCount * (1.0 + percent/100.0);
}


const string Weapon::getWeaponStats() {
    return "--- " + weaponName +
        " ---\nDamage per shot: " + to_string(getDamagePerShot()) +
        "\nAttack Interval: " + to_string(tickRound(attackInterval)) +
        "\nNonstop DPS: " + to_string(getDPS()) + "\n";
}


const double Weapon::getDPS() {
    return getDamagePerShot() / tickRound(attackInterval);
}


ClippedWeapon::ClippedWeapon() {}


ClippedWeapon::ClippedWeapon(string weaponName, float baseDamage,
                             float attackInterval, float pelletCount,
                             int clipSize, float reloadFirst,
                             float reloadConsecutive, bool doesFullReload):
    Weapon(weaponName, baseDamage, attackInterval, pelletCount) {
        this->clipSize = clipSize;
        this->reloadFirst = reloadFirst;
        this->reloadConsecutive = reloadConsecutive;
        this->doesFullReload = doesFullReload;
}


const float ClippedWeapon::getClipSize() {
    return clipSize;
}


const float ClippedWeapon::getFirstReload() {
    return tickRound(reloadFirst);
}


const float ClippedWeapon::getConsecutiveReload() {
    return doesFullReload ? 0 : tickRound(reloadConsecutive);
}


void ClippedWeapon::modifyClipSize(float percent) {
    clipSize = percent < 0 ? round(clipSize * (1.0 + percent/100.0)) : floor(clipSize * (1 + percent/100.0));
}


void ClippedWeapon::modifyReload(float percent) {
    float mult = (1.0 - percent/100.0);
    reloadFirst = reloadFirst * mult;
    reloadConsecutive = reloadConsecutive * mult;
}


const string ClippedWeapon::getWeaponStats() {
    string reloadStat = doesFullReload ?
        "\nReload: " + to_string(getFirstReload()) :
        "\nReload (First): " + to_string(getFirstReload()) +
        "\nReload (Consecutive): " + to_string(getConsecutiveReload()) +
        "\nTime to Full Reload: " + to_string(getFullReloadTime());
    
    return Weapon::getWeaponStats() +
        "Clip Size: " + to_string(clipSize) +
        "\nTime to Empty Clip: " + to_string(getEmptyClipTime()) +
        reloadStat +
        "\nReal DPS: " + to_string(getRealDPS()) + "\n";
}


const float ClippedWeapon::getEmptyClipTime() {
    return tickRound(attackInterval) * clipSize;
}


const float ClippedWeapon::getFullReloadTime() {
    return doesFullReload ? getFirstReload() :
        getFirstReload() + getConsecutiveReload() * (clipSize - 1);
}


const float ClippedWeapon::getRealDPS() {
    float emptyTime = getEmptyClipTime();
    return Weapon::getDPS() * (emptyTime/(emptyTime+getFullReloadTime()));
}


const float SniperRifle::getFullChargeTime() {
    return timeToFullCharge + 0.3;
}


void SniperRifle::modifyFullChargeTime(float percent) {
    timeToFullCharge = timeToFullCharge / (1.0 + percent/100.0);
}


void SniperRifle::modifyChargeMultiplier(float percent) {
    chargeMultiplier = chargeMultiplier * (1.0 + percent/100.0);
}


const string SniperRifle::getWeaponStats() {
    return Weapon::getWeaponStats() +
        "Damage on Full Charge: " + to_string(getChargedDamage()) +
        "\nTime To Full Charge: " + to_string(getFullChargeTime()) +
        "\nCharged DPS: " + to_string(getChargedDPS()) + "\n";
}


const float SniperRifle::getChargedDamage() {
    return getDamagePerShot() * chargeMultiplier;
}


const float SniperRifle::getChargedDPS() {
    return getChargedDamage() / (getFullChargeTime() + tickRound(attackInterval));
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

        auto* isRifled = dynamic_cast<SniperRifle*>(wep);
        if(isRifled) {
            output += "\nCharged DPS: " + to_string(isRifled->getChargedDPS());
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
                      [](Weapon* w1, Weapon* w2) {
                        return w1->getDPS() > w2->getDPS();
                      });
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