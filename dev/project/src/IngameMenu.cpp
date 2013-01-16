#include "pch.h"
#include "IngameMenu.h"
#include "VisibleRect.h"

IngameMenu::IngameMenu():
    m_pIngameMenu(nullptr),
    m_pBackToMainMenu(nullptr)
{

}

IngameMenu::~IngameMenu()
{

}

bool IngameMenu::init()
{
    bool kRet = CCLayer::init();
    m_pIngameMenu = CCMenu::create();

    CCLabelTTF* label = CCLabelTTF::create("Main menu", "Arial", 24);
    m_pBackToMainMenu = CCMenuItemLabel::create(label);
    m_pBackToMainMenu->setPosition( ccp( VisibleRect::left().x + m_pBackToMainMenu->getContentSize().width / 2, VisibleRect::center().y) );

    m_pIngameMenu->setPosition(0, 0);
    m_pIngameMenu->addChild(m_pBackToMainMenu);

    addChild(m_pIngameMenu);

    setTouchEnabled(true);

    return kRet;
}

CCMenuItemLabel* IngameMenu::getBackToMainMenu() const
{
    return m_pBackToMainMenu;
}
