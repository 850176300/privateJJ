//
//  EatSprite.h
//  MAKE-Dumpling
//
//  Created by zhuliang on 21/11/13.
//
//

#ifndef __MAKE_Dumpling__EatSprite__
#define __MAKE_Dumpling__EatSprite__

#include <iostream>
#include "CommonHeaders.h"
#include "cocos2d.h"
USING_NS_CC;

class EatSprite: public CCSprite,public CCTouchDelegate {

public:
    static EatSprite* create(CCTexture2D *texture);
    
    virtual ~EatSprite();
    
    void update(float dt);
    
    //重写触屏相关函数----
//    virtual void onEnter();
//    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    void removeEatAction();
    void startDraw();
    void endDraw();
    
public:
    bool isEnable;

private:
    

private:
    CCSprite *brush_;
    CCArray *touches_;
    CCRenderTexture *render_;
    
    string textureName_;
    string brushName_;

    int touchCount;
};

#endif /* defined(__MAKE_Dumpling__EatSprite__) */
