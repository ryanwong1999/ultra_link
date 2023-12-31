#ifndef __APP_MENU_H
#define __APP_MENU_H

struct MenuProperty_t
{
	u8 MenuLen;				//当前菜单页菜单个数
	u8 scrollBarLen;	//滚动条长度,由于都是用的16SIZE的字符，所以一个菜单页最多四个菜单，五个菜单滚动条就为1
};

//菜单结构体
struct Menu_t{
	struct MenuProperty_t *MenuProperty;
	u8 displayString[15];					//当前菜单的字符
	void (*func1) (void);					//当前菜单的功能函数
	void (*func2) (void);					//当前菜单的功能函数
	struct Menu_t *fatherMenu;		//当前菜单的父级菜单
	struct Menu_t *childrenMenu;	//当前菜单的子级菜单	
};

extern uint16_t count1, count2,count3, count4, count5;

void MenuInit(void);
void MenuControl(void);
void DisplayRefreash(struct Menu_t *nowMenu, u8 selectItem, u8 scrollBar);
void DisplayRefreashData(struct Menu_t *nowMenu, u8 selectItem, u8 scrollBar);
void GuiDataDisplayRefresh(void);

#endif