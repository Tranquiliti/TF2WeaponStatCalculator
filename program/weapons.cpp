//======== Made by Tranquility =======//

#include "weapons.h"


/*
    Rounds a number to the nearest TF2 server tick
*/
double tickRound(double d) {
    return round(d / SECONDS_PER_TICK) *  SECONDS_PER_TICK;
}


/*
    Constructs a Weapon with a name, base damage,
    attack interval, and pellet count
*/
Weapon::Weapon(string name, double damage, double atkInt, int pelletCount) {
    weaponName = name;
    baseDamage = damage;
    attackInterval = atkInt;
    numOfPellets = pelletCount;
}


double Weapon::getBaseDamage() {
    return baseDamage;
}


double Weapon::getAttackInterval() {
    return attackInterval;
}


int Weapon::getPelletCount(){
    return numOfPellets;
}


void Weapon::setWeaponName(string s) {
    weaponName = s;
}


/*
    Changes base damage by a percentage
*/
void Weapon::modifyBaseDamage(int m) {
    baseDamage *= (1 + m/100.0);
}


/*
    Changes attack interval by a percentage,
    rounded to the nearest server tick
*/
void Weapon::modifyAttackInterval(int m) {
    attackInterval = 
        tickRound(attackInterval * (1 - m/100.0));
}


/*
    Changes pellet count by a percentage,
    rounded down to an integer
*/
void Weapon::modifyPelletCount(int m) {
    numOfPellets = floor(numOfPellets * (1 + m/100.0));
}


string Weapon::getWeaponStats() {
    return "--- " + weaponName +
        " ---\nDamage per shot: " + to_string(baseDamage * numOfPellets) +
        "\nAttack Interval: " + to_string(attackInterval) +
        "\nNonstop DPS: " + to_string(getDPS()) + "\n";
}


/*
    Returns the Weapon DPS, assuming nonstop DPS
*/
double Weapon::getDPS() {
    return baseDamage * numOfPellets / attackInterval;
}


/*
    Constructs a Weapon with a name, base damage, attack interval,pellet count,
    clip size, first reload time, and consecutive reload time.
    Can either fully reload entire clip at once or load it one ammo at a time.
*/
ClippedWeapon::ClippedWeapon(string name, double damage, double atkInt,
    int pelletCount, int clipNum, double firstReload,
    double conscReload, bool fullyReloads) :
    Weapon(name, damage, atkInt, pelletCount) {
        clipSize = clipNum;
        reloadTimeFirst = firstReload;
        reloadTimeConsecutive = conscReload;
        doesFullReload = fullyReloads;
}


double ClippedWeapon::getClipSize() {
    return clipSize;
}


double ClippedWeapon::getFirstReload() {
    return reloadTimeFirst;
}


/*
    Returns the reload time of consecutive rounds
    If weapon fully reloads every clip, returns 0 instead
*/
double ClippedWeapon::getConsecutiveReload() {
    return doesFullReload ? 0 : reloadTimeConsecutive;
}


/*
    Changes clip size by a percentage,
    rounded to the nearest integer
*/
void ClippedWeapon::modifyClipSize(int m) {
    clipSize = round(clipSize * (1 + m/100.0));
}


/*
    Changes first and, if applicable, consecutive reload times by a percentage,
    rounded to the nearest server tick
*/
void ClippedWeapon::modifyReload(int m) {
    double multiplier = (1 - m/100.0);
    reloadTimeFirst = tickRound(reloadTimeFirst * multiplier);
    reloadTimeConsecutive = tickRound(reloadTimeConsecutive * multiplier);
}


string ClippedWeapon::getWeaponStats() {
    string reloadStat = doesFullReload ?
        "\nReload Time: " + to_string(reloadTimeFirst) :
        "\nReload Time (First): " + to_string(reloadTimeFirst) +
        "\nReload Time (Consecutive): " + to_string(reloadTimeConsecutive) +
        "\nTime to Full Reload: " + to_string(getFullReloadTime());
    return Weapon::getWeaponStats() +
        "Clip Size: " + to_string(clipSize) +
        "\nTime to Empty Clip: " + to_string(getEmptyClipTime()) +
        reloadStat +
        "\nReal DPS: " + to_string(getRealDPS()) + "\n";
}


/*
    Returns the time to empty this Weapon's clip
*/
double ClippedWeapon::getEmptyClipTime() {
    return attackInterval * clipSize;
}


/*
    Returns the time to fully reload this Weapon
*/
double ClippedWeapon::getFullReloadTime() {
    return doesFullReload ? reloadTimeFirst :
        reloadTimeFirst + reloadTimeConsecutive * (clipSize - 1);
}


/*
    Returns the Weapon DPS, taking reloading into account
*/
double ClippedWeapon::getRealDPS() {
    double emptyTime = getEmptyClipTime();
    return Weapon::getDPS() * (emptyTime/(emptyTime+getFullReloadTime()));
}