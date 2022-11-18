//======== Made by Tranquility =======//

#include <string>
#include <cmath>

using namespace std;

// TF2 servers usually run at 15 milliseconds per server clock tick
// Therefore, there are 66.666... server ticks per second
const double SECONDS_PER_TICK = 0.015;


double tickRound(double);


/*
    All TF2 weapons are Weapons (duh!)
*/
class Weapon {
    protected:
        string weaponName;
        double baseDamage;
        double attackInterval; // in seconds
        int numOfPellets;
        
        Weapon(){};
    
    public:
        Weapon(string,double,double,int);

        double getBaseDamage();
        double getAttackInterval();
        int getPelletCount();
        
        void setWeaponName(string);
        void modifyBaseDamage(int);
        void modifyAttackInterval(int);
        void modifyPelletCount(int);
        
        string getWeaponStats();
        double getDPS();
};


/*
    Weapons using clips that require occasional reloading
*/
class ClippedWeapon: public Weapon {
    protected:
        int clipSize;
        double reloadTimeFirst; // in seconds
        double reloadTimeConsecutive; // in seconds
        bool doesFullReload;
        
        ClippedWeapon(){};
        
    public:
        ClippedWeapon(string,double,double,int,int,double,double,bool);

        double getClipSize();
        double getFirstReload();
        double getConsecutiveReload();
        
        void modifyClipSize(int);
        void modifyReload(int);
        
        string getWeaponStats();
        double getEmptyClipTime();
        double getFullReloadTime();
        double getRealDPS();
};


/*
    Pistol used by Scout and Engineer
    (Scout reloads his Pistol a few ticks faster, but it's not very noticeable)
*/
class Pistol: public ClippedWeapon {
    public:
        Pistol() {
            weaponName = "Pistol";
            baseDamage = 15;
            numOfPellets = 1;
            attackInterval = 0.15; // 10 ticks
            clipSize = 12;
            reloadTimeFirst = 1.035; // 69 ticks for Engineer
            doesFullReload = true;
        }
};


/*
    Shotgun used by Soldier, Pyro, Heavy, and Engineer.
    (First reload time differs slightly for each class, but
    it's usually too insignificant to consider)
*/
class ShotgunGeneric: public ClippedWeapon {
    public:
        ShotgunGeneric() {
            weaponName = "Shotgun";
            baseDamage = 6.0;
            numOfPellets = 10;
            attackInterval = 0.625; // ~42 ticks
            clipSize = 6;
            reloadTimeFirst = 1.005; // 67 ticks for Soldier
            reloadTimeConsecutive = 0.51; // 34 ticks
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
            numOfPellets = 1;
            attackInterval = 0.8; // ~53 ticks
        }
};


/*
    Heavy Minigun
*/
class Minigun: public Weapon {
    public:
        Minigun() {
            weaponName = "Minigun";
            baseDamage = 9.0;
            numOfPellets = 4;
            attackInterval = 0.105; // 7 ticks
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
            numOfPellets = 1;
            attackInterval = 0.105; // 7 ticks
            clipSize = 40;
            reloadTimeFirst = 1.305; // 87 ticks
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
            numOfPellets = 1;
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
            numOfPellets = 1;
            attackInterval = 0.105; // 7 ticks
            clipSize = 25;
            reloadTimeFirst = 1.1; // ~73 ticks
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
            numOfPellets = 1;
            attackInterval = 0.5; // ~33 ticks
            clipSize = 6;
            reloadTimeFirst = 1.133; // ~75 ticks
            doesFullReload = true;
        }
};