//
//  Bird.cpp
//  FlappyBird
//
//  Created by meng-x on 2014/03/16.
//
//

#include "Bird.h"
#include "config.h"

Bird::Bird(){
    initWithSpriteFrameName("bird1.png");
    this->runAction(flying());
    
    status = isIdle;
    score = 0;
}

CCRepeatForever* Bird::flying(){
    int numFrame = 3;
    
    CCArray* frames = CCArray::createWithCapacity(numFrame);
    CCSpriteFrameCache* frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    
    char fileName[100] = {0};
    for (int i = 0; i < numFrame; i++) {
        sprintf(fileName, "bird%d.png", i+1);
        CCSpriteFrame* frame = frameCache->spriteFrameByName(fileName);
        frames->addObject(frame);
    }
    
    CCAnimation* anim = CCAnimation::createWithSpriteFrames(frames, kFlyingDura);
    CCAnimate* action = CCAnimate::create(anim);
    
    CCRepeatForever* repeat = CCRepeatForever::create(action);
    
    return repeat;
}

void Bird::tap(){
    status = isTap;
}

void Bird::hit(){

}

void Bird::updateScore(){

}