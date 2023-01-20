//======== Made by Tranquility =======//

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

/*
Putting testing notes here before I forget:
Damage is internally stored as a floating point number
First, pellet count (which is floored) multiplies the damage, keeping the decimal intact
Then, the total shot damage is floored (e.g 9.9 * 4 = 39.6 ~= 39)
Then, damage falloff/ramp-up modifies the floored number, rounding to the nearest integer

(Testing done against the Horseless Headless Horsemann, so this may not accurately apply to func_breakables or robot Tanks)
*/

// TF2 servers usually run at 15 milliseconds per server clock tick
// Therefore, there are 66.666... server ticks per second
const float SECONDS_PER_TICK = 0.015;


/*
    Rounds a number to the nearest TF2 server tick
*/
const float tickRound(float num);

/*
    Rounds a floating point number to a specified number of decimal places
*/
const float roundTo(float num, int precision);


/*
    All TF2 weapons are Weapons (duh!)
*/
class Weapon {
    protected:
        string weaponName;
        float baseDamage; // per pellet
        float attackInterval; // in seconds
        float pelletCount;
        
        Weapon(); // Default constructor
    
    public:
        /*
            Constructs a Weapon with specified stats
        */
        Weapon(string weaponName, float baseDamage,
               float attackInterval, float pelletCount);

        const string getWeaponName();
        const float getBaseDamage();
        const float getAttackInterval();
        const float getPelletCount();
        
        const int getDamagePerShot();

        void setWeaponName(string newName);

        /*
            Changes base damage by a percentage
        */
        void modifyBaseDamage(float percent);

        /*
            Changes attack interval by a percentag
        */
        void modifyAttackInterval(float percent);
        
        /*
            Changes pellet count by a percentage
        */
        void modifyPelletCount(float percent);
        
        virtual const string getWeaponStats();

        /*
            Returns this Weapon's DPS, assuming nonstop firing
        */
        const double getDPS();
};


/*
    Weapons using clips that require occasional reloading
*/
class ClippedWeapon: public Weapon {
    protected:
        int    clipSize;
        float reloadFirst; // in seconds
        float reloadConsecutive; // in seconds
        bool   doesFullReload;
        
        ClippedWeapon(); // Default constructor
        
    public:
        /*
            Constructs a clipped Weapon with specified stats
        */
        ClippedWeapon(string weaponName, float baseDamage,
                      float attackInterval, float pelletCount,
                      int clipSize, float reloadFirst,
                      float reloadConsecutive, bool doesFullReload);

        const float getClipSize();
        const float getFirstReload(); // Rounded to nearest tick
        const float getConsecutiveReload(); // Returns 0 if weapon does full reloads
        
        /*
            Changes clip size by a percentage,
            rounded to the nearest integer if percent m is negative
            or rounded down if percent m is positive
        */
        void modifyClipSize(float percent);

        /*
            Changes first and consecutive reload times by a percentage,
        */
        void modifyReload(float percent);
        
        const string getWeaponStats();

        /*
            Returns the time (in seconds) to empty this Weapon's clip
        */
        const float getEmptyClipTime();

        /*
            Returns the time (in seconds) to fully reload this Weapon
        */
        const float getFullReloadTime();

        /*
            Returns this Weapon's DPS, taking reloading into account
        */
        const float getRealDPS();
};


/*
    Manages a list of weapons
*/
class WeaponManager {
    private:
        vector<Weapon*> weapons;

    public:
        // Attributes used to sort weapons
        enum SortType{Name,AttackInterval,NonstopDPS,RealDPS};

        WeaponManager(); // Constructs the weapon manager

        /*
            Adds a Weapon to this Manager
        */
        void addWeapon(Weapon* wep);

        /*
            Outputs the stats of all weapons stored in this Manager
        */
        const string printWeaponStats();

        /*
            Outputs the DPS stats of all weapons stored in this Manager
        */
        const string printWeaponDPS();

        /*
            Sorts weapons by a specified criterion
        */
        void sort(SortType stat);
};


/*
    Scattergun used by a dumb Scout
*/
class Scattergun: public ClippedWeapon {
    public:
        Scattergun() {
            weaponName = "Scattergun";
            baseDamage = 6;
            pelletCount = 10;
            attackInterval = 0.625; // ~42 ticks
            clipSize = 6;
            reloadFirst = 0.7; // ~47 ticks for Soldier
            reloadConsecutive = 0.5; // ~33 ticks
            doesFullReload = false;
        }
};


/*
    Pistol used by Scout and Engineer
    (Scout reloads his Pistol a few ticks faster, but it's not noticeable)
*/
class Pistol: public ClippedWeapon {
    public:
        Pistol() {
            weaponName = "Pistol";
            baseDamage = 15;
            pelletCount = 1;
            attackInterval = 0.15; // 10 ticks
            clipSize = 12;
            reloadFirst = 1.035; // 69 ticks for Engineer
            doesFullReload = true;
        }
};


/*
    Rocket Launcher used by the patriotic Soldier
*/
class RocketLauncher: public ClippedWeapon {
    public:
        RocketLauncher() {
            weaponName = "Rocket Launcher";
            baseDamage = 90;
            pelletCount = 1;
            attackInterval = 0.8; // ~53 ticks
            clipSize = 4;
            reloadFirst = 0.92; // ~61 ticks
            reloadConsecutive = 0.8; // ~53 ticks
            doesFullReload = false;
        }
};


/*
    Shotgun used by Soldier, Pyro, Heavy, and Engineer.
    (First reload time differs slightly for each class, but
    it's usually too insignificant to consider)
*/
class Shotgun: public ClippedWeapon {
    public:
        Shotgun() {
            weaponName = "Shotgun";
            baseDamage = 6;
            pelletCount = 10;
            attackInterval = 0.625; // ~42 ticks
            clipSize = 6;
            reloadFirst = 1; // ~67 ticks for Soldier
            reloadConsecutive = 0.5; // ~34 ticks
            doesFullReload = false;
        }
};


/*
    Stock melee weapon used by all classes except Scout and Spy
    (In this case, it's a Shovel!)
*/
class Shovel: public Weapon {
    public:
        Shovel() {
            weaponName = "Shovel";
            baseDamage = 65;
            pelletCount = 1;
            attackInterval = 0.8; // ~53 ticks
        }
};


/*
    Grenade Launcher used by a drunk Demoman
*/
class GrenadeLauncher: public ClippedWeapon {
    public:
        GrenadeLauncher() {
            weaponName = "Grenade Launcher";
            baseDamage = 100;
            pelletCount = 1;
            attackInterval = 0.6; // 40 ticks
            clipSize = 4;
            reloadFirst = 1.24; // ~83 ticks
            reloadConsecutive = 0.6; // 40 ticks
            doesFullReload = false;
        }
};


/*
    Stickybomb Launcher used by a drunk, Scottish Demoman
*/
class StickybombLauncher: public ClippedWeapon {
    public:
        StickybombLauncher() {
            weaponName = "Stickybomb Launcher";
            baseDamage = 120;
            pelletCount = 1;
            attackInterval = 0.6; // 40 ticks
            clipSize = 8;
            reloadFirst = 1.09; // ~73 ticks
            reloadConsecutive = 0.67; // ~45 ticks
            doesFullReload = false;
        }
};


/*
    Heavy Minigun
*/
class Minigun: public Weapon {
    public:
        Minigun() {
            weaponName = "Minigun";
            baseDamage = 9;
            pelletCount = 4;
            attackInterval = 0.1; // ~7 ticks
        }
};


/*
    Syringe Gun used by MEDIC!!!
*/
class SyringeGun: public ClippedWeapon {
    public:
        SyringeGun() {
            weaponName = "Syringe Gun";
            baseDamage = 10;
            pelletCount = 1;
            attackInterval = 0.1; // ~7 ticks
            clipSize = 40;
            reloadFirst = 1.305; // 87 ticks
            doesFullReload = true;
        }
};


/*
    Sniper Rifle used by Sniper (Sniping's a good job, mate!)
*/
class SniperRifle: public Weapon {
    public:
        SniperRifle() {
            weaponName = "Sniper Rifle";
            baseDamage = 50;
            pelletCount = 1;
            attackInterval = 1.5; // 100 ticks
        }
};


/*
    SMG used by a professional Sniper
*/
class SMG: public ClippedWeapon {
    public:
        SMG() {
            weaponName = "SMG";
            baseDamage = 8;
            pelletCount = 1;
            attackInterval = 0.1; // ~7 ticks
            clipSize = 25;
            reloadFirst = 1.1; // ~73 ticks
            doesFullReload = true;
        }
};


/*
    Revolver used by the Spies among us
*/
class Revolver: public ClippedWeapon {
    public:
        Revolver() {
            weaponName = "Revolver";
            baseDamage = 40;
            pelletCount = 1;
            attackInterval = 0.5; // ~33 ticks
            clipSize = 6;
            reloadFirst = 1.133; // ~75 ticks
            doesFullReload = true;
        }
};