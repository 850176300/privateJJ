//
//  EatSprite.m
//  MAKE
//
//  Created by zhuliang on 18/10/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#import "EatSprite.h"
#import "AudioRobot.h"
#import "DeviceHelper.h"
@implementation EatSprite
@synthesize isEnable;

-(EatSprite *)initWithRenderTexture:(CCTexture2D *)texture AndBrushTextureName:(NSString *)brushName
{
    CCSprite *bg = [CCSprite spriteWithTexture:texture];
    brushName_ = [brushName retain];
    
    if (self = [super initWithFile:@"transparent.png" rect:bg.textureRect]) {
        
        
        NSLog(@"self retaincount %i",self.retainCount);
        
        [self addChild:bg];
        bg.position = ccp(WINSIZE.width/2, WINSIZE.height /2);
        bg.flipY = YES;

		render_ = [CCRenderTexture renderTextureWithWidth:WINSIZE.width height:WINSIZE.height];
		render_.position = ccp(WINSIZE.width/2, WINSIZE.height /2);
		[self addChild:render_ z:0 tag:1];
        [render_ begin];
        [bg visit];
        [render_ end];
        
        bg.visible = NO;

        
		brush = [[CCSprite spriteWithFile:brushName] retain];
        [brush setBlendFunc:(ccBlendFunc){GL_ZERO,GL_ONE_MINUS_SRC_ALPHA }];
        
        
		touches = [[NSMutableArray arrayWithCapacity:5] retain];

        [[[CCDirector sharedDirector] touchDispatcher] addTargetedDelegate:self priority:0 swallowsTouches:YES];

		isEnable = YES;
        
        [self startDraw];

       
    }
    return self;
}


-(void)removeEatAction
{
    [[[CCDirector sharedDirector] touchDispatcher]  removeDelegate:self];

    [self unscheduleUpdate];

}

-(void)dealloc
{
    CCLOG(@"%@->%@",NSStringFromClass([self class]),NSStringFromSelector(_cmd));
    
    
    
    [[CCTextureCache sharedTextureCache] removeTextureForKey:@"transparent.png"];
    [[CCTextureCache sharedTextureCache] removeTextureForKey:textureName_];
    [[CCTextureCache sharedTextureCache] removeTextureForKey:brushName_];
    
	
    [textureName_ release];
    [brushName_ release];
    
	[brush release];
	brush = nil;
	
	[touches release];
	touches = nil;

    
    [super dealloc];
    
}


-(BOOL) ccTouchBegan:(UITouch *)touch withEvent:(UIEvent *)event
{
    if (!isEnable) {
        return NO;
    }
    
    
    [[AudioRobot sharedRobot] playEffectWithName:@"eat.mp3"];
    
	[touches addObject:touch];
    
	return YES;
}

-(void)ccTouchMoved:(UITouch *)touch withEvent:(UIEvent *)event
{
//    [touches addObject:touch];
    
}

-(void) ccTouchEnded:(UITouch *)touch withEvent:(UIEvent *)event
{
    
	[touches removeObject:touch];
}

-(void) ccTouchCancelled:(UITouch *)touch withEvent:(UIEvent *)event
{
	[self ccTouchEnded:touch withEvent:event];
}



-(void)startDraw
{
    [self unscheduleUpdate];
    [self scheduleUpdate];
}


-(void)endDraw
{
    
}



-(void) update:(ccTime)delta
{
    CCDirector* director = [CCDirector sharedDirector];
    
    
	[render_ begin];
    
    
    for (UITouch* touch in touches)
    {
        CGPoint touchLocation = [director convertToGL:[touch locationInView:(CCGLView *)[director view]]];
    
        // the location must be converted to the rendertexture sprite's node space
        touchLocation = [render_.sprite convertToNodeSpace:touchLocation];
    
        // because the rendertexture sprite is flipped along its Y axis the Y coordinate must be flipped:
        touchLocation.y = render_.sprite.contentSize.height - touchLocation.y;
    
    
        brush.position = touchLocation;
    
        [brush visit];
    
    }
    
	
//    for (int i = 0; i<[points count];i += 2)
//	{
//        
//        
//		float  x = [[points objectAtIndex:i] floatValue];
//        float  y = [[points objectAtIndex:i+1] floatValue];
//		
//        
//        
//		brush.position = ccp(x, y);
//        
//		[brush visit];
//        
//	}
    
    [touches removeAllObjects];
   // [points removeAllObjects];
    
	[render_ end];
}


@end
