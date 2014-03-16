//
//  Collision.cpp
//  FlappyBird
//
//  Created by meng-x on 2014/03/16.
//
//

#include "Collision.h"


Collision::Collision(Bird* bird, bool getScore){
    setName("Collision");
    this->bird = bird;
    this->getScore = getScore;
}


void Collision::update(float delta){
    parent = (CCNode*)getOwner();
    if (!parent) {
        return;
    }
    
    if (bird->status == isDie) {
        return;
    }
    
    if (getScore) {
        if (getWorldPosition().x <= bird->getPosition().x) {
            getScore = false;
            bird->updateScore();
        }
    }
    
    if (isCollision()) {
        bird->hit();
    }
}

bool Collision::isCollision()
{
    CCSize spipe = parent->boundingBox().size;
    CCPoint ppipe = getWorldPosition();
    
    CCSize sbird = bird->boundingBox().size;
    CCPoint pbird = bird->getPosition();
    
    float d = 6; 
    
    float maxx1 = ppipe.x + spipe.width/2 - d;
    float minx1 = ppipe.x - spipe.width/2 + d;
    float maxy1 = ppipe.y + spipe.height/2 - d;
    float miny1 = ppipe.y - spipe.height/2 + d;
    
    float maxx2 = pbird.x + sbird.width/2 - d;
    float minx2 = pbird.x - sbird.width/2 + d;
    float maxy2 = pbird.y + sbird.height/2 - d;
    float miny2 = pbird.y - sbird.height/2 + d;
    
    return !(maxx1 < minx2 ||
             maxx2 < minx1 ||
             maxy1 < miny2 ||
             maxy2 < miny1);
    
}

CCPoint Collision::getWorldPosition()
{
    return ((CCParallaxNode*)parent->getParent())->convertToWorldSpace(parent->getPosition());
}