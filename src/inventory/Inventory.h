/*------------------------------------------------------------------------------
* Source: Inventory.h         
*
* Functions:
*
* Date: 
*
* Revisions: 
* Edited By : Tim Makimov on 2017/APR/05
*
* Designer: 
*
* Author: 
*
* Notes:
------------------------------------------------------------------------------*/
#ifndef INVENTORY_H
#define INVENTORY_H
#include <SDL2/SDL.h>
#include <array>
#include <memory>

#include "Consumable.h"
#include "BasicMedkit.h"
#include "weapons/Weapon.h"
#include "weapons/HandGun.h"
#include "weapons/Rifle.h"
#include "weapons/ShotGun.h"
#include "weapons/ZombieHand.h"


/*
 * Created By Maitiu Morton
 * THe inventory class acts as the marine's inventory. It sotres the ids for all the objects that the
 * Marine has equipped such as Weapons and Consumables.
 */
class Inventory {
public:
    void switchCurrent(int slot);//switches currently selected slot based on key input
    Weapon *getCurrent() const;//Returns current weapon
    void scrollCurrent(int direction);//switches current slot based on wheel scroll
    void useItem(Marine& marine); //uses current inventory item
    int getCurrentSlot() const {return current;}; //returns the current slot selected in the inventory
    Weapon *getWeaponFromInventory(int inventorySlot); //returns the weapon in the inventory slot specified
    int getCurretSlot() const {return current;}; //returns the current sloted selected int the inventory
    Inventory();
    ~Inventory() = default;
    void initZombie();

private:
    int current = 0;//current weapon
    std::array<int32_t, 3> weaponIds;//array of weapon ids
    HandGun defaultGun;
    Rifle defaultGun2;
    ShotGun defaultGun3;

    ZombieHand tempZombieHand;
    //temp for now, in the future this will simply be a pointer to a consumable which is null initially
    //when this is updated, update the getMedkit function
    int slotScrollTick = 0;
    int scrollDelay = 200;
};

#endif
