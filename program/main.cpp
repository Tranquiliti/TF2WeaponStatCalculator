//======== Made by Tranquility =======//

#include <iostream>
#include "weapons.h"

int main() {
    // Pistol
    Pistol gotta;
    gotta.modifyBaseDamage(33);
    gotta.modifyClipSize(500);
    gotta.modifyAttackInterval(33);
    gotta.modifyReload(-47);
    cout<<gotta.getWeaponStats() + "\n";
    
    // Bat
    Weapon bat("Bat", 35, 0.5, 1);
    cout<<bat.getWeaponStats() + "\n";
    
    // Rocket Launcher
    // 0.8 attack interval is ~53 ticks
    ClippedWeapon rocket("Rocket Launcher", 90, 0.8, 1,
        4, 0.92, 0.8, false);
    rocket.modifyClipSize(50);
    cout<<rocket.getWeaponStats() + "\n";
    
    // Shotgun
    ShotgunGeneric shotty;
    shotty.modifyBaseDamage(-40);
    shotty.modifyAttackInterval(70);
    shotty.modifyClipSize(200);
    shotty.modifyReload(60);
    cout<<shotty.getWeaponStats() + "\n";
    
    // Shovel
    Shovel knight;
    cout<<knight.getWeaponStats() + "\n";
    
    // Grenade Launcher
    // 0.6 attack interval is 40 ticks
    ClippedWeapon grenade("Grenade Launcher", 100, 0.6, 1,
        4, 1.24, 0.6, false);
    grenade.modifyReload(50);
    cout<<grenade.getWeaponStats() + "\n";
    
    // Minigun
    Minigun hoovy;
    hoovy.modifyAttackInterval(-5);
    cout<<hoovy.getWeaponStats() + "\n";

    // Brass Beast
    Minigun brass;
    brass.setWeaponName("Brass Beast");
    brass.modifyBaseDamage(10);
    brass.modifyAttackInterval(10);
    cout<<brass.getWeaponStats() + "\n";
    
    // Frontier Justice
    ShotgunGeneric frontier;
    frontier.setWeaponName("Frontier Justice");
    frontier.modifyBaseDamage(60);
    frontier.modifyClipSize(300);
    frontier.modifyClipSize(-50);
    frontier.modifyAttackInterval(55);
    frontier.modifyPelletCount(25);
    frontier.modifyReload(40);
    cout<<frontier.getWeaponStats() + "\n";
    
    // Sniper Rifle
    SniperRifle awp;
    cout<<awp.getWeaponStats() + "\n";
    
    // SMG
    SMG submarine;
    submarine.modifyBaseDamage(50);
    submarine.modifyAttackInterval(20);
    submarine.modifyClipSize(200);
    submarine.modifyReload(-82);
    cout<<submarine.getWeaponStats() + "\n";
    
    // Syringe Gun
    SyringeGun medicine;
    medicine.modifyBaseDamage(100);
    medicine.modifyClipSize(100);
    medicine.modifyReload(-25);
    cout<<medicine.getWeaponStats() + "\n";
    
    // Revolver
    Revolver ocelot;
    ocelot.modifyClipSize(300);
    ocelot.modifyAttackInterval(75);
    cout<<ocelot.getWeaponStats();

    return 0;
}