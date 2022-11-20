//======== Made by Tranquility =======//

#include <iostream>
#include "weapons.h"


int main() {
    // Scattergun
    Scattergun dummy;
    dummy.modifyClipSize(200);      // +200% clip size
    dummy.modifyAttackInterval(70); // +70% faster firing speed
    dummy.modifyReload(65);         // 65% faster reload time
    dummy.modifyBaseDamage(-40);    // -40% damage penalty
    cout<<dummy.getWeaponStats() + "\n";

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
    ClippedWeapon forceANature("Force-A-Nature", 6, 0.625, 10,
        6, 1.4333, 0, true);
    forceANature.modifyClipSize(400);
    forceANature.modifyAttackInterval(80);
    forceANature.modifyBaseDamage(-40);
    forceANature.modifyClipSize(-66);
    cout<<forceANature.getWeaponStats() + "\n";

    // Shortstop
    ClippedWeapon shortstop("Shortstop", 12, 0.36, 4,
        4, 1.52, 0, true);
    shortstop.modifyClipSize(100);
    shortstop.modifyAttackInterval(50);
    cout<<shortstop.getWeaponStats() + "\n";

    // Soda Popper
    ClippedWeapon sodaPopper("Soda Popper", 6, 0.625, 10,
        6, 1.4333, 0, true);
    sodaPopper.modifyBaseDamage(40);     // +40% damage bonus
    sodaPopper.modifyClipSize(500);      // +500% clip size
    sodaPopper.modifyAttackInterval(65); // +65% faster firing speed
    sodaPopper.modifyPelletCount(-50);   // -50% bullets per shot
    sodaPopper.modifyReload(25);         // 25% faster reload time
    sodaPopper.modifyClipSize(-66);      // -66% clip size
    cout<<sodaPopper.getWeaponStats() + "\n";

    // Baby Face's Blaster
    Scattergun babyFace;
    babyFace.setWeaponName("Baby Face's Blaster");
    babyFace.modifyBaseDamage(-40);
    babyFace.modifyAttackInterval(70);
    babyFace.modifyReload(65);
    cout<<babyFace.getWeaponStats() + "\n";

    // Back Scatter
    Scattergun backScatter;
    backScatter.setWeaponName("Back Scatter");
    backScatter.modifyBaseDamage(20);
    backScatter.modifyClipSize(275);
    backScatter.modifyAttackInterval(55);
    backScatter.modifyPelletCount(50);
    backScatter.modifyReload(65);
    backScatter.modifyClipSize(-34);
    cout<<backScatter.getWeaponStats() + "\n";

    // Pistol
    Pistol gotta;
    gotta.modifyBaseDamage(33);
    gotta.modifyClipSize(500);
    gotta.modifyAttackInterval(33);
    gotta.modifyReload(-47);
    cout<<gotta.getWeaponStats() + "\n";

    // Winger
    Pistol winger;
    winger.setWeaponName("Winger");
    winger.modifyBaseDamage(40);
    winger.modifyClipSize(800);
    winger.modifyAttackInterval(33);
    winger.modifyClipSize(-60);
    winger.modifyReload(-65);
    cout<<winger.getWeaponStats() + "\n";

    // Pretty Boy's Pocket Pistol
    Pistol prettyBoy;
    prettyBoy.setWeaponName("Pretty Boy's Pocket Pistol");
    prettyBoy.modifyBaseDamage(33);
    prettyBoy.modifyClipSize(500);
    prettyBoy.modifyAttackInterval(33);
    prettyBoy.modifyReload(-47);
    prettyBoy.modifyClipSize(-25);
    cout<<prettyBoy.getWeaponStats() + "\n";
    
    // Bat
    // Base Damage: 35
    // Attack Interval: 0.5
    // Pellet Count: 1
    Weapon bat("Bat", 35, 0.5, 1);
    cout<<bat.getWeaponStats() + "\n";
    
    // Rocket Launcher
    RocketLauncher blam;
    blam.modifyClipSize(50);
    cout<<blam.getWeaponStats() + "\n";

    // Direct Hit
    RocketLauncher directHit;
    directHit.setWeaponName("Direct Hit");
    directHit.modifyBaseDamage(25);
    directHit.modifyClipSize(50);
    cout<<directHit.getWeaponStats() + "\n";

    // Black Box
    RocketLauncher blackBox;
    blackBox.setWeaponName("Black Box");
    blackBox.modifyClipSize(-25);
    blackBox.modifyClipSize(50);
    cout<<blackBox.getWeaponStats() + "\n";

    // Liberty Launcher
    RocketLauncher liberty;
    liberty.setWeaponName("Liberty Launcher");
    liberty.modifyClipSize(75);
    liberty.modifyBaseDamage(-25);
    liberty.modifyAttackInterval(-15);
    liberty.modifyReload(-25);
    cout<<liberty.getWeaponStats() + "\n";

    // Cow Mangler 5000
    RocketLauncher cow;
    cow.setWeaponName("Cow Mangler 5000");
    cow.modifyReload(60);
    cow.modifyAttackInterval(-25);
    cout<<cow.getWeaponStats() + "\n";

    // Air Strike
    RocketLauncher air;
    air.setWeaponName("Air Strike");
    air.modifyClipSize(100);
    air.modifyAttackInterval(40);
    air.modifyBaseDamage(-15);
    cout<<air.getWeaponStats() + "\n";

    // Shotgun
    Shotgun shotty;
    shotty.modifyBaseDamage(-40);
    shotty.modifyAttackInterval(70);
    shotty.modifyClipSize(200);
    shotty.modifyReload(60);
    cout<<shotty.getWeaponStats() + "\n";

    // Panic Attack
    Shotgun panic;
    panic.setWeaponName("Panic Attack");
    panic.modifyBaseDamage(-40);
    panic.modifyClipSize(200);
    panic.modifyAttackInterval(70);
    panic.modifyPelletCount(50);
    panic.modifyReload(60);
    panic.modifyBaseDamage(-20);
    cout<<panic.getWeaponStats() + "\n";

    // Reserve Shooter
    Shotgun reserve;
    reserve.setWeaponName("Reserve Shooter");
    reserve.modifyBaseDamage(-34);
    reserve.modifyAttackInterval(70);
    reserve.modifyClipSize(200);
    reserve.modifyReload(60);
    reserve.modifyClipSize(-34);
    cout<<reserve.getWeaponStats() + "\n";
    
    // Shovel
    Shovel knight;
    cout<<knight.getWeaponStats() + "\n";
    
    // Grenade Launcher
    GrenadeLauncher iDidIt;
    iDidIt.modifyReload(50);
    cout<<iDidIt.getWeaponStats() + "\n";

    // Loch-N-Load
    GrenadeLauncher loch;
    loch.setWeaponName("Loch-N-Load");
    loch.modifyReload(50);
    loch.modifyAttackInterval(25);
    cout<<loch.getWeaponStats() + "\n";

    // Stickybomb Launcher
    StickybombLauncher likeThis;
    likeThis.modifyReload(50);
    cout<<likeThis.getWeaponStats() + "\n";

    // Scottish Resistance
    StickybombLauncher scottish;
    scottish.setWeaponName("Scottish Resistance");
    scottish.modifyBaseDamage(10);
    scottish.modifyClipSize(50);
    scottish.modifyAttackInterval(50);
    scottish.modifyReload(35);
    cout<<scottish.getWeaponStats() + "\n";

    // Quickiebomb Launcher
    StickybombLauncher quickie;
    quickie.setWeaponName("Quickiebomb Launcher");
    quickie.modifyClipSize(50);
    quickie.modifyAttackInterval(40);
    quickie.modifyReload(20);
    quickie.modifyBaseDamage(-5);
    quickie.modifyClipSize(-50);
    cout<<quickie.getWeaponStats() + "\n";
    
    // Minigun
    Minigun hoovy;
    hoovy.modifyAttackInterval(-5);
    cout<<hoovy.getWeaponStats() + "\n";

    // Natascha
    Minigun natascha;
    natascha.setWeaponName("Natascha");
    natascha.modifyAttackInterval(25);
    natascha.modifyPelletCount(25);
    natascha.modifyBaseDamage(-44);
    cout<<natascha.getWeaponStats() + "\n";

    // Brass Beast
    Minigun brass;
    brass.setWeaponName("Brass Beast");
    brass.modifyBaseDamage(10);
    brass.modifyAttackInterval(10);
    cout<<brass.getWeaponStats() + "\n";

    // Tomislav
    Minigun tomi;
    tomi.setWeaponName("Tomislav");
    tomi.modifyAttackInterval(-25);
    cout<<tomi.getWeaponStats() + "\n";

    // Huo-Long Heater
    Minigun heater;
    heater.setWeaponName("Huo-Long Heater");
    heater.modifyAttackInterval(25);
    heater.modifyPelletCount(25);
    heater.modifyBaseDamage(-20);
    cout<<heater.getWeaponStats() + "\n";

    // Family Business
    Shotgun family;
    family.setWeaponName("Family Business");
    family.modifyClipSize(300);
    family.modifyAttackInterval(75);
    family.modifyReload(40);
    family.modifyBaseDamage(-30);
    cout<<family.getWeaponStats() + "\n";
    
    // Frontier Justice
    Shotgun frontier;
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

    // Cleaner's Carbine
    SMG cleaner;
    cleaner.setWeaponName("Cleaner's Carbine");
    cleaner.modifyBaseDamage(100);
    cleaner.modifyClipSize(100);
    cleaner.modifyAttackInterval(20);
    cleaner.modifyClipSize(-20);
    cleaner.modifyAttackInterval(-25);
    cout<<cleaner.getWeaponStats() + "\n";
    
    // Syringe Gun
    SyringeGun medicine;
    medicine.modifyBaseDamage(100);
    medicine.modifyClipSize(100);
    medicine.modifyReload(-25);
    cout<<medicine.getWeaponStats() + "\n";

    // Blutsauger
    SyringeGun bluts;
    bluts.setWeaponName("Blutsauger");
    bluts.modifyBaseDamage(100);
    bluts.modifyClipSize(50);
    bluts.modifyAttackInterval(15);
    bluts.modifyReload(-75);
    cout<<bluts.getWeaponStats() + "\n";

    // Overdose
    SyringeGun overdose;
    overdose.setWeaponName("Overdose");
    overdose.modifyBaseDamage(100);
    overdose.modifyClipSize(50);
    overdose.modifyAttackInterval(-15);
    overdose.modifyReload(-25);
    cout<<overdose.getWeaponStats() + "\n";
    
    // Revolver
    Revolver ocelot;
    ocelot.modifyClipSize(300);
    ocelot.modifyAttackInterval(75);
    cout<<ocelot.getWeaponStats() + "\n";

    // Ambassador
    Revolver amby;
    amby.setWeaponName("Ambassador");
    amby.modifyBaseDamage(50);
    amby.modifyClipSize(200);
    amby.modifyAttackInterval(65);
    amby.modifyBaseDamage(-15);
    amby.modifyAttackInterval(-20);
    amby.modifyReload(-50);
    cout<<amby.getWeaponStats() + "\n";

    // L'Etranger
    Revolver letr;
    letr.setWeaponName("L\'Etranger");
    letr.modifyClipSize(300);
    letr.modifyAttackInterval(75);
    letr.modifyBaseDamage(-20);
    cout<<letr.getWeaponStats() + "\n";

    // Enforcer
    Revolver enforcer;
    enforcer.setWeaponName("Enforcer");
    enforcer.modifyClipSize(300);
    enforcer.modifyPelletCount(300);
    enforcer.modifyBaseDamage(-80);
    enforcer.modifyAttackInterval(75);
    cout<<enforcer.getWeaponStats() + "\n";

    // Diamondback
    Revolver diamond;
    diamond.setWeaponName("Diamondback");
    diamond.modifyClipSize(300);
    diamond.modifyAttackInterval(75);
    diamond.modifyBaseDamage(-15);
    cout<<diamond.getWeaponStats();

    return 0;
}
