//
//  EatSprite.cpp
//  MAKE-Dumpling
//
//  Created by zhuliang on 21/11/13.
//
//

#include "EatSprite.h"


EatSprite* EatSprite::create(cocos2d::CCTexture2D *texture)
{
    EatSprite *eatSprite = new EatSprite();

    CCSprite *bg = CCSprite::createWithTexture(texture);
    
    
    if (eatSprite && eatSprite->initWithFile("transparent.png", bg->getTextureRect()))
    {
        eatSprite->addChild(bg);
        bg->setPosition(VisibleRect::center());
        bg->setFlipY(true);
        
        eatSprite->render_= CCRenderTexture::create(VisibleRect::center().x*2, VisibleRect::center().y*2);
        eatSprite->render_->setPosition(VisibleRect::center());
        eatSprite->addChild(eatSprite->render_,1);
        eatSprite->render_->begin();
        bg->visit();
        eatSprite->render_->end();
        
        bg->removeFromParent();
        
        eatSprite->brush_ = CCSprite::create("brush.png");
        eatSprite->brush_->retain();
        ccBlendFunc ccbFunc = {GL_ZERO,GL_ONE_MINUS_SRC_ALPHA};
        eatSprite->brush_->setBlendFunc(ccbFunc);
        
        eatSprite->touches_ = CCArray::createWithCapacity(0);
        eatSprite->touches_->retain();
        
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(eatSprite, 0, true);
        
        eatSprite->isEnable = true;
        
        eatSprite->startDraw();
        
        eatSprite->autorelease();
        return eatSprite;
        
    }
    CC_SAFE_DELETE(eatSprite);
    
    return eatSprite;

}


void EatSprite::removeEatAction()
{
     CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    this->unscheduleUpdate();
}


EatSprite::~EatSprite()
{
    CCLog("eatsprite del");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("transparent.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("brush.png");
    
    brush_->release();
    
    touches_->release();
    
    
    
}

void EatSprite::startDraw()
{
    this->unscheduleUpdate();
    this->scheduleUpdate();

}

void EatSprite::update(float dt)
{
    render_->begin();
    
    CCObject *obj = NULL;
    CCARRAY_FOREACH(touches_, obj)
    {
        CCPoint touchLocation = CCDirector::sharedDirector()->convertToGL(dynamic_cast<CCTouch *>(obj)->getLocation());
        
//        touchLocation = render_->getSprite()->convertToNodeSpace(touchLocation);
        
        touchLocation.y = render_->getSprite()->getContentSize().height-touchLocation.y;
        
        brush_->setPosition(touchLocation);
        brush_->visit();
        
    }
    
    touches_->removeAllObjects();
    
    render_->end();
    
}


#pragma mark -touchDelegate
bool EatSprite::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!isEnable) {
        return false;
    }
    
    SoundPlayer::getInstance()->playEatEffect();
    
    touches_->addObject(pTouch);
    
    touchCount++;
    if (touchCount == 3) {
        CCNotificationCenter::sharedNotificationCenter()->postNotification("showSurprise");
    }
    
    return true;
    
}


void EatSprite::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
        

    
    
}


void EatSprite::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    touches_->removeAllObjects();

}


void EatSprite::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    touches_->removeAllObjects();
    
}




