//
//  MoveLeft.cpp
//  FlappyBird
//
//  Created by meng-x on 2014/03/16.
//
//

#include "MoveLeft.h"
#include "config.h"


MoveLeft::MoveLeft(float w){
    setName("MoveLeft");
    this->w = w / kLandParts;
}

void MoveLeft::onEnter(){
    actionMove();
}

void MoveLeft::update(float delta){

}

void MoveLeft::actionMove(){
    CCNode* parent = (CCNode*)getOwner();
    CCMoveBy* moveleft = CCMoveBy::create(kMoveLeftDura, ccp(-w, 0));
    parent->runAction(CCRepeatForever::create(moveleft));
}