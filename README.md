# TF2WeaponStatCalculator

A simple C++ program that can output stats for most TF2 weapons, including weapons with modified attributes. These stats include DPS and reload time calculations that account for TF2's server tick speed (usually at 15 milliseconds per tick, or 66.666... ticks per second). The weapon stat list can also be sorted by their name, attack interval, or damage per second (DPS).

Any C++ compiler should be able to run this program. If you can't or don't want to download a compiler just for this, feel free to use an online compiler like https://www.onlinegdb.com/online_c++_compiler to upload and run the program files instead.

To use this for your own use, simply edit <i>main.cpp</i>, which has plenty of examples (currently, they are stats for weapons in the Zombie Escape mod hosted on Skial servers). You can also add new weapon types to <i>weapon.h</i>, again with plenty of examples. Doing either should not require extensive C++ knowledge, so feel free to mess around with the program code.
