//
//  EatSprite.h
//  MAKE
//
//  Created by zhuliang on 18/10/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "cocos2d.h"

@interface EatSprite : CCSprite <CCTargetedTouchDelegate> {
    CCSprite* brush;                //画刷
	NSMutableArray* touches;

    CCRenderTexture *render_;
    
    NSString *textureName_;
    NSString *brushName_;

}

@property (nonatomic,assign) BOOL isEnable;

-(EatSprite *)initWithRenderTexture:(CCTexture2D *)texture AndBrushTextureName:(NSString *)brushName;
-(void)removeEatAction;
-(void)startDraw;
-(void)endDraw;
@end
