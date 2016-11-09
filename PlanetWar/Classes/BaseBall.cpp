//
//  BaseBall.cpp
//  PlanetWar
//
//  Created by Xinhou Jiang on 8/11/16.
//
//

#include "BaseBall.h"
USING_NS_CC;

/**
 * 创建对象
 */
BaseBall* BaseBall::create() {
	BaseBall *sprite = new BaseBall();
    
	if (sprite && sprite->init())
	{
        sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

/**
 * 初始化
 */
bool BaseBall::init() {
    // 随机位置
    x = CCRANDOM_0_1() * maxW;
    y = CCRANDOM_0_1() * maxH;
    // 半径
    radius = 3;
    // 随机颜色
    color = Color4F(255*CCRANDOM_0_1(), 255*CCRANDOM_0_1(), 255*CCRANDOM_0_1(), 1.0);
    // drawnode
    drawNode = DrawNode::create();
    this->addChild(drawNode);
    
    // 随机图片
    //initWithFile("CloseNormal.png");
    
    // 设置位置
    setPosition(Vec2(x, y));
    
    // 开启安帧更新
    //this->scheduleUpdate();
    
    return true;
}

/**
 * 绘图
 */
void BaseBall::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) {
    // 清空之前的绘制
    drawNode->clear();
    // 绘制实心圆形
    drawNode->drawDot(Vec2(0, 0), radius, color);

}

/**
 * 安帧更新
 */
void BaseBall::update(float time) {
    
}
