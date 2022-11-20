//======== Made by Tranquility =======//

#include "weapons.h"


double tickRound(double num) {
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


double Weapon::getBaseDamage() {
    return baseDamage;
}


double Weapon::getAttackInterval() {
    return attackInterval;
}


int Weapon::getPelletCount(){
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


string Weapon::getWeaponStats() {
    return "--- " + weaponName +
        " ---\nDamage per shot: " + to_string(baseDamage * pelletCount) +
        "\nAttack Interval: " + to_string(attackInterval) +
        "\nNonstop DPS: " + to_string(getDPS()) + "\n";
}


double Weapon::getDPS() {
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


double ClippedWeapon::getClipSize() {
    return clipSize;
}


double ClippedWeapon::getFirstReload() {
    return reloadFirst;
}


double ClippedWeapon::getConsecutiveReload() {
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


string ClippedWeapon::getWeaponStats() {
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


double ClippedWeapon::getEmptyClipTime() {
    return attackInterval * clipSize;
}


double ClippedWeapon::getFullReloadTime() {
    return doesFullReload ? reloadFirst :
        reloadFirst + reloadConsecutive * (clipSize - 1);
}


double ClippedWeapon::getRealDPS() {
    double emptyTime = getEmptyClipTime();
    return Weapon::getDPS() * (emptyTime/(emptyTime+getFullReloadTime()));
}
