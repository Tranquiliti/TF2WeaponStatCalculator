//======== Made by Tranquility =======//

#include <iostream>
#include "weapons.h"


int main() {
    WeaponManager weaponMan; // Manages weapons

    // Scattergun
    Scattergun dummy;
    dummy.modifyClipSize(200);      // +200% clip size
    dummy.modifyAttackInterval(70); // +70% faster firing speed
    dummy.modifyReload(65);         // 65% faster reload time
    dummy.modifyBaseDamage(-40);    // -40% damage penalty
    weaponMan.addWeapon(&dummy); // Needed to print weapon stats

    /*
        Example below creates a clipped weapon with initial stats:
        Base Damage          - 6 / pellet
        Attack Interval      - 0.625 s
        Pellet count         - 10
        Clip size            - 6
        Reload (First)       - 1.4333 s
        Reload (Consecutive) - 0 s
        Fully reloads all ammo in clip
    */
    // Force-A-Nature
    ClippedWeapon forceANature("Force-A-Nature",
        6, 0.625, 10, 6, 1.4333, 0, true);
    forceANature.modifyClipSize(200);
    forceANature.modifyAttackInterval(75);
    forceANature.modifyBaseDamage(-50);
    forceANature.modifyReload(20);
    weaponMan.addWeapon(&forceANature); 

    // Shortstop
    ClippedWeapon shortstop("Shortstop",
        12, 0.36, 4, 4, 1.0133, 0, true);
    shortstop.modifyClipSize(100);
    shortstop.modifyAttackInterval(37);
    shortstop.modifyPelletCount(25);
    shortstop.modifyReload(25);
    shortstop.modifyBaseDamage(-25);
    //shortstop.modifyReload(-50); // -50% slower reload time (hidden)
    weaponMan.addWeapon(&shortstop);

    // Soda Popper
    ClippedWeapon sodaPopper("Soda Popper",
        6, 0.625, 10, 6, 1.4333, 0, true);
    sodaPopper.modifyBaseDamage(40);     // +40% damage bonus
    sodaPopper.modifyClipSize(500);      // +500% clip size
    sodaPopper.modifyAttackInterval(65); // +65% faster firing speed
    sodaPopper.modifyPelletCount(-50);   // -50% bullets per shot
    sodaPopper.modifyReload(25);         // 25% faster reload time
    sodaPopper.modifyClipSize(-66);      // -66% clip size
    weaponMan.addWeapon(&sodaPopper);

    // Baby Face's Blaster
    Scattergun babyFace;
    babyFace.setWeaponName("Baby Face's Blaster");
    babyFace.modifyBaseDamage(-40);
    babyFace.modifyAttackInterval(70);
    babyFace.modifyReload(65);
    weaponMan.addWeapon(&babyFace);

    // Back Scatter
    Scattergun backScatter;
    backScatter.setWeaponName("Back Scatter");
    backScatter.modifyBaseDamage(20);
    backScatter.modifyClipSize(275);
    backScatter.modifyAttackInterval(55);
    backScatter.modifyPelletCount(50);
    backScatter.modifyReload(65);
    backScatter.modifyClipSize(-34);
    weaponMan.addWeapon(&backScatter);

    // Pistol
    Pistol gotta;
    gotta.modifyBaseDamage(33);
    gotta.modifyClipSize(500);
    gotta.modifyAttackInterval(33);
    gotta.modifyReload(-47);
    weaponMan.addWeapon(&gotta);

    // Winger
    Pistol winger;
    winger.setWeaponName("Winger");
    winger.modifyBaseDamage(33);
    winger.modifyClipSize(200);
    winger.modifyAttackInterval(33);
    winger.modifyReload(10);
    weaponMan.addWeapon(&winger);

    // Pretty Boy's Pocket Pistol
    Pistol prettyBoy;
    prettyBoy.setWeaponName("Pretty Boy's Pocket Pistol");
    prettyBoy.modifyBaseDamage(33);
    prettyBoy.modifyClipSize(500);
    prettyBoy.modifyAttackInterval(33);
    prettyBoy.modifyReload(-47);
    prettyBoy.modifyClipSize(-25);
    weaponMan.addWeapon(&prettyBoy);
    
    // Bat
    /*
        Base Damage     - 35 / pellet
        Attack Interval - 0.5 s
        Pellet Count    - 1
    */
    Weapon bat("Bat", 35, 0.5, 1);
    weaponMan.addWeapon(&bat);
    
    // Rocket Launcher
    RocketLauncher blam;
    blam.modifyBaseDamage(100);
    blam.modifyClipSize(50);
    weaponMan.addWeapon(&blam);

    // Direct Hit
    RocketLauncher directHit;
    directHit.setWeaponName("Direct Hit");
    directHit.modifyBaseDamage(100);
    directHit.modifyBaseDamage(25);
    directHit.modifyClipSize(50);
    weaponMan.addWeapon(&directHit);

    // Black Box
    RocketLauncher blackBox;
    blackBox.setWeaponName("Black Box");
    blackBox.modifyBaseDamage(100);
    blackBox.modifyClipSize(-25);
    blackBox.modifyClipSize(50);
    weaponMan.addWeapon(&blackBox);

    // Liberty Launcher
    RocketLauncher liberty;
    liberty.setWeaponName("Liberty Launcher");
    liberty.modifyClipSize(75);
    liberty.modifyBaseDamage(-25);
    liberty.modifyBaseDamage(100);
    liberty.modifyAttackInterval(-15);
    liberty.modifyReload(-25);
    weaponMan.addWeapon(&liberty);

    // Cow Mangler 5000
    RocketLauncher cow;
    cow.setWeaponName("Cow Mangler 5000");
    cow.modifyBaseDamage(100);
    cow.modifyReload(60);
    cow.modifyAttackInterval(-25);
    weaponMan.addWeapon(&cow);

    // Air Strike
    RocketLauncher air;
    air.setWeaponName("Air Strike");
    air.modifyClipSize(100);
    air.modifyAttackInterval(40);
    air.modifyBaseDamage(-15);
    air.modifyBaseDamage(100);
    weaponMan.addWeapon(&air);

    // Shotgun
    Shotgun shotty;
    shotty.modifyBaseDamage(-40);
    shotty.modifyAttackInterval(70);
    shotty.modifyClipSize(200);
    shotty.modifyReload(60);
    weaponMan.addWeapon(&shotty);

    // Panic Attack
    Shotgun panic;
    panic.setWeaponName("Panic Attack");
    panic.modifyBaseDamage(-40);
    panic.modifyClipSize(200);
    panic.modifyAttackInterval(70);
    panic.modifyPelletCount(50);
    panic.modifyReload(60);
    panic.modifyBaseDamage(-20);
    weaponMan.addWeapon(&panic);

    // Reserve Shooter
    Shotgun reserve;
    reserve.setWeaponName("Reserve Shooter");
    reserve.modifyBaseDamage(-34);
    reserve.modifyAttackInterval(70);
    reserve.modifyClipSize(200);
    reserve.modifyReload(60);
    reserve.modifyClipSize(-34);
    weaponMan.addWeapon(&reserve);
    
    // Shovel
    Shovel knight;
    weaponMan.addWeapon(&knight);
    
    // Grenade Launcher
    GrenadeLauncher iDidIt;
    iDidIt.modifyReload(50);
    weaponMan.addWeapon(&iDidIt);

    // Loch-N-Load
    GrenadeLauncher loch;
    loch.setWeaponName("Loch-N-Load");
    loch.modifyReload(50);
    loch.modifyAttackInterval(25);
    weaponMan.addWeapon(&loch);

    // Stickybomb Launcher
    StickybombLauncher likeThis;
    likeThis.modifyReload(50);
    weaponMan.addWeapon(&likeThis);

    // Scottish Resistance
    StickybombLauncher scottish;
    scottish.setWeaponName("Scottish Resistance");
    scottish.modifyBaseDamage(10);
    scottish.modifyClipSize(50);
    scottish.modifyAttackInterval(50);
    scottish.modifyReload(35);
    weaponMan.addWeapon(&scottish);

    // Quickiebomb Launcher
    StickybombLauncher quickie;
    quickie.setWeaponName("Quickiebomb Launcher");
    quickie.modifyClipSize(50);
    quickie.modifyAttackInterval(40);
    quickie.modifyReload(20);
    quickie.modifyBaseDamage(-5);
    quickie.modifyClipSize(-50);
    weaponMan.addWeapon(&quickie);
    
    // Minigun
    Minigun hoovy;
    hoovy.modifyAttackInterval(-5);
    weaponMan.addWeapon(&hoovy);

    // Natascha
    Minigun natascha;
    natascha.setWeaponName("Natascha");
    natascha.modifyAttackInterval(25);
    natascha.modifyPelletCount(25);
    natascha.modifyBaseDamage(-44);
    weaponMan.addWeapon(&natascha);

    // Brass Beast
    Minigun brass;
    brass.setWeaponName("Brass Beast");
    brass.modifyBaseDamage(10);
    brass.modifyAttackInterval(10);
    weaponMan.addWeapon(&brass);

    // Tomislav
    Minigun tomi;
    tomi.setWeaponName("Tomislav");
    tomi.modifyAttackInterval(-25);
    weaponMan.addWeapon(&tomi);

    // Huo-Long Heater
    Minigun heater;
    heater.setWeaponName("Huo-Long Heater");
    heater.modifyAttackInterval(25);
    heater.modifyPelletCount(25);
    heater.modifyBaseDamage(-20);
    weaponMan.addWeapon(&heater);

    // Family Business
    Shotgun family;
    family.setWeaponName("Family Business");
    family.modifyClipSize(300);
    family.modifyAttackInterval(75);
    family.modifyReload(40);
    family.modifyBaseDamage(-30);
    weaponMan.addWeapon(&family);
    
    // Frontier Justice
    Shotgun frontier;
    frontier.setWeaponName("Frontier Justice");
    frontier.modifyBaseDamage(60);
    frontier.modifyClipSize(300);
    frontier.modifyClipSize(-50);
    frontier.modifyAttackInterval(55);
    frontier.modifyPelletCount(25);
    frontier.modifyReload(40);
    weaponMan.addWeapon(&frontier);
    
    // Sniper Rifle
    SniperRifle awp;
    weaponMan.addWeapon(&awp);
    
    // SMG
    SMG submarine;
    submarine.modifyBaseDamage(50);
    submarine.modifyAttackInterval(20);
    submarine.modifyClipSize(200);
    submarine.modifyReload(-82);
    weaponMan.addWeapon(&submarine);

    // Cleaner's Carbine
    SMG cleaner;
    cleaner.setWeaponName("Cleaner's Carbine");
    cleaner.modifyBaseDamage(100);
    cleaner.modifyClipSize(100);
    cleaner.modifyAttackInterval(20);
    cleaner.modifyClipSize(-20);
    cleaner.modifyAttackInterval(-25);
    weaponMan.addWeapon(&cleaner);
    
    // Syringe Gun
    SyringeGun medicine;
    medicine.modifyBaseDamage(100);
    medicine.modifyClipSize(100);
    medicine.modifyReload(-25);
    weaponMan.addWeapon(&medicine);

    // Blutsauger
    SyringeGun bluts;
    bluts.setWeaponName("Blutsauger");
    bluts.modifyBaseDamage(100);
    bluts.modifyClipSize(50);
    bluts.modifyAttackInterval(15);
    bluts.modifyReload(-75);
    weaponMan.addWeapon(&bluts);

    // Overdose
    SyringeGun overdose;
    overdose.setWeaponName("Overdose");
    overdose.modifyBaseDamage(100);
    overdose.modifyClipSize(50);
    overdose.modifyAttackInterval(-15);
    overdose.modifyReload(-25);
    weaponMan.addWeapon(&overdose);
    
    // Revolver
    Revolver ocelot;
    ocelot.modifyClipSize(300);
    ocelot.modifyAttackInterval(75);
    weaponMan.addWeapon(&ocelot);

    // Ambassador
    Revolver amby;
    amby.setWeaponName("Ambassador");
    amby.modifyBaseDamage(50);
    amby.modifyClipSize(200);
    amby.modifyAttackInterval(65);
    amby.modifyBaseDamage(-15);
    amby.modifyAttackInterval(-20);
    amby.modifyReload(-50);
    weaponMan.addWeapon(&amby);

    // L'Etranger
    Revolver letr;
    letr.setWeaponName("L\'Etranger");
    letr.modifyClipSize(300);
    letr.modifyAttackInterval(75);
    letr.modifyBaseDamage(-20);
    weaponMan.addWeapon(&letr);

    // Enforcer
    Revolver enforcer;
    enforcer.setWeaponName("Enforcer");
    enforcer.modifyClipSize(300);
    enforcer.modifyPelletCount(300);
    enforcer.modifyBaseDamage(-80);
    enforcer.modifyAttackInterval(75);
    weaponMan.addWeapon(&enforcer);

    // Diamondback
    Revolver diamond;
    diamond.setWeaponName("Diamondback");
    diamond.modifyClipSize(300);
    diamond.modifyAttackInterval(75);
    diamond.modifyBaseDamage(-15);
    weaponMan.addWeapon(&diamond);

    // Knife
    Weapon stab("Knife", 40, 0.8, 1);
    weaponMan.addWeapon(&stab);

    // Sort options: Name, AttackInterval, NonstopDPS, RealDPS
    //weaponMan.sort(WeaponManager::Name); // Sort by Name
    weaponMan.sort(WeaponManager::RealDPS); // Sort by Real DPS
    //cout<<weaponMan.printWeaponDPS(); // Print all weapon DPS stats
    cout<<weaponMan.printWeaponStats();

    return 0;
}